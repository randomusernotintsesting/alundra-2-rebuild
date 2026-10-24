"""Read-only A2RES resource inspection for deterministic text cooks."""
import bisect
import functools
import struct
import zlib

class NativeArchive:
    def __init__(self, path):
        self.file = path.open('rb')
        magic, version, mask, nf, ns, nc, crc, fo, so, co, do = struct.unpack('<8s6I4Q', self.file.read(64))
        if magic != b'A2RES001' or version != 1 or fo != 64: raise ValueError('Invalid archive header')
        table = self.file.read(do - 64)
        if zlib.crc32(table) != crc: raise ValueError('Invalid archive table CRC')
        self.records = {}
        for i in range(nf):
            n, lang, flags, size, first, count, reserved = struct.unpack_from('<64sIIQIIQ', table, i * 96)
            self.records[lang, n.rstrip(b'\0').decode()] = (size, first, count)
        self.spans = [struct.unpack_from('<Q4I', table, so - 64 + i * 24) for i in range(ns)]
        self.chunks = [struct.unpack_from('<Q4I', table, co - 64 + i * 24) for i in range(nc)]

    @functools.lru_cache(maxsize=32)
    def chunk(self, index):
        o, stored, raw, crc, codec = self.chunks[index]
        self.file.seek(o); encoded = self.file.read(stored)
        data = zlib.decompress(encoded) if codec else encoded
        if len(data) != raw or zlib.crc32(data) != crc: raise ValueError('Invalid archive chunk')
        return data

    def logical(self, lang, name):
        size, first, count = self.records.get((lang, name), self.records.get((3, name)))
        spans = self.spans[first:first + count]; starts = [s[0] for s in spans]
        def read(offset, length):
            if not 0 <= offset <= offset + length <= size: raise ValueError('Logical read out of bounds')
            result = bytearray(); i = bisect.bisect_right(starts, offset) - 1
            while length:
                pos, chunk, start, spanlen, reserved = spans[i]
                take = min(length, spanlen - (offset - pos))
                if take <= 0: raise ValueError('Invalid archive span')
                result += self.chunk(chunk)[start + offset - pos:start + offset - pos + take]
                offset += take; length -= take; i += 1
            return bytes(result)
        return read, size

    def extract(self, lang, name, path):
        read, size = self.logical(lang, name)
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open('xb') as out:
            for pos in range(0, size, 1024 * 1024): out.write(read(pos, min(size - pos, 1024 * 1024)))

    def close(self):
        self.chunk.cache_clear(); self.file.close()
