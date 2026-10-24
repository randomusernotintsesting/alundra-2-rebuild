#include "native_save_store.h"
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static char root[] = "/private/tmp/a2-native-save-test.XXXXXX";
static char error[512];

#ifdef A2_SAVE_STORE_TESTING
static int directory_sync_failure;
static int new_publish_race;
static uint8_t racing_save_bytes[8240];
void a2_save_test_before_publish(int directory, const char *name) {
    if (!new_publish_race) return;
    new_publish_race = 0;
    int fd = openat(directory, name, O_WRONLY | O_CREAT | O_EXCL, 0600);
    assert(fd >= 0);
    assert(write(fd, racing_save_bytes, sizeof racing_save_bytes) == sizeof racing_save_bytes);
    assert(!close(fd));
}
int a2_save_test_directory_fsync(int fd) {
    if (directory_sync_failure) { directory_sync_failure--; errno = EIO; return -1; }
    return fsync(fd);
}
#endif

static void join(char *out, const char *dir, const char *name) {
    assert(snprintf(out, 1024, "%s/%s", dir, name) < 1024);
}
static void put16(unsigned char *p, unsigned n) {
    p[0] = (unsigned char)n; p[1] = (unsigned char)(n >> 8);
}
static void put32(unsigned char *p, unsigned n) {
    for (unsigned i = 0; i < 4; i++) p[i] = (unsigned char)(n >> (i * 8));
}
static unsigned get32(const unsigned char *p) {
    return p[0] | (unsigned)p[1] << 8 | (unsigned)p[2] << 16 | (unsigned)p[3] << 24;
}
static void payload(unsigned char p[8192], unsigned marker) {
    memset(p, 0, 8192);
    memcpy(p, "SC\x11\x01", 4);
    p[4] = (unsigned char)marker;
    p[0xc14] = 14; /* First original save location, index 0. */
    put16(p + 0xd8c, 0x4472 + marker); /* Independent fixture sum. */
    p[8191] = (unsigned char)(marker ^ 0x5a); /* Opaque tail must survive. */
}
static void write_bytes(const char *path, const void *bytes, size_t n) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    assert(fd >= 0);
    assert(write(fd, bytes, n) == (ssize_t)n);
    assert(close(fd) == 0);
}
static size_t read_bytes(const char *path, void *bytes, size_t capacity) {
    int fd = open(path, O_RDONLY); assert(fd >= 0);
    ssize_t n = read(fd, bytes, capacity); assert(n >= 0);
    assert(close(fd) == 0); return (size_t)n;
}
static void roundtrip_and_replacement(void) {
    char path[1024]; join(path, root, "one.a2save");
    unsigned char first[8192], second[8192], got[8192], file[9000];
    payload(first, 17); payload(second, 23);
    time_t before = time(NULL);
    assert(a2_save_write(path, first, error, sizeof error));
    A2SaveMetadata meta;
    assert(a2_save_read(path, got, &meta, error, sizeof error));
    assert(memcmp(got, first, 8192) == 0);
    assert(meta.scene == 14 && meta.location_index == 0);
    assert(meta.utc_seconds >= (uint64_t)before && meta.utc_seconds <= (uint64_t)time(NULL));
    assert(meta.payload_crc32 == 0x2caeb1a3); /* Independently calculated fixture. */
    assert(read_bytes(path, file, sizeof file) == 8240);
    assert(memcmp(file, "A2SAVE\r\n", 8) == 0);
    assert(get32(file + 8) == 1 && get32(file + 12) == 48);
    assert(get32(file + 16) == 8192 && get32(file + 20) == 0x2caeb1a3);
    assert(memcmp(file + 32, "SCPS-10115\0\0\0\0\0\0\0", 16) == 0);
    assert(memcmp(file + 48, first, 8192) == 0);
    assert(a2_save_write(path, second, error, sizeof error));
    assert(a2_save_read(path, got, NULL, error, sizeof error));
    assert(memcmp(got, second, 8192) == 0);
    /* A free-position checkpoint has its own format version, while original
     * indexed saves keep version 1 for compatibility with previous ports. */
    put16(second+0x102,0xffff); put16(second+0xc14,21);
    unsigned sum=0;for(unsigned i=0;i<0xd8c;i+=2)sum+=second[i]|second[i+1]<<8;
    put16(second+0xd8c,sum);
    assert(a2_save_write(path,second,error,sizeof error));
    assert(a2_save_read(path,got,&meta,error,sizeof error));
    assert(!memcmp(got,second,8192) && meta.location_index==0xffff && meta.scene==21);
    assert(read_bytes(path,file,sizeof file)==8240 && get32(file+8)==2);
    put32(file+8,1);write_bytes(path,file,8240);
    assert(!a2_save_read(path,got,&meta,error,sizeof error));
    payload(second,23);
    assert(a2_save_write(path,second,error,sizeof error));
}
static void corrupt_files_leave_outputs_unchanged(void) {
    char good[1024], bad[1024]; join(good, root, "one.a2save"); join(bad, root, "bad.a2save");
    unsigned char original[8241], changed[8241], got[8192], untouched[8192];
    assert(read_bytes(good, original, sizeof original) == 8240);
    const unsigned offsets[] = {0, 8, 12, 16, 20, 32, 47, 48, 8239};
    memset(untouched, 0xa5, sizeof untouched);
    for (unsigned i = 0; i < sizeof offsets / sizeof offsets[0]; i++) {
        memcpy(changed, original, 8240); changed[offsets[i]] ^= 0x80;
        write_bytes(bad, changed, 8240);
        memcpy(got, untouched, sizeof got);
        A2SaveMetadata meta = {123, 456, 789, 234}, old = meta;
        assert(!a2_save_read(bad, got, &meta, error, sizeof error));
        assert(error[0] && memcmp(got, untouched, sizeof got) == 0);
        assert(memcmp(&meta, &old, sizeof meta) == 0);
    }
    const size_t lengths[] = {0, 47, 48, 8239, 8241};
    original[8240] = 0;
    for (unsigned i = 0; i < sizeof lengths / sizeof lengths[0]; i++) {
        write_bytes(bad, original, lengths[i]);
        assert(!a2_save_read(bad, got, NULL, error, sizeof error));
        assert(error[0]);
    }
    /* A valid outer CRC is insufficient: read must also validate the original
     * block. These fixture CRCs were calculated independently, not by store. */
    const unsigned crcs[] = {0x3980bd2d, 0x5867c6e9, 0xff778357};
    for (unsigned which = 0; which < 3; which++) {
        memcpy(changed, original, 8240);
        unsigned char *p = changed + 48;
        if (which == 0) { p[0] = 'X'; put16(p + 0xd8c, 0x4489 + 5); }
        if (which == 1) p[4] = 24;
        if (which == 2) { put16(p + 0x102, 40); put16(p + 0xd8c, 0x4489 + 40); }
        put32(changed + 20, crcs[which]);
        write_bytes(bad, changed, 8240);
        assert(!a2_save_read(bad, got, NULL, error, sizeof error));
        assert(strstr(error, "CRC32") == NULL && error[0]);
    }
}
static void invalid_payload_never_replaces_valid_file(void) {
    char path[1024]; join(path, root, "one.a2save");
    unsigned char good[8192], bad[8192], before[8240], after[8240];
    payload(good, 17);
    assert(a2_save_write(path, good, error, sizeof error));
    assert(read_bytes(path, before, sizeof before) == sizeof before);
    for (unsigned which = 0; which < 4; which++) {
        memcpy(bad, good, sizeof bad);
        if (which == 0) { bad[0] = 'X'; put16(bad + 0xd8c, 0x4483 + 5); }
        if (which == 1) bad[4]++;
        if (which == 2) { put16(bad + 0x102, 40); put16(bad + 0xd8c, 0x4483 + 40); }
        if (which == 3) { put16(bad + 0xc14, 20); put16(bad + 0xd8c, 0x4483 + 6); }
        assert(!a2_save_write(path, bad, error, sizeof error));
        assert(error[0]);
        assert(read_bytes(path, after, sizeof after) == sizeof after);
        assert(memcmp(before, after, sizeof before) == 0);
    }
}
static void symlinks_and_locks_preserve_targets(void) {
    char path[1024], link[1024], lock[1024], dirlink[1024], nested[1024];
    join(path, root, "one.a2save"); join(link, root, "link.a2save");
    join(lock, root, "one.a2save.lock"); join(dirlink, root, "directory-link");
    unsigned char next[8192], before[8240], after[8240]; payload(next, 99);
    assert(read_bytes(path, before, sizeof before) == sizeof before);
    assert(symlink(path, link) == 0);
    assert(!a2_save_write(link, next, error, sizeof error));
    assert(!a2_save_read(link, next, NULL, error, sizeof error));
    assert(symlink(root, dirlink) == 0); join(nested, dirlink, "one.a2save");
    assert(!a2_save_write(nested, next, error, sizeof error));
    int fd = open(lock, O_RDWR); assert(fd >= 0);
    assert(flock(fd, LOCK_EX | LOCK_NB) == 0);
    pid_t child = fork(); assert(child >= 0);
    if (child == 0) {
        close(fd);
        _exit(a2_save_write(path, next, error, sizeof error) ? 9 : 0);
    }
    int status; assert(waitpid(child, &status, 0) == child);
    assert(WIFEXITED(status) && WEXITSTATUS(status) == 0);
    assert(close(fd) == 0);
    assert(read_bytes(path, after, sizeof after) == sizeof after);
    assert(memcmp(before, after, sizeof before) == 0);
    join(lock, root, "locked-by-symlink.a2save.lock");
    assert(symlink(path, lock) == 0); join(link, root, "locked-by-symlink.a2save");
    assert(!a2_save_write(link, next, error, sizeof error));
    assert(access(link, F_OK) != 0);
}
static void failed_partial_write_preserves_old_file(void) {
    char path[1024]; join(path, root, "one.a2save");
    unsigned char next[8192], before[8240], after[8240]; payload(next, 99);
    assert(read_bytes(path, before, sizeof before) == sizeof before);
    pid_t child = fork(); assert(child >= 0);
    if (child == 0) {
        /* A real short write followed by EFBIG, before fsync/rename. */
        struct rlimit limit = {512, 512};
        assert(signal(SIGXFSZ, SIG_IGN) != SIG_ERR);
        assert(setrlimit(RLIMIT_FSIZE, &limit) == 0);
        int ok = a2_save_write(path, next, error, sizeof error);
        _exit(ok || !error[0] ? 9 : 0);
    }
    int status; assert(waitpid(child, &status, 0) == child);
    assert(WIFEXITED(status) && WEXITSTATUS(status) == 0);
    assert(read_bytes(path, after, sizeof after) == sizeof after);
    assert(memcmp(before, after, sizeof before) == 0);
    DIR *d = opendir(root); assert(d); struct dirent *e;
    while ((e = readdir(d))) assert(strncmp(e->d_name, ".a2save.", 8) != 0);
    closedir(d);
}
#ifdef A2_SAVE_STORE_TESTING
/* Catch conflating a successful rename with prepublication failure: callers
 * need to commit the checkpoint even when final directory durability is unknown. */
static void directory_sync_failure_reports_published_payload(void) {
    char path[1024]; join(path, root, "published.a2save");
    unsigned char first[8192], second[8192], got[8192];
    payload(first, 17); payload(second, 23);
    assert(a2_save_write(path, first, error, sizeof error) == A2_SAVE_OK);
    directory_sync_failure = 1;
    assert(a2_save_write(path, second, error, sizeof error) == A2_SAVE_PUBLISHED_UNCERTAIN);
    assert(error[0]);
    directory_sync_failure = 0;
    assert(a2_save_read(path, got, NULL, error, sizeof error));
    assert(memcmp(got, second, sizeof got) == 0);
    assert(a2_save_write(path, first, error, sizeof error) == A2_SAVE_OK);
    assert(!error[0]);
}
#endif
static void sector_checksum(unsigned char *p) {
    p[127] = 0; for (unsigned i = 0; i < 127; i++) p[127] ^= p[i];
}
static void card(unsigned char bytes[131072], unsigned marker) {
    memset(bytes, 0, 131072); memcpy(bytes, "MC", 2); sector_checksum(bytes);
    unsigned char *dir = bytes + 128;
    dir[0] = 0x51; put32(dir + 4, 8192); put16(dir + 8, 0xffff);
    memcpy(dir + 10, "BISCPS-1011500", 15); sector_checksum(dir);
    payload(bytes + 8192, marker);
    /* A foreign allocated file with a bad payload must be ignored. */
    dir = bytes + 256; dir[0] = 0x51; memcpy(dir + 10, "OTHER-GAME", 11);
}
static unsigned imported_count(const char *directory) {
    DIR *d = opendir(directory); assert(d);
    unsigned count = 0; struct dirent *e;
    while ((e = readdir(d))) if (strstr(e->d_name, ".a2save") && !strstr(e->d_name, ".lock")) count++;
    closedir(d); return count;
}
/* Catch ordinary saves overwriting content-addressed imports: a later import
 * must still reach newer card entries instead of failing at the old filename. */
static void imported_snapshots_are_immutable_but_copies_are_writable(void) {
    char cards[1024], saves[1024], first[1024], second[1024], imported[1024], copy[1024];
    join(cards, root, "immutable-cards"); join(saves, root, "immutable-saves");
    assert(mkdir(cards, 0700) == 0);
    join(first, cards, "memcard1.mcr"); join(second, cards, "memcard2.mcr");
    unsigned char *bytes = malloc(131072), *readback = malloc(131072);
    assert(bytes && readback); card(bytes, 17); write_bytes(first, bytes, 131072);
    assert(a2_save_import_cards(cards, saves, error, sizeof error) == A2_SAVE_OK);
    join(imported, saves, "card1-BISCPS-1011500-2CAEB1A3.a2save");
    unsigned char before[8240], after[8240], next[8192], got[8192];
    payload(next, 23);
    assert(read_bytes(imported, before, sizeof before) == sizeof before);
    assert(a2_save_write(imported, next, error, sizeof error) == A2_SAVE_FAILED);
    assert(error[0]);
    assert(read_bytes(imported, after, sizeof after) == sizeof after);
    assert(!memcmp(before, after, sizeof before));
    /* Case aliases resolve to the same file on usual macOS filesystems. */
    join(copy, saves, "CARD1-biscps-1011500-2caeb1a3.A2SAVE");
    assert(a2_save_write(copy, next, error, sizeof error) == A2_SAVE_FAILED);
    join(copy, saves, "checkpoint-1234.a2save");
    assert(a2_save_write(copy, next, error, sizeof error) == A2_SAVE_OK);
    assert(a2_save_read(copy, got, NULL, error, sizeof error));
    assert(!memcmp(got, next, sizeof got));
    card(bytes, 23); write_bytes(second, bytes, 131072);
    assert(a2_save_import_cards(cards, saves, error, sizeof error) == A2_SAVE_OK);
    assert(imported_count(saves) == 3);
    assert(read_bytes(second, readback, 131072) == 131072 && !memcmp(bytes, readback, 131072));
    assert(read_bytes(imported, after, sizeof after) == sizeof after);
    assert(!memcmp(before, after, sizeof before));
    /* The reservation is not a broad ban on user filenames starting card. */
    join(copy, saves, "card1-my-checkpoint.a2save");
    assert(a2_save_write(copy, next, error, sizeof error) == A2_SAVE_OK);
    free(bytes); free(readback);
}
#ifdef A2_SAVE_STORE_TESTING
/* Catch import discarding a published-but-uncertain result or allowing a later
 * successful snapshot to erase the warning. Both cards still must import. */
static void import_propagates_uncertain_publication_without_losing_entries(void) {
    char cards[1024], saves[1024], first[1024], second[1024];
    join(cards, root, "uncertain-cards"); join(saves, root, "uncertain-saves");
    assert(mkdir(cards, 0700) == 0);
    join(first, cards, "memcard1.mcr"); join(second, cards, "memcard2.mcr");
    unsigned char *bytes = malloc(131072); assert(bytes);
    card(bytes, 17); write_bytes(first, bytes, 131072);
    card(bytes, 23); write_bytes(second, bytes, 131072);
    directory_sync_failure = 1;
    assert(a2_save_import_cards(cards, saves, error, sizeof error) == A2_SAVE_PUBLISHED_UNCERTAIN);
    assert(error[0] && imported_count(saves) == 2);
    directory_sync_failure = 0;
    assert(a2_save_import_cards(cards, saves, error, sizeof error) == A2_SAVE_OK);
    assert(!error[0] && imported_count(saves) == 2);
    free(bytes);
}
#endif
static void imports_are_exact_idempotent_and_distinct(void) {
    char cards[1024], saves[1024], first[1024], second[1024], imported[1024];
    join(cards, root, "cards"); join(saves, root, "saves"); assert(mkdir(cards, 0700) == 0);
    join(first, cards, "memcard1.mcr"); join(second, cards, "memcard2.mcr");
    assert(a2_save_import_cards(cards, saves, error, sizeof error));
    assert(imported_count(saves) == 0); /* Missing cards are not reset/created. */
    assert(access(first, F_OK) != 0 && access(second, F_OK) != 0);
    unsigned char *a = malloc(131072), *b = malloc(131072), *readback = malloc(131072);
    assert(a && b && readback); card(a, 17); card(b, 17);
    write_bytes(first, a, 131072); write_bytes(second, b, 131072);
    assert(a2_save_import_cards(cards, saves, error, sizeof error));
    assert(imported_count(saves) == 2);
    join(imported, saves, "card1-BISCPS-1011500-2CAEB1A3.a2save");
    unsigned char before[8240], after[8240], got[8192];
    assert(a2_save_read(imported, got, NULL, error, sizeof error));
    assert(memcmp(got, a + 8192, 8192) == 0);
    assert(read_bytes(imported, before, sizeof before) == sizeof before);
    assert(a2_save_import_cards(cards, saves, error, sizeof error));
    assert(imported_count(saves) == 2);
    assert(read_bytes(imported, after, sizeof after) == sizeof after);
    assert(memcmp(before, after, sizeof before) == 0);
    assert(read_bytes(first, readback, 131072) == 131072 && memcmp(a, readback, 131072) == 0);
    assert(read_bytes(second, readback, 131072) == 131072 && memcmp(b, readback, 131072) == 0);
    card(a, 23); write_bytes(first, a, 131072);
    assert(a2_save_import_cards(cards, saves, error, sizeof error));
    assert(imported_count(saves) == 3);
    for (unsigned which = 0; which < 5; which++) {
        card(a, 17);
        if (which == 0) a[128 + 127] ^= 1;
        if (which == 1) { a[128 + 8] = 0; sector_checksum(a + 128); }
        if (which == 2) { put32(a + 128 + 4, 3584); sector_checksum(a + 128); }
        if (which == 3) a[8192 + 4]++;
        if (which == 4) { a[128 + 10 + 14] = 'x'; sector_checksum(a + 128); }
        write_bytes(first, a, 131072);
        assert(!a2_save_import_cards(cards, saves, error, sizeof error));
        assert(error[0] && imported_count(saves) == 3);
        assert(read_bytes(first, readback, 131072) == 131072 && memcmp(a, readback, 131072) == 0);
    }
    write_bytes(first, a, 100);
    assert(!a2_save_import_cards(cards, saves, error, sizeof error));
    assert(unlink(first) == 0 && symlink(second, first) == 0);
    assert(!a2_save_import_cards(cards, saves, error, sizeof error));
    assert(read_bytes(second, readback, 131072) == 131072 && memcmp(b, readback, 131072) == 0);
    free(a); free(b); free(readback);
}
static void new_save_never_replaces_existing_file(void) {
    char path[1024]; join(path, root, "fresh-only.a2save");
    uint8_t first[8192], second[8192], got[8192], before[8240], after[8240];
    payload(first, 31); payload(second, 47);
    assert(a2_save_write_new(path, first, error, sizeof error) == A2_SAVE_OK);
    assert(read_bytes(path, before, sizeof before) == sizeof before);
    assert(a2_save_write_new(path, second, error, sizeof error) == A2_SAVE_FAILED);
    assert(error[0]);
    assert(read_bytes(path, after, sizeof after) == sizeof after);
    assert(!memcmp(before, after, sizeof before));
    assert(a2_save_read(path, got, NULL, error, sizeof error));
    assert(!memcmp(first, got, sizeof first));
#ifdef A2_SAVE_STORE_TESTING
    join(path, root, "fresh-racing-creator.a2save");
    memcpy(racing_save_bytes, before, sizeof before); new_publish_race = 1;
    assert(a2_save_write_new(path, second, error, sizeof error) == A2_SAVE_FAILED);
    assert(!new_publish_race && error[0]);
    assert(read_bytes(path, after, sizeof after) == sizeof after);
    assert(!memcmp(before, after, sizeof before));
    join(path, root, "fresh-uncertain.a2save");
    directory_sync_failure = 1;
    assert(a2_save_write_new(path, second, error, sizeof error) == A2_SAVE_PUBLISHED_UNCERTAIN);
    assert(error[0]);
    assert(a2_save_read(path, got, NULL, error, sizeof error));
    assert(!memcmp(second, got, sizeof second));
#endif
}
static void cleanup_fixture(const char *path) {
    struct stat st; assert(lstat(path, &st) == 0);
    if (!S_ISDIR(st.st_mode)) { assert(unlink(path) == 0); return; }
    DIR *d = opendir(path); assert(d); struct dirent *e;
    while ((e = readdir(d))) {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
        char child[1024]; join(child, path, e->d_name); cleanup_fixture(child);
    }
    closedir(d); assert(rmdir(path) == 0);
}
int main(void) {
    assert(mkdtemp(root));
    new_save_never_replaces_existing_file();
    roundtrip_and_replacement();
    corrupt_files_leave_outputs_unchanged();
    invalid_payload_never_replaces_valid_file();
    symlinks_and_locks_preserve_targets();
    failed_partial_write_preserves_old_file();
#ifdef A2_SAVE_STORE_TESTING
    directory_sync_failure_reports_published_payload();
#endif
    imported_snapshots_are_immutable_but_copies_are_writable();
#ifdef A2_SAVE_STORE_TESTING
    import_propagates_uncertain_publication_without_losing_entries();
#endif
    imports_are_exact_idempotent_and_distinct();
    cleanup_fixture(root);
    puts("PASS: native save format, validation, atomic replacement, locks and exact card import");
    return 0;
}
