#include "poko/mute/emit.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/declaration.hpp"
#include "poko/mute/lower.hpp"
#include "poko/mute/fold.hpp"
#include "poko/mute/optimize.hpp"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
Type i32() { return {TypeTag::scalar,"i32",{}}; }

bool compile(std::string_view src,bool optimize,EmitResult& em) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) { std::cerr << "parse failed: " << src << "\n"; return false; }
  std::size_t body=no_declaration;
  for (const auto& n:d->nodes()) if (n.kind==DeclarationKind::fn_decl && n.body<d->bodies().size()) { body=n.body; break; }
  if (body==no_declaration) return false;
  LowerResult lr=lower_function(d->bodies()[body],"f",i32(),{});
  if (!lr.ok()) { std::cerr << "lower failed: " << src << "\n"; for (auto& x:lr.diagnostics) std::cerr<<"  code="<<(int)x.code<<" blk="<<x.block<<"\n"; return false; }
  IrModule mod; mod.functions.push_back(lr.fn);
  if (optimize) {
    mod=fold_constants(mod);
    mod=simplify_control_flow(mod);
    mod=eliminate_dead_code(mod);
  }
  em=emit_bytecode(mod);
  if (!em.ok()) { std::cerr << "emit failed: " << src << " errors=" << em.errors.size(); for (auto& x:em.diagnostics) std::cerr<<" ["<<(int)x.code<<" fn="<<x.function<<" blk="<<x.block<<" "<<x.detail<<"]"; std::cerr << "\n"; return false; }
  return true;
}

VmResult run(const EmitResult& em) {
  std::array<std::int32_t,256> r{};
  return run_register_vm(em.functions[0],r,1'000'000);
}

std::int64_t best_ns(const EmitResult& em,int reps) {
  std::int64_t best=INT64_MAX;
  for (int i=0;i<reps;++i) {
    const auto t0=std::chrono::steady_clock::now();
    auto res=run(em);
    const auto t1=std::chrono::steady_clock::now();
    if (std::holds_alternative<VmError>(res)) { std::cerr << "bench run trapped\n"; return -1; }
    best=std::min(best,std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count());
  }
  return best;
}

// Pinned workloads: fixed sources, fixed iteration counts, fixed budget.
// Times are reported, never claimed as speedups; the only hard regressions
// asserted are code-size growth and a >2x best-time slowdown (debug-build
// noise floor is wide, so the bound is deliberately loose).
void bench(std::string_view name,std::string_view src) {
  EmitResult base,opt;
  check(compile(src,false,base),"bench baseline compiles");
  check(compile(src,true,opt),"bench optimized compiles");
  if (!base.ok()||!opt.ok()) return;
  const auto ra=run(base), rb=run(opt);
  check(std::holds_alternative<std::int32_t>(ra)&&std::holds_alternative<std::int32_t>(rb)&&
        std::get<std::int32_t>(ra)==std::get<std::int32_t>(rb),"bench results equal");
  const auto tb=best_ns(base,5), to=best_ns(opt,5);
  const auto sb=base.functions[0].size(), so=opt.functions[0].size();
  std::cout << name << ": instrs " << sb << "->" << so
            << "  best_ns " << tb << "->" << to << "\n";
  check(so<=sb,"optimized size regression");
  if (tb>0&&to>0) check(to<=tb*2,"optimized >2x slower (reported, not claimed)");
}

void cases() {
  bench("loop-sum",
    "package \"a\" version \"A\" fn f() -> i32 { let s = 0; let x = 0; while x < 20000 { s = s + x; x = x + 1; } return s % 1000003; }");
  bench("nested-loop",
    "package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..60 { for j in 0..60 { s = s + (i % 7) * (j % 5); } } return s % 1000003; }");
  bench("branchy",
    "package \"a\" version \"A\" fn f() -> i32 { let s = 0; let x = 0; while x < 5000 { if x % 3 == 0 { s = s + 1; } else { if x % 4 == 1 { s = s + 2; } else { s = s + 3; } } x = x + 1; } return s % 1000003; }");
  bench("dead-heavy",
    "package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 5000 { let a = 1 + 2; let b = a * 3; let c = b - a; if 2 < 3 { let d = c + 1; } x = x + 1; } return x; }");
  bench("phi-merge",
    "package \"a\" version \"A\" fn f() -> i32 { let s = 0; let x = 0; while x < 8000 { if x % 2 == 0 { s = s + x; } else { s = s - x / 2; } x = x + 1; } return s % 1000003; }");
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " bench regression(s)\n"; return 1; }
  std::cout << "optimizer bench report complete\n";
  return 0;
}
