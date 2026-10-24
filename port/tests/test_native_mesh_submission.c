#include "native_mesh_submission.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
static uint8_t ram[0x200000];
static A2MeshSubmission s;
static void word(uint32_t a,uint32_t v){memcpy(ram+(a&0x1fffff),&v,4);}
int main(void){
    A2ActorPacket p={0};p.command_address=0x80000104;p.polygon_word_count=4;
    for(unsigned i=0;i<4;i++){p.words[i+2]=0x28000000+i;word(0x104+i*4,p.words[i+2]);}
    word(0x100,0x04000200);word(0x200,0x00ffffff);
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x80000100,0,1);
    assert(s.known&&s.valid&&a2_mesh_submission_contains(&s,&p));
    /* Repeated immutable lists are legitimate submissions, not stale poses. */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x100,0,1);
    assert(a2_mesh_submission_contains(&s,&p));
    word(0x200,0x00000100); /* cycle after an otherwise complete packet */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x100,0,1);
    assert(!s.valid&&!a2_mesh_submission_contains(&s,&p));
    word(0x200,0x00800000); /* non-RAM pointer */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x100,0,1);
    assert(!s.valid&&!a2_mesh_submission_contains(&s,&p));
    word(0x200,0x00000101); /* misaligned pointer */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x100,0,1);
    assert(!s.valid&&!a2_mesh_submission_contains(&s,&p));
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x104,3,0);
    assert(s.valid&&!a2_mesh_submission_contains(&s,&p)); /* truncated polygon */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x104,4,0);
    assert(a2_mesh_submission_contains(&s,&p));
    word(0x108,123);assert(!a2_mesh_submission_contains(&s,&p));
    word(0x108,p.words[3]);
    p.command_address=0x1ffffc;
    for(unsigned i=0;i<4;i++)word(p.command_address+i*4,p.words[i+2]);
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x601ffc,4,0);
    assert(!a2_mesh_submission_contains(&s,&p));
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x7ffffc,4,0);
    assert(a2_mesh_submission_contains(&s,&p)); /* RAM mirror and wrap */
    a2_mesh_submission_begin(&s,ram,sizeof ram,0x100,UINT64_MAX,0);
    assert(a2_mesh_submission_contains(&s,&p)); /* bounded scan, no arithmetic overflow */
    a2_mesh_submission_begin(&s,ram,sizeof ram-4,0,4,0);
    assert(!s.valid&&!a2_mesh_submission_contains(&s,&p));
    a2_mesh_submission_end(&s);assert(!s.known&&a2_mesh_submission_contains(&s,&p));
    puts("PASS: current DMA membership, immutable replay, payload changes, truncation, cycles, invalid pointers, RAM mirrors and wrap");return 0;
}
