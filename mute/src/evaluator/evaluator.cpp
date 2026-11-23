#include "poko/mute/evaluator.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cfenv>
#include <charconv>
#include <cfloat>
#include <cmath>
#include <cstdint>
#include <limits>
#include <optional>
#include <string_view>
#include <system_error>
#include <utility>
#include <vector>
#if defined(__SSE__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1)
#include <xmmintrin.h>
#define POKO_MUTE_SSE_ENV 1
#else
#define POKO_MUTE_SSE_ENV 0
#endif
// MSVC's feholdexcept/fesetenv reject environments with unmasked exceptions
// and do not round-trip MXCSR. On x64 the SSE control register already covers
// every FP state the evaluator touches, so the fenv calls are skipped there.
#if defined(_MSC_VER) && defined(_M_X64)
#define POKO_MUTE_MSVC_SSE_ENV 1
#else
#define POKO_MUTE_MSVC_SSE_ENV 0
#endif

#ifndef POKO_MUTE_FP_FLAGS_CONFIGURED
#define POKO_MUTE_FP_FLAGS_CONFIGURED 0
#endif

#ifdef __FAST_MATH__
#error "Mute arithmetic requires fast-math to be disabled"
#endif

namespace poko::mute {
namespace {
using E = EvalErrorCode;
using T = NumericType;
bool is_unsigned(T t) { return t==T::u8 || t==T::u16 || t==T::u32 || t==T::u64; }
bool is_float(T t) { return t==T::f32 || t==T::f64; }
unsigned width(T t) {
  switch (t) {
    case T::i8: case T::u8: return 8;
    case T::i16: case T::u16: return 16;
    case T::i32: case T::u32: return 32;
    case T::i64: case T::u64: return 64;
    default: return 0;
  }
}
std::uint64_t unsigned_max(unsigned bits) { return bits==64 ? UINT64_MAX : (std::uint64_t{1}<<bits)-1; }
std::int64_t signed_max(unsigned bits) { return bits==64 ? INT64_MAX : static_cast<std::int64_t>((std::uint64_t{1}<<(bits-1))-1); }
std::int64_t signed_min(unsigned bits) { return bits==64 ? INT64_MIN : -static_cast<std::int64_t>(std::uint64_t{1}<<(bits-1)); }
std::uint64_t magnitude(std::int64_t n) { return n<0 ? std::uint64_t{0}-static_cast<std::uint64_t>(n) : static_cast<std::uint64_t>(n); }
std::int64_t negative(std::uint64_t n) { return n==(std::uint64_t{1}<<63) ? INT64_MIN : -static_cast<std::int64_t>(n); }
std::optional<T> integer_suffix(std::string_view s) {
  constexpr auto suffixes=std::to_array<std::pair<std::string_view,T>>({{"i8",T::i8},{"i16",T::i16},{"i32",T::i32},{"i64",T::i64},{"u8",T::u8},{"u16",T::u16},{"u32",T::u32},{"u64",T::u64}});
  for (auto [suffix,type]:suffixes) if (s.ends_with(suffix)) return type;
  return std::nullopt;
}
std::size_t suffix_length(T type) { return width(type)==8 ? 2 : 3; }
struct Entry { bool pending_integer=false; std::uint64_t integer=0; NumericValue value{T::i32,std::int64_t{0}}; };
using Step = std::variant<Entry, EvalDiagnostic>;
EvalDiagnostic fail(E code,const ExprNode& node) { return {code,node.token_begin}; }
Step literal_integer(const ExprNode& node,T type) {
  std::string_view text=node.spelling;
  if (const auto suffix=integer_suffix(text)) text.remove_suffix(suffix_length(*suffix));
  int base=10;
  if (text.starts_with("0x") || text.starts_with("0X")) { base=16; text.remove_prefix(2); }
  else if (text.starts_with("0b") || text.starts_with("0B")) { base=2; text.remove_prefix(2); }
  else if (text.starts_with("0o") || text.starts_with("0O")) { base=8; text.remove_prefix(2); }
  std::uint64_t number=0;
  auto result=std::from_chars(text.data(),text.data()+text.size(),number,base);
  if (result.ec!=std::errc{} || result.ptr!=text.data()+text.size()) return fail(E::literal_out_of_range,node);
  return Entry{true,number,{type,std::int64_t{0}}};
}
Step materialize(Entry entry,T type,const ExprNode& source) {
  if (!entry.pending_integer) return entry;
  if (is_unsigned(type)) {
    if (entry.integer>unsigned_max(width(type))) return fail(E::literal_out_of_range,source);
    return Entry{false,0,{type,entry.integer}};
  }
  if (entry.integer>static_cast<std::uint64_t>(signed_max(width(type)))) return fail(E::literal_out_of_range,source);
  return Entry{false,0,{type,static_cast<std::int64_t>(entry.integer)}};
}
// Preserve the caller's flags and modes, while masking host FP traps during
// checks, decimal conversion and arithmetic. This guard is thread-local insofar
// as the host C floating-point environment is thread-local.
class FloatEnvironment {
  std::fenv_t saved_{};
#if POKO_MUTE_SSE_ENV
  unsigned mxcsr_{0};
#endif
  bool active_{false};
 public:
  FloatEnvironment() = default;
  FloatEnvironment(const FloatEnvironment&) = delete;
  FloatEnvironment& operator=(const FloatEnvironment&) = delete;
  bool enter() {
#if POKO_MUTE_SSE_ENV
    mxcsr_ = _mm_getcsr();
#endif
#if POKO_MUTE_MSVC_SSE_ENV
    active_ = true;
    _mm_setcsr(mxcsr_ | 0x1f80U);
    return active_;
#else
    active_ = std::feholdexcept(&saved_) == 0;
#if POKO_MUTE_SSE_ENV
    // feholdexcept does not mask SSE exceptions on every platform (e.g. MinGW);
    // mask them explicitly so evaluation cannot trap on the host environment.
    if (active_) _mm_setcsr(mxcsr_ | 0x1f80U);
#endif
    return active_;
#endif
  }
  bool restore() {
    if (!active_) return true;
#if POKO_MUTE_SSE_ENV
    _mm_setcsr(mxcsr_);
#endif
#if !POKO_MUTE_MSVC_SSE_ENV
    if (std::fesetenv(&saved_) != 0) return false;
#endif
    active_ = false;
    return true;
  }
  ~FloatEnvironment() {
    if (!active_) return;
#if POKO_MUTE_SSE_ENV
    _mm_setcsr(mxcsr_);
#endif
#if !POKO_MUTE_MSVC_SSE_ENV
    (void)std::fesetenv(&saved_);
#endif
  }
};
template<class F> bool supported_float() {
  if (!POKO_MUTE_FP_FLAGS_CONFIGURED || !std::numeric_limits<F>::is_iec559 || std::numeric_limits<F>::radix!=2 ||
      std::numeric_limits<F>::has_denorm!=std::denorm_present || FLT_EVAL_METHOD!=0 || std::fegetround()!=FE_TONEAREST) return false;
  if constexpr (sizeof(F)==4) { if (std::numeric_limits<F>::digits!=24) return false; }
  else if constexpr (sizeof(F)==8) { if (std::numeric_limits<F>::digits!=53) return false; }
  else return false;
  // Probe arithmetic rounding as well as fegetround: on some systems the
  // scalar execution unit can be configured independently of the fenv query.
  volatile F one=F{1};
  volatile F half=std::numeric_limits<F>::epsilon()/F{2};
  volatile F one_half=one+half;
  volatile F three_half=half*F{3};
  volatile F one_three_half=one+three_half;
  if (one_half!=F{1} || one_three_half!=F{1}+F{2}*std::numeric_limits<F>::epsilon()) return false;
  // Reject flush-to-zero or denormals-are-zero instead of silently diverging.
  volatile F denorm=std::numeric_limits<F>::denorm_min();
  volatile F twice=denorm+denorm;
  if constexpr (sizeof(F)==4) return std::bit_cast<std::uint32_t>(static_cast<F>(twice))==2;
  else if constexpr (sizeof(F)==8) return std::bit_cast<std::uint64_t>(static_cast<F>(twice))==2;
  else return false;
}
template<class F> Step literal_float(const ExprNode& node,T type) {
  std::string_view text=node.spelling;
  if (text.ends_with("f32") || text.ends_with("f64")) text.remove_suffix(3);
  F number{};
  const auto result=std::from_chars(text.data(),text.data()+text.size(),number,std::chars_format::fixed);
  if (result.ec!=std::errc{} || result.ptr!=text.data()+text.size() || !std::isfinite(number)) return fail(E::literal_out_of_range,node);
  return Entry{false,0,{type,number}};
}
Step unary(const ExprNode& node,const ExprNode& child,Entry operand,T type) {
  if (node.op==ArithmeticOp::minus && operand.pending_integer && !is_unsigned(type) && !is_float(type)) {
    const auto limit=magnitude(signed_min(width(type)));
    if (operand.integer>limit) return fail(E::literal_out_of_range,child);
    return Entry{false,0,{type,negative(operand.integer)}};
  }
  auto ready=materialize(operand,type,child);
  if (auto* error=std::get_if<EvalDiagnostic>(&ready)) return *error;
  auto value=std::get<Entry>(ready);
  if (node.op==ArithmeticOp::plus) return value;
  if (node.op!=ArithmeticOp::minus) return fail(E::invalid_ast,node);
  if (is_unsigned(type)) return fail(E::invalid_unary,node);
  if (type==T::f32) return Entry{false,0,{type,-std::get<float>(value.value.data)}};
  if (type==T::f64) return Entry{false,0,{type,-std::get<double>(value.value.data)}};
  const auto n=std::get<std::int64_t>(value.value.data);
  if (n==signed_min(width(type))) return fail(E::arithmetic_overflow,node);
  return Entry{false,0,{type,-n}};
}
Step unsigned_binary(const ExprNode& node,T type,std::uint64_t a,std::uint64_t b) {
  const auto max=unsigned_max(width(type)); std::uint64_t result=0;
  switch (node.op) {
    case ArithmeticOp::plus: if (a>max-b) return fail(E::arithmetic_overflow,node); result=a+b; break;
    case ArithmeticOp::minus: if (a<b) return fail(E::arithmetic_overflow,node); result=a-b; break;
    case ArithmeticOp::multiply: if (b && a>max/b) return fail(E::arithmetic_overflow,node); result=a*b; break;
    case ArithmeticOp::divide: if (!b) return fail(E::divide_by_zero,node); result=a/b; break;
    case ArithmeticOp::remainder: if (!b) return fail(E::divide_by_zero,node); result=a%b; break;
    default: return fail(E::invalid_ast,node);
  }
  return Entry{false,0,{type,result}};
}
Step signed_binary(const ExprNode& node,T type,std::int64_t a,std::int64_t b) {
  const auto min=signed_min(width(type)), max=signed_max(width(type)); std::int64_t result=0;
  switch (node.op) {
    case ArithmeticOp::plus:
      if ((b>0 && a>max-b) || (b<0 && a<min-b)) return fail(E::arithmetic_overflow,node);
      result=a+b; break;
    case ArithmeticOp::minus:
      if ((b>0 && a<min+b) || (b<0 && a>max+b)) return fail(E::arithmetic_overflow,node);
      result=a-b; break;
    case ArithmeticOp::multiply: {
      const bool neg=(a<0)!=(b<0); const auto x=magnitude(a),y=magnitude(b);
      const auto limit=neg ? magnitude(min) : static_cast<std::uint64_t>(max);
      if (y && x>limit/y) return fail(E::arithmetic_overflow,node);
      const auto product=x*y; result=neg ? negative(product) : static_cast<std::int64_t>(product); break;
    }
    case ArithmeticOp::divide: case ArithmeticOp::remainder:
      if (!b) return fail(E::divide_by_zero,node);
      if (a==min && b==-1) return fail(E::arithmetic_overflow,node);
      result=node.op==ArithmeticOp::divide ? a/b : a%b; break;
    default: return fail(E::invalid_ast,node);
  }
  return Entry{false,0,{type,result}};
}
template<class F> Step float_binary(const ExprNode& node,T type,F a,F b) {
  F result{};
  switch (node.op) {
    case ArithmeticOp::plus: result=a+b; break;
    case ArithmeticOp::minus: result=a-b; break;
    case ArithmeticOp::multiply: result=a*b; break;
    case ArithmeticOp::divide: if (b==F{0}) return fail(E::divide_by_zero,node); result=a/b; break;
    case ArithmeticOp::remainder: if (b==F{0}) return fail(E::divide_by_zero,node); result=std::fmod(a,b); break;
    default: return fail(E::invalid_ast,node);
  }
  if (!std::isfinite(result)) return fail(E::arithmetic_overflow,node);
  return Entry{false,0,{type,result}};
}
} // namespace
EvalResult evaluate_arithmetic(const Ast& ast, EvalOptions options, std::span<const NumericBinding> bindings) {
  const auto nodes=ast.nodes();
  if (ast.root()>=nodes.size()) return EvalDiagnostic{E::invalid_ast,{0,1,1}};
  if (nodes.size()>options.max_nodes) return EvalDiagnostic{E::budget_exceeded,nodes[options.max_nodes].token_begin};
  const auto root_error = [&](E e) { return EvalDiagnostic{e,nodes[ast.root()].token_begin}; };
  if (bindings.size()>options.max_bindings) return root_error(E::budget_exceeded);
  std::size_t bytes=0;
  std::vector<const NumericBinding*> sorted;
  sorted.reserve(bindings.size());
  for (const auto& binding:bindings) {
    if (binding.name.empty()) return root_error(E::invalid_binding);
    if (binding.name.size()>options.max_binding_bytes-bytes) return root_error(E::budget_exceeded);
    bytes+=binding.name.size(); sorted.push_back(&binding);
  }
  std::sort(sorted.begin(),sorted.end(),[](auto a,auto b){ return a->name<b->name; });
  for (std::size_t i=1;i<sorted.size();++i)
    if (sorted[i-1]->name==sorted[i]->name) return root_error(E::invalid_binding);
  const auto lookup = [&](std::string_view name) -> const NumericBinding* {
    const auto it=std::lower_bound(sorted.begin(),sorted.end(),name,
      [](const NumericBinding* b,std::string_view n){return b->name<n;});
    return it!=sorted.end() && (*it)->name==name ? *it : nullptr;
  };
  std::optional<T> selected; bool saw_integer=false, saw_float=false;
  for (const auto& node:nodes) {
    std::optional<T> explicit_type;
    if (node.kind==ExprKind::identifier) {
      const auto* binding=lookup(node.spelling);
      if (!binding) return fail(E::unknown_identifier,node);
      const auto t=binding->value.type;
      switch (t) {
        case T::i8: case T::i16: case T::i32: case T::i64: case T::u8: case T::u16: case T::u32: case T::u64: saw_integer=true; break;
        case T::f32: case T::f64: saw_float=true; break;
        default: return fail(E::invalid_binding,node);
      }
      explicit_type=t;
    }
    if (node.kind==ExprKind::integer) { saw_integer=true; explicit_type=integer_suffix(node.spelling); }
    if (node.kind==ExprKind::floating) { saw_float=true; explicit_type=node.spelling.ends_with("f32") ? T::f32 : T::f64; }
    if (saw_integer && saw_float) return fail(E::type_mismatch,node);
    if (explicit_type) {
      if (selected && *selected!=*explicit_type) return fail(E::type_mismatch,node);
      selected=explicit_type;
    }
  }
  const auto type=selected.value_or(T::i32);
  FloatEnvironment environment;
  if (is_float(type) && !environment.enter()) return EvalDiagnostic{E::unsupported_float_environment,nodes[ast.root()].token_begin};
  auto execute = [&]() -> EvalResult {
    if ((type==T::f32 && !supported_float<float>()) || (type==T::f64 && !supported_float<double>())) return EvalDiagnostic{E::unsupported_float_environment,nodes[ast.root()].token_begin};
    std::vector<Entry> values; values.reserve(nodes.size());
    for (std::size_t i=0;i<nodes.size();++i) {
      const auto& node=nodes[i]; Step step=Entry{};
      if (node.kind==ExprKind::integer) step=literal_integer(node,type);
      else if (node.kind==ExprKind::floating) step=type==T::f32 ? literal_float<float>(node,type) : literal_float<double>(node,type);
      else if (node.kind==ExprKind::identifier) {
        const auto* binding=lookup(node.spelling);
        if (!binding) return fail(E::unknown_identifier,node);
        const auto& data=binding->value.data;
        if (is_unsigned(type)) {
          const auto* n=std::get_if<std::uint64_t>(&data);
          if (!n || *n>unsigned_max(width(type))) return fail(E::invalid_binding,node);
        } else if (type==T::f32) {
          const auto* n=std::get_if<float>(&data);
          if (!n || !std::isfinite(*n)) return fail(E::invalid_binding,node);
        } else if (type==T::f64) {
          const auto* n=std::get_if<double>(&data);
          if (!n || !std::isfinite(*n)) return fail(E::invalid_binding,node);
        } else {
          const auto* n=std::get_if<std::int64_t>(&data);
          if (!n || *n<signed_min(width(type)) || *n>signed_max(width(type))) return fail(E::invalid_binding,node);
        }
        step=Entry{false,0,binding->value};
      }
      else if (node.kind==ExprKind::unary) {
        if (node.left>=i) return fail(E::invalid_ast,node);
        step=unary(node,nodes[node.left],values[node.left],type);
      } else if (node.kind==ExprKind::binary) {
        if (node.left>=i || node.right>=i) return fail(E::invalid_ast,node);
        auto left=materialize(values[node.left],type,nodes[node.left]);
        if (auto* error=std::get_if<EvalDiagnostic>(&left)) return *error;
        auto right=materialize(values[node.right],type,nodes[node.right]);
        if (auto* error=std::get_if<EvalDiagnostic>(&right)) return *error;
        const auto& a=std::get<Entry>(left).value.data; const auto& b=std::get<Entry>(right).value.data;
        if (is_unsigned(type)) step=unsigned_binary(node,type,std::get<std::uint64_t>(a),std::get<std::uint64_t>(b));
        else if (type==T::f32) step=float_binary(node,type,std::get<float>(a),std::get<float>(b));
        else if (type==T::f64) step=float_binary(node,type,std::get<double>(a),std::get<double>(b));
        else step=signed_binary(node,type,std::get<std::int64_t>(a),std::get<std::int64_t>(b));
      } else return fail(E::invalid_ast,node);
      if (auto* error=std::get_if<EvalDiagnostic>(&step)) return *error;
      values.push_back(std::get<Entry>(step));
    }
    auto result=materialize(values[ast.root()],type,nodes[ast.root()]);
    if (auto* error=std::get_if<EvalDiagnostic>(&result)) return *error;
    return std::get<Entry>(result).value;
  };
  auto result = execute();
  if (!environment.restore()) return EvalDiagnostic{E::unsupported_float_environment,nodes[ast.root()].token_begin};
  return result;
}
std::string_view name(NumericType type) {
  constexpr auto names=std::to_array<std::string_view>({"i8","i16","i32","i64","u8","u16","u32","u64","f32","f64"});
  return names.at(static_cast<std::size_t>(type));
}
std::string_view name(EvalErrorCode error) {
  constexpr auto names=std::to_array<std::string_view>({"invalid_ast","unknown_identifier","type_mismatch","literal_out_of_range","arithmetic_overflow","divide_by_zero","invalid_unary","unsupported_operator","unsupported_float_environment","budget_exceeded","invalid_binding"});
  return names.at(static_cast<std::size_t>(error));
}
} // namespace poko::mute
