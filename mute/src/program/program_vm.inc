// Internal source-program compiler and register interpreter for the MUT-01–07 subset.
// Included inside program.cpp's anonymous namespace so AST views stay call-local.
enum class VmOp : std::uint8_t {
  expr_enter=0, block_enter=1, depth_leave=2, step=3, literal=4, negative_literal=5, boolean=6,
  load_local=7, unary=8, binary=9, short_guard=10, bool_copy=11, call_check=12, args_begin=13, arg_push=14, call=15,
  decl_check=16, declare_local=17, assign_check=18, assign_local=19, scope_enter=20, scope_leave=21,
  branch_false=22, jump=23, ret=24, missing_return=25
};
struct VmInstruction {
  VmOp op; Position pos{}; std::string_view text{};
  std::size_t a=0,b=0;
};
using VmCode=std::vector<VmInstruction>;
struct CompiledProgram { std::vector<VmCode> functions; VmCode main; };
class ProgramCompiler {
 public:
  explicit ProgramCompiler(const Program& program):p_(program) {}
  CompiledProgram compile() {
    CompiledProgram result;result.functions.reserve(p_.functions.size());
    for (const auto& f:p_.functions) {
      code_=&result.functions.emplace_back(); used_=0; block(f.body,f.pos);
      emit(VmOp::missing_return,f.pos);
    }
    code_=&result.main;used_=0;const auto result_reg=expr(p_.main,0);
    emit(VmOp::ret,p_.exprs[p_.main].pos,{},result_reg); release(result_reg);
    return result;
  }
 private:
  std::size_t emit(VmOp op,Position pos,std::string_view text={},std::size_t a=0,std::size_t b=0) {
    if (code_->size()>=131072) fail("compile","instruction_limit",pos);
    code_->push_back(VmInstruction{op,pos,text,a,b});return code_->size()-1;
  }
  std::size_t reserve(Position pos) {
    if (used_>=256) fail("compile","register_limit",pos);
    return used_++;
  }
  void release(std::size_t reg) {
    if (used_==0 || reg!=used_-1) fail("compile","register_internal_error",Position{0,1,1});
    --used_;
  }
  std::size_t expr(std::size_t index,std::size_t depth) {
    const auto& e=p_.exprs[index];
    // This entry cannot execute successfully when 128 expression entries are
    // already active. Keep the trap in the emitted path, not at compile time.
    if (depth>=eval_depth_limit) {
      emit(VmOp::expr_enter,e.pos);
      const auto r=reserve(e.pos);
      emit(VmOp::boolean,e.pos,"false",r);
      emit(VmOp::depth_leave,e.pos);
      return r;
    }
    emit(VmOp::expr_enter,e.pos);
    std::size_t result=0;
    switch (e.kind) {
      case Expr::Kind::integer: case Expr::Kind::boolean: case Expr::Kind::variable:
        result=reserve(e.pos);
        emit(e.kind==Expr::Kind::integer ? VmOp::literal : e.kind==Expr::Kind::boolean ? VmOp::boolean : VmOp::load_local,e.pos,e.text,result);
        break;
      case Expr::Kind::unary:
        if (e.text=="-" && p_.exprs[e.left].kind==Expr::Kind::integer) {
          result=reserve(e.pos);emit(VmOp::negative_literal,e.pos,p_.exprs[e.left].text,result);
        } else {
          result=expr(e.left,depth+1);emit(VmOp::unary,e.pos,e.text,result);
        }
        break;
      case Expr::Kind::binary: {
        result=expr(e.left,depth+1);
        if (e.text=="&&" || e.text=="||") {
          auto guard=emit(VmOp::short_guard,e.pos,e.text,result);
          auto right=expr(e.right,depth+1);emit(VmOp::bool_copy,e.pos,{},result,right);release(right);
          (*code_)[guard].b=code_->size();
        } else {
          auto right=expr(e.right,depth+1);emit(VmOp::binary,e.pos,e.text,result,right);release(right);
        }
        break;
      }
      case Expr::Kind::call: {
        emit(VmOp::call_check,e.pos,e.text,0,e.args.size());
        emit(VmOp::args_begin,e.pos,{},e.args.size());
        for (auto arg:e.args) {
          const auto reg=expr(arg,depth+1);
          // Spill evaluated arguments into this call's bounded argument area.
          // This keeps earlier arguments alive without consuming 256 registers.
          emit(VmOp::arg_push,p_.exprs[arg].pos,{},reg);release(reg);
        }
        result=reserve(e.pos);
        emit(VmOp::call,e.pos,e.text,result);
        break;
      }
    }
    emit(VmOp::depth_leave,e.pos);return result;
  }
  void block(const std::vector<Stmt>& body,Position pos) {
    emit(VmOp::block_enter,pos);
    for (const auto& s:body) {
      emit(VmOp::step,s.pos);
      switch (s.kind) {
        case Stmt::Kind::declare_let: case Stmt::Kind::declare_var: {
          emit(VmOp::decl_check,s.pos,s.text); auto r=expr(s.expr,0);
          emit(VmOp::declare_local,p_.exprs[s.expr].pos,s.text,r,s.kind==Stmt::Kind::declare_var?1U:0U);release(r);break;
        }
        case Stmt::Kind::assign: {
          emit(VmOp::assign_check,s.pos,s.text);auto r=expr(s.expr,0);
          emit(VmOp::assign_local,p_.exprs[s.expr].pos,s.text,r);release(r);break;
        }
        case Stmt::Kind::ret: {
          auto r=expr(s.expr,0);emit(VmOp::ret,p_.exprs[s.expr].pos,{},r);release(r);break;
        }
        case Stmt::Kind::conditional: {
          auto r=expr(s.expr,0);auto branch=emit(VmOp::branch_false,p_.exprs[s.expr].pos,{},r);release(r);
          emit(VmOp::scope_enter,s.pos);block(s.yes,s.pos);emit(VmOp::scope_leave,s.pos);
          auto end=emit(VmOp::jump,s.pos);(*code_)[branch].b=code_->size();
          emit(VmOp::scope_enter,s.pos);block(s.no,s.pos);emit(VmOp::scope_leave,s.pos);
          (*code_)[end].a=code_->size();break;
        }
        case Stmt::Kind::while_loop: {
          const auto loop=code_->size();emit(VmOp::step,s.pos);auto r=expr(s.expr,0);
          auto branch=emit(VmOp::branch_false,p_.exprs[s.expr].pos,{},r);release(r);
          emit(VmOp::scope_enter,s.pos);block(s.yes,s.pos);emit(VmOp::scope_leave,s.pos);
          emit(VmOp::jump,s.pos,{},loop);(*code_)[branch].b=code_->size();break;
        }
      }
    }
    emit(VmOp::depth_leave,pos);
  }
  const Program& p_;VmCode* code_=nullptr;std::size_t used_=0;
};
class ProgramVm {
 public:
  ProgramVm(const Program& p,const CompiledProgram& c,std::size_t max_steps,Scope* globals=nullptr):p_(p),c_(c),max_steps_(max_steps),globals_(globals) {}
  NumericValue run() { Frame frame;frame.scopes.emplace_back();return execute(c_.main,frame); }
 private:
  struct RestoreDepth { std::size_t& depth;std::size_t saved;~RestoreDepth(){depth=saved;} };
  void step(Position p) {if (steps_>=max_steps_) fail("runtime","budget_exceeded",p);++steps_;}
  Local* find(Frame& f,std::string_view name) {
    for (auto scope=f.scopes.rbegin();scope!=f.scopes.rend();++scope)
      for (auto& local:*scope) if (local.name==name) return &local;
    if (globals_) for (auto& global:*globals_) if (global.name==name) return &global;
    return nullptr;
  }
  const Function& function(std::string_view name,Position pos) const {
    const auto it=std::find_if(p_.functions.begin(),p_.functions.end(),[&](const auto& f){return f.name==name;});
    if (it==p_.functions.end()) fail("runtime","unknown_function",pos);
    return *it;
  }
  static NumericValue int_operation(Opcode op,const NumericValue& left,const NumericValue& right,Position pos) {
    std::array<std::int32_t,256> regs{};
    regs[1]=static_cast<std::int32_t>(std::get<std::int64_t>(left.data));
    regs[2]=static_cast<std::int32_t>(std::get<std::int64_t>(right.data));
    const std::array instructions{Instruction{op,3,1,2},Instruction{Opcode::ret,3,0,0}};
    auto value=run_register_vm(instructions,regs,2);
    if (const auto* e=std::get_if<VmError>(&value)) {
      if (e->code==VmErrorCode::divide_by_zero) fail("eval","divide_by_zero",pos);
      if (e->code==VmErrorCode::overflow) fail("eval","arithmetic_overflow",pos);
      fail("runtime","invalid_bytecode",pos);
    }
    return NumericValue{NumericType::i32,static_cast<std::int64_t>(std::get<std::int32_t>(value))};
  }
  NumericValue execute(const VmCode& code,Frame& frame) {
    RestoreDepth restore{eval_depth_,eval_depth_};std::array<Value,256> r{};
    std::vector<std::vector<NumericValue>> pending_args;
    for (std::size_t pc=0;pc<code.size();) {
      const auto& ins=code[pc++];
      switch (ins.op) {
        case VmOp::expr_enter:step(ins.pos);[[fallthrough]];
        case VmOp::block_enter:
          if (eval_depth_>=eval_depth_limit) fail("runtime","depth_exceeded",ins.pos);
          ++eval_depth_;break;
        case VmOp::depth_leave:--eval_depth_;break;
        case VmOp::step:step(ins.pos);break;
        case VmOp::literal:r[ins.a]=Runner::arithmetic(ins.text,ins.pos);break;
        case VmOp::negative_literal:r[ins.a]=Runner::arithmetic(std::string("-")+std::string(ins.text),ins.pos);break;
        case VmOp::boolean:r[ins.a]=(ins.text=="true");break;
        case VmOp::load_local:{auto* l=find(frame,ins.text);if (!l) fail("runtime","unknown_local",ins.pos);r[ins.a]=l->value;break;}
        case VmOp::unary: {
          if (ins.text=="!") {r[ins.a]=!Runner::as_bool(r[ins.a],ins.pos);break;}
          auto v=Runner::as_number(r[ins.a],ins.pos);
          if (ins.text=="+") {r[ins.a]=v;break;}
          const NumericValue zero{NumericType::i32,std::int64_t{0}};
          r[ins.a]=int_operation(Opcode::sub,zero,v,ins.pos);break;
        }
        case VmOp::binary: {
          const auto& l=r[ins.a];const auto& right=r[ins.b];
          if (ins.text=="=="||ins.text=="!=") {
            bool eq;
            if (const auto* b=std::get_if<bool>(&l)) eq=*b==Runner::as_bool(right,ins.pos);
            else eq=std::get<std::int64_t>(Runner::as_number(l,ins.pos).data)==std::get<std::int64_t>(Runner::as_number(right,ins.pos).data);
            r[ins.a]=ins.text=="==" ? eq : !eq;break;
          }
          auto x=Runner::as_number(l,ins.pos),y=Runner::as_number(right,ins.pos);
          if (ins.text=="<"||ins.text=="<="||ins.text==">"||ins.text==">=") {
            const auto a=std::get<std::int64_t>(x.data),b=std::get<std::int64_t>(y.data);
            r[ins.a]=ins.text=="<" ? a<b : ins.text=="<=" ? a<=b : ins.text==">" ? a>b : a>=b;break;
          }
          const auto op=ins.text=="+" ? Opcode::add : ins.text=="-" ? Opcode::sub :
                        ins.text=="*" ? Opcode::mul : ins.text=="/" ? Opcode::div : Opcode::mod;
          r[ins.a]=int_operation(op,x,y,ins.pos);break;
        }
        case VmOp::short_guard:{const bool b=Runner::as_bool(r[ins.a],ins.pos);if ((ins.text=="&&"&&!b)||(ins.text=="||"&&b)) pc=ins.b;break;}
        case VmOp::bool_copy:r[ins.a]=Runner::as_bool(r[ins.b],ins.pos);break;
        case VmOp::call_check:{const auto& f=function(ins.text,ins.pos);if (f.params.size()!=ins.b) fail("runtime","wrong_arity",ins.pos);break;}
        case VmOp::args_begin:pending_args.emplace_back();pending_args.back().reserve(ins.a);break;
        case VmOp::arg_push:pending_args.back().push_back(Runner::as_number(r[ins.a],ins.pos));break;
        case VmOp::call: {
          const auto& f=function(ins.text,ins.pos);auto args=std::move(pending_args.back());pending_args.pop_back();
          Depth call(call_depth_,call_limit,"runtime",ins.pos);Frame callee;callee.scopes.emplace_back();
          for (std::size_t j=0;j<args.size();++j) callee.scopes.back().push_back(Local{f.params[j],args[j],false});
          callee.local_count=args.size();auto index=static_cast<std::size_t>(&f-p_.functions.data());
          r[ins.a]=execute(c_.functions[index],callee);break;
        }
        case VmOp::decl_check:
          for (const auto& l:frame.scopes.back()) if (l.name==ins.text) fail("runtime","duplicate_local",ins.pos);
          if (frame.local_count>=local_limit) fail("runtime","local_limit",ins.pos);
          break;
        case VmOp::declare_local:frame.scopes.back().push_back(Local{ins.text,Runner::as_number(r[ins.a],ins.pos),ins.b!=0});++frame.local_count;break;
        case VmOp::assign_check:{auto* l=find(frame,ins.text);if (!l) fail("runtime","unknown_local",ins.pos);if (!l->mut) fail("runtime","immutable_local",ins.pos);break;}
        case VmOp::assign_local:{auto* l=find(frame,ins.text);if (!l) fail("runtime","unknown_local",ins.pos);l->value=Runner::as_number(r[ins.a],ins.pos);break;}
        case VmOp::scope_enter:frame.scopes.emplace_back();break;
        case VmOp::scope_leave:frame.local_count-=frame.scopes.back().size();frame.scopes.pop_back();break;
        case VmOp::branch_false:if (!Runner::as_bool(r[ins.a],ins.pos)) pc=ins.b;break;
        case VmOp::jump:pc=ins.a;break;
        case VmOp::ret:return Runner::as_number(r[ins.a],ins.pos);
        case VmOp::missing_return:fail("runtime","missing_return",ins.pos);
      }
    }
    fail("runtime","invalid_bytecode",Position{0,1,1});
  }
  const Program& p_;const CompiledProgram& c_;std::size_t max_steps_,steps_=0,call_depth_=0,eval_depth_=0;Scope* globals_;
};
