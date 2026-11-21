"""Check the real ImGui demo rejects bad SPIR-V before initializing a window."""
import pathlib
import struct
import subprocess
import sys
import tempfile

exe = sys.argv[1]
for arguments in (['--frames', '0'], ['--adapter', 'abc'], ['--adapter', '-1'], ['--unknown']):
    result = subprocess.run([exe, *arguments], text=True, capture_output=True, timeout=10)
    assert result.returncode == 2 and 'Usage:' in result.stderr, (arguments, result.stderr)
with tempfile.TemporaryDirectory(prefix='poko imgui input ') as temp:
    directory = pathlib.Path(temp)
    good_header = directory / 'header.spv'
    good_header.write_bytes(struct.pack('<5I', 0x07230203, 0x10300, 0, 1, 0))
    good_args = ['--imgui-vertex', str(good_header), '--imgui-fragment', str(good_header)]
    for name, content, expected in (
        ('short.spv', b'bad', 'Invalid SPIR-V size'),
        ('odd.spv', b'\0' * 21, 'Invalid SPIR-V size'),
        ('wrong.spv', b'\0' * 20, 'Invalid SPIR-V data'),
        ('large.spv', b'\0' * (16 * 1024 * 1024 + 4), 'Invalid SPIR-V size'),
    ):
        path = directory / name
        path.write_bytes(content)
        result = subprocess.run([exe, '--vertex', str(path), '--fragment', str(good_header), *good_args],
                                text=True, capture_output=True, timeout=10)
        assert result.returncode != 0 and expected in result.stderr, (name, result.stderr)
    result = subprocess.run([exe, '--vertex', str(good_header), '--fragment', str(directory / 'missing.spv'), *good_args],
                            text=True, capture_output=True, timeout=10)
    assert result.returncode != 0 and 'Cannot open shader' in result.stderr
print('PASS: invalid ImGui demo shader inputs rejected before window creation')
