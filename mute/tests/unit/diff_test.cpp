#include "poko/mute/emit.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/declaration.hpp"
#include "poko/mute/lower.hpp"
#include "poko/mute/fold.hpp"
#include "poko/mute/optimize.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }

// Parse + lower the whole module + verify + emit. When optimize, runs the
// MUT-28/29/30 pipeline (fold -> simplify -> dce) over every function before
// emit. Entry "f" is located by name so helper/callee functions may come
// first.
bool compile(std::string_view src,bool optimize,EmitResult& em,std::size_t& entry) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) { std::cerr << "parse failed: " << src << '\n'; return false; }
  auto lm=lower_module(*d);
  if (!lm.ok()) {
    std::cerr << "lower failed: " << src << '\n';
    for (auto& x:lm.diagnostics) std::cerr<<"  code="<<(int)x.code<<" fn="<<x.function<<" blk="<<x.block<<" "<<x.detail<<"\n";
    return false;
  }
  IrModule mod=std::move(lm.module);
  if (optimize) {
    mod=fold_constants(mod);
    mod=simplify_control_flow(mod);
    mod=eliminate_dead_code(mod);
  }
  entry=0;
  for (std::size_t i=0;i<mod.functions.size();++i)
    if (mod.functions[i].name=="f") entry=i;
  auto ver=verify(mod);
  if (!ver.ok()) { std::cerr << "verify failed: " << src << "\n"; for (auto& x:ver.diagnostics) std::cerr<<"  code="<<(int)x.code<<" fn="<<x.function<<" blk="<<x.block<<" "<<x.detail<<"\n"; std::cerr<<dump_ir(mod); return false; }
  em=emit_bytecode(mod);
  return em.ok();
}

std::size_t total_words(const EmitResult& em) {
  std::size_t total=0;
  for (const auto& fn:em.functions) total+=fn.size();
  return total;
}

VmResult run(const EmitResult& em,std::size_t entry,std::size_t budget=100'000) {
  VmModule module{em.functions,em.capabilities};
  return run_register_module(module,entry,{},budget);
}

bool same_result(const VmResult& a,const VmResult& b) {
  const auto* av=std::get_if<std::int32_t>(&a); const auto* bv=std::get_if<std::int32_t>(&b);
  if (av||bv) return av&&bv&&*av==*bv;
  const auto* ae=std::get_if<VmError>(&a); const auto* be=std::get_if<VmError>(&b);
  // pc may legitimately differ between baseline and optimized layouts; the
  // error code is the observable contract.
  return ae&&be&&ae->code==be->code;
}

// One corpus entry: baseline vs optimized must agree on value or trap code,
// and a trap in both must map to the same source position (MUT-33 map).
void diff_case(std::string_view src,std::string_view name,std::size_t budget=100'000) {
  EmitResult base,opt; std::size_t be=0,oe=0;
  if (!compile(src,false,base,be)) { check(false,name); return; }
  if (!compile(src,true,opt,oe)) { check(false,name); return; }
  check(be==oe,std::string(name)+" entry index stable");
  auto ra=run(base,be,budget), rb=run(opt,oe,budget);
  check(same_result(ra,rb),name);
  const auto* ea=std::get_if<VmError>(&ra); const auto* eb=std::get_if<VmError>(&rb);
  // Position equality is asserted for real traps (div/mod/overflow). Budget
  // exhaustion legitimately stops at different pcs after optimization
  // removes instructions, so its position is not comparable.
  const bool real_trap=ea&&(ea->code==VmErrorCode::divide_by_zero||ea->code==VmErrorCode::overflow);
  if (real_trap&&eb) {
    const auto pa=source_position(base,be,ea->pc), pb=source_position(opt,oe,eb->pc);
    check(pa.byte==pb.byte && pa.line==pb.line && pa.column==pb.column,
          std::string(name)+" trap source position");
  }
}

void cases() {
  const std::vector<std::pair<std::string,std::string>> corpus={
    {"package \"a\" version \"A\" fn f() -> i32 { return 20 + 22; }","const-arith"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 6 * 7; return x - 2; }","let-arith"},
    {"package \"a\" version \"A\" fn f() -> i32 { return 100 / 4 + 100 % 7; }","divmod-ok"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 1; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-true"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 3; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-false"},
    {"package \"a\" version \"A\" fn f() -> i32 { if 1 < 2 { return 11; } return 22; }","const-branch-fold"},
    {"package \"a\" version \"A\" fn f() -> i32 { if 1 > 2 { return 11; } return 22; }","const-branch-dead"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 5 { x = x + 1; } return x; }","while"},
    {"package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..4 { s = s + i; } return s; }","for-range"},
    {"package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..=3 { s = s + i; } return s; }","for-inclusive"},
    {"package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..6 { if i == 3 { break; } s = s + i; } return s; }","for-break"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 10 { x = x + 1; if x == 4 { continue; } } return x; }","while-continue"},
    {"package \"a\" version \"A\" fn f() -> i32 { return 1 < 2 && 3 < 4; }","land"},
    {"package \"a\" version \"A\" fn f() -> i32 { return 1 > 2 || 3 < 4; }","lor"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 3 { x = x + 1; let y = 9; } return x; }","dead-let"},
    {"package \"a\" version \"A\" fn f() -> i32 { return -(5 - 9); }","unary"},
    {"package \"a\" version \"A\" fn f() -> i32 { let d = 4 - 4; return 100 / d; }","trap-div0"},
    {"package \"a\" version \"A\" fn f() -> i32 { return 2147483647 + 1; }","trap-overflow"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = -2147483647 - 1; return -x; }","trap-neg-min"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 3 { x = x + 1; } return 100 / (x - x); }","trap-after-loop"},
    {"package \"a\" version \"A\" fn f() -> i32 { if 1 > 2 { return 100 / 0; } return 8; }","dead-trap-arm"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 2; let y = x * x + x * x; return y; }","shared-subexpr"},
    {"package \"a\" version \"A\" fn f() -> i32 { let a = 1; let b = 2; if a < b { let c = a + b; return c * 2; } return 0; }","if-let-phi"},
    {"package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..3 { for j in 0..3 { s = s + j; } } return s; }","for-nested"},
    {"package \"a\" version \"A\" fn f() -> i32 { let x = 2; if x > 0 { if x < 3 { let y = 4; } else { let y = 8; } } else { let y = 0; } return y + x; }","if-nested-arith"},
  };
  for (const auto& [src,name]:corpus) diff_case(src,name);
  // Call corpus: functions that call helpers must agree on value and total
  // emitted size (helpers included). No trap-position assertions here because
  // a trap can surface inside a callee's own position map.
  const std::vector<std::pair<std::string,std::string>> call_corpus={
    {"package \"a\" version \"A\" fn add(a: i32, b: i32) -> i32 { return a + b; } fn f() -> i32 { return add(20, 22); }","call-add"},
    {"package \"a\" version \"A\" fn tw(x: i32) -> i32 { return x * 2; } fn inc(x: i32) -> i32 { return x + 1; } fn f() -> i32 { return tw(inc(20)); }","call-nested"},
    {"package \"a\" version \"A\" fn fib(n: i32) -> i32 { if n < 2 { return n; } return fib(n - 1) + fib(n - 2); } fn f() -> i32 { return fib(10); }","call-recursive"},
    {"package \"a\" version \"A\" fn even(n: i32) -> i32 { if n == 0 { return 1; } return odd(n - 1); } fn odd(n: i32) -> i32 { if n == 0 { return 0; } return even(n - 1); } fn f() -> i32 { return even(9); }","call-mutual"},
  };
  for (const auto& [src,name]:call_corpus) diff_case(src,name);
  // Documented budget semantics: instruction budget counts executed words;
  // optimization may legitimately reduce the count, so the corpus uses a
  // budget both sides exceed (tiny loop) rather than asserting identical pcs.
  diff_case("package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 100 { x = x + 1; } return x; }","budget-exceeded",8);
  // Sizes: optimized emission must never be larger than baseline for this
  // corpus (dead arms/phis removed, nothing added). Totals include helpers.
  for (const auto& [src,name]:corpus) {
    EmitResult base,opt; std::size_t be=0,oe=0;
    if (!compile(src,false,base,be) || !compile(src,true,opt,oe)) continue;
    check(total_words(opt)<=total_words(base),std::string(name)+" size");
  }
  for (const auto& [src,name]:call_corpus) {
    EmitResult base,opt; std::size_t be=0,oe=0;
    if (!compile(src,false,base,be) || !compile(src,true,opt,oe)) continue;
    check(total_words(opt)<=total_words(base),std::string(name)+" size");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " differential test(s) failed\n"; return 1; }
  std::cout << "differential tests passed\n";
  return 0;
}
