#ifndef A2_STORAGE_WINDOWS_H
#define A2_STORAGE_WINDOWS_H
#ifdef _WIN32
#include <stddef.h>
#include <stdio.h>
#include <windows.h>

typedef struct A2WDirectory A2WDirectory;
typedef struct A2WTarget { A2WDirectory *dir; char name[1024]; } A2WTarget;
int a2w_random(void *bytes, size_t size);
wchar_t *a2w_utf16(const char *path);
char *a2w_utf8(const wchar_t *path);
char *a2w_getenv(const wchar_t *name);
int a2w_setenv(const char *name, const char *value, int overwrite);
A2WDirectory *a2w_directory(const char *path, int create);
void a2w_directory_close(A2WDirectory *dir);
int a2w_target(const char *path, A2WTarget *target);
/* 1 regular single-link file; 0 absent; -1 unsafe or inaccessible. */
int a2w_exists(A2WDirectory *dir, const char *name);
int a2w_read(A2WDirectory *dir, const char *name, void *bytes, size_t size);
HANDLE a2w_lock(A2WDirectory *dir, const char *name);
/* 0 unchanged; 1 published; 2 published, but post-publication sync/close failed.
 * Windows offers no portable directory fsync: power-loss durability is unproven. */
int a2w_publish(A2WDirectory *dir, const char *name, const void *bytes, size_t size, int new_only);
int a2w_list(A2WDirectory *dir, char ***names, size_t *count);
FILE *a2w_fopen(const char *path, const wchar_t *mode);
int a2w_atomic_stream(const char *path, A2WTarget *target, HANDLE *file, FILE **stream);
int a2w_commit_stream(A2WTarget *target, HANDLE file, FILE *stream, int failed);
int a2w_regular(const char *path);
#endif
#endif
