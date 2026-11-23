#include "poko/mute/semantic.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
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
  std::ifstream file(argv[1],std::ios::binary); if (!file) return 2;
  const std::string source((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
  auto parsed=parse_declarations(source);
  if (auto* error=std::get_if<Diagnostic>(&parsed)) {
    std::cout << "lex " << name(error->code) << ' ' << error->position.line << ':' << error->position.column << '\n'; return 1;
  }
  if (auto* error=std::get_if<ParseDiagnostic>(&parsed)) {
    std::cout << "parse " << name(error->code) << ' ' << error->position.line << ':' << error->position.column << '\n'; return 1;
  }
  if (auto* error=std::get_if<StatementDiagnostic>(&parsed)) {
    std::cout << "parse " << name(error->code) << ' ' << error->position.line << ':' << error->position.column << '\n'; return 1;
  }
  if (auto* error=std::get_if<DeclarationDiagnostic>(&parsed)) {
    std::cout << "parse " << name(error->code) << ' ' << error->position.line << ':' << error->position.column << '\n'; return 1;
  }
  const auto result=analyze(std::get<DeclarationAst>(parsed));
  std::cout << dump_semantic(result);
  return result.ok() ? 0 : 1;
}
