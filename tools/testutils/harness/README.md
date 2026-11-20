# Golden-file harness

`golden.py` compares any two files **byte-for-byte**, including encoded screenshots. It does not decode PNGs, compare pixels or allow tolerance: a metadata, encoder or compression change can fail a screenshot comparison even if the pixels look identical. Produce deterministic screenshot files, or add a separately specified pixel-comparison mode later.

## Layout

- `golden.py` — shared comparison and explicit-update tool.
- `tests/` — harness unit and CLI tests.
- `../fixtures/golden/` — tiny binary and PNG fixtures for testing the harness itself. Product-specific goldens should live with the tests of the owning module.

## Usage

From the project root (Python 3.9+):

```sh
python tools/testutils/harness/golden.py --golden path/to/reference.bin --actual path/to/output.bin
python tools/testutils/harness/golden.py --golden path/to/reference.png --actual path/to/screenshot.png
python tools/testutils/harness/golden.py --self-test
```

Exit codes: `0` match or successful update; `1` mismatch or self-test failure; `2` invalid arguments, missing files or I/O errors. Mismatches report the first differing byte and file sizes; comparison never changes either file.

To deliberately create or replace a reference after reviewing the output:

```sh
python tools/testutils/harness/golden.py --golden path/to/reference.bin --actual path/to/output.bin --update
```

The reference's parent directory must already exist. Update uses an atomic replacement and refuses a symlink reference or the same input path. Do not use `--update` in CI; review any changed golden before committing it. CTest runs `--self-test` when `BUILD_TESTING=ON`.
