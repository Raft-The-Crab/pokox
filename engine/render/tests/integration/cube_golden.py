#!/usr/bin/env python3
"""Capture a fixed lit Vulkan cube on isolated X11 and compare exact PNG bytes.

No third-party Python packages are needed. Run only on the documented pinned
software-renderer configuration; this is not a portable hardware image test.
"""
import argparse
import ctypes
import ctypes.util
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile
import time
import zlib

WIDTH, HEIGHT, FRAMES = 320, 240, 300
TITLE = b'PokoX - Vulkan mesh cube'
# {"window": {"width": 320, "height": 240}} in CBOR.
CONFIG = b'\xa1\x66window\xa2\x65width\x19\x01\x40\x66height\x18\xf0'


def png_chunk(tag, payload):
    return struct.pack('>I', len(payload)) + tag + payload + struct.pack('>I', zlib.crc32(tag + payload) & 0xffffffff)


def canonical_png(width, height, rgb):
    """RGB8 PNG with filter 0 and explicit uncompressed DEFLATE blocks."""
    if width <= 0 or height <= 0 or len(rgb) != width * height * 3:
        raise ValueError('invalid image size')
    stride = width * 3
    scan = b''.join(b'\0' + rgb[y * stride:(y + 1) * stride] for y in range(height))
    stream = bytearray(b'\x78\x01')
    for start in range(0, len(scan), 65535):
        part = scan[start:start + 65535]
        final = start + len(part) == len(scan)
        stream.append(1 if final else 0)
        stream.extend(struct.pack('<HH', len(part), len(part) ^ 0xffff))
        stream.extend(part)
    stream.extend(struct.pack('>I', zlib.adler32(scan) & 0xffffffff))
    ihdr = struct.pack('>IIBBBBB', width, height, 8, 2, 0, 0, 0)
    return b'\x89PNG\r\n\x1a\n' + png_chunk(b'IHDR', ihdr) + png_chunk(b'IDAT', stream) + png_chunk(b'IEND', b'')


class XImage(ctypes.Structure):
    _fields_ = [('width', ctypes.c_int), ('height', ctypes.c_int), ('xoffset', ctypes.c_int),
                ('format', ctypes.c_int), ('data', ctypes.c_void_p), ('byte_order', ctypes.c_int),
                ('bitmap_unit', ctypes.c_int), ('bitmap_bit_order', ctypes.c_int),
                ('bitmap_pad', ctypes.c_int), ('depth', ctypes.c_int), ('bytes_per_line', ctypes.c_int),
                ('bits_per_pixel', ctypes.c_int), ('red_mask', ctypes.c_ulong),
                ('green_mask', ctypes.c_ulong), ('blue_mask', ctypes.c_ulong)]


class X11:
    def __init__(self):
        lib = ctypes.util.find_library('X11')
        if not lib:
            raise RuntimeError('libX11 not found')
        self.x = ctypes.CDLL(lib)
        signatures = {
            'XOpenDisplay': ([ctypes.c_char_p], ctypes.c_void_p),
            'XDefaultRootWindow': ([ctypes.c_void_p], ctypes.c_ulong),
            'XQueryTree': ([ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.POINTER(ctypes.c_ulong)), ctypes.POINTER(ctypes.c_uint)], ctypes.c_int),
            'XFetchName': ([ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_void_p)], ctypes.c_int),
            'XGetGeometry': ([ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint)], ctypes.c_int),
            'XGetImage': ([ctypes.c_void_p, ctypes.c_ulong, ctypes.c_int, ctypes.c_int, ctypes.c_uint, ctypes.c_uint, ctypes.c_ulong, ctypes.c_int], ctypes.POINTER(XImage)),
            'XGetPixel': ([ctypes.POINTER(XImage), ctypes.c_int, ctypes.c_int], ctypes.c_ulong),
            'XDestroyImage': ([ctypes.POINTER(XImage)], ctypes.c_int),
            'XFree': ([ctypes.c_void_p], ctypes.c_int),
            'XCloseDisplay': ([ctypes.c_void_p], ctypes.c_int),
        }
        for name, (arguments, result) in signatures.items():
            func = getattr(self.x, name)
            func.argtypes, func.restype = arguments, result
        self.display = self.x.XOpenDisplay(None)
        if not self.display:
            raise RuntimeError('X11 display unavailable')
        self.root = self.x.XDefaultRootWindow(self.display)

    def close(self):
        self.x.XCloseDisplay(self.display)

    def find_window(self):
        root, parent, count = ctypes.c_ulong(), ctypes.c_ulong(), ctypes.c_uint()
        children = ctypes.POINTER(ctypes.c_ulong)()
        if not self.x.XQueryTree(self.display, self.root, ctypes.byref(root), ctypes.byref(parent), ctypes.byref(children), ctypes.byref(count)):
            raise RuntimeError('XQueryTree failed')
        found = []
        try:
            for index in range(count.value):
                name = ctypes.c_void_p()
                if self.x.XFetchName(self.display, children[index], ctypes.byref(name)) and name.value:
                    try:
                        if ctypes.string_at(name) == TITLE:
                            found.append(children[index])
                    finally:
                        self.x.XFree(name)
        finally:
            if children:
                self.x.XFree(children)
        if len(found) > 1:
            raise RuntimeError('multiple cube windows: use an isolated X display')
        return found[0] if found else None

    def capture(self, window):
        root, x, y = ctypes.c_ulong(), ctypes.c_int(), ctypes.c_int()
        width, height, border, depth = ctypes.c_uint(), ctypes.c_uint(), ctypes.c_uint(), ctypes.c_uint()
        if not self.x.XGetGeometry(self.display, window, ctypes.byref(root), ctypes.byref(x), ctypes.byref(y), ctypes.byref(width), ctypes.byref(height), ctypes.byref(border), ctypes.byref(depth)):
            raise RuntimeError('XGetGeometry failed')
        if (width.value, height.value, depth.value) != (WIDTH, HEIGHT, 24):
            raise RuntimeError(f'unexpected window geometry {width.value}x{height.value} depth={depth.value}')
        image = self.x.XGetImage(self.display, window, 0, 0, WIDTH, HEIGHT, ctypes.c_ulong(-1).value, 2)  # ZPixmap
        if not image:
            raise RuntimeError('XGetImage failed')
        try:
            masks = (image.contents.red_mask, image.contents.green_mask, image.contents.blue_mask)
            if masks != (0xff0000, 0x00ff00, 0x0000ff):
                raise RuntimeError(f'unsupported X11 RGB masks: {masks!r}')
            pixel = self.x.XGetPixel
            data = bytearray(WIDTH * HEIGHT * 3)
            for row in range(HEIGHT):
                for col in range(WIDTH):
                    p = pixel(image, col, row)
                    offset = (row * WIDTH + col) * 3
                    data[offset:offset + 3] = bytes(((p >> 16) & 255, (p >> 8) & 255, p & 255))
            return bytes(data)
        finally:
            self.x.XDestroyImage(image)


def run(exe, golden, capture, fragment, actual_output):
    x11 = X11()
    try:
        if x11.find_window() is not None:
            raise RuntimeError('pre-existing cube window: use an isolated X display')
        with tempfile.TemporaryDirectory(prefix='poko-cube-golden-') as temp:
            folder = Path(temp)
            config = folder / 'window.cbor'
            config.write_bytes(CONFIG)
            with (folder / 'cube.log').open('w+t', encoding='utf-8') as log:
                command = [str(exe), '--frames', str(FRAMES), '--config', str(config),
                           '--light', '0.4', '0.7', '0.6', '--golden-view']
                if fragment is not None:
                    command.extend(['--fragment', str(fragment.resolve())])
                process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
                try:
                    window = None
                    deadline = time.monotonic() + 30
                    while time.monotonic() < deadline and process.poll() is None:
                        window = x11.find_window()
                        if window:
                            break
                        time.sleep(0.05)
                    if not window:
                        raise RuntimeError('cube window not found')
                    previous = None
                    image = None
                    while time.monotonic() < deadline and process.poll() is None:
                        current = x11.capture(window)
                        # Wait for a nonblank, stable presented image; the camera and light are fixed.
                        colors = {current[i:i + 3] for i in range(0, len(current), 3)}
                        if len(colors) >= 3 and current == previous:
                            image = current
                            break
                        previous = current
                        time.sleep(0.15)
                    if image is None:
                        raise RuntimeError('no stable, nonblank frame was presented')
                    code = process.wait(timeout=45)
                    log.seek(0)
                    output = log.read()
                    match = re.search(r'POKO_CUBE_RESULT submitted=(\d+) validation_requested=(\w+) graphics_errors=(\d+) graphics_warnings=(\d+)', output)
                    if code or not match or match.groups() != (str(FRAMES), 'true', '0', '0'):
                        raise RuntimeError(f'cube failed or reported graphics diagnostics (exit {code})')
                    if not re.search(r"Using physical device 'llvmpipe \(LLVM 23\.1\.6, 128 bits\)', API version [^,]+, Driver version 26\.3\.1\.", output):
                        raise RuntimeError('expected pinned llvmpipe software adapter not confirmed')
                    encoded = canonical_png(WIDTH, HEIGHT, image)
                    actual = actual_output if actual_output else folder / 'actual.png'
                    actual.write_bytes(encoded)
                    if capture:
                        if capture.is_symlink():
                            raise RuntimeError('refusing to write a symlink output')
                        capture.write_bytes(encoded)
                        print(f'Captured {WIDTH}x{HEIGHT} screenshot to {capture}; reference not changed')
                    else:
                        harness = Path(__file__).resolve().parents[4] / 'tools/testutils/harness/golden.py'
                        result = subprocess.run([sys.executable, str(harness), '--golden', str(golden), '--actual', str(actual)], check=False)
                        if result.returncode:
                            return result.returncode
                    print(f'PASS: software Vulkan, {FRAMES} frames, 0 graphics errors/warnings')
                    return 0
                except Exception:
                    if process.poll() is None:
                        process.terminate()
                        try:
                            process.wait(timeout=5)
                        except subprocess.TimeoutExpired:
                            process.kill()
                            process.wait()
                    log.seek(0)
                    print('\n'.join(log.read().splitlines()[-30:]), file=sys.stderr)
                    raise
    finally:
        x11.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, required=True)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--golden', type=Path, help='compare reference without modifying it')
    mode.add_argument('--capture', type=Path, help='write a candidate for manual review (not a golden update)')
    parser.add_argument('--fragment', type=Path, help='override fragment SPIR-V for regression testing')
    parser.add_argument('--actual', type=Path, help='save actual PNG for inspecting a mismatch')
    args = parser.parse_args()
    try:
        if args.actual and args.capture:
            raise ValueError('--actual is only used with --golden')
        if args.actual and (args.actual.is_symlink() or args.actual.resolve() == args.golden.resolve() or
                            (args.actual.exists() and args.golden.exists() and os.path.samefile(args.actual, args.golden))):
            raise ValueError('actual must not be a symlink or the golden reference')
        reference = Path(__file__).resolve().parents[1] / 'fixtures/golden/lit_cube_llvmpipe.png'
        if args.capture and (args.capture.is_symlink() or args.capture.resolve() == reference.resolve() or
                             (args.capture.exists() and reference.exists() and os.path.samefile(args.capture, reference))):
            raise ValueError('capture must not be a symlink or the golden reference')
        return run(args.exe.resolve(), args.golden, args.capture, args.fragment, args.actual)
    except (OSError, RuntimeError, ValueError) as error:
        print(f'FAIL: {error}', file=sys.stderr)
        return 2


if __name__ == '__main__':
    sys.exit(main())
