"""Build native English captions and SRT from a reviewed word-timed catalog."""
import argparse
import json
from pathlib import Path
import re
import textwrap

def wrapped(text):
    text=re.sub(r" ([,.;:!?'’]|-)",r'\1',text)
    lines=textwrap.wrap(text,width=52,break_long_words=False,break_on_hyphens=False)
    if len(lines)>2 or any(len(line)>52 for line in lines):return None
    return '\n'.join(lines)

def caption_words(words,duration_ms):
    clean=[]
    for word in words:
        text=' '.join(word['word'].split())
        start=round(word['start']*1000);end=round(word['end']*1000)
        if start<0 or end<start or start>duration_ms:raise ValueError('Invalid word timing')
        if text:clean.append(dict(word=text,start=start,end=min(end,duration_ms)))
    groups=[];current=[]
    for word in clean:
        if current:
            candidate=' '.join(w['word'] for w in current+[word])
            boundary=(word['start']-current[-1]['end']>=700 or
                      re.search(r'[.!?][\"\']?$',current[-1]['word']) or
                      word['end']-current[0]['start']>6000 or wrapped(candidate) is None)
            if boundary:groups.append(current);current=[]
        if wrapped(word['word']) is None:raise ValueError('Unreviewed oversized word')
        current.append(word)
    if current:groups.append(current)
    captions=[]
    for i,group in enumerate(groups):
        start=group[0]['start'];end=max(group[-1]['end']+250,start+800)
        end=min(end,duration_ms,start+6500)
        if i+1<len(groups):end=min(end,groups[i+1][0]['start'])
        if end<=start:raise ValueError('Overlapping or empty subtitle interval')
        captions.append(dict(start_ms=start,end_ms=end,text=wrapped(' '.join(w['word'] for w in group))))
    return captions

def srt(captions):
    def stamp(ms):
        hours,ms=divmod(ms,3600000);minutes,ms=divmod(ms,60000);seconds,ms=divmod(ms,1000)
        return f'{hours:02}:{minutes:02}:{seconds:02},{ms:03}'
    return ''.join(f"{i}\n{stamp(c['start_ms'])} --> {stamp(c['end_ms'])}\n{c['text']}\n\n" for i,c in enumerate(captions,1))

def build(catalog,header,output):
    entries=[];clips=[];seen=set();output.mkdir(parents=True,exist_ok=True)
    plain=['Все русские реплики английской озвучки',
           'Перевод английской записи. Время указано от начала соответствующей сцены.', '']
    for language in ('en','ru'):(output/language).mkdir(exist_ok=True)
    for clip in sorted(catalog['clips'],key=lambda r:r['name']):
        name=clip['name']
        if not re.fullmatch('[A-Za-z0-9_]{1,15}',name) or name in seen:raise ValueError('Invalid cue name')
        seen.add(name)
        if clip['status'] not in ('speech','non_speech','non_english','missing_english'):raise ValueError('Unreviewed clip')
        captions=clip.get('captions',caption_words(clip.get('words',[]),clip['duration_ms']))
        if bool(captions)!=(clip['status']=='speech'):raise ValueError('Speech classification mismatch')
        translated=[];previous_end=0
        for c in captions:
            if not(0<=previous_end<=c['start_ms']<c['end_ms']<=clip['duration_ms']):raise ValueError('Invalid caption interval')
            previous_end=c['end_ms']
            ru=catalog.get('russian',{}).get(name+':'+str(c['start_ms']))
            if not ru or not wrapped(ru.replace('\n',' ')):raise ValueError(f'Missing or oversized Russian subtitle {name}:{c["start_ms"]}')
            if not wrapped(c['text'].replace('\n',' ')):raise ValueError('Oversized English subtitle')
            translated.append(dict(c,text=wrapped(ru.replace('\n',' '))))
        clips.append((name,len(entries),len(captions)))
        entries.extend(dict(c,ru=r['text']) for c,r in zip(captions,translated))
        if translated:
            plain += [f'СЦЕНА {name}', '']
            first = len(entries) - len(translated) + 1
            for number, c in enumerate(translated, first):
                minutes, ms = divmod(c['start_ms'], 60000); seconds, ms = divmod(ms, 1000)
                plain += [f"{number:03d}. [{minutes:02d}:{seconds:02d}.{ms:03d}] {c['text'].replace(chr(10), ' ')}", '']
        (output/'en'/f'{name}.srt').write_text(srt(captions),encoding='utf-8')
        (output/'ru'/f'{name}.srt').write_text(srt(translated),encoding='utf-8')
    lines=['/* Generated from the reviewed English source-audio catalog. */',
           'static const SubtitleEntry subtitle_entries[] = {']
    for c in entries:lines.append('    {%d,%d,%s,%s},'%(c['start_ms'],c['end_ms'],json.dumps(c['text'],ensure_ascii=True),json.dumps(c['ru'],ensure_ascii=True)))
    lines+=['};','static const SubtitleClip subtitle_clips[] = {']
    lines += ['    {"%s",%d,%d},'%c for c in clips]
    lines+=['};','']
    header.parent.mkdir(parents=True,exist_ok=True);header.write_text('\n'.join(lines))
    plain.insert(2, f'Всего реплик: {len(entries)}. Сцен с речью: {sum(c[2]>0 for c in clips)}.')
    (output/'Все русские реплики английской озвучки.txt').write_text('\n'.join(plain), encoding='utf-8')
    return dict(clips=len(clips),captions=len(entries),speech_clips=sum(c[2]>0 for c in clips))

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('catalog',type=Path);p.add_argument('--header',type=Path,required=True)
    p.add_argument('--srt',type=Path,required=True);a=p.parse_args()
    print(json.dumps(build(json.loads(a.catalog.read_text()),a.header,a.srt),indent=2))

if __name__=='__main__':main()
