#!/usr/bin/env python3
"""Optional real-Vulkan X11 F1 smoke test; needs python-xlib and XTest.

Arguments: executable, triangle vertex/fragment SPIR-V, ImGui vertex/fragment SPIR-V.
This is software/display-specific evidence, not target-device acceptance.
"""
import re
import subprocess
import sys
import tempfile
import time
from Xlib import X, XK, display
from Xlib.ext import xtest


def find_window(root):
    for child in root.query_tree().children:
        if (child.get_wm_name() or '') == 'PokoX - Vulkan ImGui':
            return child
    return None


def main():
    if len(sys.argv) != 6:
        print('Usage: test_imgui_toggle_x11.py executable scene.vert scene.frag ui.vert ui.frag', file=sys.stderr)
        return 2
    d = display.Display()
    with tempfile.TemporaryFile(mode='w+t') as log:
        proc = subprocess.Popen([sys.argv[1], '--vertex', sys.argv[2], '--fragment', sys.argv[3],
                                 '--imgui-vertex', sys.argv[4], '--imgui-fragment', sys.argv[5],
                                 '--frames', '1500'], stdout=log, stderr=subprocess.STDOUT)
        try:
            window = None
            for _ in range(200):
                if proc.poll() is not None:
                    raise RuntimeError('demo exited during startup')
                window = find_window(d.screen().root)
                if window:
                    break
                time.sleep(.05)
            if not window:
                raise RuntimeError('window did not appear')
            window.set_input_focus(X.RevertToParent, X.CurrentTime)
            d.sync()
            time.sleep(.7)
            def pixels():
                size = window.get_geometry()
                return window.get_image(0, 0, size.width, size.height, X.ZPixmap, 0xffffffff).data
            def toggle():
                key = d.keysym_to_keycode(XK.string_to_keysym('F1'))
                if not key:
                    raise RuntimeError('F1 unavailable')
                xtest.fake_input(d, X.KeyPress, key); d.sync(); time.sleep(.1)
                xtest.fake_input(d, X.KeyRelease, key); d.sync(); time.sleep(.3)
            before = pixels(); toggle(); hidden = pixels(); toggle(); restored = pixels()
            hide_diff = sum(a != b for a, b in zip(before, hidden))
            show_diff = sum(a != b for a, b in zip(hidden, restored))
            if min(hide_diff, show_diff) < 5000:
                raise RuntimeError(f'F1 did not visibly toggle both ways: {hide_diff}, {show_diff}')
            code = proc.wait(timeout=60)
            log.seek(0); output = log.read()
            match = re.search(r'POKO_IMGUI_RESULT submitted=(\d+) validation_requested=(\w+) '
                              r'graphics_errors=(\d+) graphics_warnings=(\d+).*gpu_available=(\w+)', output)
            if code or not match or match.groups() != ('1500', 'true', '0', '0', 'true'):
                raise RuntimeError(f'demo failed or reported diagnostics (exit {code})')
            print(f'PASS: F1 changed {hide_diff}/{show_diff} image bytes; {match[0]}')
            return 0
        except Exception as error:
            if proc.poll() is None:
                proc.terminate()
                try: proc.wait(timeout=5)
                except subprocess.TimeoutExpired: proc.kill(); proc.wait()
            log.seek(0)
            print(f'FAIL: {error}\n' + '\n'.join(log.read().splitlines()[-25:]), file=sys.stderr)
            return 1
        finally:
            d.close()


if __name__ == '__main__':
    sys.exit(main())
