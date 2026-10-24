#include "native_resources_guest.h"
#include "psx_rt.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Resident resource contracts: scps_004.c 8001B0CC, 8001B30C, 8001B640.
 * The original callbacks expose pending/done/error and buffer progress; they
 * do not invoke application callbacks. Completion is published at the next
 * host vblank boundary for asynchronous requests, never inside a guest call. */
#define SINGLE 0x8005D8C0u
#define QUEUE  0x8005D8D8u
#define QUEUE_MAX 12
typedef struct { uint32_t destination, offset, length; uint8_t *data; } Transfer;
static A2Resources *resources;
static int text_language;
static Transfer single, queued[QUEUE_MAX];
static unsigned queued_count, active_count;
static int single_pending, queue_pending;

static int fail(char *error,size_t size,const char *message) {
    if(error && size)snprintf(error,size,"%s",message);
    return 0;
}
static int ram_range(uint32_t address,size_t bytes) {
    uint32_t physical=address&0x1FFFFFFFu;
    return physical<PSX_RAM_SIZE && bytes<=PSX_RAM_SIZE-physical;
}
static void copy_ram(uint32_t address,const void *data,size_t bytes) {
    psx_precision_invalidate(address&0x1FFFFFu,bytes);
    memcpy(PSX_RAM+(address&0x1FFFFFu),data,bytes);
}
static int resource_name(uint32_t address,char name[64]) {
    char raw[96];size_t i;
    for(i=0;i<sizeof raw;i++) {
        if(address>UINT32_MAX-i || !ram_range(address+(uint32_t)i,1))return 0;
        unsigned c=PSX_RAM[(address+(uint32_t)i)&0x1FFFFFu];
        if(c>127)return 0;
        raw[i]=(char)c;if(!c)break;
    }
    if(i==sizeof raw)return 0;
    /* Normalize only the game's DOS/ISO spelling at this guest boundary. The
     * archive itself exposes canonical relative names, without ISO semantics. */
    size_t start=(raw[0]=='\\'||raw[0]=='/'), n=i-start;
    if(n>=2 && !strcmp(raw+i-2,";1"))n-=2;
    if(!n || n>=64)return 0;
    for(i=0;i<n;i++) {
        unsigned char c=(unsigned char)raw[start+i];
        if(c=='\\')c='/';
        if(c<33 || c==':' || c==';')return 0;
        name[i]=(char)toupper(c);
    }
    name[n]=0;
    for(size_t a=0;a<n;) {
        size_t b=a;while(b<n && name[b]!='/')b++;
        if(b==a || (b-a==1 && name[a]=='.') ||
           (b-a==2 && name[a]=='.' && name[a+1]=='.'))return 0;
        a=b+1;
    }
    return name[n-1]!='/';
}
static void result(uint32_t value) {R[2]=value;psx_next=R[31];}
static void pause_stream(void) {
    uint32_t saved[32],hi=HI,lo=LO,next=psx_next;
    memcpy(saved,R,sizeof saved);psx_call(0x8002FAA4u);
    memcpy(R,saved,sizeof saved);HI=hi;LO=lo;psx_next=next;
}
static void diagnostic(const char *operation,const char *name,const char *error) {
    fprintf(stderr,"native-resource: %s %s: %s\n",operation,name,error);
}
static int stage(A2ResourceId id,Transfer *t,char *error,size_t size) {
    uint64_t length=a2_resource_size(resources,id);
    if(!ram_range(t->destination,t->length))return fail(error,size,"destination exceeds guest RAM");
    if(t->offset>length || t->length>length-t->offset)return fail(error,size,"range exceeds resource");
    t->data=malloc(t->length?t->length:1);
    if(!t->data)return fail(error,size,"cannot allocate transfer buffer");
    if(!a2_resource_pread(resources,id,t->offset,t->data,t->length,error,size)) {
        free(t->data);t->data=NULL;return 0;
    }
    return 1;
}
static void complete_single(void) {
    if(!single_pending)return;
    copy_ram(single.destination,single.data,single.length);
    sw_(SINGLE+4,single.destination+single.length);
    sw_(SINGLE+8,0);sw_(SINGLE+12,0);sh_(SINGLE,1);
    free(single.data);memset(&single,0,sizeof single);single_pending=0;
}
static void complete_queue(void) {
    if(!queue_pending)return;
    for(unsigned i=0;i<active_count;i++) {
        Transfer *t=queued+i;uint32_t record=QUEUE+12+i*16;
        copy_ram(t->destination,t->data,t->length);
        /* Original tail-copy path leaves +4 at its previous position; callers
         * consume status only. Native completion consistently reports end. */
        sw_(record+4,t->destination+t->length);sw_(record+8,0);
        sw_(record+12,0);sh_(record,1);free(t->data);t->data=NULL;
    }
    sh_(QUEUE,0);sh_(QUEUE+2,0);sh_(QUEUE+4,1);
    memset(queued,0,sizeof queued);queued_count=active_count=0;queue_pending=0;
}
void a2_native_resources_tick(void) {
    extern int psx_in_irq,psx_critical;
    if(psx_in_irq || psx_critical)return;
    complete_single();complete_queue();
}
static void lookup_file(void) {
    char name[64];uint8_t record[24]={0};
    if(!ram_range(R[4],sizeof record) || !resource_name(R[5],name)){result(0);return;}
    A2ResourceId id=a2_resource_find(resources,text_language,name);
    uint64_t length=id?a2_resource_size(resources,id):0;
    if(!id || length>UINT32_MAX){result(0);return;}
    /* Position is unused: every consumer of file data resolves the name.
     * Preserve the size/name layout for existing resource parsers. */
    for(unsigned i=0;i<4;i++)record[4+i]=(uint8_t)(length>>(8*i));
    const char *base=strrchr(name,'/');base=base?base+1:name;
    size_t n=strlen(base);if(n>15)n=15;memcpy(record+8,base,n);
    copy_ram(R[4],record,sizeof record);result(R[4]);
}
static void read_file(void) {
    char name[64]="?",error[256];
    if(single_pending || queue_pending) {
        diagnostic("busy",name,"another transfer is pending");result(UINT32_MAX);return;
    }
    A2ResourceId id=resource_name(R[4],name)?a2_resource_find(resources,text_language,name):0;
    uint64_t size=id?a2_resource_size(resources,id):0;
    uint32_t length=R[7]==UINT32_MAX?(uint32_t)size:R[7];
    if(!id || size>UINT32_MAX || !ram_range(R[29],20)) {
        sh_(SINGLE,2);result(UINT32_MAX);return;
    }
    int asynchronous=lw_(R[29]+16)==1;
    single=(Transfer){R[5],R[6],length,NULL};
    if(!stage(id,&single,error,sizeof error)) {
        diagnostic("read",name,error);sh_(SINGLE,2);result(UINT32_MAX);return;
    }
    pause_stream();
    sh_(SINGLE,0);sw_(SINGLE+4,single.destination);
    sw_(SINGLE+8,single.offset&2047);sw_(SINGLE+12,single.length);
    single_pending=1;
    if(!asynchronous)complete_single();
    if(getenv("A2_RESOURCE_LOG"))fprintf(stderr,"native-resource: read %s offset=%u bytes=%u async=%d\n",name,R[6],length,asynchronous);
    result(asynchronous?0:length);
}
static void prepare_file(void) {
    char name[64];A2ResourceId id=resource_name(R[4],name)?a2_resource_find(resources,text_language,name):0;
    if(!id || R[5]>a2_resource_size(resources,id)){result(0);return;}
    pause_stream();result(1);
}
static void enqueue(void) {
    /* The guest resets count directly before assembling a new batch. */
    unsigned count=lh_(QUEUE+2);
    if(queue_pending || count>=QUEUE_MAX || count>queued_count ||
       !ram_range(R[4],R[6])) {
        diagnostic("enqueue","?","invalid or busy resource queue");result(UINT32_MAX);return;
    }
    queued_count=count;
    Transfer *t=queued+queued_count;*t=(Transfer){R[4],R[5],R[6],NULL};
    uint32_t record=QUEUE+12+queued_count*16;
    if(!queued_count)sw_(QUEUE+8,R[5]);
    sh_(record,0);sw_(record+4,R[4]);sw_(record+8,R[5]&2047);sw_(record+12,R[6]);
    queued_count++;sh_(QUEUE+2,queued_count);result(queued_count);
}
static void read_queue(void) {
    char name[64]="?",error[256]="invalid or empty resource queue";
    if(single_pending || queue_pending){result(UINT32_MAX);return;}
    unsigned count=lh_(QUEUE+2);uint32_t mode=R[5];
    A2ResourceId id=resource_name(R[4],name)?a2_resource_find(resources,text_language,name):0;
    if(!id || !count || count!=queued_count)goto failed;
    for(unsigned i=0;i<count;i++)if(!stage(id,queued+i,error,sizeof error))goto failed;
    pause_stream();
    sh_(QUEUE,0);sh_(QUEUE+4,0);sh_(QUEUE+6,mode);
    queue_pending=1;active_count=count;
    if(mode!=1 && mode!=2)complete_queue();
    if(getenv("A2_RESOURCE_LOG"))fprintf(stderr,"native-resource: queue %s ranges=%u mode=%u\n",name,count,mode);
    result(0);return;
failed:
    for(unsigned i=0;i<queued_count;i++){free(queued[i].data);queued[i].data=NULL;}
    diagnostic("queue",name,error);queued_count=0;
    sh_(QUEUE+2,0);sh_(QUEUE+4,2);result(UINT32_MAX);
}
void a2_native_resources_close(void) {
    free(single.data);memset(&single,0,sizeof single);single_pending=0;
    for(unsigned i=0;i<QUEUE_MAX;i++)free(queued[i].data);
    memset(queued,0,sizeof queued);queued_count=active_count=0;queue_pending=0;resources=NULL;
}
int a2_native_resources_install(A2Resources *store,int language,char *error,size_t size) {
    static const struct {uint32_t address,word;void (*fn)(void);} entries[]={
        {0x8001AD68,0x27BDFF58,lookup_file},{0x8001B0CC,0x27BDFFA0,read_file},
        {0x8001B298,0x27BDFFC0,prepare_file},{0x8001B30C,0x00804021,enqueue},
        {0x8001B640,0x27BDFED8,read_queue},{0x80042228,0x27BDFFB0,lookup_file}};
    if(!store || language<0 || language>2 || resources)return fail(error,size,"invalid native resource installation");
    for(unsigned i=0;i<sizeof entries/sizeof entries[0];i++)
        if(lw_(entries[i].address)!=entries[i].word)return fail(error,size,"unsupported game resource routines");
    resources=store;text_language=language;
    void psx_register_hle(uint32_t,void (*)(void));
    for(unsigned i=0;i<sizeof entries/sizeof entries[0];i++)psx_register_hle(entries[i].address,entries[i].fn);
    if(error && size)error[0]=0;return 1;
}
