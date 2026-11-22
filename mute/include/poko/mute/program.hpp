#pragma once

#include "poko/mute/evaluator.hpp"
#include "poko/mute/state.hpp"
#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>
#include <string>
#include <string_view>
#include <variant>

namespace poko::mute {
// Initial i32/bool program subset, compiled to an internal register VM.
// This is not the full Mute language or a security sandbox.
// Source and all program state are borrowed only for this call. Allocation may throw.
struct ProgramDiagnostic { std::string stage; std::string code; Position position; };
using ProgramResult = std::variant<NumericValue, ProgramDiagnostic>;
struct ProgramOptions {
  static constexpr std::size_t max_allowed_steps = 100'000;
  std::size_t max_steps = max_allowed_steps;
};
// Each call gets a fresh budget; values above the hard cap are rejected.
[[nodiscard]] ProgramResult run_program(std::string_view source, ProgramOptions options = {});
// State initializes on the first successful tick. A failure leaves it unchanged.
// Schema changes require explicit migration; concurrent mutation is unsupported.
[[nodiscard]] ProgramResult run_stateful_program(std::string_view source, ProgramState& state, ProgramOptions options = {});
[[nodiscard]] std::variant<std::vector<std::string>,ProgramDiagnostic> inspect_program_state_schema(std::string_view source);
// MUTP v1 is a bounded, source-backed snapshot of the current program subset,
// not .pkB or a sandbox. The input bytes must remain unmodified for the call.
using ProgramBytecodeResult = std::variant<std::vector<std::uint8_t>, ProgramDiagnostic>;
[[nodiscard]] ProgramBytecodeResult compile_program_bytecode(std::string_view source);
[[nodiscard]] ProgramBytecodeResult assemble_program_bytecode(std::string_view listing);
[[nodiscard]] ProgramResult run_program_bytecode(std::span<const std::uint8_t> bytes, ProgramOptions options = {});
[[nodiscard]] ProgramResult run_stateful_program_bytecode(std::span<const std::uint8_t> bytes, ProgramState& state, ProgramOptions options = {});
[[nodiscard]] std::variant<std::string, ProgramDiagnostic> disassemble_program_bytecode(std::span<const std::uint8_t> bytes);
} // namespace poko::mute
