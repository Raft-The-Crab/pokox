#!/usr/bin/env python3
"""Check arithmetic AST and error goldens with the shared harness."""
import pathlib
import subprocess
import sys
import tempfile

root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/golden'
cases = [('arithmetic_precedence', 0), ('arithmetic_unary', 0),
         ('arithmetic_left_assoc', 0), ('arithmetic_missing_operand', 1),
         ('arithmetic_missing_close', 1), ('arithmetic_extra_close', 1),
         ('arithmetic_extra_token', 1), ('arithmetic_lex_error', 1),
         ('arithmetic_invalid_utf8', 1)]
with tempfile.TemporaryDirectory(prefix='poko parser golden ') as tmp:
    actual = pathlib.Path(tmp) / 'actual.ast'
    for stem, expected_exit in cases:
        result = subprocess.run([sys.argv[1], str(fixture / (stem + '.expr'))], capture_output=True)
        if result.returncode != expected_exit:
            raise SystemExit(f'{stem}: exit {result.returncode}; stderr={result.stderr!r}')
        actual.write_bytes(result.stdout)
        command = [sys.executable, str(root / 'tools/testutils/harness/golden.py'),
                   '--golden', str(fixture / (stem + '.ast')), '--actual', str(actual)]
        subprocess.run(command, check=True)
        actual.write_bytes(result.stdout + b'corruption\n')
        if subprocess.run(command, capture_output=True).returncode != 1:
            raise SystemExit(f'{stem}: golden harness did not detect corruption')
