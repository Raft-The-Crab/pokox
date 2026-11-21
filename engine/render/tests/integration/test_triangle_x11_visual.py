#!/usr/bin/env python3
"""Opt-in Linux/X11 visual smoke test; run on an isolated display, not a desktop.

Requires libX11, ImageMagick's import and Pillow. Not a GPU validation test.
"""
import argparse
import ctypes
from pathlib import Path
import subprocess
import tempfile
import time
from PIL import Image

parser = argparse.ArgumentParser()
parser.add_argument('--exe', required=True)
parser.add_argument('--vertex', required=True)
parser.add_argument('--fragment', required=True)
parser.add_argument('--screenshot', required=True)
parser.add_argument('--frames', type=int, default=1800)
parser.add_argument('--mode', choices=('triangle', 'depth', 'depth-control'), default='triangle')
args = parser.parse_args()
if args.frames < 100:
    parser.error('--frames must be at least 100 to allow time for captures')
x = ctypes.CDLL('libX11.so.6')
x.XOpenDisplay.argtypes = [ctypes.c_char_p]; x.XOpenDisplay.restype = ctypes.c_void_p
x.XDefaultRootWindow.argtypes = [ctypes.c_void_p]; x.XDefaultRootWindow.restype = ctypes.c_ulong
x.XQueryTree.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.POINTER(ctypes.c_ulong)), ctypes.POINTER(ctypes.c_uint)]
x.XQueryTree.restype = ctypes.c_int
x.XFetchName.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_void_p)]; x.XFetchName.restype = ctypes.c_int
x.XFree.argtypes = [ctypes.c_void_p]
x.XResizeWindow.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.c_uint, ctypes.c_uint]
x.XSync.argtypes = [ctypes.c_void_p, ctypes.c_int]
x.XGetGeometry.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.POINTER(ctypes.c_ulong), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint)]
x.XCloseDisplay.argtypes = [ctypes.c_void_p]
display = x.XOpenDisplay(None)
if not display:
    raise RuntimeError('X11 display unavailable')

def find_window():
    root = x.XDefaultRootWindow(display); rr = ctypes.c_ulong(); parent = ctypes.c_ulong()
    children = ctypes.POINTER(ctypes.c_ulong)(); count = ctypes.c_uint()
    if not x.XQueryTree(display, root, ctypes.byref(rr), ctypes.byref(parent), ctypes.byref(children), ctypes.byref(count)):
        return None
    found = None
    try:
        for i in range(count.value):
            name = ctypes.c_void_p()
            if x.XFetchName(display, children[i], ctypes.byref(name)) and name.value:
                text = ctypes.string_at(name).decode(errors='replace'); x.XFree(name)
                if text == ('PokoX - Vulkan triangle' if args.mode == 'triangle' else 'PokoX - Vulkan depth'):
                    found = children[i]; break
    finally:
        if children: x.XFree(children)
    return found

with tempfile.TemporaryFile(mode='w+', encoding='utf-8') as log:
    command = [args.exe, '--vertex', args.vertex, '--fragment', args.fragment,
               '--frames', str(args.frames), '--no-validation']
    if args.mode == 'depth-control': command.append('--show-no-depth')
    proc = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
    try:
        window = None
        for _ in range(200):
            window = find_window()
            if window or proc.poll() is not None: break
            time.sleep(0.05)
        if not window: raise RuntimeError('triangle window not found')
        for width, height in ((640, 480), (900, 650), (720, 540)):
            x.XResizeWindow(display, window, width, height); x.XSync(display, 0); time.sleep(0.5)
            rr = ctypes.c_ulong(); xx = ctypes.c_int(); yy = ctypes.c_int()
            ww = ctypes.c_uint(); hh = ctypes.c_uint(); border = ctypes.c_uint(); depth = ctypes.c_uint()
            if not x.XGetGeometry(display, window, ctypes.byref(rr), ctypes.byref(xx), ctypes.byref(yy), ctypes.byref(ww), ctypes.byref(hh), ctypes.byref(border), ctypes.byref(depth)):
                raise RuntimeError('window disappeared')
            if (ww.value, hh.value) != (width, height) or proc.poll() is not None:
                raise RuntimeError('resize failed or renderer stopped')
            print('window size:', width, height, flush=True)
        subprocess.run(['import', '-window', str(window), args.screenshot], check=True, timeout=15)
        image = Image.open(args.screenshot).convert('RGB')
        if image.size != (720, 540): raise AssertionError(f'unexpected screenshot size {image.size}')
        def pixel(rx, ry): return image.getpixel((int(image.width * rx), int(image.height * ry)))
        background = pixel(.05, .05)
        if args.mode == 'triangle':
            blue, green, red = pixel(.30, .72), pixel(.70, .72), pixel(.50, .30)
            valid = (blue[2] > max(blue[0], blue[1]) + 50 and
                     green[1] > max(green[0], green[2]) + 50 and red[0] > max(red[1], red[2]) + 50)
            samples = (background, blue, green, red)
        else:
            near, far, overlap = pixel(.25, .28), pixel(.75, .28), pixel(.50, .35)
            def red(pixel_value): return pixel_value[0] > max(pixel_value[1], pixel_value[2]) + 100
            def green(pixel_value): return pixel_value[1] > max(pixel_value[0], pixel_value[2]) + 100
            valid = red(near) and green(far) and (green(overlap) if args.mode == 'depth-control' else red(overlap))
            samples = (background, near, far, overlap)
        if not (background[2] > background[0] + 30 and valid):
            raise AssertionError(f'pixel checks failed: {args.mode=} {samples=}')
        print('pixel samples:', samples, flush=True)
        proc.wait(timeout=90)
        log.seek(0); output = log.read()
        if proc.returncode != 0 or f'submitted={args.frames}' not in output or 'graphics_errors=0' not in output:
            raise RuntimeError('triangle run failed:\n' + output)
        print(output[-1500:])
        print('PASS:', args.mode, 'pixel samples and three X11 resizes; Vulkan validation disabled')
    finally:
        if proc.poll() is None:
            proc.kill(); proc.wait()
        x.XCloseDisplay(display)
