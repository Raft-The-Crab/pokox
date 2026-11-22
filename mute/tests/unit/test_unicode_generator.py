#!/usr/bin/env python3
"""Check regeneration and reject changed pinned Unicode input."""
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

root = Path(__file__).resolve().parents[2]
with tempfile.TemporaryDirectory(prefix='poko mute unicode ') as directory:
    temp = Path(directory)
    for name in ('tools/generate_unicode_xid.py', 'src/lexer/unicode_xid.hpp',
                 'data/unicode/DerivedCoreProperties-15.1.0.txt'):
        target = temp / name
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(root / name, target)
    tool = temp / 'tools/generate_unicode_xid.py'
    header = temp / 'src/lexer/unicode_xid.hpp'
    source = temp / 'data/unicode/DerivedCoreProperties-15.1.0.txt'
    original = header.read_bytes()
    def run(*args):
        return subprocess.run([sys.executable, str(tool), *args], capture_output=True)
    if run('--check').returncode != 0:
        raise SystemExit('matching checked-in table rejected')
    header.write_bytes(b'stale\n')
    if run('--check').returncode == 0:
        raise SystemExit('stale generated table was accepted')
    if run().returncode != 0 or header.read_bytes() != original:
        raise SystemExit('regeneration differed from checked-in table')
    source.write_bytes(source.read_bytes() + b'\n')
    if run('--check').returncode == 0 or run().returncode == 0:
        raise SystemExit('modified Unicode input was accepted')
    if header.read_bytes() != original:
        raise SystemExit('failed validation modified the generated table')
