#!/usr/bin/env python3
"""Run the Windows 11 and physical Android arm64 test legs concurrently.

The runner builds the existing MSVC/Ninja tree, cross-compiles a small Mute
binary set with the pinned Android NDK, executes both legs in parallel, and
compares the approved G1 10,000-tick trace byte-for-byte after LF
normalization. Linux is not a gate target (owner decision 2026-11-25).
"""
from __future__ import annotations

import argparse
import concurrent.futures
import datetime as dt
import hashlib
import json
import os
import pathlib
import re
import shutil
import subprocess
import sys
import time
from typing import Any

EXPECTED_G1_SHA256 = "a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68"
EXPECTED_G1_TICKS = 10000
# Legacy Mute tests pass silently; newer tests must print a PASS marker.
SILENT_ANDROID_TESTS = {
    "state_test", "program_test", "evaluator_test", "bytecode_vm_test", "snapshot_test"
}

MUTE_COMMON_SOURCES = [
    "mute/src/program/program.cpp",
    "mute/src/bytecode/bytecode.cpp",
    "mute/src/vm/register_vm.cpp",
    "mute/src/vm/vm_core.cpp",
    "mute/src/vm/debugger.cpp",
    "mute/src/vm/hostcall.cpp",
    "mute/src/state/state.cpp",
    "mute/src/state/state_snapshot.cpp",
    "mute/src/pkb/pkb_draft.cpp",
    "mute/src/evaluator/evaluator.cpp",
    "mute/src/parser/parser.cpp",
    "mute/src/parser/statement.cpp",
    "mute/src/parser/declaration.cpp",
    "mute/src/lexer/lexer.cpp",
]
MUTE_INPUT_SOURCES = [
    "mute/src/input/input_snapshot.cpp",
    "mute/src/input/device_router.cpp",
    "mute/src/input/action_map.cpp",
    "engine/foundation/src/loop.cpp",
]
MUTE_STDLIB_SOURCES = [
    "mute/src/stdlib/stdlib_math.cpp",
    "mute/src/stdlib/stdlib_string.cpp",
    "mute/src/stdlib/stdlib_collections.cpp",
    "mute/src/stdlib/stdlib_crypto.cpp",
    "mute/src/stdlib/events.cpp",
]
ANDROID_TESTS = [
    ("state_test", "mute/tests/unit/state_test.cpp", [], []),
    ("program_test", "mute/tests/unit/program_test.cpp", [], []),
    ("evaluator_test", "mute/tests/unit/evaluator_test.cpp", [], []),
    ("bytecode_vm_test", "mute/tests/unit/bytecode_vm_test.cpp", [], []),
    ("snapshot_test", "mute/tests/unit/state_snapshot_test.cpp", [], []),
    ("input_snapshot_test", "mute/tests/unit/input_snapshot_test.cpp", MUTE_INPUT_SOURCES, []),
    ("action_map_test", "mute/tests/unit/action_map_test.cpp", MUTE_INPUT_SOURCES, []),
    ("device_router_test", "mute/tests/unit/device_router_test.cpp", MUTE_INPUT_SOURCES, []),
    ("stdlib_math_test", "mute/tests/unit/stdlib_math_test.cpp", MUTE_STDLIB_SOURCES, []),
    ("stdlib_collections_test", "mute/tests/unit/stdlib_collections_test.cpp", MUTE_STDLIB_SOURCES, []),
    ("stdlib_crypto_test", "mute/tests/unit/stdlib_crypto_test.cpp", MUTE_STDLIB_SOURCES, []),
    ("events_test", "mute/tests/unit/events_test.cpp", MUTE_STDLIB_SOURCES, []),
]


def now() -> str:
    return dt.datetime.now().astimezone().isoformat(timespec="seconds")


def write_log(path: pathlib.Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8", errors="replace")


def run_command(cmd: list[str], *, cwd: pathlib.Path | None = None,
                env: dict[str, str] | None = None, timeout: int = 900,
                log: pathlib.Path | None = None, text: bool = True) -> dict[str, Any]:
    started = time.time()
    try:
        proc = subprocess.run(cmd, cwd=str(cwd) if cwd else None, env=env,
                              capture_output=True, timeout=timeout, text=text)
        out, err, code = proc.stdout, proc.stderr, proc.returncode
    except subprocess.TimeoutExpired as exc:
        out, err, code = exc.stdout or "", exc.stderr or "", 124
    except OSError as exc:
        out, err, code = "", f"{type(exc).__name__}: {exc}", 127
    if log is not None:
        write_log(log, f"$ {' '.join(cmd)}\n\n--- stdout ---\n{out}\n\n--- stderr ---\n{err}\n")
    if isinstance(out, bytes):
        out = out.decode("utf-8", errors="replace")
    if isinstance(err, bytes):
        err = err.decode("utf-8", errors="replace")
    return {"command": cmd, "exit_code": code, "seconds": round(time.time() - started, 2),
            "stdout": out, "stderr": err}


def normalize_lf(data: str) -> bytes:
    return data.replace("\r\n", "\n").encode("utf-8")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def msvc_tools() -> tuple[pathlib.Path, pathlib.Path, pathlib.Path, dict[str, str]]:
    local = pathlib.Path(os.environ.get("LOCALAPPDATA", r"C:\Users\mysti.LAPTOP.000\AppData\Local"))
    tools = pathlib.Path(os.environ.get("POKO_TOOLS_DIR", str(local / "Microsoft" / "WinGet" / "Links")))
    cmake = pathlib.Path(os.environ.get("POKO_CMAKE", str(tools / "cmake.exe")))
    ctest = pathlib.Path(os.environ.get("POKO_CTEST", str(tools / "ctest.exe")))
    ninja = pathlib.Path(os.environ.get(
        "POKO_NINJA",
        str(local / "Microsoft" / "WinGet" / "Packages"
            / "Ninja-build.Ninja_Microsoft.Winget.Source_8wekyb3d8bbwe" / "ninja.exe")))
    msvc = pathlib.Path(os.environ.get("POKO_MSVC", r"C:\BuildTools\VC\Tools\MSVC\14.44.35207"))
    sdk = pathlib.Path(os.environ.get("POKO_SDK", r"C:\Program Files (x86)\Windows Kits\10"))
    sdkv = os.environ.get("POKO_SDKV", "10.0.26100.0")
    required = (cmake, ctest, ninja, msvc / "bin" / "Hostx64" / "x64" / "cl.exe",
                sdk / "bin" / sdkv / "x64")
    missing = [str(p) for p in required if not p.exists()]
    if missing:
        raise SystemExit("Missing Windows build tools: " + "; ".join(missing))
    env = dict(os.environ)
    env["PATH"] = ";".join([str(msvc / "bin" / "Hostx64" / "x64"),
                            str(sdk / "bin" / sdkv / "x64"), str(tools), env.get("PATH", "")])
    env["INCLUDE"] = ";".join([str(msvc / "include"),
                               *(str(sdk / "Include" / sdkv / part)
                                 for part in ("ucrt", "um", "shared", "winrt"))])
    env["LIB"] = ";".join([str(msvc / "lib" / "x64"),
                           str(sdk / "Lib" / sdkv / "ucrt" / "x64"),
                           str(sdk / "Lib" / sdkv / "um" / "x64")])
    env["LIBPATH"] = env["LIB"]
    return cmake, ctest, ninja, env


def android_tools(sdk_root: pathlib.Path) -> tuple[pathlib.Path, pathlib.Path, pathlib.Path]:
    ndk_root = pathlib.Path(os.environ.get("POKO_NDK", str(sdk_root / "ndk-bundle")))
    props = ndk_root / "source.properties"
    revision = props.read_text(encoding="utf-8", errors="replace") if props.is_file() else ""
    if not re.search(r"Pkg\.Revision\s*=\s*22\.", revision):
        raise SystemExit(f"Expected pinned NDK r22 in {props}; update the shim before using a newer NDK")
    ndk_prebuilt = ndk_root / "toolchains" / "llvm" / "prebuilt"
    bins = sorted(p for p in ndk_prebuilt.glob("*/bin") if p.is_dir())
    if not bins:
        raise SystemExit(f"No NDK toolchain bin directory under {ndk_prebuilt}")
    clangxx = bins[0] / "clang++.exe"
    adb = pathlib.Path(os.environ.get("POKO_ADB", str(sdk_root / "platform-tools" / "adb.exe")))
    if not clangxx.exists() or not adb.exists():
        raise SystemExit(f"Missing Android tools: {clangxx} / {adb}")
    return clangxx, adb, bins[0]


def windows_leg(repo: pathlib.Path, build: pathlib.Path, out: pathlib.Path,
                ticks: int, run_ctest: bool, build_sources: bool) -> dict[str, Any]:
    cmake, ctest, ninja, env = msvc_tools()
    log_dir = out / "logs"
    result: dict[str, Any] = {"target": "windows-x64-msvc", "started": now(), "steps": {}}
    if build_sources:
        configure = run_command(
            [str(cmake), "-S", str(repo), "-B", str(build), "-G", "Ninja",
             "-DCMAKE_BUILD_TYPE=Debug", "-DCMAKE_CXX_STANDARD=20",
             f"-DCMAKE_MAKE_PROGRAM={ninja}"],
            env=env, log=log_dir / "windows-configure.log", timeout=600)
        result["steps"]["configure"] = configure
        if configure["exit_code"] != 0:
            result["finished"] = now()
            return result
        build_step = run_command([str(cmake), "--build", str(build), "-j", "12"],
                                 env=env, log=log_dir / "windows-build.log", timeout=1800)
        result["steps"]["build"] = build_step
        if build_step["exit_code"] != 0:
            result["finished"] = now()
            return result
    if run_ctest:
        result["steps"]["ctest"] = run_command(
            [str(ctest), "--test-dir", str(build), "-j", "12", "--output-on-failure",
             "--no-tests=error"],
            env=env, log=log_dir / "windows-ctest.log", timeout=1800)
    probe = build / "poko_mute_g1_replay_probe.exe"
    fixture = repo / "mute" / "tests" / "fixtures" / "g1-replay.mute"
    trace = run_command([str(probe), str(fixture), str(ticks)], env=env,
                        log=log_dir / "windows-g1-probe.log", timeout=300)
    result["steps"]["g1_probe"] = {k: v for k, v in trace.items() if k != "stdout"}
    trace_lf = normalize_lf(trace["stdout"])
    (out / "g1-windows.trace").write_bytes(trace_lf)
    result["g1"] = {"lines": trace_lf.count(b"\n"), "sha256": sha256(trace_lf),
                    "exit_code": trace["exit_code"]}
    result["finished"] = now()
    return result


def adb_shell(adb: pathlib.Path, command: str, timeout: int = 300) -> dict[str, Any]:
    # Older adb versions return 0 even when the remote command fails. Append an
    # explicit marker so the report records the remote status, not adb's own.
    wrapped = command + "; printf '\\n__POKO_EXIT__:%d\\n' \"$?\""
    step = run_command([str(adb), "shell", wrapped], timeout=timeout)
    match = re.search(r"__POKO_EXIT__:(\d+)\s*$", step["stdout"])
    if match:
        step["remote_exit_code"] = int(match.group(1))
        step["exit_code"] = int(match.group(1))
        prefix = step["stdout"][:match.start()]
        step["stdout"] = prefix.rstrip("\n") + "\n" if prefix.strip() else ""
    return step


def android_compile(clangxx: pathlib.Path, repo: pathlib.Path, out: pathlib.Path,
                    shim: pathlib.Path) -> tuple[dict[str, Any], dict[str, pathlib.Path]]:
    obj_dir = out / "android" / "obj"
    bin_dir = out / "android" / "bin"
    obj_dir.mkdir(parents=True, exist_ok=True)
    bin_dir.mkdir(parents=True, exist_ok=True)
    log_dir = out / "logs"
    base = ["--target=aarch64-linux-android30", "-std=c++20", "-O2",
            "-fno-fast-math", "-ffp-contract=off",
            "-DPOKO_MUTE_FP_FLAGS_CONFIGURED=1", "-include", str(shim),
            f"-I{repo / 'mute' / 'include'}", f"-I{repo / 'engine' / 'foundation' / 'include'}"]
    key_source = "\n".join(base) + "\n" + shim.read_text(encoding="utf-8", errors="replace")
    for source in MUTE_COMMON_SOURCES + MUTE_INPUT_SOURCES + MUTE_STDLIB_SOURCES:
        key_source += "\n" + (repo / source).read_text(encoding="utf-8", errors="replace")
    build_key = sha256(key_source.encode("utf-8", errors="replace"))
    key_path = obj_dir / "build-key.txt"
    force_rebuild = not key_path.is_file() or key_path.read_text(encoding="utf-8") != build_key
    objects: dict[str, pathlib.Path] = {}
    failures: list[dict[str, Any]] = []
    for source in MUTE_COMMON_SOURCES + MUTE_INPUT_SOURCES + MUTE_STDLIB_SOURCES:
        src = repo / source
        obj = obj_dir / (source.replace("/", "_").replace(".cpp", ".o"))
        objects[source] = obj
        if not force_rebuild and obj.exists() and obj.stat().st_mtime >= src.stat().st_mtime:
            continue
        step = run_command([str(clangxx), *base, "-c", str(src), "-o", str(obj)],
                           log=log_dir / f"android-obj-{obj.stem}.log", timeout=900)
        if step["exit_code"] != 0:
            failures.append({"source": source, **step})
    executables: dict[str, pathlib.Path] = {}
    targets = [("g1_replay_probe", "mute/tools/g1_replay_probe.cpp", [], [])] + ANDROID_TESTS
    for name, main_source, extra, _ in targets:
        exe = bin_dir / name
        executables[name] = exe
        objs = [obj_dir / (s.replace("/", "_").replace(".cpp", ".o"))
                for s in MUTE_COMMON_SOURCES]
        if extra:
            objs += [obj_dir / (s.replace("/", "_").replace(".cpp", ".o")) for s in extra]
        main = repo / main_source
        dependencies = [main, *objs]
        if not force_rebuild and exe.exists() and exe.stat().st_mtime >= max(p.stat().st_mtime for p in dependencies):
            continue
        step = run_command([str(clangxx), *base, str(main), *[str(o) for o in objs],
                            "-static-libstdc++", "-o", str(exe)],
                           log=log_dir / f"android-link-{name}.log", timeout=600)
        if step["exit_code"] != 0:
            failures.append({"target": name, **step})
    if not failures:
        key_path.write_text(build_key, encoding="utf-8")
    return ({"failures": failures,
             "objects": sum(1 for p in objects.values() if p.exists()),
             "executables": sum(1 for p in executables.values() if p.exists())}, executables)


def android_leg(repo: pathlib.Path, sdk_root: pathlib.Path, out: pathlib.Path,
                ticks: int) -> dict[str, Any]:
    clangxx, adb, _ = android_tools(sdk_root)
    shim = repo / "tools" / "targets" / "android_std_shim.hpp"
    remote = "/data/local/tmp/poko-dual-target"
    log_dir = out / "logs"
    result: dict[str, Any] = {"target": "android-arm64-physical", "started": now(), "steps": {}}
    state = run_command([str(adb), "get-state"], timeout=60)
    result["steps"]["adb_state"] = state
    if state["stdout"].strip() != "device":
        result["finished"] = now()
        return result
    props = adb_shell(adb, "getprop ro.product.model; getprop ro.build.version.release; "
                           "getprop ro.build.version.sdk; uname -m; getprop ro.kernel.qemu")
    device_lines = props["stdout"].strip().splitlines()
    result["device"] = device_lines
    result["steps"]["device_props"] = props
    if len(device_lines) < 4 or device_lines[3] != "aarch64" or (
            len(device_lines) >= 5 and device_lines[4] == "1"):
        result["error"] = "Expected a physical aarch64 device, not an emulator"
        result["finished"] = now()
        return result
    result["steps"]["mkdir"] = adb_shell(adb, f"mkdir -p {remote}")
    compile_info, executables = android_compile(clangxx, repo, out, shim)
    result["steps"]["compile"] = compile_info
    if compile_info["failures"]:
        result["finished"] = now()
        return result
    for name, exe in executables.items():
        push = run_command([str(adb), "push", str(exe), f"{remote}/{name}"],
                           log=log_dir / f"android-push-{name}.log", timeout=300)
        if push["exit_code"] != 0:
            result["steps"][f"push_{name}"] = push
            result["finished"] = now()
            return result
    fixture = repo / "mute" / "tests" / "fixtures" / "g1-replay.mute"
    push = run_command([str(adb), "push", str(fixture), f"{remote}/g1-replay.mute"],
                       log=log_dir / "android-push-fixture.log", timeout=300)
    result["steps"]["push_fixture"] = {k: v for k, v in push.items() if k != "stdout"}
    chmod = adb_shell(adb, "chmod 755 " + " ".join(f"{remote}/{n}" for n in executables))
    result["steps"]["chmod"] = chmod
    for name, _, _, args in ANDROID_TESTS:
        command = f"{remote}/{name}" + (" " + " ".join(args) if args else "")
        step = adb_shell(adb, command)
        result["steps"][f"test_{name}"] = {"exit_code": step["exit_code"],
                                           "stdout": step["stdout"].strip(),
                                           "stderr": step["stderr"].strip()}
    probe = adb_shell(adb, f"{remote}/g1_replay_probe {remote}/g1-replay.mute {ticks} "
                           f"> {remote}/g1.trace", timeout=300)
    result["steps"]["g1_probe"] = {"exit_code": probe["exit_code"],
                                   "stderr": probe["stderr"].strip()}
    trace = adb_shell(adb, f"cat {remote}/g1.trace", timeout=300)
    result["steps"]["g1_cat"] = {k: v for k, v in trace.items() if k != "stdout"}
    trace_lf = normalize_lf(trace["stdout"])
    (out / "g1-android.trace").write_bytes(trace_lf)
    result["g1"] = {"lines": trace_lf.count(b"\n"), "sha256": sha256(trace_lf),
                    "exit_code": probe["exit_code"] if trace["exit_code"] == 0 else trace["exit_code"]}
    result["finished"] = now()
    return result


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--repo", type=pathlib.Path,
                        default=pathlib.Path(__file__).resolve().parents[2])
    parser.add_argument("--android-sdk", type=pathlib.Path, default=pathlib.Path(r"C:\Android"))
    parser.add_argument("--windows-build", type=pathlib.Path, default=None)
    parser.add_argument("--out", type=pathlib.Path, default=None)
    parser.add_argument("--ticks", type=int, default=10000)
    parser.add_argument("--skip-ctest", action="store_true")
    parser.add_argument("--skip-build", action="store_true")
    parser.add_argument("--windows-only", action="store_true")
    parser.add_argument("--android-only", action="store_true")
    args = parser.parse_args()
    repo = args.repo.resolve()
    build = (args.windows_build or repo / "build-msvc").resolve()
    out = (args.out or repo / "artifacts" / "dual-target").resolve()
    # Clear previous-run artifacts: stale traces and binaries must never pass.
    for stale in ("g1-windows.trace", "g1-android.trace", "gate-report.json"):
        (out / stale).unlink(missing_ok=True)
    out.mkdir(parents=True, exist_ok=True)
    report: dict[str, Any] = {"started": now(), "repo": str(repo), "ticks": args.ticks,
                              "gates": {"G1": "pending", "G2": "deferred", "ENG-02": "separate"}}
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        futures = {}
        if not args.android_only:
            futures["windows"] = pool.submit(windows_leg, repo, build, out, args.ticks,
                                             not args.skip_ctest, not args.skip_build)
        if not args.windows_only:
            futures["android"] = pool.submit(android_leg, repo, args.android_sdk, out, args.ticks)
        for name, future in futures.items():
            report[name] = future.result()
    ctest_step = report.get("windows", {}).get("steps", {}).get("ctest")
    ctest_match = re.search(r"\b\d+% tests passed out of (\d+)\b", ctest_step.get("stdout", "")) if ctest_step else None
    ctest_ok = bool(ctest_step and ctest_step.get("exit_code") == 0 and
                    ctest_match and int(ctest_match.group(1)) > 0)
    android_test_steps = {k: v for k, v in report.get("android", {}).get("steps", {}).items()
                          if k.startswith("test_")}
    def android_test_ok(name: str, step: dict[str, Any]) -> bool:
        if step.get("exit_code") != 0:
            return False
        if name[len("test_"):] in SILENT_ANDROID_TESTS:
            return True
        return "pass" in step.get("stdout", "").lower()
    android_tests_ok = bool(android_test_steps) and all(
        android_test_ok(name, step) for name, step in android_test_steps.items())
    win = report.get("windows", {}).get("g1", {})
    android = report.get("android", {}).get("g1", {})
    expected_g1_sha = EXPECTED_G1_SHA256 if args.ticks == EXPECTED_G1_TICKS else None
    def leg_g1_ok(leg: dict[str, Any]) -> bool:
        return bool(leg and leg.get("exit_code") == 0 and leg.get("lines") == args.ticks and
                    (expected_g1_sha is None or leg.get("sha256") == expected_g1_sha))
    windows_ok = ctest_ok and leg_g1_ok(win)
    android_ok = android_tests_ok and leg_g1_ok(android)
    g1_comparison = None
    if win and android:
        wbytes = (out / "g1-windows.trace").read_bytes()
        abytes = (out / "g1-android.trace").read_bytes()
        match = wbytes == abytes
        g1_comparison = {"byte_identical": match, "expected_sha256": expected_g1_sha,
                         "windows_sha256": win.get("sha256"),
                         "android_sha256": android.get("sha256"),
                         "passed": bool(match and windows_ok and android_ok)}
        report["g1_comparison"] = g1_comparison
    if args.android_only:
        all_tests_ok = android_ok
    elif args.windows_only:
        all_tests_ok = windows_ok
    else:
        all_tests_ok = bool(windows_ok and android_ok and g1_comparison and g1_comparison["passed"])
    report["all_tests_ok"] = bool(all_tests_ok)
    report["gates"]["G1"] = ("accepted-evidence" if all_tests_ok and win and android
                              else "single-leg-only" if all_tests_ok else "failed")
    report["finished"] = now()
    (out / "gate-report.json").write_text(json.dumps(report, indent=2, ensure_ascii=False),
                                          encoding="utf-8")
    summary = {"report": str(out / "gate-report.json"),
               "all_tests_ok": report.get("all_tests_ok"), "g1": report.get("g1_comparison")}
    print(json.dumps(summary, indent=2))
    return 0 if report.get("all_tests_ok") else 1


if __name__ == "__main__":
    sys.exit(main())
