#!/usr/bin/env python3
"""Compare binary64 sin/cos result traces; this does not implement math or prove accuracy.

Trace JSON: {"format":1,"implementation":"same-version-id", "target":"platform-id",
 "vectors":[{"op":"sin","input":"hex16","output":"hex16"}, ...]}.
Records must exactly match the checked-in corpus order. Outputs are raw IEEE bits,
including zero signs and NaN payloads; a future math contract must define those.
"""
import argparse
import json
from pathlib import Path
import re
import sys

CORPUS = Path(__file__).with_name('math_determinism_corpus.json')
MAX_BYTES = 128 * 1024
BITS = re.compile(r'^[0-9a-f]{16}$')


def _object(pairs):
    result = {}
    for key, value in pairs:
        if key in result:
            raise ValueError('duplicate JSON key: ' + key)
        result[key] = value
    return result


def _read(path):
    with Path(path).open('rb') as f:
        raw = f.read(MAX_BYTES + 1)
    if len(raw) > MAX_BYTES:
        raise ValueError('input exceeds size limit')
    return json.loads(raw, object_pairs_hook=_object)


def load_corpus(path=CORPUS):
    corpus = _read(path)
    if not isinstance(corpus, list) or len(corpus) != 36:
        raise ValueError('invalid corpus size')
    seen = set()
    for entry in corpus:
        if not isinstance(entry, dict) or set(entry) != {'op', 'input'}:
            raise ValueError('invalid corpus entry')
        op, bits = entry['op'], entry['input']
        if op not in ('sin', 'cos') or not isinstance(bits, str) or not BITS.fullmatch(bits):
            raise ValueError('invalid corpus case')
        if (op, bits) in seen:
            raise ValueError('duplicate corpus case')
        seen.add((op, bits))
    if {bits for op, bits in seen if op == 'sin'} != {bits for op, bits in seen if op == 'cos'}:
        raise ValueError('sin/cos corpus differs')
    return corpus


def load_trace(path, corpus):
    trace = _read(path)
    if not isinstance(trace, dict) or set(trace) != {'format', 'implementation', 'target', 'vectors'}:
        raise ValueError('invalid trace schema')
    if type(trace['format']) is not int or trace['format'] != 1:
        raise ValueError('unsupported trace format')
    for key in ('implementation', 'target'):
        if not isinstance(trace[key], str) or not trace[key].strip() or len(trace[key]) > 128:
            raise ValueError('invalid ' + key)
    vectors = trace['vectors']
    if not isinstance(vectors, list) or len(vectors) != len(corpus):
        raise ValueError('missing or extra vectors')
    for entry, wanted in zip(vectors, corpus):
        if not isinstance(entry, dict) or set(entry) != {'op', 'input', 'output'}:
            raise ValueError('invalid vector schema')
        if (entry['op'], entry['input']) != (wanted['op'], wanted['input']):
            raise ValueError('corpus mismatch or reordering')
        if not isinstance(entry['output'], str) or not BITS.fullmatch(entry['output']):
            raise ValueError('invalid output bits')
    return trace


def compare(left, right, corpus):
    a, b = load_trace(left, corpus), load_trace(right, corpus)
    if a['implementation'] != b['implementation']:
        raise ValueError('implementation versions differ')
    if a['target'] == b['target']:
        raise ValueError('target labels must differ')
    for i, (x, y) in enumerate(zip(a['vectors'], b['vectors'])):
        if x['output'] != y['output']:
            raise ValueError(f"mismatch at {i}: {x['op']}({x['input']}): {x['output']} != {y['output']}")
    return len(corpus)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('left', type=Path)
    parser.add_argument('right', type=Path)
    args = parser.parse_args()
    try:
        if args.left.resolve() == args.right.resolve() or args.left.samefile(args.right):
            raise ValueError('two independent trace files are required')
        corpus = load_corpus()
        count = compare(args.left, args.right, corpus)
    except (ValueError, OSError, UnicodeError, RecursionError) as exc:
        print('comparison failed:', exc, file=sys.stderr)
        return 1
    print(f'{count} vectors match bit-for-bit; accuracy and target provenance require separate evidence.')
    return 0

if __name__ == '__main__':
    sys.exit(main())
