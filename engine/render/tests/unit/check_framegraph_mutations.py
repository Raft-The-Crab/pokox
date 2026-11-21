"""Optional fault-sensitivity test; compiles intentional defects in temp files."""
import argparse
from pathlib import Path
import subprocess
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--cxx', default='c++')
args = parser.parse_args()
root = Path(__file__).resolve().parents[4]
source = root / 'engine/render/src/framegraph/frame_graph.cpp'
test = root / 'engine/render/tests/unit/frame_graph_test.cpp'
original = source.read_text(encoding='utf-8')
mutations = {
    'missing_edges': ('if (predecessors[to].insert(from).second)', 'if (false && predecessors[to].insert(from).second)'),
    'ignore_cycle': ('if (result.order.size() != passes_.size())', 'if (false)'),
    'allow_unproduced': ('else if (!imported.contains(resource))', 'else if (false)'),
    'allow_duplicate_writers': ('if (!writers.emplace(resource, i).second) return {FrameGraphError::multiple_writers, resource, {}};', 'writers.emplace(resource, i);'),
    'allow_duplicate_usage': ('if (!used.insert(resource).second) return {FrameGraphError::duplicate_resource_use, resource, {}};', 'used.insert(resource);'),
    'reverse_tie_break': ('std::greater<>', 'std::less<>'),
    'allow_import_during_execution': ('if (executing_) return FrameGraphError::busy;', 'if (false) return FrameGraphError::busy;'),
    'ignore_callback_failure': ('return {FrameGraphError::callback_failed, passes_[index].name, completed};', 'return {FrameGraphError::none, passes_[index].name, completed};'),
}
with tempfile.TemporaryDirectory(prefix='poko-framegraph-mutations-') as temp:
    work = Path(temp)
    for name, (old, new) in mutations.items():
        count = original.count(old)
        if count != (3 if name == 'allow_import_during_execution' else 1):
            raise RuntimeError(f'{name}: unexpected anchor count {count}')
        mutant = work / 'frame_graph.cpp'
        mutant.write_text(original.replace(old, new, 1), encoding='utf-8')
        binary = work / 'mutation-test'
        build = subprocess.run([args.cxx, '-std=c++20', '-I' + str(root / 'engine/render/include'),
                                str(mutant), str(test), '-o', str(binary)], capture_output=True, text=True, timeout=60)
        if build.returncode:
            raise RuntimeError(f'{name}: mutant did not build\n{build.stderr}')
        run = subprocess.run([str(binary)], capture_output=True, text=True, timeout=10)
        if run.returncode == 0:
            raise RuntimeError(f'{name}: test missed mutation')
        print(f'CAUGHT: {name}', flush=True)
print('PASS: all frame-graph mutations detected')
