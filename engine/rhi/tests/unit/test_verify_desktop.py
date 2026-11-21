"""Evidence handling tests, not real SDK or GPU acceptance."""
from pathlib import Path
import contextlib
import importlib.util
import io
import json
import os
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT = Path(__file__).resolve().parents[4]
spec = importlib.util.spec_from_file_location('verify_desktop', ROOT / 'engine/rhi/scripts/verify_desktop.py')
verify = importlib.util.module_from_spec(spec)
spec.loader.exec_module(verify)
GOOD = 'POKO_CLEAR_RESULT submitted=120 validation_requested=true graphics_errors=0 graphics_warnings=0\n'

class EvidenceTests(unittest.TestCase):
    def test_summary(self):
        self.assertEqual(verify.parse_runtime(GOOD, 120)['submitted'], 120)
    def test_warning_retained(self):
        self.assertEqual(verify.parse_runtime(GOOD.replace('warnings=0', 'warnings=3'), 120)['graphics_warnings'], 3)
    def test_bad_summaries(self):
        for text in ['', GOOD + GOOD, GOOD.replace('120', '119'), GOOD.replace('true', 'false'),
                     GOOD.replace('errors=0', 'errors=1'), GOOD.replace('120', 'bad'), GOOD.rstrip() + ' extra']:
            with self.subTest(text=text), self.assertRaises(ValueError): verify.parse_runtime(text, 120)
    def test_never_auto_accept(self):
        report = verify.classify(verify.parse_runtime(GOOD, 120))
        for key in ('accepted', 'visual_output_verified', 'validation_layer_verified'): self.assertFalse(report[key])
    def test_process_success(self):
        with tempfile.TemporaryDirectory() as directory:
            log = Path(directory) / 'log'
            self.assertEqual(verify.run_step([sys.executable, '-c', 'print("output")'], log, 5)['returncode'], 0)
            self.assertIn('output', log.read_text())
    def test_process_failure(self):
        with tempfile.TemporaryDirectory() as directory:
            self.assertEqual(verify.run_step([sys.executable, '-c', 'raise SystemExit(7)'], Path(directory) / 'log', 5)['returncode'], 7)
    def test_process_timeout(self):
        with tempfile.TemporaryDirectory() as directory:
            result = verify.run_step([sys.executable, '-c', 'import time; time.sleep(20)'], Path(directory) / 'log', 0.1)
            self.assertTrue(result['timed_out']); self.assertNotEqual(result['returncode'], 0)
    def test_missing_executable(self):
        with tempfile.TemporaryDirectory() as directory:
            result = verify.run_step([str(Path(directory) / 'missing')], Path(directory) / 'log', 5)
            self.assertIsNone(result['returncode']); self.assertIn('error', result)
    def simulate(self, output, fail=None):
        def step(command, log, timeout):
            if Path(log).name == '02-build.log':
                exe = output / 'build' / ('pokox_vulkan_clear.exe' if os.name == 'nt' else 'pokox_vulkan_clear')
                exe.parent.mkdir(parents=True, exist_ok=True); exe.write_bytes(b'test placeholder, never executed')
            Path(log).write_text(GOOD if Path(log).name == '04-runtime.log' else 'simulated step\n')
            return dict(returncode=1 if Path(log).name == fail else 0, timed_out=False, log=str(log))
        return step
    def test_simulated_success_keeps_gate_open(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / 'run'
            with patch.object(verify, 'run_step', self.simulate(output)), contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(verify.main(['--output-dir', str(output)]), 0)
            report = json.loads((output / 'report.json').read_text())
            self.assertFalse(report['accepted']); self.assertEqual(len(report['steps']), 4)
    def test_failed_configure_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / 'run'
            with patch.object(verify, 'run_step', self.simulate(output, '01-configure.log')), contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(verify.main(['--output-dir', str(output)]), 1)
            report = json.loads((output / 'report.json').read_text())
            self.assertEqual(report['status'], 'failed'); self.assertEqual(len(report['steps']), 1)
    def test_nonzero_runtime_cannot_pass(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / 'run'
            with patch.object(verify, 'run_step', self.simulate(output, '04-runtime.log')), contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(verify.main(['--output-dir', str(output)]), 1)
            self.assertEqual(json.loads((output / 'report.json').read_text())['status'], 'failed')
    def test_refuse_old_output(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory); (output / 'old').write_text('keep')
            with contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit): verify.main(['--output-dir', str(output)])
            self.assertEqual((output / 'old').read_text(), 'keep')
    def test_refuse_nonfinite_timeouts(self):
        for flag in ('--build-timeout', '--runtime-timeout'):
            for value in ('nan', 'inf', '-inf'):
                with self.subTest(flag=flag, value=value), contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit) as error:
                    verify.main([flag, value])
                self.assertEqual(error.exception.code, 2)

if __name__ == '__main__': unittest.main()
