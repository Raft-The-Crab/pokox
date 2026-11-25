#include "poko/mute/determinism.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
using namespace poko::mute;
namespace {
int failures=0;
void ok(std::string_view source) {
  auto parsed=parse_declarations(source);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  if (!ast) { std::cerr << "parse failed: " << source << '\n'; ++failures; return; }
  const auto r=analyze_determinism(*ast);
  if (!r.ok()) { std::cerr << "unexpected: " << dump_determinism(r) << " in: " << source << '\n'; ++failures; }
}
void error(std::string_view source,DeterminismErrorCode code) {
  auto parsed=parse_declarations(source);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  if (!ast) { std::cerr << "parse failed: " << source << '\n'; ++failures; return; }
  const auto r=analyze_determinism(*ast);
  if (std::none_of(r.diagnostics.begin(),r.diagnostics.end(),[&](const auto& d){return d.code==code;})) {
    std::cerr << "missing " << name(code) << " in: " << source << '\n' << dump_determinism(r); ++failures;
  }
}
void cases() {
  ok("package \"a\" version \"A\" allow: Time, Crypto");
  ok("package \"a\" version \"A\" allow: Net fn f() -> i32 { return 1; }");
  ok("package \"a\" version \"A\" @state var x: i32 = 1 + 2");
  // Unknown and duplicate capabilities.
  error("package \"a\" version \"A\" allow: Teleport",DeterminismErrorCode::unknown_capability);
  error("package \"a\" version \"A\" allow: Time, Time",DeterminismErrorCode::duplicate_capability);
  // Capability tokens banned in @state types.
  error("package \"a\" version \"A\" @state var s: Storage = ()",DeterminismErrorCode::capability_in_state);
  // Capability token inside @state initializer.
  error("package \"a\" version \"A\" @state var x: i32 = Net",DeterminismErrorCode::capability_in_state);
  // Nondeterministic builtins: banned without the capability, banned in @state always.
  error("package \"a\" version \"A\" @state var t: i32 = now()",DeterminismErrorCode::nondeterministic_operation);
  error("package \"a\" version \"A\" @state var t: i32 = env(\"X\")",DeterminismErrorCode::nondeterministic_operation);
  error("package \"a\" version \"A\" @state var r: i32 = random()",DeterminismErrorCode::nondeterministic_operation);
  // Wall-clock builtins are rejected even with Time; tick-based APIs are valid.
  error("package \"a\" version \"A\" allow: Time fn f() -> i32 { return now(); }",DeterminismErrorCode::nondeterministic_operation);
  error("package \"a\" version \"A\" allow: Time, Crypto fn f() -> i32 { return timestamp(); }",DeterminismErrorCode::nondeterministic_operation);
  ok("package \"a\" version \"A\" allow: Time fn f() -> i32 { return tick(); }");
  ok("package \"a\" version \"A\" allow: Time fn f() -> i32 { return simNow(); }");
  // Declared capability permits the approved nondeterministic source outside @state.
  ok("package \"a\" version \"A\" allow: Crypto fn f() -> i32 { return random(); }");
  // Missing capability still fails outside @state.
  error("package \"a\" version \"A\" fn f() -> i32 { return now(); }",DeterminismErrorCode::nondeterministic_operation);
  error("package \"a\" version \"A\" fn f() -> i32 { return random(); }",DeterminismErrorCode::nondeterministic_operation);
  // Unconditionally banned builtins fail even with broad allows.
  error("package \"a\" version \"A\" allow: Net, Time, Crypto, Storage, Ui, Asset, Log, Replicate, Spawn, Physics fn f() -> i32 { return env(\"HOME\"); }",DeterminismErrorCode::nondeterministic_operation);
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " determinism test(s) failed\n"; return 1; }
  std::cout << "determinism tests passed\n";
  return 0;
}
