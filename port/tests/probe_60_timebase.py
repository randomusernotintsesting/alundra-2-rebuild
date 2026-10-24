#!/usr/bin/env python3
"""Execute exact generated timing fragments; never launch the game or edit sources.

This is a bounded diagnostic, not a release 60-FPS implementation or full-game
test. The simulated VBlank increments only at a generated busy-loop boundary.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

PORT = Path(__file__).resolve().parents[1]
FRAGMENTS = {
    "scps_017.c": ["f_80037D98", "f_80037DA8", "f_80037E50", "f_80037E74", "f_80037F10"],
    "game00_006.c": ["g0_8008BEC0"],
    "scps_008.c": ["f_8002508C"],
}


def extract(source, name):
    start = source.index("void " + name + "(void) {")
    end = source.find("\nvoid ", start + 1)
    return source[start:end if end != -1 else len(source)].strip() + "\n"


HARNESS = r'''
#include "psx_rt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
uint8_t PSX_RAM[PSX_RAM_SIZE],PSX_SCRATCH[0x400];
uint32_t R[32],HI,LO,psx_work,psx_next,a2_ramwatch;
int psx_bb_budget=1;
static unsigned simulated_vblanks;
void psx_bb_fire(void) {
    assert(++simulated_vblanks<1000);psx_bb_budget=1;
    sw_(0x8005bce4,lw_(0x8005bce4)+1);
    sw_(0x80001004,lw_(0x80001004)+1);
}
void a2_ramwatch_hit(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;abort();}
uint32_t psx_mmio_read(uint32_t a,int n){(void)a;(void)n;abort();}
void psx_mmio_write(uint32_t a,uint32_t v,int n){(void)a;(void)v;(void)n;abort();}
'''
MAIN = r'''
static void init(void){
    memset(PSX_RAM,0,sizeof PSX_RAM);memset(R,0,sizeof R);
    simulated_vblanks=0;psx_bb_budget=1;R[29]=0x801ff000;R[31]=0xffaa0000;
}
static unsigned vsync(int mode){
    init();sw_(0x8005ab9c,0x80001000);sw_(0x8005aba0,0x80001004);
    sw_(0x8005aba4,100);sw_(0x8005aba8,100);sw_(0x8005bce4,100);
    sw_(0x80001004,100);R[4]=(uint32_t)mode;psx_next=0x80037d98;
    for(unsigned n=0;psx_next!=0xffaa0000;n++){
        assert(n<100);
        switch(psx_next){
        case 0x80037d98:f_80037D98();break;
        case 0x80037da8:f_80037DA8();break;
        case 0x80037e50:f_80037E50();break;
        case 0x80037e74:f_80037E74();break;
        case 0x80037f10:f_80037F10();break;
        default:fprintf(stderr,"Unexpected continuation %08x\n",psx_next);abort();
        }
    }
    assert(R[29]==0x801ff000);
    if(mode<0)assert(R[2]==100);
    return simulated_vblanks;
}
static int movement(unsigned calls){
    init();R[18]=0x80180000;sw_(R[18]+144,7*4096);
    sw_(R[18]+148,(uint32_t)(-3*4096));sw_(R[18]+152,5*4096);
    for(unsigned i=0;i<calls;i++){
        /* Existing A2_60 alters only trigger-call argument registers. These
         * arbitrary values do not scale the real stored motion integrator. */
        R[5]=123;R[6]=456;R[7]=789;g0_8008BEC0();assert(psx_next==0x8008c03c);
    }
    assert((int32_t)lw_(R[18]+28)==-(int)calls*3*4096);
    assert(lw_(R[18]+32)==calls*5*4096);
    assert(lw_(R[18]+472)==calls*7*4096);
    return (int32_t)lw_(R[18]+24)/4096;
}
static unsigned animation(unsigned calls){
    init();const uint32_t obj=0x80180000,base=0x80181000;
    sh_(obj,0xa000);sh_(obj+2,4);sw_(obj+20,base);sw_(obj+24,base);
    sh_(base+2,4);sh_(base+18+2,4);sh_(base+36+2,0);
    for(unsigned i=0;i<calls;i++){R[4]=obj;f_8002508C();assert(psx_next==0xffaa0000);}
    return (lw_(obj+20)-base)/18*4+4-lh_(obj+2);
}
int main(void){
    unsigned m0=vsync(0),m1=vsync(1),m2=vsync(2),m3=vsync(3),mn=vsync(-1);
    assert(m0==1&&m1==0&&m2==2&&m3==3&&mn==0);
    int p30=movement(30),p60=movement(60);assert(p30==210&&p60==420);
    unsigned a3=animation(3),a6=animation(6);assert(a3==3&&a6==6);
    printf("{\"vsync_vblanks\":{\"0\":%u,\"1\":%u,\"2\":%u,\"3\":%u,\"-1\":%u},"
           "\"movement_x_30_calls\":%d,\"movement_x_60_calls\":%d,"
           "\"animation_units_3_calls\":%u,\"animation_units_6_calls\":%u}\n",m0,m1,m2,m3,mn,p30,p60,a3,a6);
}
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    text, provenance = HARNESS, []
    for file, names in FRAGMENTS.items():
        path = PORT / "gen" / file
        source = path.read_text()
        for name in names:
            body = extract(source, name)
            text += "\n" + body
            provenance.append({"path": str(path), "function": name,
                               "fragment_sha256": hashlib.sha256(body.encode()).hexdigest(),
                               "source_sha256": hashlib.sha256(path.read_bytes()).hexdigest()})
    cfile = out / "probe.c"
    cfile.write_text(text + MAIN)
    command = ["cc", "-std=c11", "-O1", "-Wall", "-Wextra", "-Werror",
               "-fsanitize=undefined", "-fno-sanitize-recover=all",
               "-I", str(PORT / "src"), str(cfile), "-o", str(out / "probe")]
    subprocess.run(command, check=True, timeout=30)
    result = subprocess.run([str(out / "probe")], check=True, capture_output=True, text=True, timeout=5)
    report = {"scope": __doc__, "compile": command, "fragments": provenance,
              "result": json.loads(result.stdout), "exit_code": result.returncode}
    (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(result.stdout, end="")


if __name__ == "__main__":
    main()
