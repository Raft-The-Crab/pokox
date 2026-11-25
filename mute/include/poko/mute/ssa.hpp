#pragma once

#include "poko/mute/semantic.hpp"
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace poko::mute {

// Typed SSA IR (MUT-25 foundation). Functions are lists of basic blocks in
// layout order; values are numbered defs usable only after definition.
// `verify` rejects malformed control flow (missing terminators, dangling
// predecessors, undefined values, bad phi arity) and type errors (operand
// kind mismatches, non-matching phi inputs, wrong return type). Lowering
// from the AST lands in MUT-26; this module is the verified target.

enum class IrOp : std::uint8_t {
  constant, copy, unary, binary, compare, phi, call, call_host, load, store,
  jump, branch, return_
};

struct IrValue {
  std::uint32_t id{};
  Type type{};
};
struct IrOperand {
  std::uint32_t value{0}; // 0 = none
  std::uint64_t imm{};    // literal payload for constant
};
struct IrInstr {
  IrOp op{};
  std::uint32_t def{0};              // produced value id; 0 = no result
  Type result{};               // result type; unit for side-effect ops
  std::vector<IrOperand> args; // value operands
  std::uint32_t target{0};     // jump/branch target block index +1; 0 none
  std::uint32_t target2{0};    // branch false target +1
  std::uint8_t detail{0};      // sub-operation: binary 0=add 1=sub 2=mul 3=div
                               // 4=mod; unary 0=neg; compare 0=eq 1=ne 2=lt
                               // 3=le 4=gt 5=ge; phi operands carry
                               // imm = predecessor block index + 1
  std::uint32_t callee{0};     // call: IrModule::functions index + 1;
                               // call_host: IrModule::hostcalls index + 1; 0 none
  Position pos{};              // source position for diagnostics (MUT-33)
};
struct IrBlock {
  std::string label;
  std::vector<std::uint32_t> preds;   // block indices +1
  std::vector<IrInstr> instrs;        // terminator is last
};
struct IrFunction {
  std::string name;
  Type result{};
  std::vector<Type> params;
  // Narrowed capability grant for this function (package ceiling intersected
  // with an explicit `@requires(...)`, MUT-36). 0x3FF = no narrowing.
  std::uint32_t capabilities{0x3FFu};
  std::vector<IrBlock> blocks;
};
// Hostcalls referenced by IrOp::call_host. `id` is the registered hostcall id;
// the instruction's callee indexes this table (index + 1).
struct IrHostcall {
  std::uint32_t id{};
  std::vector<Type> params;
  Type result{};
};
struct IrModule {
  std::vector<IrFunction> functions;
  std::vector<IrHostcall> hostcalls;
};

enum class IrErrorCode : std::uint8_t {
  empty_function, missing_entry, missing_terminator, bad_terminator,
  undefined_value, phi_arity, type_mismatch, bad_operand_count,
  duplicate_label, unreachable_block
};
struct IrDiagnostic { IrErrorCode code; std::string detail; std::size_t function{}, block{}; Position pos{}; };
struct IrResult {
  std::vector<IrDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] IrResult verify(const IrModule& module);
// Deterministic listing for goldens/tests: one line per instruction.
[[nodiscard]] std::string dump_ir(const IrModule& module);
[[nodiscard]] std::string_view name(IrErrorCode code);
} // namespace poko::mute
