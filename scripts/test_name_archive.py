import struct
import tempfile
from pathlib import Path
import unittest
import repack_resources
from test_native_resources import fixture

class AppendNamesTests(unittest.TestCase):
    def test_existing_payload_is_preserved_and_new_records_are_added(self):
        with tempfile.TemporaryDirectory() as temporary:
            root=Path(temporary);base=root/'base.a2r';base.write_bytes(fixture())
            extra=root/'label';extra.write_bytes(b'JP name variant')
            self.assertTrue(hasattr(repack_resources,'append_files'), 'No lossless additive resource builder')
            report=repack_resources.append_files(base,root/'next.a2r',{(2,'NAMES/JA/LABEL'):extra})
            before=base.read_bytes();after=(root/'next.a2r').read_bytes()
            old=struct.unpack('<8s6I4Q',before[:64]);new=struct.unpack('<8s6I4Q',after[:64])
            self.assertEqual(new[3],old[3]+1)
            self.assertEqual(after[new[-1]:new[-1]+len(before)-old[-1]],before[old[-1]:])
            self.assertEqual(after[64:64+old[3]*96],before[64:64+old[3]*96])
            self.assertEqual(report['added_files'],1)
            with self.assertRaises(ValueError):
                repack_resources.append_files(base,root/'bad.a2r',{(0,'LABEL'):extra})
            self.assertFalse((root/'bad.a2r').exists())

if __name__=='__main__':unittest.main()
