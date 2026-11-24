#include "poko/mute/lower.hpp"
#include <map>
#include <set>
namespace poko::mute {
namespace {
Type i32t() { return {TypeTag::scalar,"i32",{}}; }
Type boolt() { return {TypeTag::scalar,"bool",{}}; }
Type unit_t() { return {TypeTag::unit,"",{}}; }
IrOperand v(std::uint32_t id) { return {id,0}; }
IrOperand pv(std::uint32_t id,std::uint64_t imm) { return {id,imm}; }

std::uint8_t bin_detail(ExprOp op) {
  switch (op) {
    case ExprOp::plus: return 0; case ExprOp::minus: return 1;
    case ExprOp::multiply: return 2; case ExprOp::divide: return 3;
    case ExprOp::remainder: return 4;
    default: return 0;
  }
}
std::uint8_t cmp_detail(ExprOp op) {
  switch (op) {
    case ExprOp::eq: return 0; case ExprOp::ne: return 1;
    case ExprOp::lt: return 2; case ExprOp::le: return 3;
    case ExprOp::gt: return 4; case ExprOp::ge: return 5;
    default: return 0;
  }
}
bool is_cmp(ExprOp op) {
  return op==ExprOp::eq||op==ExprOp::ne||op==ExprOp::lt||op==ExprOp::le||op==ExprOp::gt||op==ExprOp::ge;
}
bool is_arith(ExprOp op) {
  return op==ExprOp::plus||op==ExprOp::minus||op==ExprOp::multiply||op==ExprOp::divide||op==ExprOp::remainder;
}

struct Val { std::uint32_t id{0}; Type type{}; };
using Env = std::map<std::string,Val>;

class Lowerer {
 public:
  Lowerer(const StatementAst& body,const Type& result,std::span<const LowerParam> params)
      : body_(body),result_(result) {
    fn_.name="f"; fn_.result=result;
    for (const auto& p:params) {
      env_[p.name]={static_cast<std::uint32_t>(fn_.params.size()+1),p.type};
      fn_.params.push_back(p.type);
    }
    fn_.blocks.push_back(IrBlock{"entry"});
  }
  LowerResult run() {
    if (body_.root()<body_.nodes().size()) stmt(body_.root());
    finish();
    return {std::move(fn_),std::move(diags_)};
  }
 private:
  void diag(IrErrorCode c,std::string d,std::size_t b=0) { diags_.push_back({c,std::move(d),0,b}); }
  IrBlock& blk() { return fn_.blocks[cur_]; }
  bool terminated() const { const auto& b=fn_.blocks[cur_]; return !b.instrs.empty() && is_term(b.instrs.back().op); }
  static bool is_term(IrOp op) { return op==IrOp::jump||op==IrOp::branch||op==IrOp::return_; }
  std::size_t new_block(std::string label) { fn_.blocks.push_back(IrBlock{std::move(label)}); return fn_.blocks.size()-1; }
  std::uint32_t emit(IrInstr in) {
    if (in.def==0) in.def=++next_id_;
    blk().instrs.push_back(std::move(in)); return in.def;
  }
  void term(IrInstr in) { blk().instrs.push_back(std::move(in)); }
  void jump_to(std::size_t target) {
    IrInstr j; j.op=IrOp::jump; j.target=static_cast<std::uint32_t>(target+1); term(j);
  }
  // Actual predecessor block indices (0-based) of block `target`.
  std::vector<std::size_t> preds_of(std::size_t target) const {
    std::vector<std::size_t> out;
    for (std::size_t i=0;i<fn_.blocks.size();++i) {
      if (fn_.blocks[i].instrs.empty()) continue;
      const auto& t=fn_.blocks[i].instrs.back();
      if (t.target==target+1 || t.target2==target+1) out.push_back(i);
    }
    return out;
  }
  void finish() {
    for (auto& b:fn_.blocks) if (b.instrs.empty() || !is_term(b.instrs.back().op)) {
      IrInstr r; r.op=IrOp::return_; r.result=result_; b.instrs.push_back(r);
    }
    // Populate declared predecessor lists for the verifier.
    for (std::size_t i=0;i<fn_.blocks.size();++i) {
      auto p=preds_of(i);
      fn_.blocks[i].preds.assign(p.begin(),p.end());
      for (auto& x:fn_.blocks[i].preds) ++x; // store 1-based ids
    }
  }
  Val eval(std::size_t ei) {
    if (ei==no_statement || ei>=body_.expressions().size()) { diag(IrErrorCode::bad_operand_count,"missing expr"); return {0,unit_t()}; }
    const auto& ast=body_.expressions()[ei];
    return eval_node(ast,ast.root());
  }
  Val eval_node(const Ast& ast,std::size_t ni) {
    if (ni>=ast.nodes().size()) { diag(IrErrorCode::undefined_value,"bad expr node"); return {0,unit_t()}; }
    const auto& n=ast.nodes()[ni];
    switch (n.kind) {
      case ExprKind::integer: {
        std::int64_t x=0; try { x=std::stoll(n.spelling); } catch (...) { x=0; }
        IrInstr c; c.op=IrOp::constant; c.result=i32t(); c.args={{0,static_cast<std::uint64_t>(x)}};
        return {emit(std::move(c)),i32t()};
      }
      case ExprKind::boolean: {
        IrInstr c; c.op=IrOp::constant; c.result=boolt(); c.args={pv(0,n.spelling=="true"?1ULL:0ULL)};
        return {emit(std::move(c)),boolt()};
      }
      case ExprKind::unit: {
        IrInstr c; c.op=IrOp::constant; c.result=unit_t(); c.args={pv(0,0)};
        return {emit(std::move(c)),unit_t()};
      }
      case ExprKind::identifier: {
        auto it=env_.find(n.spelling);
        if (it==env_.end()) { diag(IrErrorCode::undefined_value,"unknown name "+n.spelling); return {0,i32t()}; }
        return it->second;
      }
      case ExprKind::unary: {
        auto a=eval_node(ast,n.left);
        if (n.op==ExprOp::neg || n.op==ExprOp::pos) {
          IrInstr u; u.op=IrOp::unary; u.detail=0; u.result=a.type; u.args={v(a.id)};
          return {emit(std::move(u)),a.type};
        }
        if (n.op==ExprOp::not_op) {
          IrInstr u; u.op=IrOp::compare; u.detail=1; u.result=boolt(); u.args={v(a.id),v(0)};
          return {emit(std::move(u)),boolt()};
        }
        diag(IrErrorCode::bad_operand_count,"unsupported unary"); return {0,i32t()};
      }
      case ExprKind::binary: {
        if (n.op==ExprOp::land || n.op==ExprOp::lor) {
          // Short-circuit: branch on left; right evaluated only on the
          // taking edge. Result is a phi of (left,right) per predecessor.
          const auto rhs=new_block("sc.rhs"), join=new_block("sc.join");
          const auto lhs_v=eval_node(ast,n.left);
          IrInstr br; br.op=IrOp::branch; br.args={v(lhs_v.id)};
          br.target=static_cast<std::uint32_t>(n.op==ExprOp::land?rhs+1:join+1);
          br.target2=static_cast<std::uint32_t>(n.op==ExprOp::land?join+1:rhs+1);
          term(std::move(br));
          const auto lhs_last=cur_;
          cur_=rhs; const auto rv=eval_node(ast,n.right);
          if (!terminated()) jump_to(join);
          const auto rhs_last=cur_;
          // merge env: result id differs per path -> phi in join
          cur_=join;
          auto preds=preds_of(join);
          IrInstr phi; phi.op=IrOp::phi; phi.result=boolt();
          // For each actual pred emit two operands (verifier arity = 2*preds)
          for (const auto p:preds) {
            const auto id=(p==lhs_last?lhs_v.id:rv.id);
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
          }
          phi.def=0; const auto id=emit(std::move(phi));
          return {id,boolt()};
        }
        auto l=eval_node(ast,n.left), r=eval_node(ast,n.right);
        IrInstr in;
        if (is_arith(n.op)) { in.op=IrOp::binary; in.detail=bin_detail(n.op); in.result=i32t(); }
        else if (is_cmp(n.op)) { in.op=IrOp::compare; in.detail=cmp_detail(n.op); in.result=boolt(); }
        else { diag(IrErrorCode::bad_operand_count,"unsupported binary"); return {0,i32t()}; }
        in.args={v(l.id),v(r.id)}; return {emit(std::move(in)),in.result};
      }
      default:
        diag(IrErrorCode::type_mismatch,"unsupported expression kind");
        return {0,i32t()};
    }
  }
  void stmt(std::size_t si) {
    if (si>=body_.nodes().size() || terminated()) return;
    const auto& n=body_.nodes()[si];
    switch (n.kind) {
      case StatementKind::block:
        for (const auto c:n.children) stmt(c);
        break;
      case StatementKind::let_stmt: case StatementKind::var_stmt: {
        auto val=eval(n.expression); env_[n.spelling]=val; break;
      }
      case StatementKind::expression: eval(n.expression); break;
      case StatementKind::return_stmt: {
        Val val{0,unit_t()};
        if (n.expression!=no_statement) val=eval(n.expression);
        IrInstr r; r.op=IrOp::return_; r.result=result_; r.args={v(val.id)};
        term(std::move(r)); return;
      }
      case StatementKind::if_stmt: {
        const auto pre=env_;
        const auto cond=eval(n.expression);
        const auto then_i=new_block("then"), else_i=n.children.size()>1?new_block("else"):0, join=new_block("join");
        IrInstr br; br.op=IrOp::branch; br.args={v(cond.id)};
        br.target=then_i+1; br.target2=(else_i?else_i:join)+1;
        term(std::move(br));
        auto then_env=pre, else_env=pre;
        cur_=then_i; env_=pre; stmt(n.children[0]); then_env=env_;
        if (!terminated()) jump_to(join);
        const auto then_last=cur_;
        if (else_i) {
          cur_=else_i; env_=pre; stmt(n.children[1]); else_env=env_;
          if (!terminated()) jump_to(join);
        }
        // Merge envs at join: phi for names whose value differs per arm.
        cur_=join; env_=pre;
        const auto preds=preds_of(join);
        std::set<std::string> names;
        for (const auto& [k,_]:then_env) names.insert(k);
        for (const auto& [k,_]:else_env) names.insert(k);
        for (const auto& name:names) {
          const auto in_then=then_env.count(name), in_else=else_env.count(name);
          const Val tv=in_then?then_env[name]:Val{0,i32t()};
          const Val ev=else_i&&in_else?else_env[name]:Val{0,i32t()};
          if (tv.id==ev.id) { env_[name]=tv; continue; }
          IrInstr phi; phi.op=IrOp::phi; phi.result=tv.type;
          for (const auto p:preds) {
            const auto id=(p==then_last?tv.id:ev.id);
            const auto ty=(p==then_last?tv.type:ev.type);
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
            (void)ty;
          }
          phi.def=0; const auto id=emit(std::move(phi));
          env_[name]={id,tv.type};
        }
        break;
      }
      case StatementKind::while_stmt: {
        const auto pre=env_;
        const auto header=new_block("while.cond"), body_b=new_block("while.body"), exit=new_block("while.exit");
        jump_to(header);
        cur_=header; env_=pre;
        const auto cond=eval(n.expression);
        IrInstr br; br.op=IrOp::branch; br.args={v(cond.id)}; br.target=body_b+1; br.target2=exit+1;
        term(std::move(br));
        cur_=body_b; env_=pre;
        loop_stack_.push_back({exit,header});
        stmt(n.children[0]);
        if (!terminated()) jump_to(header);
        loop_stack_.pop_back();
        cur_=exit; env_=pre; // loop-carried assignments not merged (v1)
        break;
      }
      case StatementKind::loop_stmt: {
        const auto pre=env_;
        const auto body_b=new_block("loop.body"), exit=new_block("loop.exit");
        jump_to(body_b);
        cur_=body_b; env_=pre;
        loop_stack_.push_back({exit,body_b});
        stmt(n.children[0]);
        if (!terminated()) jump_to(body_b);
        loop_stack_.pop_back();
        cur_=exit; env_=pre;
        break;
      }
      case StatementKind::break_stmt: {
        if (loop_stack_.empty()) { diag(IrErrorCode::bad_terminator,"break outside loop"); break; }
        jump_to(loop_stack_.back().first); return;
      }
      case StatementKind::continue_stmt: {
        if (loop_stack_.empty()) { diag(IrErrorCode::bad_terminator,"continue outside loop"); break; }
        jump_to(loop_stack_.back().second); return;
      }
      default:
        diag(IrErrorCode::type_mismatch,"unsupported statement");
        break;
    }
  }
  const StatementAst& body_;
  Type result_;
  IrFunction fn_;
  Env env_;
  std::size_t cur_{0};
  std::uint32_t next_id_{0};
  std::vector<std::pair<std::size_t,std::size_t>> loop_stack_;
  std::vector<IrDiagnostic> diags_;
};
} // namespace

LowerResult lower_function(const StatementAst& body,std::string_view name,const Type& result,std::span<const LowerParam> params) {
  Lowerer l(body,result,params);
  // params must be bound before run; Lowerer ctor already did env_/params.
  auto r=l.run(); r.fn.name=std::string(name);
  // Append implicit return for any unterminated tail already handled in run().
  return r;
}
} // namespace poko::mute
