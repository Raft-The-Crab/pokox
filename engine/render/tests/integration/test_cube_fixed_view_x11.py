#!/usr/bin/env python3
"""Optional isolated-X11 test: golden view ignores orbit/zoom/light input."""
import re
import subprocess
import sys
import tempfile
import time
from Xlib import X, XK, display
from Xlib.ext import xtest
from test_cube_x11_smoke import find_window


def main():
    if len(sys.argv) != 2:
        print('Usage: test_cube_fixed_view_x11.py /path/to/pokox_cube', file=sys.stderr)
        return 2
    connection = display.Display()
    root = connection.screen().root
    with tempfile.TemporaryFile(mode='w+t') as log:
        process = subprocess.Popen([sys.argv[1], '--frames', '300', '--golden-view'],
                                   stdout=log, stderr=subprocess.STDOUT)
        try:
            window = None
            for _ in range(200):
                if process.poll() is not None:
                    raise RuntimeError('cube exited during startup')
                window = find_window(root)
                if window is not None:
                    break
                time.sleep(0.05)
            if window is None:
                raise RuntimeError('cube window did not appear')
            window.set_input_focus(X.RevertToParent, X.CurrentTime)
            connection.sync()
            time.sleep(0.8)
            def image():
                geometry = window.get_geometry()
                return window.get_image(0, 0, geometry.width, geometry.height,
                                        X.ZPixmap, 0xffffffff).data
            before = image()
            key = connection.keysym_to_keycode(XK.string_to_keysym('Right'))
            if not key:
                raise RuntimeError('Right key unavailable')
            xtest.fake_input(connection, X.KeyPress, key)
            origin = root.translate_coords(window, 0, 0)
            xtest.fake_input(connection, X.MotionNotify, x=origin.x + 200, y=origin.y + 200)
            xtest.fake_input(connection, X.ButtonPress, 1)
            connection.sync()
            for x in range(210, 350, 10):
                xtest.fake_input(connection, X.MotionNotify, x=origin.x + x, y=origin.y + 250)
                connection.sync()
                time.sleep(0.025)
            xtest.fake_input(connection, X.ButtonRelease, 1)
            xtest.fake_input(connection, X.ButtonPress, 4)
            xtest.fake_input(connection, X.ButtonRelease, 4)
            time.sleep(0.4)
            xtest.fake_input(connection, X.KeyRelease, key)
            connection.sync()
            time.sleep(0.3)
            after = image()
            if before != after:
                raise RuntimeError('input changed the fixed view')
            code = process.wait(timeout=45)
            log.seek(0)
            output = log.read()
            match = re.search(r'POKO_CUBE_RESULT submitted=(\d+) validation_requested=(\w+) '
                              r'graphics_errors=(\d+) graphics_warnings=(\d+)', output)
            if code or not match or match.groups() != ('300', 'true', '0', '0'):
                raise RuntimeError(f'cube failed or reported diagnostics (exit {code})')
            print(f'PASS: fixed image unchanged after orbit, wheel and light input; {match[0]}')
            return 0
        except Exception as error:
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()
            log.seek(0)
            print(f'FAIL: {error}\n' + '\n'.join(log.read().splitlines()[-25:]), file=sys.stderr)
            return 1
        finally:
            connection.close()


if __name__ == '__main__':
    sys.exit(main())
