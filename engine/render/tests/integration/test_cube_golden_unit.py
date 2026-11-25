#!/usr/bin/env python3
"""Dependency-free canonical PNG and checked-in scene-reference tests."""
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path
import unittest
import zlib
from cube_golden import canonical_png


def decode(png):
    if png[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('bad signature')
    offset, header, image = 8, None, bytearray()
    while offset < len(png):
        length = struct.unpack_from('>I', png, offset)[0]
        tag = png[offset + 4:offset + 8]
        payload = png[offset + 8:offset + 8 + length]
        crc = struct.unpack_from('>I', png, offset + 8 + length)[0]
        if zlib.crc32(tag + payload) & 0xffffffff != crc:
            raise ValueError('bad CRC')
        offset += length + 12
        if tag == b'IHDR':
            header = struct.unpack('>IIBBBBB', payload)
        elif tag == b'IDAT':
            image.extend(payload)
        elif tag == b'IEND':
            if offset != len(png):
                raise ValueError('trailing bytes')
            break
    if not header or header[2:] != (8, 2, 0, 0, 0):
        raise ValueError('unexpected header')
    width, height = header[:2]
    raw = zlib.decompress(image)
    stride = width * 3
    if len(raw) != height * (stride + 1):
        raise ValueError('invalid size')
    rows = []
    for y in range(height):
        row = raw[y * (stride + 1):(y + 1) * (stride + 1)]
        if row[0] != 0:
            raise ValueError('unexpected filter')
        rows.append(row[1:])
    return width, height, b''.join(rows)


class GoldenEncoderTests(unittest.TestCase):
    def test_roundtrip_and_multiple_deflate_blocks(self):
        rgb = bytes((i * 19) % 256 for i in range(400 * 100 * 3))
        encoded = canonical_png(400, 100, rgb)
        self.assertEqual((400, 100, rgb), decode(encoded))
        self.assertEqual(encoded, canonical_png(400, 100, rgb))

    def test_bad_inputs(self):
        for width, height, rgb in ((0, 1, b''), (1, 0, b''), (1, 1, b'\x00')):
            with self.assertRaises(ValueError):
                canonical_png(width, height, rgb)

    def test_actual_cannot_replace_reference_or_be_a_symlink(self):
        script = Path(__file__).with_name('cube_golden.py')
        with tempfile.TemporaryDirectory() as directory:
            reference = Path(directory) / 'reference.png'
            reference.write_bytes(b'unchanged')
            paths = [reference]
            skipped_links = []
            link = Path(directory) / 'actual.png'
            try:
                link.symlink_to(reference)
                paths.append(link)
            except OSError:  # Windows may not grant symlink creation privilege.
                skipped_links.append('symlink')
            hardlink = Path(directory) / 'hardlink.png'
            try:
                os.link(reference, hardlink)
                paths.append(hardlink)
            except (OSError, NotImplementedError):
                skipped_links.append('hardlink')
            for actual in paths:
                result = subprocess.run([sys.executable, str(script), '--exe', 'missing',
                                         '--golden', str(reference), '--actual', str(actual)],
                                        capture_output=True, text=True, timeout=5)
                self.assertEqual(result.returncode, 2)
                self.assertIn('actual must not', result.stderr)
                self.assertEqual(reference.read_bytes(), b'unchanged')
            if skipped_links:
                print('SKIP: cube-golden link guards: ' + ', '.join(skipped_links), flush=True)

    def test_capture_cannot_replace_shipped_reference(self):
        script = Path(__file__).with_name('cube_golden.py')
        reference = Path(__file__).resolve().parents[1] / 'fixtures/golden/lit_cube_llvmpipe.png'
        before = reference.read_bytes()
        result = subprocess.run([sys.executable, str(script), '--exe', 'missing', '--capture', str(reference)],
                                capture_output=True, text=True, timeout=5)
        self.assertEqual(result.returncode, 2)
        self.assertIn('capture must not', result.stderr)
        self.assertEqual(reference.read_bytes(), before)

    def test_reference_is_full_cube_with_three_lit_faces(self):
        reference = Path(__file__).resolve().parents[1] / 'fixtures/golden/lit_cube_llvmpipe.png'
        encoded = reference.read_bytes()
        width, height, rgb = decode(encoded)
        self.assertEqual((width, height), (320, 240))
        self.assertEqual(encoded, canonical_png(width, height, rgb))
        def pixel(x, y):
            offset = (y * width + x) * 3
            return tuple(rgb[offset:offset + 3])
        background = pixel(0, 0)
        left, right, top = pixel(120, 100), pixel(190, 110), pixel(150, 70)
        self.assertEqual(background, (53, 97, 144))
        self.assertEqual((left, right, top), ((217, 217, 217), (195, 195, 195), (228, 228, 228)))
        self.assertEqual(len({background, left, right, top}), 4)


if __name__ == '__main__':
    unittest.main()
