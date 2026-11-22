#!/usr/bin/env python3
"""CLI validation must reject invalid light vectors before SDL initialization."""
import subprocess
import sys

exe = sys.argv[1]
for arguments in (['--light', '0', '0', '0'], ['--light', 'nan', '1', '0'],
                  ['--light', 'inf', '0', '1'], ['--light', 'x', '0', '1'],
                  ['--light', '1e99', '0', '1'], ['--light', '1', '0']):
    result = subprocess.run([exe, *arguments], capture_output=True, text=True, timeout=10)
    if result.returncode != 2 or ('--light' not in result.stderr):
        raise SystemExit(f'FAIL {arguments}: exit={result.returncode}, stderr={result.stderr!r}')
print('PASS: invalid, non-finite, zero, overflowing and incomplete directions rejected')
