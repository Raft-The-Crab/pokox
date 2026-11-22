#include "poko/mute/lexer.hpp"
#include "unicode_xid.hpp"
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok, const char* message) { if (!ok) { std::cerr << message << '\n'; ++failures; } }
void error(std::string_view text, ErrorCode code) {
  auto r=lex(text); auto e=std::get_if<Diagnostic>(&r); check(e && e->code==code,"wrong error");
}
void test_cases() {
  auto r=lex("let caf\xc3\xa9 = 0xffu8\r\n/// hi\n\"value { f(\"x\", {a: 1}) }\"");
  auto p=std::get_if<std::vector<Token>>(&r); check(p!=nullptr,"valid sample failed");
  if (p) {
    const auto& v=*p; check(v.size()==7,"wrong sample token count");
    if (v.size()==7) { check(v[1].kind==TokenKind::identifier && v[1].begin.column==5,"unicode position");
      check(v[3].kind==TokenKind::integer,"hex suffix");
      check(v[4].kind==TokenKind::doc_comment && v[4].begin.line==2,"CRLF or doc");
      check(v[5].kind==TokenKind::string_literal && v[5].begin.line==3,"interpolation"); }
  }
  error("\xef\xbb\xbfxyz",ErrorCode::bom);
  error(std::string("\xc0\x80",2),ErrorCode::invalid_utf8);
  error(std::string("\xed\xa0\x80",3),ErrorCode::invalid_utf8);
  error(std::string("\xf4\x90\x80\x80",4),ErrorCode::invalid_utf8);
  error(std::string("//\xff",3),ErrorCode::invalid_utf8);
  error("0b102",ErrorCode::invalid_number); error("0x",ErrorCode::invalid_number);
  error("123foo",ErrorCode::invalid_number); error("_abc",ErrorCode::unexpected_character);
  error("/* unterminated",ErrorCode::unterminated_comment);
  error("\"bad\\q\"",ErrorCode::invalid_escape);
  error("\"{abc",ErrorCode::unterminated_interpolation);
  error("\"abc",ErrorCode::unterminated_string);
  const std::string oversized(1'048'577,' ');
  auto large=lex(oversized); auto large_error=std::get_if<Diagnostic>(&large);
  check(large_error && large_error->code==ErrorCode::source_too_large && large_error->position.byte==0 && large_error->position.line==1 && large_error->position.column==1,"default source bound");
  check(std::holds_alternative<std::vector<Token>>(lex(oversized,LexOptions{oversized.size()})),"explicit larger source bound");
  check(std::holds_alternative<std::vector<Token>>(lex("abc",LexOptions{3})),"exact source bound");
  large=lex(std::string("\xffx",2),LexOptions{1}); large_error=std::get_if<Diagnostic>(&large);
  check(large_error && large_error->code==ErrorCode::source_too_large,"size rejection must precede UTF-8 validation");
  large=lex("a",LexOptions{0}); large_error=std::get_if<Diagnostic>(&large);
  check(large_error && large_error->code==ErrorCode::source_too_large,"zero source bound");
  auto range=lex("1..2 3.14f32 1.");
  auto t=std::get_if<std::vector<Token>>(&range);
  check(t && t->size()==7 && (*t)[0].kind==TokenKind::integer && (*t)[1].kind==TokenKind::op && (*t)[3].kind==TokenKind::floating && (*t)[5].kind==TokenKind::punctuation,"range and float handling");
  auto cr=lex("a\r\nb\rc\nd");
  t=std::get_if<std::vector<Token>>(&cr);
  check(t && t->size()==5 && (*t)[3].begin.line==4 && (*t)[3].begin.column==1,"newline positions");
  // Deterministic malformed-byte and arbitrary-ASCII exercise of all cursor paths.
  std::mt19937 rng(0x5eed); for (int i=0;i<20000;++i) {
    std::string s; auto n=rng()%100; for (unsigned j=0;j<n;++j) s.push_back(static_cast<char>(rng()%(i%2 ? 128 : 256)));
    auto result=lex(s); if (auto tokens=std::get_if<std::vector<Token>>(&result)) {
      std::size_t previous=0;
      for (const auto& token:*tokens) { check(token.begin.byte>=previous && token.end_byte>=token.begin.byte && token.end_byte<=s.size(),"token offsets invalid"); previous=token.end_byte; }
      check(!tokens->empty() && tokens->back().kind==TokenKind::end && tokens->back().end_byte==s.size(),"EOF invalid");
    } else check(std::get<Diagnostic>(result).position.byte<=s.size(),"diagnostic out of range");
  }
}
void unicode_conformance(const char* path) {
  std::ifstream file(path); check(bool(file),"cannot open unicode data"); if (!file) return;
  std::vector<bool> starts(0x110000), continues(0x110000); std::string line;
  while (std::getline(file,line)) {
    auto comment=line.find('#'); if (comment!=std::string::npos) line.resize(comment);
    auto sep=line.find(';'); if (sep==std::string::npos) continue;
    auto prop=line.substr(sep+1); auto a=prop.find_first_not_of(" \t\r"); if (a==std::string::npos) continue;
    auto b=prop.find_last_not_of(" \t\r"); prop=prop.substr(a,b-a+1);
    auto* flags=prop=="XID_Start" ? &starts : prop=="XID_Continue" ? &continues : nullptr;
    if (!flags) continue;
    auto range=line.substr(0,sep); auto dots=range.find("..");
    auto first=std::stoul(range.substr(0,dots),nullptr,16);
    auto last=dots==std::string::npos ? first : std::stoul(range.substr(dots+2),nullptr,16);
    for (auto i=first;i<=last;++i) (*flags)[i]=true;
  }
  for (char32_t i=0;i<0x110000;++i) {
    if (poko::mute::detail::contains(poko::mute::detail::XID_Start,i)!=starts[i] || poko::mute::detail::contains(poko::mute::detail::XID_Continue,i)!=continues[i]) { check(false,"Unicode table mismatch"); break; }
  }
}
}
int main(int argc,char** argv) { if (argc!=2) return 2; test_cases(); unicode_conformance(argv[1]); return failures ? 1 : 0; }
