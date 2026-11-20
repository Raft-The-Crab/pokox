#!/usr/bin/env python3
"""Compare binary files exactly or explicitly update a golden reference."""
from __future__ import annotations

import argparse
import os
from pathlib import Path
import shutil
import sys
import tempfile
import unittest

CHUNK_SIZE = 64 * 1024


def first_difference(golden: Path, actual: Path):
    """Return the first differing offset and sizes, or None if files match."""
    with golden.open("rb") as expected, actual.open("rb") as observed:
        expected_size = os.fstat(expected.fileno()).st_size
        actual_size = os.fstat(observed.fileno()).st_size
        offset = 0
        while True:
            left = expected.read(CHUNK_SIZE)
            right = observed.read(CHUNK_SIZE)
            if left != right:
                for i, (a, b) in enumerate(zip(left, right)):
                    if a != b:
                        return offset + i, expected_size, actual_size
                return offset + min(len(left), len(right)), expected_size, actual_size
            if not left:
                return None
            offset += len(left)


def update_golden(golden: Path, actual: Path) -> None:
    """Replace the reference atomically, only on an explicit update request."""
    if golden.resolve() == actual.resolve():
        raise ValueError("golden and actual must be different files when updating")
    if golden.is_symlink():
        raise ValueError("refusing to replace a symlink golden")
    temporary = None
    try:
        with actual.open("rb") as source:
            with tempfile.NamedTemporaryFile(dir=golden.parent, prefix=".poko-golden-", delete=False) as target:
                temporary = Path(target.name)
                shutil.copyfileobj(source, target, CHUNK_SIZE)
        os.replace(temporary, golden)
        temporary = None
    finally:
        if temporary is not None:
            temporary.unlink(missing_ok=True)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Compare a golden file byte-for-byte, including PNG screenshots.")
    parser.add_argument("--golden", type=Path, help="reference file")
    parser.add_argument("--actual", type=Path, help="actual output file")
    parser.add_argument("--update", action="store_true", help="explicitly replace or create the reference from actual")
    parser.add_argument("--self-test", action="store_true", help="run harness unit and CLI tests")
    args = parser.parse_args(argv)
    if args.self_test:
        if args.golden is not None or args.actual is not None or args.update:
            parser.error("--self-test cannot be combined with comparison or update arguments")
        sys.dont_write_bytecode = True
        suite = unittest.defaultTestLoader.discover(str(Path(__file__).resolve().parent / "tests"), pattern="test_*.py")
        if suite.countTestCases() == 0:
            print("error: no golden harness tests found", file=sys.stderr)
            return 2
        return 0 if unittest.TextTestRunner(verbosity=2).run(suite).wasSuccessful() else 1
    if args.golden is None or args.actual is None:
        parser.error("--golden and --actual are required unless --self-test is used")
    try:
        if args.update:
            update_golden(args.golden, args.actual)
            print(f"Updated golden: {args.golden}")
            return 0
        difference = first_difference(args.golden, args.actual)
        if difference is None:
            print(f"MATCH: {args.actual} matches {args.golden}")
            return 0
        offset, expected_size, actual_size = difference
        print(f"MISMATCH at byte {offset} (golden: {expected_size} bytes; actual: {actual_size} bytes)", file=sys.stderr)
        return 1
    except (OSError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
