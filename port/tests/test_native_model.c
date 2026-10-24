#include "native_model.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Hand-authored independent little-endian fixture, not encoder round-trip. */
static unsigned char fixture[920], trial[920];
static void u32(unsigned char *p, uint32_t x) { for(int i=0;i<4;i++)p[i]=(unsigned char)(x>>(8*i)); }
static void u64(unsigned char *p, uint64_t x) { for(int i=0;i<8;i++)p[i]=(unsigned char)(x>>(8*i)); }
static void f32(unsigned char *p, float x) { uint32_t u;memcpy(&u,&x,4);u32(p,u); }
static void make_fixture(void) {
    memset(fixture,0,sizeof fixture); memcpy(fixture,"A2M2",4);
    u32(fixture+8,1);u32(fixture+12,256);u64(fixture+16,sizeof fixture);
    const uint32_t counts[]={3,3,1,1,1,1};
    const uint64_t offsets[]={256,544,552,680,824,872};
    for(int i=0;i<6;i++){u32(fixture+32+4*i,counts[i]);u64(fixture+64+8*i,offsets[i]);}
    u32(fixture+56,2);u64(fixture+112,904);u64(fixture+120,16);
    memset(fixture+128,0x21,32);memcpy(fixture+160,"T02",3);
    f32(fixture+204,1);f32(fixture+208,1);
    for(int v=0;v<3;v++){
        unsigned char *p=fixture+256+v*96;
        if(v)f32(p+4*(v-1),1);
        f32(p+20,1);
        for(int i=0;i<8;i++)f32(p+40+4*i,1);
        f32(p+80,1);
    }
    fixture[546]=1;fixture[548]=2;
    unsigned char *m=fixture+552;
    u32(m+12,UINT32_MAX);for(int i=0;i<4;i++)f32(m+16+4*i,1);
    f32(m+32,.5f);f32(m+44,1);f32(m+48,.5f);f32(m+52,1.45f);
    memcpy(m+80,"wood",4);
    unsigned char *j=fixture+680;u32(j+4,UINT32_MAX);u32(j+8,1);
    for(int i=0;i<4;i++){f32(j+16+20*i,1);f32(j+80+20*i,1);}
    unsigned char *s=fixture+824;u32(s+4,3);f32(s+28,1);f32(s+32,1);
    unsigned char *t=fixture+872;u32(t,2);u32(t+4,2);u64(t+16,16);u32(t+24,1);
    const unsigned char pixels[]={255,0,0,255,0,255,0,255,0,0,255,255,255,255,255,255};
    memcpy(fixture+904,pixels,16);
}
static void rejected(size_t size) {
    A2NativeModel *m=NULL;char error[200]={0};
    assert(!a2_native_model_decode(trial,size,&m,error,sizeof error));
    assert(!m && error[0]);
}
static void signed_color_contract(void){
    A2NativeModel *m=NULL;char error[200];
    memcpy(trial,fixture,sizeof trial);u32(trial+24,1);
    const float values[]={-16,.25f,16,1,-.07422932237386703f,1.0063167810440063f,.5f,0};
    for(unsigned i=0;i<8;i++)f32(trial+296+4*i,values[i]);
    assert(a2_native_model_decode(trial,sizeof trial,&m,error,sizeof error));
    assert(m->file_flags==A2_MODEL_SIGNED_CORNER_RGB);
    for(unsigned layer=0;layer<2;layer++)for(unsigned c=0;c<4;c++)
        assert(!memcmp(&m->vertices[0].color[layer][c],&values[layer*4+c],4));
    a2_native_model_destroy(m);u32(trial+24,0);rejected(sizeof trial);
    const float bad[]={-16.01f,16.01f,NAN,INFINITY,-INFINITY};
    for(unsigned layer=0;layer<2;layer++)for(unsigned c=0;c<3;c++)for(unsigned i=0;i<5;i++){
        memcpy(trial,fixture,sizeof trial);u32(trial+24,1);f32(trial+296+16*layer+4*c,bad[i]);rejected(sizeof trial);
    }
    for(unsigned layer=0;layer<2;layer++)for(unsigned i=0;i<2;i++){
        memcpy(trial,fixture,sizeof trial);u32(trial+24,1);f32(trial+308+16*layer,i?1.001f:-.001f);rejected(sizeof trial);
    }
    memcpy(trial,fixture,sizeof trial);u32(trial+24,1);f32(trial+568,-.1f);rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);u32(trial+24,3);rejected(sizeof trial);
}
int main(int argc,char **argv) {
    make_fixture();signed_color_contract();A2NativeModel *m=NULL;char error[200];
    assert(a2_native_model_decode(fixture,sizeof fixture,&m,error,sizeof error));
    assert(m && m->file_flags==0 && m->vertex_count==3 && m->textures[0].bytes==16);
    assert(m->vertices[1].position[0]==1 && ((uint16_t *)m->indices)[2]==2);
    assert(!strcmp(m->source_key,"T02") && m->joints[0].inverse_bind[15]==1);
    assert(m->materials[0].texture[1]==UINT32_MAX && m->textures[0].rgba[7]==255);
    assert(!a2_native_model_decode(fixture,sizeof fixture,&m,error,sizeof error));
    assert(m->vertex_count==3);a2_native_model_destroy(m);m=NULL;
    for(size_t n=0;n<sizeof fixture;n++){memcpy(trial,fixture,sizeof trial);rejected(n);}
    const unsigned bad32[][2]={
        {8,2},{12,255},{24,2},{32,1000001},{36,UINT32_MAX},{44,65},{56,3},
        {60,1},{216,1},{552,4},{556,3},{560,1},{616,2},{628,1},{664,1},
        {684,0},{688,2},{692,1},{824,1},{828,2},{832,1},{836,999},
        {864,1},{872,4097},{896,2},{900,1}
    };
    for(size_t i=0;i<sizeof bad32/sizeof *bad32;i++){
        memcpy(trial,fixture,sizeof trial);u32(trial+bad32[i][0],bad32[i][1]);rejected(sizeof trial);
    }
    const unsigned bad64[][2]={{16,919},{64,260},{72,256},{80,551},{112,908},{120,12},{880,4},{888,12}};
    for(size_t i=0;i<sizeof bad64/sizeof *bad64;i++){
        memcpy(trial,fixture,sizeof trial);u64(trial+bad64[i][0],bad64[i][1]);rejected(sizeof trial);
    }
    const unsigned nan_offsets[]={192,256,268,280,296,336,568,584,604,748,840};
    for(size_t i=0;i<sizeof nan_offsets/sizeof *nan_offsets;i++){
        memcpy(trial,fixture,sizeof trial);f32(trial+nan_offsets[i],NAN);rejected(sizeof trial);
    }
    memcpy(trial,fixture,sizeof trial);trial[548]=3;rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);trial[328]=1;rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);f32(trial+336,.9f);rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);f32(trial+276,2);rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);f32(trial+760,2);rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);
    for(unsigned r=0;r<2;r++)for(unsigned c=0;c<2;c++){
        f32(trial+696+4*(4*r+c),1000);
        f32(trial+760+4*(4*r+c),r==c?1000:-1000);
    }
    rejected(sizeof trial); /* Large cancellation is not an inverse. */
    memcpy(trial,fixture,sizeof trial);memset(trial+128,0,32);rejected(sizeof trial);
    memcpy(trial,fixture,sizeof trial);trial[164]='x';rejected(sizeof trial);
    /* A successful decode owns its bytes independently of the input. */
    memcpy(trial,fixture,sizeof trial);
    assert(a2_native_model_decode(trial,sizeof trial,&m,error,sizeof error));
    memset(trial,0,sizeof trial);assert(m->textures[0].rgba[0]==255);a2_native_model_destroy(m);
    if(argc==3 && !strcmp(argv[1],"--write-fixture")){
        FILE *f=fopen(argv[2],"wb");assert(f);assert(fwrite(fixture,1,sizeof fixture,f)==sizeof fixture);assert(!fclose(f));
    } else if((argc==3 && !strcmp(argv[1],"--decode")) || (argc==4 && !strcmp(argv[1],"--readback"))){
        FILE *f=fopen(argv[2],"rb");assert(f);assert(!fseek(f,0,SEEK_END));long size=ftell(f);
        assert(size>0 && size<=A2_MODEL_MAX_BYTES);rewind(f);void *data=malloc((size_t)size);assert(data);
        assert(fread(data,1,(size_t)size,f)==(size_t)size);assert(!fclose(f));m=NULL;
        if(!a2_native_model_decode(data,(size_t)size,&m,error,sizeof error)){fprintf(stderr,"%s\n",error);free(data);return 1;}
        printf("%s: vertices=%u triangles=%u materials=%u joints=%u host_bytes=%zu\n",m->source_key,
               m->vertex_count,m->index_count/3,m->material_count,m->joint_count,m->allocated_bytes);
        if(argc==4){
            /* Canonical little-endian readback from decoded host fields, not input bytes. */
            FILE *out=fopen(argv[3],"wb");assert(out);
            unsigned char record[144];
            u32(record,m->file_flags);u32(record+4,m->vertex_count);u32(record+8,m->joint_count);
            assert(fwrite(record,1,12,out)==12);
            for(uint32_t i=0;i<m->vertex_count;i++){
                const A2ModelVertex *v=&m->vertices[i];
                for(unsigned j=0;j<3;j++){f32(record+4*j,v->position[j]);f32(record+12+4*j,v->normal[j]);}
                for(unsigned k=0;k<2;k++){
                    for(unsigned j=0;j<2;j++)f32(record+24+8*k+4*j,v->uv[k][j]);
                    for(unsigned j=0;j<4;j++)f32(record+40+16*k+4*j,v->color[k][j]);
                }
                for(unsigned j=0;j<4;j++){record[72+2*j]=(unsigned char)v->joints[j];record[73+2*j]=(unsigned char)(v->joints[j]>>8);f32(record+80+4*j,v->weights[j]);}
                assert(fwrite(record,1,96,out)==96);
            }
            for(uint32_t i=0;i<m->joint_count;i++){
                const A2ModelJoint *j=&m->joints[i];u32(record,j->source_id);u32(record+4,j->parent);u32(record+8,j->flags);u32(record+12,0);
                for(unsigned k=0;k<16;k++){f32(record+16+4*k,j->bind[k]);f32(record+80+4*k,j->inverse_bind[k]);}
                assert(fwrite(record,1,144,out)==144);
            }
            assert(!fclose(out));
        }
        a2_native_model_destroy(m);free(data);
    } else if(argc==3 && !strcmp(argv[1],"--archive")){
        A2Resources *r=NULL;assert(a2_resources_open(argv[2],&r,error,sizeof error));
        A2ResourceId id=a2_resource_find(r,0,"MODELS/T02.A2M");assert(id);m=NULL;
        assert(a2_native_model_load(r,id,&m,error,sizeof error));assert(m->vertex_count==3);
        a2_native_model_destroy(m);a2_resources_close(r);
    }
    puts("native model: independent fixture, malformed inputs, ownership passed");return 0;
}
