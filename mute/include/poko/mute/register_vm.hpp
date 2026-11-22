#pragma once
#include "poko/mute/bytecode.hpp"
#include <array>
#include <variant>
namespace poko::mute {
enum class VmErrorCode { invalid_bytecode, invalid_budget, budget_exceeded, overflow, divide_by_zero, no_return };
struct VmError { VmErrorCode code; std::size_t pc; };
using VmResult = std::variant<std::int32_t, VmError>;
// Experimental i32 register machine. No calls, hostcalls, floats or heap yet.
// Registers are copied per invocation; r0 is always zero and cannot be written.
[[nodiscard]] VmResult run_register_vm(std::span<const Instruction> code, std::array<std::int32_t,256> registers = {}, std::size_t budget = 100'000);
} // namespace poko::mute
