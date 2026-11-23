#!/usr/bin/env python3
"""Check MUT-17–20 semantic diagnostics with the shared harness."""
import pathlib
import subprocess
import sys
import tempfile

root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/golden'
cases = [
    ('semantic_ok_scalar', 0), ('semantic_ok_struct', 0),
    ('semantic_ok_generic', 0), ('semantic_ok_shadow', 0),
    ('semantic_unknown_name', 1), ('semantic_duplicate_binding', 1),
    ('semantic_duplicate_declaration', 1), ('semantic_immutable', 1),
    ('semantic_invalid_return', 1), ('semantic_wrong_arity', 1),
    ('semantic_type_mismatch', 1), ('semantic_unknown_field', 1),
    ('semantic_trait', 1), ('semantic_unknown_type', 1),
    ('semantic_generic_arity', 1),
]
with tempfile.TemporaryDirectory(prefix='poko semantic golden ') as tmp:
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
