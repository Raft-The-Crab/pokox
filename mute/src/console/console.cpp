#include "poko/mute/console.hpp"
#include "poko/mute/evaluator.hpp"
#include "poko/mute/program.hpp"
#include <algorithm>
#include <array>
#include <charconv>
#include <limits>
#include <string>
#include <system_error>
#include <type_traits>
#include <variant>
#include <vector>

namespace poko::mute {
namespace {
std::string diagnostic(std::string_view stage, std::string_view code, Position position) {
  return std::string(stage) + " error " + std::string(code) + " at " +
         std::to_string(position.line) + ":" + std::to_string(position.column);
}
Position rebased(Position position, Position base) {
  if (position.line == 1) position.column += base.column - 1;
  position.line += base.line - 1;
  position.byte += base.byte;
  return position;
}
template<class T> std::string number(T value) {
  std::array<char,128> buffer{};
  std::to_chars_result converted;
  if constexpr (std::is_floating_point_v<T>)
    converted=std::to_chars(buffer.data(),buffer.data()+buffer.size(),value,
                            std::chars_format::general,std::numeric_limits<T>::max_digits10);
  else converted=std::to_chars(buffer.data(),buffer.data()+buffer.size(),value);
  if (converted.ec!=std::errc{}) return "<format error>";
  return std::string(buffer.data(),converted.ptr);
}
struct NumericText { std::string value; std::string type; };
using NumericResult = std::variant<NumericText, std::string>;
NumericResult numeric(std::string_view source, Position base) {
  auto parsed=parse_arithmetic(source,LexOptions{4095});
  if (const auto* e=std::get_if<Diagnostic>(&parsed)) return diagnostic("lex",name(e->code),rebased(e->position,base));
  if (const auto* e=std::get_if<ParseDiagnostic>(&parsed)) return diagnostic("parse",name(e->code),rebased(e->position,base));
  auto result=evaluate_arithmetic(std::get<Ast>(parsed),EvalOptions{4095});
  if (const auto* e=std::get_if<EvalDiagnostic>(&result)) return diagnostic("eval",name(e->code),rebased(e->position,base));
  const auto& value=std::get<NumericValue>(result);
  return NumericText{std::visit([](auto v){ return number(v); },value.data),std::string(name(value.type))};
}
std::string_view spelling(std::string_view source,const Token& token) {
  return source.substr(token.begin.byte,token.end_byte-token.begin.byte);
}
// The lexer has already validated UTF-8, termination and supported escapes.
// Interpolation is deliberately rejected: it is not evaluated in this baseline.
std::variant<std::string, bool> decode_string(std::string_view raw) {
  std::string result; result.reserve(raw.size()-2);
  for (std::size_t i=1;i+1<raw.size();++i) {
    const char c=raw[i];
    if (c=='{') return false;
    if (c!='\\') { result.push_back(c); continue; }
    const char escaped=raw[++i];
    switch (escaped) {
      case 'n': result.push_back('\n'); break;
      case 'r': result.push_back('\r'); break;
      case 't': result.push_back('\t'); break;
      case '0': result.push_back('\0'); break;
      case '\\': case '"': case '{': case '}': result.push_back(escaped); break;
      default: return false;
    }
  }
  return result;
}
} // namespace
std::string evaluate_console(std::string_view expression) {
  auto result=numeric(expression,{0,1,1});
  if (const auto* e=std::get_if<std::string>(&result)) return *e;
  const auto& value=std::get<NumericText>(result);
  return value.type + ": " + value.value;
}
static std::string execute_console_impl(std::string_view source, PrintHost host, ProgramState* state) {
  auto result=lex(source,LexOptions{4095});
  if (const auto* e=std::get_if<Diagnostic>(&result)) return diagnostic("lex",name(e->code),e->position);
  const auto& tokens=std::get<std::vector<Token>>(result);
  if (!tokens.empty() && (spelling(source,tokens[0])=="fn" || spelling(source,tokens[0])=="@")) {
    const bool state_source=spelling(source,tokens[0])=="@";
    auto program=(state_source && state) ? run_stateful_program(source,*state) : run_program(source);
    if (const auto* e=std::get_if<ProgramDiagnostic>(&program)) return diagnostic(e->stage,e->code,e->position);
    const auto& value=std::get<NumericValue>(program);
    return std::string(name(value.type))+": "+std::visit([](auto v){ return number(v); },value.data);
  }
  if (tokens.size()<3 || tokens[0].kind!=TokenKind::identifier || spelling(source,tokens[0])!="print" ||
      spelling(source,tokens[1])!="(") return evaluate_console(source);
  std::size_t close=0, depth=0;
  for (std::size_t i=1;i+1<tokens.size();++i) {
    const auto text=spelling(source,tokens[i]);
    if (text=="(") ++depth;
    else if (text==")") {
      if (--depth==0) { close=i; break; }
    }
  }
  if (close==0 || close+2!=tokens.size()) return diagnostic("host","invalid_print_call",tokens[0].begin);
  std::string payload;
  if (close==3 && tokens[2].kind==TokenKind::string_literal) {
    auto decoded=decode_string(spelling(source,tokens[2]));
    if (const auto* text=std::get_if<std::string>(&decoded)) payload=*text;
    else return diagnostic("host","unsupported_interpolation",tokens[2].begin);
  } else {
    const auto start=tokens[1].end_byte, end=tokens[close].begin.byte;
    Position base=tokens[1].begin; ++base.byte; ++base.column;
    auto value=numeric(source.substr(start,end-start),base);
    if (const auto* error=std::get_if<std::string>(&value)) return *error;
    payload=std::get<NumericText>(std::move(value)).value;
  }
  if (!host.write) return diagnostic("host","print_unavailable",tokens[0].begin);
  if (!host.write(payload,host.context)) return diagnostic("host","print_failed",tokens[0].begin);
  return "unit";
}
std::string execute_console(std::string_view source,PrintHost host) {return execute_console_impl(source,host,nullptr);}
std::string execute_console_stateful(std::string_view source,ProgramState& state,PrintHost host) {return execute_console_impl(source,host,&state);}
bool console_input_full(std::span<const char> buffer) noexcept {
  if (buffer.empty()) return true;
  const auto end=std::find(buffer.begin(),buffer.end(),'\0');
  return end==buffer.end() || static_cast<std::size_t>(end-buffer.begin())==buffer.size()-1;
}
namespace {
// Decode the UTF-8 sequence starting at text[i]; returns the code point and
// advances i past it, or returns -1 (leaving i unchanged) on invalid input.
std::int32_t decode_utf8(std::string_view text,std::size_t& i) noexcept {
  const auto c=static_cast<unsigned char>(text[i]);
  if (c<0x80) return c;
  std::uint32_t cp; unsigned need;
  if ((c&0xe0)==0xc0) { cp=c&0x1f; need=1; if (cp<2) return -1; }
  else if ((c&0xf0)==0xe0) { cp=c&0x0f; need=2; }
  else if ((c&0xf8)==0xf0) { cp=c&0x07; need=3; if (cp>4) return -1; }
  else return -1;
  if (i+need>=text.size()) return -1;
  for (unsigned k=1;k<=need;++k) {
    const auto t=static_cast<unsigned char>(text[i+k]);
    if ((t&0xc0)!=0x80) return -1;
    cp=(cp<<6)|(t&0x3f);
  }
  // Reject overlong forms, surrogates and out-of-range values.
  const std::uint32_t min_value=need==1?0x80:need==2?0x800:0x10000;
  if (cp<min_value || (cp>=0xd800&&cp<=0xdfff) || cp>0x10ffff) return -1;
  i+=need+1; return static_cast<std::int32_t>(cp);
}
// Unicode category Cf (format) controls: bidi overrides/embeddings/isolates,
// zero-width characters, word joiner, tag characters and similar. These can
// visually reorder or hide log text, so they are escaped like ASCII controls.
bool is_format_control(std::uint32_t cp) noexcept {
  return cp==0x00ad || (cp>=0x0600&&cp<=0x0605) || cp==0x061c || cp==0x06dd ||
    cp==0x070f || (cp>=0x0890&&cp<=0x0891) || cp==0x08e2 || cp==0x180e ||
    (cp>=0x200b&&cp<=0x200f) || (cp>=0x202a&&cp<=0x202e) ||
    (cp>=0x2060&&cp<=0x2064) || (cp>=0x2066&&cp<=0x206f) || cp==0xfeff ||
    (cp>=0xfff9&&cp<=0xfffb) || cp==0x110bd || cp==0x110cd ||
    (cp>=0x13430&&cp<=0x1343f) || (cp>=0x1bca0&&cp<=0x1bca3) ||
    (cp>=0x1d173&&cp<=0x1d17a) || cp==0xe0001 || (cp>=0xe0020&&cp<=0xe007f);
}
}
bool ConsoleLog::append(std::string_view text) {
  if (text.size()>max_input_bytes) return false;
  constexpr char hex[]="0123456789abcdef";
  std::string line; line.reserve(text.size());
  auto escape_codepoint=[&](std::uint32_t cp) {
    if (cp<=0xffff) {
      line+="\\u";
      for (int shift=12;shift>=0;shift-=4) line.push_back(hex[(cp>>shift)&15]);
    } else {
      line+="\\U";
      for (int shift=28;shift>=0;shift-=4) line.push_back(hex[(cp>>shift)&15]);
    }
  };
  for (std::size_t i=0;i<text.size();) {
    const unsigned char c=static_cast<unsigned char>(text[i]);
    if (c=='\\') { line+="\\\\"; ++i; continue; }
    if (c=='\n') { line+="\\n"; ++i; continue; }
    if (c=='\r') { line+="\\r"; ++i; continue; }
    if (c=='\t') { line+="\\t"; ++i; continue; }
    if (c=='\0') { line+="\\0"; ++i; continue; }
    if (c<0x20 || c==0x7f) { line+="\\x"; line.push_back(hex[c>>4]); line.push_back(hex[c&15]); ++i; continue; }
    if (c<0x80) { line.push_back(static_cast<char>(c)); ++i; continue; }
    const auto at=i;
    const auto cp=decode_utf8(text,i);
    if (cp<0) { line+="\\x"; line.push_back(hex[c>>4]); line.push_back(hex[c&15]); ++i; continue; }
    if (is_format_control(static_cast<std::uint32_t>(cp))) escape_codepoint(static_cast<std::uint32_t>(cp));
    else line.append(text.substr(at,i-at));
  }
  const auto length=line.size();
  entries_.push_back(std::move(line)); // Strong guarantee if allocation fails.
  bytes_+=length;
  while (entries_.size()>max_entries || bytes_>max_bytes) {
    bytes_-=entries_.front().size(); entries_.pop_front();
  }
  return true;
}
void ConsoleLog::clear() noexcept { entries_.clear(); bytes_=0; }
} // namespace poko::mute
