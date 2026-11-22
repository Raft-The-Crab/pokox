import copy
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location('math_determinism', Path(__file__).parents[2] / 'tools' / 'math_determinism.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)

class TraceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.p = Path(self.temp.name)
        self.corpus = m.load_corpus()
        self.base = {'format': 1, 'implementation': 'candidate-v1', 'target': 'x64',
                     'vectors': [dict(v, output='0000000000000000') for v in self.corpus]}
    def write(self, name, trace):
        path = self.p / name
        path.write_text(json.dumps(trace), encoding='utf-8')
        return path
    def check_invalid(self, changed):
        changed['target'] = 'arm64'
        with self.assertRaises(ValueError):
            m.compare(self.write('a', self.base), self.write('b', changed), self.corpus)
    def test_match_is_only_agreement(self):
        other = copy.deepcopy(self.base); other['target'] = 'arm64'
        self.assertEqual(m.compare(self.write('a', self.base), self.write('b', other), self.corpus), len(self.corpus))
    def test_mismatch(self):
        other = copy.deepcopy(self.base); other['vectors'][0]['output'] = '8000000000000000'
        self.check_invalid(other)
    def test_missing_extra_reordered_and_bad_bits(self):
        for mode in ('missing', 'extra', 'reorder', 'bits', 'id'):
            other = copy.deepcopy(self.base)
            if mode == 'missing': other['vectors'].pop()
            if mode == 'extra': other['vectors'].append(other['vectors'][0])
            if mode == 'reorder': other['vectors'][0], other['vectors'][1] = other['vectors'][1], other['vectors'][0]
            if mode == 'bits': other['vectors'][0]['output'] = 'not-hex'
            if mode == 'id': other['implementation'] = 'other'
            self.check_invalid(other)
    def test_corpus_corruption_rejected(self):
        for corpus in ([], self.corpus[:-1] + [self.corpus[0]]):
            with self.assertRaises(ValueError): m.load_corpus(self.write('corpus', corpus))
    def test_same_target_is_not_cross_platform(self):
        with self.assertRaises(ValueError): m.compare(self.write('a',self.base),self.write('b',self.base),self.corpus)
    def test_duplicate_json_keys_rejected(self):
        path=self.p/'bad';path.write_text('{"format":1,"format":1}')
        with self.assertRaises(ValueError): m._read(path)
    def test_overlong_file_rejected(self):
        path=self.p/'bad';path.write_bytes(b' '* (m.MAX_BYTES+1))
        with self.assertRaises(ValueError): m._read(path)

if __name__ == '__main__': unittest.main()
