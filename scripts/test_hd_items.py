import importlib
import unittest
import struct
from PIL import Image
from a2.pak import PakArchive

class HDItemTests(unittest.TestCase):
    def test_pixel_art_compilation_does_not_blur_cluster_boundaries(self):
        module=importlib.import_module('build_hd_items')
        palette=struct.pack('<HHH',0x801f,0,0x03e0)
        source=Image.new('RGBA',(2,2))
        source.putdata([(255,0,0,255),(0,255,0,255),
                        (255,0,0,0),(0,255,0,128)])
        pixels=module.encode_pixel_art(source,palette)
        self.assertEqual(len(pixels),128*128)
        for y in range(128):
            for x in range(128):
                pixel=pixels[y*128+x]
                self.assertEqual(pixel&255,0 if x<64 else 2)
                self.assertEqual((pixel>>16)&255,0)
                self.assertEqual(pixel>>24,255 if y<64 else (0 if x<64 else 128))

    def test_palette_word_not_index_controls_transparency(self):
        module=importlib.import_module('build_hd_items')
        palette=struct.pack('<HHH',0x801f,0,0x03e0)
        pixels=module.encode_rgba(bytes((255,0,0,255,255,0,0,0,0,255,0,128)),palette)
        self.assertEqual((pixels[0]&255,pixels[0]>>24),(0,255))
        self.assertEqual(pixels[1]>>24,0)
        self.assertEqual((pixels[2]&255,pixels[2]>>24),(2,128))
        self.assertTrue(all((p&255)!=1 and ((p>>8)&255)!=1 for p in pixels))

    def test_generated_herb_keeps_exact_native_source_and_transparent_edges(self):
        module=importlib.import_module('build_hd_items')
        archive=PakArchive.load(module.ROOT/'disc.orig/DATA/PACK0.PAK')
        asset=module.build_herb(archive)
        self.assertEqual((asset['uv'],asset['bpp']),((128,192,32,32),4))
        self.assertEqual(len(asset['source']),1024)
        self.assertEqual(len(asset['pixels']),16384)
        self.assertTrue(any(0<(p>>24)<255 for p in asset['pixels']))
        self.assertTrue(any((p>>24)==255 for p in asset['pixels']))
        self.assertTrue(all((p&255)<10 and ((p>>8)&255)<10 for p in asset['pixels']))
        self.assertEqual(asset['pixels'][0]>>24,0)

if __name__=='__main__': unittest.main()
