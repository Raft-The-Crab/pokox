"""Check schema preview CLI independently of project source files."""
import subprocess
import sys
import tempfile
from pathlib import Path

exe = sys.argv[1]
expected = bytes.fromhex('a4646b696e6475706f6b6f2e706b622e736368656d612d6472616674656472616674f5666669656c647382a2646e616d6565636f756e74647479706563693332a2646e616d656573636f72656474797065636933326776657273696f6e01')
with tempfile.TemporaryDirectory() as temp:
    path = Path(temp) / 'source.mute'
    path.write_text('@state var count:i32=0; @state var score:i32=-2; fn tick()->i32 {return score;} tick()',encoding='utf-8')
    result = subprocess.run([exe,str(path)],capture_output=True,check=True)
    assert result.stdout == expected
    assert b'not a .pkB' in result.stderr
    path.write_text('@state var x:u32=1; fn f()->i32{return 0;} f()',encoding='utf-8')
    result = subprocess.run([exe,str(path)],capture_output=True)
    assert result.returncode != 0 and not result.stdout
    path.write_bytes(b' ' * 65537)
    result = subprocess.run([exe,str(path)],capture_output=True)
    assert result.returncode != 0 and not result.stdout
