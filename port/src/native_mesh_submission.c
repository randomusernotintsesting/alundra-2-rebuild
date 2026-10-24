#include "native_mesh_submission.h"
#include <string.h>
#define RAM_BYTES 0x200000u
static int address(uint32_t in,uint32_t *out){
    in&=0x1fffffffu;if(in>=0x800000u||(in&3))return 0;*out=in&(RAM_BYTES-1);return 1;
}
static void mark(uint8_t *bits,uint32_t a){bits[a>>5]|=(uint8_t)(1u<<((a>>2)&7));}
static int marked(const uint8_t *bits,uint32_t a){return !!(bits[a>>5]&(1u<<((a>>2)&7)));}
void a2_mesh_submission_end(A2MeshSubmission *s){s->known=s->valid=0;s->ram=NULL;}
void a2_mesh_submission_begin(A2MeshSubmission *s,const uint8_t *ram,size_t bytes,
                              uint32_t start,uint64_t count,int linked){
    s->known=1;s->valid=0;s->ram=ram;
    memset(s->words,0,sizeof s->words);memset(s->visited,0,sizeof s->visited);
    uint32_t at;if(!ram||bytes!=RAM_BYTES||!address(start,&at))return;
    if(!linked){
        if(count>=RAM_BYTES/4)memset(s->words,255,sizeof s->words);
        else for(uint64_t i=0;i<count;i++)mark(s->words,(at+(uint32_t)i*4)&(RAM_BYTES-1));
        s->valid=1;return;
    }
    for(unsigned nodes=0;nodes<RAM_BYTES/4;nodes++){
        if(marked(s->visited,at))return;mark(s->visited,at);
        uint32_t header;memcpy(&header,ram+at,4);unsigned n=header>>24;
        for(unsigned i=1;i<=n;i++)mark(s->words,(at+4*i)&(RAM_BYTES-1));
        uint32_t next=header&0xffffffu;
        if(!next||next==0xffffffu){s->valid=1;return;}
        if(!address(next,&at))return;
    }
}
int a2_mesh_submission_contains(const A2MeshSubmission *s,const A2ActorPacket *p){
    if(!s->known)return 1; /* Direct GP0 fixtures/paths have no DMA scope. */
    if(!s->valid||!p||!p->polygon_word_count||p->polygon_word_count>12)return 0;
    uint32_t a;if(!address(p->command_address,&a))return 0;
    for(unsigned i=0;i<p->polygon_word_count;i++){
        uint32_t at=(a+4*i)&(RAM_BYTES-1),word;
        if(!marked(s->words,at))return 0;memcpy(&word,s->ram+at,4);
        if(word!=p->words[i+2])return 0;
    }
    return 1;
}
