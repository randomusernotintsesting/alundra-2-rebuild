"""Export native replay frames at the game's intended 4:3 display aspect."""
from pathlib import Path
from PIL import Image

BASE=Path(__file__).resolve().parents[1]/'build/verification/full-menu-v3'
def main():
    for folder,frames in (('settings-replay',(6400,)),('chest-replay',(19000,19300,19900,20300,20900,21300,21800,22300,23600))):
        for frame in frames:
            source=BASE/folder/f'shot_{frame:05}.bmp'
            if not source.is_file():continue
            image=Image.open(source)
            image.resize((640,480),Image.Resampling.NEAREST).save(BASE/f'{folder}-{frame:05}-4x3.png')
if __name__=='__main__':main()
