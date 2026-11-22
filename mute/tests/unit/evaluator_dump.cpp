#include "poko/mute/evaluator.hpp"
#include <bit>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
#ifdef _WIN32
#include <cstdio>
#include <fcntl.h>
#include <io.h>
#endif
using namespace poko::mute;
int main(int argc,char** argv) {
  if (argc!=2) return 2;
#ifdef _WIN32
  if (_setmode(_fileno(stdout),_O_BINARY)==-1) return 2;
#endif
  std::cout.imbue(std::locale::classic());
  std::ifstream file(argv[1],std::ios::binary); if (!file) return 2;
  const std::string source((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
  auto parsed=parse_arithmetic(source);
  if (auto e=std::get_if<Diagnostic>(&parsed)) { std::cout << "lex " << name(e->code) << ' ' << e->position.line << ':' << e->position.column << '\n'; return 1; }
  if (auto e=std::get_if<ParseDiagnostic>(&parsed)) { std::cout << "parse " << name(e->code) << ' ' << e->position.line << ':' << e->position.column << '\n'; return 1; }
  auto result=evaluate_arithmetic(std::get<Ast>(parsed));
  if (auto e=std::get_if<EvalDiagnostic>(&result)) { std::cout << "eval " << name(e->code) << ' ' << e->position.line << ':' << e->position.column << '\n'; return 1; }
  const auto& value=std::get<NumericValue>(result);
  std::cout << "value " << name(value.type) << ' ';
  if (auto i=std::get_if<std::int64_t>(&value.data)) std::cout << *i;
  else if (auto u=std::get_if<std::uint64_t>(&value.data)) std::cout << *u;
  else if (auto f=std::get_if<float>(&value.data)) std::cout << "0x" << std::hex << std::setfill('0') << std::setw(8) << std::bit_cast<std::uint32_t>(*f);
  else std::cout << "0x" << std::hex << std::setfill('0') << std::setw(16) << std::bit_cast<std::uint64_t>(std::get<double>(value.data));
  std::cout << '\n';
}
