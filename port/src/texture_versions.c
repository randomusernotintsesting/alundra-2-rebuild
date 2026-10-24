#include "texture_versions.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
enum {TILE_COUNT=2048,MAX_REGION_TILES=272};
struct A2TexVersion {
 struct A2TexCache *owner;
 A2TexRegion region;
 uint16_t *words;
 unsigned refs,tile_count,current;
 uint16_t tile[MAX_REGION_TILES];
 uint64_t stamp[MAX_REGION_TILES];
};
struct A2TexCache {
 uint64_t tiles[TILE_COUNT],epoch,next_id;
 size_t limit;
 unsigned count,cursor;
 struct A2TexVersion *versions;
 A2TexStats stats;
};
A2TexCache *a2_tex_create(size_t bytes,unsigned slots){
 if(!bytes||!slots||slots>4096)return NULL;
 A2TexCache *c=calloc(1,sizeof *c);if(!c)return NULL;
 c->versions=calloc(slots,sizeof *c->versions);if(!c->versions){free(c);return NULL;}
 c->limit=bytes;c->count=slots;c->next_id=1;
 for(unsigned i=0;i<slots;i++)c->versions[i].owner=c;
 return c;
}
void a2_tex_destroy(A2TexCache *c){
 if(!c)return;
 for(unsigned i=0;i<c->count;i++){assert(!c->versions[i].refs);free(c->versions[i].words);}
 free(c->versions);free(c);
}
void a2_tex_reset(A2TexCache *c){
 if(!c)return;
 memset(c->tiles,0,sizeof c->tiles);c->epoch=0;c->stats.epoch_resets++;
 /* Leased old data stays valid, but cannot satisfy a new native lookup. */
 for(unsigned i=0;i<c->count;i++)c->versions[i].current=0;
}
void a2_tex_written(A2TexCache *c,int x,int y,int width,int height){
 if(!c||width<=0||height<=0)return;
 c->stats.write_marks++;
 if(c->epoch==UINT64_MAX)a2_tex_reset(c);
 uint64_t stamp=++c->epoch;
 unsigned left=(unsigned)x&1023,top=(unsigned)y&511;
 unsigned w=width>=1024?1024:(unsigned)width,h=height>=512?512:(unsigned)height;
 unsigned columns=((left&15)+w+15)/16,rows=((top&15)+h+15)/16;
 for(unsigned j=0;j<rows;j++)for(unsigned i=0;i<columns;i++)
  c->tiles[(((top/16+j)&31)*64)+((left/16+i)&63)]=stamp;
}
static A2TexRegion descriptor(uint32_t page,uint32_t clut){
 unsigned mode=(page>>7)&3;if(mode==3)mode=2;
 unsigned width=mode==0?64:mode==1?128:256,palette=mode==0?16:mode==1?256:0;
 return (A2TexRegion){mode,(page&31)|(mode<<7),palette?(clut&32767):0,width,palette,width*256+palette,0};
}
static unsigned region_tiles(A2TexRegion d,uint16_t ids[MAX_REGION_TILES]){
 unsigned page_x=(d.page&15)*4,page_y=((d.page>>4)&1)*16,count=0;
 for(unsigned y=0;y<16;y++)for(unsigned x=0;x<d.width_words/16;x++)
  ids[count++]=(uint16_t)(((page_y+y)&31)*64+((page_x+x)&63));
 if(d.palette_words){
  unsigned palette_x=d.clut&63,palette_y=((d.clut>>6)&511)/16;
  for(unsigned x=0;x<d.palette_words/16;x++)ids[count++]=(uint16_t)(palette_y*64+((palette_x+x)&63));
 }
 assert(count<=MAX_REGION_TILES);return count;
}
static int matches(A2TexCache *c,A2TexVersion *v,A2TexRegion d){
 if(!v->words||!v->current||v->region.page!=d.page||v->region.clut!=d.clut)return 0;
 for(unsigned i=0;i<v->tile_count;i++)if(v->stamp[i]!=c->tiles[v->tile[i]])return 0;
 return 1;
}
static void evict(A2TexCache *c,A2TexVersion *v){
 assert(!v->refs);
 if(v->words){c->stats.live_bytes-=(size_t)v->region.word_count*2;c->stats.evictions++;free(v->words);v->words=NULL;}
 v->current=0;
}
const A2TexVersion *a2_tex_acquire(A2TexCache *c,const uint16_t *native,uint32_t page,uint32_t clut){
 if(!c||!native)return NULL;
 c->stats.requests++;A2TexRegion d=descriptor(page,clut);
 for(unsigned i=0;i<c->count;i++)if(matches(c,&c->versions[i],d)){
  A2TexVersion *v=&c->versions[i];if(v->refs==UINT_MAX)return NULL;v->refs++;c->stats.hits++;return v;
 }
 c->stats.misses++;size_t bytes=(size_t)d.word_count*2;
 if(bytes>c->limit||c->next_id==UINT64_MAX)return NULL;
 A2TexVersion *slot=NULL;size_t releasable=0;
 for(unsigned i=0;i<c->count;i++){
  A2TexVersion *v=&c->versions[(c->cursor+i)%c->count];
  if(!v->refs){if(!slot)slot=v;if(v->words)releasable+=(size_t)v->region.word_count*2;}
 }
 if(!slot||c->stats.live_bytes-releasable>c->limit-bytes)return NULL;
 evict(c,slot);
 for(unsigned i=0;c->stats.live_bytes>c->limit-bytes&&i<c->count;i++){
  A2TexVersion *v=&c->versions[(c->cursor+i)%c->count];if(!v->refs)evict(c,v);
 }
 assert(c->stats.live_bytes<=c->limit-bytes);
 uint16_t *words=malloc(bytes);if(!words)return NULL;
 unsigned px=(d.page&15)*64,py=((d.page>>4)&1)*256;
 for(unsigned y=0;y<256;y++)for(unsigned x=0;x<d.width_words;x++)
  words[y*d.width_words+x]=native[((py+y)&511)*1024+((px+x)&1023)];
 for(unsigned i=0;i<d.palette_words;i++)
  words[d.width_words*256+i]=native[((d.clut>>6)&511)*1024+(((d.clut&63)*16+i)&1023)];
 slot->region=d;slot->region.id=c->next_id++;slot->words=words;slot->refs=1;slot->current=1;
 slot->tile_count=region_tiles(d,slot->tile);
 for(unsigned i=0;i<slot->tile_count;i++)slot->stamp[i]=c->tiles[slot->tile[i]];
 c->cursor=(unsigned)(slot-c->versions+1)%c->count;
 c->stats.copied_bytes+=bytes;c->stats.live_bytes+=bytes;if(c->stats.peak_bytes<c->stats.live_bytes)c->stats.peak_bytes=c->stats.live_bytes;
 return slot;
}
void a2_tex_release(A2TexCache *c,const A2TexVersion *version){
 assert(c&&version&&version->owner==c&&version->refs);
 ((A2TexVersion *)version)->refs--;
}
A2TexRegion a2_tex_region(const A2TexVersion *v){assert(v&&v->refs);return v->region;}
const uint16_t *a2_tex_words(const A2TexVersion *v){assert(v&&v->refs);return v->words;}
A2TexStats a2_tex_stats(const A2TexCache *c){return c?c->stats:(A2TexStats){0};}
uint16_t a2_tex_sample(const A2TexVersion *v,uint32_t window,int u,int row){
 assert(v&&v->refs);const A2TexRegion *d=&v->region;
 unsigned x=(unsigned)u&255,y=(unsigned)row&255;
 unsigned mx=(window&31)*8,my=((window>>5)&31)*8,ox=((window>>10)&31)*8,oy=((window>>15)&31)*8;
 x=(x&~mx)|(ox&mx);y=(y&~my)|(oy&my);
 if(d->mode<2){
  unsigned shift=d->mode?1:2,bits=d->mode?8:4;
  unsigned word=v->words[y*d->width_words+(x>>shift)];
  unsigned index=(word>>((x&((1u<<shift)-1))*bits))&(d->mode?255:15);
  return v->words[d->width_words*256+index];
 }
 return v->words[y*d->width_words+x];
}
#ifdef A2_TEX_TEST
void a2_tex_test_set_epoch(A2TexCache *c,uint64_t epoch){assert(c);c->epoch=epoch;}
#endif
