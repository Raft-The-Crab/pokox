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

OPTIONS = None
PROJECT = Path(__file__).resolve().parents[4]
SOURCE_FILES = ("CMakeLists.txt",)
SOURCE_TREES = ("engine", "mute", "server/identity", "tools/version/cmake")
COPY_IGNORE = shutil.ignore_patterns(
    ".git", "__pycache__", "*.py[cod]", "build-*", "artifacts", "graphify-out",
    ".workbuddy-ai", ".serena", "*.exe", "*.lib", "*.obj", "*.pdb", "*.apk")


def parse_options() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cmake", required=True)
    parser.add_argument("--git", required=True)
    parser.add_argument("--generator", required=True)
    parser.add_argument("--platform", default="")
    return parser.parse_args()


def copy_sources(root: Path) -> None:
    for relative in SOURCE_FILES:
        source = PROJECT / relative
        if not source.is_file():
            raise AssertionError(f"missing source file: {relative}")
        destination = root / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, destination)
    for relative in SOURCE_TREES:
        source = PROJECT / relative
        if not source.is_dir():
            raise AssertionError(f"missing source tree: {relative}")
        shutil.copytree(source, root / relative, ignore=COPY_IGNORE, dirs_exist_ok=True)


def command(args, **kwargs):
    kwargs.setdefault("timeout", 900)
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
            copy_sources(root)
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
            # Double quotes are valid Git ref characters but invalid in
            # Windows paths, so keep this case portable while still checking
            # semicolon handling on Windows.
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


def main() -> None:
    global OPTIONS
    OPTIONS = parse_options()
    sys.argv[:] = [sys.argv[0]]
    unittest.main(verbosity=2)


if __name__ == "__main__":
    main()
