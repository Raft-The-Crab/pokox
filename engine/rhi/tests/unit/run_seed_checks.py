"""Portable GCC/Clang-compatible seed checks. These do NOT use real SDL/Diligent/GPU."""
from pathlib import Path
import argparse
import os
import shutil
import subprocess
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--cxx', default='c++')
parser.add_argument('--sanitize', action='store_true')
parser.add_argument('--mutations', action='store_true')
args = parser.parse_args()
if shutil.which(args.cxx) is None:
    print(f'SKIP: GCC/Clang-compatible compiler not found: {args.cxx}', flush=True)
    raise SystemExit(0)
root = Path(__file__).resolve().parents[4]
source = root / 'engine/rhi/src/device/vulkan_clear_renderer.cpp'
platform_source = root / 'engine/platform/src/window/sdl_platform.cpp'
diagnostics_source = root / 'engine/rhi/src/debug/vulkan_diagnostics.cpp'
test = root / 'engine/rhi/tests/unit/vulkan_clear_faults.cpp'
flags = ['-std=c++20', '-Wall', '-Wextra', '-Wpedantic', '-Werror']
if args.sanitize:
    flags += ['-g', '-O1', '-fsanitize=address,undefined', '-fno-omit-frame-pointer']
else:
    flags += ['-O2', '-DNDEBUG']
includes = ['-I' + str(root / p) for p in (
    'engine/rhi/include', 'engine/platform/include',
    'engine/rhi/tests/fakes', 'engine/platform/tests/fakes')]
env = os.environ.copy()
if args.sanitize:
    env.setdefault('ASAN_OPTIONS', 'detect_leaks=1')
    env.setdefault('UBSAN_OPTIONS', 'halt_on_error=1')
def run(command, expected=0, extra_env=None):
    result = subprocess.run([str(x) for x in command], capture_output=True, text=True,
                            timeout=60, env={**env, **(extra_env or {})})
    if result.returncode != expected:
        raise RuntimeError(f'{command}\nexit={result.returncode}\n{result.stdout}{result.stderr}')
    return result
with tempfile.TemporaryDirectory(prefix='poko-clear-seed-') as directory:
    work = Path(directory)
    common = [args.cxx, *flags, *includes]
    for native in ('LINUX', 'WIN32', 'ANDROID'):
        exe = work / f'faults-{native}.exe'
        run([*common, f'-DPLATFORM_{native}=1', platform_source, source, diagnostics_source, test, '-o', exe])
        run([exe])
        print(f'PASS: {native} native-window branch with dependency doubles', flush=True)
    helper = work / 'demo-double.o'
    run([*common, '-DPLATFORM_LINUX=1', '-Dmain=poko_dependency_double_test_main',
         '-c', test, '-o', helper])
    demo = work / 'demo.exe'
    run([*common, '-DPLATFORM_LINUX=1', platform_source, source, diagnostics_source,
         root / 'engine/rhi/src/device/vulkan_clear_demo.cpp', helper, '-o', demo])
    run([demo, '--frames', '2'])
    run([demo, '--frames', '2', '--no-validation'])
    for invalid in (('--frames', '0'), ('--frames', '-1'), ('--frames', '2junk'),
                    ('--frames',), ('--bogus',), ('--frames', '99999999999999999999')):
        run([demo, *invalid], expected=2)
    print('PASS: bounded demo and six invalid-argument cases with doubles', flush=True)
    for phase in ('create', 'present', 'shutdown'):
        failed = run([demo, '--frames', '2'], expected=1, extra_env={'POKO_TEST_GRAPHICS_MESSAGE': 'error:' + phase})
        if 'Completed 2' in failed.stdout: raise RuntimeError('False success: ' + phase)
    failed = run([demo, '--frames', '2'], expected=1, extra_env={'POKO_TEST_THROW_IDLE': '1'})
    if 'Completed 2' in failed.stdout or 'cleanup failed' not in failed.stderr:
        raise RuntimeError('Idle exception was not reported as a cleanup failure')
    run([demo, '--frames', '2', '--no-validation'], expected=1, extra_env={'POKO_TEST_GRAPHICS_MESSAGE': 'error:present'})
    warned = run([demo, '--frames', '2'], extra_env={'POKO_TEST_GRAPHICS_MESSAGE': 'warning:present'})
    if 'graphics_errors=0 graphics_warnings=2' not in warned.stdout: raise RuntimeError('Warning accounting failed')
    print('PASS: diagnostic errors fail create/present/shutdown; warnings counted; no-validation is not a bypass', flush=True)
    if args.mutations:
        original = source.read_text()
        changes = {
            'accept_plain_window': ('if (!window || (SDL_GetWindowFlags(window) & SDL_WINDOW_VULKAN) == 0)', 'if (!window)'),
            'allow_duplicate_initialization': ('if (impl_) return RenderError::already_initialized;', 'if (false) return RenderError::already_initialized;'),
            'ignore_zero_drawable': ('if (size.pixel_width == 0 || size.pixel_height == 0) return RenderError::not_drawable;', 'if (false) return RenderError::not_drawable;'),
            'ignore_minimized': ('if ((SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) != 0)', 'if (false)'),
            'ignore_resize': ('if (size.pixel_width != desc.Width || size.pixel_height != desc.Height)', 'if (false)'),
            'omit_present': ('impl_->swapchain->Present(1);', '// omitted'),
            'omit_idle': ('try { context->WaitForIdle(); }', 'try { /* omitted */ }'),
            'ignore_window_identity': ('if (!window || SDL_GetWindowID(window) != impl_->window_id)', 'if (!window)'),
            'swap_cleanup_order': ('swapchain.Release();\n    context.Release();', 'context.Release();\n    swapchain.Release();'),
        }
        for name, (old, new) in changes.items():
            count = original.count(old)
            if count != 1 and not (name in ('ignore_zero_drawable', 'ignore_minimized') and count == 2):
                raise RuntimeError(f'{name}: expected anchor count, found {count}')
            mutant = work / 'mutant.cpp'
            mutant.write_text(original.replace(old, new))
            exe = work / 'mutant.exe'
            # Mutants deliberately break invariants; warnings are not runtime catches.
            mutant_flags = [x for x in common if x != '-Werror']
            run([*mutant_flags, '-DPLATFORM_LINUX=1', platform_source, mutant, diagnostics_source, test, '-o', exe])
            result = subprocess.run([str(exe)], capture_output=True, text=True, timeout=5, env=env)
            if result.returncode == 0:
                raise RuntimeError(f'MISSED mutation: {name}')
            print(f'CAUGHT: {name}', flush=True)
print('Complete. No real SDK, window, GPU, target-platform or pixel validation was performed.')
