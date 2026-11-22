#!/usr/bin/env python3
"""Compare this build's sin/cos raw bits on x64 and another target.

The second executable may run under an emulator. This checks bit agreement,
not accuracy, physical-device provenance, floating-point flags, or G1/G2.
"""
import argparse
import json
from pathlib import Path
import random
import subprocess

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--x64',required=True)
p.add_argument('--other',required=True)
p.add_argument('--runner',help='optional emulator executable for the other target')
a=p.parse_args()
root=Path(__file__).resolve().parents[1]
corpus=json.loads((root/'tools'/'math_determinism_corpus.json').read_text())
reference=json.loads((root/'tests'/'fixtures'/'math_reference.json').read_text())['vectors']
rng=random.Random(0x4d55542d3039)
values=[int(v['input'],16) for v in corpus]+[int(v['input'],16) for v in reference]+[rng.getrandbits(64) for _ in range(20000)]
inputs=''.join(f'{v:016x}\n' for v in values)
def run(command):
    output=subprocess.run(command,input=inputs,text=True,capture_output=True,check=True,timeout=120).stdout.splitlines()
    if len(output)!=len(values): raise ValueError('wrong output count')
    return output
first=run([a.x64])
second=run(([a.runner] if a.runner else [])+[a.other])
for i,(x,y) in enumerate(zip(first,second)):
    if x!=y: raise SystemExit(f'mismatch at {i}, input {values[i]:016x}: {x} != {y}')
print(f'{len(values)} inputs, sin and cos both bit-identical; independent device evidence remains necessary.')
