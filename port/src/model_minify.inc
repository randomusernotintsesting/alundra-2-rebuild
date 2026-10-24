/* Included after the typed camera/fine/depth helpers. No native VRAM writes. */
#ifndef A2_MODEL_MINIFY_CALLOC
#define A2_MODEL_MINIFY_CALLOC calloc
#endif
static void model_minify_prepare(const A2ActorPacket *packet,const WorldFinePoint *points,int count) {
    if(model_minify_enabled!=1 || !packet || count!=3 || a2_mesh_live_enabled ||
       a2_mesh_live_active || a2_mesh_live_writes_watched || !model_depth_plane_valid || !filter_on())return;
    unsigned command=fifo[0]>>24;
    if(packet->polygon_word_count!=(unsigned)fifo_n || packet->dma_word_count!=(unsigned)fifo_n+1 ||
       packet->command_address!=packet->dma_base+8 ||
       packet->command_address!=(fifo_source[0]&0x1fffffu))return;
    if(command==0x30 && packet->material_layer==0) {
        if(model_minify_key_count!=model_depth_count) {
            uint64_t *keys=A2_MODEL_MINIFY_CALLOC(model_depth_count,sizeof *keys);
            if(!keys)return;
            free(model_minify_keys);model_minify_keys=keys;model_minify_key_count=model_depth_count;
        }
        model_minify_base.word=model_minify_write=model_minify_word;
        model_minify_tracking=1;
        model_minify_base.packet=*packet;
        model_minify_base.camera=model_depth_camera;
        model_minify_base.camera_generation=world_vertices[0].camera_generation;
        model_minify_base.stamp=model_depth_stamp;model_minify_base.scale=IR;
        for(unsigned i=0;i<3;i++) {
            model_minify_base.xy[i][0]=points[i].x;model_minify_base.xy[i][1]=points[i].y;
            model_minify_base.z[i]=world_vertices[i].z;
        }
        return;
    }
    if(command!=0x34 || packet->material_layer!=1 || !model_minify_base.word)return;
    const A2ActorPacket *base=&model_minify_base.packet;
    if(model_minify_word-model_minify_base.word!=packet->dma_word_count ||
       model_minify_prefix_word!=model_minify_base.word+1 ||
       (model_minify_prefix_address&0x1fffffu)!=packet->dma_base+4 ||
       model_minify_prefix_value!=packet->prefix_word ||
       (packet->prefix_word>>24!=0xe1 && packet->prefix_word>>24!=0xe2) ||
       base->previous_head!=packet->dma_base ||
       base->owner_handle!=packet->owner_handle || base->submission_sequence!=packet->submission_sequence ||
       base->entity_generation!=packet->entity_generation ||
       base->source_mesh_index!=packet->source_mesh_index || base->native_face_index!=packet->native_face_index ||
       model_minify_base.stamp!=model_depth_stamp || model_minify_base.scale!=IR ||
       model_minify_base.camera_generation!=world_vertices[0].camera_generation ||
       memcmp(&model_minify_base.camera,&model_depth_camera,sizeof model_depth_camera))return;
    for(unsigned i=0;i<3;i++)if(model_minify_base.xy[i][0]!=points[i].x ||
       model_minify_base.xy[i][1]!=points[i].y || model_minify_base.z[i]!=world_vertices[i].z)return;
    model_minify_pair=model_minify_base.word;
    model_minify_base.word=0; /* A pair is consumed once, even if it covers nothing. */
    model_minify_tracking=1;
}

typedef struct {unsigned count;double u[16],v[16];} ModelMinifyFootprint;
static ModelMinifyFootprint model_minify_footprint(double ux,double uy,double vx,double vy) {
    ModelMinifyFootprint out={0};
    if(!model_minify_pair)return out;
    double dx=hypot(ux,vx),dy=hypot(uy,vy);
    if(!isfinite(dx)||!isfinite(dy))return out;
    unsigned nx=dx<=1?1:dx<=2?2:4,ny=dy<=1?1:dy<=2?2:4;
    if(nx*ny==1)return out;
    for(unsigned y=0;y<ny;y++)for(unsigned x=0;x<nx;x++) {
        double ox=((double)x+.5)/nx-.5,oy=((double)y+.5)/ny-.5;
        out.u[out.count]=(ox*ux+oy*uy)*256;
        out.v[out.count]=(ox*vx+oy*vy)*256;
        out.count++;
    }
    return out;
}
static int model_minify_pixel(uint16_t *pixel,int red,int green,int blue,int u,int v,
                              const ModelMinifyFootprint *footprint) {
    if(!footprint->count || !model_depth_plane_valid || !model_depth_pixels ||
       !model_minify_keys || model_minify_key_count!=model_depth_count)return 0;
    size_t offset=(size_t)(pixel-SHADOW);
    int y=(int)(offset/(unsigned)IR_W),x=(int)(offset%(unsigned)IR_W);
    int page=y>=256*IR?256:0,local_y=y-page*IR;
    if(x>=320*IR || local_y<0 || local_y>=216*IR)return 0;
    size_t index=(size_t)(local_y+(page?216*IR:0))*320*IR+x;
    ModelDepthPixel *prior=&model_depth_pixels[index];
    /* Read before overlay depth can manufacture a same-face certificate. */
    if(prior->stamp!=model_depth_stamp || model_minify_keys[index]!=model_minify_pair ||
       prior->owner!=model_depth_owner || prior->face!=model_depth_face)return 0;
    uint16_t before=*pixel;uint32_t before_rgb=SHADOW_RGB?SHADOW_RGB[offset]:display_from_555(before);
    unsigned sums5[3]={0},sums8[3]={0},writes=0;
    for(unsigned i=0;i<footprint->count;i++) {
        /* Derivatives can be enormous on a near-degenerate triangle. Clamp
         * before conversion; existing polygon UV bounds are inside0..255. */
        double su=(double)u+footprint->u[i],sv=(double)v+footprint->v[i];
        if(su<0)su=0;if(su>65280)su=65280;
        if(sv<0)sv=0;if(sv>65280)sv=65280;
        uint16_t texel=sample_tex_fine((int)floor(su)-128,(int)floor(sv)-128);
        uint16_t value5=before;uint32_t value8=before_rgb;
        if(texel) {
            int r=(((texel&31)<<3)*red)>>7,gc=((((texel>>5)&31)<<3)*green)>>7,
                b=((((texel>>10)&31)<<3)*blue)>>7;
            if(r>255)r=255;if(gc>255)gc=255;if(b>255)b=255;
            value5=(uint16_t)((r>>3)|((gc>>3)<<5)|((b>>3)<<10));
            value8=display_rgb(r,gc,b);writes++;
        }
        for(unsigned channel=0;channel<3;channel++) {
            sums5[channel]+=(value5>>(channel*5))&31;
            sums8[channel]+=(value8>>(channel*8))&255;
        }
    }
    if(writes) {
        uint16_t center=sample_tex_fine(u-128,v-128);
        uint16_t out5=(center?center:before)&0x8000;
        uint32_t out8=0xff000000u;unsigned count=footprint->count;
        for(unsigned channel=0;channel<3;channel++) {
            out5|=((sums5[channel]+count/2)/count)<<(channel*5);
            out8|=((sums8[channel]+count/2)/count)<<(channel*8);
        }
        *pixel=out5;if(SHADOW_RGB)SHADOW_RGB[offset]=out8;
        model_minify_keys[index]=0;
    }
    /* The existing opaque base still owns depth, including transparent taps. */
    return 1;
}
#undef A2_MODEL_MINIFY_CALLOC
