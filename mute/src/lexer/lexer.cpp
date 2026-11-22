#include "poko/mute/lexer.hpp"
#include "unicode_xid.hpp"
#include <algorithm>
#include <array>
#include <string_view>
#include <vector>

namespace poko::mute {
namespace {
struct Decoded { char32_t value; std::size_t length; };
Decoded decode(std::string_view s, std::size_t i) {
  const auto b = [&](std::size_t n) { return static_cast<unsigned char>(s[i+n]); };
  const auto a = b(0);
  if (a < 0x80) return {a, 1};
  std::size_t n = 0; char32_t c = 0;
  if (a >= 0xc2 && a <= 0xdf) { n=2; c=a & 0x1f; }
  else if (a >= 0xe0 && a <= 0xef) { n=3; c=a & 0x0f; }
  else if (a >= 0xf0 && a <= 0xf4) { n=4; c=a & 0x07; }
  else return {0,0};
  if (s.size()-i < n) return {0,0};
  for (std::size_t j=1;j<n;++j) {
    if ((b(j)&0xc0)!=0x80) return {0,0};
    c=(c<<6)|(b(j)&0x3f);
  }
  if ((n==3 && c<0x800) || (n==4 && c<0x10000) || (c>=0xd800 && c<=0xdfff) || c>0x10ffff) return {0,0};
  return {c,n};
}
struct Cursor {
  std::string_view s; Position p{0,1,1};
  bool done() const { return p.byte==s.size(); }
  bool starts(std::string_view x) const { return s.substr(p.byte).starts_with(x); }
  char32_t current() const { return decode(s,p.byte).value; }
  void advance() {
    auto d=decode(s,p.byte);
    p.byte+=d.length;
    if (d.value=='\r') {
      if (p.byte<s.size() && s[p.byte]=='\n') ++p.byte;
      ++p.line; p.column=1;
    } else if (d.value=='\n') { ++p.line; p.column=1; }
    else ++p.column;
  }
};
bool digit(char32_t c) { return c>='0' && c<='9'; }
bool digit_for(char32_t c, unsigned base) {
  unsigned v = c>='0' && c<='9' ? static_cast<unsigned>(c-'0') :
               c>='a' && c<='f' ? static_cast<unsigned>(c-'a'+10) :
               c>='A' && c<='F' ? static_cast<unsigned>(c-'A'+10) : 255;
  return v<base;
}
bool is_start(char32_t c) { return detail::contains(detail::XID_Start,c); }
bool is_continue(char32_t c) { return detail::contains(detail::XID_Continue,c); }
bool keyword(std::string_view s) {
  constexpr auto words=std::to_array<std::string_view>({std::string_view{"package"},"version","allow","import","as","struct","enum","let","var","fn","async","await","for","in","if","while","loop","match","guard","else","break","continue","return","true","false","move","pub","spawn","trait","impl"});
  return std::find(words.begin(),words.end(),s)!=words.end();
}
bool suffix(std::string_view s, bool floating) {
  constexpr auto ints=std::to_array<std::string_view>({std::string_view{"i8"},"i16","i32","i64","u8","u16","u32","u64"});
  constexpr auto floats=std::to_array<std::string_view>({std::string_view{"f32"},"f64"});
  if (floating) return std::find(floats.begin(),floats.end(),s)!=floats.end();
  return std::find(ints.begin(),ints.end(),s)!=ints.end();
}
// Scan a complete raw string. Interpolations are balanced, not parsed.
// Stack entries represent string text (0) or an interpolation's brace depth (>0).
std::variant<std::monostate, Diagnostic> string_body(Cursor& c) {
  std::vector<std::size_t> stack{0}; c.advance();
  while (!c.done()) {
    if (stack.back()==0) {
      if (c.current()=='"') { c.advance(); stack.pop_back(); if (stack.empty()) return std::monostate{}; continue; }
      if (c.current()=='\\') {
        const auto at=c.p; c.advance();
        if (c.done() || c.current()>127 || std::string_view("\\\"nrt0{}").find(static_cast<char>(c.current()))==std::string_view::npos) return Diagnostic{ErrorCode::invalid_escape,at};
        c.advance(); continue;
      }
      if (c.current()=='\n' || c.current()=='\r') return Diagnostic{ErrorCode::unterminated_string,c.p};
      if (c.current()=='{') { c.advance(); stack.push_back(1); continue; }
      c.advance();
    } else {
      if (c.starts("//")) { while (!c.done() && c.current()!='\r' && c.current()!='\n') c.advance(); continue; }
      if (c.starts("/*")) {
        const auto at=c.p; c.advance(); c.advance();
        while (!c.done() && !c.starts("*/")) c.advance();
        if (c.done()) return Diagnostic{ErrorCode::unterminated_comment,at};
        c.advance(); c.advance(); continue;
      }
      if (c.current()=='"') { c.advance(); stack.push_back(0); continue; }
      if (c.current()=='{') { ++stack.back(); c.advance(); continue; }
      if (c.current()=='}') { --stack.back(); c.advance(); if (stack.back()==0) stack.pop_back(); continue; }
      c.advance();
    }
  }
  return Diagnostic{stack.back()==0 ? ErrorCode::unterminated_string : ErrorCode::unterminated_interpolation,c.p};
}
} // namespace
Result lex(std::string_view input, LexOptions options) {
  if (input.size() > options.max_source_bytes) return Diagnostic{ErrorCode::source_too_large,{0,1,1}};
  // Validate all bytes, even inside comments and strings, before tokenization.
  Cursor validation{input};
  if (input.starts_with("\xef\xbb\xbf")) return Diagnostic{ErrorCode::bom,validation.p};
  while (!validation.done()) {
    if (decode(input,validation.p.byte).length==0) return Diagnostic{ErrorCode::invalid_utf8,validation.p};
    validation.advance();
  }
  Cursor c{input}; std::vector<Token> out;
  const auto emit=[&](TokenKind k, Position p) { out.push_back({k,p,c.p.byte}); };
  while (!c.done()) {
    const auto at=c.p; const auto ch=c.current();
    if (ch==' ' || ch=='\t' || ch=='\r' || ch=='\n') { c.advance(); continue; }
    if (c.starts("//")) {
      const bool doc=c.starts("///");
      while (!c.done() && c.current()!='\r' && c.current()!='\n') c.advance();
      if (doc) emit(TokenKind::doc_comment,at);
      continue;
    }
    if (c.starts("/*")) {
      c.advance(); c.advance();
      while (!c.done() && !c.starts("*/")) c.advance();
      if (c.done()) return Diagnostic{ErrorCode::unterminated_comment,at};
      c.advance(); c.advance(); continue;
    }
    if (is_start(ch)) {
      c.advance(); while (!c.done() && is_continue(c.current())) c.advance();
      emit(keyword(input.substr(at.byte,c.p.byte-at.byte)) ? TokenKind::keyword : TokenKind::identifier,at); continue;
    }
    if (digit(ch)) {
      unsigned base=10; bool floating=false;
      if (c.starts("0x") || c.starts("0X")) base=16;
      else if (c.starts("0b") || c.starts("0B")) base=2;
      else if (c.starts("0o") || c.starts("0O")) base=8;
      if (base!=10) { c.advance(); c.advance(); }
      const auto digits_begin=c.p.byte;
      while (!c.done() && digit_for(c.current(),base)) c.advance();
      if (c.p.byte==digits_begin) return Diagnostic{ErrorCode::invalid_number,at};
      if (base==10 && !c.done() && c.current()=='.' && c.p.byte+1<input.size() && digit(static_cast<unsigned char>(input[c.p.byte+1]))) {
        floating=true; c.advance(); while (!c.done() && digit(c.current())) c.advance();
      }
      // Decimal exponents and digit separators are deliberately not inferred from the specification.
      const auto suffix_begin=c.p.byte;
      while (!c.done() && is_continue(c.current())) c.advance();
      const auto tail=input.substr(suffix_begin,c.p.byte-suffix_begin);
      if (!tail.empty() && !suffix(tail,floating)) return Diagnostic{ErrorCode::invalid_number,at};
      emit(floating ? TokenKind::floating : TokenKind::integer,at); continue;
    }
    if (ch=='"') {
      auto status=string_body(c);
      if (const auto* error=std::get_if<Diagnostic>(&status)) return *error;
      emit(TokenKind::string_literal,at); continue;
    }
    constexpr auto ops=std::to_array<std::string_view>({std::string_view{"<<="},">>=","..=","==","!=","<=",">=","&&","||","<<",">>","+=","-=","*=","/=","%=","&=","|=","^=","..","->","=>","::","+","-","*","/","%","!","<",">","=","&","|","^","?"});
    bool found=false;
    for (auto op:ops) if (c.starts(op)) { for (std::size_t i=0;i<op.size();++i) c.advance(); emit(TokenKind::op,at); found=true; break; }
    if (found) continue;
    if (ch<128 && std::string_view("()[]{}.,:;@").find(static_cast<char>(ch))!=std::string_view::npos) { c.advance(); emit(TokenKind::punctuation,at); continue; }
    return Diagnostic{ErrorCode::unexpected_character,at};
  }
  out.push_back({TokenKind::end,c.p,c.p.byte}); return out;
}
std::string_view name(TokenKind k) {
  constexpr auto names=std::to_array<std::string_view>({std::string_view{"identifier"},"keyword","integer","floating","string","doc_comment","punctuation","operator","end"});
  return names.at(static_cast<std::size_t>(k));
}
std::string_view name(ErrorCode k) {
  constexpr auto names=std::to_array<std::string_view>({std::string_view{"invalid_utf8"},"bom","unexpected_character","invalid_number","unterminated_string","invalid_escape","unterminated_comment","unterminated_interpolation","source_too_large"});
  return names.at(static_cast<std::size_t>(k));
}
} // namespace poko::mute
