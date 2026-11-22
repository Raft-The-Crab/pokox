#include "poko/mute/program.hpp"
#include <cstdint>
#include <iostream>
#include <random>
#include <span>
#include <string>
#include <string_view>
#include <variant>
using namespace poko::mute;
namespace poko::mute::testing { ProgramResult run_program_reference(std::string_view,ProgramOptions={}); }

int main() {
  int failures=0;
  auto compare=[&](std::string_view input,ProgramOptions options=ProgramOptions{}) {
    const auto actual=run_program(input,options), reference=testing::run_program_reference(input,options);
    const auto binary=compile_program_bytecode(input);
    if (const auto* bytes=std::get_if<std::vector<std::uint8_t>>(&binary)) {
      const auto roundtrip=run_program_bytecode(*bytes,options);
      bool equal=roundtrip.index()==actual.index();
      if (equal && std::holds_alternative<NumericValue>(actual)) {
        const auto& a=std::get<NumericValue>(actual);const auto& b=std::get<NumericValue>(roundtrip);equal=a.type==b.type && a.data==b.data;
      } else if (equal) {
        const auto& a=std::get<ProgramDiagnostic>(actual);const auto& b=std::get<ProgramDiagnostic>(roundtrip);
        equal=a.stage==b.stage && a.code==b.code && a.position.byte==b.position.byte && a.position.line==b.position.line && a.position.column==b.position.column;
      }
      if (!equal) {std::cerr<<"source/wire mismatch in "<<input<<'\n';++failures;}
      auto again=compile_program_bytecode(input);
      if (std::get<std::vector<std::uint8_t>>(again)!=*bytes || !std::holds_alternative<std::string>(disassemble_program_bytecode(*bytes))) {
        std::cerr<<"program bytecode nondeterministic or undisassemblable\n";++failures;
      }
    } else if (!std::holds_alternative<ProgramDiagnostic>(actual)) {
      std::cerr<<"valid source failed compilation\n";++failures;
    }
    bool same=actual.index()==reference.index();
    if (same && std::holds_alternative<NumericValue>(actual)) {
      const auto& a=std::get<NumericValue>(actual); const auto& b=std::get<NumericValue>(reference);
      same=a.type==b.type && a.data==b.data;
    } else if (same) {
      const auto& a=std::get<ProgramDiagnostic>(actual); const auto& b=std::get<ProgramDiagnostic>(reference);
      same=a.stage==b.stage && a.code==b.code && a.position.byte==b.position.byte && a.position.line==b.position.line && a.position.column==b.position.column;
    }
    if (!same) { std::cerr<<"VM/reference mismatch in "<<input<<'\n';++failures; }
  };
  auto ok=[&](std::string_view input,std::int64_t expected) {
    compare(input);
    auto result=run_program(input);
    if (auto* e=std::get_if<ProgramDiagnostic>(&result)) {
      std::cerr<<"unexpected "<<e->stage<<" "<<e->code<<" at "<<e->position.line<<":"<<e->position.column<<" in "<<input<<'\n'; ++failures; return;
    }
    auto value=std::get<NumericValue>(result);
    if (value.type!=NumericType::i32 || std::get<std::int64_t>(value.data)!=expected) { std::cerr<<"wrong value in "<<input<<'\n'; ++failures; }
  };
  auto error=[&](std::string_view input,std::string_view code) {
    compare(input);
    auto result=run_program(input); auto* e=std::get_if<ProgramDiagnostic>(&result);
    if (!e || e->code!=code) { std::cerr<<"expected "<<code<<", got "<<(e?e->code:"value")<<" in "<<input<<'\n'; ++failures; }
  };
  ok("fn fact(n:i32)->i32 { if n==0 { return 1; } let m = n-1; return n*fact(m); } fact(5)",120);
  ok("fn fib(n:i32)->i32 { if n==0 {return 0;} if n==1 {return 1;} return fib(n-1)+fib(n-2); } fib(8)",21);
  ok("fn even(n:i32)->i32 { if n==0 {return 1;} return odd(n-1); } fn odd(n:i32)->i32 { if n==0 {return 0;} return even(n-1); } even(8)",1);
  ok("fn f(x:i32)->i32 { var y:i32=x; if y==2 { let x=7; y=x; } else {y=3;} return y; } f(2)",7);
  ok("fn f(x:i32)->i32 { if x==0 {let y=2;} else {let y=3;} return x; } f(4)",4);
  ok("fn f()->i32 {return -2147483648;} f()",-2147483648LL);
  ok("fn f(a:i32,b:i32)->i32 {return a-b;} f(9,2)*3",21);
  error("fn f()->i32 {return 1/0;} f()","divide_by_zero");
  error("fn f()->i32 {return 2147483648;} f()","literal_out_of_range");
  error("fn f()->i32 {return 2i64;} f()","type_mismatch");
  error("fn f(n:i32)->i32 {if n==0 {return 1;} return n*f(n-1);} f(13)","arithmetic_overflow");
  error("fn f()->i32 {return f();} f()","depth_exceeded");
  error("fn f()->i32 {let x=1; x=2; return x;} f()","immutable_local");
  error("fn f()->i32 {let x=1; let x=2; return x;} f()","duplicate_local");
  error("fn f(x:i32,x:i32)->i32 {return x;} f(1,2)","duplicate_parameter");
  error("fn f()->i32 {return 1;} fn f()->i32 {return 2;} f()","duplicate_function");
  error("fn f()->i32 {return x;} f()","unknown_local");
  error("fn f()->i32 {if 1==1 {let x=2;} return x;} f()","unknown_local");
  error("fn f()->i32 {return 1;} f(1)","wrong_arity");
  error("fn f()->i32 {return absent();} f()","unknown_function");
  error("fn f()->i32 {let x=1;} f()","missing_return");
  ok("fn f()->i32 {while 1==1 {return 1;} return 0;} f()",1);
  ok("fn sum(n:i32)->i32 {var i=0; var result=0; while i<n {i=i+1; result=result+i;} return result;} sum(10)",55);
  ok("fn f()->i32 {var i=0; while i<3 {let t=i; i=t+1;} return i;} f()",3);
  ok("fn f()->i32 {var i=0; while i<300 {let t=7; i=i+1;} return i;} f()",300);
  ok("fn f(x:i32)->i32 {return x;} fn g()->i32 {var i=0; while f(i)<4 {i=i+1;} return i;} g()",4);
  ok("fn f()->i32 {if true || false && false {return 1;} return 0;} f()",1);
  ok("fn f()->i32 {if 1+2*3==7 && -2<0 {return 1;} return 0;} f()",1);
  ok("fn f()->i32 {if false && absent()==0 {return 0;} return 1;} f()",1);
  error("fn f()->i32 {if 1/0<absent() {return 1;} return 0;} f()","divide_by_zero");
  error("fn f()->i32 {while true {let x=0;} return 0;} f()","budget_exceeded");
  error("fn f()->i32 {var i=0;while i<2 {let x=1;i=i+1;}return x;} f()","unknown_local");
  ok("fn f()->i32 {var x=7; while false {x=9;} return x;} f()",7);
  ok("fn f()->i32 {if true || (1/0==0) {return 4;} return 1;} f()",4);
  ok("fn f()->i32 {if false && (1/0==0) {return 1;} else {return 9;}} f()",9);
  ok("fn f()->i32 {if !(2+3<5) && (3>=3) && 2!=3 && 4<=4 {return 7;} return 0;} f()",7);
  ok("fn f()->i32 {if true==!false && false!=true {return 1;} return 0;} f()",1);
  ok("fn f()->i32 {var i=0; var x=0; while i<3 {var j=0; while j<4 {j=j+1; x=x+1;} i=i+1;} return x;} f()",12);
  error("fn f()->i32 {while true {} return 0;} f()","budget_exceeded");
  const auto limited=[&](std::string_view code,std::size_t limit,std::string_view expected) {
    compare(code,ProgramOptions{limit});
    auto r=run_program(code,ProgramOptions{limit}); auto* e=std::get_if<ProgramDiagnostic>(&r);
    if ((expected.empty() && e) || (!expected.empty() && (!e || e->code!=expected))) {
      std::cerr<<"budget boundary mismatch at "<<limit<<'\n'; ++failures;
    }
  };
  constexpr auto simple="fn f()->i32 {return 1;} f()";
  limited(simple,0,"budget_exceeded"); limited(simple,2,"budget_exceeded"); limited(simple,3,"");
  for (std::size_t budget=0;budget<80;++budget) {
    compare("fn f(n:i32)->i32 {var x=0; while x<n {if x==2 {x=x+2;} else {x=x+1;}} return x;} f(6)",ProgramOptions{budget});
    compare("fn f(n:i32)->i32 {if n==0 {return 1;} return n*f(n-1);} f(5)",ProgramOptions{budget});
  }
  constexpr auto no_iterations="fn f()->i32 {while false {} return 0;} f()";
  limited(no_iterations,5,"budget_exceeded"); limited(no_iterations,6,"");
  limited("fn f()->i32 {while true {} return 0;} f()",4,"budget_exceeded");
  limited(simple,ProgramOptions::max_allowed_steps+1,"invalid_options");
  limited(simple,3,""); // a new invocation never inherits a previous budget

  error("fn f()->i32 {if 1 {return 1;} return 0;} f()","type_mismatch");
  error("fn f()->i32 {while 1 {} return 0;} f()","type_mismatch");
  error("fn f()->i32 {return true;} f()","type_mismatch");
  error("fn f()->i32 {let x=true; return 0;} f()","type_mismatch");
  error("fn f()->i32 {if 1==true {return 1;} return 0;} f()","type_mismatch");
  error("fn f()->i32 {if true && 1 {return 1;} return 0;} f()","type_mismatch");
  error("fn f()->i32 {while true {break;} return 0;} f()","unsupported_statement");
  error("fn f()->i32 {while true {continue;} return 0;} f()","unsupported_statement");
  error("fn f()->i32 {while false {} else {} return 0;} f()","unsupported_statement");
  error("fn f()->i32 {return 0;} f(1/0)","wrong_arity");
  error("fn f()->i32 {return 0;} (1/0) + missing()","divide_by_zero");
  error("fn f()->i32 {var x=1; if x==1 {var y=3; y=4;} return y;} f()","unknown_local");
  error("fn f(x:i32)->i32 {x=1; return x;} f(0)","immutable_local");
  error("fn f()->i32 {return 1.0;} f()","expected_expression");
  error("fn f()->i32 {return 1;} f()+2u8","type_mismatch");
  error("fn f(n:i32)->i32 {if n==0 {return 1;} if n==1 {return 1;} return f(n-1)+f(n-2);} f(30)","budget_exceeded");
  std::string wide="fn f()->i32 {return 1;} f()"; for (int i=0;i<150;++i) wide+="+1";
  error(wide,"depth_exceeded");
  std::string nested="fn f()->i32 {"; for (int i=0;i<40;++i) nested+="if 1==1 {";
  nested+="return f();"; for (int i=0;i<40;++i) nested+="}"; nested+="return 0;} f()";
  error(nested,"depth_exceeded");
  error(std::string(65537,' '),"source_too_large");
  std::string deep="fn f()->i32 {return "+std::string(90,'(')+"1"+std::string(90,')')+";} f()";
  error(deep,"depth_exceeded");
  std::string dead="fn f()->i32 {if false {return 1";
  for (int i=0;i<400;++i) dead+="+1";
  dead+=";} return 7;} f()";
  ok(dead,7);
  // More than 256 nested pending call arguments must spill rather than
  // fail at compile time; each function still has only 256 registers.
  std::string many="fn f(";
  for (int i=0;i<32;++i) { if (i) many+=","; many+="p"+std::to_string(i)+":i32"; }
  many+=")->i32 {return p31;} ";
  std::string nested_calls="1";
  for (int depth=0;depth<10;++depth) {
    std::string call="f(";
    for (int i=0;i<31;++i) call+="1,";
    nested_calls=call+nested_calls+")";
  }
  ok(many+nested_calls,1);
  for (int n=0;n<100;++n) {
    std::string code="fn f()->i32 {var i=0; var sum=0; while i<"+std::to_string(n)+" {sum=sum+i; i=i+1;} return sum;} f()";
    ok(code,static_cast<std::int64_t>(n)*(n-1)/2);
  }
  std::mt19937 reference_rng(0x4354524c);
  for (int i=0;i<500;++i) {
    int a=static_cast<int>(reference_rng()%100), b=static_cast<int>(reference_rng()%100);
    const bool condition=(a*2+b)<100 && (a!=b || !(b>=50));
    auto code="fn f(a:i32,b:i32)->i32 {if (a*2+b)<100 && (a!=b || !(b>=50)) {return a+b*2;} else {return a-b;}} f("+std::to_string(a)+","+std::to_string(b)+")";
    ok(code,condition ? a+b*2 : a-b);
  }
  ok("fn f()->i32 {if 8>7 && 7<=7 && 7>=7 {return 1;} return 0;} f()",1);
  std::mt19937 rng(0x4d555436);
  for (int i=0;i<5000;++i) {
    std::string s; auto n=rng()%160; for (unsigned j=0;j<n;++j) s.push_back(static_cast<char>(rng()%256));
    (void)run_program(s);
  }
  constexpr std::string_view alphabet="fnretu123{}();=+-*/,: abc";
  for (int i=0;i<5000;++i) {
    std::string s="fn "; auto n=rng()%240;
    for (unsigned j=0;j<n;++j) s.push_back(alphabet[rng()%alphabet.size()]);
    (void)run_program(s);
  }
  const auto wire=std::get<std::vector<std::uint8_t>>(compile_program_bytecode("fn f()->i32 {return 7;} f()"));
  auto invalid=[&](std::span<const std::uint8_t> bytes) {
    const auto result=run_program_bytecode(bytes);
    const auto* error=std::get_if<ProgramDiagnostic>(&result);
    if (!error || error->stage!="bytecode" || error->code!="invalid_program") {std::cerr<<"invalid program bytecode accepted\n";++failures;}
  };
  for (std::size_t n=0;n<wire.size();++n) invalid(std::span(wire).first(n));
  auto corrupted=wire;corrupted.push_back(0);invalid(corrupted);
  for (std::size_t n=0;n<wire.size();++n) {auto bad=wire;bad[n]^=0x80;invalid(bad);}
  for (int k=0;k<1000;++k) {std::vector<std::uint8_t> bad(rng()%100);for (auto& b:bad) b=static_cast<std::uint8_t>(rng());invalid(bad);}
  const auto listing=std::get<std::string>(disassemble_program_bytecode(wire));
  const auto assembled=assemble_program_bytecode(listing);
  if (!std::holds_alternative<std::vector<std::uint8_t>>(assembled) || std::get<std::vector<std::uint8_t>>(assembled)!=wire) {std::cerr<<"program listing roundtrip failed\n";++failures;}
  auto bad_listing=listing;bad_listing.back()='X';
  if (!std::holds_alternative<ProgramDiagnostic>(assemble_program_bytecode(bad_listing)) || !std::holds_alternative<ProgramDiagnostic>(assemble_program_bytecode("MUTP1 zz\n"))) {std::cerr<<"invalid program listing accepted\n";++failures;}
  if (listing.find("function 0\n")==std::string::npos || listing.find("literal")==std::string::npos || listing.find("main\n")==std::string::npos) {std::cerr<<"program listing missing content\n";++failures;}
  return failures ? 1 : 0;
}
