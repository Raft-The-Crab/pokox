#include "poko/mute/values.hpp"
#include <iostream>
#include <string>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
template<class T> T unwrap(std::variant<T,ValueError> v,std::string_view what) {
  if (const auto* e=std::get_if<ValueError>(&v)) { std::cerr << "FAIL: " << what << " code=" << static_cast<int>(e->code) << '\n'; ++failures; }
  return std::get<T>(v);
}
void cases() {
  AggregateStore s;
  // String creation, length, access.
  auto str=unwrap(s.make_string("hello"),"make_string");
  check(unwrap(s.length(str),"strlen")==5,"string length");
  check(unwrap(s.as_string(str),"as_string")=="hello","string bytes");
  check(std::holds_alternative<ValueError>(s.get_index(str,0)),"string index wrong kind");
  // Array creation, fill, bounds.
  auto arr=unwrap(s.make_array(4,make_int(7)),"make_array");
  check(unwrap(s.length(arr),"arrlen")==4,"array length");
  check(unwrap(s.get_index(arr,2),"get_index").scalar==7,"array fill");
  check(std::holds_alternative<ValueError>(s.get_index(arr,-1)) && std::holds_alternative<ValueError>(s.get_index(arr,4)),"bounds");
  check(std::holds_alternative<Value>(s.set_index(arr,1,make_int(9))),"set_index");
  check(unwrap(s.get_index(arr,1),"get after set").scalar==9,"set value");
  // Copies are independent for arrays.
  auto c=unwrap(s.copy(arr),"copy");
  s.set_index(c,0,make_int(1));
  check(unwrap(s.get_index(arr,0),"orig after copy write").scalar==7,"copy isolation");
  // Nested arrays and strings.
  auto inner=unwrap(s.make_array(2,str),"inner array");
  auto outer=unwrap(s.make_array(1,inner),"outer array");
  auto got=unwrap(s.get_index(outer,0),"outer get");
  auto str2=unwrap(s.get_index(got,1),"inner get");
  check(unwrap(s.as_string(str2),"nested string")=="hello","nested string bytes");
  // Refcounted release: shared child survives one release.
  s.release(inner); // outer still holds a ref via its items
  check(s.live_objects()>0,"objects alive");
  // Promotion survives reset_tick.
  auto p=unwrap(s.promote(outer),"promote");
  s.reset_tick();
  auto still=unwrap(s.get_index(p,0),"promoted access");
  check(std::holds_alternative<Value>(s.get_index(still,0)),"promoted child alive");
  // Arena objects die on reset_tick.
  auto tmp=unwrap(s.make_string("tmp"),"tmp");
  s.reset_tick();
  check(std::holds_alternative<ValueError>(s.as_string(tmp)),"arena freed");
  // Bounds on oversized inputs.
  AggregateStore tight{AggregateStore::Limits{.max_string_bytes=4,.max_array_length=2,.max_depth=4,.heap_objects=8,.heap_bytes=1<<20}};
  check(std::holds_alternative<ValueError>(tight.make_string("12345")),"string cap");
  check(std::holds_alternative<ValueError>(tight.make_array(3)),"array cap");
  // Scalars pass through copy/promote untouched.
  check(unwrap(s.copy(make_int(42)),"copy int").scalar==42,"copy scalar");
  check(unwrap(s.promote(make_bool(true)),"promote bool").scalar==1,"promote scalar");
  // Heap parent must promote arena children on insert, or reset_tick dangles.
  {
    auto hp=unwrap(s.promote(unwrap(s.make_array(1),"heap parent")),"promote parent");
    auto arena_str=unwrap(s.make_string("tick"),"arena child");
    check(std::holds_alternative<Value>(s.set_index(hp,0,arena_str)),"set into heap");
    s.reset_tick();
    auto back=unwrap(s.get_index(hp,0),"heap child after reset");
    check(unwrap(s.as_string(back),"promoted child")=="tick","arena child promoted into heap parent");
  }
  // Deep nesting is bounded: copy must trap, not overflow the stack.
  {
    AggregateStore deep{AggregateStore::Limits{.max_string_bytes=1024,.max_array_length=4,.max_depth=8,.heap_objects=4096,.heap_bytes=1<<22}};
    Value v=make_int(0);
    for (int i=0;i<12;++i) { auto n=unwrap(deep.make_array(1,v),"nest"); v=n; }
    check(std::holds_alternative<ValueError>(deep.copy(v)),"deep copy traps");
    check(std::holds_alternative<ValueError>(deep.promote(v)),"deep promote traps");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " values test(s) failed\n"; return 1; }
  std::cout << "values tests passed\n";
  return 0;
}
