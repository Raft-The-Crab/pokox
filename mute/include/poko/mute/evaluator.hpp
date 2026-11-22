#pragma once

#include "poko/mute/parser.hpp"
#include <cstdint>
#include <string_view>
#include <variant>

namespace poko::mute {
enum class NumericType { i8, i16, i32, i64, u8, u16, u32, u64, f32, f64 };
using NumericData = std::variant<std::int64_t, std::uint64_t, float, double>;
struct NumericValue { NumericType type; NumericData data; };
enum class EvalErrorCode { invalid_ast, unknown_identifier, type_mismatch, literal_out_of_range, arithmetic_overflow, divide_by_zero, invalid_unary, unsupported_operator, unsupported_float_environment, budget_exceeded, invalid_binding };
struct EvalDiagnostic { EvalErrorCode code; Position position; };
using EvalResult = std::variant<NumericValue, EvalDiagnostic>;
// Node-visit budget; this is not the future VM instruction/heap budget.
struct EvalOptions { std::size_t max_nodes{1'000'000}; std::size_t max_bindings{10'000}; std::size_t max_binding_bytes{1'048'576}; };
// Borrowed names need only remain valid for the duration of evaluation.
struct NumericBinding { std::string_view name; NumericValue value; };
[[nodiscard]] EvalResult evaluate_arithmetic(const Ast& ast, EvalOptions options = {}, std::span<const NumericBinding> bindings = {});
[[nodiscard]] std::string_view name(NumericType type);
[[nodiscard]] std::string_view name(EvalErrorCode code);
} // namespace poko::mute
