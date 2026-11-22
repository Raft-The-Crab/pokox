#include "poko/mute/evaluator.hpp"
#include <array>
#include <bit>
#include <cfenv>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <variant>
#if defined(__SSE__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1)
#include <xmmintrin.h>
#define POKO_TEST_X86_SSE 1
#endif
using namespace poko::mute;
namespace {
int failures=0;
void check(bool condition,std::string_view message) { if (!condition) { std::cerr<<message<<'\n'; ++failures; } }
EvalResult eval(std::string_view expression) {
  auto parsed=parse_arithmetic(expression);
  if (auto ast=std::get_if<Ast>(&parsed)) return evaluate_arithmetic(*ast);
  std::cerr << "parse failed: " << expression << '\n'; ++failures;
  return EvalDiagnostic{EvalErrorCode::invalid_ast,{0,1,1}};
}
void signed_case(std::string_view expression,NumericType type,std::int64_t expected) {
  auto result=eval(expression); const auto* value=std::get_if<NumericValue>(&result);
  if (!value || value->type!=type || !std::holds_alternative<std::int64_t>(value->data) || std::get<std::int64_t>(value->data)!=expected) {
    std::cerr<<"signed mismatch: "<<expression<<'\n'; ++failures;
  }
}
void unsigned_case(std::string_view expression,NumericType type,std::uint64_t expected) {
  auto result=eval(expression); const auto* value=std::get_if<NumericValue>(&result);
  if (!value || value->type!=type || !std::holds_alternative<std::uint64_t>(value->data) || std::get<std::uint64_t>(value->data)!=expected) {
    std::cerr<<"unsigned mismatch: "<<expression<<'\n'; ++failures;
  }
}
void error_case(std::string_view expression,EvalErrorCode code,std::size_t byte) {
  auto result=eval(expression); const auto* error=std::get_if<EvalDiagnostic>(&result);
  if (!error || error->code!=code || error->position.byte!=byte) { std::cerr<<"error mismatch: "<<expression<<" expected "<<name(code)<<'\n'; ++failures; }
}
void cases() {
  signed_case("1 + 2 * (3 - 5)",NumericType::i32,-3);
  signed_case("-7 / 3",NumericType::i32,-2);
  signed_case("-7 % 3",NumericType::i32,-1);
  signed_case("1 + 2i64",NumericType::i64,3);
  signed_case("0xffi16 + 0b10",NumericType::i16,257);
  signed_case("-128i8",NumericType::i8,-128);
  signed_case("-32768i16",NumericType::i16,-32768);
  signed_case("-2147483648",NumericType::i32,INT32_MIN);
  signed_case("-9223372036854775808i64",NumericType::i64,INT64_MIN);
  signed_case("9223372036854775807i64",NumericType::i64,INT64_MAX);
  signed_case("-2147483648 * 1",NumericType::i32,INT32_MIN);
  signed_case("-3037000499i64 * -3037000499i64",NumericType::i64,9223372030926249001LL);
  unsigned_case("255u8",NumericType::u8,255);
  unsigned_case("65535u16 - 1",NumericType::u16,65534);
  unsigned_case("4294967295u32",NumericType::u32,UINT32_MAX);
  unsigned_case("18446744073709551615u64",NumericType::u64,UINT64_MAX);
  unsigned_case("0xFFFFFFFFFFFFFFFFu64 / 3",NumericType::u64,UINT64_MAX/3);
  unsigned_case("+0o10u8 * 2",NumericType::u8,16);
  error_case("128i8",EvalErrorCode::literal_out_of_range,0);
  error_case("-129i8",EvalErrorCode::literal_out_of_range,1);
  error_case("18446744073709551616u64",EvalErrorCode::literal_out_of_range,0);
  error_case("127i8 + 1",EvalErrorCode::arithmetic_overflow,6);
  error_case("-128i8 - 1",EvalErrorCode::arithmetic_overflow,7);
  error_case("-(-128i8)",EvalErrorCode::arithmetic_overflow,0);
  error_case("-9223372036854775808i64 / -1",EvalErrorCode::arithmetic_overflow,24);
  error_case("-9223372036854775808i64 % -1",EvalErrorCode::arithmetic_overflow,24);
  error_case("3037000500i64 * 3037000500",EvalErrorCode::arithmetic_overflow,14);
  error_case("0u8 - 1",EvalErrorCode::arithmetic_overflow,4);
  error_case("255u8 + 1",EvalErrorCode::arithmetic_overflow,6);
  error_case("18446744073709551615u64 * 2",EvalErrorCode::arithmetic_overflow,24);
  error_case("-0u8",EvalErrorCode::invalid_unary,0);
  error_case("1 / 0",EvalErrorCode::divide_by_zero,2);
  error_case("1 % 0",EvalErrorCode::divide_by_zero,2);
  error_case("1i8 + 1i16",EvalErrorCode::type_mismatch,6);
  error_case("1 + 1.0",EvalErrorCode::type_mismatch,4);
  error_case("1.0 + 1",EvalErrorCode::type_mismatch,6);
  error_case("alpha + 2",EvalErrorCode::unknown_identifier,0);
}
void floating() {
  auto f32=eval("1.5f32 + 2.25f32");
  auto f=std::get_if<NumericValue>(&f32);
  check(f && f->type==NumericType::f32 && std::holds_alternative<float>(f->data) && std::bit_cast<std::uint32_t>(std::get<float>(f->data))==0x40700000U,"f32 addition bits");
  auto f64=eval("-1.5 * (2.0 + 1.0)");
  f=std::get_if<NumericValue>(&f64);
  check(f && f->type==NumericType::f64 && std::holds_alternative<double>(f->data) && std::bit_cast<std::uint64_t>(std::get<double>(f->data))==UINT64_C(0xc012000000000000),"f64 arithmetic bits");
  auto zero=eval("-0.0"); f=std::get_if<NumericValue>(&zero);
  check(f && std::bit_cast<std::uint64_t>(std::get<double>(f->data))==UINT64_C(0x8000000000000000),"signed zero");
  error_case("1.0 / -0.0",EvalErrorCode::divide_by_zero,4);
  auto rem=eval("-5.5 % 2.0"); f=std::get_if<NumericValue>(&rem);
  check(f && std::bit_cast<std::uint64_t>(std::get<double>(f->data))==UINT64_C(0xbff8000000000000),"f64 negative remainder");
  rem=eval("5.5f32 % -2.0f32"); f=std::get_if<NumericValue>(&rem);
  check(f && std::bit_cast<std::uint32_t>(std::get<float>(f->data))==0x3fc00000U,"f32 remainder");
  rem=eval("-0.0 % 3.0"); f=std::get_if<NumericValue>(&rem);
  check(f && std::bit_cast<std::uint64_t>(std::get<double>(f->data))==UINT64_C(0x8000000000000000),"remainder signed zero");
  error_case("1.0 % -0.0",EvalErrorCode::divide_by_zero,4);
  error_case("1.0f32 + 1.0",EvalErrorCode::type_mismatch,9);
  const std::string tiny="0."+std::string(44,'0')+"14f32";
  auto subnormal=eval(tiny); f=std::get_if<NumericValue>(&subnormal);
  check(f && std::bit_cast<std::uint32_t>(std::get<float>(f->data))==1,"f32 subnormal literal bits");
  const std::string underflow="0."+std::string(50,'0')+"1f32";
  error_case(underflow,EvalErrorCode::literal_out_of_range,0);
  error_case("340282346638528859811704183484516925440.0f32 * 2.0f32",EvalErrorCode::arithmetic_overflow,45);
  std::fenv_t saved{};
  if (std::fegetenv(&saved)==0 && std::feclearexcept(FE_ALL_EXCEPT)==0 && std::feraiseexcept(FE_INEXACT)==0) {
    auto preserved=eval("1.0 / 3.0");
    const int flags=std::fetestexcept(FE_ALL_EXCEPT);
    const int restore=std::fesetenv(&saved);
    check(std::holds_alternative<NumericValue>(preserved) && (flags&FE_INEXACT)!=0 && restore==0,"FP exception flags not preserved");
  } else check(false,"cannot test FP environment preservation");
  const int previous=std::fegetround();
  if (previous!=-1 && std::fesetround(FE_DOWNWARD)==0) {
    error_case("1.0 + 2.0",EvalErrorCode::unsupported_float_environment,4);
    check(std::fesetround(previous)==0,"rounding mode not restored");
  } else { check(false,"cannot test alternate rounding mode"); }
#if POKO_TEST_X86_SSE
  const unsigned csr=_mm_getcsr();
  _mm_setcsr(csr | (1U<<15) | (1U<<6));
  error_case("1.0 + 2.0",EvalErrorCode::unsupported_float_environment,4);
  _mm_setcsr(csr);
  // Change SSE rounding without changing the separate C fenv rounding state.
  _mm_setcsr((csr & ~(3U<<13)) | (2U<<13));
  error_case("1.0 + 2.0",EvalErrorCode::unsupported_float_environment,4);
  _mm_setcsr(csr);
  // With the overflow trap unmasked, evaluation must return a diagnostic and
  // restore the caller's exact SSE control/status register without trapping.
  const unsigned unmasked=(csr | 0x1f80U) & ~(1U<<10) & ~0x3fU;
  _mm_setcsr(unmasked);
  auto overflow=eval("340282346638528859811704183484516925440.0f32 * 2.0f32");
  const unsigned restored=_mm_getcsr();
  _mm_setcsr(csr);
  const auto* overflow_error=std::get_if<EvalDiagnostic>(&overflow);
  check(overflow_error && overflow_error->code==EvalErrorCode::arithmetic_overflow && restored==unmasked,"FP trap masking or restoration failed");
#endif
}
void bindings() {
  auto parsed=parse_arithmetic("x + x * 2");
  auto* ast=std::get_if<Ast>(&parsed);
  if (!ast) { check(false,"binding parse"); return; }
  const std::array<NumericBinding,1> good{{{"x",{NumericType::i8,std::int64_t{4}}}}};
  auto result=evaluate_arithmetic(*ast,{},good); const auto* value=std::get_if<NumericValue>(&result);
  check(value && value->type==NumericType::i8 && std::get<std::int64_t>(value->data)==12,"binding result/inference");
  const std::array<NumericBinding,2> duplicate{{good[0],good[0]}};
  result=evaluate_arithmetic(*ast,{},duplicate);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"duplicate bindings");
  const std::array<NumericBinding,1> wrong{{{"x",{NumericType::i8,std::uint64_t{4}}}}};
  result=evaluate_arithmetic(*ast,{},wrong);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"binding variant validation");
  const std::array<NumericBinding,1> range{{{"x",{NumericType::i8,std::int64_t{128}}}}};
  result=evaluate_arithmetic(*ast,{},range);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"binding range validation");
  result=evaluate_arithmetic(*ast,EvalOptions{100,0,100},good);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::budget_exceeded,"binding count limit");
  result=evaluate_arithmetic(*ast,EvalOptions{100,1,0},good);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::budget_exceeded,"binding byte limit");
  const std::array<NumericBinding,1> badtype{{{"x",{static_cast<NumericType>(999),std::int64_t{1}}}}};
  result=evaluate_arithmetic(*ast,{},badtype);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"binding type enum validation");
  const std::array<NumericBinding,1> empty{{{"",{NumericType::i8,std::int64_t{1}}}}};
  result=evaluate_arithmetic(*ast,{},empty);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"empty binding name");
  const std::array<NumericBinding,1> missing{{{"other",{NumericType::i8,std::int64_t{1}}}}};
  result=evaluate_arithmetic(*ast,{},missing);
  check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::unknown_identifier,"missing binding");
  auto fp=parse_arithmetic("x % 2.0f32"); auto* fpast=std::get_if<Ast>(&fp);
  const std::array<NumericBinding,1> floats{{{"x",{NumericType::f32,5.5f}}}};
  if (fpast) {
    result=evaluate_arithmetic(*fpast,{},floats); value=std::get_if<NumericValue>(&result);
    check(value && std::bit_cast<std::uint32_t>(std::get<float>(value->data))==0x3fc00000U,"float binding/remainder");
    const std::array<NumericBinding,1> nan{{{"x",{NumericType::f32,std::numeric_limits<float>::quiet_NaN()}}}};
    result=evaluate_arithmetic(*fpast,{},nan);
    check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding,"nonfinite binding");
  } else check(false,"float binding parse");
  auto pair=parse_arithmetic("x % y");
  if (auto* a=std::get_if<Ast>(&pair)) {
    const std::array<NumericBinding,2> sub{{{"x",{NumericType::f32,std::bit_cast<float>(std::uint32_t{3})}}, {"y",{NumericType::f32,std::bit_cast<float>(std::uint32_t{2})}}}};
    result=evaluate_arithmetic(*a,{},sub); value=std::get_if<NumericValue>(&result);
    check(value && std::bit_cast<std::uint32_t>(std::get<float>(value->data))==1,"subnormal remainder");
#if POKO_TEST_X86_SSE
    const unsigned csr=_mm_getcsr();
    const unsigned unmasked=(csr | 0x1f80U) & ~(1U<<7) & ~0x3fU;
    const std::array<NumericBinding,2> snan{{{"x",{NumericType::f32,std::bit_cast<float>(std::uint32_t{0x7f800001})}},sub[1]}};
    _mm_setcsr(unmasked);
    result=evaluate_arithmetic(*a,{},snan);
    const unsigned restored=_mm_getcsr(); _mm_setcsr(csr);
    check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_binding && restored==unmasked,"signaling NaN trap masking/restoration");
#endif
  } else check(false,"subnormal binding parse");
  auto mixed=parse_arithmetic("x + 1.0");
  if (auto* a=std::get_if<Ast>(&mixed)) {
    result=evaluate_arithmetic(*a,{},good);
    check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::type_mismatch,"binding type mismatch");
  } else check(false,"mixed binding parse");
}
void deep() {
  std::string expression="1"; for (int i=0;i<30000;++i) expression+="+1";
  signed_case(expression,NumericType::i32,30001);
  std::string unary(30000,'-'); unary+='1'; signed_case(unary,NumericType::i32,1);
  auto budget_parse=parse_arithmetic("1 + 1");
  if (auto ast=std::get_if<Ast>(&budget_parse)) {
    check(std::holds_alternative<NumericValue>(evaluate_arithmetic(*ast,EvalOptions{3})),"exact node budget failed");
    auto limited=evaluate_arithmetic(*ast,EvalOptions{2});
    check(std::get_if<EvalDiagnostic>(&limited) && std::get<EvalDiagnostic>(limited).code==EvalErrorCode::budget_exceeded,"node budget not enforced");
    limited=evaluate_arithmetic(*ast,EvalOptions{0});
    check(std::get_if<EvalDiagnostic>(&limited) && std::get<EvalDiagnostic>(limited).code==EvalErrorCode::budget_exceeded,"zero node budget not enforced");
  } else check(false,"node budget parse failure");
  auto parsed=parse_arithmetic("1");
  auto* original=std::get_if<Ast>(&parsed);
  if (original) { Ast moved=std::move(*original); (void)moved; auto result=evaluate_arithmetic(*original); check(std::get_if<EvalDiagnostic>(&result) && std::get<EvalDiagnostic>(result).code==EvalErrorCode::invalid_ast,"moved-from AST"); }
  else check(false,"moved AST parse failure");
}
}
int main() { cases(); floating(); bindings(); deep(); return failures ? 1 : 0; }
