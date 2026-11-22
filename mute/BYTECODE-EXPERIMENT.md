# Mute bytecode and program snapshots

Both formats below cover the current bounded prototype, not the production `.pkB` package or a security sandbox. Full source-to-word-ISA compilation is MUT-26 and independent verification is MUT-27. Inputs and bytecode remain borrowed and must not be concurrently modified during API calls. Standard allocation failures may propagate.

## Word ISA branch decision and `MUTB` v1

The wire header is ASCII `MUTB`, version `01`, three zero bytes, and a little-endian u32 word count (at most 65,536). It is followed by exactly that many 4-byte words, each `opcode, a, b, c`; trailing bytes are rejected. Binary and canonical assembly round-trip. Old short-only readers can reject new long instructions rather than silently misinterpret them.

Implemented ordinary opcodes: `add`, `sub`, `mul`, `div`, `mod`, `neg`, `eq`, `ne`, `lt`, `le`, `gt`, `ge`, `jmp`, `br_true`, `br_false`, `mov`, `ret`, `halt`. See `docs/plan/04-mute.md` for the selected branch decision. In brief, short branches store a signed 16-bit `b:c` offset relative to the next word; long branches use `ext_prefix` (`0x60`), `a=1/2/3` for jump/true/false, `b` for a condition register (zero for unconditional), `c=0`, then a signed little-endian 32-bit payload relative to the word following the payload. Payloads cannot be branch targets. Compiler policy is short when in range, long otherwise. One extended pair consumes one execution step. Tests cover both directions beyond the short range, short extrema, malformed prefixes, overflow targets, payload-target rejection, condition outcomes and binary/text round trips.

The `run_register_vm` machine validates structural details and executes i32 operations with checked overflow and budget. It does not verify type, data flow or capabilities, implement recursion or source programs, or provide a production sandbox.

## Source-backed compiled-program snapshot `MUTP` v1

`compile_program_bytecode(source)` emits the **entire existing i32/bool program subset** and `run_program_bytecode(bytes)` reconstructs and executes the serialized VM instructions. `disassemble_program_bytecode` includes a canonical lowercase-hex snapshot line plus a readable per-function listing; `assemble_program_bytecode` requires an exact canonical listing and round-trips it byte-for-byte. Diagnostic source positions and execution budgets are preserved. APIs and structures are in `program.hpp`.

`MUTP` contains a header `MUTP 01 00 00 00`, a little-endian u32 source length and source bytes, a u32 function count, then one instruction stream per function and one main stream. Each stream has a u32 instruction count. Each instruction is opcode u8, operands a/b u32, byte/line/column u32, text length u32, and text bytes. For internal jump, conditional branch and short-circuit guard, the target operand is instead a signed i32 displacement relative to the next internal instruction. Non-target operands retain their internal meanings. The bytecode input is capped at 16 MiB; source and compiler limits still apply.

State initializers are checked for i32 type/range when compiling or decoding, as well as when running. Previously emitted snapshots with invalid initializers are now rejected; valid v1 bytes are unchanged. Other semantic checks may still occur only at runtime, so compilation is not full type/name verification.

As an interim safety boundary, decoding reparses and recompiles the embedded source and accepts only an exact canonical byte-for-byte match before reconstructing and executing the encoded instructions. This avoids executing arbitrary forged internal streams without pretending to implement MUT-27, but incurs compilation cost, exposes the embedded source, and is **not authentication** or a security verifier. Do not use this snapshot for untrusted mod execution, long-term compatibility or as `.pkB`. Diagnostic/budget equivalence and corrupted/truncated-input tests exercise this boundary. See `docs/mut08-mut10-completion-audit-2026-11-22.md` for remaining gates.
