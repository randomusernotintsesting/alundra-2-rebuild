/* Frozen pre-optimization raster; independent full-surface comparison oracle.
 * gpu.c SHA256 7854af0e0e3eec4fbeff020c563fd081a0f92ff0f6fbef5c79bed4cda2ef226d. */
static int reference_world_attribute(int64_t wa,int64_t wb,int64_t wc,
                           int a,int b,int c,int64_t area,int shift) {
    __int128 sum=(__int128)wa*a+(__int128)wb*b+(__int128)wc*c;
    return (int)((sum*((__int128)1<<shift))/area);
}
static void reference_world_fine(Vtx a,Vtx b,Vtx c,WorldFineTriangle triangle,
                                  int gouraud,int tex,int semi,int scale,
                                  const double *inverse_depth) {
    /* Source coordinates lie in [-1024,1024), offsets in [-1024,1024),
     * and scale<=4. Every difference is <2^30 Q16 units, so two products
     * and their subtraction fit int64. Attribute products require128 bits. */
    if(scale<2 || scale>4) return;
    for(int i=0;i<3;i++) {triangle.p[i].x*=scale;triangle.p[i].y*=scale;}
    WorldFinePoint p=triangle.p[0],q=triangle.p[1],r=triangle.p[2];
    double za=0,zb=0,zc=0;
    if(inverse_depth) {
        za=inverse_depth[0];zb=inverse_depth[1];zc=inverse_depth[2];
        if(za==zb&&zb==zc)inverse_depth=NULL;
    }
    int64_t area=world_edge(p,q,r);
    if(area<0) {
        WorldFinePoint point=q;q=r;r=point;Vtx v=b;b=c;c=v;area=-area;
        double z=zb;zb=zc;zc=z;
    }
    if(!area) return;
    int64_t minx=p.x,maxx=p.x,miny=p.y,maxy=p.y;
    const WorldFinePoint others[2]={q,r};
    for(int i=0;i<2;i++) {
        if(others[i].x<minx)minx=others[i].x;if(others[i].x>maxx)maxx=others[i].x;
        if(others[i].y<miny)miny=others[i].y;if(others[i].y>maxy)maxy=others[i].y;
    }
    int x0=world_floor_q16(minx),x1=world_floor_q16(maxx);
    int y0=world_floor_q16(miny),y1=world_floor_q16(maxy);
    if(x0<g.dax1*scale)x0=g.dax1*scale;
    if(x1>=(g.dax2+1)*scale)x1=(g.dax2+1)*scale-1;
    if(y0<g.day1*scale)y0=g.day1*scale;
    if(y1>=(g.day2+1)*scale)y1=(g.day2+1)*scale-1;
    int own0=world_top_left(p,q),own1=world_top_left(q,r),own2=world_top_left(r,p);
    for(int y=y0;y<=y1;y++)for(int x=x0;x<=x1;x++) {
        WorldFinePoint sample={(int64_t)x*65536,(int64_t)y*65536};
        int64_t w0=world_edge(p,q,sample),w1=world_edge(q,r,sample),w2=world_edge(r,p,sample);
        if(w0<0 || (!w0&&!own0) || w1<0 || (!w1&&!own1) || w2<0 || (!w2&&!own2))continue;
        int red=a.r,green=a.gr,blue=a.b;
        if(gouraud) {
            red=reference_world_attribute(w1,w2,w0,a.r,b.r,c.r,area,0);
            green=reference_world_attribute(w1,w2,w0,a.gr,b.gr,c.gr,area,0);
            blue=reference_world_attribute(w1,w2,w0,a.b,b.b,c.b,area,0);
        }
        uint16_t texel=0;
        if(tex) {
            if(inverse_depth) {
                /* Positive owned-edge weights make D strictly positive.
                 * The primitive-wide GTE depth bounds keep all products
                 * finite. One reciprocal serves both UV attributes. */
                double wa=(double)w1*za,wb=(double)w2*zb,wc=(double)w0*zc;
                double reciprocal=1.0/(wa+wb+wc);
                /* A constant attribute is exact; a reciprocal roundoff just
                 * below its integer value must not select a different texel. */
                double u=(a.u==b.u&&b.u==c.u)?a.u:(wa*a.u+wb*b.u+wc*c.u)*reciprocal;
                double v=(a.v==b.v&&b.v==c.v)?a.v:(wa*a.v+wb*b.v+wc*c.v)*reciprocal;
                if(filter_on())texel=sample_tex_fine((int)(u*256.0)-128,(int)(v*256.0)-128);
                else texel=sample_tex((int)u,(int)v);
            } else {
#ifdef A2_HD_FONTS
            if(hd_matches_active()) {
                int u=reference_world_attribute(w1,w2,w0,a.u,b.u,c.u,area,8);
                int v=reference_world_attribute(w1,w2,w0,a.v,b.v,c.v,area,8);
                if(put_hd_ui(x,y,red,green,blue,semi,u,v))continue;
            }
#endif
            if(filter_on()) {
                int u=reference_world_attribute(w1,w2,w0,a.u,b.u,c.u,area,8);
                int v=reference_world_attribute(w1,w2,w0,a.v,b.v,c.v,area,8);
                texel=sample_tex_fine(u-128,v-128);
            } else {
                int u=reference_world_attribute(w1,w2,w0,a.u,b.u,c.u,area,0);
                int v=reference_world_attribute(w1,w2,w0,a.v,b.v,c.v,area,0);
                texel=sample_tex(u,v);
            }
            }
        }
        put_fine(x,y,red,green,blue,semi,tex,texel);
    }
}
