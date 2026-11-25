#include "poko/mute/debugger.hpp"
#include "vm_core.hpp"
#include <algorithm>
namespace poko::mute {
namespace {
DebugRun finish(VmCore& core,DebugStop stop) {
  return {stop,core.done()?core.result():VmResult{},core.pc()};
}
}

VmDebugger::VmDebugger(std::span<const Instruction> code,std::array<std::int32_t,256> registers,
                       std::size_t budget,const VmEnvironment* environment)
    : core_(std::make_unique<VmCore>(code,registers,budget,environment)) {}
VmDebugger::VmDebugger(const VmModule& module,std::size_t entry,std::array<std::int32_t,256> registers,
                       std::size_t budget,const VmEnvironment* environment)
    : core_(std::make_unique<VmCore>(std::span<const Instruction>{},registers,budget,environment,
                                     module.functions,module.capabilities,entry)) {}
VmDebugger::~VmDebugger() = default;
VmDebugger::VmDebugger(VmDebugger&&) noexcept = default;
VmDebugger& VmDebugger::operator=(VmDebugger&&) noexcept = default;

void VmDebugger::add_breakpoint(std::size_t pc) {
  if (std::find(breakpoints_.begin(),breakpoints_.end(),pc)==breakpoints_.end())
    breakpoints_.push_back(pc);
}
void VmDebugger::remove_breakpoint(std::size_t pc) {
  breakpoints_.erase(std::remove(breakpoints_.begin(),breakpoints_.end(),pc),breakpoints_.end());
}
bool VmDebugger::has_breakpoint(std::size_t pc) const {
  return std::find(breakpoints_.begin(),breakpoints_.end(),pc)!=breakpoints_.end();
}
void VmDebugger::clear_breakpoints() { breakpoints_.clear(); }

DebugRun VmDebugger::step() {
  core_->step();
  if (core_->state()==VmCore::State::returned) return finish(*core_,DebugStop::returned);
  if (core_->state()==VmCore::State::error) return finish(*core_,DebugStop::trapped);
  return {DebugStop::stepped,VmResult{},core_->pc()};
}

DebugRun VmDebugger::run() {
  if (core_->state()!=VmCore::State::running)
    return finish(*core_,core_->state()==VmCore::State::returned?DebugStop::returned:DebugStop::trapped);
  if (has_breakpoint(core_->pc())) return {DebugStop::breakpoint,VmResult{},core_->pc()};
  for (;;) {
    core_->step();
    if (core_->state()!=VmCore::State::running)
      return finish(*core_,core_->state()==VmCore::State::returned?DebugStop::returned:DebugStop::trapped);
    if (has_breakpoint(core_->pc())) return {DebugStop::breakpoint,VmResult{},core_->pc()};
  }
}

bool VmDebugger::finished() const noexcept { return core_->done(); }
std::size_t VmDebugger::pc() const noexcept { return core_->pc(); }
std::size_t VmDebugger::last_pc() const noexcept { return core_->last_pc(); }
std::size_t VmDebugger::steps() const noexcept { return core_->steps(); }
const std::array<std::int32_t,256>& VmDebugger::registers() const noexcept { return core_->registers(); }
VmResult VmDebugger::result() const noexcept { return core_->result(); }
std::vector<std::size_t> VmDebugger::stack() const {
  if (core_->done()) return {};
  std::vector<std::size_t> out;
  out.reserve(core_->frames().size()+1);
  for (const auto& f:core_->frames()) out.push_back(f.return_pc);
  out.push_back(core_->pc());
  return out;
}
} // namespace poko::mute
