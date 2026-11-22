#!/usr/bin/env python3
"""Exercise the project golden harness, including its mismatch path."""
import pathlib
import subprocess
import sys
import tempfile
root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/golden'
spec = (root / 'docs/plan/04-mute.md').read_text(encoding='utf-8')
example = spec.split('```', 2)[1].lstrip('\n').encode('utf-8')
if (fixture / 'spec_example.mute').read_bytes() != example:
    raise SystemExit('Mute syntax example changed; review its golden fixture')
with tempfile.TemporaryDirectory() as tmp:
    actual = pathlib.Path(tmp) / 'actual.txt'
    for stem, expected_exit in [('core', 0), ('newlines', 0), ('spec_example', 0), ('invalid', 1),
                                ('bom', 1), ('utf8_error', 1), ('escape_error', 1),
                                ('comment_error', 1), ('interpolation_error', 1)]:
        dump = subprocess.run([sys.argv[1], str(fixture / (stem + '.mute'))], capture_output=True)
        if dump.returncode != expected_exit:
            raise SystemExit(f'{stem}: unexpected exit {dump.returncode}: {dump.stderr!r}')
        actual.write_bytes(dump.stdout)
        command = [sys.executable, str(root / 'tools/testutils/harness/golden.py'), '--golden', str(fixture / (stem + '.tokens')), '--actual', str(actual)]
        subprocess.run(command, check=True)
        actual.write_bytes(dump.stdout + b'corruption\n')
        mismatch = subprocess.run(command, capture_output=True)
        if mismatch.returncode != 1:
            raise SystemExit(f'{stem}: golden harness did not detect a mismatch')
