# MUT-27 progress — bytecode verification before execution

Status: implemented and verified locally. No gate accepted.

## Delivered

`validate_bytecode` (`mute/src/bytecode/bytecode.cpp`) now rejects, before
any execution (it is called by `encode_bytecode`, `decode_bytecode`,
`assemble_bytecode`, `disassemble_bytecode` and `run_register_vm`):

- Empty instruction streams (`invalid_operands`).
- Programs whose last real instruction can fall through past the end of the
  stream — i.e. the final non-payload instruction must be `ret`, `halt`,
  `jump`, or an unconditional long jump (`ext_prefix` mode 1). Conditional
  branches, ALU ops, `move`, `li`, and conditional `ext` modes (2/3) as the
  last instruction are rejected (`invalid_operands`).

Already covered before this pass and re-verified: invalid/unknown opcodes,
operand-field violations (r0 writes, reserved operands), branch targets
out of bounds or into payload words, truncated payloads, oversize streams,
wire framing (header/version/length/trailing bytes).

Register operands are `uint8_t` so all indices are < 256 by construction;
destination-register writes to r0 were already rejected. No hostcall
opcodes exist in the ISA yet — unknown opcodes are rejected, and the typed
hostcall boundary itself is MUT-35.

## Bugs found and fixed while landing this milestone

- `run_register_vm` previously accepted empty streams and fall-off-end
  programs (they failed later as `no_return`); now rejected statically.
- The new terminator rule initially rejected legitimate programs ending in
  an unconditional `ext_prefix` long jump — caught by
  `mute_bytecode_vm_unit` and corrected.

## Verified

- Debug MSVC `mute_*`: 36/36 (incl. new `mute_fold_unit`).
- ASan `build-msvc-asan`: fold/lower/ssa/emit/bytecode_vm/values/package/
  scheduler/determinism all clean.

## Still open

- No reachability analysis (unreachable code is allowed; the VM simply
  never executes it).
- No hostcall opcodes or signature table yet (MUT-35).
- `.pkB` production format is separate work.
