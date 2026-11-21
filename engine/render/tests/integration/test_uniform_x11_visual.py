#!/usr/bin/env python3
"""Optional isolated X11 visual test for per-frame uniform updates and depth.

Requires libX11, ImageMagick import, Pillow, and a working Vulkan ICD. It passes
--no-validation and is not a hardware or validation-layer acceptance test.
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
parser.add_argument('--screenshot-red', required=True)
parser.add_argument('--screenshot-blue', required=True)
parser.add_argument('--frames', type=int, default=2400)
args = parser.parse_args()
if args.frames < 1000:
    parser.error('--frames must be at least 1000 to allow time for captures')
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
                if text == 'PokoX - Vulkan uniform':
                    found = children[i]; break
    finally:
        if children: x.XFree(children)
    return found

with tempfile.TemporaryDirectory(prefix='poko-uniform-visual-') as temp, tempfile.TemporaryFile(mode='w+', encoding='utf-8') as log:
    proc = subprocess.Popen([args.exe, '--vertex', args.vertex, '--fragment', args.fragment,
                             '--frames', str(args.frames), '--no-validation'], stdout=log, stderr=subprocess.STDOUT)
    try:
        window = None
        for _ in range(200):
            window = find_window()
            if window or proc.poll() is not None: break
            time.sleep(0.05)
        if not window: raise RuntimeError('uniform demo window not found')
        for width, height in ((640,480), (900,650), (720,540)):
            x.XResizeWindow(display, window, width, height); x.XSync(display, 0); time.sleep(0.4)
            rr=ctypes.c_ulong(); xx=ctypes.c_int(); yy=ctypes.c_int(); ww=ctypes.c_uint(); hh=ctypes.c_uint(); border=ctypes.c_uint(); dep=ctypes.c_uint()
            if not x.XGetGeometry(display, window, ctypes.byref(rr), ctypes.byref(xx), ctypes.byref(yy), ctypes.byref(ww), ctypes.byref(hh), ctypes.byref(border), ctypes.byref(dep)) or (ww.value, hh.value)!=(width,height) or proc.poll() is not None:
                raise RuntimeError('resize failed or renderer stopped')
            print('window size:', width, height, flush=True)
        captures=[]
        for index in range(8):
            path=Path(temp)/f'{index}.png'
            subprocess.run(['import','-window',str(window),str(path)], check=True, timeout=15)
            with Image.open(path) as opened:
                image=opened.convert('RGB')
            if image.size != (720,540): raise AssertionError(f'unexpected image size: {image.size}')
            def pixel(rx, ry): return image.getpixel((int(image.width*rx),int(image.height*ry)))
            near, far, overlap, background = pixel(.25,.28),pixel(.75,.28),pixel(.50,.35),pixel(.05,.05)
            if far[1] < max(far[0],far[2])+100 or background[2] < background[0]+30 or max(abs(a-b) for a,b in zip(near,overlap))>4:
                raise AssertionError(f'depth or background check failed: {near=} {far=} {overlap=} {background=}')
            captures.append((near, path.read_bytes())); time.sleep(0.45)
        red=max(captures,key=lambda p:p[0][0]); blue=max(captures,key=lambda p:p[0][2])
        if red[0][0]-blue[0][0]<80 or blue[0][2]-red[0][2]<80:
            raise AssertionError(f'color did not change sufficiently: {[v[0] for v in captures]}')
        Path(args.screenshot_red).write_bytes(red[1]); Path(args.screenshot_blue).write_bytes(blue[1])
        print('sampled near colors:', [v[0] for v in captures], flush=True)
        proc.wait(timeout=90); log.seek(0); output=log.read()
        if proc.returncode != 0 or f'submitted={args.frames}' not in output or 'graphics_errors=0' not in output or 'graphics_warnings=0' not in output:
            raise RuntimeError('uniform demo failed:\n'+output)
        print(output[-1500:]); print('PASS: per-frame color changes, depth overlap and resizes; validation disabled')
    finally:
        if proc.poll() is None: proc.kill(); proc.wait()
        x.XCloseDisplay(display)
