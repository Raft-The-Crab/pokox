#include "poko/mute/lexer.hpp"
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace {
using namespace poko::mute;
int failures = 0;
void check(bool ok, std::string_view message) {
  if (!ok) { std::cerr << message << '\n'; ++failures; }
}
using Expected = std::pair<TokenKind, std::string_view>;
void tokens(std::string_view input, const std::vector<Expected>& expected) {
  const auto result = lex(input);
  const auto* actual = std::get_if<std::vector<Token>>(&result);
  if (!actual || actual->size() != expected.size() + 1) {
    std::cerr << "unexpected tokenization: " << input << '\n'; ++failures; return;
  }
  for (std::size_t i = 0; i < expected.size(); ++i) {
    const auto& token = (*actual)[i];
    if (token.kind != expected[i].first || token.end_byte < token.begin.byte ||
        token.end_byte > input.size() ||
        input.substr(token.begin.byte, token.end_byte-token.begin.byte) != expected[i].second) {
      std::cerr << "token " << i << " mismatch in " << input << '\n'; ++failures; return;
    }
  }
  check(actual->back().kind == TokenKind::end && actual->back().begin.byte == input.size() &&
        actual->back().end_byte == input.size(), "invalid EOF token");
}
void diagnostic(std::string_view input, ErrorCode code, std::size_t byte, std::size_t line, std::size_t column) {
  const auto result = lex(input);
  const auto* actual = std::get_if<Diagnostic>(&result);
  if (!actual || actual->code != code || actual->position.byte != byte ||
      actual->position.line != line || actual->position.column != column) {
    std::cerr << "diagnostic mismatch: " << name(code) << '\n'; ++failures;
  }
}
void examples() {
  constexpr auto K = TokenKind::keyword; constexpr auto I = TokenKind::identifier;
  constexpr auto N = TokenKind::integer; constexpr auto F = TokenKind::floating;
  constexpr auto O = TokenKind::op; constexpr auto P = TokenKind::punctuation;
  tokens("package version allow import as struct enum let var fn async await for in if while loop match guard else break continue return true false move pub spawn trait impl",
    {{K,"package"},{K,"version"},{K,"allow"},{K,"import"},{K,"as"},{K,"struct"},{K,"enum"},{K,"let"},{K,"var"},{K,"fn"},{K,"async"},{K,"await"},{K,"for"},{K,"in"},{K,"if"},{K,"while"},{K,"loop"},{K,"match"},{K,"guard"},{K,"else"},{K,"break"},{K,"continue"},{K,"return"},{K,"true"},{K,"false"},{K,"move"},{K,"pub"},{K,"spawn"},{K,"trait"},{K,"impl"}});
  tokens("letdown trueValue state x_0 a\xcc\x81", {{I,"letdown"},{I,"trueValue"},{I,"state"},{I,"x_0"},{I,"a\xcc\x81"}});
  tokens("0 42i8 12i16 12i32 12i64 3u8 3u16 3u32 3u64 0xffi8 0b10u32 0o77 1.2 1.2f32 1.2f64",
    {{N,"0"},{N,"42i8"},{N,"12i16"},{N,"12i32"},{N,"12i64"},{N,"3u8"},{N,"3u16"},{N,"3u32"},{N,"3u64"},{N,"0xffi8"},{N,"0b10u32"},{N,"0o77"},{F,"1.2"},{F,"1.2f32"},{F,"1.2f64"}});
  tokens("<<= >>= ..= == != <= >= && || << >> += -= *= /= %= &= |= ^= .. -> => :: + - * / % ! < > = & | ^ ? . : @ () [] {} , ;",
    {{O,"<<="},{O,">>="},{O,"..="},{O,"=="},{O,"!="},{O,"<="},{O,">="},{O,"&&"},{O,"||"},{O,"<<"},{O,">>"},{O,"+="},{O,"-="},{O,"*="},{O,"/="},{O,"%="},{O,"&="},{O,"|="},{O,"^="},{O,".."},{O,"->"},{O,"=>"},{O,"::"},{O,"+"},{O,"-"},{O,"*"},{O,"/"},{O,"%"},{O,"!"},{O,"<"},{O,">"},{O,"="},{O,"&"},{O,"|"},{O,"^"},{O,"?"},{P,"."},{P,":"},{P,"@"},{P,"("},{P,")"},{P,"["},{P,"]"},{P,"{"},{P,"}"},{P,","},{P,";"}});
  tokens("1..2 1..=2 1. 1.0", {{N,"1"},{O,".."},{N,"2"},{N,"1"},{O,"..="},{N,"2"},{N,"1"},{P,"."},{F,"1.0"}});
  tokens("/// doc\r\n/* ignore /* non-nesting */ x // ignore\n/", {{TokenKind::doc_comment,"/// doc"},{I,"x"},{O,"/"}});
  tokens(R"mute("hi \n \\ \" \{ \} {f("x", {a:1}) /* } */}")mute", {{TokenKind::string_literal,R"mute("hi \n \\ \" \{ \} {f("x", {a:1}) /* } */}")mute"}});
  tokens("", {});
  diagnostic("letdown trueValue state _", ErrorCode::unexpected_character, 24, 1, 25);
  diagnostic("\xef\xbb\xbf", ErrorCode::bom, 0, 1, 1);
  diagnostic("a\r\n\xc3\xa9 \xff", ErrorCode::invalid_utf8, 6, 2, 3);
  diagnostic("//\xc0\x80", ErrorCode::invalid_utf8, 2, 1, 3);
  diagnostic("\xf0\x9f\x92", ErrorCode::invalid_utf8, 0, 1, 1);
  diagnostic("0b102", ErrorCode::invalid_number, 0, 1, 1);
  diagnostic("0o8", ErrorCode::invalid_number, 0, 1, 1);
  diagnostic("1f32", ErrorCode::invalid_number, 0, 1, 1);
  diagnostic("1.2u8", ErrorCode::invalid_number, 0, 1, 1);
  diagnostic("1_0", ErrorCode::invalid_number, 0, 1, 1);
  diagnostic("/* missing", ErrorCode::unterminated_comment, 0, 1, 1);
  diagnostic("\"a\\q\"", ErrorCode::invalid_escape, 2, 1, 3);
  diagnostic("\"a\n", ErrorCode::unterminated_string, 2, 1, 3);
  diagnostic("\"{a", ErrorCode::unterminated_interpolation, 3, 1, 4);
  diagnostic("\"{/*", ErrorCode::unterminated_comment, 2, 1, 3);
  // Whole-source UTF-8 validation intentionally precedes earlier lexical errors.
  diagnostic("_\xff", ErrorCode::invalid_utf8, 1, 1, 2);
  std::string nested="\"";
  for (int i=0;i<2000;++i) nested += "{\"";
  nested += 'x';
  for (int i=0;i<2000;++i) nested += "\"}";
  nested += '"';
  tokens(nested, {{TokenKind::string_literal,nested}});
}
void deterministic_streams() {
  constexpr std::array<Expected, 14> corpus{{
    {TokenKind::keyword,"fn"},{TokenKind::keyword,"let"},{TokenKind::identifier,"alpha_1"},
    {TokenKind::integer,"0x2au8"},{TokenKind::integer,"9"},{TokenKind::floating,"1.5f32"},
    {TokenKind::string_literal,"\"{a}\""},{TokenKind::op,"<<="},{TokenKind::op,".."},
    {TokenKind::op,"/"},{TokenKind::punctuation,"."},{TokenKind::punctuation,"{"},
    {TokenKind::punctuation,"}"},{TokenKind::doc_comment,"///doc"}}};
  std::mt19937 random(0x42a17U);
  for (int iteration=0; iteration<1000; ++iteration) {
    std::string input; std::vector<Expected> expected;
    for (int n=0;n<40;++n) {
      const auto entry=corpus[random()%corpus.size()];
      input.append(entry.second); input += (entry.first==TokenKind::doc_comment ? "\r\n" : " ");
      expected.push_back(entry);
    }
    tokens(input, expected);
  }
}
}
int main() { examples(); deterministic_streams(); return failures ? 1 : 0; }
