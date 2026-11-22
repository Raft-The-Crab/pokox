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
bool ConsoleLog::append(std::string_view text) {
  if (text.size()>max_input_bytes) return false;
  constexpr char hex[]="0123456789abcdef";
  std::string line; line.reserve(text.size());
  for (const unsigned char c:text) {
    switch (c) {
      case '\\': line+="\\\\"; break;
      case '\n': line+="\\n"; break;
      case '\r': line+="\\r"; break;
      case '\t': line+="\\t"; break;
      case '\0': line+="\\0"; break;
      default:
        if (c<0x20 || c==0x7f) { line+="\\x"; line.push_back(hex[c>>4]); line.push_back(hex[c&15]); }
        else line.push_back(static_cast<char>(c));
    }
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
