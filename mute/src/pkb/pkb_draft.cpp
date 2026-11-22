#include "poko/mute/pkb_draft.hpp"
#include <cstdint>
#include <string_view>
namespace poko::mute {
namespace {
void head(std::vector<std::uint8_t>& out,std::uint8_t major,std::size_t n) {
  if(n<24){out.push_back(static_cast<std::uint8_t>((major<<5)|n));return;}
  if(n<=255){out.push_back(static_cast<std::uint8_t>((major<<5)|24));out.push_back(static_cast<std::uint8_t>(n));return;}
  if(n<=65535){out.push_back(static_cast<std::uint8_t>((major<<5)|25));out.push_back(static_cast<std::uint8_t>(n>>8));out.push_back(static_cast<std::uint8_t>(n));return;}
  out.push_back(static_cast<std::uint8_t>((major<<5)|26));
  for(int shift=24;shift>=0;shift-=8)out.push_back(static_cast<std::uint8_t>(n>>shift));
}
void text(std::vector<std::uint8_t>& out,std::string_view s) {head(out,3,s.size());out.insert(out.end(),s.begin(),s.end());}
}
ProgramBytecodeResult make_pkb_schema_draft(std::string_view source) {
 auto schema=inspect_program_state_schema(source);
 if(const auto* error=std::get_if<ProgramDiagnostic>(&schema))return *error;
 const auto& names=std::get<std::vector<std::string>>(schema);
 std::vector<std::uint8_t> out;
 // RFC 8949 deterministic map ordering: encoded key length then bytewise value.
 head(out,5,4);text(out,"kind");text(out,"poko.pkb.schema-draft");
 text(out,"draft");out.push_back(0xf5);
 text(out,"fields");head(out,4,names.size());
 for(const auto& name:names){head(out,5,2);text(out,"name");text(out,name);text(out,"type");text(out,"i32");}
 text(out,"version");head(out,0,1);
 return out;
}
} // namespace poko::mute
