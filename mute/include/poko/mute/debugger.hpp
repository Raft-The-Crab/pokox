#pragma once

#include "poko/mute/register_vm.hpp"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace poko::mute {

// MUT-34: debugger breakpoints and stepping over the experimental register
// VM. A VmDebugger owns its own register file (callers' arrays are never
// touched) and executes through the same VmCore as run_register_vm, so trap,
// budget, capability and hostcall semantics are identical — debugging cannot
// silently mutate validated simulation state.
//
// Scope: Opcode::call frames are visible through stack(). Host-mediated
// recursion via hostcall handlers still runs in nested VmCore instances
// outside this debugger's view; VmEnvironment::state->depth bounds both.

enum class DebugStop : std::uint8_t {
  breakpoint,   // suspended on a breakpoint before executing pc()
  stepped,      // step() completed exactly one instruction
  returned,     // program returned; result() holds the value
  trapped,      // VmError; result() holds the error (incl. budget/invalid)
};

struct DebugRun {
  DebugStop stop{};
  VmResult result{};      // meaningful for returned/trapped
  std::size_t pc{};       // pc of the next instruction to execute
};

class VmCore; // defined in src/vm/vm_core.hpp

class VmDebugger {
 public:
  VmDebugger(std::span<const Instruction> code,std::array<std::int32_t,256> registers = {},
             std::size_t budget = 100'000,const VmEnvironment* environment = nullptr);
  // Module-aware debugging: Opcode::call dispatches within the table and
  // stack() reports one entry per live frame.
  VmDebugger(const VmModule& module,std::size_t entry = 0,
             std::array<std::int32_t,256> registers = {},
             std::size_t budget = 100'000,const VmEnvironment* environment = nullptr);
  ~VmDebugger();
  VmDebugger(const VmDebugger&) = delete;
  VmDebugger& operator=(const VmDebugger&) = delete;
  VmDebugger(VmDebugger&&) noexcept;
  VmDebugger& operator=(VmDebugger&&) noexcept;

  void add_breakpoint(std::size_t pc);
  void remove_breakpoint(std::size_t pc);
  [[nodiscard]] bool has_breakpoint(std::size_t pc) const;
  void clear_breakpoints();

  // Execute exactly one instruction (the instruction at pc() unless the run
  // already ended). Breakpoints do not interrupt a single step.
  [[nodiscard]] DebugRun step();
  // Execute until a breakpoint, program end, or trap. Returns immediately
  // with stop==breakpoint when pc() is a breakpoint.
  [[nodiscard]] DebugRun run();

  [[nodiscard]] bool finished() const noexcept;
  [[nodiscard]] std::size_t pc() const noexcept;          // next instruction
  [[nodiscard]] std::size_t last_pc() const noexcept;     // last executed
  [[nodiscard]] std::size_t steps() const noexcept;
  [[nodiscard]] const std::array<std::int32_t,256>& registers() const noexcept;
  [[nodiscard]] VmResult result() const noexcept;         // after returned/trapped
  // One entry per live frame, innermost last: suspended return pcs followed
  // by the current frame's pc. Empty once the run ends.
  [[nodiscard]] std::vector<std::size_t> stack() const;

 private:
  std::unique_ptr<VmCore> core_;
  std::vector<std::size_t> breakpoints_;
};

} // namespace poko::mute
