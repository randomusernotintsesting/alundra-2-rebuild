#include "paths.h"
#include <SDL.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include "platform/storage_windows.h"
#endif

A2Paths a2_paths;

static int join(char *out, size_t size, const char *dir, const char *name) {
    int n = snprintf(out, size, "%s%s%s", dir,
                     *dir && dir[strlen(dir)-1] != '/' ? "/" : "", name);
    return n >= 0 && (size_t)n < size;
}

static int regular_file(const char *path) {
#ifdef _WIN32
    return a2w_regular(path);
#else
    struct stat s;
    return stat(path, &s) == 0 && S_ISREG(s.st_mode);
#endif
}

static int mkdirs(const char *path) {
#ifdef _WIN32
    A2WDirectory *d=a2w_directory(path,1);
    if(!d)return 0;
    a2w_directory_close(d);return 1;
#else
    char buf[4096];
    if (snprintf(buf, sizeof buf, "%s", path) >= (int)sizeof buf) return 0;
    for (char *p = buf + 1; ; p++) {
        if (*p && *p != '/') continue;
        char c = *p;
        *p = 0;
        struct stat s;
        if (mkdir(buf, 0700) && errno != EEXIST) return 0;
        if (stat(buf, &s) || !S_ISDIR(s.st_mode)) return 0;
        *p = c;
        if (!c) return 1;
    }
#endif
}

static int disc_exists(const char *dir) {
    char p[4096];
    return join(p, sizeof p, dir, "SCPS_101.15") && regular_file(p);
}

static int paths_init(const char *disc_override, const char *image_override,
                      const char *user, const char *env_disc, const char *env_image,
                      const char *env_archive) {
    memset(&a2_paths, 0, sizeof a2_paths);
    (void)env_archive;
    char *pref = NULL, *base = SDL_GetBasePath();
    if (!user || !*user) user = pref = SDL_GetPrefPath("Alundra2", "Alundra 2");
    if (!user || !*user || !join(a2_paths.user, sizeof a2_paths.user, user, "") ||
        !mkdirs(a2_paths.user) ||
        !join(a2_paths.settings, sizeof a2_paths.settings, user, "a2settings.ini")) {
        snprintf(a2_paths.error, sizeof a2_paths.error,
                 "Cannot create the settings/save directory: %s", user ? user : SDL_GetError());
        SDL_free(base); SDL_free(pref);
        return 0;
    }
    if (base) join(a2_paths.legacy_settings, sizeof a2_paths.legacy_settings,
                   base, "a2settings.ini");
    SDL_free(pref);

    if (!disc_override) disc_override = env_disc;
    if (!image_override) image_override = env_image;
    if(disc_override && !*disc_override)disc_override=NULL;
    if(image_override && !*image_override)image_override=NULL;
#ifdef A2_NATIVE_RESOURCES
    const char *archive=env_archive;
    if(archive && *archive) {
        if(!join(a2_paths.resources,sizeof a2_paths.resources,"",archive))goto too_long;
        if(!regular_file(a2_paths.resources)) {
            snprintf(a2_paths.error,sizeof a2_paths.error,"Native resource archive not found: %.400s",archive);
            SDL_free(base);return 0;
        }
    } else if(!disc_override && !image_override) {
        static const char *candidates[]={"game-data/game.a2r","../Resources/game-data/game.a2r",
            "../game-data/game.a2r"};
        for(unsigned i=0;base && i<sizeof candidates/sizeof candidates[0];i++) {
            if(join(a2_paths.resources,sizeof a2_paths.resources,base,candidates[i]) &&
               regular_file(a2_paths.resources))break;
            a2_paths.resources[0]=0;
        }
    }
    if(a2_paths.resources[0]) {SDL_free(base);return 1;}
#endif
    if (disc_override && *disc_override) {
        if (!join(a2_paths.disc, sizeof a2_paths.disc, disc_override, "")) goto too_long;
    } else {
        static const char *candidates[] = {"game-data/disc", "../Resources/game-data/disc", "../../disc_jp", "../../../disc_jp"};
        for (unsigned i = 0; base && i < sizeof candidates / sizeof candidates[0]; i++) {
            if (join(a2_paths.disc, sizeof a2_paths.disc, base, candidates[i]) && disc_exists(a2_paths.disc)) break;
            a2_paths.disc[0] = 0;
        }
        if (!a2_paths.disc[0] && disc_exists("disc_jp")) strcpy(a2_paths.disc, "disc_jp");
        if (!a2_paths.disc[0] && disc_exists("../disc_jp")) strcpy(a2_paths.disc, "../disc_jp");
    }
    if (image_override && *image_override) {
        if (!join(a2_paths.image, sizeof a2_paths.image, "", image_override)) goto too_long;
    } else {
        /* Locate the image belonging to the selected asset directory. */
        static const char *rel[] = {"../disc.bin", "../build/alundra2_jp.bin"};
        for (unsigned i = 0; a2_paths.disc[0] && i < sizeof rel / sizeof rel[0]; i++) {
            if (join(a2_paths.image, sizeof a2_paths.image, a2_paths.disc, rel[i]) && regular_file(a2_paths.image)) break;
            a2_paths.image[0] = 0;
        }
    }
    SDL_free(base);
    if (!a2_paths.disc[0] || !disc_exists(a2_paths.disc)) {
        snprintf(a2_paths.error, sizeof a2_paths.error, "Game data not found (SCPS_101.15). Supply the extracted Japanese disc directory.");
        return 0;
    }
    if (!a2_paths.image[0] || !regular_file(a2_paths.image)) {
        snprintf(a2_paths.error, sizeof a2_paths.error, "Disc image not found. Supply --boot /path/to/alundra2_jp.bin.");
        return 0;
    }
    return 1;
too_long:
    SDL_free(base);
    snprintf(a2_paths.error, sizeof a2_paths.error, "A game data path is too long.");
    return 0;
}

int a2_paths_init(const char *disc_override,const char *image_override) {
#ifdef _WIN32
    char *user=a2w_getenv(L"A2_USER_DIR"),*disc=a2w_getenv(L"A2_DISC_ROOT");
    char *image=a2w_getenv(L"A2_DISC_IMAGE"),*archive=a2w_getenv(L"A2_RESOURCE_ARCHIVE");
    int ok=paths_init(disc_override,image_override,user,disc,image,archive);
    free(user);free(disc);free(image);free(archive);return ok;
#else
    return paths_init(disc_override,image_override,SDL_getenv("A2_USER_DIR"),
        SDL_getenv("A2_DISC_ROOT"),SDL_getenv("A2_DISC_IMAGE"),SDL_getenv("A2_RESOURCE_ARCHIVE"));
#endif
}
