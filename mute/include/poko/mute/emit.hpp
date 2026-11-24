#pragma once

#include "poko/mute/bytecode.hpp"
#include "poko/mute/ssa.hpp"
#include <vector>

namespace poko::mute {

// IR -> register bytecode emission (MUT-26 foundation). Lowers a verified
// IrModule subset onto the experimental register ISA: params and value defs
// map to registers 1..255, ALU ops emit reg-reg instructions, phi operands
// become move sequences on predecessor edges (critical edges are split into
// trampoline blocks), and out-of-range branches use ext_prefix long form.
//
// Unsupported for now (typed emit errors, never silent): constant (the
// register ISA has no immediate load — literal pool is later work), call,
// load, store, and value ids above 255.

enum class EmitErrorCode : std::uint8_t {
  verify_failed, unsupported_op, too_many_values, bad_phi_operand,
  too_many_functions, branch_range
};
struct EmitError { EmitErrorCode code{}; std::size_t function{}, block{}, instr{}; };
struct EmitResult {
  std::vector<Bytecode> functions;
  std::vector<IrDiagnostic> diagnostics; // verify() output when verify_failed
  std::vector<EmitError> errors;
  [[nodiscard]] bool ok() const noexcept { return errors.empty() && diagnostics.empty(); }
};

[[nodiscard]] EmitResult emit_bytecode(const IrModule& module);
[[nodiscard]] std::string_view name(EmitErrorCode code);
} // namespace poko::mute
