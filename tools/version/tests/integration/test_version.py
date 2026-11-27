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
SOURCE_TREES = ("engine", "mute", "server/identity", "server/net", "server/authority", "server/matchmaker", "tools/version/cmake")
COPY_IGNORE = shutil.ignore_patterns(
    ".git", "__pycache__", "*.py[cod]", "build-*", "artifacts", "graphify-out",
    ".workbuddy-ai", ".serena", "*.exe", "*.lib", "*.obj", "*.pdb", "*.apk")


def parse_options() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cmake", required=True)
    parser.add_argument("--git", required=True)
    parser.add_argument("--generator", required=True)
    parser.add_argument("--platform", default="")
    parser.add_argument("--cxx-compiler", default="")
    parser.add_argument("--make-program", default="")
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


def build_env() -> dict[str, str]:
    env = os.environ.copy()
    if os.name == "nt" and OPTIONS.cxx_compiler:
        compiler = Path(OPTIONS.cxx_compiler)
        if compiler.name.lower() == "cl.exe" and compiler.is_file():
            bin_dir = str(compiler.parent)
            if bin_dir.lower() not in env.get("PATH", "").lower():
                env["PATH"] = bin_dir + os.pathsep + env.get("PATH", "")
            # Populate PATH (Windows SDK bin for rc.exe), INCLUDE, LIB when ctest runs outside msvcenv.bat.
            sdk_root = Path(r"C:\Program Files (x86)\Windows Kits\10")
            sdk_inc = sdk_root / "Include"
            sdk_lib = sdk_root / "Lib"
            sdk_ver = ""
            if sdk_inc.is_dir():
                versions = sorted((p.name for p in sdk_inc.iterdir() if p.is_dir()), reverse=True)
                if versions:
                    sdk_ver = versions[0]
            if sdk_ver:
                sdk_bin = str(sdk_root / "bin" / sdk_ver / "x64")
                if sdk_bin.lower() not in env.get("PATH", "").lower():
                    env["PATH"] = sdk_bin + os.pathsep + env.get("PATH", "")
            if not env.get("INCLUDE") or not env.get("LIB"):
                msvc_root = compiler.parents[3]
                if not env.get("INCLUDE"):
                    includes = [str(msvc_root / "include")]
                    if sdk_ver:
                        includes += [
                            str(sdk_inc / sdk_ver / sub)
                            for sub in ("ucrt", "um", "shared", "winrt")
                        ]
                    env["INCLUDE"] = os.pathsep.join(includes)
                if not env.get("LIB"):
                    libs = [str(msvc_root / "lib" / "x64")]
                    if sdk_ver:
                        libs += [
                            str(sdk_lib / sdk_ver / sub / "x64")
                            for sub in ("ucrt", "um")
                        ]
                    env["LIB"] = os.pathsep.join(libs)
    return env


def command(args, **kwargs):
    kwargs.setdefault("timeout", 900)
    kwargs.setdefault("env", build_env())
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
                         "-DPOKO_WITH_DEPENDENCIES=OFF", "-DCMAKE_BUILD_TYPE=Debug",
                         "-DCMAKE_CXX_STANDARD=20"]
            if OPTIONS.platform:
                configure += ["-A", OPTIONS.platform]
            if OPTIONS.cxx_compiler:
                configure += [f"-DCMAKE_CXX_COMPILER={OPTIONS.cxx_compiler}"]
            if OPTIONS.make_program:
                configure += [f"-DCMAKE_MAKE_PROGRAM={OPTIONS.make_program}"]
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
