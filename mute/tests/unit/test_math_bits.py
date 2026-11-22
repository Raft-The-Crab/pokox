import json
from pathlib import Path
import subprocess
import sys
root=Path(__file__).parents[2]
corpus=json.loads((root/'tools'/'math_determinism_corpus.json').read_text())
golden=json.loads((root/'tests'/'fixtures'/'math_portable_golden.json').read_text())
if len(golden)!=36 or [(v['op'],v['input']) for v in golden]!=[(v['op'],v['input']) for v in corpus]:
    raise AssertionError('golden does not match the full corpus')
result=subprocess.run([sys.argv[1]],input=''.join(v['input']+'\n' for v in golden),text=True,capture_output=True,check=True).stdout.splitlines()
if len(result)!=len(golden): raise AssertionError('missing results')
for v,line in zip(golden,result):
    outputs=line.split()
    if len(outputs)!=2 or outputs[0 if v['op']=='sin' else 1]!=v['output']:
        raise AssertionError(f"{v['op']}({v['input']}): {line}, expected {v['output']}")
print(f'{len(golden)} exact math golden cases passed')
