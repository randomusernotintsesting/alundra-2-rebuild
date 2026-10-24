#import <Metal/Metal.h>
#include "native_mesh_backend.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t rgba[64*64*4];
static float depth[64*64];
static A2MeshMat4 identity(void) {
    return (A2MeshMat4){{1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1}};
}
static A2MeshMaterial material(float r,float g,float b) {
    return (A2MeshMaterial){{r,g,b,1},1,0,.5f,A2_MESH_OPAQUE,0};
}
static A2MeshDraw draw(A2MeshHandle mesh) {
    A2MeshDraw d={0};d.mesh=mesh;d.index_count=6;d.model=identity();
    d.material=material(1,1,1);d.depth_test=d.depth_write=d.color_write=1;return d;
}
static void read_pixels(A2MeshBackend *b) {
    assert(a2_mesh_readback(b,rgba,sizeof rgba,64*4,depth,sizeof depth,64*sizeof(float)));
}
static void pixel(unsigned x,unsigned y,int r,int g,int b) {
    const uint8_t *p=rgba+4*(y*64+x);
    if(abs((int)p[0]-r)>1||abs((int)p[1]-g)>1||abs((int)p[2]-b)>1)
        fprintf(stderr,"pixel %u,%u actual %u,%u,%u expected %d,%d,%d\n",x,y,p[0],p[1],p[2],r,g,b);
    assert(abs((int)p[0]-r)<=1&&abs((int)p[1]-g)<=1&&abs((int)p[2]-b)<=1);
}
static double srgb_decode(double v){return v<=.04045?v/12.92:pow((v+.055)/1.055,2.4);}
static int output_byte(double v,int srgb){
    v=fmax(0,fmin(1,v));if(srgb)v=v<=.0031308?12.92*v:1.055*pow(v,1/2.4)-.055;
    return (int)lround(255*v);
}
static void owner_pixels(A2MeshBackend *b,A2MeshHandle mesh) {
    uint32_t owners[64*64],retained[64*64],padded[64*67];
    uint8_t color_before[sizeof rgba];float depth_before[64*64];
    A2MeshFrame frame={0};frame.view_projection=identity();frame.clear_depth=1;
    A2MeshDraw batch[2]={draw(mesh),draw(mesh)};
    batch[0].model.m[0]=batch[0].model.m[5]=.4f;batch[0].model.m[11]=-.4f;
    batch[0].material=material(.2f,.7f,.4f);batch[1].material=material(.7f,.3f,.2f);
    for(unsigned encode=0;encode<2;encode++){
        frame.encode_srgb=encode;batch[0].owner_tag=batch[1].owner_tag=0;
        assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);
        memcpy(color_before,rgba,sizeof rgba);memcpy(depth_before,depth,sizeof depth);
        assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
        for(unsigned i=0;i<64*64;i++)assert(!owners[i]);
        /* Values beyond exact float integer precision must survive unchanged. */
        batch[0].owner_tag=UINT32_C(0x80000007);batch[1].owner_tag=UINT32_MAX;
        assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);
        assert(!memcmp(color_before,rgba,sizeof rgba)&&!memcmp(depth_before,depth,sizeof depth));
        assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
        assert(owners[32*64+32]==batch[0].owner_tag&&owners[8*64+8]==UINT32_MAX&&!owners[0]);
        memcpy(retained,owners,sizeof owners);
        A2MeshDraw reverse[]={batch[1],batch[0]};
        assert(a2_mesh_render(b,&frame,reverse,2));read_pixels(b);
        assert(!memcmp(color_before,rgba,sizeof rgba)&&!memcmp(depth_before,depth,sizeof depth));
        assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
        assert(!memcmp(retained,owners,sizeof owners));
    }
    batch[0].index_count=9;assert(!a2_mesh_render(b,&frame,batch,2));batch[0].index_count=6;
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    assert(!memcmp(retained,owners,sizeof owners));
    memset(padded,0x5a,sizeof padded);
    assert(!a2_mesh_readback_owners(b,padded,1,67*sizeof *padded));
    assert(!a2_mesh_readback_owners(b,padded,sizeof padded,63*sizeof *padded));
    assert(!a2_mesh_readback_owners(b,padded,sizeof padded,SIZE_MAX));
    assert(!a2_mesh_readback_owners(b,NULL,sizeof padded,67*sizeof *padded));
    for(unsigned i=0;i<64*67;i++)assert(padded[i]==UINT32_C(0x5a5a5a5a));
    assert(a2_mesh_readback_owners(b,padded,sizeof padded,67*sizeof *padded));
    for(unsigned y=0;y<64;y++){
        assert(!memcmp(padded+y*67,retained+y*64,64*sizeof *padded));
        for(unsigned x=64;x<67;x++)assert(padded[y*67+x]==UINT32_C(0x5a5a5a5a));
    }
    /* An untagged foreground clears prior ownership. Depth-only draws do not
     * own color; discarded cutouts do not own either output. */
    batch[0].owner_tag=0;
    A2MeshDraw reverse[]={batch[1],batch[0]};
    assert(a2_mesh_render(b,&frame,reverse,2));
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    assert(!owners[32*64+32]&&owners[8*64+8]==UINT32_MAX);
    batch[0].owner_tag=17;batch[0].color_write=0;
    assert(a2_mesh_render(b,&frame,batch,2));
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    assert(!owners[32*64+32]&&owners[8*64+8]==UINT32_MAX);
    batch[0].color_write=1;batch[0].material.alpha=A2_MESH_MASK;batch[0].material.base_color[3]=0;
    assert(a2_mesh_render(b,&frame,batch,2));
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    assert(owners[32*64+32]==UINT32_MAX);
    /* Integer ownership does not blend, and follows the color-writing draw. */
    reverse[1]=batch[0];reverse[1].material.alpha=A2_MESH_BLEND;
    reverse[1].material.base_color[3]=.5f;reverse[1].depth_write=0;
    assert(a2_mesh_render(b,&frame,reverse,2));
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    assert(owners[32*64+32]==17);
    assert(a2_mesh_render(b,&frame,NULL,0));
    assert(a2_mesh_readback_owners(b,owners,sizeof owners,64*sizeof *owners));
    for(unsigned i=0;i<64*64;i++)assert(!owners[i]);
}
int main(void) { @autoreleasepool {
    if(!MTLCreateSystemDefaultDevice()){puts("SKIP: no real Metal device");return 77;}
    char error[256]={0};
    assert(!a2_mesh_backend_create(0,64,error,sizeof error));
    assert(!a2_mesh_backend_create(4097,64,error,sizeof error));
    A2MeshBackend *b=a2_mesh_backend_create(64,64,error,sizeof error);
    if(!b)fprintf(stderr,"Metal setup failed: %s\n",error);
    assert(b);assert(a2_mesh_backend_name(b)&&strstr(a2_mesh_backend_name(b),"Metal"));
    uint32_t no_frame[64*64];memset(no_frame,0x3c,sizeof no_frame);
    assert(!a2_mesh_readback_owners(b,no_frame,sizeof no_frame,64*sizeof *no_frame));
    for(unsigned i=0;i<64*64;i++)assert(no_frame[i]==UINT32_C(0x3c3c3c3c));
    A2MeshVertex v[4]={0};
    const float pos[4][3]={{-.9f,.9f,.6f},{.9f,.9f,.6f},{.9f,-.9f,.6f},{-.9f,-.9f,.6f}};
    const float uv[4][2]={{0,0},{1,0},{1,1},{0,1}};
    for(unsigned j=0;j<4;j++){
        memcpy(v[j].position,pos[j],sizeof pos[j]);memcpy(v[j].uv,uv[j],sizeof uv[j]);
        v[j].normal[2]=1;for(unsigned k=0;k<4;k++)v[j].color[k]=1;
        v[j].weights[0]=1;
    }
    uint16_t indices[]={0,1,2,0,2,3};
    A2MeshHandle mesh=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);assert(mesh);
    uint32_t indices32[]={0,1,2,0,2,3};
    A2MeshHandle mesh32=a2_mesh_create(b,v,4,indices32,6,A2_MESH_INDEX_U32);assert(mesh32);
    owner_pixels(b,mesh);
    uint16_t bad_indices[]={0,1,4};assert(!a2_mesh_create(b,v,4,bad_indices,3,A2_MESH_INDEX_U16));
    v[0].weights[0]=NAN;assert(!a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16));v[0].weights[0]=1;
    const uint8_t texels[]={255,0,0,255, 0,255,0,255, 0,0,255,255, 255,255,255,255};
    assert(!a2_mesh_texture_create(b,2,2,texels,7));
    A2MeshHandle texture=a2_mesh_texture_create(b,2,2,texels,8);assert(texture);
    A2MeshFrame frame={0};frame.view_projection=identity();frame.clear_rgba[3]=1;frame.clear_depth=1;
    A2MeshDraw d=draw(mesh);d.material.texture=texture;
    assert(a2_mesh_render(b,&frame,&d,1));read_pixels(b);
    pixel(8,8,255,0,0);pixel(56,8,0,255,0);pixel(8,56,0,0,255);pixel(56,56,255,255,255);
    assert(fabsf(depth[32*64+32]-.6f)<1e-6f);
    /* Actual depth, independent of submission order: foreground first. */
    A2MeshDraw batch[2]={draw(mesh32),d};
    batch[0].model.m[0]=batch[0].model.m[5]=.4f;batch[0].model.m[11]=-.4f;
    batch[0].material=material(0,1,1);
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,0,255,255);
    assert(fabsf(depth[32*64+32]-.2f)<1e-6f);pixel(8,8,255,0,0);
    batch[0].color_write=0;
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,0,0,0);
    assert(fabsf(depth[32*64+32]-.2f)<1e-6f);
    batch[0].color_write=1;batch[0].depth_write=0;
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,255,255,255);
    /* Transparent cutout must not write depth; source-over must respect order. */
    const uint8_t cutout[]={255,0,0,0};
    A2MeshHandle alpha_texture=a2_mesh_texture_create(b,1,1,cutout,4);assert(alpha_texture);
    batch[0].depth_write=1;batch[0].material=material(1,1,1);
    batch[0].material.texture=alpha_texture;batch[0].material.alpha=A2_MESH_MASK;
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,255,255,255);
    assert(fabsf(depth[32*64+32]-.6f)<1e-6f);
    batch[0]=draw(mesh);batch[0].material=material(0,0,1);
    batch[1]=draw(mesh);batch[1].model.m[11]=-.4f;
    batch[1].material=material(1,0,0);batch[1].material.base_color[3]=.5f;
    batch[1].material.alpha=A2_MESH_BLEND;batch[1].depth_write=0;
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,128,0,128);
    assert(fabsf(depth[32*64+32]-.6f)<1e-6f);
    frame.encode_srgb=1;
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(32,32,188,0,188);
    frame.encode_srgb=0;
    assert(a2_mesh_texture_destroy(b,alpha_texture));
    /* Authored atlas alpha mixes two vertex colors; alpha zero is NOT a hole.
     * Independently evaluate scalar sRGB transfer and mix for all endpoints. */
    for(unsigned j=0;j<4;j++)for(unsigned k=0;k<3;k++){
        v[j].color[k]=(float[]){.2f,.3f,.4f}[k];v[j].color1[k]=(float[]){.25f,.5f,.75f}[k];
    }
    A2MeshHandle atlas_mesh=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);assert(atlas_mesh);
    const unsigned alphas[]={0,128,255};
    for(unsigned n=0;n<3;n++){
        uint8_t tex[]={128,64,192,(uint8_t)alphas[n]};
        A2MeshHandle atlas=a2_mesh_texture_create(b,1,1,tex,4);assert(atlas);
        A2MeshDraw authored=draw(atlas_mesh);authored.material.texture=atlas;
        authored.material.shader=A2_MESH_LAYERED_ATLAS;authored.material.texture_srgb=1;
        for(unsigned encode=0;encode<2;encode++){
            frame.encode_srgb=encode;assert(a2_mesh_render(b,&frame,&authored,1));read_pixels(b);
            int expected[3];for(unsigned k=0;k<3;k++){
                double t=alphas[n]/255.0;
                expected[k]=output_byte((1-t)*v[0].color[k]+t*2*v[0].color1[k]*srgb_decode(tex[k]/255.0),encode);
            }
            pixel(32,32,expected[0],expected[1],expected[2]);assert(rgba[4*(32*64+32)+3]==255);
            assert(fabsf(depth[32*64+32]-.6f)<1e-6f);
        }
        authored.material.alpha=A2_MESH_MASK;assert(!a2_mesh_render(b,&frame,&authored,1));
        assert(a2_mesh_texture_destroy(b,atlas));
    }
    assert(a2_mesh_destroy(b,atlas_mesh));frame.encode_srgb=0;
    /* Authored atlas uses UV1; UV0 is deliberately constant and different. */
    for(unsigned j=0;j<4;j++){
        v[j].uv[0]=v[j].uv[1]=0;memcpy(v[j].uv1,uv[j],sizeof uv[j]);
        for(unsigned k=0;k<3;k++)v[j].color1[k]=.5f;
    }
    A2MeshHandle uv_mesh=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);assert(uv_mesh);
    A2MeshDraw uv_draw=draw(uv_mesh);uv_draw.material.texture=texture;
    uv_draw.material.shader=A2_MESH_LAYERED_ATLAS;
    assert(a2_mesh_render(b,&frame,&uv_draw,1));read_pixels(b);
    pixel(8,8,255,0,0);pixel(56,8,0,255,0);pixel(8,56,0,0,255);pixel(56,56,255,255,255);
    assert(a2_mesh_destroy(b,uv_mesh));
    /* Row-major non-symmetric matrix: rigid joint moves a lid in X. */
    A2MeshMat4 joint=identity();joint.m[3]=1;
    d=draw(mesh);d.model.m[0]=d.model.m[5]=.25f;d.material=material(1,0,1);
    d.joints=&joint;d.joint_count=1;
    assert(a2_mesh_render(b,&frame,&d,1));read_pixels(b);pixel(40,32,255,0,255);pixel(32,32,0,0,0);
    /* Camera composes after the model and skin, in the public row-major ABI. */
    frame.view_projection.m[3]=-.5f;
    assert(a2_mesh_render(b,&frame,&d,1));read_pixels(b);pixel(24,32,255,0,255);pixel(40,32,0,0,0);
    frame.view_projection=identity();
    /* Synthetic lid rotates 90 degrees about its left-edge hinge (-.9,0).
     * Colored UV corners distinguish rotation from a translation or transpose. */
    A2MeshMat4 hinge=identity();hinge.m[0]=hinge.m[5]=0;hinge.m[1]=-1;hinge.m[4]=1;
    hinge.m[3]=-.9f;hinge.m[7]=.9f;
    A2MeshDraw lid=draw(mesh);lid.model.m[0]=lid.model.m[5]=.4f;
    lid.material.texture=texture;lid.joints=&hinge;lid.joint_count=1;
    assert(a2_mesh_render(b,&frame,&lid,1));read_pixels(b);
    pixel(16,16,0,255,0);pixel(24,16,255,255,255);
    pixel(16,24,255,0,0);pixel(24,24,0,0,255);pixel(40,40,0,0,0);
    /* Every influence contributes, including the fourth; a too-short palette
     * is rejected before the GPU can access a joint beyond its range. */
    for(unsigned j=0;j<4;j++)for(unsigned k=0;k<4;k++){
        v[j].joints[k]=(uint16_t)k;v[j].weights[k]=.25f;v[j].color[k]=1;
    }
    A2MeshHandle weighted=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);assert(weighted);
    A2MeshMat4 four[4]={identity(),identity(),identity(),identity()};four[3].m[3]=4;
    d.mesh=weighted;d.joints=four;d.joint_count=3;assert(!a2_mesh_render(b,&frame,&d,1));
    d.joint_count=4;assert(a2_mesh_render(b,&frame,&d,1));read_pixels(b);
    pixel(40,32,255,0,255);pixel(32,32,0,0,0);assert(a2_mesh_destroy(b,weighted));
    /* Match A2M2's double-accumulated binary32 weight contract at both
     * neighboring representable values around each tolerance boundary. */
    const float boundary_weights[]={.2501f,nextafterf(.2501f,INFINITY),
                                   nextafterf(.2499f,INFINITY),.2499f};
    for(unsigned c=0;c<4;c++){
        const int valid=c==0||c==2;
        assert((fabs(.75+(double)boundary_weights[c]-1)<=1e-4)==valid);
        for(unsigned j=0;j<4;j++)v[j].weights[3]=boundary_weights[c];
        A2MeshHandle edge=a2_mesh_create(b,v,4,indices,6,A2_MESH_INDEX_U16);
        assert((edge!=0)==valid);if(edge)assert(a2_mesh_destroy(b,edge));
    }
    /* Model transforms are instance-local, even with the same GPU mesh. */
    batch[0]=draw(mesh);batch[1]=draw(mesh);
    for(unsigned j=0;j<2;j++){batch[j].model.m[0]=batch[j].model.m[5]=.2f;batch[j].model.m[3]=j?.5f:-.5f;}
    batch[0].material=material(1,1,0);batch[1].material=material(0,1,1);
    assert(a2_mesh_render(b,&frame,batch,2));read_pixels(b);pixel(16,32,255,255,0);pixel(48,32,0,255,255);pixel(32,32,0,0,0);
    uint8_t retained[sizeof rgba];memcpy(retained,rgba,sizeof rgba);
    batch[1].index_count=9;assert(!a2_mesh_render(b,&frame,batch,2));read_pixels(b);assert(!memcmp(retained,rgba,sizeof rgba));
    batch[1].index_count=6;batch[1].model.m[3]=NAN;assert(!a2_mesh_render(b,&frame,batch,2));
    d=draw(mesh);d.first_index=UINT32_MAX;assert(!a2_mesh_render(b,&frame,&d,1));
    d=draw(mesh);d.joint_count=A2_MESH_MAX_JOINTS+1;d.joints=&joint;assert(!a2_mesh_render(b,&frame,&d,1));
    d=draw(mesh);d.material.texture=mesh;assert(!a2_mesh_render(b,&frame,&d,1));
    A2MeshBackend *other=a2_mesh_backend_create(8,8,error,sizeof error);assert(other);
    d=draw(mesh);assert(!a2_mesh_render(other,&frame,&d,1));assert(!a2_mesh_destroy(other,mesh));
    assert(!a2_mesh_readback(other,rgba,sizeof rgba,256,depth,sizeof depth,256));a2_mesh_backend_destroy(other);
    /* Readback rejects both bad outputs before writing either one. */
    memset(rgba,73,sizeof rgba);assert(!a2_mesh_readback(b,rgba,sizeof rgba,256,depth,1,256));
    for(unsigned j=0;j<sizeof rgba;j++)assert(rgba[j]==73);
    assert(a2_mesh_texture_destroy(b,texture));assert(!a2_mesh_texture_destroy(b,texture));
    d=draw(mesh);d.material.texture=texture;assert(!a2_mesh_render(b,&frame,&d,1));
    assert(a2_mesh_destroy(b,mesh));assert(!a2_mesh_destroy(b,mesh));
    assert(a2_mesh_destroy(b,mesh32));A2MeshStats stats;a2_mesh_backend_stats(b,&stats);
    assert(stats.meshes==0&&stats.textures==0&&stats.submissions>=7);
    assert(a2_mesh_render(b,&frame,NULL,0));read_pixels(b);pixel(32,32,0,0,0);assert(depth[32*64+32]==1);
    a2_mesh_backend_destroy(b);a2_mesh_backend_destroy(NULL);
    puts("PASS: real Metal indexed UV/depth, exact owner MRT, unchanged color/depth, masks/blend, authored atlas+sRGB, rigid joint, two instances, ranges and lifetime");
    return 0;
} }
