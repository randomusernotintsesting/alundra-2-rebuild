#!/usr/bin/env python3
"""Validate the bounded cabin capture and publish three proven pose clips."""
import argparse
import json
from pathlib import Path
import shutil
import statistics

from a2.animation_bridge import (convert_submission, fixed_vertex, multiply,
    rtp_sequences, sha, transform, validate_live_rtp, write_json)


CLIPS = {
    'idle': dict(start=3048,end=3109,loop=True,selector=0,frames=30,
                 recorded_action='neutral input; original standing animation'),
    'walk': dict(start=3302,end=3352,loop=True,selector=5,frames=24,
                 recorded_action='D-pad down held in cabin b30; original movement'),
    'attack': dict(start=3597,end=3646,loop=False,selector=82,frames=15,
                   recorded_action='one Square press, bit 15; action 0 -> 82 -> 0'),
}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--capture',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();cap=args.capture.resolve();out=args.output.resolve()
    manifest=json.loads((out/'manifest.json').read_text())
    source=json.loads((cap/'source-proof-final.json').read_text())
    if manifest['source'] != source['manifest_identity']:
        raise ValueError('end-of-capture resource identity differs from reference')
    geometry=json.loads((out/'geometry.json').read_text())
    geometry={g['source_mesh_index']:g for g in geometry['parts']}
    if set(geometry)!=set(range(16)) or sum(len(g['vertices_local']) for g in geometry.values())!=430:
        raise ValueError('reference geometry must contain all 16 PC00 parts / 430 vertices')
    rtp=rtp_sequences(cap/'modelcap.txt');samples=[];rejected=[];vertices=0
    frames=[]
    for line in (cap/'actor-snapshots.jsonl').open():
        f=json.loads(line)
        if not 2990<=f['guest_frame']<4000:continue
        if not f['valid']:
            rejected.append(f['guest_frame']);continue
        if f['shadow_pass']:continue
        candidates=[b for b in rtp.get(f['guest_frame'],[]) if
                    b['object']==f['draw_object_address'] and not b['flags']&0x100]
        if len(candidates)!=1:raise ValueError('ambiguous or missing sequential PART proof')
        vertices+=validate_live_rtp(f,candidates[0],geometry,0x80119710)
        s=convert_submission(f,0x80119710,list(range(16)))
        if s is None:raise ValueError('missing PC00 instance')
        samples.append(s);frames.append(f)
    if not samples:raise ValueError('no verified live samples')
    capture_hash=sha(cap/'actor-snapshots.jsonl')
    clip_data={};clip_validation={}
    for name,spec in CLIPS.items():
        data=[s for s in samples if spec['start']<=s['guest_frame']<=spec['end']]
        if not data or any(spec['start']<=f<=spec['end'] for f in rejected):
            raise ValueError(f'{name}: missing/rejected submissions inside selected clip')
        if data[0]['guest_frame']!=spec['start'] or data[-1]['guest_frame']!=spec['end']:
            raise ValueError(f'{name}: missing clip endpoint')
        generations={json.dumps(s['actor_instance_id'],sort_keys=True) for s in data}
        if len(generations)!=1 or not data[0]['actor_instance_id']['generation_known']:
            raise ValueError(f'{name}: unknown/mixed actor lifetime')
        t0=data[0]['capture_monotonic_ns'];errors=[];periods=[]
        for index,s in enumerate(data):
            if s['valid_mask']!=65535 or s['visible_mask']!=65535:
                raise ValueError(f'{name}: incomplete pose')
            if not s['capture_clock_known'] or not s['animation']['clock_known']:
                raise ValueError(f'{name}: unknown clock/controller provenance')
            if index:
                prior=data[index-1]
                if s['animation']['entity_update_calls']-prior['animation']['entity_update_calls']!=1:
                    raise ValueError(f'{name}: missing or repeated entity update')
                dt=(s['capture_monotonic_ns']-prior['capture_monotonic_ns'])/1e9
                if dt<=0:raise ValueError(f'{name}: nonmonotone time')
                periods.append(dt)
            s['sample_id']=index
            s['simulation_tick']=s['animation']['entity_update_calls']
            s['simulation_tick_kind']='observed PC00 entity-update sequence; not a uniform-rate clock'
            s['time_seconds']=(s['capture_monotonic_ns']-t0)/1e9
            s['time_basis']='observed monotonic elapsed seconds in paced capture'
            s['nominal_host_time_seconds']=(s['guest_frame']-data[0]['guest_frame'])/60
            s['actor_instance_id']['capture_sha256']=capture_hash
            s['asset_identity']=dict(asset_id='PC00',variant=0,
                mesh_sha256=manifest['source']['mesh']['sha256'],
                proof='manifest.json source; normalized reference and final RAM resources')
            camera=[v>>12 for v in s['camera']['origin_q12']]
            for p in s['parts']:
                if not p['matrix_only_reproduction_valid']:
                    raise ValueError(f'{name}: separately deformed source needs vertex stream')
                world=multiply(s['actor_to_world'],p['part_to_actor'])
                for v in geometry[p['source_mesh_index']]['vertices_local']:
                    fixed=fixed_vertex(v,p['matrix_q12'],p['pretranslation'],p['translation0'],p['translation1'],camera)
                    floating=transform(world,v)
                    errors.extend(abs(floating[k]-(fixed[k]+camera[k])) for k in range(3))
        if spec['loop']:
            a,b=data[0]['animation'],data[-1]['animation']
            if (a['frame']!=0 or b['frame']!=0 or b['loops']!=a['loops']+1 or
                any(s['animation']['selector']!=spec['selector'] for s in data) or
                [s['animation']['frame'] for s in data] != list(range(spec['frames']))+[0]):
                raise ValueError(f'{name}: not one complete original controller cycle')
        else:
            states=[s['action_id'] for s in data]
            attack=[s for s in data if s['action_id']==82]
            if states[0]!=0 or states[-1]!=0 or set(states)!={0,82}:
                raise ValueError('attack lacks entry/return')
            if sorted(set(s['animation']['frame'] for s in attack))!=list(range(15)):
                raise ValueError('attack lacks original frames 0..14')
            if any(s['animation']['selector']!=82 for s in attack):
                raise ValueError('attack selector mismatch')
        clip_data[name]=data
        clip_validation[name]=dict(samples=len(data),all_parts_valid=True,all_parts_visible=True,
            actor_generations=1,entity_update_step=1,all_native_vertices_exact=True,
            native_vertex_comparisons=430*len(data),camera_matrix_matches_live_rtp=True,
            float_vs_fixed_max_coordinate_error=max(errors),
            float_vs_fixed_mean_coordinate_error=sum(errors)/len(errors),
            observed_update_rate_hz=(len(data)-1)/data[-1]['time_seconds'],
            observed_interval_seconds=dict(min=min(periods),median=statistics.median(periods),max=max(periods)),
            duration_seconds=data[-1]['time_seconds'],full_cycle_or_action=True,
            root_displacement_game_units=[data[-1]['actor_to_world'][i]-data[0]['actor_to_world'][i] for i in (3,7,11)])
    # Publish only after every clip passes; the original reference stays intact.
    (out/'clips').mkdir(exist_ok=True)
    for name,data in clip_data.items():
        path=out/'clips'/f'{name}.jsonl'
        path.write_text(''.join(json.dumps(s,ensure_ascii=False,separators=(',',':'),allow_nan=False)+'\n' for s in data))
        manifest['clips'][name]=dict(status='verified',path=f'clips/{name}.jsonl',sha256=sha(path),
            **CLIPS[name],**clip_validation[name])
    validation=json.loads((out/'validation.json').read_text())
    validation['live_capture']=dict(samples=len(samples),exact_pc00_vertex_comparisons=vertices,
        rejected_host_frames_outside_selected_clips=rejected,clips=clip_validation,
        source_unchanged_at_end=True,capture_sha256=capture_hash)
    write_json(out/'validation.json',validation)
    for name in ['launch.json','result.json','source-proof-final.json']:
        shutil.copy2(cap/name,out/'evidence'/('live-'+name))
    manifest['status']='verified_reference_and_three_clips'
    manifest['coordinates']['seconds']='time_seconds: observed monotonic elapsed; nominal_host_time_seconds: host labels/60, explicitly not original animation FPS'
    manifest['coordinates']['camera_matrix']='actual GTE Q12 projection rotation may include scale; do not normalize it or use it as a bone transform'
    manifest['runtime_binding']='source_key/source_sha256 inside raw part records remain unbound; asset_identity is independently proved offline for this capture'
    manifest['limits']=['Original anatomical hierarchy and rest pose remain unknown.',
        'Reference chooses frame2999 as bind pose; approved modern mesh has not yet been weighted.',
        'Two rejected submissions outside selected clips are retained in raw evidence; selected clips have consecutive entity updates.',
        'No universal animation FPS is inferred; capture wall timing includes the diagnostic recording overhead.',
        'New host renderer, detailed mesh skinning and in-game replacement are separate work.']
    write_json(out/'manifest.json',manifest)
    print(json.dumps(dict(clips=clip_validation,total_native_vertex_comparisons=vertices),indent=2))


if __name__=='__main__':main()
