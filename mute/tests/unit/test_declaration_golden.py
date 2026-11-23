#!/usr/bin/env python3
"""Check v1 declaration AST and error goldens with the shared harness."""
import pathlib
import subprocess
import sys
import tempfile

root = pathlib.Path(__file__).resolve().parents[3]
fixture = root / 'mute/tests/fixtures/golden'
cases = [
    ('decl_struct', 0), ('decl_enum', 0), ('decl_types_generic', 0),
    ('decl_types_nested_generic', 0), ('decl_types_tuple', 0),
    ('decl_state', 0), ('decl_fn', 0), ('decl_fn_async', 0),
    ('decl_fn_attributes', 0), ('decl_package_import', 0),
    ('decl_missing_colon', 1), ('decl_missing_lbrace', 1),
    ('decl_missing_rbrace', 1), ('decl_deferred_attribute', 1),
    ('decl_expected_declaration', 1),
]
with tempfile.TemporaryDirectory(prefix='poko declaration golden ') as tmp:
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
