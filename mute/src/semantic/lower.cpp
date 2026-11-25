#include "poko/mute/lower.hpp"
#include "poko/mute/determinism.hpp"
#include "poko/mute/hostcall.hpp"
#include <array>
#include <map>
#include <set>
namespace poko::mute {
namespace {
Type i32t() { return {TypeTag::scalar,"i32",{}}; }
Type boolt() { return {TypeTag::scalar,"bool",{}}; }
Type unit_t() { return {TypeTag::unit,"",{}}; }
IrOperand v(std::uint32_t id) { return {id,0}; }
IrOperand pv(std::uint32_t id,std::uint64_t imm) { return {id,imm}; }

// TypeNode -> Type, mirroring semantic.cpp's conversion. Aggregate names the
// VM cannot represent become unknown (verify treats unknown as compatible).
Type convert_type(const DeclarationAst& ast,std::size_t index) {
  const auto& types=ast.types();
  if (index>=types.size()) return unit_t();
  const auto& node=types[index];
  if (node.kind==TypeKind::tuple) {
    Type t{TypeTag::tuple,"",{}};
    for (const auto arg:node.args) t.args.push_back(convert_type(ast,arg));
    return t;
  }
  if (node.kind==TypeKind::generic) {
    Type t;
    t.tag = node.spelling=="array"?TypeTag::array : node.spelling=="option"?TypeTag::option :
            node.spelling=="map"?TypeTag::map : node.spelling=="result"?TypeTag::result :
            TypeTag::unknown;
    t.name=node.spelling;
    for (const auto arg:node.args) t.args.push_back(convert_type(ast,arg));
    return t;
  }
  if (node.spelling=="Unit" || node.spelling=="unit") return unit_t();
  if (node.spelling=="Never" || node.spelling=="never") return {TypeTag::never,"Never",{}};
  constexpr auto scalars=std::to_array<std::string_view>({
    "bool","i8","i16","i32","i64","u8","u16","u32","u64","f32","f64","string"});
  for (const auto s:scalars) if (node.spelling==s) return {TypeTag::scalar,node.spelling,{}};
  return {TypeTag::unknown,node.spelling,{}};
}
// `@requires(Net, Time)` -> mask. Unknown names contribute no bits, matching
// program_capability_mask's allow: handling (the safe direction: narrower).
std::uint32_t requires_mask(std::string_view spelling) {
  const auto open=spelling.find('(');
  if (open==std::string_view::npos) return 0;
  const auto close=spelling.rfind(')');
  if (close==std::string_view::npos || close<open) return 0;
  std::uint32_t mask=0;
  auto list=spelling.substr(open+1,close-open-1);
  while (!list.empty()) {
    const auto comma=list.find(',');
    auto item=list.substr(0,comma);
    while (!item.empty() && (item.front()==' '||item.front()=='\t')) item.remove_prefix(1);
    while (!item.empty() && (item.back()==' '||item.back()=='\t')) item.remove_suffix(1);
    mask |= capability_from_name(item);
    if (comma==std::string_view::npos) break;
    list.remove_prefix(comma+1);
  }
  return mask;
}

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
  Lowerer(const StatementAst& body,const Type& result,std::span<const LowerParam> params,
          std::span<const LowerSignature> sigs,std::uint32_t capabilities)
      : body_(body),result_(result),sigs_(sigs) {
    fn_.name="f"; fn_.result=result; fn_.capabilities=capabilities;
    for (const auto& p:params) {
      env_[p.name]={static_cast<std::uint32_t>(fn_.params.size()+1),p.type};
      fn_.params.push_back(p.type);
    }
    for (std::size_t i=0;i<sigs_.size();++i)
      sig_index_.emplace(sigs_[i].name,i);
    fn_.blocks.push_back(IrBlock{"entry"});
    used_labels_.insert("entry");
    // Params occupy ids 1..N; generated defs must not collide with them.
    next_id_=static_cast<std::uint32_t>(params.size());
  }
  LowerResult run() {
    if (body_.root()<body_.nodes().size()) stmt(body_.root());
    finish();
    return {std::move(fn_),std::move(diags_)};
  }
 private:
  void diag(IrErrorCode c,std::string d,std::size_t b=0) { diags_.push_back({c,std::move(d),0,b,pos_}); }
  IrBlock& blk() { return fn_.blocks[cur_]; }
  bool terminated() const { const auto& b=fn_.blocks[cur_]; return !b.instrs.empty() && is_term(b.instrs.back().op); }
  static bool is_term(IrOp op) { return op==IrOp::jump||op==IrOp::branch||op==IrOp::return_; }
  // Block labels must be unique for verify(); nested control flow reuses
  // the same base names, so collisions get a deterministic .N suffix.
  std::size_t new_block(std::string label) {
    if (!used_labels_.insert(label).second) {
      for (std::size_t n=1;;++n) {
        auto cand=label+"."+std::to_string(n);
        if (used_labels_.insert(cand).second) { label=std::move(cand); break; }
      }
    }
    fn_.blocks.push_back(IrBlock{std::move(label)}); return fn_.blocks.size()-1;
  }
  std::uint32_t emit(IrInstr in) {
    if (in.pos.line==0) in.pos=pos_; if (in.def==0) in.def=++next_id_;
    blk().instrs.push_back(std::move(in)); return in.def;
  }
  void term(IrInstr in) { if (in.pos.line==0) in.pos=pos_; blk().instrs.push_back(std::move(in)); }
  std::uint32_t emit_into(std::size_t block,IrInstr in) {
    if (in.pos.line==0) in.pos=pos_; if (in.def==0) in.def=++next_id_;
    fn_.blocks[block].instrs.push_back(std::move(in)); return in.def;
  }
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
    const auto& n=ast.nodes()[ni]; pos_=n.begin;
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
          IrInstr u; u.op=IrOp::unary; u.detail=0; u.result=a.type; u.args={v(a.id)}; u.pos=n.begin;
          return {emit(std::move(u)),a.type};
        }
        if (n.op==ExprOp::not_op) {
          IrInstr u; u.op=IrOp::compare; u.detail=1; u.result=boolt(); u.args={v(a.id),v(0)}; u.pos=n.begin;
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
        IrInstr in; in.pos=n.begin;
        if (is_arith(n.op)) { in.op=IrOp::binary; in.detail=bin_detail(n.op); in.result=i32t(); }
        else if (is_cmp(n.op)) { in.op=IrOp::compare; in.detail=cmp_detail(n.op); in.result=boolt(); }
        else { diag(IrErrorCode::bad_operand_count,"unsupported binary"); return {0,i32t()}; }
        in.args={v(l.id),v(r.id)}; const Type rty=in.result; return {emit(std::move(in)),rty};
      }
      case ExprKind::call: {
        if (n.left>=ast.nodes().size() || ast.nodes()[n.left].kind!=ExprKind::identifier) {
          diag(IrErrorCode::type_mismatch,"call target must be a function name");
          return {0,i32t()};
        }
        const auto& target=ast.nodes()[n.left];
        const auto it=sig_index_.find(target.spelling);
        if (it==sig_index_.end()) {
          diag(IrErrorCode::undefined_value,"unknown function "+target.spelling,n.left);
          return {0,i32t()};
        }
        const auto& sig=sigs_[it->second];
        if (n.children.size()!=sig.params.size()) {
          diag(IrErrorCode::bad_operand_count,
               "call arity "+std::to_string(n.children.size())+" vs "+std::to_string(sig.params.size()));
          return {0,sig.result};
        }
        IrInstr call; call.op=IrOp::call; call.pos=n.begin;
        call.callee=static_cast<std::uint32_t>(it->second+1); call.result=sig.result;
        for (const auto c:n.children) {
          const auto arg=eval_node(ast,c);
          call.args.push_back(v(arg.id));
        }
        return {emit(std::move(call)),sig.result};
      }
      default:
        diag(IrErrorCode::type_mismatch,"unsupported expression kind");
        return {0,i32t()};
    }
  }
  void stmt(std::size_t si) {
    if (si>=body_.nodes().size() || terminated()) return;
    const auto& n=body_.nodes()[si]; pos_=n.begin;
    switch (n.kind) {
      case StatementKind::block:
        for (const auto c:n.children) stmt(c);
        break;
      case StatementKind::let_stmt: case StatementKind::var_stmt: {
        auto val=eval(n.expression); env_[n.spelling]=val; break;
      }
      case StatementKind::expression: {
        // Assignment statements rebind the environment (SSA values are
        // immutable; the name simply points at the new def).
        if (n.expression!=no_statement && n.expression<body_.expressions().size()) {
          const auto& ast=body_.expressions()[n.expression];
          if (ast.root()<ast.nodes().size()) {
            const auto& root=ast.nodes()[ast.root()];
            if (root.kind==ExprKind::binary && root.left<ast.nodes().size() &&
                ast.nodes()[root.left].kind==ExprKind::identifier &&
                (root.op==ExprOp::assign||root.op==ExprOp::assign_add||root.op==ExprOp::assign_sub||
                 root.op==ExprOp::assign_mul||root.op==ExprOp::assign_div||root.op==ExprOp::assign_mod)) {
              const auto name=ast.nodes()[root.left].spelling;
              auto it=env_.find(name);
              if (it==env_.end()) { diag(IrErrorCode::undefined_value,"assign to unknown "+name); break; }
              if (root.op==ExprOp::assign) { env_[name]=eval_node(ast,root.right); break; }
              const auto rhs=eval_node(ast,root.right);
              const auto bop=root.op==ExprOp::assign_add?ExprOp::plus:root.op==ExprOp::assign_sub?ExprOp::minus:
                root.op==ExprOp::assign_mul?ExprOp::multiply:root.op==ExprOp::assign_div?ExprOp::divide:
                ExprOp::remainder;
              IrInstr in; in.op=IrOp::binary; in.detail=bin_detail(bop);
              in.result=it->second.type; in.args={v(it->second.id),v(rhs.id)};
              const Type aty=in.result; env_[name]={emit(std::move(in)),aty};
              break;
            }
          }
        }
        eval(n.expression); break;
      }
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
        std::size_t else_last=0;
        if (else_i) {
          cur_=else_i; env_=pre; stmt(n.children[1]); else_env=env_;
          if (!terminated()) jump_to(join);
          else_last=cur_;
        }
        // Merge envs at join: phi for names whose value differs per arm.
        // Join predecessors are actual blocks: the then fall-through, the
        // else fall-through, or — with no else — the branch block itself,
        // which carries the pre-if env on the false edge.
        cur_=join; env_=pre;
        const auto preds=preds_of(join);
        std::set<std::string> names;
        for (const auto& [k,_]:then_env) names.insert(k);
        for (const auto& [k,_]:else_env) names.insert(k);
        for (const auto& name:names) {
          // Per-predecessor value: then fall-through, else fall-through, or
          // the branch block's false edge carrying the pre-if env.
          auto src_for=[&](std::size_t p)->const Val* {
            if (p==then_last) return then_env.count(name)?&then_env.at(name):nullptr;
            if (else_i && p==else_last) return else_env.count(name)?&else_env.at(name):nullptr;
            return pre.count(name)?&pre.at(name):nullptr;
          };
          std::uint32_t first_id=0; Type first_ty{}; bool uniform=true, seen=false;
          for (const auto p:preds) {
            const auto* s=src_for(p);
            const auto id=s?s->id:0;
            if (!seen) { seen=true; first_id=id; if (s) first_ty=s->type; }
            else if (id!=first_id) uniform=false;
          }
          if (uniform) {
            if (first_id!=0) env_[name]={first_id,first_ty};
            continue;
          }
          Type name_ty=i32t();
          if (then_env.count(name)) name_ty=then_env.at(name).type;
          else if (else_env.count(name)) name_ty=else_env.at(name).type;
          else if (pre.count(name)) name_ty=pre.at(name).type;
          IrInstr phi; phi.op=IrOp::phi; phi.result=name_ty;
          for (const auto p:preds) {
            const auto* s=src_for(p);
            const auto id=s?s->id:0;
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
            phi.args.push_back(pv(id,static_cast<std::uint64_t>(p+1)));
          }
          phi.def=0; const auto id=emit(std::move(phi));
          env_[name]={id,name_ty}; // phi.result is moved-from after emit()
        }
        break;
      }
      case StatementKind::while_stmt: {
        const auto pre=env_;
        const auto header=new_block("while.cond"), body_b=new_block("while.body"), exit=new_block("while.exit");
        const auto preheader=cur_;
        jump_to(header);
        // Pre-assign a phi id for every live name: the header phi merges the
        // pre-loop value (preheader edge) with the body-end value (back edge).
        Env loop_env;
        std::vector<std::pair<std::string,std::uint32_t>> phi_ids;
        for (const auto& [name,val]:pre) {
          IrInstr phi; phi.op=IrOp::phi; phi.result=val.type; phi.def=0;
          const auto id=emit_into(header,std::move(phi));
          phi_ids.push_back({name,id});
          loop_env[name]={id,val.type};
        }
        cur_=header; env_=loop_env;
        const auto cond=eval(n.expression);
        IrInstr br; br.op=IrOp::branch; br.args={v(cond.id)}; br.target=body_b+1; br.target2=exit+1;
        term(std::move(br));
        cur_=body_b; env_=loop_env;
        loop_stack_.push_back({exit,header});
        stmt(n.children[0]);
        if (!terminated()) jump_to(header);
        loop_stack_.pop_back();
        const auto body_last=cur_;
        // Fill phi operands now that both preds are known.
        const auto preds=preds_of(header);
        for (auto& [name,id]:phi_ids) {
          for (auto& in:fn_.blocks[header].instrs) {
            if (in.op!=IrOp::phi || in.def!=id) continue;
            in.args.clear();
            for (const auto p:preds) {
              const auto vid=(p==preheader?pre.at(name).id:env_.at(name).id);
              in.args.push_back(pv(vid,static_cast<std::uint64_t>(p+1)));
              in.args.push_back(pv(vid,static_cast<std::uint64_t>(p+1)));
            }
          }
        }
        cur_=exit; env_=loop_env;
        break;
      }
      case StatementKind::for_stmt: {
        // for name in lo..hi { body }  desugars to a counted while loop.
        const auto pre=env_;
        if (n.expression==no_statement || n.expression>=body_.expressions().size()) {
          diag(IrErrorCode::bad_operand_count,"for without iterable"); break;
        }
        const auto& ast=body_.expressions()[n.expression];
        if (ast.root()>=ast.nodes().size()) { diag(IrErrorCode::bad_operand_count,"bad iterable"); break; }
        const auto& it=ast.nodes()[ast.root()];
        const bool inclusive=it.op==ExprOp::range_inclusive;
        if (it.kind!=ExprKind::binary || (it.op!=ExprOp::range && !inclusive)) {
          diag(IrErrorCode::type_mismatch,"for requires a range iterable"); break;
        }
        const auto lo=eval_node(ast,it.left), hi=eval_node(ast,it.right);
        env_[n.spelling]=lo;
        const auto pre2=env_;
        const auto header=new_block("for.cond"), body_b=new_block("for.body"),
                   inc=new_block("for.inc"), exit=new_block("for.exit");
        const auto preheader=cur_;
        jump_to(header);
        Env loop_env; std::vector<std::pair<std::string,std::uint32_t>> phi_ids;
        for (const auto& [name,val]:pre2) {
          IrInstr phi; phi.op=IrOp::phi; phi.result=val.type; phi.def=0;
          const auto id=emit_into(header,std::move(phi));
          phi_ids.push_back({name,id}); loop_env[name]={id,val.type};
        }
        cur_=header; env_=loop_env;
        // cond: name <= hi (or < hi for exclusive range)
        IrInstr cmp; cmp.op=IrOp::compare; cmp.detail=inclusive?3:2; cmp.result=boolt();
        cmp.args={v(loop_env[n.spelling].id),v(hi.id)};
        const auto cid=emit(std::move(cmp));
        IrInstr br; br.op=IrOp::branch; br.args={v(cid)}; br.target=body_b+1; br.target2=exit+1;
        term(std::move(br));
        cur_=body_b; env_=loop_env;
        loop_stack_.push_back({exit,inc});
        stmt(n.children[0]);
        if (!terminated()) jump_to(inc);
        const auto body_last=cur_;
        // increment block: name = name + 1; jump header
        cur_=inc; env_=env_; // body-end env carries loop var value
        {
          auto curv=env_[n.spelling];
          IrInstr one; one.op=IrOp::constant; one.result=i32t(); one.args={pv(0,1)};
          const auto one_id=emit(std::move(one));
          IrInstr add; add.op=IrOp::binary; add.detail=0; add.result=i32t();
          add.args={v(curv.id),v(one_id)};
          env_[n.spelling]={emit(std::move(add)),i32t()};
          jump_to(header);
        }
        loop_stack_.pop_back();
        const auto inc_last=cur_;
        const auto preds=preds_of(header);
        for (auto& [name,id]:phi_ids) {
          for (auto& in:fn_.blocks[header].instrs) {
            if (in.op!=IrOp::phi || in.def!=id) continue;
            in.args.clear();
            for (const auto p:preds) {
              std::uint32_t vid;
              if (p==preheader) vid=pre2.at(name).id;
              else if (p==inc_last) vid=env_.at(name).id;   // post-increment value
              else vid=env_.count(name)?env_[name].id:pre2.at(name).id;
              in.args.push_back(pv(vid,static_cast<std::uint64_t>(p+1)));
              in.args.push_back(pv(vid,static_cast<std::uint64_t>(p+1)));
            }
          }
        }
        cur_=exit; env_=loop_env;
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
  std::set<std::string> used_labels_;
  Position pos_{};
  std::span<const LowerSignature> sigs_;
  std::map<std::string,std::size_t> sig_index_;
};
} // namespace

LowerResult lower_function(const StatementAst& body,std::string_view name,const Type& result,
                           std::span<const LowerParam> params) {
  return lower_function_ex(body,name,result,params,{});
}

LowerResult lower_function_ex(const StatementAst& body,std::string_view name,const Type& result,
                              std::span<const LowerParam> params,
                              std::span<const LowerSignature> sigs,
                              std::uint32_t capabilities) {
  Lowerer l(body,result,params,sigs,capabilities);
  // params must be bound before run; Lowerer ctor already did env_/params.
  auto r=l.run(); r.fn.name=std::string(name);
  // Append implicit return for any unterminated tail already handled in run().
  return r;
}

LowerModuleResult lower_module(const DeclarationAst& ast) {
  LowerModuleResult out;
  const auto& nodes=ast.nodes();
  const auto ceiling=program_capability_mask(ast);
  std::vector<LowerSignature> sigs;
  std::vector<std::size_t> decls;
  for (std::size_t i=0;i<nodes.size();++i) {
    const auto& n=nodes[i];
    if (n.kind!=DeclarationKind::fn_decl) continue;
    LowerSignature sig;
    sig.name=n.spelling;
    sig.result=n.type==no_declaration?unit_t():convert_type(ast,n.type);
    bool narrowed=false;
    std::uint32_t required=0;
    for (const auto child:n.children) {
      if (child>=nodes.size()) continue;
      const auto& c=nodes[child];
      if (c.kind==DeclarationKind::attribute) {
        if (c.spelling.rfind("@requires",0)==0) {
          narrowed=true; required|=requires_mask(c.spelling);
        }
      } else if (c.kind==DeclarationKind::param) {
        sig.params.push_back(c.type==no_declaration?unit_t():convert_type(ast,c.type));
      }
    }
    if (narrowed) sig.capabilities=ceiling&required;
    sigs.push_back(std::move(sig));
    decls.push_back(i);
  }
  for (std::size_t fi=0;fi<decls.size();++fi) {
    const auto& n=nodes[decls[fi]];
    const auto& sig=sigs[fi];
    std::vector<LowerParam> params;
    for (const auto child:n.children) {
      if (child>=nodes.size() || nodes[child].kind!=DeclarationKind::param) continue;
      const auto& p=nodes[child];
      params.push_back({p.spelling,p.type==no_declaration?unit_t():convert_type(ast,p.type)});
    }
    if (n.body>=ast.bodies().size()) {
      out.diagnostics.push_back({IrErrorCode::missing_entry,"missing body",fi,0,n.begin});
      out.module.functions.push_back(IrFunction{sig.name,sig.result,sig.params,sig.capabilities,{}});
      continue;
    }
    auto lr=lower_function_ex(ast.bodies()[n.body],sig.name,sig.result,params,sigs,sig.capabilities);
    for (auto& d:lr.diagnostics) { d.function=fi; out.diagnostics.push_back(std::move(d)); }
    // Keep one IR function per signature entry even on diagnostics: callee
    // indices are part of the module contract and must stay aligned.
    out.module.functions.push_back(std::move(lr.fn));
  }
  return out;
}
} // namespace poko::mute
