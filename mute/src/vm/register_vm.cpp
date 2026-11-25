#include "poko/mute/register_vm.hpp"
#include "vm_core.hpp"
namespace poko::mute {
VmResult run_register_vm(std::span<const Instruction> code,std::array<std::int32_t,256> r,std::size_t budget,const VmEnvironment* environment) {
  VmCore core(code,r,budget,environment);
  while (!core.done()) core.step();
  return core.result();
}
VmResult run_register_module(const VmModule& module,std::size_t entry,std::array<std::int32_t,256> r,
                             std::size_t budget,const VmEnvironment* environment) {
  VmCore core({},r,budget,environment,module.functions,module.capabilities,entry);
  while (!core.done()) core.step();
  return core.result();
}
} // namespace poko::mute
