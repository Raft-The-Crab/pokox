#!/usr/bin/env python3
"""Optional SDL3/ImGui/Vulkan interaction test under X11, using XTest.

Arguments: demo executable, scene vertex/fragment SPIR-V, UI vertex/fragment SPIR-V.
Requires python-xlib, Pillow and an X11 display. This is software-display evidence,
not proof of behavior on a physical GPU, IME, Windows or Android.
"""
from pathlib import Path
import os
import re
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
    d=display.Display()
    with tempfile.TemporaryDirectory(prefix='poko console ui ') as wd, tempfile.TemporaryFile(mode='w+t') as log:
        p=subprocess.Popen([sys.argv[1], '--vertex', sys.argv[2], '--fragment', sys.argv[3],
                            '--imgui-vertex', sys.argv[4], '--imgui-fragment', sys.argv[5], '--frames', '2700'],
                           cwd=wd, stdout=log, stderr=subprocess.STDOUT)
        try:
            for _ in range(300):
                windows=[w for w in d.screen().root.query_tree().children if w.get_wm_name() == 'PokoX - Vulkan ImGui']
                if windows: break
                if p.poll() is not None: raise RuntimeError('demo exited before window appeared')
                time.sleep(.05)
            else: raise RuntimeError('window did not appear')
            w=windows[0]; w.set_input_focus(X.RevertToParent,X.CurrentTime); d.sync(); time.sleep(1)
            def image():
                g=w.get_geometry(); raw=w.get_image(0,0,g.width,g.height,X.ZPixmap,0xffffffff)
                return Image.frombytes('RGB',(g.width,g.height),raw.data,'raw','BGRX')
            def press(name, shift=False):
                key=d.keysym_to_keycode(XK.string_to_keysym(name))
                shiftkey=d.keysym_to_keycode(XK.string_to_keysym('Shift_L'))
                if not key or not shiftkey: raise RuntimeError(f'unavailable key {name}')
                if shift: xtest.fake_input(d,X.KeyPress,shiftkey)
                xtest.fake_input(d,X.KeyPress,key); d.sync(); time.sleep(.05)
                xtest.fake_input(d,X.KeyRelease,key)
                if shift: xtest.fake_input(d,X.KeyRelease,shiftkey)
                d.sync(); time.sleep(.05)
            # First-use layout at 800x600: expression field below stats.
            pos=d.screen().root.translate_coords(w,80,194)
            xtest.fake_input(d,X.MotionNotify,x=pos.x,y=pos.y); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonPress,1); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonRelease,1); d.sync(); time.sleep(.4)
            before=image()
            for name,shift in [('1',False),('equal',True),('2',False),('8',True),('3',False),('Return',False)]: press(name,shift)
            time.sleep(.6); answer=image()
            for name in ('1','slash','0','Return'): press(name)
            time.sleep(.6); error=image()
            # Send a string and then a numeric print hostcall through real SDL text events.
            for name,shift in [('p',False),('r',False),('i',False),('n',False),('t',False),
                               ('9',True),('apostrophe',True),('h',False),('e',False),('l',False),
                               ('l',False),('o',False),('apostrophe',True),('0',True),('Return',False)]:
                press(name,shift)
            time.sleep(.6); printed=image()
            for name,shift in [('p',False),('r',False),('i',False),('n',False),('t',False),('9',True),
                               ('2',False),('equal',True),('3',False),('0',True),('Return',False)]:
                press(name,shift)
            time.sleep(.6); printed_again=image()
            clear_pos=d.screen().root.translate_coords(w,110,236)
            xtest.fake_input(d,X.MotionNotify,x=clear_pos.x,y=clear_pos.y); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonPress,1); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonRelease,1); d.sync(); time.sleep(.4); cleared=image()
            # Compare the recursive program's exact result region with a known 120.
            pos=d.screen().root.translate_coords(w,80,194)
            xtest.fake_input(d,X.MotionNotify,x=pos.x,y=pos.y); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonPress,1); d.sync(); time.sleep(.1)
            xtest.fake_input(d,X.ButtonRelease,1); d.sync(); time.sleep(.2)
            for name in ('1','2','0','Return'): press(name)
            time.sleep(.4); reference=image()
            special={'(':('9',True),')':('0',True),'{':('bracketleft',True),
                     '}':('bracketright',True),':':('semicolon',True),
                     '=':('equal',False),'-':('minus',False),'>':('period',True),
                     '*':('8',True),'+':('equal',True),'<':('comma',True),';':('semicolon',False),' ':('space',False)}
            source='fn f(n:i32)->i32{if n==0{return 1;}return n*f(n-1);}f(5)'
            for char in source:
                name,shift=special.get(char,(char,False)); press(name,shift)
            press('Return'); time.sleep(.5); recursive=image()
            for name in ('5','5','Return'): press(name)
            time.sleep(.4); loop_reference=image()
            source='fn f()->i32{var i=0;var s=0;while i<10{i=i+1;s=s+i;}return s;}f()'
            for char in source:
                name,shift=special.get(char,(char,False)); press(name,shift)
            press('Return'); time.sleep(.5); loop_result=image()
            source='fn f()->i32{while true{}return 0;}f()'
            for char in source:
                name,shift=special.get(char,(char,False)); press(name,shift)
            press('Return'); time.sleep(.5); loop_trap=image()
            region=(15,206,320,227)
            def delta(a,b):
                diff=ImageChops.difference(a.crop(region),b.crop(region))
                return sum(1 for px in getattr(diff,'get_flattened_data',diff.getdata)() if px != (0,0,0))
            loop_diff=delta(loop_reference,loop_result)
            trap_diff=delta(loop_result,loop_trap)
            if loop_diff!=0 or trap_diff<50: raise RuntimeError(f"loop output or trap mismatch ({loop_diff}, {trap_diff} pixels)")
            recursion_diff=delta(reference,recursive)
            if recursion_diff!=0: raise RuntimeError(f"recursive output did not match i32: 120 reference ({recursion_diff} pixels differ)")
            a,b=delta(before,answer),delta(answer,error)
            region=(15,240,320,345)
            c,diff_second,clear_diff=delta(error,printed),delta(printed,printed_again),delta(printed_again,cleared)
            capture=os.environ.get('POKO_REPL_CAPTURE_DIR')
            if capture:
                Path(capture).mkdir(parents=True,exist_ok=True)
                before.save(Path(capture)/'console-before.png'); answer.save(Path(capture)/'console-answer.png'); error.save(Path(capture)/'console-error.png'); printed.save(Path(capture)/'console-print.png'); printed_again.save(Path(capture)/'console-print-twice.png'); cleared.save(Path(capture)/'console-cleared.png'); recursive.save(Path(capture)/'console-recursion.png'); loop_result.save(Path(capture)/'console-loop.png'); loop_trap.save(Path(capture)/'console-loop-trap.png')
            if min(a,b,c)<50 or diff_second<10 or clear_diff<50: raise RuntimeError(f'console/log area did not change: {a}, {b}, {c}, {diff_second}, {clear_diff}')
            code=p.wait(timeout=65); log.seek(0); output=log.read()
            match=re.search(r'POKO_IMGUI_RESULT submitted=(\d+) validation_requested=(\w+) graphics_errors=(\d+) graphics_warnings=(\d+)',output)
            if code or not match or match.groups()!=('2700','true','0','0'):
                raise RuntimeError(f'demo failed or diagnostics nonzero, exit {code}')
            print(f'PASS: synthetic typing changed output/log ({a}, {b}, {c}, {diff_second}, {clear_diff} pixels) recursion matched i32: 120, loop matched i32: 55 and trap changed output; {match[0]}')
            return 0
        except Exception as error:
            if p.poll() is None:
                p.terminate()
                try: p.wait(timeout=5)
                except subprocess.TimeoutExpired: p.kill(); p.wait()
            log.seek(0); lines=log.read().splitlines()
            diagnostics=[line for line in lines if '[Poko graphics warning]' in line or '[Poko graphics error]' in line]
            print(f'FAIL: {error}\n'+'\n'.join(diagnostics+lines[-30:]),file=sys.stderr)
            return 1
        finally: d.close()

if __name__ == '__main__':
    sys.exit(main())
