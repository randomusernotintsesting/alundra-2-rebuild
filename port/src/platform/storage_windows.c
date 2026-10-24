#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif
#include "storage_windows.h"
#include <bcrypt.h>
#include <fcntl.h>
#include <io.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

struct A2WDirectory {
    wchar_t *path;
    HANDLE *pins;
    size_t count;
};

wchar_t *a2w_utf16(const char *s) {
    if (!s || !*s) return NULL;
    int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s, -1, NULL, 0);
    if (!n || n > 32760) return NULL;
    wchar_t *w = malloc((size_t)n * sizeof *w);
    if (w && !MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s, -1, w, n)) { free(w); w = NULL; }
    return w;
}
char *a2w_utf8(const wchar_t *w) {
    int n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w, -1, NULL, 0, NULL, NULL);
    if (!n) return NULL;
    char *s = malloc((size_t)n);
    if (s && !WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w, -1, s, n, NULL, NULL)) { free(s); s = NULL; }
    return s;
}
int a2w_random(void *p, size_t n) {
    return n <= ULONG_MAX && BCryptGenRandom(NULL, p, (ULONG)n, BCRYPT_USE_SYSTEM_PREFERRED_RNG) == 0;
}
char *a2w_getenv(const wchar_t *name) {
    DWORD n=GetEnvironmentVariableW(name,NULL,0);
    if(!n)return NULL;
    wchar_t *w=malloc((size_t)n*sizeof *w);if(!w)return NULL;
    DWORD used=GetEnvironmentVariableW(name,w,n);
    if(!used||used>=n){free(w);return NULL;}
    char *s=a2w_utf8(w);free(w);return s;
}
int a2w_setenv(const char *name,const char *value,int overwrite) {
    if(!overwrite&&getenv(name))return 0;
    wchar_t *wname=a2w_utf16(name),*wvalue=value&&*value?a2w_utf16(value):NULL;
    if(!wname||(value&&*value&&!wvalue)){free(wname);free(wvalue);return -1;}
    int ok=_wputenv_s(wname,wvalue?wvalue:L"")==0&&SetEnvironmentVariableW(wname,wvalue);
    free(wname);free(wvalue);return ok?0:-1;
}
static int component(const wchar_t *s) {
    size_t n = wcslen(s);
    if (!n || n > 255 || s[n-1] == L'.' || s[n-1] == L' ') return 0;
    for (size_t i=0; i<n; i++) if (s[i]<32 || wcschr(L"<>:\"/\\|?*",s[i])) return 0;
    wchar_t base[256]; wcscpy(base,s);
    wchar_t *dot=wcschr(base,L'.'); if(dot)*dot=0;
    if (!_wcsicmp(base,L"CON") || !_wcsicmp(base,L"PRN") || !_wcsicmp(base,L"AUX") || !_wcsicmp(base,L"NUL")) return 0;
    if (wcslen(base)==4 && (!_wcsnicmp(base,L"COM",3) || !_wcsnicmp(base,L"LPT",3)) && base[3]>=L'1' && base[3]<=L'9') return 0;
    return 1;
}
static int info(HANDLE h, int directory) {
    BY_HANDLE_FILE_INFORMATION i;
    return h != INVALID_HANDLE_VALUE && GetFileType(h)==FILE_TYPE_DISK && GetFileInformationByHandle(h,&i) &&
        !(i.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) &&
        !!(i.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==directory && (directory || i.nNumberOfLinks==1);
}
void a2w_directory_close(A2WDirectory *d) {
    if(!d)return;
    while(d->count)CloseHandle(d->pins[--d->count]);
    free(d->pins);free(d->path);free(d);
}
static int pin(A2WDirectory *d, int create) {
    if(create && !CreateDirectoryW(d->path,NULL) && GetLastError()!=ERROR_ALREADY_EXISTS) return 0;
    HANDLE h=CreateFileW(d->path,FILE_LIST_DIRECTORY|FILE_READ_ATTRIBUTES,
        FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS|FILE_FLAG_OPEN_REPARSE_POINT,NULL);
    if(!info(h,1)){if(h!=INVALID_HANDLE_VALUE)CloseHandle(h);return 0;}
    HANDLE *p=realloc(d->pins,(d->count+1)*sizeof *p);
    if(!p){CloseHandle(h);return 0;} d->pins=p;d->pins[d->count++]=h;return 1;
}
A2WDirectory *a2w_directory(const char *path,int create) {
    wchar_t *input=a2w_utf16(path);if(!input)return NULL;
    for(wchar_t *p=input;*p;p++)if(*p==L'/')*p=L'\\';
    /* Reject device namespaces and drive-relative forms; ordinary UNC roots
     * are pinned just like drive roots, before opening each child. */
    if(!wcsncmp(input,L"\\\\?\\",4)||!wcsncmp(input,L"\\\\.\\",4)||
       (input[0] && input[1]==L':' && input[2]!=L'\\')){free(input);return NULL;}
    DWORD n=GetFullPathNameW(input,0,NULL,NULL);if(!n||n>32760){free(input);return NULL;}
    wchar_t *full=calloc((size_t)n+1,sizeof *full);
    if(!full || !GetFullPathNameW(input,n,full,NULL)){free(input);free(full);return NULL;}free(input);
    size_t len=wcslen(full),root=0;
    if(len>=3 && full[1]==L':' && full[2]==L'\\')root=3;
    else if(len>4 && full[0]==L'\\'&&full[1]==L'\\'){
        wchar_t *server=wcschr(full+2,L'\\');
        if(server && server>full+2){wchar_t *share=wcschr(server+1,L'\\');root=share?(size_t)(share-full):len; if(root==(size_t)(server-full)+1)root=0;}
    }
    if(!root){free(full);return NULL;}
    while(len>root && full[len-1]==L'\\')full[--len]=0;
    A2WDirectory *d=calloc(1,sizeof *d);if(!d){free(full);return NULL;}
    /* Extended-length paths avoid MAX_PATH without accepting caller-supplied
     * device paths. All components below are checked before use. */
    size_t prefix=full[0]==L'\\'?6:4;
    d->path=calloc(len+prefix+1,sizeof *d->path);
    if(!d->path){free(full);free(d);return NULL;}
    if(prefix==4)wcscpy(d->path,L"\\\\?\\");else wcscpy(d->path,L"\\\\?\\UNC\\");
    wcsncat(d->path,full+(prefix==6?2:0),root-(prefix==6?2:0));
    if(!pin(d,0))goto bad;
    for(size_t pos=root;pos<len;){
        if(full[pos]==L'\\')pos++;
        size_t end=pos;while(end<len&&full[end]!=L'\\')end++;
        wchar_t saved=full[end];full[end]=0;
        if(!component(full+pos)){full[end]=saved;goto bad;}
        size_t used=wcslen(d->path);if(d->path[used-1]!=L'\\')wcscat(d->path,L"\\");wcscat(d->path,full+pos);
        full[end]=saved;if(!pin(d,create))goto bad;pos=end;
    }
    DWORD actual=GetFinalPathNameByHandleW(d->pins[d->count-1],NULL,0,FILE_NAME_NORMALIZED|VOLUME_NAME_DOS);
    if(!actual||actual>32760)goto bad;
    wchar_t *resolved=calloc((size_t)actual+1,sizeof *resolved);
    if(!resolved)goto bad;
    DWORD used=GetFinalPathNameByHandleW(d->pins[d->count-1],resolved,actual+1,FILE_NAME_NORMALIZED|VOLUME_NAME_DOS);
    if(!used||used>actual){free(resolved);goto bad;}
    free(d->path);d->path=resolved;
    free(full);return d;
bad:free(full);a2w_directory_close(d);return NULL;
}
static wchar_t *child(A2WDirectory *d,const char *name){
    wchar_t *w=a2w_utf16(name);if(!w)return NULL;
    if(!component(w)){free(w);return NULL;}
    size_t n=wcslen(d->path)+wcslen(w)+2;
    wchar_t *p=malloc(n*sizeof *p);if(p)swprintf(p,n,L"%ls\\%ls",d->path,w);free(w);return p;
}
int a2w_target(const char *path,A2WTarget *t){
    memset(t,0,sizeof *t);if(!path)return 0;
    const char *a=strrchr(path,'/'),*b=strrchr(path,'\\'),*slash=a;
    if(b&&(!a||b>a))slash=b;
    const char *name=slash?slash+1:path;size_t n=strlen(name);
    if(!n||n>=sizeof t->name)return 0;
    wchar_t *w=a2w_utf16(name);if(!w)return 0;int valid=component(w);free(w);if(!valid)return 0;
    char *parent=slash?malloc((size_t)(slash-path)+2):strdup(".");if(!parent)return 0;
    if(slash){size_t k=(size_t)(slash-path);if(k==2&&path[1]==':')k++;if(!k)k=1;memcpy(parent,path,k);parent[k]=0;}
    t->dir=a2w_directory(parent,0);free(parent);if(!t->dir)return 0;memcpy(t->name,name,n+1);return 1;
}
static HANDLE open_child(A2WDirectory *d,const char *name,DWORD access,DWORD share,DWORD disposition){
    wchar_t *p=child(d,name);if(!p){SetLastError(ERROR_INVALID_NAME);return INVALID_HANDLE_VALUE;}
    HANDLE h=CreateFileW(p,access,share,NULL,disposition,FILE_FLAG_OPEN_REPARSE_POINT,NULL);free(p);
    if(h!=INVALID_HANDLE_VALUE&&!info(h,0)){CloseHandle(h);SetLastError(ERROR_ACCESS_DENIED);return INVALID_HANDLE_VALUE;}return h;
}
int a2w_exists(A2WDirectory *d,const char *name){
    HANDLE h=open_child(d,name,FILE_READ_ATTRIBUTES,FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,OPEN_EXISTING);
    if(h==INVALID_HANDLE_VALUE)return GetLastError()==ERROR_FILE_NOT_FOUND?0:-1;
    CloseHandle(h);return 1;
}
int a2w_read(A2WDirectory *d,const char *name,void *bytes,size_t size){
    HANDLE h=open_child(d,name,GENERIC_READ,FILE_SHARE_READ,OPEN_EXISTING);if(h==INVALID_HANDLE_VALUE)return 0;
    LARGE_INTEGER n;int ok=GetFileSizeEx(h,&n)&&n.QuadPart==(LONGLONG)size;
    size_t pos=0;while(ok&&pos<size){DWORD got=0,chunk=(DWORD)((size-pos)>1048576?1048576:size-pos);ok=ReadFile(h,(char*)bytes+pos,chunk,&got,NULL)&&got;pos+=got;}
    unsigned char extra;DWORD got=0;if(ok)ok=ReadFile(h,&extra,1,&got,NULL)&&!got;
    if(!CloseHandle(h))ok=0;
    return ok;
}
HANDLE a2w_lock(A2WDirectory *d,const char *name){
    return open_child(d,name,GENERIC_READ|GENERIC_WRITE,0,OPEN_ALWAYS);
}
static HANDLE temporary(A2WDirectory *d){
    for(int attempt=0;attempt<16;attempt++){
        unsigned char bytes[16];if(!a2w_random(bytes,sizeof bytes))return INVALID_HANDLE_VALUE;
        char name[64]=".a2tmp-";for(unsigned i=0;i<16;i++)snprintf(name+7+2*i,3,"%02x",bytes[i]);
        HANDLE h=open_child(d,name,GENERIC_READ|GENERIC_WRITE|DELETE,0,CREATE_NEW);
        if(h!=INVALID_HANDLE_VALUE)return h;
        if(GetLastError()!=ERROR_FILE_EXISTS)return INVALID_HANDLE_VALUE;
    }return INVALID_HANDLE_VALUE;
}
static void discard(HANDLE h){FILE_DISPOSITION_INFO i={TRUE};SetFileInformationByHandle(h,FileDispositionInfo,&i,sizeof i);}
static int publish(A2WDirectory *d,const char *name,HANDLE h,int new_only){
    int exists=a2w_exists(d,name);if(exists<0||(exists&&new_only))return 0;
    wchar_t *p=child(d,name);if(!p)return 0;
    size_t bytes=wcslen(p)*sizeof *p,sz=sizeof(FILE_RENAME_INFO)+bytes;
    FILE_RENAME_INFO *i=calloc(1,sz);if(!i){free(p);return 0;}
    i->ReplaceIfExists=!new_only;i->FileNameLength=(DWORD)bytes;memcpy(i->FileName,p,bytes);
    int ok=SetFileInformationByHandle(h,FileRenameInfo,i,(DWORD)sz);free(i);free(p);return ok;
}
static int published_flush(HANDLE h) {
    int ok=FlushFileBuffers(h);
#ifdef A2_STORAGE_WINDOWS_TESTING
    extern int a2w_test_after_publish(void);
    if(!a2w_test_after_publish())ok=0;
#endif
    return ok;
}
int a2w_publish(A2WDirectory *d,const char *name,const void *bytes,size_t size,int new_only){
    HANDLE h=temporary(d);if(h==INVALID_HANDLE_VALUE)return 0;
    int ok=1;size_t pos=0;
    while(ok&&pos<size){DWORD n=0,chunk=(DWORD)((size-pos)>1048576?1048576:size-pos);ok=WriteFile(h,(const char*)bytes+pos,chunk,&n,NULL)&&n;pos+=n;}
    if(ok)ok=FlushFileBuffers(h);
    if(ok)ok=publish(d,name,h,new_only);
    if(!ok)discard(h);
    else if(!published_flush(h))ok=2;
    if(!CloseHandle(h)&&ok)ok=2;
    return ok;
}
int a2w_list(A2WDirectory *d,char ***names,size_t *count){
    *names=NULL;*count=0;size_t n=wcslen(d->path)+3;wchar_t *pattern=malloc(n*sizeof *pattern);if(!pattern)return 0;
    swprintf(pattern,n,L"%ls\\*",d->path);WIN32_FIND_DATAW data;
    HANDLE h=FindFirstFileW(pattern,&data);free(pattern);
    if(h==INVALID_HANDLE_VALUE)return GetLastError()==ERROR_FILE_NOT_FOUND;
    int ok=1;do{if(!wcscmp(data.cFileName,L".")||!wcscmp(data.cFileName,L".."))continue;
        char *s=a2w_utf8(data.cFileName);char **p=realloc(*names,(*count+1)*sizeof *p);
        if(p)*names=p;
        if(!s||!p){free(s);ok=0;break;}(*names)[(*count)++]=s;
    }while(FindNextFileW(h,&data));
    if(ok&&GetLastError()!=ERROR_NO_MORE_FILES)ok=0;
    FindClose(h);return ok;
}
FILE *a2w_fopen(const char *path,const wchar_t *mode){
    A2WTarget t;if(!a2w_target(path,&t))return NULL;
    HANDLE h=open_child(t.dir,t.name,GENERIC_READ,FILE_SHARE_READ,OPEN_EXISTING);a2w_directory_close(t.dir);
    if(h==INVALID_HANDLE_VALUE)return NULL;
    int fd=_open_osfhandle((intptr_t)h,_O_RDONLY|_O_BINARY);if(fd<0){CloseHandle(h);return NULL;}
    FILE *f=_wfdopen(fd,mode);if(!f)_close(fd);return f;
}
int a2w_atomic_stream(const char *path,A2WTarget *t,HANDLE *file,FILE **stream){
    if(!a2w_target(path,t))return 0;
    *file=temporary(t->dir);
    if(*file==INVALID_HANDLE_VALUE){a2w_directory_close(t->dir);return 0;}
    HANDLE duplicate;if(!DuplicateHandle(GetCurrentProcess(),*file,GetCurrentProcess(),&duplicate,0,FALSE,DUPLICATE_SAME_ACCESS)){discard(*file);CloseHandle(*file);a2w_directory_close(t->dir);return 0;}
    int fd=_open_osfhandle((intptr_t)duplicate,_O_WRONLY|_O_BINARY);
    if(fd<0){CloseHandle(duplicate);discard(*file);CloseHandle(*file);a2w_directory_close(t->dir);return 0;}
    *stream=_fdopen(fd,"wb");if(!*stream){_close(fd);discard(*file);CloseHandle(*file);a2w_directory_close(t->dir);return 0;}return 1;
}
int a2w_commit_stream(A2WTarget *t,HANDLE h,FILE *f,int failed){
    if(fflush(f))failed=1;
    if(!FlushFileBuffers(h))failed=1;
    if(fclose(f))failed=1;
    int ok=!failed&&publish(t->dir,t->name,h,0);
    if(!ok)discard(h);
    else if(!published_flush(h))ok=2;
    if(!CloseHandle(h)&&ok)ok=2;
    a2w_directory_close(t->dir);return ok;
}
int a2w_regular(const char *path){A2WTarget t;if(!a2w_target(path,&t))return 0;int ok=a2w_exists(t.dir,t.name)==1;a2w_directory_close(t.dir);return ok;}
#endif
