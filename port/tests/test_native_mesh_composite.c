#include "native_mesh_composite.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static const uint16_t original[3]={123,456,789};
static uint16_t background[3]={31,31,31},model[3]={31<<10,31<<10,0};
static float depth[3]={.5f,.5f,NAN};
static uint8_t coverage[3]={1,1,0};
#define IMAGE(a) (A2CompositeImage){(a),sizeof(a),sizeof(a)}
static void begin(A2MeshComposite *c){assert(a2_mesh_composite_begin(c,1,IMAGE(background),IMAGE(model),IMAGE(depth),IMAGE(coverage)));}
static uint16_t at(A2MeshComposite *c,int x){return a2_mesh_composite_row(c,0,original)[x];}
static A2CompositePixel pixel(A2CompositeKind kind,float z,int r,int g,int b){
    return (A2CompositePixel){.kind=kind,.depth=z,.r=r,.g=g,.b=b};
}
static void opaque_model_depth_contract(void){
    A2MeshComposite *c=a2_mesh_composite_create(3,1);assert(c);
    A2CompositePixel near=pixel(A2_COMPOSITE_WORLD,.2f,0,255,0);
    A2CompositePixel far=pixel(A2_COMPOSITE_WORLD,.8f,255,0,0);
    begin(c);a2_mesh_composite_pixel(c,0,0,near);
    a2_mesh_composite_pixel(c,0,0,far);
    assert(a2_mesh_composite_valid(c)&&at(c,0)==(31<<5));
    /* A model-covered pixel has a fixed model depth, not a world Z-buffer:
     * discard far samples, preserve OT order among all accepted samples. */
    for(unsigned reversed=0;reversed<2;reversed++){
        begin(c);near.depth=reversed?.4f:.1f;
        a2_mesh_composite_pixel(c,0,0,near);a2_mesh_composite_pixel(c,0,0,far);
        A2CompositePixel later=pixel(A2_COMPOSITE_WORLD,reversed?.1f:.4f,255,0,0);
        a2_mesh_composite_pixel(c,0,0,later);
        assert(a2_mesh_composite_valid(c)&&at(c,0)==31);
    }
    const uint16_t on_model[]={16<<10,1|(1<<5)|(31<<10),29<<10,31<<10};
    const uint16_t on_near[]={16<<5,1|(31<<5)|(1<<10),29<<5,31<<5};
    for(unsigned mode=0;mode<4;mode++){
        A2CompositePixel semi=pixel(A2_COMPOSITE_WORLD,.4f,15,15,15);
        semi.semi=1;semi.blend_mode=mode;
        begin(c);a2_mesh_composite_pixel(c,0,0,semi);
        assert(at(c,0)==on_model[mode]);
        a2_mesh_composite_pixel(c,0,0,far);
        assert(a2_mesh_composite_valid(c)&&at(c,0)==on_model[mode]);
        /* A far semitransparent sample is equally occluded; it must neither
         * blend nor erase the earlier semitransparent foreground. */
        A2CompositePixel far_semi=far;far_semi.semi=1;far_semi.blend_mode=mode;
        a2_mesh_composite_pixel(c,0,0,far_semi);
        assert(a2_mesh_composite_valid(c)&&at(c,0)==on_model[mode]);
        begin(c);near.depth=.2f;a2_mesh_composite_pixel(c,0,0,near);
        a2_mesh_composite_pixel(c,0,0,far);a2_mesh_composite_pixel(c,0,0,semi);
        assert(a2_mesh_composite_valid(c)&&at(c,0)==on_near[mode]);
    }
    begin(c);a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_HUD,NAN,255,255,255));
    a2_mesh_composite_pixel(c,0,0,far);assert(a2_mesh_composite_valid(c)&&at(c,0)==32767);
    /* HUD bypasses depth, retaining existing stream ordering. */
    a2_mesh_composite_pixel(c,0,0,near);assert(at(c,0)==(31<<5));
    far.semi=1;far.textured=1;far.texel=1;
    a2_mesh_composite_pixel(c,0,0,far);assert(a2_mesh_composite_valid(c)&&at(c,0)==(31<<5));
    far.semi=0;far.textured=0;far.texel=0;
    begin(c);a2_mesh_composite_pixel(c,2,0,near);a2_mesh_composite_pixel(c,2,0,far);
    assert(at(c,2)==31); /* no model coverage: ordinary far opaque still draws */
    a2_mesh_composite_pixel(c,2,0,pixel(A2_COMPOSITE_OWNED,NAN,0,0,255));assert(at(c,2)==31);
    a2_mesh_composite_destroy(c);
}
static void destination_contract(void){
    A2MeshComposite *c=a2_mesh_composite_create(3,1);assert(c);begin(c);
    assert(!a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_OWNED,NAN));
    assert(!a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_WORLD,.8f));
    uint16_t *p=a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_WORLD,.2f);
    assert(p&&*p==(31<<10));*p=(uint16_t)(7|(11<<5)|(17<<10));
    assert(at(c,0)==(7|(11<<5)|(17<<10))&&original[0]==123);
    p=a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_HUD,NAN);assert(p);*p=0x1234;
    assert(at(c,0)==0x1234);
    assert(a2_mesh_composite_destination(c,2,0,A2_COMPOSITE_WORLD,NAN));
    assert(!a2_mesh_composite_destination(c,-1,0,A2_COMPOSITE_UNKNOWN,NAN)&&a2_mesh_composite_valid(c));
    assert(!a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_UNKNOWN,0));
    assert(!a2_mesh_composite_valid(c)&&a2_mesh_composite_failure(c)==3);
    assert(!a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_HUD,0));
    begin(c);assert(!a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_WORLD,NAN));
    assert(a2_mesh_composite_failure(c)==4);
    begin(c);assert(a2_mesh_composite_destination(c,0,0,A2_COMPOSITE_WORLD,.5f));
    a2_mesh_composite_destroy(c);
}
static void native_order_background_contract(void){
    A2MeshComposite *c=a2_mesh_composite_create(3,1);assert(c);begin(c);
    /* A real command with native stream order needs no made-up depth in
     * uncovered background and must not reveal an old model via rollback. */
    a2_mesh_composite_pixel(c,2,0,pixel((A2CompositeKind)4,NAN,0,255,0));
    assert(a2_mesh_composite_valid(c)&&at(c,2)==(31<<5));
    uint32_t tags[3]={1,2,0};
    assert(a2_mesh_composite_owners(c,IMAGE(tags),2));
    A2CompositePixel p=pixel(A2_COMPOSITE_ORDERED,NAN,0,255,0);
    a2_mesh_composite_pixel(c,0,0,p);a2_mesh_composite_pixel(c,1,0,p);
    assert(at(c,0)==(31<<10)&&at(c,1)==(31<<10));
    assert(a2_mesh_composite_anchor(c,1));
    a2_mesh_composite_pixel(c,0,0,p);a2_mesh_composite_pixel(c,1,0,p);
    assert(at(c,0)==(31<<5)&&at(c,1)==(31<<10));
    assert(a2_mesh_composite_anchor(c,2));
    p.semi=1;a2_mesh_composite_pixel(c,1,0,p);
    assert(at(c,1)==((15<<5)|(15<<10)));
    /* Near and far WORLD remain depth-based, independent of source order. */
    a2_mesh_composite_pixel(c,1,0,pixel(A2_COMPOSITE_WORLD,.8f,255,0,0));
    assert(at(c,1)==((15<<5)|(15<<10)));
    a2_mesh_composite_pixel(c,1,0,pixel(A2_COMPOSITE_WORLD,.2f,255,0,0));assert(at(c,1)==31);
    a2_mesh_composite_pixel(c,1,0,pixel(A2_COMPOSITE_OWNED,NAN,0,0,255));assert(at(c,1)==31);
    assert(!a2_mesh_composite_anchor(c,0)&&!a2_mesh_composite_anchor(c,3));
    begin(c);assert(a2_mesh_composite_owners(c,IMAGE(tags),2));
    a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==(31<<10));
    tags[0]=0;assert(!a2_mesh_composite_owners(c,IMAGE(tags),2));
    begin(c);tags[0]=3;assert(!a2_mesh_composite_owners(c,IMAGE(tags),2));
    begin(c);tags[0]=1;A2CompositeImage short_tags=IMAGE(tags);short_tags.size--;
    assert(!a2_mesh_composite_owners(c,short_tags,2));
    a2_mesh_composite_destroy(c);
}
int main(void){
    native_order_background_contract();
    destination_contract();
    opaque_model_depth_contract();
    assert(!a2_mesh_composite_create(0,1));assert(!a2_mesh_composite_create(4096,4096));
    A2MeshComposite *c=a2_mesh_composite_create(3,1);assert(c);
    assert(a2_mesh_composite_row(c,0,original)==original);begin(c);
    assert(at(c,0)==(31<<10)&&at(c,2)==31);
    /* Replacement removes the OLD-only silhouette while preserving original. */
    a2_mesh_composite_pixel(c,2,0,pixel(A2_COMPOSITE_OWNED,NAN,0,255,0));assert(at(c,2)==31);
    assert(original[0]==123&&original[1]==456&&original[2]==789);
    /* A later opaque sample behind the model cannot erase nearer foreground. */
    a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,.2f,0,255,0));assert(at(c,0)==(31<<5));
    a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,.8f,255,0,0));
    assert(a2_mesh_composite_valid(c));assert(at(c,0)==(31<<5));
    begin(c);a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,.8f,255,0,0));assert(at(c,0)==(31<<10));
    a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,.5f,0,255,0));assert(at(c,0)==(31<<5));
    a2_mesh_composite_pixel(c,2,0,pixel(A2_COMPOSITE_WORLD,NAN,0,255,0));assert(at(c,2)==(31<<5));
    /* Mode0 uses (248+15)/2 ->131 ->16, not prequantized source15>>3. */
    begin(c);A2CompositePixel p=pixel(A2_COMPOSITE_WORLD,.4f,15,15,15);p.semi=1;
    a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==(16<<10));
    p.depth=.8f;a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==(16<<10));
    p.semi=0;a2_mesh_composite_pixel(c,0,0,p);assert(a2_mesh_composite_valid(c)&&at(c,0)==(16<<10));p.semi=1;
    /* Literal PSX blend results for clamping, subtraction and quarter source. */
    const uint16_t expected[]={16<<10,1|(1<<5)|(31<<10),29<<10,31<<10};
    for(unsigned mode=0;mode<4;mode++){begin(c);p.depth=.4f;p.blend_mode=mode;
        a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==expected[mode]);}
    /* Texture STP gates semi, texel zero has no coverage; MSB survives write. */
    begin(c);p.textured=1;p.blend_mode=0;p.texel=1;
    a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==(1|(1<<5)|(1<<10)));
    /* STP-clear semi command is effectively opaque, but still occluded. */
    a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,.1f,0,255,0));
    p.depth=.9f;a2_mesh_composite_pixel(c,0,0,p);assert(a2_mesh_composite_valid(c)&&at(c,0)==(31<<5));p.depth=.4f;
    begin(c);p.texel=0x8000;a2_mesh_composite_pixel(c,0,0,p);assert(at(c,0)==((16<<10)|0x8000));
    p.kind=A2_COMPOSITE_UNKNOWN;p.texel=0;a2_mesh_composite_pixel(c,0,0,p);assert(a2_mesh_composite_valid(c));
    p.texel=1;a2_mesh_composite_pixel(c,-1,0,p);assert(a2_mesh_composite_valid(c));
    a2_mesh_composite_pixel(c,1,0,p);assert(!a2_mesh_composite_valid(c));assert(a2_mesh_composite_row(c,0,original)==original);
    /* HUD cannot inherit a world depth test. Unknown coverage anywhere in the
     * union, including old-only silhouette, conservatively rolls back all. */
    begin(c);a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_HUD,NAN,255,255,255));assert(at(c,0)==32767);
    a2_mesh_composite_pixel(c,2,0,pixel(A2_COMPOSITE_UNKNOWN,NAN,1,1,1));assert(!a2_mesh_composite_valid(c));
    begin(c);a2_mesh_composite_pixel(c,0,0,pixel(A2_COMPOSITE_WORLD,NAN,1,1,1));assert(!a2_mesh_composite_valid(c));
    begin(c);a2_mesh_composite_invalidate(c);assert(a2_mesh_composite_row(c,0,original)==original);
    begin(c);assert(!a2_mesh_composite_begin(c,0,IMAGE(background),IMAGE(model),IMAGE(depth),IMAGE(coverage)));assert(!a2_mesh_composite_valid(c));
    begin(c);A2CompositeImage short_image=IMAGE(background);short_image.size--;
    assert(!a2_mesh_composite_begin(c,1,short_image,IMAGE(model),IMAGE(depth),IMAGE(coverage)));assert(!a2_mesh_composite_valid(c));
    depth[0]=NAN;assert(!a2_mesh_composite_begin(c,1,IMAGE(background),IMAGE(model),IMAGE(depth),IMAGE(coverage)));depth[0]=.5f;
    coverage[0]=2;assert(!a2_mesh_composite_begin(c,1,IMAGE(background),IMAGE(model),IMAGE(depth),IMAGE(coverage)));coverage[0]=1;
    begin(c);model[0]=0;background[2]=0;coverage[0]=0;depth[0]=0;
    assert(at(c,0)==(31<<10)&&at(c,2)==31); /* owned copies, no borrowed lifetime */
    assert(a2_mesh_composite_row(c,1,original)==original);
    a2_mesh_composite_destroy(c);a2_mesh_composite_destroy(NULL);
    /* Padded, byte-aligned 2D inputs: row1 must not alias row0/padding.
     * Huge strides cannot wrap size checks into acceptance. */
    c=a2_mesh_composite_create(1,2);assert(c);
    uint8_t colors[9]={0},zs[13]={0},masks[5]={0,1,0,0,1};
    uint16_t red=31,green=31<<5;float near=.25f,far=.75f;
    memcpy(colors+1,&red,2);memcpy(colors+6,&green,2);
    memcpy(zs+1,&near,4);memcpy(zs+8,&far,4);
    A2CompositeImage ci={colors+1,8,5},zi={zs+1,12,7},mi={masks+1,4,3};
    assert(a2_mesh_composite_begin(c,1,ci,ci,zi,mi));
    assert(a2_mesh_composite_row(c,0,original)[0]==red&&a2_mesh_composite_row(c,1,original)[0]==green);
    a2_mesh_composite_pixel(c,0,1,pixel(A2_COMPOSITE_WORLD,.5f,0,0,255));
    assert(a2_mesh_composite_row(c,0,original)[0]==red&&a2_mesh_composite_row(c,1,original)[0]==(31<<10));
    ci.stride=SIZE_MAX;assert(!a2_mesh_composite_begin(c,1,ci,ci,zi,mi));assert(!a2_mesh_composite_valid(c));
    ci.stride=5;ci.size=6;assert(!a2_mesh_composite_begin(c,1,ci,ci,zi,mi));
    ci.size=8;assert(a2_mesh_composite_begin(c,1,ci,ci,zi,mi));
    p=pixel(A2_COMPOSITE_WORLD,.2f,1,1,1);p.blend_mode=4;
    a2_mesh_composite_pixel(c,0,0,p);assert(!a2_mesh_composite_valid(c));
    a2_mesh_composite_destroy(c);
    puts("PASS: opaque replacement, ordered world, PSX blends, ROI rollback and ownership");
}
