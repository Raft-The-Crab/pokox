#!/usr/bin/env python3
"""Compare deterministic generated integer expressions to a Python oracle."""
from pathlib import Path
import random
import subprocess
import sys
import tempfile
rng=random.Random(0x4d555433)
def make(depth):
    if depth==0 or rng.randrange(4)==0:
        n=rng.randrange(-100,101)
        return str(n),n
    for _ in range(100):
        left,a=make(depth-1); right,b=make(depth-1)
        op=rng.choice('+-*/%')
        if op in '/%' and b==0: continue
        if op=='+': value=a+b
        elif op=='-': value=a-b
        elif op=='*': value=a*b
        else:
            quotient=(abs(a)//abs(b))*(-1 if (a<0)!=(b<0) else 1)
            value=quotient if op=='/' else a-quotient*b
        if -(1<<31)<=value<(1<<31):
            return '('+left+') '+op+' ('+right+')',value
    return '0',0
with tempfile.TemporaryDirectory(prefix='poko evaluator reference ') as directory:
    source=Path(directory)/'input.expr'
    for _ in range(600):
        expression,expected=make(4)
        source.write_bytes(expression.encode('ascii'))
        actual=subprocess.run([sys.argv[1],str(source)],capture_output=True)
        wanted=f'value i32 {expected}\n'.encode('ascii')
        if actual.returncode or actual.stdout!=wanted:
            raise SystemExit(f'{expression!r}: expected {wanted!r}, got {actual.stdout!r}, exit {actual.returncode}')
# Independently exercise width boundaries and signed/unsigned overflow.
with tempfile.TemporaryDirectory(prefix='poko evaluator widths ') as directory:
    source=Path(directory)/'input.expr'
    for _ in range(500):
        signed=rng.choice([True,False]); bits=rng.choice([8,16,32,64])
        suffix=('i' if signed else 'u')+str(bits)
        minimum=-(1<<(bits-1)) if signed else 0
        maximum=(1<<(bits-1))-1 if signed else (1<<bits)-1
        edges=[minimum,min(minimum+1,maximum),0,1,maximum-1,maximum]
        a=rng.choice(edges) if rng.randrange(2) else rng.randint(minimum,maximum)
        b=rng.choice(edges) if rng.randrange(2) else rng.randint(minimum,maximum)
        op=rng.choice('+-*/%')
        expression=f'{a}{suffix} {op} {b}'
        if op in '/%' and b==0: error='divide_by_zero'; value=None
        elif op in '/%' and signed and a==minimum and b==-1: error='arithmetic_overflow'; value=None
        else:
            if op=='+': value=a+b
            elif op=='-': value=a-b
            elif op=='*': value=a*b
            else:
                quotient=(abs(a)//abs(b))*(-1 if (a<0)!=(b<0) else 1)
                value=quotient if op=='/' else a-quotient*b
            error='arithmetic_overflow' if not minimum<=value<=maximum else None
        source.write_bytes(expression.encode('ascii'))
        result=subprocess.run([sys.argv[1],str(source)],capture_output=True)
        if error:
            expected_prefix=f'eval {error} '.encode('ascii')
            if result.returncode!=1 or not result.stdout.startswith(expected_prefix):
                raise SystemExit(f'{expression}: expected {error}, got {result.stdout!r}, exit {result.returncode}')
        else:
            wanted=f'value {suffix} {value}\n'.encode('ascii')
            if result.returncode or result.stdout!=wanted:
                raise SystemExit(f'{expression}: expected {wanted!r}, got {result.stdout!r}, exit {result.returncode}')
# Compare bounded f32/f64 operations with explicit IEEE binary bit patterns.
import struct
import math
with tempfile.TemporaryDirectory(prefix='poko evaluator floats ') as directory:
    source=Path(directory)/'input.expr'
    for _ in range(400):
        width=rng.choice([32,64]); a=rng.randint(-4000,4000)/4; b=rng.randint(-4000,4000)/4
        op=rng.choice('+-*/%')
        if op in '/%' and b==0: b=0.25
        value={'+':lambda:a+b,'-':lambda:a-b,'*':lambda:a*b,'/':lambda:a/b,'%':lambda:math.fmod(a,b)}[op]()
        if width==32:
            bits=struct.unpack('>I',struct.pack('>f',value))[0]
            suffix='f32'; hexbits=f'{bits:08x}'
        else:
            bits=struct.unpack('>Q',struct.pack('>d',value))[0]
            suffix='f64'; hexbits=f'{bits:016x}'
        expression=f'{a:.2f}{suffix} {op} {b:.2f}{suffix}'
        source.write_bytes(expression.encode('ascii'))
        result=subprocess.run([sys.argv[1],str(source)],capture_output=True)
        wanted=f'value {suffix} 0x{hexbits}\n'.encode('ascii')
        if result.returncode or result.stdout!=wanted:
            raise SystemExit(f'{expression}: expected {wanted!r}, got {result.stdout!r}, exit {result.returncode}')
