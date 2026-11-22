import json
from pathlib import Path
import subprocess
import sys

def ordered(bits):
    n=int(bits,16)
    return (~n & 0xffffffffffffffff) if (n>>63) else n | 0x8000000000000000

fixture=json.loads((Path(__file__).parents[1]/'fixtures'/'math_reference.json').read_text())['vectors']
assert len(fixture)==312
run=subprocess.run([sys.argv[1]],input=''.join(x['input']+'\n' for x in fixture),text=True,capture_output=True,check=True)
lines=run.stdout.splitlines()
if len(lines)!=len(fixture): raise AssertionError('missing math outputs')
for row,line in zip(fixture,lines):
    actual=line.split()
    if len(actual)!=2: raise AssertionError('malformed output')
    for op,bits in zip(('sin','cos'),actual):
        expected=row[op+'_reference']
        if len(bits)!=16 or abs(ordered(bits)-ordered(expected))>2:
            raise AssertionError(f"{op}({row['input']}): {bits} vs reference {expected}")
print(f'{len(fixture)*2} independent high-precision references passed')
