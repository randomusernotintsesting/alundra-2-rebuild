/* Immutable named byte resources. No disc/sector transport is represented. */
#include "a2_resources.h"
#include "platform_file.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define MAX_INDEX (64u * 1024u * 1024u)
#define MAX_CHUNK 65536u
#define CACHE_COUNT 4u

typedef struct {
    char name[64];
    uint32_t language, first, count, id;
    uint64_t size;
} ResourceFile;
typedef struct { uint64_t offset; uint32_t chunk, start, length; } ResourceSpan;
typedef struct { uint64_t offset; uint32_t stored, raw, crc, codec; } ResourceChunk;
typedef struct { uint32_t id; int valid; uint64_t age; uint8_t data[MAX_CHUNK]; } Cache;
struct A2Resources {
    A2File *file;
    unsigned profiles;
    uint32_t file_count, span_count, chunk_count;
    ResourceFile *files, *lookup;
    ResourceSpan *spans;
    ResourceChunk *chunks;
    Cache cache[CACHE_COUNT];
    /* All reads belong to the emulation thread. Reuse scratch and decoder
     * state across cache misses without reserving 64 KiB on its stack. */
    uint8_t *compressed;
    z_stream decoder;
    int decoder_ready;
    uint64_t clock;
    int name_voice; /* zero: original lookup, one: JP names, two: US names */
};
static uint32_t u32(const uint8_t *p) {
    return (uint32_t)p[0] | (uint32_t)p[1]<<8 | (uint32_t)p[2]<<16 | (uint32_t)p[3]<<24;
}
static uint64_t u64(const uint8_t *p) { return u32(p) | (uint64_t)u32(p+4)<<32; }
static int failure(char *error,size_t size,const char *message) {
    if(error && size)snprintf(error,size,"%s",message);
    return 0;
}
static int name_valid(const char *name) {
    if(!name || !*name)return 0;
    size_t component=0;
    for(size_t i=0;i<64;i++) {
        unsigned char c=(unsigned char)name[i];
        if(!c || c=='/') {
            if(!component || (component==1 && name[i-1]=='.') ||
               (component==2 && name[i-1]=='.' && name[i-2]=='.'))return 0;
            if(!c)return 1;
            component=0;
        } else {
            if(c<32 || c>126 || c=='\\' || c==':')return 0;
            component++;
        }
    }
    return 0;
}
static int file_compare(const void *left,const void *right) {
    const ResourceFile *a=left,*b=right;
    int cmp=strcmp(a->name,b->name);
    if(cmp)return cmp;
    return (a->language>b->language)-(a->language<b->language);
}
void a2_resources_close(A2Resources *s) {
    if(!s)return;
    a2_file_close(s->file);
    if(s->decoder_ready)inflateEnd(&s->decoder);
    free(s->compressed);
    free(s->files);free(s->lookup);free(s->spans);free(s->chunks);free(s);
}
int a2_resources_open(const char *path,A2Resources **out,char *error,size_t size) {
    if(error && size)*error=0;
    if(!out)return failure(error,size,"Missing resource-store output");
    *out=NULL;
    if(!path || !*path)return failure(error,size,"Missing resource archive path");
    A2File *file=NULL;
    if(!a2_file_open_read(path,&file,NULL,0))return failure(error,size,"Cannot open resource archive");
    uint64_t file_size;uint8_t header[64];
    if(!a2_file_size(file,&file_size,NULL,0) || file_size<64 ||
       !a2_file_read_at(file,0,header,sizeof header,NULL,0)) {
        a2_file_close(file);return failure(error,size,"Truncated resource archive header");
    }
    uint32_t nf=u32(header+16),ns=u32(header+20),nc=u32(header+24);
    uint64_t fo=u64(header+32),so=u64(header+40),co=u64(header+48),data=u64(header+56);
    uint64_t expected_so=64+(uint64_t)nf*96,expected_co=expected_so+(uint64_t)ns*24;
    uint64_t expected_data=expected_co+(uint64_t)nc*24;
    if(memcmp(header,"A2RES001",8) || u32(header+8)!=1 ||
       !u32(header+12) || (u32(header+12)&~7u) || fo!=64 ||
       so!=expected_so || co!=expected_co || data!=expected_data ||
       expected_data-64>MAX_INDEX || data>file_size) {
        a2_file_close(file);return failure(error,size,"Invalid resource archive header or table bounds");
    }
    size_t index_size=(size_t)(data-64);
    uint8_t *index=malloc(index_size?index_size:1);
    if(!index) { a2_file_close(file);return failure(error,size,"Cannot allocate resource index"); }
    if(!a2_file_read_at(file,64,index,index_size,NULL,0) ||
       crc32(0,index,(uInt)index_size)!=u32(header+28)) {
        free(index);a2_file_close(file);return failure(error,size,"Resource index CRC or read failed");
    }
    A2Resources *s=calloc(1,sizeof *s);
    if(!s) { free(index);a2_file_close(file);return failure(error,size,"Cannot allocate resource store"); }
    s->file=file;s->profiles=u32(header+12);s->file_count=nf;s->span_count=ns;s->chunk_count=nc;
    s->files=calloc(nf?nf:1,sizeof *s->files);s->lookup=calloc(nf?nf:1,sizeof *s->lookup);
    s->spans=calloc(ns?ns:1,sizeof *s->spans);s->chunks=calloc(nc?nc:1,sizeof *s->chunks);
    const char *problem="Cannot allocate resource tables";
    if(!s->files || !s->lookup || !s->spans || !s->chunks)goto bad;
    problem="Invalid resource chunk bounds or codec";
    uint64_t payload=data;
    for(uint32_t i=0;i<nc;i++) {
        const uint8_t *p=index+(size_t)(co-64)+(size_t)i*24;
        ResourceChunk *c=s->chunks+i;
        c->offset=u64(p);c->stored=u32(p+8);c->raw=u32(p+12);c->crc=u32(p+16);c->codec=u32(p+20);
        if(c->offset!=payload || !c->stored || !c->raw || c->raw>MAX_CHUNK ||
           c->stored>c->raw || c->codec>1 || (!c->codec && c->stored!=c->raw) ||
           c->stored>file_size-payload)goto bad;
        payload+=c->stored;
    }
    if(payload!=file_size)goto bad;
    problem="Invalid resource span reference";
    for(uint32_t i=0;i<ns;i++) {
        const uint8_t *p=index+(size_t)(so-64)+(size_t)i*24;
        ResourceSpan *span=s->spans+i;
        span->offset=u64(p);span->chunk=u32(p+8);span->start=u32(p+12);span->length=u32(p+16);
        if(u32(p+20) || span->chunk>=nc || !span->length ||
           span->start>s->chunks[span->chunk].raw ||
           span->length>s->chunks[span->chunk].raw-span->start)goto bad;
    }
    problem="Invalid resource file name, language or span coverage";
    for(uint32_t i=0;i<nf;i++) {
        const uint8_t *p=index+(size_t)i*96;
        ResourceFile *f=s->files+i;
        memcpy(f->name,p,64);f->language=u32(p+64);f->size=u64(p+72);
        f->first=u32(p+80);f->count=u32(p+84);f->id=i+1;
        if(!memchr(f->name,0,64) || !name_valid(f->name) || f->language>3 ||
           (f->language<3 && !(s->profiles&(1u<<f->language))) || u32(p+68) || u64(p+88) ||
           f->first>ns || f->count>ns-f->first)goto bad;
        uint64_t pos=0;
        for(uint32_t j=0;j<f->count;j++) {
            const ResourceSpan *span=s->spans+f->first+j;
            if(span->offset!=pos || pos>f->size || span->length>f->size-pos)goto bad;
            pos+=span->length;
        }
        if(pos!=f->size)goto bad;
        s->lookup[i]=*f;
    }
    qsort(s->lookup,nf,sizeof *s->lookup,file_compare);
    for(uint32_t i=1;i<nf;i++)if(!file_compare(s->lookup+i-1,s->lookup+i)) {
        problem="Duplicate resource language/name";goto bad;
    }
    free(index);*out=s;return 1;
bad:
    free(index);a2_resources_close(s);return failure(error,size,problem);
}
unsigned a2_resources_profiles(const A2Resources *s) { return s?s->profiles:0; }
static A2ResourceId find_original(const A2Resources *s,int language,const char *name) {
    if(!s || language<0 || language>3 || !name_valid(name))return 0;
    ResourceFile key={0};memcpy(key.name,name,strlen(name)+1);key.language=(uint32_t)language;
    const ResourceFile *f=bsearch(&key,s->lookup,s->file_count,sizeof *s->lookup,file_compare);
    if(!f && language!=3) { key.language=3;f=bsearch(&key,s->lookup,s->file_count,sizeof *s->lookup,file_compare); }
    return f?f->id:0;
}
static const char *const name_files[]={"DATA/GRP.GP","DATA/PACK0.PAK","DATA/PAKVCAST.PAK"};
int a2_resources_set_name_voice(A2Resources *s,int voice) {
    if(!s || voice<0 || voice>1)return 0;
    unsigned found=0;
    for(int language=0;language<=2;language+=2)for(int v=0;v<2;v++)
        for(unsigned i=0;i<sizeof name_files/sizeof name_files[0];i++) {
            char name[64];snprintf(name,sizeof name,"NAMES/%s/%s",v?"EN":"JA",name_files[i]);
            found+=find_original(s,language,name)!=0;
        }
    if(found && found!=12)return 0;
    s->name_voice=found?voice+1:0;return 1;
}
A2ResourceId a2_resource_find(const A2Resources *s,int language,const char *name) {
    if(!s || language<0 || language>3 || !name_valid(name))return 0;
    if(s->name_voice && (language==0 || language==2))
        for(unsigned i=0;i<sizeof name_files/sizeof name_files[0];i++)
            if(!strcmp(name,name_files[i])) {
                char variant[64];snprintf(variant,sizeof variant,"NAMES/%s/%s",s->name_voice==1?"JA":"EN",name);
                return find_original(s,language,variant);
            }
    return find_original(s,language,name);
}
uint64_t a2_resource_size(const A2Resources *s,A2ResourceId id) {
    return s && id && id<=s->file_count?s->files[id-1].size:0;
}
static const uint8_t *decode(A2Resources *s,uint32_t id,char *error,size_t size) {
    Cache *entry=s->cache;
    for(unsigned i=0;i<CACHE_COUNT;i++) {
        Cache *c=s->cache+i;
        if(c->valid && c->id==id) { c->age=++s->clock;return c->data; }
        if(!c->valid || (entry->valid && c->age<entry->age))entry=c;
    }
    entry->valid=0;
    const ResourceChunk *chunk=s->chunks+id;
    if(chunk->codec && !s->compressed) {
        s->compressed=malloc(MAX_CHUNK);
        if(!s->compressed) { failure(error,size,"Cannot allocate resource decoder scratch");return NULL; }
    }
    uint8_t *target=chunk->codec?s->compressed:entry->data;
    if(!a2_file_read_at(s->file,chunk->offset,target,chunk->stored,NULL,0)) {
        failure(error,size,"Cannot read resource chunk");return NULL;
    }
    if(chunk->codec) {
        z_stream *stream=&s->decoder;
        if(!s->decoder_ready) {
            if(inflateInit(stream)!=Z_OK) { failure(error,size,"Cannot initialize resource decoder");return NULL; }
            s->decoder_ready=1;
        } else if(inflateReset(stream)!=Z_OK) {
            failure(error,size,"Cannot reset resource decoder");return NULL;
        }
        stream->next_in=s->compressed;stream->avail_in=chunk->stored;
        stream->next_out=entry->data;stream->avail_out=chunk->raw;
        int result=inflate(stream,Z_FINISH);
        int valid=result==Z_STREAM_END && stream->total_out==chunk->raw && stream->total_in==chunk->stored;
        if(!valid) { failure(error,size,"Invalid compressed resource chunk");return NULL; }
    }
    if(crc32(0,entry->data,chunk->raw)!=chunk->crc) {
        failure(error,size,"Resource chunk CRC mismatch");return NULL;
    }
    entry->id=id;entry->valid=1;entry->age=++s->clock;return entry->data;
}
int a2_resource_pread(A2Resources *s,A2ResourceId id,uint64_t offset,void *destination,
                      size_t length,char *error,size_t size) {
    if(error && size)*error=0;
    if(!s || !id || id>s->file_count || (!destination && length))
        return failure(error,size,"Invalid resource read arguments");
    const ResourceFile *f=s->files+id-1;
    if(offset>f->size || (uint64_t)length>f->size-offset)
        return failure(error,size,"Resource read exceeds logical file");
    if(!length)return 1;
    uint32_t lo=0,hi=f->count;
    while(lo<hi) {
        uint32_t middle=lo+(hi-lo)/2;
        if(s->spans[f->first+middle].offset<=offset)lo=middle+1;else hi=middle;
    }
    uint32_t position=lo-1;uint8_t *out=destination;
    while(length) {
        const ResourceSpan *span=s->spans+f->first+position++;
        size_t within=(size_t)(offset-span->offset),amount=span->length-within;
        if(amount>length)amount=length;
        const uint8_t *bytes=decode(s,span->chunk,error,size);
        if(!bytes)return 0;
        memcpy(out,bytes+span->start+within,amount);
        offset+=amount;out+=amount;length-=amount;
    }
    return 1;
}
