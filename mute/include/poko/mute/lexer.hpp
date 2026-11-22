#pragma once

#include <cstddef>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {
enum class TokenKind { identifier, keyword, integer, floating, string_literal, doc_comment, punctuation, op, end };
enum class ErrorCode { invalid_utf8, bom, unexpected_character, invalid_number, unterminated_string, invalid_escape, unterminated_comment, unterminated_interpolation, source_too_large };
struct Position { std::size_t byte, line, column; };
struct Token { TokenKind kind; Position begin; std::size_t end_byte; };
struct Diagnostic { ErrorCode code; Position position; };
using Result = std::variant<std::vector<Token>, Diagnostic>;
// Positions refer to original bytes; line and Unicode-scalar column are one-based.
// The caller owns the input; tokens store offsets, not views into it.
// Rejected before scanning or allocating; positions for this error are 0:1:1.
struct LexOptions { std::size_t max_source_bytes{1'048'576}; };
[[nodiscard]] Result lex(std::string_view input, LexOptions options = {});
[[nodiscard]] std::string_view name(TokenKind kind);
[[nodiscard]] std::string_view name(ErrorCode code);
} // namespace poko::mute
