"""Small native file fixtures; no game data or game process is used."""
import os
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]


def mark_sparse_on_windows(stream):
    """Avoid allocating four GiB for the large-offset fixture on Windows."""
    if os.name != 'nt':
        return
    import ctypes
    from ctypes import wintypes
    import msvcrt
    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    ioctl = kernel.DeviceIoControl
    ioctl.argtypes = [wintypes.HANDLE, wintypes.DWORD, ctypes.c_void_p,
                      wintypes.DWORD, ctypes.c_void_p, wintypes.DWORD,
                      ctypes.POINTER(wintypes.DWORD), ctypes.c_void_p]
    ioctl.restype = wintypes.BOOL
    returned = wintypes.DWORD()
    # FSCTL_SET_SPARSE, NULL input means SetSparse=TRUE. Fail before extending
    # the file if its filesystem does not support a genuinely sparse fixture.
    if not ioctl(msvcrt.get_osfhandle(stream.fileno()), 0x000900C4,
                 None, 0, None, 0, ctypes.byref(returned), None):
        raise ctypes.WinError(ctypes.get_last_error())


class PlatformFileTests(unittest.TestCase):
    def compile_and_run(self, name, sources):
        with tempfile.TemporaryDirectory(prefix='a2-file-') as directory:
            work = Path(directory)
            (work / 'данные 日本 space.bin').write_bytes(bytes([0, 10, 13, 26, 255]))
            if os.name != 'nt':
                os.mkfifo(work / 'not-regular.fifo')
            with (work / 'large.bin').open('wb') as stream:
                mark_sparse_on_windows(stream)
                stream.seek(0x100000000 + 123)
                stream.write(bytes([0, 10, 13, 26, 255]))
            exe = work / (name + ('.exe' if os.name == 'nt' else ''))
            command = [os.environ.get('CC', 'clang'), '-std=c11', '-O1', '-g',
                       '-UNDEBUG', '-Wall', '-Wextra', '-Werror',
                       '-I' + str(ROOT / 'port/src')]
            if os.name != 'nt':
                command += ['-fsanitize=undefined']
            subprocess.run(command + [str(ROOT / s) for s in sources] +
                           ['-o', str(exe)], check=True, timeout=60)
            subprocess.run([str(exe)], cwd=work, check=True, timeout=10)

    def test_exact_read_contract(self):
        backend = 'windows' if os.name == 'nt' else 'posix'
        self.compile_and_run('contract', ['port/tests/test_platform_file.c',
                             f'port/src/platform/file_{backend}.c'])

    @unittest.skipIf(os.name == 'nt', 'POSIX syscall fault injection')
    def test_posix_interrupted_short_and_failed_reads(self):
        self.compile_and_run('faults', ['port/tests/test_platform_file_posix_faults.c'])


if __name__ == '__main__':
    unittest.main()
