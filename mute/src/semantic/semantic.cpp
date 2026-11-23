#include "poko/mute/semantic.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace poko::mute {
[[nodiscard]] bool same_type(const Type& a,const Type& b) noexcept {
  if (a.tag!=b.tag || a.name!=b.name || a.args.size()!=b.args.size()) return false;
  for (std::size_t i=0;i<a.args.size();++i) if (!same_type(a.args[i],b.args[i])) return false;
  return true;
}
[[nodiscard]] bool accepts(const Type& target,const Type& value) noexcept {
  if (target.tag==TypeTag::unknown || value.tag==TypeTag::unknown ||
      target.tag==TypeTag::error || value.tag==TypeTag::error) return true;
  if (target.tag==value.tag && target.name==value.name && !target.args.empty() &&
      target.args.size()==value.args.size()) {
    bool compatible=true;
    for (std::size_t i=0;i<target.args.size();++i)
      if (!accepts(target.args[i],value.args[i])) compatible=false;
    if (compatible) return true;
  }
  if (target.tag==TypeTag::never) return false;
  if (value.tag==TypeTag::never) return true;
  if (value.tag==TypeTag::int_literal &&
      (target.tag==TypeTag::scalar) && target.name.size()>1 &&
      (target.name[0]=='i' || target.name[0]=='u')) return true;
  return same_type(target,value);
}
[[nodiscard]] std::string type_name(const Type& type) {
  if (type.tag==TypeTag::unknown) return "?";
  if (type.tag==TypeTag::int_literal) return "int";
  if (type.tag==TypeTag::tuple) {
    std::string out="(";
    for (std::size_t i=0;i<type.args.size();++i) { if (i) out+=", "; out+=type_name(type.args[i]); }
    return out+")";
  }
  if (type.args.empty()) return type.name.empty() ? "unit" : type.name;
  std::string out=type.name+"<";
  for (std::size_t i=0;i<type.args.size();++i) { if (i) out+=", "; out+=type_name(type.args[i]); }
  return out+">";
}
namespace {
[[nodiscard]] Type scalar(std::string_view name) { return {TypeTag::scalar,std::string(name),{}}; }
[[nodiscard]] bool is_integer_scalar(const Type& t) {
  return t.tag==TypeTag::scalar && t.name.size()>1 && (t.name[0]=='i'||t.name[0]=='u') &&
         t.name.find_first_not_of("iu0123456789")==std::string::npos;
}
[[nodiscard]] bool is_float_scalar(const Type& t) {
  return t.tag==TypeTag::scalar && (t.name=="f32"||t.name=="f64");
}
[[nodiscard]] bool numeric(const Type& t) {
  return t.tag==TypeTag::int_literal || is_integer_scalar(t) || is_float_scalar(t);
}
[[nodiscard]] bool is_assign_op(ExprOp op) {
  return op>=ExprOp::assign && op<=ExprOp::assign_shr;
}
[[nodiscard]] int generic_arity(std::string_view name) {
  if (name=="array" || name=="option") return 1;
  if (name=="map" || name=="result") return 2;
  return -1;
}
[[nodiscard]] TypeTag generic_tag(std::string_view name) {
  if (name=="array") return TypeTag::array;
  if (name=="map") return TypeTag::map;
  if (name=="option") return TypeTag::option;
  return TypeTag::result;
}
struct Binding { Type type; Position position; bool mutable_binding; };
struct FunctionSig {
  std::vector<Type> parameters;
  Type result;
  Position position;
};
struct TypeDef {
  bool is_enum{false};
  std::vector<std::string> members;
  std::vector<Type> member_types;
  Position position;
};
class Analyzer {
  const DeclarationAst& ast_;
  std::vector<std::map<std::string,Binding>> scopes_;
  std::map<std::string,FunctionSig> functions_;
  std::map<std::string,TypeDef> types_;
  std::vector<SemanticDiagnostic> diagnostics_;
  Type return_type_{TypeTag::unit,"",{}};

  void report(SemanticErrorCode code,Position at) { diagnostics_.push_back({code,at}); }
  void push_scope() { scopes_.emplace_back(); }
  void pop_scope() { scopes_.pop_back(); }
  void bind(const std::string& name,Type type,bool mut,Position at) {
    if (scopes_.empty()) return;
    auto& scope=scopes_.back();
    if (scope.count(name)) { report(SemanticErrorCode::duplicate_binding,at); return; }
    scope.emplace(name,Binding{std::move(type),at,mut});
  }
  [[nodiscard]] const Binding* lookup(const std::string& name) const {
    for (auto i=scopes_.size();i-->0;) {
      const auto it=scopes_[i].find(name);
      if (it!=scopes_[i].end()) return &it->second;
    }
    return nullptr;
  }
  [[nodiscard]] Type convert_type(std::size_t index) {
    const auto& types=ast_.types();
    if (index>=types.size()) return {TypeTag::error,"",{}};
    const auto& node=types[index];
    if (node.kind==TypeKind::tuple) {
      Type result{TypeTag::tuple,"",{}};
      for (const auto arg:node.args) result.args.push_back(convert_type(arg));
      return result;
    }
    if (node.kind==TypeKind::generic) {
      const auto arity=generic_arity(node.spelling);
      if (arity<0 || static_cast<int>(node.args.size())!=arity) {
        report(SemanticErrorCode::invalid_generic_arity,node.begin);
        return {TypeTag::error,node.spelling,{}};
      }
      Type result{generic_tag(node.spelling),node.spelling,{}};
      for (const auto arg:node.args) result.args.push_back(convert_type(arg));
      if (node.spelling=="map" || node.spelling=="result") {
        if (!same_type(result.args[0],result.args[1]) && result.args[0].tag==TypeTag::int_literal) result.args[0]=result.args[1];
      }
      return result;
    }
    if (node.spelling=="Unit" || node.spelling=="unit") return {TypeTag::unit,"Unit",{}};
    if (node.spelling=="Never" || node.spelling=="never") return {TypeTag::never,"Never",{}};
    constexpr auto scalars=std::to_array<std::string_view>({
      "bool","i8","i16","i32","i64","u8","u16","u32","u64","f32","f64","string"});
    if (std::find(scalars.begin(),scalars.end(),node.spelling)!=scalars.end()) return scalar(node.spelling);
    const auto it=types_.find(node.spelling);
    if (it==types_.end()) { report(SemanticErrorCode::unknown_type,node.begin); return {TypeTag::unknown,node.spelling,{}}; }
    return {it->second.is_enum ? TypeTag::enumeration : TypeTag::structure,node.spelling,{}};
  }
  void collect_types() {
    const auto& nodes=ast_.nodes();
    const auto root=ast_.root();
    if (root>=nodes.size()) return;
    for (auto child:nodes[root].children) {
      if (child>=nodes.size()) continue;
      const auto& node=nodes[child];
      if (node.kind==DeclarationKind::struct_decl || node.kind==DeclarationKind::enum_decl) {
        if (types_.count(node.spelling)) { report(SemanticErrorCode::duplicate_declaration,node.begin); continue; }
        TypeDef def;
        def.is_enum=node.kind==DeclarationKind::enum_decl;
        def.position=node.begin;
        for (auto member:node.children) {
          if (member>=nodes.size()) continue;
          const auto& m=nodes[member];
          if (m.kind==DeclarationKind::field || m.kind==DeclarationKind::variant) {
            def.members.push_back(m.spelling);
            def.member_types.push_back(m.type==no_declaration ? Type{TypeTag::unit,"",{}} : convert_type(m.type));
          }
        }
        types_.emplace(node.spelling,std::move(def));
      } else if (node.kind==DeclarationKind::state_decl || node.kind==DeclarationKind::fn_decl) {
        if (functions_.count(node.spelling) || types_.count(node.spelling)) report(SemanticErrorCode::duplicate_declaration,node.begin);
        if (node.kind==DeclarationKind::fn_decl) {
          FunctionSig sig; sig.position=node.begin;
          sig.result=node.type==no_declaration ? Type{TypeTag::unit,"",{}} : convert_type(node.type);
          for (auto param:node.children) {
            if (param>=nodes.size()) continue;
            const auto& p=nodes[param];
            if (p.kind==DeclarationKind::param) sig.parameters.push_back(p.type==no_declaration ? Type{TypeTag::unknown,"",{}} : convert_type(p.type));
          }
          functions_.emplace(node.spelling,std::move(sig));
        } else {
          FunctionSig sig; sig.position=node.begin;
          sig.result=node.type==no_declaration ? Type{TypeTag::unknown,"",{}} : convert_type(node.type);
          functions_.emplace("state:"+node.spelling,std::move(sig));
        }
      } else if (node.kind==DeclarationKind::import) {
        for (auto alias:node.children) if (alias<nodes.size()) {
          const auto& a=nodes[alias];
          if (types_.count(a.spelling) || functions_.count(a.spelling)) report(SemanticErrorCode::duplicate_declaration,a.begin);
          types_.emplace(a.spelling,TypeDef{false,{}, {},a.begin});
        }
      }
    }
  }
  [[nodiscard]] Type literal_type(const ExprNode& node) const {
    const auto& spelling=node.spelling;
    if (node.kind==ExprKind::boolean) return scalar("bool");
    if (node.kind==ExprKind::string) return scalar("string");
    constexpr auto suffixes=std::to_array<std::string_view>({"i8","i16","i32","i64","u8","u16","u32","u64","f32","f64"});
    for (const auto suffix:suffixes) if (spelling.size()>suffix.size() &&
        spelling.compare(spelling.size()-suffix.size(),suffix.size(),suffix)==0) return scalar(suffix);
    return node.kind==ExprKind::floating ? scalar("f64") : Type{TypeTag::int_literal,"",{}};
  }
  [[nodiscard]] Type infer(const Ast& ast,std::size_t index) {
    const auto nodes=ast.nodes();
    if (index>=nodes.size()) return {TypeTag::error,"",{}};
    const auto& node=nodes[index];
    switch (node.kind) {
      case ExprKind::integer: case ExprKind::floating: case ExprKind::string:
      case ExprKind::boolean: return literal_type(node);
      case ExprKind::unit: return {TypeTag::unit,"Unit",{}};
      case ExprKind::identifier: {
        if (const auto* binding=lookup(node.spelling)) return binding->type;
        const auto qualified="state:"+node.spelling;
        const auto it=functions_.find(qualified);
        if (it!=functions_.end()) return it->second.result;
        report(SemanticErrorCode::unknown_name,node.begin);
        return {TypeTag::unknown,node.spelling,{}};
      }
      case ExprKind::unary: {
        const auto operand=infer(ast,node.left);
        switch (node.op) {
          case ExprOp::not_op:
            if (!same_type(operand,scalar("bool")) && operand.tag!=TypeTag::unknown) report(SemanticErrorCode::trait_not_satisfied,node.begin);
            return scalar("bool");
          case ExprOp::neg: case ExprOp::pos:
            if (!numeric(operand) && operand.tag!=TypeTag::unknown) report(SemanticErrorCode::trait_not_satisfied,node.begin);
            return operand;
          default: return operand;
        }
      }
      case ExprKind::await: return infer(ast,node.left);
      case ExprKind::question: {
        const auto operand=infer(ast,node.left);
        if (operand.tag==TypeTag::option || operand.tag==TypeTag::result) return operand.args.empty() ? Type{TypeTag::unknown,"",{}} : operand.args[0];
        if (operand.tag!=TypeTag::unknown && operand.tag!=TypeTag::error) report(SemanticErrorCode::invalid_operand,node.begin);
        return {TypeTag::unknown,"",{}};
      }
      case ExprKind::binary: {
        const auto left=infer(ast,node.left);
        const auto right=infer(ast,node.right);
        if (is_assign_op(node.op)) {
          if (!accepts(left,right)) report(SemanticErrorCode::invalid_assignment,node.begin);
          if (const auto* binding=lookup(nodes[node.left].spelling))
            if (!binding->mutable_binding) report(SemanticErrorCode::immutable_assignment,node.begin);
          return left;
        }
        if (node.op==ExprOp::land || node.op==ExprOp::lor) {
          if ((!same_type(left,scalar("bool")) || !same_type(right,scalar("bool"))) &&
              left.tag!=TypeTag::unknown && right.tag!=TypeTag::unknown) report(SemanticErrorCode::trait_not_satisfied,node.begin);
          return scalar("bool");
        }
        const bool comparison=node.op==ExprOp::eq||node.op==ExprOp::ne||node.op==ExprOp::lt||
          node.op==ExprOp::le||node.op==ExprOp::gt||node.op==ExprOp::ge;
        if (comparison) {
          if (!same_type(left,right) && left.tag!=TypeTag::int_literal && right.tag!=TypeTag::int_literal &&
              left.tag!=TypeTag::unknown && right.tag!=TypeTag::unknown) report(SemanticErrorCode::type_mismatch,node.begin);
          return scalar("bool");
        }
        if (!numeric(left) || !numeric(right)) {
          if (left.tag!=TypeTag::unknown && right.tag!=TypeTag::unknown) report(SemanticErrorCode::trait_not_satisfied,node.begin);
          return {TypeTag::unknown,"",{}};
        }
        if (left.tag==TypeTag::int_literal) return right;
        return left;
      }
      case ExprKind::call: {
        const auto& callee=nodes[node.left];
        if (callee.kind!=ExprKind::identifier) { report(SemanticErrorCode::invalid_operand,callee.begin); return {TypeTag::unknown,"",{}}; }
        const auto name=callee.spelling;
        std::vector<Type> args;
        for (const auto arg:node.children) args.push_back(infer(ast,arg));
        const auto fn=functions_.find(name);
        if (fn!=functions_.end()) {
          if (args.size()!=fn->second.parameters.size()) { report(SemanticErrorCode::wrong_arity,callee.begin); return fn->second.result; }
          for (std::size_t i=0;i<args.size();++i) if (!accepts(fn->second.parameters[i],args[i])) report(SemanticErrorCode::type_mismatch,nodes[node.children[i]].begin);
          return fn->second.result;
        }
        if (name=="some" || name=="none") {
          if (name=="none" && !args.empty()) report(SemanticErrorCode::wrong_arity,callee.begin);
          if (name=="some" && args.size()!=1) report(SemanticErrorCode::wrong_arity,callee.begin);
          return {TypeTag::option,"option",args};
        }
        if (name=="ok" || name=="err") {
          if (args.size()!=1) { report(SemanticErrorCode::wrong_arity,callee.begin); return {TypeTag::result,"result",{}}; }
          if (name=="ok") return {TypeTag::result,"result",{args[0],Type{TypeTag::unknown,"",{}}}};
          return {TypeTag::result,"result",{Type{TypeTag::unknown,"",{}},args[0]}};
        }
        const auto type=types_.find(name);
        if (type!=types_.end()) {
          if (args.size()!=type->second.members.size()) { report(SemanticErrorCode::wrong_arity,callee.begin); return {TypeTag::error,name,{}}; }
          for (std::size_t i=0;i<args.size();++i) if (!accepts(type->second.member_types[i],args[i])) report(SemanticErrorCode::type_mismatch,nodes[node.children[i]].begin);
          return {type->second.is_enum ? TypeTag::enumeration : TypeTag::structure,name,{}};
        }
        report(SemanticErrorCode::unknown_function,callee.begin);
        return {TypeTag::unknown,"",{}};
      }
      case ExprKind::index: {
        const auto base=infer(ast,node.left);
        (void)infer(ast,node.right);
        if (base.tag==TypeTag::array || base.tag==TypeTag::option) return base.args.empty() ? Type{TypeTag::unknown,"",{}} : base.args[0];
        if (base.tag==TypeTag::map) return base.args.size()>1 ? base.args[1] : Type{TypeTag::unknown,"",{}};
        if (base.tag!=TypeTag::unknown && base.tag!=TypeTag::error) report(SemanticErrorCode::invalid_operand,node.begin);
        return {TypeTag::unknown,"",{}};
      }
      case ExprKind::member: {
        const auto base=infer(ast,node.left);
        const auto it=types_.find(base.name);
        if (it==types_.end()) {
          if (base.tag!=TypeTag::unknown && base.tag!=TypeTag::error) report(SemanticErrorCode::unknown_field,node.begin);
          return {TypeTag::unknown,"",{}};
        }
        const auto found=std::find(it->second.members.begin(),it->second.members.end(),node.spelling);
        if (found==it->second.members.end()) { report(SemanticErrorCode::unknown_field,node.begin); return {TypeTag::unknown,"",{}}; }
        return it->second.member_types[static_cast<std::size_t>(found-it->second.members.begin())];
      }
    }
    return {TypeTag::unknown,"",{}};
  }
  void check_expression(const Ast& ast,std::size_t index) { (void)infer(ast,index); }
  void check_statements(const StatementAst& body) {
    const auto nodes=body.nodes();
    const auto expressions=body.expressions();
    if (nodes.empty() || body.root()>=nodes.size()) return;
    push_scope();
    walk_statement(body,nodes,expressions,body.root());
    pop_scope();
  }
  void walk_statement(const StatementAst& body,std::span<const StatementNode> nodes,
                      std::span<const Ast> expressions,std::size_t index) {
    if (index>=nodes.size()) return;
    const auto& node=nodes[index];
    switch (node.kind) {
      case StatementKind::block:
        push_scope();
        for (const auto child:node.children) walk_statement(body,nodes,expressions,child);
        pop_scope();
        return;
      case StatementKind::let_stmt: case StatementKind::var_stmt: {
        Type type{TypeTag::unknown,"",{}};
        if (node.expression!=no_statement && node.expression<expressions.size()) type=infer(expressions[node.expression],expressions[node.expression].root());
        bind(node.spelling,type,node.kind==StatementKind::var_stmt,node.begin);
        return;
      }
      case StatementKind::expression: case StatementKind::return_stmt:
        if (node.expression!=no_statement && node.expression<expressions.size()) {
          const auto type=infer(expressions[node.expression],expressions[node.expression].root());
          if (node.kind==StatementKind::return_stmt && !accepts(return_type_,type)) report(SemanticErrorCode::invalid_return,node.begin);
        } else if (node.kind==StatementKind::return_stmt && return_type_.tag!=TypeTag::unit) {
          report(SemanticErrorCode::invalid_return,node.begin);
        }
        return;
      case StatementKind::if_stmt: case StatementKind::guard_stmt: case StatementKind::while_stmt:
        if (node.expression!=no_statement && node.expression<expressions.size()) {
          const auto condition=infer(expressions[node.expression],expressions[node.expression].root());
          if (!same_type(condition,scalar("bool")) && condition.tag!=TypeTag::unknown) report(SemanticErrorCode::type_mismatch,node.begin);
        }
        for (const auto child:node.children) walk_statement(body,nodes,expressions,child);
        return;
      case StatementKind::for_stmt: {
        Type element{TypeTag::unknown,"",{}};
        if (node.expression!=no_statement && node.expression<expressions.size()) {
          const auto iterable=infer(expressions[node.expression],expressions[node.expression].root());
          if (iterable.tag==TypeTag::array || iterable.tag==TypeTag::map) element=iterable.args.empty() ? Type{TypeTag::unknown,"",{}} : iterable.args.back();
        }
        push_scope();
        bind(node.spelling,element,false,node.begin);
        for (const auto child:node.children) walk_statement(body,nodes,expressions,child);
        pop_scope();
        return;
      }
      case StatementKind::loop_stmt:
        for (const auto child:node.children) walk_statement(body,nodes,expressions,child);
        return;
      case StatementKind::match_stmt:
        if (node.expression!=no_statement && node.expression<expressions.size()) (void)infer(expressions[node.expression],expressions[node.expression].root());
        for (const auto child:node.children) {
          push_scope();
          const auto& arm=nodes[child];
          if (!arm.spelling.empty() && arm.spelling!="_") bind(arm.spelling,Type{TypeTag::unknown,"",{}},false,arm.begin);
          for (const auto sub:arm.children) walk_statement(body,nodes,expressions,sub);
          pop_scope();
        }
        return;
      default:
        for (const auto child:node.children) walk_statement(body,nodes,expressions,child);
        return;
    }
  }
  void check_initializers() {
    const auto& nodes=ast_.nodes();
    const auto& values=ast_.values();
    for (const auto& node:nodes) if (node.kind==DeclarationKind::state_decl && node.value<values.size()) {
      const auto& ast=values[node.value];
      const auto value=infer(ast,ast.root());
      const auto target=node.type==no_declaration ? Type{TypeTag::unknown,"",{}} : convert_type(node.type);
      if (!accepts(target,value)) report(SemanticErrorCode::invalid_assignment,node.begin);
    }
  }
  void check_functions() {
    const auto& nodes=ast_.nodes();
    const auto& bodies=ast_.bodies();
    for (const auto& node:nodes) if (node.kind==DeclarationKind::fn_decl && node.body<bodies.size()) {
      const auto sig=functions_.find(node.spelling);
      return_type_=sig==functions_.end() ? Type{TypeTag::unknown,"",{}} : sig->second.result;
      push_scope();
      for (auto param:node.children) {
        if (param>=nodes.size()) continue;
        const auto& p=nodes[param];
        if (p.kind==DeclarationKind::param) bind(p.spelling,p.type==no_declaration ? Type{TypeTag::unknown,"",{}} : convert_type(p.type),false,p.begin);
      }
      walk_statement(bodies[node.body],bodies[node.body].nodes(),bodies[node.body].expressions(),bodies[node.body].root());
      pop_scope();
    }
  }
 public:
  explicit Analyzer(const DeclarationAst& ast):ast_(ast) {}
  SemanticResult run() {
    collect_types();
    check_initializers();
    check_functions();
    return {std::move(diagnostics_)};
  }
};
} // namespace

SemanticResult analyze(const DeclarationAst& ast) { return Analyzer(ast).run(); }
std::string_view name(SemanticErrorCode code) {
  constexpr auto names=std::to_array<std::string_view>({
    "duplicate_declaration","duplicate_binding","unknown_name","unknown_type",
    "unknown_function","unknown_field","wrong_arity","type_mismatch",
    "invalid_operand","invalid_assignment","invalid_return","trait_not_satisfied",
    "invalid_generic_arity","immutable_assignment"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_semantic(const SemanticResult& result) {
  if (result.ok()) return "ok\n";
  const auto& first=result.diagnostics.front();
  return "semantic "+std::string(name(first.code))+" "+std::to_string(first.position.line)+":"+std::to_string(first.position.column)+"\n";
}
} // namespace poko::mute
