#!/usr/bin/env python3
"""Synthetic X11 state-console check; requires XTest, Pillow and Vulkan demo."""
import re
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time
from Xlib import X, XK, display
from Xlib.ext import xtest
from PIL import Image, ImageChops


def main():
    if len(sys.argv) != 6:
        print('expected executable and four shader paths', file=sys.stderr)
        return 2
    d = display.Display()
    with tempfile.TemporaryDirectory(prefix='poko state console ') as wd, tempfile.TemporaryFile(mode='w+t') as log:
        p = subprocess.Popen([sys.argv[1], '--vertex', sys.argv[2], '--fragment', sys.argv[3],
                              '--imgui-vertex', sys.argv[4], '--imgui-fragment', sys.argv[5], '--frames', '2400'],
                             cwd=wd, stdout=log, stderr=subprocess.STDOUT)
        try:
            for _ in range(300):
                windows = [w for w in d.screen().root.query_tree().children if w.get_wm_name() == 'PokoX - Vulkan ImGui']
                if windows: break
                if p.poll() is not None: raise RuntimeError('demo exited before window appeared')
                time.sleep(.05)
            else: raise RuntimeError('window did not appear')
            w=windows[0]
            def focus():
                w.set_input_focus(X.RevertToParent,X.CurrentTime)
                w.raise_window();d.sync();time.sleep(.15)
            focus();time.sleep(1)
            def click(x,y):
                focus()
                pos=d.screen().root.translate_coords(w,x,y)
                xtest.fake_input(d,X.MotionNotify,x=pos.x,y=pos.y);d.sync();time.sleep(.1)
                xtest.fake_input(d,X.ButtonPress,1);d.sync();time.sleep(.1)
                xtest.fake_input(d,X.ButtonRelease,1);d.sync();time.sleep(.3)
            def press(name,shift=False):
                focus()
                key=d.keysym_to_keycode(XK.string_to_keysym(name));sk=d.keysym_to_keycode(XK.string_to_keysym('Shift_L'))
                if not key or not sk: raise RuntimeError(f'unavailable key {name}')
                if shift: xtest.fake_input(d,X.KeyPress,sk)
                xtest.fake_input(d,X.KeyPress,key);d.sync();time.sleep(.035)
                xtest.fake_input(d,X.KeyRelease,key)
                if shift: xtest.fake_input(d,X.KeyRelease,sk)
                d.sync();time.sleep(.035)
            special={'@':('2',True),'(':('9',True),')':('0',True),'{':('bracketleft',True),
                     '}':('bracketright',True),':':('semicolon',True),'=':('equal',False),
                     '-':('minus',False),'>':('period',True),'+':('equal',True),
                     ';':('semicolon',False),' ':('space',False)}
            def send(text):
                for char in text:
                    name,shift=special.get(char,(char,False));press(name,shift)
                press('Return');time.sleep(.45)
            def image():
                g=w.get_geometry();raw=w.get_image(0,0,g.width,g.height,X.ZPixmap,0xffffffff)
                return Image.frombytes('RGB',(g.width,g.height),raw.data,'raw','BGRX')
            def same(a,b):
                return ImageChops.difference(a.crop((15,207,90,224)),b.crop((15,207,90,224))).getbbox() is None
            click(80,194);send('1');one=image()
            source='@state var x:i32=0;fn f()->i32{x=x+1;return x;}f()'
            send(source);first=image()
            send('2');two=image()
            send(source);second=image()
            capture=os.environ.get('POKO_STATE_CAPTURE_DIR')
            if capture:
                Path(capture).mkdir(parents=True,exist_ok=True)
                for label,im in [('one',one),('first',first),('two',two),('second',second)]: im.save(Path(capture)/(label+'.png'))
            if not same(one,first) or not same(two,second): raise RuntimeError('persistent state outputs did not match 1 and 2')
            click(155,172);click(80,194);send(source);reset=image()
            if not same(one,reset): raise RuntimeError('reset state did not restore first tick')
            code=p.wait(timeout=65);log.seek(0);output=log.read()
            match=re.search(r'POKO_IMGUI_RESULT submitted=(\d+) validation_requested=(\w+) graphics_errors=(\d+) graphics_warnings=(\d+)',output)
            if code or not match or match.groups()!=('2400','true','0','0'):
                raise RuntimeError(f'demo failed or diagnostics nonzero: exit={code}')
            print('PASS: persistent state produced 1, then 2, then 1 after reset;',match[0]);return 0
        except Exception as error:
            if p.poll() is None:
                p.terminate()
                try: p.wait(timeout=5)
                except subprocess.TimeoutExpired: p.kill();p.wait()
            log.seek(0);lines=log.read().splitlines()
            diagnostics=[line for line in lines if '[Poko graphics warning]' in line or '[Poko graphics error]' in line]
            print(f'FAIL: {error}\n'+'\n'.join(diagnostics+lines[-30:]),file=sys.stderr);return 1
        finally: d.close()

if __name__=='__main__': sys.exit(main())
