#!/usr/bin/env python3
"""Local web editor for the translation JSONs.

Usage: editor.py [-p port] [-c charmap.json]

Serves http://localhost:8765 with:
  - all translation files (grp/pack0/vcast/ui), search, filters, progress
  - inline editing with live encoding validation and dialogue-box preview
  - "insert + build disc" button producing build/alundra2_ru.bin

Saves go straight back to translations/*.json (atomic replace).
"""
import json
import os
import re
import subprocess
import sys
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from a2.textcodec import Message, encode_message
import ui_text

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRANS = os.path.join(ROOT, "translations")
FILES = {
    "grp": ("grp_text.json", "Диалоги (GRP.GP)"),
    "pack0": ("pack0_text.json", "Система/предметы (PACK0)"),
    "vcast": ("vcast_text.json", "Катсцены (PAKVCAST)"),
    "ui": ("ui_text.json", "UI мини-игр (GAME0x)"),
}

LOCK = threading.Lock()
DATA = {}      # key -> loaded JSON document
CHARMAP = None


def load_all():
    for key, (fname, _) in FILES.items():
        path = os.path.join(TRANS, fname)
        if os.path.exists(path):
            with open(path, encoding="utf-8") as f:
                DATA[key] = json.load(f)


def save_file(key):
    path = os.path.join(TRANS, FILES[key][0])
    tmp = path + ".tmp"
    with open(tmp, "w", encoding="utf-8") as f:
        json.dump(DATA[key], f, ensure_ascii=False, indent=1)
    os.replace(tmp, path)


def validate(key, entry_id, text):
    """-> {ok, error?, warnings: []}"""
    warnings = []
    if not text:
        return {"ok": True, "warnings": []}
    if key == "ui":
        entry = DATA[key]["entries"].get(entry_id, {})
        enc = "shift_jis" if entry_id.startswith("GAME00") else "ascii"
        try:
            raw = ui_text.encode_slot(text, enc)
        except (ValueError, UnicodeEncodeError) as e:
            return {"ok": False, "error": str(e), "warnings": []}
        maxlen = entry.get("max_inplace", 9999)
        if len(raw) > maxlen:
            warnings.append(f"длиннее слота ({len(raw)} > {maxlen} Б) — "
                            "вставка потребует --extend")
        return {"ok": True, "warnings": warnings}
    try:
        encode_message(Message(text, 1), CHARMAP)
    except ValueError as e:
        return {"ok": False, "error": str(e), "warnings": []}
    for page in text.split("{PAGE}"):
        lines = page.split("\n")
        if len(lines) > 3:
            warnings.append(f"{len(lines)} строк на страницу (обычно ≤3)")
        for ln in lines:
            plain = re.sub(r"\{[^}]*\}", "", ln)
            if len(plain) > 34:
                warnings.append(f"строка {len(plain)} симв. (~34 влезает): "
                                f"«{plain[:20]}…»")
    return {"ok": True, "warnings": warnings[:4]}


DISC = "disc_jp"  # localization base


def run_build(disc_too):
    steps = [[sys.executable, "scripts/text_insert.py", "-d", DISC]]
    if "ui" in DATA:
        steps.append([sys.executable, "scripts/ui_text.py", "insert", "-d", DISC])
    if disc_too:
        steps.append(["sh", "scripts/build_disc.sh", "build/alundra2_ru", DISC])
    log = []
    for cmd in steps:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           timeout=1800)
        log.append("$ " + " ".join(cmd) + "\n" + r.stdout + r.stderr)
        if r.returncode != 0:
            return False, "\n".join(log)
    return True, "\n".join(log)


class Handler(BaseHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def _json(self, obj, code=200):
        body = json.dumps(obj, ensure_ascii=False).encode()
        self.send_response(code)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        if self.path == "/":
            body = HTML.encode()
            self.send_response(200)
            self.send_header("Content-Type", "text/html; charset=utf-8")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
        elif self.path == "/api/files":
            out = {}
            with LOCK:
                for key in DATA:
                    es = DATA[key]["entries"]
                    out[key] = {
                        "label": FILES[key][1],
                        "total": len(es),
                        "done": sum(1 for e in es.values() if e.get("text")),
                    }
            self._json(out)
        elif self.path.startswith("/api/entries"):
            key = self.path.split("=", 1)[1]
            with LOCK:
                if key not in DATA:
                    return self._json({"error": "no such file"}, 404)
                self._json(DATA[key]["entries"])
        else:
            self._json({"error": "not found"}, 404)

    def do_POST(self):
        n = int(self.headers.get("Content-Length", 0))
        req = json.loads(self.rfile.read(n) or b"{}")
        if self.path == "/api/save":
            key, eid, text = req["file"], req["id"], req["text"]
            with LOCK:
                if key not in DATA or eid not in DATA[key]["entries"]:
                    return self._json({"error": "no such entry"}, 404)
                DATA[key]["entries"][eid]["text"] = text
                save_file(key)
            self._json({"ok": True, **validate(key, eid, text)})
        elif self.path == "/api/validate":
            with LOCK:
                self._json(validate(req["file"], req["id"], req["text"]))
        elif self.path == "/api/build":
            ok, log = run_build(req.get("disc", False))
            self._json({"ok": ok, "log": log})
        else:
            self._json({"error": "not found"}, 404)


HTML = r"""<!doctype html><html lang="ru"><head><meta charset="utf-8">
<title>Alundra 2 — редактор перевода</title>
<style>
:root{--bg:#16161e;--panel:#1f1f2b;--line:#2e2e3e;--fg:#d6d6e0;--dim:#8a8a9a;
--acc:#7aa2f7;--ok:#9ece6a;--warn:#e0af68;--err:#f7768e;--gold:#ffd166}
*{box-sizing:border-box}body{margin:0;background:var(--bg);color:var(--fg);
font:14px/1.45 -apple-system,'Segoe UI',sans-serif;display:flex;height:100vh}
#side{width:270px;min-width:270px;background:var(--panel);border-right:1px solid var(--line);
padding:14px;display:flex;flex-direction:column;gap:10px}
h1{font-size:15px;margin:0 0 4px}
.file{padding:8px 10px;border:1px solid var(--line);border-radius:8px;cursor:pointer}
.file.sel{border-color:var(--acc);background:#232336}
.file .bar{height:4px;background:var(--line);border-radius:2px;margin-top:6px}
.file .bar i{display:block;height:4px;background:var(--ok);border-radius:2px}
.file small{color:var(--dim)}
input[type=search]{width:100%;padding:7px 9px;border-radius:7px;border:1px solid var(--line);
background:var(--bg);color:var(--fg)}
select{width:100%;padding:6px;border-radius:7px;background:var(--bg);color:var(--fg);
border:1px solid var(--line)}
button{padding:8px 10px;border-radius:7px;border:1px solid var(--line);background:#283045;
color:var(--fg);cursor:pointer}button:hover{border-color:var(--acc)}
#buildlog{font:11px/1.4 ui-monospace,monospace;white-space:pre-wrap;color:var(--dim);
max-height:160px;overflow:auto;display:none;background:var(--bg);padding:8px;border-radius:7px}
#main{flex:1;overflow-y:auto;padding:16px 22px}
.entry{border:1px solid var(--line);border-radius:10px;padding:10px 14px;margin-bottom:10px;
background:var(--panel)}
.entry .id{font:12px ui-monospace,monospace;color:var(--acc)}
.entry .ctx{color:var(--dim);font-size:12px;margin-left:8px}
.orig{margin:6px 0;white-space:pre-wrap;font:13px ui-monospace,monospace;color:#c8c8d8}
.tag{color:var(--gold);background:#2a2a1e;border-radius:4px;padding:0 3px;font-size:11px}
textarea{width:100%;min-height:54px;background:var(--bg);color:var(--fg);
border:1px solid var(--line);border-radius:7px;padding:7px 9px;
font:13px ui-monospace,monospace;resize:vertical}
textarea:focus{outline:none;border-color:var(--acc)}
.entry.dirty textarea{border-color:var(--warn)}
.msg{font-size:12px;margin-top:4px;min-height:14px}
.msg.err{color:var(--err)}.msg.warn{color:var(--warn)}.msg.ok{color:var(--ok)}
.preview{margin-top:6px;display:none;gap:8px;flex-wrap:wrap}
.pv{border:2px solid #46507a;border-radius:6px;background:#0d0d16;padding:8px 12px;
font:13px/1.5 ui-monospace,monospace;white-space:pre-wrap;min-width:280px;max-width:480px}
.pv .name{color:#9ece6a}.pv .hl{color:var(--gold)}.pv .sys{color:#7dcfff}
.foot{display:flex;gap:10px;align-items:center;margin-top:6px}
.foot .lbl{font-size:11px;color:var(--dim)}
#more{margin:10px auto;display:block}
.count{color:var(--dim);font-size:12px}
</style></head><body>
<div id="side">
 <h1>Alundra 2 — перевод</h1>
 <div id="files"></div>
 <input type="search" id="q" placeholder="поиск: текст, id…">
 <select id="filter">
  <option value="all">все строки</option>
  <option value="todo">непереведённые</option>
  <option value="done">переведённые</option>
 </select>
 <span class="count" id="count"></span>
 <button id="insertBtn">Вставить в архивы (disc/)</button>
 <button id="buildBtn">Вставить + собрать образ</button>
 <div id="buildlog"></div>
 <span class="count">Сохранение — автоматически при<br>уходе из поля (или Cmd+S)</span>
</div>
<div id="main"><div id="list"></div><button id="more" style="display:none">показать ещё</button></div>
<script>
let FILEKEY='grp', ENTRIES={}, SHOWN=0, PAGE=60;
const $=s=>document.querySelector(s);
const esc=s=>s.replace(/&/g,'&amp;').replace(/</g,'&lt;');
const fmt=s=>esc(s).replace(/\{[^}]*\}/g,m=>'<span class="tag">'+m+'</span>');

async function loadFiles(){
 const d=await (await fetch('/api/files')).json();
 $('#files').innerHTML=Object.entries(d).map(([k,f])=>
  `<div class="file ${k===FILEKEY?'sel':''}" data-k="${k}">${f.label}
   <small>${f.done}/${f.total}</small>
   <div class="bar"><i style="width:${f.total?100*f.done/f.total:0}%"></i></div></div>`).join('');
 document.querySelectorAll('.file').forEach(el=>el.onclick=()=>{
  FILEKEY=el.dataset.k;$('#q').value='';$('#filter').value='all';loadEntries();});
}
async function loadEntries(){
 ENTRIES=await (await fetch('/api/entries?file='+FILEKEY)).json();
 await loadFiles(); render(true);
}
function visible(){
 const q=$('#q').value.toLowerCase(), f=$('#filter').value;
 return Object.entries(ENTRIES).filter(([id,e])=>{
  if(f==='todo'&&e.text)return false;
  if(f==='done'&&!e.text)return false;
  if(q&&!(id.toLowerCase().includes(q)||e.orig.toLowerCase().includes(q)
    ||(e.text||'').toLowerCase().includes(q)||(e.ctx||'').toLowerCase().includes(q)))return false;
  return true;});
}
function render(reset){
 if(reset)SHOWN=0;
 const vis=visible(); SHOWN=Math.min(vis.length,SHOWN+PAGE);
 $('#count').textContent=vis.length+' строк';
 if(!vis.length&&Object.keys(ENTRIES).length){
  $('#list').innerHTML='<div class="count">Ничего не найдено — мешает поиск или фильтр. '
   +'<button id="clearq">Сбросить</button></div>';
  $('#more').style.display='none';
  $('#clearq').onclick=()=>{$('#q').value='';$('#filter').value='all';render(true);};
  return;
 }
 $('#list').innerHTML=vis.slice(0,SHOWN).map(([id,e])=>{
  const mi=e.max_inplace!==undefined?` · слот ${e.max_inplace} Б`:'';
  return `<div class="entry" data-id="${esc(id)}">
   <span class="id">${esc(id)}</span><span class="ctx">${esc(e.ctx||'')}${mi}</span>
   <div class="orig">${fmt(e.jp||e.orig)}</div>
   ${e.en?`<div class="orig" style="color:#9ece6a">${fmt(e.en)}</div>`:''}
   <textarea spellcheck="false" placeholder="перевод…">${esc(e.text||'')}</textarea>
   <div class="msg"></div>
   <div class="foot">
    <button class="pvbtn">предпросмотр</button>
    <span class="lbl">ориг. ${e.orig.length} симв.</span>
   </div>
   <div class="preview"></div>
  </div>`;}).join('');
 $('#more').style.display=SHOWN<vis.length?'block':'none';
 document.querySelectorAll('.entry').forEach(hook);
}
function preview(el,text){
 const box=el.querySelector('.preview');
 const pages=(text||el.dataset&&'').split('{PAGE}');
 box.innerHTML=pages.map(p=>'<div class="pv">'+esc(p)
   .replace(/\{NAME\}/g,'<span class="name">Флинт</span>')
   .replace(/\{04:0001\}/g,'<span class="hl">').replace(/\{04:0007\}/g,'</span>')
   .replace(/\{SYS\}/g,'<span class="sys">◆</span>')
   .replace(/\{[^}]*\}/g,m=>'<span class="tag">'+m+'</span>')
   +'</div>').join('');
 box.style.display='flex';
}
function hook(el){
 const id=el.dataset.id, ta=el.querySelector('textarea'), msg=el.querySelector('.msg');
 let saved=ENTRIES[id].text||'', timer;
 const check=async()=>{
  const r=await (await fetch('/api/validate',{method:'POST',
    body:JSON.stringify({file:FILEKEY,id,text:ta.value})})).json();
  if(!r.ok){msg.className='msg err';msg.textContent='✗ '+r.error;}
  else if(r.warnings&&r.warnings.length){msg.className='msg warn';msg.textContent='⚠ '+r.warnings.join(' · ');}
  else{msg.className='msg ok';msg.textContent=ta.value?'✓ кодируется':'';}
 };
 ta.oninput=()=>{el.classList.toggle('dirty',ta.value!==saved);
  clearTimeout(timer);timer=setTimeout(check,300);};
 ta.onblur=async()=>{ if(ta.value===saved) return;
  const r=await (await fetch('/api/save',{method:'POST',
    body:JSON.stringify({file:FILEKEY,id,text:ta.value})})).json();
  if(r.ok!==false){saved=ta.value;ENTRIES[id].text=ta.value;el.classList.remove('dirty');loadFiles();}
 };
 el.querySelector('.pvbtn').onclick=()=>preview(el,ta.value||ENTRIES[id].orig);
}
$('#q').oninput=()=>render(true);
$('#filter').onchange=()=>render(true);
$('#more').onclick=()=>render(false);
document.addEventListener('keydown',e=>{
 if((e.metaKey||e.ctrlKey)&&e.key==='s'){e.preventDefault();
  document.activeElement&&document.activeElement.blur();}});
async function build(disc){
 const log=$('#buildlog');log.style.display='block';
 log.textContent=disc?'Вставка + сборка образа… (1–3 мин)':'Вставка в архивы…';
 const r=await (await fetch('/api/build',{method:'POST',body:JSON.stringify({disc})})).json();
 log.textContent=(r.ok?'ГОТОВО\n':'ОШИБКА\n')+r.log;
}
$('#insertBtn').onclick=()=>build(false);
$('#buildBtn').onclick=()=>build(true);
loadEntries();
</script></body></html>"""


def main():
    args = sys.argv[1:]
    port = int(args[args.index("-p") + 1] if "-p" in args
               else os.environ.get("PORT", 8765))
    global CHARMAP
    if "-c" in args:
        with open(args[args.index("-c") + 1], encoding="utf-8") as f:
            CHARMAP = {k: int(v) for k, v in json.load(f).items()}
    load_all()
    if not DATA:
        print("translations/ пуст — сначала запустите text_dump.py и "
              "ui_text.py dump", file=sys.stderr)
        sys.exit(1)
    srv = ThreadingHTTPServer(("127.0.0.1", port), Handler)
    print(f"Редактор: http://localhost:{port}  (Ctrl+C — выход)")
    srv.serve_forever()


if __name__ == "__main__":
    main()
