#!/usr/bin/env python3
"""Regenerate the independent 312-input reference (requires mpmath==1.3.0)."""
from pathlib import Path
import json
import random
import struct
import mpmath as mp
if mp.__version__ != '1.3.0':
    raise SystemExit('requires mpmath 1.3.0')
mp.mp.dps=500
rng=random.Random(0x4d55543039)
values=[0,0x8000000000000000,1,0x8000000000000001,0x0010000000000000,
        0x3fe921fb54442d18,0x3ff0000000000000,0x3ff921fb54442d18,
        0x400921fb54442d18,0x400921fb54442d19,0x4415af1d78b58c40,0x7fefffffffffffff]
while len(values)<312:
    value=rng.getrandbits(64)
    if (value>>52)&0x7ff != 0x7ff: values.append(value)
def bits(x): return f'{struct.unpack(">Q",struct.pack(">d",x))[0]:016x}'
records=[]
for value in values:
    x=struct.unpack('>d',struct.pack('>Q',value))[0]
    if value==0x8000000000000000:
        sin_bits,cos_bits='8000000000000000','3ff0000000000000'
    else:
        y=mp.mpf(x)
        sin_bits,cos_bits=bits(float(mp.sin(y))),bits(float(mp.cos(y)))
    records.append({'input':f'{value:016x}','sin_reference':sin_bits,'cos_reference':cos_bits})
out={'reference':'mpmath 1.3.0, 500 decimal digits, rounded to binary64; tolerance 2 ULP','vectors':records}
(Path(__file__).parents[1]/'tests'/'fixtures'/'math_reference.json').write_text(json.dumps(out,indent=2)+'\n')
