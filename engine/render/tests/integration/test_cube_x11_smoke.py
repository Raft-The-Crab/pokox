#!/usr/bin/env python3
"""Optional Linux/X11 software-rendering smoke test; requires python-xlib.

Start Xvfb separately and set DISPLAY, SDL_VIDEODRIVER=x11 and the Vulkan
loader/ICD library paths. Pass the real pokox_cube executable as argument.
This tests synthetic input and nonuniform output, not visual correctness.
"""
import re
import subprocess
import sys
import tempfile
import time
from Xlib import X, display
from Xlib.ext import xtest


def find_window(parent):
    for window in parent.query_tree().children:
        try:
            name = window.get_wm_name()
            if name and "PokoX - Vulkan mesh cube" in name:
                return window
            found = find_window(window)
            if found is not None:
                return found
        except Exception:  # The window may disappear between X11 queries.
            continue
    return None


def main():
    if len(sys.argv) != 2:
        print("Usage: test_cube_x11_smoke.py /path/to/pokox_cube", file=sys.stderr)
        return 2
    connection = display.Display()
    root = connection.screen().root
    with tempfile.TemporaryFile(mode="w+t") as log:
        process = subprocess.Popen([sys.argv[1], "--frames", "300"],
                                   stdout=log, stderr=subprocess.STDOUT)
        try:
            window = None
            for _ in range(200):
                if process.poll() is not None:
                    raise RuntimeError("cube exited during startup")
                window = find_window(root)
                if window is not None:
                    break
                time.sleep(0.05)
            if window is None:
                raise RuntimeError("cube window did not appear")
            time.sleep(2)

            def image():
                geometry = window.get_geometry()
                connection.sync()
                pixels = window.get_image(0, 0, geometry.width, geometry.height,
                                          X.ZPixmap, 0xFFFFFFFF).data
                return geometry, pixels

            geometry, before = image()
            colors = len(set(before[i:i + 4] for i in range(0, len(before), 4)))
            if colors < 2:
                raise RuntimeError("initial frame is uniform")
            origin = root.translate_coords(window, 0, 0)
            xtest.fake_input(connection, X.MotionNotify, x=origin.x + 200, y=origin.y + 200)
            connection.sync()
            xtest.fake_input(connection, X.ButtonPress, 1)
            connection.sync()
            for x in range(210, 390, 10):
                xtest.fake_input(connection, X.MotionNotify, x=origin.x + x, y=origin.y + 240)
                connection.sync()
                time.sleep(0.015)
            xtest.fake_input(connection, X.ButtonRelease, 1)
            connection.sync()
            time.sleep(0.7)
            _, after = image()
            changed = sum(a != b for a, b in zip(before, after))
            if changed < 5000:
                raise RuntimeError(f"orbit frame changed only {changed} bytes")
            window.configure(width=700, height=500)
            connection.sync()
            time.sleep(1)
            resized, pixels = image()
            if (resized.width, resized.height) != (700, 500):
                raise RuntimeError(f"unexpected window size {resized.width}x{resized.height}")
            if len(set(pixels[i:i + 4] for i in range(0, len(pixels), 4))) < 2:
                raise RuntimeError("resized frame is uniform")
            code = process.wait(timeout=45)
            log.seek(0)
            output = log.read()
            match = re.search(r"POKO_CUBE_RESULT submitted=(\d+) validation_requested=(\w+) "
                              r"graphics_errors=(\d+) graphics_warnings=(\d+)", output)
            if code or not match or int(match[1]) < 300 or match[2] != "true" or match.group(3, 4) != ("0", "0"):
                raise RuntimeError(f"cube failed or reported diagnostics (exit {code})")
            print(f"PASS: {geometry.width}x{geometry.height}, orbit changed {changed} bytes, "
                  f"resize {resized.width}x{resized.height}; {match[0]}")
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
            print(f"FAIL: {error}\n" + "\n".join(log.read().splitlines()[-20:]), file=sys.stderr)
            return 1
        finally:
            connection.close()


if __name__ == "__main__":
    sys.exit(main())
