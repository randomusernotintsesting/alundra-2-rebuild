/* The fixture is independently encoded by test_native_resources.py. */
#include "a2_resources.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv) {
    assert(argc>=3);
    A2Resources *s=NULL;char error[256];
    int opened=a2_resources_open(argv[2],&s,error,sizeof error);
    if(!strcmp(argv[1],"reject")) { assert(!opened && !s && error[0]);return 0; }
    assert(opened && s);
    if(!strcmp(argv[1],"extract")) {
        assert(argc==6);A2ResourceId id=a2_resource_find(s,atoi(argv[3]),argv[4]);assert(id);
        FILE *out=fopen(argv[5],"wb");assert(out);uint8_t buf[997],first[997];
        size_t first_length=a2_resource_size(s,id)<sizeof first?(size_t)a2_resource_size(s,id):sizeof first;
        assert(a2_resource_pread(s,id,0,first,first_length,error,sizeof error));
        for(uint64_t off=0,n=a2_resource_size(s,id);off<n;) {
            size_t amount=n-off<sizeof buf?(size_t)(n-off):sizeof buf;
            assert(a2_resource_pread(s,id,off,buf,amount,error,sizeof error));
            assert(fwrite(buf,1,amount,out)==amount);off+=amount;
        }
        assert(a2_resource_pread(s,id,0,buf,first_length,error,sizeof error));
        assert(!memcmp(buf,first,first_length));
        assert(!fclose(out));a2_resources_close(s);return 0;
    }
    A2ResourceId id=a2_resource_find(s,0,"DATA/SHARED");assert(id);
    if(!strcmp(argv[1],"bad-payload")) {
        uint8_t data[6];assert(!a2_resource_pread(s,id,0,data,sizeof data,error,sizeof error));
        assert(error[0]);a2_resources_close(s);return 0;
    }
    assert(a2_resources_profiles(s)==7);
    assert(id==a2_resource_find(s,1,"DATA/SHARED"));
    uint8_t data[16]={0};
    assert(a2_resource_size(s,id)==6);
    assert(a2_resource_pread(s,id,0,data,6,error,sizeof error));assert(!memcmp(data,"ABCxxx",6));
    assert(a2_resource_pread(s,id,2,data,3,error,sizeof error));assert(!memcmp(data,"Cxx",3));
    assert(a2_resource_pread(s,id,6,NULL,0,error,sizeof error));
    memset(data,0xA5,sizeof data);
    assert(!a2_resource_pread(s,id,5,data,2,error,sizeof error));assert(data[0]==0xA5);
    assert(!a2_resource_pread(s,id,UINT64_MAX,data,1,error,sizeof error));
    assert(!a2_resource_pread(s,id,0,NULL,1,error,sizeof error));
    assert(!a2_resource_pread(s,0,0,data,1,error,sizeof error));
    assert(!a2_resource_find(s,0,"../DATA/SHARED"));assert(!a2_resource_find(s,-1,"DATA/SHARED"));
    assert(!a2_resource_find(s,2,"MISSING"));
    A2ResourceId ru=a2_resource_find(s,0,"LABEL");A2ResourceId ja=a2_resource_find(s,1,"LABEL");
    assert(ru && ja && ru!=ja && ja==a2_resource_find(s,2,"LABEL"));
    assert(a2_resource_pread(s,ru,0,data,2,error,sizeof error));assert(!memcmp(data,"RU",2));
    A2ResourceId empty=a2_resource_find(s,0,"EMPTY");assert(empty && !a2_resource_size(s,empty));
    assert(a2_resource_pread(s,empty,0,NULL,0,error,sizeof error));
    a2_resources_close(s);a2_resources_close(NULL);puts("native resource fixture passed");return 0;
}
