#include "poko/mute/evaluator.hpp"
#include <iostream>
#include <string>
#include <variant>
using namespace poko::mute;
namespace {
bool check(int a,int b,char op,bool is_unsigned) {
  const std::string input=std::to_string(a)+(is_unsigned?"u8 ":"i8 ")+op+" "+std::to_string(b);
  auto parsed=parse_arithmetic(input); auto ast=std::get_if<Ast>(&parsed);
  if (!ast) { std::cerr<<"parse failed: "<<input<<'\n'; return false; }
  auto result=evaluate_arithmetic(*ast);
  const int minimum=is_unsigned?0:-128, maximum=is_unsigned?255:127;
  bool divide_zero=(op=='/' || op=='%') && b==0;
  bool overflow=(op=='/' || op=='%') && !is_unsigned && a==-128 && b==-1;
  int expected=0;
  if (!divide_zero && !overflow) {
    switch(op) { case '+': expected=a+b; break; case '-': expected=a-b; break; case '*': expected=a*b; break; case '/': expected=a/b; break; default: expected=a%b; break; }
    overflow=expected<minimum || expected>maximum;
  }
  if (divide_zero || overflow) {
    auto error=std::get_if<EvalDiagnostic>(&result);
    if (error && error->code==(divide_zero?EvalErrorCode::divide_by_zero:EvalErrorCode::arithmetic_overflow)) return true;
  } else if (auto value=std::get_if<NumericValue>(&result)) {
    if (is_unsigned && value->type==NumericType::u8 && std::get<std::uint64_t>(value->data)==static_cast<std::uint64_t>(expected)) return true;
    if (!is_unsigned && value->type==NumericType::i8 && std::get<std::int64_t>(value->data)==expected) return true;
  }
  std::cerr<<"arithmetic mismatch: "<<input<<'\n'; return false;
}
}
int main() {
  constexpr char ops[]={'+','-','*','/','%'};
  for (bool u:{false,true}) {
    const int first=u?0:-128, last=u?255:127;
    for (int a=first;a<=last;++a) for (int b=first;b<=last;++b) for (char op:ops) if (!check(a,b,op,u)) return 1;
  }
  std::cout<<"PASS: 655360 signed and unsigned 8-bit operation cases\n";
}
