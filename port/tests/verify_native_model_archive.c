/* Offline diagnostic: exact archived model bytes and real C loader in all languages. */
#include "native_model.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv) {
    if(argc!=4){fprintf(stderr,"usage: %s archive T02.A2M T03.A2M\n",argv[0]);return 2;}
    A2Resources *store=NULL;char error[256];
    if(!a2_resources_open(argv[1],&store,error,sizeof error)){fprintf(stderr,"%s\n",error);return 1;}
    const char *keys[]={"T02","T03"};
    for(unsigned k=0;k<2;k++) {
        FILE *f=fopen(argv[k+2],"rb");assert(f);assert(!fseek(f,0,SEEK_END));long length=ftell(f);
        assert(length>0&&(unsigned long)length<=A2_MODEL_MAX_BYTES);rewind(f);
        unsigned char *expected=malloc((size_t)length),*actual=malloc((size_t)length);assert(expected&&actual);
        assert(fread(expected,1,(size_t)length,f)==(size_t)length);assert(!fclose(f));
        char logical[32];snprintf(logical,sizeof logical,"MODELS/%s.A2M",keys[k]);
        for(int language=0;language<3;language++) {
            A2ResourceId id=a2_resource_find(store,language,logical);assert(id);
            assert(a2_resource_size(store,id)==(uint64_t)length);
            assert(a2_resource_pread(store,id,0,actual,(size_t)length,error,sizeof error));
            assert(!memcmp(expected,actual,(size_t)length));
            A2NativeModel *model=NULL;
            if(!a2_native_model_load(store,id,&model,error,sizeof error)){fprintf(stderr,"%s\n",error);return 1;}
            assert(!strcmp(model->source_key,keys[k]));assert(model->joint_count==2);
            assert(model->joints[0].source_id==0&&model->joints[1].source_id==1);
            printf("{\"key\":\"%s\",\"language\":%d,\"bytes_equal\":true,\"vertices\":%u,\"triangles\":%u,\"materials\":%u,\"joints\":%u}\n",
                keys[k],language,model->vertex_count,model->index_count/3,model->material_count,model->joint_count);
            a2_native_model_destroy(model);
        }
        free(expected);free(actual);
    }
    a2_resources_close(store);return 0;
}
