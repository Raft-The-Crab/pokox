#include "poko/mute/console.hpp"
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <type_traits>
using namespace poko::mute;
static_assert(!std::is_copy_constructible_v<ConsoleLog>);
static_assert(!std::is_copy_assignable_v<ConsoleLog>);
static_assert(!std::is_move_constructible_v<ConsoleLog>);
static_assert(!std::is_move_assignable_v<ConsoleLog>);
namespace {
struct Sink { std::string text; int calls=0; bool accept=true; };
bool write(std::string_view text,void* user) {
  auto& sink=*static_cast<Sink*>(user); ++sink.calls; sink.text.assign(text); return sink.accept;
}
}
int main() {
  int failures=0;
  const auto test=[&](std::string_view actual,std::string_view expected) {
    if (actual!=expected) { std::cerr << "expected " << expected << ", got " << actual << '\n'; ++failures; }
  };
  test(evaluate_console("1+2*3"),"i32: 7");
  test(evaluate_console("-7 % 3"),"i32: -1");
  test(evaluate_console("1.5f32 + 2.25f32"),"f32: 3.75");
  test(evaluate_console("-0.0"),"f64: -0");
  test(evaluate_console("1/0"),"eval error divide_by_zero at 1:2");
  test(evaluate_console("x+1"),"eval error unknown_identifier at 1:1");
  test(evaluate_console("1+"),"parse error expected_expression at 1:3");
  test(evaluate_console("0b2"),"lex error invalid_number at 1:1");
  test(evaluate_console(std::string(4096,' ')),"lex error source_too_large at 1:1");
  test(execute_console("@state var count:i32=1; fn f()->i32 {count=count+1; return count;} f()"),"i32: 2");
  ProgramState state;
  constexpr auto state_source="@state var count:i32=1; fn f()->i32 {count=count+1; return count;} f()";
  test(execute_console_stateful(state_source,state),"i32: 2");
  test(execute_console_stateful(state_source,state),"i32: 3");
  test(execute_console_stateful("1+2",state),"i32: 3");
  test(execute_console_stateful("fn f()->i32 {return 7;} f()",state),"i32: 7");
  test(execute_console_stateful(state_source,state),"i32: 4");
  state={};test(execute_console_stateful(state_source,state),"i32: 2");
  test(execute_console("fn f(n:i32)->i32 { if n==0 {return 1;} return n*f(n-1); } f(5)"),"i32: 120");
  test(execute_console("fn f()->i32 {return 1/0;} f()"),"eval error divide_by_zero at 1:22");
  test(execute_console("fn f()->i32{var i=0;while i<3{i=i+1;}return i;}f()"),"i32: 3");
  if (!execute_console("fn f()->i32{while true {} return 0;}f()").starts_with("runtime error budget_exceeded at ")) { std::cerr<<"console loop did not trap\n"; ++failures; }
  Sink sink; const PrintHost host{write,&sink};
  test(execute_console("print(1 + 2*3)",host),"unit");
  test(sink.text,"7");
  test(execute_console("print(\"Hello, Mute!\")",host),"unit"); test(sink.text,"Hello, Mute!");
  test(execute_console("print(\"a\\n\\t\\0\\{x\\}\\\\\\\"\")",host),"unit");
  test(sink.text,std::string_view("a\n\t\0{x}\\\"",9));
  test(execute_console("print(\"\")",host),"unit"); test(sink.text,"");
  test(execute_console("print(\"caf\xc3\xa9 %s\")",host),"unit"); test(sink.text,"caf\xc3\xa9 %s");
  test(execute_console("print(1.5f32 + 2.25f32)",host),"unit"); test(sink.text,"3.75");
  test(execute_console(" print /* comment */ ( (1 + 2) * 3 ) ",host),"unit"); test(sink.text,"9");
  const int prior=sink.calls;
  test(execute_console("print(1/0)",host),"eval error divide_by_zero at 1:8");
  test(execute_console("print(\n  1/0)",host),"eval error divide_by_zero at 2:4");
  test(execute_console("print(\r\n  1/0)",host),"eval error divide_by_zero at 2:4");
  test(execute_console("print(\"hi {name}\")",host),"host error unsupported_interpolation at 1:7");
  test(execute_console("print(\"a\", \"b\")",host),"parse error unexpected_token at 1:10");
  test(execute_console("print()",host),"parse error expected_expression at 1:7");
  test(execute_console("print(1) + 2",host),"host error invalid_print_call at 1:1");
  test(execute_console("print(1",host),"host error invalid_print_call at 1:1");
  test(execute_console("print(print(1))",host),"eval error unknown_identifier at 1:7");
  test(execute_console("print(0b2)",host),"lex error invalid_number at 1:7");
  test(execute_console("print(1)",{}),"host error print_unavailable at 1:1");
  test(execute_console("print",host),"eval error unknown_identifier at 1:1");
  test(execute_console("2+3",host),"i32: 5");
  if (sink.calls!=prior) { std::cerr << "unexpected print side effect\n"; ++failures; }
  sink.accept=false; test(execute_console("print(1)",host),"host error print_failed at 1:1");
  if (sink.calls!=prior+1) { std::cerr << "failure sink call count\n"; ++failures; }
  // A previously full buffer may retain bytes beyond its new NUL terminator.
  const std::array<char,5> shortened{{'a','\0','x','x','x'}};
  const std::array<char,5> full{{'a','b','c','d','\0'}};
  const std::array<char,5> no_terminator{{'a','b','c','d','e'}};
  const std::array<char,0> empty{};
  if (console_input_full(shortened) || !console_input_full(full) ||
      !console_input_full(no_terminator) || !console_input_full(empty)) {
    std::cerr << "input capacity guard\n"; ++failures;
  }
  ConsoleLog log;
  if (!log.append(std::string_view("a\0\n\t\r\x1b",6)) || log.entries().back()!="a\\0\\n\\t\\r\\x1b") { std::cerr << "log escaping\n"; ++failures; }
  if (!log.append("a\n") || !log.append("a\\n") || log.entries()[1]==log.entries()[2] || log.entries()[2]!="a\\\\n") { std::cerr << "ambiguous log escape\n"; ++failures; }
  if (log.append(std::string(ConsoleLog::max_input_bytes+1,'x'))) { std::cerr << "oversized log accepted\n"; ++failures; }
  log.clear();
  // Unicode format controls (bidi overrides, zero-width, tag characters) must
  // be escaped; ordinary non-ASCII text and invalid bytes stay unambiguous.
  if (!log.append("a\xe2\x80\xae" "b\xe2\x80\x8b" "c\xef\xbb\xbf" "d\xf0\x9d\x90\x80" "e\xff\xfe")) { std::cerr << "unicode log append\n"; ++failures; }
  if (log.entries().back()!="a\\u202eb\\u200bc\\ufeffd" "\xf0\x9d\x90\x80" "e\\xff\\xfe") {
    std::cerr << "unicode format control not escaped: " << log.entries().back() << '\n'; ++failures;
  }
  for (int i=0;i<105;++i) if (!log.append(std::to_string(i))) ++failures;
  if (log.entries().size()!=100 || log.entries().front()!="5" || log.entries().back()!="104") { std::cerr << "FIFO entry eviction\n"; ++failures; }
  log.clear();
  for (int i=0;i<20;++i) if (!log.append(std::string(4095,'\x01'))) ++failures;
  if (log.bytes()>ConsoleLog::max_bytes || log.entries().size()!=4 || log.bytes()!=4*4095*4) { std::cerr << "FIFO byte eviction\n"; ++failures; }
  log.clear(); if (!log.entries().empty() || log.bytes()!=0) { std::cerr << "clear\n"; ++failures; }
  // Random malformed UTF-8 and syntax must never cause an unexpected hostcall.
  std::mt19937 rng(0x4d555435);
  sink.accept=true;
  for (int i=0;i<10000;++i) {
    std::string text; const auto length=rng()%100;
    for (unsigned j=0;j<length;++j) text.push_back(static_cast<char>(rng()%(i%2 ? 128 : 256)));
    const int before=sink.calls;
    const auto output=execute_console(text,host);
    if (sink.calls!=before+(output=="unit" ? 1 : 0)) { std::cerr << "random side effect mismatch\n"; ++failures; break; }
  }
  for (int i=0;i<1000;++i) {
    const auto x=rng()%1000, y=rng()%1000;
    const std::string expression=std::to_string(x)+" + "+std::to_string(y);
    const auto expected=std::to_string(x+y);
    const auto output=execute_console("print("+expression+")",host);
    if (output!="unit" || sink.text!=expected || evaluate_console(expression)!="i32: "+expected) {
      std::cerr << "random arithmetic print mismatch\n"; ++failures; break;
    }
  }
  return failures ? 1 : 0;
}
