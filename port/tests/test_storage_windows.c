#include "native_save_store.h"
#include "save_browser_model.h"
#include "platform/storage_windows.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static char error[512];
static int fail_post_publish;
int a2w_test_after_publish(void) {return !fail_post_publish;}
static void payload(uint8_t p[8192],unsigned marker) {
    memset(p,0,8192);memcpy(p,"SC\x11\x01",4);p[4]=(uint8_t)marker;p[0xc14]=14;
    unsigned sum=0;for(unsigned i=0;i<0xd8c;i+=2)sum+=p[i]|p[i+1]<<8;
    p[0xd8c]=(uint8_t)sum;p[0xd8d]=(uint8_t)(sum>>8);p[8191]=(uint8_t)(marker^0x5a);
}
static void roundtrip(const char *path) {
    uint8_t p[8192],got[8192],file[8240];payload(p,17);
    assert(a2_save_write_new(path,p,error,sizeof error)==A2_SAVE_OK);
    A2SaveMetadata meta;if(!a2_save_read(path,got,&meta,error,sizeof error)){fprintf(stderr,"read: %s\n",error);abort();}
    assert(!memcmp(p,got,sizeof p)&&meta.scene==14&&meta.location_index==0&&meta.payload_crc32==0x2caeb1a3);
    assert(!a2_save_write_new(path,p,error,sizeof error));
    payload(p,23);assert(a2_save_write(path,p,error,sizeof error)==A2_SAVE_OK);
    assert(a2_save_read(path,got,NULL,error,sizeof error)&&!memcmp(p,got,sizeof p));
    A2WTarget t;assert(a2w_target(path,&t));assert(a2w_read(t.dir,t.name,file,sizeof file));
    assert(!memcmp(file,"A2SAVE\r\n",8)&&file[8]==1&&file[12]==48&&file[17]==32);
    for(unsigned kind=0;kind<4;kind++) {
        uint8_t bad[8241];memcpy(bad,file,sizeof file);bad[8240]=0;
        size_t n=kind==0?123:kind==1?8241:8240;
        if(kind==2)bad[0]='?';
        if(kind==3)bad[48+8191]^=1;
        assert(a2w_publish(t.dir,t.name,bad,n,0)==1);
        memset(got,0xa5,sizeof got);memset(&meta,0x5a,sizeof meta);A2SaveMetadata before=meta;
        assert(!a2_save_read(path,got,&meta,error,sizeof error));
        for(unsigned i=0;i<sizeof got;i++)assert(got[i]==0xa5);
        assert(!memcmp(&meta,&before,sizeof meta));
        uint8_t check[8241];assert(a2w_read(t.dir,t.name,check,n)&&!memcmp(bad,check,n));
    }
    assert(a2w_publish(t.dir,t.name,file,sizeof file,0)==1);a2w_directory_close(t.dir);
    puts("PASS container roundtrip/replacement/independent CRC/no-replace/corrupt+truncated+trailing failures preserve buffers and disk");
}
int wmain(int argc,wchar_t **argv) {
    assert(argc>=3);char *command=a2w_utf8(argv[1]),*path=a2w_utf8(argv[2]);assert(command&&path);
    unsigned marker=argc>3?(unsigned)_wtoi(argv[3]):17;uint8_t p[8192],got[8192];payload(p,marker);int result=0;
    if(!strcmp(command,"roundtrip"))roundtrip(path);
    else if(!strcmp(command,"uncertain")){
        fail_post_publish=1;
        assert(a2_save_write_new(path,p,error,sizeof error)==A2_SAVE_PUBLISHED_UNCERTAIN);
        assert(error[0]&&a2_save_browser_durability_warning(error));
        assert(a2_save_read(path,got,NULL,error,sizeof error)&&!memcmp(p,got,sizeof p));
        puts("PASS deterministic post-publication sync failure returns PUBLISHED_UNCERTAIN, published bytes readable");
    }
    else if(!strcmp(command,"write")||!strcmp(command,"new"))result=!(command[0]=='n'?a2_save_write_new(path,p,error,sizeof error):a2_save_write(path,p,error,sizeof error));
    else if(!strcmp(command,"read"))result=!a2_save_read(path,got,NULL,error,sizeof error)||memcmp(p,got,sizeof p)!=0;
    else if(!strcmp(command,"invalid")){
        memset(got,0xa5,sizeof got);assert(!a2_save_read(path,got,NULL,error,sizeof error));
        for(unsigned i=0;i<sizeof got;i++)assert(got[i]==0xa5);
        assert(!a2_save_write(path,p,error,sizeof error));
    } else if(!strcmp(command,"lock")||!strcmp(command,"pin")){
        A2WTarget t;assert(a2w_target(path,&t));HANDLE lock=INVALID_HANDLE_VALUE;
        if(!strcmp(command,"lock")){char name[1040];snprintf(name,sizeof name,"%s.lock",t.name);lock=a2w_lock(t.dir,name);assert(lock!=INVALID_HANDLE_VALUE);}
        puts("READY");fflush(stdout);assert(getchar()!=EOF);
        if(lock!=INVALID_HANDLE_VALUE)CloseHandle(lock);
        a2w_directory_close(t.dir);
    } else if(!strcmp(command,"raw-new")){
        A2WTarget t;assert(a2w_target(path,&t));result=!a2w_publish(t.dir,t.name,p,sizeof p,1);a2w_directory_close(t.dir);
    } else if(!strcmp(command,"import")){
        char saves[4096];assert(snprintf(saves,sizeof saves,"%s/Saves",path)<(int)sizeof saves);
        result=!a2_save_import_cards(path,saves,error,sizeof error);
    } else if(!strcmp(command,"browser")){
        A2SaveBrowser browser={0};assert(a2_save_browser_open(&browser,path,1,error,sizeof error));
        assert(browser.count>0&&browser.rows[0].fresh);
        assert(a2_save_browser_accept(&browser,0,p,error,sizeof error));a2_save_browser_dispose(&browser);
    } else if(!strcmp(command,"immutable"))assert(!a2_save_write(path,p,error,sizeof error)&&!a2_save_write_new(path,p,error,sizeof error));
    else assert(!"unknown command");
    if(result)fprintf(stderr,"FAILED %s: %s (Windows %lu)\n",command,error,GetLastError());
    free(command);free(path);return result;
}
