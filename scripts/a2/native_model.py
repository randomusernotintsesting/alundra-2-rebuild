"""Deterministic A2M2 v1 encoder. The independent C reader validates publication.

Input records match native_model.h; None encodes an absent u32 reference.
See port/reports/a2m2-format.md for spaces, material and binary conventions.
"""
import math
import struct

ABSENT=0xffffffff
SIGNED_CORNER_RGB=1
CAPS=(1_000_000,3_000_000,128,64,256,64)


def _uint(x,maximum=ABSENT):
    if not isinstance(x,int) or isinstance(x,bool) or not 0<=x<=maximum:
        raise ValueError('invalid unsigned integer')
    return x


def _ref(x):return ABSENT if x is None else _uint(x)


def _text(x):
    try:b=x.encode('ascii')
    except (AttributeError,UnicodeError) as e:raise ValueError('ASCII name required') from e
    if not 1<=len(b)<=31 or any(c<32 or c>126 for c in b):raise ValueError('invalid name')
    return b.ljust(32,b'\0')


def _floats(values,n,unit=False):
    if len(values)!=n:raise ValueError('wrong float array size')
    out=[]
    for x in values:
        try:v=struct.unpack('<f',struct.pack('<f',x))[0]
        except (OverflowError,struct.error,TypeError) as e:raise ValueError('invalid float') from e
        if not math.isfinite(v) or (unit and not 0<=v<=1):raise ValueError('invalid float range')
        out.append(v)
    return out


def _bounds(values):
    b=_floats(values,6)
    if any(b[i]>b[i+3] for i in range(3)):raise ValueError('inverted bounds')
    return b


def _contains(bounds,pos):
    return all(bounds[i]-1e-4<=pos[i]<=bounds[i+3]+1e-4 for i in range(3))


def _matrix(values):
    m=_floats(values,16)
    if m[12:]!=[0,0,0,1]:raise ValueError('matrix must be affine')
    return m


def pack_model(model):
    file_flags=_uint(model.get("file_flags",0),SIGNED_CORNER_RGB)
    groups=[model[k] for k in ('vertices','indices','materials','joints','submeshes','textures')]
    nv,ni,nm,nj,ns,nt=counts=[len(g) for g in groups]
    if any(n>cap or (not n and i!=5) for i,(n,cap) in enumerate(zip(counts,CAPS))) or ni%3:
        raise ValueError('invalid section counts')
    width=model.get('index_width',2 if nv<=65536 else 4)
    if width not in (2,4):raise ValueError('index width must be 2 or 4')
    sha=model['source_sha256']
    if isinstance(sha,str):
        try:sha=bytes.fromhex(sha)
        except ValueError as e:raise ValueError('invalid source checksum') from e
    if not isinstance(sha,bytes) or len(sha)!=32 or not any(sha):raise ValueError('invalid source checksum')
    key=_text(model['source_key']);bounds=_bounds(model['bounds'])
    sections=[];positions=[]
    buf=bytearray()
    for v in groups[0]:
        pos=_floats(v['position'],3);normal=_floats(v['normal'],3)
        if abs(sum(x*x for x in normal)-1)>1e-3:raise ValueError('non-unit normal')
        if not _contains(bounds,pos):raise ValueError('vertex outside model bounds')
        uv=_floats(v['uv'][0],2)+_floats(v['uv'][1],2)
        color=_floats(v['color'][0],4)+_floats(v['color'][1],4)
        for i,c in enumerate(color):
            lo,hi=(-16,16) if file_flags & SIGNED_CORNER_RGB and i%4!=3 else (0,1)
            if not lo<=c<=hi:raise ValueError('invalid corner color range')
        joints=[_uint(i,65535) for i in v['joints']];weights=_floats(v['weights'],4,True)
        if len(joints)!=4 or abs(sum(weights)-1)>1e-4 or any(w and j>=nj for w,j in zip(weights,joints)):
            raise ValueError('invalid vertex influences')
        buf.extend(struct.pack('<18f4H4f',*(pos+normal+uv+color+joints+weights)));positions.append(pos)
    sections.append(buf)
    indices=[_uint(i,min(nv-1,65535 if width==2 else ABSENT)) for i in groups[1]]
    sections.append(struct.pack('<%d%s'%(ni,'H' if width==2 else 'I'),*indices))
    buf=bytearray()
    for m in groups[2]:
        kind=_uint(m['kind'],3);alpha=_uint(m['alpha_mode'],2)
        tex=[_ref(t) for t in m['texture']]
        if len(tex)!=2 or any(t!=ABSENT and t>=nt for t in tex):raise ValueError('material texture out of range')
        if kind in (1,2) and tex[0]==ABSENT:raise ValueError('atlas needs a texture')
        base=_floats(m['base_color'],4,True)
        factors=_floats([m[k] for k in ('roughness','metallic','alpha_cutoff','opacity','specular','ior','coat','coat_roughness')],8)
        if any(not 0<=x<=1 for i,x in enumerate(factors) if i!=5) or not 1<=factors[5]<=3:
            raise ValueError('invalid material factors')
        lo,hi=_floats([m['roughness_min'],m['roughness_max']],2,True)
        if lo>hi:raise ValueError('roughness range inverted')
        record=bytearray(128)
        struct.pack_into('<4I12fI2f',record,0,kind,alpha,*tex,*base,*factors,_uint(m['flags'],1),lo,hi)
        record[80:112]=_text(m['name']);buf.extend(record)
    sections.append(buf)
    buf=bytearray();source_ids=set();parents=[]
    for j in groups[3]:
        source=_uint(j['source_id'],ABSENT-1);parent=_ref(j['parent'])
        if source in source_ids or (parent!=ABSENT and parent>=nj):raise ValueError('invalid joint reference')
        source_ids.add(source);parents.append(parent)
        bind=_matrix(j['bind']);inverse=_matrix(j['inverse_bind'])
        for a,b in ((bind,inverse),(inverse,bind)):
            for r in range(4):
                for c in range(4):
                    terms=[a[4*r+k]*b[4*k+c] for k in range(4)]
                    if abs(sum(terms)-(r==c))>min(1e-3,1e-4+1e-6*sum(map(abs,terms))):
                        raise ValueError('bind inverse does not match')
        buf.extend(struct.pack('<4I32f',source,parent,_uint(j['flags'],1),0,*bind,*inverse))
    for i in range(nj):
        seen=set();p=i
        while p!=ABSENT:
            if p in seen:raise ValueError('joint parent cycle')
            seen.add(p);p=parents[p]
    sections.append(buf)
    buf=bytearray();ranges=[]
    for s in groups[4]:
        first=_uint(s['first_index']);count=_uint(s['index_count']);mat=_uint(s['material'],nm-1)
        source=_ref(s['source_part']);b=_bounds(s['bounds'])
        if first%3 or not count or count%3 or first+count>ni or (source!=ABSENT and source not in source_ids):
            raise ValueError('invalid submesh range or source')
        if any(not _contains(b,positions[indices[i]]) for i in range(first,first+count)):
            raise ValueError('vertex outside submesh bounds')
        ranges.append((first,first+count));buf.extend(struct.pack('<4I6f8x',first,count,mat,source,*b))
    if sum(b-a for a,b in ranges)!=ni:
        raise ValueError('incomplete submesh coverage')
    end=0
    for a,b in sorted(ranges):
        if a!=end:raise ValueError('overlapping or missing submesh range')
        end=b
    sections.append(buf)
    buf=bytearray();pixels=bytearray()
    for t in groups[5]:
        w=_uint(t['width'],4096);h=_uint(t['height'],4096);rgba=bytes(t['rgba'])
        if not w or not h or len(rgba)!=w*h*4:raise ValueError('invalid texture dimensions or pixels')
        if len(pixels)+len(rgba)>64*1024*1024:raise ValueError('pixel budget exceeded')
        buf.extend(struct.pack('<2I2Q2I',w,h,len(pixels),len(rgba),_uint(t['flags'],1),0));pixels.extend(rgba)
    sections.append(buf)
    output=bytearray(256);offsets=[]
    for section in sections+[pixels]:
        output.extend(bytes((-len(output))%4));offsets.append(len(output));output.extend(section)
    if len(output)>128*1024*1024:raise ValueError('file budget exceeded')
    struct.pack_into('<8s2IQ2I8I8Q',output,0,b'A2M2\0\0\0\0',1,256,len(output),file_flags,
                     _uint(model.get('source_variant',0)),*counts,width,0,*offsets,len(pixels))
    output[128:160]=sha;output[160:192]=key;struct.pack_into('<6f',output,192,*bounds)
    return bytes(output)
