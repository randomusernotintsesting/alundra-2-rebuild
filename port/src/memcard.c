/* Memory-card HLE, backed by standard raw PS1 images. All mutations are
 * copy-on-write: fsync a private temporary image, rename, then publish RAM.
 * A separate advisory lock survives replacement and excludes a second game.
 * Reference: psx-spx Kernel (BIOS), Controllers and Memory Cards.
 */
#include "memcard.h"
#include "psx_rt.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include "platform/storage_windows.h"
#else
#include <sys/file.h>
#endif
#include <sys/stat.h>
#include <unistd.h>

#define CARD_SIZE 131072u
#define BLOCK_SIZE 8192u
#define SECTOR_SIZE 128u
#define HW_CARD 0xf0000011u
#define SW_CARD 0xf4000001u
void psx_deliver_event(uint32_t cls, uint32_t spec);
static struct Card {
    uint8_t data[CARD_SIZE];
    char path[4096];
#ifdef _WIN32
    HANDLE lock;
    A2WTarget target;
#else
    int lock;
#endif
    int present, changed, status;
} cards[2];
static struct File {
    int used, slot, first;
    uint32_t pos, mode, error;
} files[16];
static int initialized, started, ignore_change, last_port;
static uint32_t last_error;
static struct { int slot, next; char pattern[21]; } search;

/* PSY-Q's firstfile wrapper inspects the BIOS Device Control Blocks at
 * [150h]/[154h] before issuing B42. Reserve this otherwise unused kernel
 * RAM (below user RAM at 10000h) for ten standard 50h-byte entries.
 * Device function dispatch remains in memcard_bios; guest driver patches
 * may update the callback fields without affecting that HLE boundary. */
static void install_device(void) {
    const uint32_t base=0x8000c000, names=0x8000c320;
    psx_precision_invalidate(base,0x340);
    memset(PSX_RAM+0xc000,0,0x340);
    sw_(0x150,base); sw_(0x154,10*0x50);
    sw_(base,names); sw_(base+4,0x14); sw_(base+8,128);
    sw_(base+12,names+4);
    memcpy(PSX_RAM+0xc320,"bu\0\0MEMORY CARD",16);
}

static uint32_t rd32(const uint8_t *p) {
    return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;
}
static void wr32(uint8_t *p, uint32_t n) {
    for(int i=0;i<4;i++) p[i]=(uint8_t)(n>>(i*8));
}
static void checksum(uint8_t *p) {
    p[127]=0; for(int i=0;i<127;i++) p[127]^=p[i];
}
static int checksum_ok(const uint8_t *p) {
    uint8_t sum=0; for(int i=0;i<128;i++) sum^=p[i]; return sum==0;
}
static void blank(uint8_t *data) {
    memset(data,0,CARD_SIZE); data[0]='M'; data[1]='C'; checksum(data);
    for(int i=1;i<16;i++) {
        uint8_t *d=data+i*128; d[0]=0xa0; d[8]=d[9]=0xff; checksum(d);
    }
    for(int i=16;i<36;i++) {
        uint8_t *d=data+i*128; memset(d,0xff,4); d[8]=d[9]=0xff; checksum(d);
    }
    memset(data+36*128,0xff,27*128);
    memcpy(data+63*128,data,128);
}
static int store(struct Card *c, const uint8_t *data) {
#ifdef _WIN32
    int result=a2w_publish(c->target.dir,c->target.name,data,CARD_SIZE,!c->present);
    if(!result)return 0;
    if(result==2)fprintf(stderr,"memcard: image published, post-publication sync/close failed\n");
    memcpy(c->data,data,CARD_SIZE);return 1;
#else
    char tmp[4160];
    if(snprintf(tmp,sizeof tmp,"%s.tmp.XXXXXX",c->path)>=(int)sizeof tmp) return 0;
    int fd=mkstemp(tmp); if(fd<0) return 0;
    size_t pos=0; int ok=1;
    while(pos<CARD_SIZE) {
        ssize_t n=write(fd,data+pos,CARD_SIZE-pos);
        if(n<0 && errno==EINTR) continue;
        if(n<=0) { ok=0; break; } pos+=(size_t)n;
    }
    if(ok && fsync(fd)!=0) ok=0;
    if(close(fd)!=0) ok=0;
    if(ok && rename(tmp,c->path)!=0) ok=0;
    if(!ok) { unlink(tmp); return 0; }
    memcpy(c->data,data,CARD_SIZE);
    /* Directory sync is best effort: some host filesystems reject it. The
     * rename already committed, so reporting failure here would be misleading. */
    char parent[4096]; strcpy(parent,c->path); char *slash=strrchr(parent,'/');
    if(slash) { *slash=0; fd=open(parent,O_RDONLY); if(fd>=0) { (void)fsync(fd); close(fd); } }
    return 1;
#endif
}
void memcard_shutdown(void) {
#ifdef _WIN32
    if(initialized)for(int i=0;i<2;i++){
        if(cards[i].lock!=INVALID_HANDLE_VALUE)CloseHandle(cards[i].lock);
        a2w_directory_close(cards[i].target.dir);
    }
#else
    if(initialized) for(int i=0;i<2;i++) if(cards[i].lock>=0) close(cards[i].lock);
#endif
    memset(cards,0,sizeof cards); memset(files,0,sizeof files);
    initialized=started=ignore_change=0; search.next=16;
}
static int initialize(const char *directory) {
    memcard_shutdown(); initialized=1;
#ifdef _WIN32
    cards[0].lock=cards[1].lock=INVALID_HANDLE_VALUE;
#else
    cards[0].lock=cards[1].lock=-1;
#endif
#ifndef _WIN32
    if(!directory) directory=getenv("A2_USER_DIR");
#endif
    if(!directory || !*directory) return 0;
    int all=1;
    for(int i=0;i<2;i++) {
        struct Card *c=&cards[i]; c->status=0x11; c->changed=1;
        char lockpath[4096];
        if(snprintf(c->path,sizeof c->path,"%s/memcard%d.mcr",directory,i+1)>=(int)sizeof c->path ||
           snprintf(lockpath,sizeof lockpath,"%s/memcard%d.lock",directory,i+1)>=(int)sizeof lockpath) { all=0; continue; }
#ifdef _WIN32
        if(!a2w_target(c->path,&c->target))goto unavailable;
        char lockname[32];snprintf(lockname,sizeof lockname,"memcard%d.lock",i+1);
        c->lock=a2w_lock(c->target.dir,lockname);
        if(c->lock==INVALID_HANDLE_VALUE)goto unavailable;
        int exists=a2w_exists(c->target.dir,c->target.name);
        if(exists<0)goto unavailable;
        if(!exists){uint8_t data[CARD_SIZE];blank(data);if(!store(c,data))goto unavailable;}
        else if(!a2w_read(c->target.dir,c->target.name,c->data,CARD_SIZE))goto unavailable;
#else
        c->lock=open(lockpath,O_RDWR|O_CREAT|O_NOFOLLOW,0600);
        if(c->lock<0 || flock(c->lock,LOCK_EX|LOCK_NB)!=0) goto unavailable;
        int fd=open(c->path,O_RDONLY|O_NOFOLLOW);
        if(fd<0) {
            if(errno!=ENOENT) goto unavailable;
            uint8_t data[CARD_SIZE]; blank(data);
            if(!store(c,data)) goto unavailable;
        } else {
            struct stat st; int ok=fstat(fd,&st)==0 && S_ISREG(st.st_mode) && st.st_size==CARD_SIZE;
            size_t pos=0;
            while(ok && pos<CARD_SIZE) {
                ssize_t n=read(fd,c->data+pos,CARD_SIZE-pos);
                if(n<0 && errno==EINTR) continue;
                if(n<=0) { ok=0; break; } pos+=(size_t)n;
            }
            close(fd); if(!ok) goto unavailable;
        }
#endif
        c->present=1; c->status=1; continue;
unavailable:
        fprintf(stderr,"memcard: slot %d unavailable: %s (existing image preserved)\n",i+1,c->path);
#ifdef _WIN32
        if(c->lock!=INVALID_HANDLE_VALUE){CloseHandle(c->lock);c->lock=INVALID_HANDLE_VALUE;}
        a2w_directory_close(c->target.dir);c->target.dir=NULL;
#else
        if(c->lock>=0) { close(c->lock); c->lock=-1; }
#endif
        all=0;
    }
    return all;
}
int memcard_init(const char *directory) {
#ifdef _WIN32
    char *env=directory?NULL:a2w_getenv(L"A2_USER_DIR");
    int ok=initialize(directory?directory:env);free(env);return ok;
#else
    return initialize(directory);
#endif
}
static int slot_for(uint32_t port) { return port==0 ? 0 : port==0x10 ? 1 : -1; }
static int ram(uint32_t addr,uint32_t len) {
    uint32_t phys=addr&0x1fffffff;
    return phys<0x800000 && len<=PSX_RAM_SIZE && (phys&0x1fffff)<=PSX_RAM_SIZE-len;
}
static int path(uint32_t addr,int *slot,char name[21]) {
    char buf[26];
    for(unsigned i=0;i<sizeof buf;i++) {
        if(!ram(addr+i,1)) return 0;
        buf[i]=(char)lb_(addr+i);
        if(!buf[i]) {
            if(i<5 || strncmp(buf,"bu",2) || buf[3]!='0' || buf[4]!=':' || (buf[2]!='0' && buf[2]!='1')) return 0;
            *slot=buf[2]-'0'; memcpy(name,buf+5,i-4); return 1;
        }
    }
    return 0;
}
static int formatted(int s) {
    return cards[s].present && cards[s].data[0]=='M' && cards[s].data[1]=='C' && checksum_ok(cards[s].data);
}
static int matches(const char *pattern,const char *name,int star) {
    for(int i=0;i<21;i++) {
        if(star && pattern[i]=='*') return 1;
        if(pattern[i]=='?') { if(!name[i]) return 1; continue; }
        if(pattern[i]!=name[i]) return 0;
        if(!pattern[i]) return 1;
    }
    return 0;
}
static int find(int s,const char *name) {
    for(int b=1;b<=15;b++) {
        uint8_t *d=cards[s].data+b*128;
        if(rd32(d)==0x51 && checksum_ok(d) && memchr(d+10,0,21) && matches(name,(char *)d+10,0)) return b;
    }
    return 0;
}
/* Validate chains before accessing data: imported/corrupt cards must never
 * loop, cross another file's allocation, or read outside the image. */
static int chain(int s,int first,int blocks[15]) {
    int b=first,n=0; unsigned seen=0;
    while(b>=1 && b<=15 && n<15 && !(seen&(1u<<b))) {
        uint8_t *d=cards[s].data+b*128;
        uint32_t state=rd32(d); int next=d[8]|d[9]<<8;
        if(!checksum_ok(d) || state!=(n==0?0x51u:next==0xffff?0x53u:0x52u)) return 0;
        blocks[n++]=b; seen|=1u<<b;
        if(next==0xffff) {
            uint32_t size=rd32(cards[s].data+first*128+4);
            return size>0 && size<=(unsigned)n*BLOCK_SIZE ? n : 0;
        }
        b=next+1;
    }
    return 0;
}
static uint32_t fail(uint32_t err) { last_error=err; return UINT32_MAX; }
static uint32_t file_open(uint32_t addr,uint32_t mode) {
    char name[21]; int s;
    if(!mode || !path(addr,&s,name) || !*name) return fail(0x13);
    if(!formatted(s)) return fail(0x10);
    int fd; for(fd=2;fd<16 && files[fd].used;fd++);
    if(fd==16) return fail(0x18);
    int first=find(s,name),blocks[15];
    if(mode&0x200) {
        if(first) return fail(0x11);
        unsigned want=mode>>16; if(!want || want>15) return fail(0x1c);
        int n=0;
        for(int b=1;b<=15 && n<(int)want;b++) {
            uint8_t *d=cards[s].data+b*128;
            if(checksum_ok(d) && (rd32(d)&0xfffffffcu)==0xa0) blocks[n++]=b;
        }
        if(n!=(int)want) return fail(0x1c);
        uint8_t data[CARD_SIZE]; memcpy(data,cards[s].data,sizeof data);
        for(int j=0;j<n;j++) {
            uint8_t *d=data+blocks[j]*128; memset(d,0,128);
            d[0]=j==0?0x51:j==n-1?0x53:0x52;
            int next=j==n-1?0xffff:blocks[j+1]-1;
            d[8]=(uint8_t)next; d[9]=(uint8_t)(next>>8);
            if(j==0) { wr32(d+4,want*BLOCK_SIZE); strcpy((char *)d+10,name); }
            checksum(d); memset(data+blocks[j]*BLOCK_SIZE,0,BLOCK_SIZE);
        }
        if(!store(&cards[s],data)) return fail(0x10);
        cards[s].changed=0; first=blocks[0];
    } else if(!first) return fail(2);
    if(!chain(s,first,blocks)) return fail(0x10);
    files[fd]=(struct File){1,s,first,0,mode,0}; return (uint32_t)fd;
}
static struct File *getfile(uint32_t fd) { return fd<16 && files[fd].used ? &files[fd] : NULL; }
static uint32_t file_io(uint32_t fd,uint32_t addr,uint32_t length,int writing) {
    struct File *f=getfile(fd); if(!f) return fail(9);
    uint32_t size=rd32(cards[f->slot].data+f->first*128+4);
    uint32_t err=0; int blocks[15];
    if(!formatted(f->slot) || !chain(f->slot,f->first,blocks)) err=0x10;
    else if((f->pos|length)&127 || f->pos>=size || !ram(addr,length)) err=0x16;
    if(err) { f->error=err; return fail(err); }
    if(length>size-f->pos) length=size-f->pos;
    uint8_t data[CARD_SIZE];
    if(writing) memcpy(data,cards[f->slot].data,sizeof data);
    for(uint32_t i=0;i<length;i++) {
        uint32_t p=f->pos+i, off=blocks[p/BLOCK_SIZE]*BLOCK_SIZE+p%BLOCK_SIZE;
        if(writing) data[off]=(uint8_t)lb_(addr+i); else sb_(addr+i,cards[f->slot].data[off]);
    }
    if(writing && !store(&cards[f->slot],data)) {
        f->error=0x10;
        if(f->mode&0x8000) psx_deliver_event(SW_CARD,0x8000);
        return fail(0x10);
    }
    f->pos+=length;
    if(f->mode&0x8000) {
        /* Both classes are observable: PSY-Q's file-read task polls the
         * hardware class at SCPS 8003B264 after submitting async read. */
        psx_deliver_event(HW_CARD,4);
        psx_deliver_event(fd,4); psx_deliver_event(SW_CARD,4); return 0;
    }
    return length;
}
static uint32_t file_seek(uint32_t fd,int32_t offset,uint32_t type) {
    struct File *f=getfile(fd); if(!f) return fail(9);
    if(type>2) return fail(0x16);
    int64_t base=type==0?0:type==1?f->pos:rd32(cards[f->slot].data+f->first*128+4);
    int64_t pos=base+offset; if(pos<0 || pos>INT32_MAX) return fail(0x16);
    return f->pos=(uint32_t)pos;
}
static uint32_t nextfile(uint32_t addr) {
    if(search.next>15 || !ram(addr,40) || !formatted(search.slot)) return 0;
    for(;search.next<=15;) {
        int b=search.next++; uint8_t *d=cards[search.slot].data+b*128; int blocks[15];
        if(rd32(d)!=0x51 || !memchr(d+10,0,21) || !matches(search.pattern,(char *)d+10,1) || !chain(search.slot,b,blocks)) continue;
        for(int i=0;i<40;i++) sb_(addr+i,0);
        for(int i=0;i<20 && d[10+i];i++) sb_(addr+i,d[10+i]);
        sw_(addr+20,0x50); sw_(addr+24,rd32(d+4)); sw_(addr+32,(uint32_t)(b*64)); return addr;
    }
    return 0;
}
static uint32_t erase(uint32_t addr) {
    char name[21]; int s,blocks[15]; if(!path(addr,&s,name) || !formatted(s)) { fail(0x10); return 0; }
    int b=find(s,name); if(!b) { fail(2); return 0; }
    int n=chain(s,b,blocks); if(!n) { fail(0x10); return 0; }
    uint8_t data[CARD_SIZE]; memcpy(data,cards[s].data,sizeof data);
    for(int j=0;j<n;j++) { uint8_t *d=data+blocks[j]*128; d[0]=(d[0]&15)|0xa0; checksum(d); }
    if(!store(&cards[s],data)) { fail(0x10); return 0; }
    for(int fd=2;fd<16;fd++) if(files[fd].used && files[fd].slot==s && files[fd].first==b) files[fd].used=0;
    return 1;
}
static void completion(int s,uint32_t spec,int software) {
    if(getenv("A2_CARDLOG")) {
        extern uint32_t psx_frame_no;
        fprintf(stderr,"card-event: f%u slot=%d spec=%04X software=%d\n",psx_frame_no,s,spec,software);
    }
    if(s>=0) cards[s].status=spec==4?1:spec==0x100?0x11:0x21;
    psx_deliver_event(HW_CARD,spec);
    if(software) psx_deliver_event(SW_CARD,spec);
}
static uint32_t probe(uint32_t port,int load) {
    int s=slot_for(port); last_port=(int)port;
    if(s<0 || !started || !cards[s].present) completion(s,0x100,1);
    else if(load) completion(s,formatted(s)?4:0x2000,1);
    else completion(s,cards[s].changed?0x2000:4,1);
    return 1;
}
static uint32_t sector(uint32_t port,uint32_t sec,uint32_t addr,int writing) {
    int s=slot_for(port); last_port=(int)port;
    if(sec>=1024 || !ram(addr,128)) return 0;
    int allow=ignore_change; ignore_change=0;
    if(s<0 || !started || !cards[s].present) { completion(s,0x100,1); return 1; }
    if(cards[s].changed && !allow) { completion(s,0x2000,1); return 1; }
    if(writing) {
        uint8_t data[CARD_SIZE]; memcpy(data,cards[s].data,sizeof data);
        for(int i=0;i<128;i++) data[sec*128+i]=(uint8_t)lb_(addr+i);
        if(!store(&cards[s],data)) { completion(s,0x8000,1); return 1; }
        cards[s].changed=0;
    } else for(int i=0;i<128;i++) sb_(addr+i,cards[s].data[sec*128+i]);
    /* BIOS bufs callbacks forward raw-sector completion to the software
     * class too; PSY-Q's create-file path waits on that class at 8003D4EC. */
    completion(s,4,1); return 1;
}
int memcard_bios(uint32_t table,uint32_t num) {
    uint32_t a=R[4],b=R[5],c=R[6],result=0;
    if(table==0xa0 && num<=4) { table=0xb0; num+=0x32; }
    if(table==0xa0) {
        if(num!=0x70 && num!=0xab && num!=0xac) return 0;
        if(!initialized) memcard_init(NULL);
        if(num==0xab || num==0xac) result=probe(a,num==0xac);
    } else if(table==0xb0) {
        switch(num) {
        case 0x32: result=file_open(a,b); break;
        case 0x33: result=file_seek(a,(int32_t)b,c); break;
        case 0x34: result=file_io(a,b,c,0); break;
        case 0x35: if(a<2) return 0; result=file_io(a,b,c,1); break;
        case 0x36: if(getfile(a)) { files[a].used=0; result=a; } else result=fail(9); break;
        case 0x42:
            search.next=16;
            if(path(a,&search.slot,search.pattern)) {
                search.next=1;
                result=nextfile(b);
                /* The initial directory access is card I/O even when no
                 * entry matches. PSY-Q waits for its software completion
                 * after firstfile returns NULL (SCPS 8003BA78). */
                completion(search.slot,formatted(search.slot)?4:0x100,1);
            }
            break;
        case 0x43: result=nextfile(a); break;
        case 0x45: result=erase(a); break;
        case 0x4a: if(!initialized) memcard_init(NULL); install_device(); started=0; ignore_change=0; break;
        case 0x4b: started=1; result=1; break;
        case 0x4c: started=0; break;
        case 0x4d: result=probe(a,0); break;
        case 0x4e: result=sector(a,b,c,1); break;
        case 0x4f: result=sector(a,b,c,0); break;
        case 0x50: ignore_change=1; break;
        case 0x54: result=last_error; break;
        case 0x55: result=getfile(a)?files[a].error:UINT32_MAX; break;
        case 0x58: result=(uint32_t)last_port; break;
        case 0x5c: case 0x5d: result=a<2?(uint32_t)cards[a].status:0x11; break;
        default: return 0;
        }
    } else return 0;
    if(getenv("A2_CARDLOG")) {
        extern uint32_t psx_frame_no;
        fprintf(stderr,"card-bios: f%u %02X:%02X(%08X,%08X,%08X)=%08X ra=%08X\n",psx_frame_no,table,num,a,b,c,result,R[31]);
    }
    R[2]=result; return 1;
}
