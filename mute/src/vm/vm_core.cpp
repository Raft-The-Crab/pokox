#include "vm_core.hpp"
#include <limits>
#include <bit>
namespace poko::mute {

VmCore::VmCore(std::span<const Instruction> code,std::array<std::int32_t,256> registers,
               std::size_t budget,const VmEnvironment* environment,
               std::span<const Bytecode> functions,
               std::span<const std::uint32_t> function_masks,
               std::size_t entry)
    : code_(code),functions_(functions),masks_(function_masks),
      r_(registers),budget_(budget),env_(environment) {
  max_depth_=env_ ? env_->max_call_depth : 64;
  if (budget>1'000'000) { fail(VmErrorCode::invalid_budget,0); return; }
  // Shared run state bounds host-mediated recursion and internal call frames.
  // Depth is charged once per nested run/frame; the guard restores it on
  // destruction so traps mid-stack never leak depth.
  if (env_ && env_->state) {
    if (env_->state->depth>=max_depth_) { fail(VmErrorCode::call_depth_exceeded,0); return; }
    depth_guard_.s=env_->state; depth_guard_.saved=env_->state->depth;
    ++env_->state->depth; base_depth_=env_->state->depth;
  }
  if (!functions_.empty()) {
    if (entry>=functions_.size()) { fail(VmErrorCode::unknown_function,0); return; }
    code_=functions_[entry];
    for (const auto& fn:functions_) {
      auto valid=validate_bytecode(fn);
      if (const auto* e=std::get_if<BytecodeError>(&valid)) { fail(VmErrorCode::invalid_bytecode,e->offset); return; }
    }
    mask_=entry<masks_.size()?masks_[entry]:0x3FFu;
  } else {
    auto valid=validate_bytecode(code_);
    if (const auto* e=std::get_if<BytecodeError>(&valid)) { fail(VmErrorCode::invalid_bytecode,e->offset); return; }
  }
  r_[0]=0;
}

void VmCore::fail(VmErrorCode code,std::size_t at) {
  state_=State::error; result_=VmError{code,at};
}

VmResult VmCore::result() const noexcept {
  if (state_==State::returned) return std::get<std::int32_t>(result_);
  return result_;
}

void VmCore::step() {
  if (state_!=State::running) return;
  if (steps_>=budget_) { fail(VmErrorCode::budget_exceeded,pc_); return; }
  if (pc_>=code_.size()) { fail(VmErrorCode::no_return,pc_); return; }
  ++steps_; const auto i=code_[pc_]; last_pc_=pc_; ++pc_;
  const auto x=r_[i.b], y=r_[i.c]; std::int64_t value=0;
  switch (i.op) {
    case Opcode::add:value=static_cast<std::int64_t>(x)+y;break;
    case Opcode::sub:value=static_cast<std::int64_t>(x)-y;break;
    case Opcode::mul:value=static_cast<std::int64_t>(x)*y;break;
    case Opcode::div: case Opcode::mod:
      if (y==0) { fail(VmErrorCode::divide_by_zero,last_pc_); return; }
      if (x==std::numeric_limits<std::int32_t>::min() && y==-1) { fail(VmErrorCode::overflow,last_pc_); return; }
      value=i.op==Opcode::div ? x/y : x%y; break;
    case Opcode::neg:value=-static_cast<std::int64_t>(x);break;
    case Opcode::eq:value=x==y;break; case Opcode::ne:value=x!=y;break;
    case Opcode::lt:value=x<y;break; case Opcode::le:value=x<=y;break;
    case Opcode::gt:value=x>y;break; case Opcode::ge:value=x>=y;break;
    case Opcode::move:value=x;break;
    case Opcode::load_imm: {
      const auto pay=code_[pc_++];
      const auto u=static_cast<std::uint32_t>(pay.op) | (static_cast<std::uint32_t>(pay.a)<<8) |
        (static_cast<std::uint32_t>(pay.b)<<16) | (static_cast<std::uint32_t>(pay.c)<<24);
      r_[i.a]=std::bit_cast<std::int32_t>(u);
      return;
    }
    case Opcode::ext_prefix: {
      const auto payload=code_[pc_++];
      const auto bits=static_cast<std::uint32_t>(payload.op) | (static_cast<std::uint32_t>(payload.a)<<8) |
        (static_cast<std::uint32_t>(payload.b)<<16) | (static_cast<std::uint32_t>(payload.c)<<24);
      const bool take=i.a==1 || ((r_[i.b]!=0)==(i.a==2));
      if (take) pc_=static_cast<std::size_t>(static_cast<std::int64_t>(pc_)+std::bit_cast<std::int32_t>(bits));
      return;
    }
    case Opcode::jump:pc_=static_cast<std::size_t>(static_cast<std::int64_t>(pc_)+branch_offset(i));return;
    case Opcode::branch_true:case Opcode::branch_false:
      if ((r_[i.a]!=0)==(i.op==Opcode::branch_true)) pc_=static_cast<std::size_t>(static_cast<std::int64_t>(pc_)+branch_offset(i));
      return;
    case Opcode::call: {
      if (functions_.empty() || i.a>=functions_.size()) { fail(VmErrorCode::unknown_function,last_pc_); return; }
      const auto depth=(env_ && env_->state) ? env_->state->depth : base_depth_+frames_.size();
      if (depth>=max_depth_) { fail(VmErrorCode::call_depth_exceeded,last_pc_); return; }
      Frame f;
      f.code=code_; f.return_pc=pc_; f.dest=i.c; f.mask=mask_; f.registers=r_;
      frames_.push_back(std::move(f));
      std::array<std::int32_t,256> fresh{};
      for (std::size_t k=0;k<call_arg_window;++k) fresh[i.b+k]=r_[i.b+k];
      r_=fresh;
      mask_=(i.a<masks_.size()?masks_[i.a]:0x3FFu) & frames_.back().mask;
      if (env_ && env_->state) ++env_->state->depth;
      code_=functions_[i.a]; pc_=0;
      return;
    }
    case Opcode::call_host: {
      const HostcallDef* def=env_ && env_->hostcalls ? env_->hostcalls->find(i.a) : nullptr;
      if (!def) { fail(VmErrorCode::unknown_hostcall,last_pc_); return; }
      const std::uint32_t granted=env_->capabilities & mask_;
      if ((def->capabilities & ~granted)!=0 ||
          (!def->serializable && env_->serialized_run))
        { fail(VmErrorCode::capability_denied,last_pc_); return; }
      const std::size_t n=def->params.size();
      if (def->version!=env_->hostcall_abi || n>256-static_cast<std::size_t>(i.b) ||
          (def->result==HostType::unit && i.c!=0))
        { fail(VmErrorCode::hostcall_signature,last_pc_); return; }
      for (std::size_t k=0;k<n;++k)
        if (def->params[k]==HostType::boolean && r_[i.b+k]!=0 && r_[i.b+k]!=1)
          { fail(VmErrorCode::hostcall_signature,last_pc_); return; }
      if (env_->state && env_->state->hostcalls>=env_->max_hostcalls)
        { fail(VmErrorCode::hostcall_quota,last_pc_); return; }
      if (env_->state) ++env_->state->hostcalls;
      auto result=def->handler(std::span<const std::int32_t>(r_.data()+i.b,n));
      const auto* value=std::get_if<std::int32_t>(&result);
      if (!value) { fail(VmErrorCode::hostcall_failed,last_pc_); return; }
      if (def->result==HostType::boolean && *value!=0 && *value!=1)
        { fail(VmErrorCode::hostcall_signature,last_pc_); return; }
      if (def->result!=HostType::unit && i.c!=0) r_[i.c]=*value;
      return;
    }
    case Opcode::ret:
      if (frames_.empty()) { state_=State::returned; result_=r_[i.a]; return; }
      {
        const auto result=r_[i.a];
        Frame f=std::move(frames_.back());
        frames_.pop_back();
        r_=std::move(f.registers); r_[0]=0;
        code_=f.code; pc_=f.return_pc; mask_=f.mask;
        if (f.dest!=0) r_[f.dest]=result;
        if (env_ && env_->state) --env_->state->depth;
        return;
      }
    case Opcode::halt: fail(VmErrorCode::no_return,last_pc_); return;
    default: fail(VmErrorCode::invalid_bytecode,last_pc_); return;
  }
  if (value<std::numeric_limits<std::int32_t>::min() || value>std::numeric_limits<std::int32_t>::max()) { fail(VmErrorCode::overflow,last_pc_); return; }
  r_[i.a]=static_cast<std::int32_t>(value);
}

} // namespace poko::mute
