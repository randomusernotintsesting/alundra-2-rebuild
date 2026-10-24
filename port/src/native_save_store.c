#include "native_save_store.h"
#include "save_location.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#ifdef _WIN32
#include "platform/storage_windows.h"
typedef A2WDirectory *SaveDirectory;
#define close_directory a2w_directory_close
#else
#include <sys/file.h>
typedef int SaveDirectory;
#define close_directory close
#endif
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#if defined(A2_SAVE_STORE_TESTING) && !defined(_WIN32)
extern int a2_save_test_directory_fsync(int fd);
extern void a2_save_test_before_publish(int directory, const char *name);
#define directory_fsync a2_save_test_directory_fsync
#else
#define directory_fsync fsync
#endif

/* The container is 48 explicit bytes followed by the complete original block:
 * 0 magic[8], 8 version u32, 12 header bytes u32, 16 payload bytes u32,
 * 20 IEEE CRC32 u32, 24 UTC Unix seconds u64, 32 game identity[16]. */
static const uint8_t magic[8] = {'A','2','S','A','V','E','\r','\n'};
static const uint8_t game[16] = "SCPS-10115";

static int fail(char *error, size_t n, const char *format, ...) {
    if (error && n) {
        va_list args; va_start(args, format); vsnprintf(error, n, format, args); va_end(args);
    }
    return 0;
}
static uint16_t rd16(const uint8_t *p) { return p[0] | (uint16_t)p[1] << 8; }
static uint32_t rd32(const uint8_t *p) {
    return p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}
static void wr32(uint8_t *p, uint32_t v) {
    for (unsigned i = 0; i < 4; i++) p[i] = (uint8_t)(v >> (i * 8));
}
static uint32_t crc32(const uint8_t *p, size_t n) {
    uint32_t crc = UINT32_MAX;
    while (n--) {
        crc ^= *p++;
        for (unsigned i = 0; i < 8; i++)
            crc = (crc >> 1) ^ (0xedb88320u & (0u - (crc & 1u)));
    }
    return ~crc;
}
static int validate_payload(const uint8_t *p, A2SaveMetadata *meta, char *error, size_t n) {
    if (!p) return fail(error, n, "Missing save payload");
    if (memcmp(p, "SC\x11\x01", 4)) return fail(error, n, "Invalid original save header (expected SC1101)");
    uint32_t sum = 0;
    for (unsigned i = 0; i < 0xd8c; i += 2) sum += rd16(p + i);
    if ((uint16_t)sum != rd16(p + 0xd8c)) return fail(error, n, "Original save checksum mismatch");
    unsigned index = rd16(p + 0x102), scene = rd16(p + 0xc14);
    if (!a2_save_location_valid(index,scene))
        return fail(error, n, "Unsupported save location: index %u, scene %u", index, scene);
    if (meta) {
        memset(meta, 0, sizeof *meta);
        meta->scene = (uint16_t)scene; meta->location_index = (uint16_t)index;
        meta->payload_crc32 = crc32(p, A2_SAVE_PAYLOAD_SIZE);
    }
    return 1;
}

#ifdef _WIN32
#define Target A2WTarget
static int open_target(const char *path, struct Target *t, char *error, size_t n) {
    return a2w_target(path,t) || fail(error,n,"Cannot open a safe UTF-8 save path (Windows error %lu)",GetLastError());
}
static int read_exact_file(SaveDirectory dir,const char *name,uint8_t *bytes,size_t length,char *error,size_t n) {
    return a2w_read(dir,name,bytes,length) || fail(error,n,"Cannot read regular single-link %s of %zu bytes (Windows error %lu)",name,length,GetLastError());
}
#else
struct Target { int dir; char parent[PATH_MAX], name[NAME_MAX + 1]; };
static int open_target(const char *path, struct Target *t, char *error, size_t n) {
    t->dir = -1;
    if (!path || !*path || strlen(path) >= PATH_MAX) return fail(error, n, "Invalid save path");
    const char *slash = strrchr(path, '/'), *name = slash ? slash + 1 : path;
    size_t length = strlen(name);
    if (!length || length > NAME_MAX - 5 || !strcmp(name, ".") || !strcmp(name, ".."))
        return fail(error, n, "Invalid save filename");
    memcpy(t->name, name, length + 1);
    if (!slash) strcpy(t->parent, ".");
    else if (slash == path) strcpy(t->parent, "/");
    else { size_t len = (size_t)(slash - path); memcpy(t->parent, path, len); t->parent[len] = 0; }
    t->dir = open(t->parent, O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
    if (t->dir < 0) return fail(error, n, "Cannot open save directory: %s", strerror(errno));
    return 1;
}
static int read_exact_file(int dir, const char *name, uint8_t *bytes, size_t length,
                           char *error, size_t n) {
    int fd = openat(dir, name, O_RDONLY | O_NOFOLLOW | O_NONBLOCK | O_CLOEXEC);
    if (fd < 0) return fail(error, n, "Cannot read %s: %s", name, strerror(errno));
    struct stat st; int ok = 1;
    if (fstat(fd, &st) || !S_ISREG(st.st_mode) || st.st_size != (off_t)length)
        ok = fail(error, n, "%s is not a regular file of %zu bytes", name, length);
    size_t pos = 0;
    while (ok && pos < length) {
        ssize_t got = read(fd, bytes + pos, length - pos);
        if (got < 0 && errno == EINTR) continue;
        if (got <= 0) { ok = fail(error, n, "Incomplete read of %s", name); break; }
        pos += (size_t)got;
    }
    if (ok) {
        uint8_t extra; ssize_t got;
        do { got = read(fd, &extra, 1); } while (got < 0 && errno == EINTR);
        if (got != 0) ok = fail(error, n, "%s changed size while reading", name);
    }
    if (close(fd) && ok) ok = fail(error, n, "Cannot close %s after reading", name);
    return ok;
}
#endif
static int read_at(SaveDirectory dir, const char *name, uint8_t *payload,
                    A2SaveMetadata *meta, char *error, size_t n) {
    uint8_t bytes[A2_SAVE_HEADER_SIZE + A2_SAVE_PAYLOAD_SIZE];
    if (!read_exact_file(dir, name, bytes, sizeof bytes, error, n)) return 0;
    if (memcmp(bytes, magic, sizeof magic)) return fail(error, n, "Invalid native save signature");
    unsigned version=rd32(bytes+8);
    if (version!=A2_SAVE_VERSION && version!=A2_SAVE_FREE_VERSION)
        return fail(error, n, "Unsupported native save version");
    if (rd32(bytes + 12) != A2_SAVE_HEADER_SIZE || rd32(bytes + 16) != A2_SAVE_PAYLOAD_SIZE)
        return fail(error, n, "Invalid native save sizes");
    if (memcmp(bytes + 32, game, sizeof game)) return fail(error, n, "Save belongs to a different game");
    if (crc32(bytes + A2_SAVE_HEADER_SIZE, A2_SAVE_PAYLOAD_SIZE) != rd32(bytes + 20))
        return fail(error, n, "Native save CRC32 mismatch");
    A2SaveMetadata parsed;
    if (!validate_payload(bytes + A2_SAVE_HEADER_SIZE, &parsed, error, n)) return 0;
    if ((version==A2_SAVE_FREE_VERSION)!=(parsed.location_index==A2_SAVE_FREE_LOCATION))
        return fail(error,n,"Unsupported native save version for location");
    for (unsigned i = 0; i < 8; i++) parsed.utc_seconds |= (uint64_t)bytes[24 + i] << (i * 8);
    if (payload) memcpy(payload, bytes + A2_SAVE_HEADER_SIZE, A2_SAVE_PAYLOAD_SIZE);
    if (meta) *meta = parsed;
    return 1;
}

int a2_save_read(const char *path, uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                 A2SaveMetadata *metadata, char *error, size_t error_size) {
    if (error && error_size) error[0] = 0;
    if (!payload) return fail(error, error_size, "Missing save read buffer");
    struct Target t;
    if (!open_target(path, &t, error, error_size)) return 0;
    int ok = read_at(t.dir, t.name, payload, metadata, error, error_size);
    close_directory(t.dir); return ok;
}

#ifdef _WIN32
static int write_save(const char *path,const uint8_t *payload,int import,int new_only,char *error,size_t n) {
    if(error&&n)error[0]=0;
    A2SaveMetadata meta;
    if(!validate_payload(payload,&meta,error,n))return 0;
    if(import&&meta.location_index==A2_SAVE_FREE_LOCATION)return fail(error,n,"Unsupported original card location");
    struct Target t;if(!open_target(path,&t,error,n))return 0;
    char lockname[1040];snprintf(lockname,sizeof lockname,"%s.lock",t.name);
    HANDLE lock=a2w_lock(t.dir,lockname);int ok=0;
    if(lock==INVALID_HANDLE_VALUE){fail(error,n,"Save is busy or its private lock is unsafe");goto done;}
    int exists=a2w_exists(t.dir,t.name);
    if(exists<0){fail(error,n,"Save target is unsafe or inaccessible");goto done;}
    if(exists&&new_only){fail(error,n,"New save already exists; existing save preserved");goto done;}
    if(exists&&import){
        uint8_t previous[A2_SAVE_PAYLOAD_SIZE];
        if(!read_at(t.dir,t.name,previous,NULL,error,n))goto done;
        if(memcmp(previous,payload,sizeof previous)){fail(error,n,"Import filename collision; existing save preserved");goto done;}
        ok=1;goto done;
    }
    uint8_t bytes[A2_SAVE_HEADER_SIZE+A2_SAVE_PAYLOAD_SIZE]={0};
    time_t now=time(NULL);if(now<0){fail(error,n,"Cannot read UTC time");goto done;}
    memcpy(bytes,magic,sizeof magic);
    wr32(bytes+8,meta.location_index==A2_SAVE_FREE_LOCATION?A2_SAVE_FREE_VERSION:A2_SAVE_VERSION);
    wr32(bytes+12,A2_SAVE_HEADER_SIZE);wr32(bytes+16,A2_SAVE_PAYLOAD_SIZE);wr32(bytes+20,meta.payload_crc32);
    for(unsigned i=0;i<8;i++)bytes[24+i]=(uint8_t)((uint64_t)now>>(i*8));
    memcpy(bytes+32,game,sizeof game);memcpy(bytes+A2_SAVE_HEADER_SIZE,payload,A2_SAVE_PAYLOAD_SIZE);
    ok=a2w_publish(t.dir,t.name,bytes,sizeof bytes,new_only||import);
    if(!ok)fail(error,n,"Cannot publish save; existing files preserved (Windows error %lu)",GetLastError());
    if(ok==A2_SAVE_PUBLISHED_UNCERTAIN)fail(error,n,"Save was published, but post-publication sync/close failed");
done:
    if(lock!=INVALID_HANDLE_VALUE)CloseHandle(lock);
    close_directory(t.dir);return ok;
}
#else
static int write_save(const char *path, const uint8_t *payload, int import, int new_only,
                       char *error, size_t n) {
    if (error && n) error[0] = 0;
    A2SaveMetadata meta;
    if (!validate_payload(payload, &meta, error, n)) return 0;
    if (import && meta.location_index==A2_SAVE_FREE_LOCATION)
        return fail(error,n,"Unsupported original card location");
    struct Target t;
    if (!open_target(path, &t, error, n)) return 0;
    int ok = 0, lock = -1, fd = -1;
    char lockname[NAME_MAX + 1], tmp[PATH_MAX] = {0};
    char *tmpname = NULL;
    snprintf(lockname, sizeof lockname, "%.*s.lock", (int)sizeof lockname - 6, t.name);
    lock = openat(t.dir, lockname, O_RDWR | O_CREAT | O_NOFOLLOW | O_NONBLOCK | O_CLOEXEC, 0600);
    struct stat st;
    if (lock < 0 || fstat(lock, &st) || !S_ISREG(st.st_mode) || st.st_nlink != 1) {
        fail(error, n, "Cannot open a regular private save lock"); goto done;
    }
    if (flock(lock, LOCK_EX | LOCK_NB)) { fail(error, n, "Save is busy in another process"); goto done; }
    int exists = fstatat(t.dir, t.name, &st, AT_SYMLINK_NOFOLLOW) == 0;
    if (!exists && errno != ENOENT) { fail(error, n, "Cannot inspect save target: %s", strerror(errno)); goto done; }
    if (exists && !S_ISREG(st.st_mode)) { fail(error, n, "Save target is not a regular file"); goto done; }
    if (exists && new_only) { fail(error, n, "New save already exists; existing save preserved"); goto done; }
    if (exists && import) {
        uint8_t previous[A2_SAVE_PAYLOAD_SIZE];
        if (!read_at(t.dir, t.name, previous, NULL, error, n)) goto done;
        if (memcmp(previous, payload, sizeof previous)) {
            fail(error, n, "Import filename collision; existing save preserved"); goto done;
        }
        ok = 1; goto done; /* Preserve original import timestamp and bytes. */
    }
    uint8_t header[A2_SAVE_HEADER_SIZE] = {0};
    time_t now = time(NULL);
    if (now < 0) { fail(error, n, "Cannot read UTC time"); goto done; }
    memcpy(header, magic, sizeof magic);
    wr32(header + 8, meta.location_index==A2_SAVE_FREE_LOCATION?A2_SAVE_FREE_VERSION:A2_SAVE_VERSION);
    wr32(header + 12, A2_SAVE_HEADER_SIZE);
    wr32(header + 16, A2_SAVE_PAYLOAD_SIZE); wr32(header + 20, meta.payload_crc32);
    for (unsigned i = 0; i < 8; i++) header[24 + i] = (uint8_t)((uint64_t)now >> (i * 8));
    memcpy(header + 32, game, sizeof game);
    if (snprintf(tmp, sizeof tmp, "%s/.a2save.XXXXXX", t.parent) >= (int)sizeof tmp) {
        fail(error, n, "Save directory path is too long"); tmp[0] = 0; goto done;
    }
    fd = mkstemp(tmp);
    if (fd < 0) { fail(error, n, "Cannot create temporary save: %s", strerror(errno)); tmp[0] = 0; goto done; }
    tmpname = strrchr(tmp, '/') + 1;
    /* Keep rename anchored to the directory opened before taking its lock.
     * Refuse a temporary created elsewhere if that path moved concurrently. */
    struct stat temp_stat, anchored_stat;
    if (fstat(fd, &temp_stat) || fstatat(t.dir, tmpname, &anchored_stat, AT_SYMLINK_NOFOLLOW) ||
        temp_stat.st_dev != anchored_stat.st_dev || temp_stat.st_ino != anchored_stat.st_ino) {
        fail(error, n, "Save directory changed during write"); goto done;
    }
    const uint8_t *parts[] = {header, payload};
    const size_t sizes[] = {sizeof header, A2_SAVE_PAYLOAD_SIZE};
    for (unsigned part = 0; part < 2; part++) {
        size_t pos = 0;
        while (pos < sizes[part]) {
            ssize_t wrote = write(fd, parts[part] + pos, sizes[part] - pos);
            if (wrote < 0 && errno == EINTR) continue;
            if (wrote <= 0) { fail(error, n, "Cannot write temporary save: %s", strerror(errno)); goto done; }
            pos += (size_t)wrote;
        }
    }
    if (fsync(fd)) { fail(error, n, "Cannot sync temporary save: %s", strerror(errno)); goto done; }
    if (close(fd)) { fd = -1; fail(error, n, "Cannot close temporary save: %s", strerror(errno)); goto done; }
    fd = -1;
#ifdef A2_SAVE_STORE_TESTING
    a2_save_test_before_publish(t.dir, t.name);
#endif
    if (new_only) {
        /* linkat creates the destination atomically only when it is absent,
         * including a writer that did not honor our lock. The temporary is
         * fully written and fsynced before it becomes visible. */
        if (linkat(t.dir, tmpname, t.dir, t.name, 0)) {
            fail(error, n, "Cannot create new save; existing files preserved: %s", strerror(errno)); goto done;
        }
        if (unlinkat(t.dir, tmpname, 0)) {
            fail(error, n, "Save was published, but temporary cleanup failed: %s", strerror(errno));
            ok = A2_SAVE_PUBLISHED_UNCERTAIN;
            goto done;
        }
    } else if (renameat(t.dir, tmpname, t.dir, t.name)) {
        fail(error, n, "Cannot publish save: %s", strerror(errno)); goto done;
    }
    tmp[0] = 0;
    if (directory_fsync(t.dir)) {
        fail(error, n, "Save was published, but directory sync failed: %s", strerror(errno));
        ok = A2_SAVE_PUBLISHED_UNCERTAIN;
        goto done;
    }
    ok = 1;
done:
    if (fd >= 0) close(fd);
    if (tmp[0] && tmpname) unlinkat(t.dir, tmpname, 0);
    if (lock >= 0) close(lock);
    close(t.dir);
    return ok;
}

#endif
static int is_import_snapshot(const char *path) {
    if (!path) return 0;
    const char *name = strrchr(path, '/');
#ifdef _WIN32
    const char *backslash = strrchr(path, '\\');
    if (backslash && (!name || backslash > name)) name = backslash;
#endif
    name = name ? name + 1 : path;
    /* Case-insensitive aliases can resolve to the same imported inode on
     * macOS. Reserve the whole canonical shape, including those aliases. */
    if (strlen(name) != 36 || strncasecmp(name, "card", 4) ||
        (name[4] != '1' && name[4] != '2') ||
        strncasecmp(name + 5, "-BISCPS-10115", 13) ||
        name[18] < '0' || name[18] > '9' || name[19] < '0' || name[19] > '9' ||
        name[20] != '-' || strcasecmp(name + 29, A2_SAVE_EXTENSION)) return 0;
    for (unsigned i = 21; i < 29; i++)
        if (!((name[i] >= '0' && name[i] <= '9') ||
              (name[i] >= 'A' && name[i] <= 'F') ||
              (name[i] >= 'a' && name[i] <= 'f'))) return 0;
    return 1;
}

int a2_save_write(const char *path, const uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                  char *error, size_t error_size) {
    if (is_import_snapshot(path))
        return fail(error, error_size, "Imported snapshots cannot be replaced; save a new copy");
    return write_save(path, payload, 0, 0, error, error_size);
}

static int checksum_ok(const uint8_t *sector) {
    uint8_t sum = 0;
    for (unsigned i = 0; i < 128; i++) sum ^= sector[i];
    return sum == 0;
}

int a2_save_import_cards(const char *user_directory, const char *saves_directory,
                         char *error, size_t error_size) {
    if (error && error_size) error[0] = 0;
    if (!user_directory || !*user_directory || !saves_directory || !*saves_directory)
        return fail(error, error_size, "Missing import directory");
#ifdef _WIN32
    SaveDirectory source=a2w_directory(user_directory,0);
    if(!source)return fail(error,error_size,"Cannot open safe memory-card directory");
#else
    int source = open(user_directory, O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
    if (source < 0) return fail(error, error_size, "Cannot open memory-card directory: %s", strerror(errno));
#endif
    int ok = 0, published_uncertain = 0;
    char warning[512] = {0};
#ifdef _WIN32
    A2WDirectory *destination=a2w_directory(saves_directory,1);
    if(!destination){fail(error,error_size,"Cannot create safe save directory");goto done;}
    a2w_directory_close(destination);
#else
    if (mkdir(saves_directory, 0700) && errno != EEXIST) {
        fail(error, error_size, "Cannot create save directory: %s", strerror(errno)); goto done;
    }
    int destination = open(saves_directory, O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
    if (destination < 0) { fail(error, error_size, "Cannot open import destination directory"); goto done; }
    close(destination);
#endif
    uint8_t *bytes = malloc(131072);
    if (!bytes) { fail(error, error_size, "Not enough memory to import card"); goto done; }
    for (unsigned slot = 1; slot <= 2; slot++) {
        char cardname[32]; snprintf(cardname, sizeof cardname, "memcard%u.mcr", slot);
#ifdef _WIN32
        int exists=a2w_exists(source,cardname);
        if(!exists)continue;
        if(exists<0){fail(error,error_size,"Cannot inspect safe %s",cardname);goto free_card;}
#else
        struct stat st;
        if (fstatat(source, cardname, &st, AT_SYMLINK_NOFOLLOW)) {
            if (errno == ENOENT) continue;
            fail(error, error_size, "Cannot inspect %s: %s", cardname, strerror(errno)); goto free_card;
        }
#endif
        if (!read_exact_file(source, cardname, bytes, 131072, error, error_size)) goto free_card;
        if (memcmp(bytes, "MC", 2) || !checksum_ok(bytes)) {
            fail(error, error_size, "%s has an invalid memory-card header", cardname); goto free_card;
        }
        for (unsigned block = 1; block <= 15; block++) {
            const uint8_t *dir = bytes + block * 128;
            if (dir[0] != 0x51 || memcmp(dir + 10, "BISCPS-10115", 12)) continue;
            if (rd32(dir) != 0x51 || !checksum_ok(dir) || rd16(dir + 8) != 0xffff ||
                rd32(dir + 4) != A2_SAVE_PAYLOAD_SIZE) {
                fail(error, error_size, "%s block %u has an invalid own-save directory entry", cardname, block);
                goto free_card;
            }
            if (dir[22] < '0' || dir[22] > '9' || dir[23] < '0' || dir[23] > '9' || dir[24]) {
                fail(error, error_size, "%s block %u has an invalid own-save filename", cardname, block);
                goto free_card;
            }
            const uint8_t *p = bytes + block * A2_SAVE_PAYLOAD_SIZE;
            A2SaveMetadata meta;
            char reason[256];
            if (!validate_payload(p, &meta, reason, sizeof reason)) {
                fail(error, error_size, "%s block %u: %s", cardname, block, reason); goto free_card;
            }
            char path[PATH_MAX];
            if (snprintf(path, sizeof path, "%s/card%u-%.14s-%08X%s", saves_directory,
                         slot, (const char *)dir + 10, meta.payload_crc32, A2_SAVE_EXTENSION) >= (int)sizeof path) {
                fail(error, error_size, "Import destination path is too long"); goto free_card;
            }
            int result = write_save(path, p, 1, 0, reason, sizeof reason);
            if (result == A2_SAVE_FAILED) {
                fail(error, error_size, "%s", reason); goto free_card;
            }
            if (result == A2_SAVE_PUBLISHED_UNCERTAIN) {
                published_uncertain = 1;
                if (!warning[0]) snprintf(warning, sizeof warning, "%s", reason);
            }
        }
    }
    ok = published_uncertain ? A2_SAVE_PUBLISHED_UNCERTAIN : A2_SAVE_OK;
    if (published_uncertain) fail(error, error_size, "%s", warning);
free_card:
    free(bytes);
done:
    close_directory(source); return ok;
}

int a2_save_write_new(const char *path, const uint8_t payload[A2_SAVE_PAYLOAD_SIZE],
                      char *error, size_t error_size) {
    if (is_import_snapshot(path))
        return fail(error, error_size, "Imported snapshot names are reserved; save a new copy");
    return write_save(path, payload, 0, 1, error, error_size);
}
