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
// Calls use the frame convention: the caller stages arguments in registers
// 224..255, Opcode::call names the function index, and the callee prologue
// moves its window into params 1..N. call_host stages the same window and
// carries the registered hostcall id. Unsupported for now (typed emit errors,
// never silent): load, store, value ids at or above the argument window, and
// functions with more than 32 parameters.

enum class EmitErrorCode : std::uint8_t {
  verify_failed, unsupported_op, too_many_values, bad_phi_operand,
  too_many_functions, branch_range
};
struct EmitError { EmitErrorCode code{}; std::size_t function{}, block{}, instr{}; Position pos{}; };
struct EmitResult {
  std::vector<Bytecode> functions;
  // Function capability mask, parallel to `functions` (MUT-36 narrowing).
  std::vector<std::uint32_t> capabilities;
  // pc -> source position map, parallel to functions (MUT-33). Every emitted
  // instruction word gets the position of the IR instruction that produced
  // it; phi-move words carry the phi's position and trampoline words carry
  // the originating phi/branch position. Position{} (line 0) means unknown.
  std::vector<std::vector<Position>> positions;
  std::vector<IrDiagnostic> diagnostics; // verify() output when verify_failed
  std::vector<EmitError> errors;
  [[nodiscard]] bool ok() const noexcept { return errors.empty() && diagnostics.empty(); }
};

[[nodiscard]] EmitResult emit_bytecode(const IrModule& module);
// Source position for a bytecode pc in an emitted function. Returns the
// position recorded at pc, or the nearest earlier known position; Position{}
// (line 0) when the function/pc is out of range or nothing is known.
[[nodiscard]] Position source_position(const EmitResult& result, std::size_t function, std::size_t pc) noexcept;
// All pcs in an emitted function whose recorded source position equals pos
// (exact byte/line/column match). Used to place source-level breakpoints.
[[nodiscard]] std::vector<std::size_t> source_pcs(const EmitResult& result, std::size_t function, const Position& pos);
[[nodiscard]] std::string_view name(EmitErrorCode code);
} // namespace poko::mute
