import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

HERE = Path(__file__).resolve()
HARNESS = HERE.parents[1] / "golden.py"
FIXTURES = HERE.parents[2] / "fixtures" / "golden"


def run(*args):
    return subprocess.run([sys.executable, str(HARNESS), *map(str, args)],
                          capture_output=True, text=True, check=False)


class GoldenHarnessTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def pair(self, expected, actual):
        return run("--golden", expected, "--actual", actual)

    def test_binary_match(self):
        actual = self.root / "actual.bin"
        actual.write_bytes((FIXTURES / "reference.bin").read_bytes())
        result = self.pair(FIXTURES / "reference.bin", actual)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("MATCH", result.stdout)

    def test_binary_mismatch_does_not_update_reference(self):
        expected = self.root / "expected.bin"
        expected.write_bytes((FIXTURES / "reference.bin").read_bytes())
        before = expected.read_bytes()
        result = self.pair(expected, FIXTURES / "different.bin")
        self.assertEqual(result.returncode, 1)
        self.assertIn("MISMATCH at byte 2", result.stderr)
        self.assertEqual(expected.read_bytes(), before)

    def test_png_match(self):
        actual = self.root / "actual.png"
        actual.write_bytes((FIXTURES / "reference.png").read_bytes())
        result = self.pair(FIXTURES / "reference.png", actual)
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_png_mismatch(self):
        result = self.pair(FIXTURES / "reference.png", FIXTURES / "different.png")
        self.assertEqual(result.returncode, 1)
        self.assertIn("MISMATCH at byte", result.stderr)

    def test_different_lengths_and_empty_files(self):
        a, b = self.root / "a", self.root / "b"
        a.write_bytes(b""); b.write_bytes(b"")
        self.assertEqual(self.pair(a, b).returncode, 0)
        b.write_bytes(b"x")
        result = self.pair(a, b)
        self.assertEqual(result.returncode, 1)
        self.assertIn("MISMATCH at byte 0", result.stderr)

    def test_chunk_boundary(self):
        a, b = self.root / "a", self.root / "b"
        a.write_bytes(b"a" * 65536 + b"x")
        b.write_bytes(b"a" * 65536 + b"y")
        result = self.pair(a, b)
        self.assertEqual(result.returncode, 1)
        self.assertIn("MISMATCH at byte 65536", result.stderr)

    def test_missing_file_is_error(self):
        result = self.pair(self.root / "missing", FIXTURES / "reference.bin")
        self.assertEqual(result.returncode, 2)
        self.assertIn("error:", result.stderr)

    def test_update_creates_and_replaces_only_when_explicit(self):
        expected = self.root / "expected.bin"
        actual = FIXTURES / "reference.bin"
        self.assertEqual(self.pair(expected, actual).returncode, 2)
        self.assertFalse(expected.exists())
        result = run("--golden", expected, "--actual", actual, "--update")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(expected.read_bytes(), actual.read_bytes())
        actual2 = FIXTURES / "different.bin"
        result = run("--golden", expected, "--actual", actual2, "--update")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(expected.read_bytes(), actual2.read_bytes())
        self.assertEqual(self.pair(expected, actual2).returncode, 0)

    def test_update_same_path_refused(self):
        path = self.root / "single.bin"
        path.write_bytes(b"keep")
        result = run("--golden", path, "--actual", path, "--update")
        self.assertEqual(result.returncode, 2)
        self.assertEqual(path.read_bytes(), b"keep")

    def test_update_missing_actual_preserves_existing_reference(self):
        expected = self.root / "expected.bin"
        expected.write_bytes(b"keep")
        result = run("--golden", expected, "--actual", self.root / "missing", "--update")
        self.assertEqual(result.returncode, 2)
        self.assertEqual(expected.read_bytes(), b"keep")

    def test_incomplete_arguments_are_errors(self):
        self.assertEqual(run("--golden", self.root / "a").returncode, 2)
        self.assertEqual(run("--self-test", "--update").returncode, 2)


if __name__ == "__main__":
    unittest.main()
