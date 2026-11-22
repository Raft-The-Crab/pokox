#include "poko/mute/pkb_draft.hpp"
#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
int main(int argc,char** argv) {
 if(argc!=2 || std::string_view(argv[1])=="--help") {
  std::cerr<<"Usage: poko_mute_pkb_schema_draft <mute-source> > draft.cbor\n"
             "UNSIGNED PREVIEW ONLY: not a .pkB, not an authority policy or publishable contract.\n";
  return argc==2?0:2;
 }
 std::ifstream in(argv[1],std::ios::binary);if(!in){std::cerr<<"Cannot open source.\n";return 1;}
 std::array<char,4096> chunk{};std::string source;
 while(in){in.read(chunk.data(),static_cast<std::streamsize>(chunk.size()));const auto count=static_cast<std::size_t>(in.gcount());
  if(source.size()+count>65'536){std::cerr<<"Source exceeds 65536 bytes.\n";return 1;}source.append(chunk.data(),count);}
 if(in.bad()){std::cerr<<"Cannot read source.\n";return 1;}
 auto result=poko::mute::make_pkb_schema_draft(source);
 if(const auto* e=std::get_if<poko::mute::ProgramDiagnostic>(&result)){
  std::cerr<<e->stage<<" error "<<e->code<<" at "<<e->position.line<<":"<<e->position.column<<"\n";return 1;
 }
#ifdef _WIN32
 if(_setmode(_fileno(stdout),_O_BINARY)==-1){std::cerr<<"Cannot set binary output.\n";return 1;}
#endif
 std::cerr<<"UNSIGNED SCHEMA PREVIEW; not a .pkB and not suitable for authority.\n";
 const auto& bytes=std::get<std::vector<std::uint8_t>>(result);
 std::cout.write(reinterpret_cast<const char*>(bytes.data()),static_cast<std::streamsize>(bytes.size()));
 if(!std::cout){std::cerr<<"Cannot write draft.\n";return 1;}
 return 0;
}
