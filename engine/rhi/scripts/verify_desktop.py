"""Collect real desktop build/run evidence. Never automatically accept ENG-03."""
from pathlib import Path
import argparse
import datetime
import hashlib
import json
import os
import platform
import re
import signal
import subprocess
import time

MARKER = re.compile(r'POKO_CLEAR_RESULT submitted=(\d+) validation_requested=(true|false) graphics_errors=(\d+) graphics_warnings=(\d+)')

def parse_runtime(text, expected_frames):
    lines = [x.strip() for x in text.splitlines() if x.strip().startswith('POKO_CLEAR_RESULT')]
    if len(lines) != 1 or not (match := MARKER.fullmatch(lines[0])):
        raise ValueError('Expected exactly one well-formed completed-run summary')
    frames, requested, errors, warnings = match.groups()
    result = dict(submitted=int(frames), validation_requested=requested == 'true',
                  graphics_errors=int(errors), graphics_warnings=int(warnings))
    if result['submitted'] != expected_frames or not result['validation_requested'] or result['graphics_errors']:
        raise ValueError('Incomplete frames, disabled validation, or graphics errors')
    return result

def classify(runtime):
    return dict(status='automated_checks_passed_visual_review_required', accepted=False,
                visual_output_verified=False, validation_layer_verified=False, runtime=runtime)

def run_step(command, log, timeout):
    command = [str(x) for x in command]
    result = dict(command=command, log=str(log), timed_out=False)
    started = time.monotonic()
    options = dict(start_new_session=True) if os.name != 'nt' else dict(creationflags=subprocess.CREATE_NEW_PROCESS_GROUP)
    with Path(log).open('w', encoding='utf-8') as out:
        try:
            proc = subprocess.Popen(command, stdout=out, stderr=subprocess.STDOUT, **options)
        except OSError as exc:
            out.write(str(exc)); return dict(result, returncode=None, error=str(exc))
        try:
            proc.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            result['timed_out'] = True
            if os.name == 'nt':
                try:
                    subprocess.run(['taskkill', '/PID', str(proc.pid), '/T', '/F'], stdout=out,
                                   stderr=subprocess.STDOUT, timeout=15, check=False)
                finally:
                    if proc.poll() is None: proc.kill()
            else:
                try: os.killpg(proc.pid, signal.SIGKILL)
                except ProcessLookupError: pass
            proc.wait(timeout=15)
        result['returncode'] = proc.returncode
    return dict(result, elapsed_seconds=round(time.monotonic() - started, 3))

def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cmake', default='cmake')
    parser.add_argument('--ctest', default='ctest')
    parser.add_argument('--generator')
    parser.add_argument('--arch')
    parser.add_argument('--toolchain-file', type=Path)
    parser.add_argument('--triplet')
    parser.add_argument('--cmake-arg', action='append', default=[])
    parser.add_argument('--config', default='Debug')
    parser.add_argument('--frames', type=int, default=120)
    parser.add_argument('--runtime-timeout', type=float, default=60)
    parser.add_argument('--build-timeout', type=float, default=3600)
    parser.add_argument('--output-dir', type=Path)
    args = parser.parse_args(argv)
    if not 1 <= args.frames <= 0xFFFFFFFF or args.runtime_timeout <= 0 or args.build_timeout <= 0:
        parser.error('Positive timeouts and uint32 frame count required')
    if not re.fullmatch(r'[A-Za-z0-9_-]+', args.config) or any(not x.startswith('-D') for x in args.cmake_arg):
        parser.error('Use a simple configuration name and -D-only extra CMake definitions')
    root = Path(__file__).resolve().parents[3]
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    output = (args.output_dir or root / 'build-validation-results' / stamp).resolve()
    if output.exists() and (not output.is_dir() or any(output.iterdir())):
        parser.error('Output directory must be empty/new; old runs are never overwritten')
    output.mkdir(parents=True, exist_ok=True)
    build = output / 'build'
    report = dict(started_utc=stamp, source_root=str(root), host=platform.platform(), accepted=False,
                  visual_output_verified=False, validation_layer_verified=False, status='failed', steps=[])
    report['source_hashes'] = {name: hashlib.sha256((root / name).read_bytes()).hexdigest() for name in (
        'CMakeLists.txt', 'engine/rhi/src/vulkan_clear_renderer.cpp',
        'engine/rhi/src/vulkan_diagnostics.cpp', 'engine/rhi/src/vulkan_clear_demo.cpp')}
    configure = [args.cmake, '-S', root, '-B', build]
    if args.generator: configure += ['-G', args.generator]
    if args.arch: configure += ['-A', args.arch]
    if args.toolchain_file: configure += ['-DCMAKE_TOOLCHAIN_FILE=' + str(args.toolchain_file.resolve())]
    if args.triplet: configure += ['-DVCPKG_TARGET_TRIPLET=' + args.triplet]
    configure += [*args.cmake_arg, '-DCMAKE_BUILD_TYPE=' + args.config, '-DPOKO_WITH_SDL_PLATFORM=ON',
                  '-DPOKO_WITH_VULKAN_DEMO=ON', '-DPOKO_D3D12=OFF', '-DDILIGENT_NO_VULKAN=OFF', '-DBUILD_TESTING=ON']
    commands = [('configure', configure),
                ('build', [args.cmake, '--build', build, '--config', args.config, '--parallel', '2']),
                ('ctest', [args.ctest, '--test-dir', build, '-C', args.config, '--output-on-failure',
                           '--no-tests=error', '--output-junit', output / 'ctest-results.xml'])]
    try:
        for index, (stage, command) in enumerate(commands, 1):
            step = run_step(command, output / f'{index:02d}-{stage}.log', args.build_timeout)
            report['steps'].append(dict(step, stage=stage))
            if step.get('returncode') != 0 or step['timed_out']:
                raise RuntimeError(stage + ' failed; inspect its log')
        name = 'pokox_vulkan_clear' + ('.exe' if os.name == 'nt' else '')
        exe = next((p for p in (build / args.config / name, build / name) if p.is_file()), None)
        if exe is None: raise RuntimeError('Built clear executable not found')
        report['executable_sha256'] = hashlib.sha256(exe.read_bytes()).hexdigest()
        log = output / '04-runtime.log'
        step = run_step([exe, '--frames', str(args.frames)], log, args.runtime_timeout)
        report['steps'].append(dict(step, stage='runtime'))
        if step.get('returncode') != 0 or step['timed_out']: raise RuntimeError('Runtime failed; inspect its log')
        report.update(classify(parse_runtime(log.read_text(encoding='utf-8', errors='replace'), args.frames)))
        return 0
    except Exception as exc:
        report['reason'] = str(exc); return 1
    finally:
        (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
        print('Evidence directory:', output)
        print('ENG-03 accepted: false; visible output, layer availability and target behavior require review.')

if __name__ == '__main__':
    raise SystemExit(main())
