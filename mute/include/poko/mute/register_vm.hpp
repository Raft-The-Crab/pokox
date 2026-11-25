#pragma once
#include "poko/mute/bytecode.hpp"
#include "poko/mute/hostcall.hpp"
#include <array>
#include <span>
#include <variant>
namespace poko::mute {
enum class VmErrorCode { invalid_bytecode, invalid_budget, budget_exceeded, overflow, divide_by_zero, no_return,
                         unknown_hostcall, hostcall_signature, capability_denied, hostcall_failed,
                         call_depth_exceeded, hostcall_quota, unknown_function };
struct VmError { VmErrorCode code; std::size_t pc; };
using VmResult = std::variant<std::int32_t, VmError>;
// Host-provided execution context for one run. hostcall_abi is the signature
// ABI version the program was built against; every dispatched def must match
// it. capabilities is the granted mask (0 grants only capability-free calls).
// hostcalls is the registered table; nullptr means no hostcalls exist.
// Mutable per-run accounting shared across nested run_register_vm calls (a
// hostcall handler may re-enter the VM) and across Opcode::call frames.
// Quotas are spec defaults: 1M instructions/tick and 1,000 hostcalls/tick;
// call depth mirrors the spec depth-64 limit.
struct VmRunState { std::size_t hostcalls{}, depth{}; };
struct VmEnvironment {
  std::uint32_t hostcall_abi{1};
  std::uint32_t capabilities{};
  const HostcallTable* hostcalls{};
  bool serialized_run{}; // true = replay/snapshot verification: non-serializable hostcalls denied
  std::uint32_t max_hostcalls{1000};
  std::uint32_t max_call_depth{64};
  VmRunState* state{};   // nullptr = untracked single run
};
// Experimental i32 register machine. Registers are copied per invocation; r0
// is always zero and cannot be written. call_host traps unknown_hostcall when
// environment is null or the id is not registered; signature and capability
// violations trap before dispatch. Opcode::call needs a module table and traps
// unknown_function under run_register_vm.
[[nodiscard]] VmResult run_register_vm(std::span<const Instruction> code, std::array<std::int32_t,256> registers = {}, std::size_t budget = 100'000, const VmEnvironment* environment = nullptr);

// Function table executed with Opcode::call. `capabilities` is optional and
// parallel to `functions`; a frame's effective mask is the caller mask
// intersected with the callee's declared mask (missing entries = 0x3FF).
struct VmModule {
  std::span<const Bytecode> functions;
  std::span<const std::uint32_t> capabilities{};
};
// Starts in functions[entry] and dispatches Opcode::call within the table.
[[nodiscard]] VmResult run_register_module(const VmModule& module, std::size_t entry = 0,
    std::array<std::int32_t,256> registers = {}, std::size_t budget = 100'000,
    const VmEnvironment* environment = nullptr);
} // namespace poko::mute
