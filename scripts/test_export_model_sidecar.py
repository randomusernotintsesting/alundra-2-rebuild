import importlib.util
import math
from pathlib import Path
import struct
import tempfile
import unittest


class SidecarArrays(unittest.TestCase):
    def setUp(self):
        path=Path(__file__).with_name('export_model_sidecar.py')
        self.assertTrue(path.is_file(), 'model sidecar exporter has not been implemented')
        spec=importlib.util.spec_from_file_location('export_model_sidecar',path)
        self.module=importlib.util.module_from_spec(spec);spec.loader.exec_module(self.module)
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.path=Path(self.temp.name)/'arrays.bin'

    def test_little_endian_rows_roundtrip_and_offsets(self):
        writer=self.module.ArrayBlob(self.path)
        a=writer.add([[1.25,-2.5,3.75],[0,4,8]],'f32',3)
        b=writer.add([[1,0,1]],'u32',3);writer.close()
        raw=self.path.read_bytes()
        self.assertEqual(a,{'offset':0,'count':2,'components':3,'dtype':'f32','bytes':24})
        self.assertEqual(b['offset'],24)
        self.assertEqual(struct.unpack('<6f3I',raw),(1.25,-2.5,3.75,0,4,8,1,0,1))

    def test_invalid_numeric_data_is_not_written(self):
        writer=self.module.ArrayBlob(self.path)
        for values,dtype,width in [([[math.nan]],'f32',1),([[math.inf]],'f32',1),([[-1]],'u32',1),([[2**32]],'u32',1),([[1.5]],'u32',1),([[1,2]],'f32',3)]:
            with self.assertRaises(ValueError):writer.add(values,dtype,width)
        writer.close();self.assertEqual(self.path.read_bytes(),b'')

    def test_existing_file_is_preserved(self):
        self.path.write_bytes(b'owned')
        with self.assertRaises(FileExistsError):self.module.ArrayBlob(self.path)
        self.assertEqual(self.path.read_bytes(),b'owned')


if __name__=='__main__':unittest.main()
