#!/usr/bin/env python3
"""Build a minimal real project repeatedly as Git tag state changes."""
import argparse
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

parser = argparse.ArgumentParser()
parser.add_argument("--cmake", required=True)
parser.add_argument("--git", required=True)
parser.add_argument("--generator", required=True)
parser.add_argument("--platform", default="")
OPTIONS = parser.parse_args()
sys.argv[:] = [sys.argv[0]]
PROJECT = Path(__file__).resolve().parents[4]


def command(args, **kwargs):
    result = subprocess.run(args, text=True, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, encoding="utf-8", errors="replace", **kwargs)
    if result.returncode:
        raise AssertionError(f"Command failed ({result.returncode}): {args}\n{result.stdout}")
    return result.stdout


class VersionIntegrationTests(unittest.TestCase):
    def test_real_binary_tracks_git_state(self):
        with tempfile.TemporaryDirectory(prefix="poko version test ") as temp:
            root = Path(temp) / "source"
            build = Path(temp) / "build"
            for relative in ("CMakeLists.txt", "mute/src/lexer/lexer.cpp",
                             "mute/src/lexer/unicode_xid.hpp",
                             "mute/src/parser/parser.cpp",
                             "mute/src/parser/statement.cpp",
                             "mute/src/parser/declaration.cpp",
                             "mute/src/semantic/semantic.cpp",
                             "mute/src/package/package.cpp",
                             "mute/include/poko/mute/package.hpp",
                             "mute/src/evaluator/evaluator.cpp",
                             "mute/src/program/program.cpp",
                             "mute/src/state/state.cpp",
                             "mute/src/state/state_snapshot.cpp",
                             "mute/include/poko/mute/state_snapshot.hpp",
                             "mute/src/pkb/pkb_draft.cpp",
                             "mute/tools/pkb_schema_draft.cpp",
                             "mute/include/poko/mute/pkb_draft.hpp",
                             "mute/include/poko/mute/state.hpp",
                             "mute/src/program/program_vm.inc",
                             "mute/src/program/program_codec.inc",
                             "mute/src/math/deterministic_math.cpp",
                             "mute/include/poko/mute/deterministic_math.hpp",
                             "mute/third_party/musl_math/math_internal.hpp",
                             "mute/third_party/musl_math/sin.cpp",
                             "mute/third_party/musl_math/cos.cpp",
                             "mute/third_party/musl_math/__sin.cpp",
                             "mute/third_party/musl_math/__cos.cpp",
                             "mute/third_party/musl_math/__rem_pio2.cpp",
                             "mute/third_party/musl_math/__rem_pio2_large.cpp",
                             "mute/third_party/musl_math/floor.cpp",
                             "mute/third_party/musl_math/scalbn.cpp",
                             "mute/src/bytecode/bytecode.cpp",
                             "mute/src/vm/register_vm.cpp",
                             "mute/include/poko/mute/evaluator.hpp",
                             "mute/include/poko/mute/program.hpp",
                             "mute/include/poko/mute/bytecode.hpp",
                             "mute/include/poko/mute/register_vm.hpp",
                             "mute/include/poko/mute/parser.hpp",
                             "mute/include/poko/mute/statement.hpp",
                             "mute/include/poko/mute/declaration.hpp",
                             "mute/include/poko/mute/semantic.hpp",
                             "mute/include/poko/mute/lexer.hpp",
                             "engine/foundation/src/main.cpp",
                             "engine/foundation/src/cbor.cpp",
                             "engine/foundation/src/config.cpp",
                             "engine/foundation/src/frame_stats.cpp",
                             "engine/foundation/include/poko/foundation/cbor.hpp",
                             "engine/foundation/include/poko/foundation/config.hpp",
                             "engine/foundation/include/poko/foundation/frame_stats.hpp",
                             "engine/foundation/include/poko/foundation/logging.hpp",
                             "engine/foundation/include/poko/foundation/build_flags.hpp",
                             "engine/resource/src/asset_store.cpp",
                             "engine/resource/src/ktx2.cpp",
                             "engine/resource/src/pokomesh.cpp",
                             "engine/resource/include/poko/resource/asset_store.hpp",
                             "engine/resource/include/poko/resource/ktx2.hpp",
                             "engine/resource/include/poko/resource/pokomesh.hpp",
                             "engine/rhi/include/poko/rhi/device/clear_backend_selection.hpp",
                             "engine/rhi/include/poko/rhi/device/render_error.hpp",
                             "engine/rhi/src/device/clear_backend_selection.cpp",
                             "engine/render/include/poko/render/framegraph/frame_graph.hpp",
                             "engine/render/src/framegraph/frame_graph.cpp",
                             "tools/version/cmake/generate_version.cmake"):
                dst = root / relative
                dst.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(PROJECT / relative, dst)
            configure = [OPTIONS.cmake, "-S", str(root), "-B", str(build),
                         "-G", OPTIONS.generator, "-DBUILD_TESTING=OFF",
                         "-DPOKO_WITH_DEPENDENCIES=OFF", "-DCMAKE_BUILD_TYPE=Debug"]
            if OPTIONS.platform:
                configure += ["-A", OPTIONS.platform]
            command(configure)
            def build_and_version():
                command([OPTIONS.cmake, "--build", str(build), "--config", "Debug", "--target", "pokox"])
                exe = next((p for p in (build / "Debug" / "pokox.exe", build / "pokox.exe", build / "pokox") if p.is_file()), None)
                self.assertIsNotNone(exe, "built executable not found")
                return command([str(exe)]).strip(), command([str(exe), "--version"]).strip()
            def git(*args):
                return command([OPTIONS.git, "-C", str(root), *args])
            # Source archive: no Git directory, no invented release version.
            normal, version = build_and_version()
            self.assertEqual(normal, "")
            self.assertEqual(version, "PokoX build: unversioned")
            git("init", "-q")
            git("config", "user.name", "PokoX Test")
            git("config", "user.email", "test@example.invalid")
            git("add", ".")
            git("-c", "commit.gpgsign=false", "commit", "-qm", "test")
            self.assertEqual(build_and_version()[1], "PokoX build: unversioned")
            git("tag", "Zulu")
            self.assertEqual(build_and_version()[1], "PokoX build: Zulu")
            # Multiple exact tags choose lexicographically first; annotated tags work.
            git("tag", "-a", "Alpha", "-m", "test")
            self.assertEqual(build_and_version()[1], "PokoX build: Alpha")
            git("tag", "-d", "Alpha", "Zulu")
            # Double quotes are valid Git ref characters but invalid Windows filenames.
            odd_tag = 'A-odd;semicolon' if os.name == "nt" else 'A-quote"and;semicolon'
            git("tag", odd_tag)
            self.assertEqual(build_and_version()[1], "PokoX build: " + odd_tag)
            git("tag", "-d", odd_tag)
            git("tag", "café")
            self.assertEqual(build_and_version()[1], "PokoX build: café")
            # An untagged new commit must not claim the earlier tag.
            git("-c", "commit.gpgsign=false", "commit", "--allow-empty", "-qm", "next")
            self.assertEqual(build_and_version()[1], "PokoX build: unversioned")
            header = build / "generated/poko/build_version.hpp"
            old_time = header.stat().st_mtime_ns
            self.assertEqual(build_and_version()[1], "PokoX build: unversioned")
            self.assertEqual(header.stat().st_mtime_ns, old_time, "unchanged header was rewritten")


if __name__ == "__main__":
    unittest.main(verbosity=2)
