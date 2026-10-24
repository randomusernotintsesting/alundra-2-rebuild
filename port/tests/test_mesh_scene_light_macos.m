#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include "native_mesh_backend.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
void gte_ctrl_write(int,uint32_t);void gte_data_write(int,uint32_t);
uint32_t gte_ctrl_read(int);uint32_t gte_data_read(int);void gte_cmd(uint32_t);
uint32_t psx_frame_no;
int a2_wide(void){return 0;}
static A2MeshMat4 identity(void){A2MeshMat4 m={0};for(int i=0;i<4;i++)m.m[5*i]=1;return m;}
static float decode(unsigned x){float f=x/255.0f;return f<=.04045f?f/12.92f:powf((f+.055f)/1.055f,2.4f);}
static void matrix(uint32_t c[32],unsigned base,const int16_t v[9]){for(unsigned i=0;i<9;i++)c[base+i/2]|=(uint32_t)(uint16_t)v[i]<<(16*(i%2));}
static uint32_t native_color(uint32_t c[32],unsigned z,const int16_t n[3],uint32_t rgb){
    for(int i=0;i<32;i++){gte_ctrl_write(i,c[i]);gte_data_write(i,0);}
    gte_ctrl_write(0,4096);gte_ctrl_write(2,4096);gte_ctrl_write(4,4096);
    gte_data_write(1,z);gte_cmd(0x4a180001); /* actual RTPS calculates IR0 */
    gte_data_write(0,(uint16_t)n[0]|((uint32_t)(uint16_t)n[1]<<16));gte_data_write(1,(uint16_t)n[2]);gte_data_write(6,0x30000000|rgb);
    gte_cmd(0x4ae80413);return gte_data_read(22)&0xffffff;
}
int main(void){@autoreleasepool{
    if(!MTLCreateSystemDefaultDevice())return 77;char error[256]={0};
    A2MeshBackend *b=a2_mesh_backend_create(32,32,error,sizeof error);if(!b)fprintf(stderr,"%s\n",error);assert(b);
    uint8_t rgba[4096],before[4096];float depths[1024],before_z[1024];uint32_t owners[1024],before_owner[1024];
    const uint16_t indices[]={0,1,2,0,2,3};const float xy[4][2]={{-.9,.9},{.9,.9},{.9,-.9},{-.9,-.9}};
    unsigned cases=0;
    for(unsigned mode=0;mode<6;mode++)for(unsigned zcase=0;zcase<4;zcase++)for(unsigned shader=0;shader<4;shader++){
        unsigned z=(unsigned[]){100,400,800,100}[zcase];uint32_t controls[32]={0};controls[26]=96;
        for(int k=0;k<3;k++)controls[13+k]=4096;
        if(mode==0){controls[13]=2048;controls[15]=1024;}
        if(mode==1){controls[28]=4096*2048;controls[21]=32*16;controls[22]=64*16;controls[23]=96*16;}
        if(mode==2)controls[28]=4096*4096; /* complete native black fade */
        if(mode==3){controls[27]=(uint16_t)-256;controls[28]=4096*4096;controls[21]=16*16;controls[22]=32*16;controls[23]=48*16;}
        if(mode>=4){for(int k=0;k<3;k++)controls[13+k]=0;
            const int16_t light[]={0,0,4096,0,0,2048,0,0,1024},color[]={4096,0,0,0,4096,0,0,0,4096};matrix(controls,8,light);matrix(controls,16,color);}
        int16_t normal[3]={0,0,4096};if(mode==5){normal[0]=4096;normal[2]=0;}
        const uint32_t original_rgb=0x506480;uint32_t expected=native_color(controls,z,normal,original_rgb);
        A2MeshVertex v[4]={0};for(unsigned i=0;i<4;i++){unsigned vertex_z=zcase==3&&(i==1||i==2)?400:z;v[i].position[0]=xy[i][0]*vertex_z;v[i].position[1]=xy[i][1]*vertex_z;v[i].position[2]=vertex_z;v[i].weights[0]=1;
            for(unsigned k=0;k<3;k++){v[i].normal[k]=normal[k]/4096.0f;v[i].color[k]=decode((original_rgb>>(8*k))&255);v[i].color1[k]=.5f;}v[i].color[3]=v[i].color1[3]=1;}
        A2MeshHandle mesh=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);assert(mesh);
        const uint8_t transparent[]={0,0,0,0};A2MeshHandle texture=a2_mesh_texture_create(b,1,1,transparent,4);assert(texture);
        A2MeshFrame frame={0};frame.view_projection=identity();frame.view_projection.m[11]=-1;frame.view_projection.m[14]=1;frame.view_projection.m[15]=0;frame.clear_depth=1;frame.encode_srgb=1;frame.camera_world[2]=-100;
        A2MeshDraw draw={0};draw.mesh=mesh;draw.index_count=6;draw.model=identity();draw.material.shader=(A2MeshShader)shader;draw.material.roughness=.6f;draw.material.specular=.5f;draw.owner_tag=313;draw.depth_test=draw.depth_write=draw.color_write=1;
        for(int k=0;k<4;k++)draw.material.base_color[k]=shader==A2_MESH_LIT_CONSTANT?v[0].color[k]:1;
        if(shader==A2_MESH_LAYERED_ATLAS||shader==A2_MESH_LIT_SHIELD)draw.material.texture=texture;
        assert(a2_mesh_render(b,&frame,&draw,1));assert(a2_mesh_readback(b,before,sizeof before,128,before_z,sizeof before_z,128));assert(a2_mesh_readback_owners(b,before_owner,sizeof before_owner,128));
        assert(a2_native_scene_light_decode(controls,&draw.native_light));assert(a2_mesh_render(b,&frame,&draw,1));
        assert(a2_mesh_readback(b,rgba,sizeof rgba,128,depths,sizeof depths,128));assert(a2_mesh_readback_owners(b,owners,sizeof owners,128));
        assert(!memcmp(depths,before_z,sizeof depths)&&!memcmp(owners,before_owner,sizeof owners));
        /* Independent hardware depth oracle on a tilted surface: z=1/(1-d).
         * An affine or stale camera_z varying would produce a different fog
         * amount. Integer truncation matches source RTPS SZ3 for this sample. */
        if(zcase==3){unsigned actual_z=(unsigned)floor(1.0/(1.0-depths[16*32+16]));expected=native_color(controls,actual_z,normal,original_rgb);}
        for(unsigned k=0;k<3;k++){unsigned actual=rgba[4*(16*32+16)+k],want=(expected>>(8*k))&255;
            if(abs((int)actual-(int)want)>1)fprintf(stderr,"case mode=%u z=%u shader=%u channel=%u expected=%u actual=%u\n",mode,z,shader,k,want,actual);
            assert(abs((int)actual-(int)want)<=1);}
        assert(owners[16*32+16]==313);draw.native_light.known=0;
        assert(a2_mesh_render(b,&frame,&draw,1));assert(a2_mesh_readback(b,rgba,sizeof rgba,128,depths,sizeof depths,128));assert(!memcmp(rgba,before,sizeof rgba));
        draw.native_light.known=2;assert(!a2_mesh_render(b,&frame,&draw,1));
        assert(a2_mesh_destroy(b,mesh)&&a2_mesh_texture_destroy(b,texture));cases++;
    }
    a2_mesh_backend_destroy(b);printf("PASS: %u actual GTE RTPS+NCDS vs Metal scene-light cases, RGB tint, black/colored/depth fade, normal orientation, all material paths, unchanged depth/owner/disabled output\n",cases);return 0;
}}
