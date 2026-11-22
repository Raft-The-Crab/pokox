#!/usr/bin/env python3
"""G1 replay determinism check: the probe's 10,000-tick trace must hash
identically on every target. The expected SHA-256 was recorded from verified
Windows x64 and physical Android arm64 runs; any platform producing a different
trace fails here. LF normalization only removes console newline differences.
"""
import hashlib
import pathlib
import subprocess
import sys

EXPECTED_SHA256 = 'a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68'
root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/g1-replay.mute'
probe = subprocess.run([sys.argv[1], str(fixture)], capture_output=True)
if probe.returncode != 0:
    raise SystemExit(f'g1 replay probe exited {probe.returncode}: {probe.stderr!r}')
trace = probe.stdout.replace(b'\r\n', b'\n')
lines = trace.split(b'\n')
if len(lines) != 10001 or lines[-1] != b'':
    raise SystemExit(f'expected 10,000 trace lines, got {len(lines) - 1}')
digest = hashlib.sha256(trace).hexdigest()
if digest != EXPECTED_SHA256:
    raise SystemExit(
        f'G1 trace mismatch: sha256 {digest} != {EXPECTED_SHA256}\n'
        f'first line: {lines[0]!r}\nlast line: {lines[-2]!r}')
print(f'G1 replay trace verified: {digest}')
