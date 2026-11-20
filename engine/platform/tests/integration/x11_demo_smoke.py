"""Optional Linux/X11 host smoke test; not a Windows or Android test.

Usage: DISPLAY=:99 python3 x11_demo_smoke.py /path/to/pokox_window_demo
Run on an isolated test display; the script targets only its uniquely titled window.
"""
import ctypes
import os
import subprocess
import sys
import time
import uuid

if len(sys.argv) != 2 or not os.environ.get("DISPLAY"):
    raise SystemExit("Usage: DISPLAY=:N python3 x11_demo_smoke.py /path/to/pokox_window_demo")

x = ctypes.CDLL("libX11.so.6")
ptr, win, integer = ctypes.c_void_p, ctypes.c_ulong, ctypes.c_int
x.XOpenDisplay.argtypes, x.XOpenDisplay.restype = [ctypes.c_char_p], ptr
x.XDefaultRootWindow.argtypes, x.XDefaultRootWindow.restype = [ptr], win
x.XQueryTree.argtypes = [ptr, win, ctypes.POINTER(win), ctypes.POINTER(win),
                        ctypes.POINTER(ctypes.POINTER(win)), ctypes.POINTER(ctypes.c_uint)]
x.XQueryTree.restype = integer
x.XFetchName.argtypes = [ptr, win, ctypes.POINTER(ptr)]
x.XFree.argtypes = [ptr]
x.XResizeWindow.argtypes = [ptr, win, ctypes.c_uint, ctypes.c_uint]
x.XSync.argtypes = [ptr, integer]
x.XInternAtom.argtypes, x.XInternAtom.restype = [ptr, ctypes.c_char_p, integer], win
x.XCloseDisplay.argtypes = [ptr]


class ClientData(ctypes.Union):
    _fields_ = [("b", ctypes.c_byte * 20), ("s", ctypes.c_short * 10), ("l", ctypes.c_long * 5)]


class ClientMessage(ctypes.Structure):
    _fields_ = [("type", integer), ("serial", win), ("send_event", integer), ("display", ptr),
                ("window", win), ("message_type", win), ("format", integer), ("data", ClientData)]


class XEvent(ctypes.Union):
    _fields_ = [("xclient", ClientMessage), ("pad", ctypes.c_long * 24)]


x.XSendEvent.argtypes = [ptr, win, integer, ctypes.c_long, ctypes.POINTER(XEvent)]
x.XSendEvent.restype = integer
display = x.XOpenDisplay(os.environ["DISPLAY"].encode())
if not display:
    raise SystemExit("Cannot open DISPLAY")
title = "PokoX smoke " + uuid.uuid4().hex
env = os.environ.copy()
env["SDL_VIDEODRIVER"] = "x11"
proc = None
try:
    proc = subprocess.Popen([sys.argv[1], title], stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True, env=env)
    root, target = x.XDefaultRootWindow(display), None
    for _ in range(100):
        root_out, parent = win(), win()
        children, count = ctypes.POINTER(win)(), ctypes.c_uint()
        if not x.XQueryTree(display, root, ctypes.byref(root_out), ctypes.byref(parent),
                            ctypes.byref(children), ctypes.byref(count)):
            raise RuntimeError("XQueryTree failed")
        try:
            for i in range(count.value):
                name = ptr()
                if x.XFetchName(display, children[i], ctypes.byref(name)) and name.value:
                    value = ctypes.string_at(name).decode(errors="replace")
                    x.XFree(name)
                    if value == title:
                        target = children[i]
                        break
        finally:
            if children:
                x.XFree(children)
        if target:
            break
        time.sleep(0.05)
    if not target:
        raise RuntimeError("Demo window not found")
    print("Found X11 demo window", target, flush=True)
    x.XResizeWindow(display, target, 704, 448)
    x.XSync(display, 0)
    time.sleep(0.5)
    event = XEvent()
    event.xclient.type = 33  # ClientMessage
    event.xclient.display = display
    event.xclient.window = target
    event.xclient.message_type = x.XInternAtom(display, b"WM_PROTOCOLS", 0)
    event.xclient.format = 32
    event.xclient.data.l[0] = x.XInternAtom(display, b"WM_DELETE_WINDOW", 0)
    if not x.XSendEvent(display, target, 0, 0, ctypes.byref(event)):
        raise RuntimeError("Failed to send WM_DELETE_WINDOW")
    x.XSync(display, 0)
    output = proc.communicate(timeout=5)[0]
    print(output, end="")
    if proc.returncode != 0 or "logical 704x448" not in output:
        raise RuntimeError("Demo resize/close verification failed")
    print("PASS: X11 resize and WM_DELETE_WINDOW closed the demo")
finally:
    if proc is not None and proc.poll() is None:
        proc.kill()
        proc.wait()
    x.XCloseDisplay(display)
