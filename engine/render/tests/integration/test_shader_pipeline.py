"""Exercise the real host compiler and CMake shader rule in an isolated build."""
import argparse
import os
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile
import time

parser = argparse.ArgumentParser()
parser.add_argument('--cmake', required=True)
parser.add_argument('--compiler', required=True)
args = parser.parse_args()
root = Path(__file__).resolve().parents[4]

def run(command, ok=True):
    result = subprocess.run([str(x) for x in command], text=True, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, timeout=60)
    if (result.returncode == 0) != ok:
        raise AssertionError(f'Unexpected status {result.returncode}: {command}\n{result.stdout}')
    return result.stdout

def check_spirv(path):
    data = path.read_bytes()
    assert len(data) >= 20 and len(data) % 4 == 0
    magic, version, _, bound, schema = struct.unpack_from('<5I', data)
    assert magic == 0x07230203 and 0x10000 <= version <= 0x10600 and bound > 0 and schema == 0
    return data

with tempfile.TemporaryDirectory(prefix='poko shader pipeline ') as temp:
    work = Path(temp)
    source = work / 'source with spaces'; build = work / 'build with spaces'
    source.mkdir()
    for file in ('PokoShaders.cmake', 'compile_shader.cmake'):
        shutil.copy2(root / 'engine/build/cmake' / file, source / file)
    shader = source / 'input.vert'
    good = '#version 450\nvoid main() { gl_Position = vec4(0.25, 0.0, 0.0, 1.0); }\n'
    shader.write_text(good, encoding='utf-8')
    (source / 'CMakeLists.txt').write_text('''cmake_minimum_required(VERSION 3.28)
project(ShaderRuleTest NONE)
include("${CMAKE_CURRENT_SOURCE_DIR}/PokoShaders.cmake")
set(POKO_SHADER_TOOL_SIGNATURE "${CMAKE_CURRENT_BINARY_DIR}/compiler-signature.txt")
file(GENERATE OUTPUT "${POKO_SHADER_TOOL_SIGNATURE}" CONTENT "${POKO_GLSLANG_EXECUTABLE}\\n")
poko_compile_shader("${CMAKE_CURRENT_BINARY_DIR}/output.spv" "${CMAKE_CURRENT_SOURCE_DIR}/input.vert" vert)
add_custom_target(shader ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/output.spv")
''', encoding='utf-8')
    run([args.cmake, '-S', source, '-B', build, '-DPOKO_GLSLANG_EXECUTABLE=' + args.compiler])
    run([args.cmake, '--build', build])
    artifact = build / 'output.spv'
    first = check_spirv(artifact)
    first_mtime = artifact.stat().st_mtime_ns
    # The replacement keeps its older timestamp: changing tool identity must
    # still trigger a rebuild, not retain an artifact from the previous tool.
    # A Windows SDK executable may need adjacent DLLs, so do not relocate it.
    if os.name != 'nt':
        tool_dir = work / 'other compiler'; tool_dir.mkdir()
        other_tool = tool_dir / Path(args.compiler).name
        shutil.copy2(args.compiler, other_tool)
        time.sleep(1.1)
        run([args.cmake, '-S', source, '-B', build, '-DPOKO_GLSLANG_EXECUTABLE=' + str(other_tool)])
        run([args.cmake, '--build', build])
        assert artifact.stat().st_mtime_ns > first_mtime, 'changed compiler did not rebuild shader'
        check_spirv(artifact)
    # Age the output instead of putting inputs in the future (which causes
    # make clock-skew warnings), then verify the normal dependency rebuild.
    def update_shader(text):
        if artifact.exists():
            old = time.time() - 3
            os.utime(artifact, (old, old))
        shader.write_text(text, encoding='utf-8')
    update_shader(good.replace('0.25', '0.75'))
    run([args.cmake, '--build', build])
    assert check_spirv(artifact) != first, 'source modification did not regenerate SPIR-V'
    update_shader('#version 450\nvoid main() { this is invalid; }\n')
    run([args.cmake, '--build', build], ok=False)
    assert not artifact.exists() and not (build / 'output.spv.tmp').exists(), 'failed compile left stale output'
    update_shader(good)
    run([args.cmake, '--build', build])
    check_spirv(artifact)
    include_cases = (
        '#include "untracked.glsl"',
        '#/**/include "untracked.glsl"',
        '# /* a comment */ include "untracked.glsl"',
        '#inc' + chr(92) + '\nlude "untracked.glsl"',
        '/* comment\n*/ #include "untracked.glsl"',
    )
    for directive in include_cases:
        update_shader('#version 450\n' + directive + '\nvoid main() {}\n')
        output = run([args.cmake, '--build', build], ok=False)
        assert 'not supported without dependency tracking' in output and not artifact.exists()
    # Commented-out text is not an active include directive.
    update_shader(good + '// #include "ignored.glsl"\n/* #include "ignored.glsl" */\n')
    run([args.cmake, '--build', build])
    check_spirv(artifact)
    shader.write_text(good, encoding='utf-8')
    output = run([args.cmake, '-DPOKO_SHADER_SOURCE=' + str(shader), '-DPOKO_SHADER_OUTPUT=' + str(shader),
                  '-DPOKO_SHADER_STAGE=vert', '-DPOKO_SHADER_COMPILER=' + args.compiler,
                  '-P', source / 'compile_shader.cmake'], ok=False)
    assert 'must not overwrite' in output and shader.read_text(encoding='utf-8') == good
    alias = source / '..' / source.name / shader.name
    output = run([args.cmake, '-DPOKO_SHADER_SOURCE=' + str(shader), '-DPOKO_SHADER_OUTPUT=' + str(alias),
                  '-DPOKO_SHADER_STAGE=vert', '-DPOKO_SHADER_COMPILER=' + args.compiler,
                  '-P', source / 'compile_shader.cmake'], ok=False)
    assert 'must not overwrite' in output and shader.read_text(encoding='utf-8') == good
    # A symlinked parent can otherwise refer to the same source despite having
    # a different spelling. Keep this portable when Windows symlinks require privileges.
    if os.name != 'nt':
        symlink_dir = work / 'source alias'
        symlink_dir.symlink_to(source, target_is_directory=True)
        output = run([args.cmake, '-DPOKO_SHADER_SOURCE=' + str(shader),
                      '-DPOKO_SHADER_OUTPUT=' + str(symlink_dir / shader.name),
                      '-DPOKO_SHADER_STAGE=vert', '-DPOKO_SHADER_COMPILER=' + args.compiler,
                      '-P', source / 'compile_shader.cmake'], ok=False)
        assert 'must not overwrite' in output and shader.read_text(encoding='utf-8') == good
    # The temporary output can also collide, including via a directory alias.
    temp_source = source / 'temporary-output.spv.tmp'
    temp_source.write_text(good, encoding='utf-8')
    temp_parent = symlink_dir if os.name != 'nt' else source
    output = run([args.cmake, '-DPOKO_SHADER_SOURCE=' + str(temp_source),
                  '-DPOKO_SHADER_OUTPUT=' + str(temp_parent / 'temporary-output.spv'),
                  '-DPOKO_SHADER_STAGE=vert', '-DPOKO_SHADER_COMPILER=' + args.compiler,
                  '-P', source / 'compile_shader.cmake'], ok=False)
    assert 'must not overwrite' in output and temp_source.read_text(encoding='utf-8') == good
    # Neither final output nor its temporary file may replace the compiler.
    tool_copy = work / 'compiler-copy'
    shutil.copy2(args.compiler, tool_copy)
    tool_bytes = tool_copy.read_bytes()
    for output_path in (tool_copy, work / 'compiler-copy-without-tmp'):
        if output_path != tool_copy:
            tool_copy.rename(Path(str(output_path) + '.tmp'))
            protected_tool = Path(str(output_path) + '.tmp')
        else:
            protected_tool = tool_copy
        output = run([args.cmake, '-DPOKO_SHADER_SOURCE=' + str(shader),
                      '-DPOKO_SHADER_OUTPUT=' + str(output_path),
                      '-DPOKO_SHADER_STAGE=vert', '-DPOKO_SHADER_COMPILER=' + str(protected_tool),
                      '-P', source / 'compile_shader.cmake'], ok=False)
        assert 'must not overwrite' in output and protected_tool.read_bytes() == tool_bytes
print('PASS: real shader compile, path quoting, rebuild, failure cleanup, include and overwrite guards')
