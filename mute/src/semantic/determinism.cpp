#include "poko/mute/determinism.hpp"
#include "poko/mute/hostcall.hpp"
#include "poko/mute/statement.hpp"
#include <array>
#include <set>
#include <string>
namespace poko::mute {
namespace {
bool is_capability(std::string_view s) { return capability_from_name(s) != 0; }
// Nondeterministic builtins -> required capability; empty = always banned.
struct Builtin { std::string_view name; std::string_view capability; };
constexpr auto builtins=std::to_array<Builtin>({
  // Wall-clock reads are never valid in simulation code, even with Time.
  // Tick-based tick()/dt()/simNow() are the approved Time surface.
  {"now",""},{"time",""},{"clock",""},{"timestamp",""},
  {"random","Crypto"},{"rand","Crypto"},{"uuid","Crypto"},{"guid","Crypto"},
  {"env",""},{"getenv",""},{"hostname",""},{"username",""},{"pid",""},{"addr",""}});
const Builtin* builtin(std::string_view name) {
  for (const auto& b:builtins) if (b.name==name) return &b;
  return nullptr;
}
std::string last_segment(std::string_view path) {
  const auto pos=path.rfind('.');
  return std::string(pos==std::string_view::npos ? path : path.substr(pos+1));
}

class Analyzer {
 public:
  explicit Analyzer(const DeclarationAst& ast):ast_(ast) {}
  DeterminismResult run() {
    collect_allows();
    scan_module();
    return {std::move(diagnostics_)};
  }
 private:
  void report(DeterminismErrorCode code,Position pos,std::string detail) {
    diagnostics_.push_back({code,pos,std::move(detail)});
  }
  void collect_allows() {
    const auto nodes=ast_.nodes();
    if (ast_.root()>=nodes.size()) return;
    for (const auto child:nodes[ast_.root()].children) {
      if (child>=nodes.size() || nodes[child].kind!=DeclarationKind::allow) continue;
      for (const auto cap:nodes[child].children) {
        if (cap>=nodes.size()) continue;
        const auto name=nodes[cap].spelling;
        if (!is_capability(name)) {
          report(DeterminismErrorCode::unknown_capability,nodes[cap].begin,name);
          continue;
        }
        if (!declared_.insert(name).second)
          report(DeterminismErrorCode::duplicate_capability,nodes[cap].begin,name);
      }
    }
  }
  void scan_module() {
    const auto nodes=ast_.nodes();
    const auto types=ast_.types();
    const auto values=ast_.values();
    const auto bodies=ast_.bodies();
    if (ast_.root()>=nodes.size()) return;
    for (const auto child:nodes[ast_.root()].children) {
      if (child>=nodes.size()) continue;
      const auto& node=nodes[child];
      if (node.kind==DeclarationKind::state_decl) {
        // Capability tokens may never appear in @state types.
        if (node.type!=no_declaration && node.type<types.size()) {
          const auto& t=types[node.type];
          if (is_capability(t.spelling))
            report(DeterminismErrorCode::capability_in_state,node.begin,t.spelling);
        }
        if (node.value!=no_declaration && node.value<values.size())
          scan_expr(values[node.value],values[node.value].root(),true);
      } else if (node.kind==DeclarationKind::fn_decl && node.body!=no_declaration && node.body<bodies.size()) {
        scan_body(bodies[node.body]);
      }
    }
  }
  void scan_body(const StatementAst& body) {
    const auto nodes=body.nodes();
    const auto exprs=body.expressions();
    if (body.root()>=nodes.size()) return;
    std::vector<std::size_t> stack{body.root()};
    while (!stack.empty()) {
      const auto i=stack.back(); stack.pop_back();
      if (i>=nodes.size()) continue;
      const auto& node=nodes[i];
      if (node.expression!=no_statement && node.expression<exprs.size())
        scan_expr(exprs[node.expression],exprs[node.expression].root(),false);
      for (auto it=node.children.rbegin();it!=node.children.rend();++it) stack.push_back(*it);
    }
  }
  void scan_expr(const Ast& ast,std::size_t index,bool in_state) {
    if (index>=ast.nodes().size()) return;
    const auto& node=ast.nodes()[index];
    const auto leaf=last_segment(node.spelling);
    if (node.kind==ExprKind::identifier || node.kind==ExprKind::call) {
      if (in_state && is_capability(node.spelling))
        report(DeterminismErrorCode::capability_in_state,node.begin,node.spelling);
      if (const auto* b=builtin(leaf)) {
        const bool declared=!b->capability.empty() && declared_.count(std::string(b->capability));
        if (in_state || !declared)
          report(DeterminismErrorCode::nondeterministic_operation,node.begin,node.spelling);
      }
    }
    if (node.left!=no_node) scan_expr(ast,node.left,in_state);
    if (node.right!=no_node) scan_expr(ast,node.right,in_state);
    for (const auto c:node.children) scan_expr(ast,c,in_state);
  }
  const DeclarationAst& ast_;
  std::set<std::string> declared_;
  std::vector<DeterminismDiagnostic> diagnostics_;
};
} // namespace

DeterminismResult analyze_determinism(const DeclarationAst& ast) { return Analyzer(ast).run(); }

std::uint32_t program_capability_mask(const DeclarationAst& ast) {
  std::uint32_t mask = 0;
  const auto nodes = ast.nodes();
  if (ast.root() >= nodes.size()) return mask;
  for (const auto child : nodes[ast.root()].children) {
    if (child >= nodes.size() || nodes[child].kind != DeclarationKind::allow) continue;
    for (const auto cap : nodes[child].children) {
      if (cap >= nodes.size()) continue;
      mask |= capability_from_name(nodes[cap].spelling);
    }
  }
  return mask;
}
std::string_view name(DeterminismErrorCode code) {
  constexpr auto names=std::to_array<std::string_view>({
    "unknown_capability","duplicate_capability","capability_in_state","nondeterministic_operation"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_determinism(const DeterminismResult& result) {
  std::string out;
  for (const auto& d:result.diagnostics) {
    out+=std::string(name(d.code))+" @"+std::to_string(d.position.byte)+":"+
         std::to_string(d.position.line)+":"+std::to_string(d.position.column)+" "+d.detail+"\n";
  }
  return out;
}
} // namespace poko::mute
