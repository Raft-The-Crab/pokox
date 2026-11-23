#!/usr/bin/env python3
"""Check v1 statement AST and error goldens with the shared harness."""
import pathlib
import subprocess
import sys
import tempfile

root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/golden'
cases = [
    ('statement_decl_assign', 0), ('statement_if_else', 0), ('statement_else_if', 0), ('statement_while', 0),
    ('statement_for_in', 0), ('statement_loop_break', 0), ('statement_while_continue', 0),
    ('statement_match', 0), ('statement_guard', 0), ('statement_return_empty', 0),
    ('statement_break_outside', 1), ('statement_continue_outside', 1),
    ('statement_missing_lbrace', 1), ('statement_missing_semicolon', 1),
    ('statement_missing_rbrace', 1), ('statement_for_missing_in', 1),
    ('statement_match_missing_arrow', 1),
]
with tempfile.TemporaryDirectory(prefix='poko statement golden ') as tmp:
    actual = pathlib.Path(tmp) / 'actual.ast'
    for stem, expected_exit in cases:
        result = subprocess.run([sys.argv[1], str(fixture / (stem + '.mute'))], capture_output=True)
        if result.returncode != expected_exit:
            raise SystemExit(f'{stem}: exit {result.returncode}; stdout={result.stdout!r}; stderr={result.stderr!r}')
        actual.write_bytes(result.stdout)
        command = [sys.executable, str(root / 'tools/testutils/harness/golden.py'),
                   '--golden', str(fixture / (stem + '.ast')), '--actual', str(actual)]
        subprocess.run(command, check=True)
        actual.write_bytes(result.stdout + b'corruption\n')
        if subprocess.run(command, capture_output=True).returncode != 1:
            raise SystemExit(f'{stem}: golden harness did not detect corruption')
