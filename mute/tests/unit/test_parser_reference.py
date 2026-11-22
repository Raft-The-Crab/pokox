#!/usr/bin/env python3
"""Differential-test against an independent, small recursive grammar."""
import random
import re
import subprocess
import sys

rng = random.Random(0x6d7574)

def expression(depth):
    if depth == 0 or rng.randrange(5) == 0:
        return str(rng.randrange(1000))
    if rng.randrange(4) == 0:
        return rng.choice('+-') + expression(depth - 1)
    if rng.randrange(4) == 0:
        return '(' + expression(depth - 1) + ')'
    return expression(depth - 1) + ' ' + rng.choice('+-*/%') + ' ' + expression(depth - 1)

def reference(source):
    tokens = re.findall(r'\d+|[()+*/%\-]', source.replace(' ', ''))
    index = 0
    def primary():
        nonlocal index
        token = tokens[index]
        index += 1
        if token in '+-':
            return '(unary ' + token + ' ' + primary() + ')'
        if token == '(':
            value = add()
            if tokens[index] != ')':
                raise AssertionError(source)
            index += 1
            return value
        if token.isdigit():
            return '(integer "' + token + '")'
        raise AssertionError(source)
    def mul():
        nonlocal index
        lhs = primary()
        while index < len(tokens) and tokens[index] in ('*', '/', '%'):
            op = tokens[index]
            index += 1
            lhs = '(binary ' + op + ' ' + lhs + ' ' + primary() + ')'
        return lhs
    def add():
        nonlocal index
        lhs = mul()
        while index < len(tokens) and tokens[index] in ('+', '-'):
            op = tokens[index]
            index += 1
            lhs = '(binary ' + op + ' ' + lhs + ' ' + mul() + ')'
        return lhs
    tree = add()
    if index != len(tokens):
        raise AssertionError(source)
    return (tree + '\n').encode('ascii')

# The driver takes a file to match the golden test's I/O contract.
import pathlib
import tempfile
with tempfile.TemporaryDirectory(prefix='poko parser reference ') as directory:
    source_file = pathlib.Path(directory) / 'input.expr'
    for _ in range(500):
        source = expression(4)
        expected = reference(source)
        source_file.write_bytes(source.encode('ascii'))
        result = subprocess.run([sys.argv[1], str(source_file)], capture_output=True)
        if result.returncode != 0 or result.stdout != expected:
            raise SystemExit(f'{source!r}: expected={expected!r} got={result.stdout!r} exit={result.returncode}')
