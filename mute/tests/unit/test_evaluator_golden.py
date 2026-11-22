#!/usr/bin/env python3
"""Exercise lexer → parser → evaluator with byte-exact result goldens."""
from pathlib import Path
import subprocess
import sys
import tempfile
root=Path(__file__).resolve().parents[3]
fixture=root/'mute/tests/fixtures/golden'
cases=[('eval_order',0),('eval_divrem',0),('eval_infer',0),('eval_i64_min',0),
       ('eval_u64_max',0),('eval_f32',0),('eval_f64',0),('eval_divzero',1),
       ('eval_overflow',1),('eval_type',1),('eval_name',1),('eval_mod_float',0),
       ('eval_lex',1),('eval_parse',1)]
with tempfile.TemporaryDirectory(prefix='poko evaluator golden ') as directory:
    actual=Path(directory)/'actual.value'
    for stem,expected_exit in cases:
        result=subprocess.run([sys.argv[1],str(fixture/(stem+'.expr'))],capture_output=True)
        if result.returncode!=expected_exit:
            raise SystemExit(f'{stem}: unexpected exit {result.returncode}: {result.stderr!r}')
        actual.write_bytes(result.stdout)
        command=[sys.executable,str(root/'tools/testutils/harness/golden.py'),'--golden',str(fixture/(stem+'.value')),'--actual',str(actual)]
        subprocess.run(command,check=True)
        actual.write_bytes(result.stdout+b'corruption\n')
        if subprocess.run(command,capture_output=True).returncode!=1:
            raise SystemExit(f'{stem}: corrupted output was not rejected')
