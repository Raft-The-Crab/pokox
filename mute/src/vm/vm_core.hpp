#pragma once

#include "poko/mute/register_vm.hpp"
#include <vector>

namespace poko::mute {

// Steppable core of the experimental register VM (MUT-34). run_register_vm
// is a thin driver over this; VmDebugger drives it one instruction at a
// time for breakpoints, stepping and inspection. Trap/budget/hostcall
// semantics are identical to the original monolithic loop. Opcode::call
// pushes a frame (registers, return pc, return register, capability mask).
class VmCore {
 public:
  enum class State { running, returned, error };
  struct Frame {
    std::span<const Instruction> code;
    std::size_t return_pc{};
    std::uint8_t dest{};
    std::uint32_t mask{0x3FFu};
    std::array<std::int32_t,256> registers{};
  };

  VmCore(std::span<const Instruction> code,std::array<std::int32_t,256> registers,
         std::size_t budget,const VmEnvironment* environment,
         std::span<const Bytecode> functions = {},
         std::span<const std::uint32_t> function_masks = {},
         std::size_t entry = 0);

  // Executes at most one instruction (payload words of long forms count as
  // part of the instruction). No-op once state != running.
  void step();

  [[nodiscard]] State state() const noexcept { return state_; }
  [[nodiscard]] bool done() const noexcept { return state_!=State::running; }
  // Valid result once done(): int32_t on return, VmError otherwise.
  [[nodiscard]] VmResult result() const noexcept;
  [[nodiscard]] std::size_t pc() const noexcept { return pc_; }
  [[nodiscard]] std::size_t steps() const noexcept { return steps_; }
  [[nodiscard]] const std::array<std::int32_t,256>& registers() const noexcept { return r_; }
  // pc of the last executed instruction (for traps); pc_ is the next one.
  [[nodiscard]] std::size_t last_pc() const noexcept { return last_pc_; }
  // Live call frames, outermost first. Empty for a single-frame run.
  [[nodiscard]] const std::vector<Frame>& frames() const noexcept { return frames_; }
  // Effective capability mask of the current frame (MUT-36 narrowing).
  [[nodiscard]] std::uint32_t capability_mask() const noexcept { return mask_; }

 private:
  void fail(VmErrorCode code,std::size_t at);

  std::span<const Instruction> code_;
  std::span<const Bytecode> functions_;
  std::span<const std::uint32_t> masks_;
  std::array<std::int32_t,256> r_{};
  std::size_t pc_{},steps_{},last_pc_{};
  std::size_t budget_{};
  const VmEnvironment* env_{};
  std::size_t max_depth_{64};
  std::size_t base_depth_{1};
  std::uint32_t mask_{0x3FFu};
  std::vector<Frame> frames_;
  State state_{State::running};
  VmResult result_{};
  struct DepthGuard {
    VmRunState* s{};
    std::size_t saved{};
    ~DepthGuard(){ if (s) s->depth=saved; }
  } depth_guard_;
};

} // namespace poko::mute
