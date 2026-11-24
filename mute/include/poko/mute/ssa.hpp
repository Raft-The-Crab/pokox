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
  constant, copy, unary, binary, compare, phi, call, load, store,
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
  std::vector<IrOperand> args; // value operands (phis get 2*preds entries)
  std::uint32_t target{0};     // jump/branch target block index +1; 0 none
  std::uint32_t target2{0};    // branch false target +1
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
  std::vector<IrBlock> blocks;
};
struct IrModule {
  std::vector<IrFunction> functions;
};

enum class IrErrorCode : std::uint8_t {
  empty_function, missing_entry, missing_terminator, bad_terminator,
  undefined_value, phi_arity, type_mismatch, bad_operand_count,
  duplicate_label, unreachable_block
};
struct IrDiagnostic { IrErrorCode code; std::string detail; std::size_t function{}, block{}; };
struct IrResult {
  std::vector<IrDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] IrResult verify(const IrModule& module);
// Deterministic listing for goldens/tests: one line per instruction.
[[nodiscard]] std::string dump_ir(const IrModule& module);
[[nodiscard]] std::string_view name(IrErrorCode code);
} // namespace poko::mute
