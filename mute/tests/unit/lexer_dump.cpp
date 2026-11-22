#include "poko/mute/lexer.hpp"
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
int main(int argc, char** argv) {
  if (argc!=2) return 2;
#ifdef _WIN32
  // Golden output is byte-identical regardless of Windows CRT newline mode.
  if (_setmode(_fileno(stdout), _O_BINARY) == -1) return 2;
#endif
  std::ifstream f(argv[1],std::ios::binary); if (!f) return 2;
  std::string source((std::istreambuf_iterator<char>(f)),std::istreambuf_iterator<char>());
  auto result=lex(source);
  if (auto e=std::get_if<Diagnostic>(&result)) { std::cout << "error " << name(e->code) << ' ' << e->position.line << ':' << e->position.column << '\n'; return 1; }
  constexpr char hex[]="0123456789abcdef";
  for (const auto& token:std::get<std::vector<Token>>(result)) {
    std::cout << token.begin.line << ':' << token.begin.column << ' ' << name(token.kind) << " \"";
    for (auto i=token.begin.byte;i<token.end_byte;++i) {
      auto b=static_cast<unsigned char>(source[i]);
      if (b>=32 && b<=126 && b!='\\' && b!='"') std::cout << static_cast<char>(b);
      else { std::cout << "\\x" << hex[b>>4] << hex[b&15]; }
    }
    std::cout << "\"\n";
  }
}
