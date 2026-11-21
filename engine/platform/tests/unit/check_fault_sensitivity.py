from pathlib import Path
import subprocess, json, argparse, tempfile
parser = argparse.ArgumentParser(description='Optional GCC/Clang/MinGW sensitivity check; not real SDL validation.')
parser.add_argument('--cxx', default='c++', help='GCC/Clang-compatible C++ compiler executable')
args = parser.parse_args()
r = Path(__file__).resolve().parents[4]
workspace = tempfile.TemporaryDirectory(prefix='poko-platform-mutations-')
work = Path(workspace.name)
source=(r/'engine/platform/src/window/sdl_platform.cpp').read_text()
mutations={
'duplicate_initialization': ('if (initialized_) return PlatformError::already_initialized;', 'if (false) return PlatformError::already_initialized;'),
'shutdown_reference_leak': ('SDL_QuitSubSystem(SDL_INIT_VIDEO);', '// deliberately leaked reference'),
'failed_init_claims_success': ('if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) return PlatformError::platform_failure;', 'if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) return PlatformError::none;'),
'window_failure_claims_success': ('return window_ ? PlatformError::none : PlatformError::platform_failure;', 'return PlatformError::none;'),
'missing_foreign_window_filter': ('if (!window_ || raw.window.windowID != SDL_GetWindowID(window_)) continue;', 'if (!window_) continue;'),
'close_translated_as_quit': ('event = {EventType::window_close_requested, {}};', 'event = {EventType::quit_requested, {}};'),
'pixel_dimensions_lost': ('nonnegative(pw), nonnegative(ph)', 'nonnegative(w), nonnegative(h)'),
'vulkan_flag_omitted': ('flags |= SDL_WINDOW_VULKAN;', 'flags |= 0;'),
'size_query_failure_ignored': ('if (!SDL_GetWindowSize(window_, &w, &h) || !SDL_GetWindowSizeInPixels(window_, &pw, &ph))', 'if ((SDL_GetWindowSize(window_, &w, &h), SDL_GetWindowSizeInPixels(window_, &pw, &ph), false))'),
'pixel_resize_event_ignored': ('raw.type != SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED', 'true'),
'destroy_window_leak': ('SDL_DestroyWindow(window_);', '// deliberately leaked window'),
}
results=[]
for name,(old,new) in mutations.items():
    assert source.count(old)==1,(name,source.count(old))
    path=(work/'mutant.cpp'); path.write_text(source.replace(old,new))
    command=[args.cxx,'-std=c++20','-I'+str(r/'engine/platform/tests/fakes'),'-I'+str(r/'engine/platform/include'),str(path),str(r/'engine/platform/tests/unit/sdl_platform_faults.cpp'),'-o',str(work/'mutant.exe')]
    build=subprocess.run(command,capture_output=True,text=True,timeout=30)
    if build.returncode:
        results.append({'mutation':name,'result':'BUILD_ERROR','detail':build.stderr})
    else:
        run=subprocess.run([str(work/'mutant.exe')],capture_output=True,text=True,timeout=5)
        results.append({'mutation':name,'result':'CAUGHT' if run.returncode else 'MISSED','detail':(run.stdout+run.stderr).strip()})
    print(results[-1],flush=True)
print(json.dumps(results, indent=2))
workspace.cleanup()
raise SystemExit(0 if all(x['result']=='CAUGHT' for x in results) else 1)
