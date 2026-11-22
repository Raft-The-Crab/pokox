#include "poko/mute/program.hpp"
#include "poko/mute/pkb_draft.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace poko::mute;
int main() {
 int failures=0;auto check=[&](bool ok,const char* msg){if(!ok){std::cerr<<msg<<'\n';++failures;}};
 // Independently generated with xxhash 3.5.0; both seeds exercise all length paths.
 struct Vector {std::size_t length;std::uint64_t zero,seed;};
 constexpr std::array vectors{
  Vector{0,0xef46db3751d8e999ULL,0x30b93d611716104aULL},Vector{1,0xf592c0c7639c4cb6ULL,0x545abe35205f5a03ULL},
  Vector{3,0x22c08528601d4f27ULL,0x477879ffb8ff9b6aULL},Vector{4,0xfb1e5cf2f1ae4d95ULL,0x7ced84098687b446ULL},
  Vector{7,0x5613ac510496c04eULL,0xdf8c1963fc5e6575ULL},Vector{8,0x57cb2b7521f3e21aULL,0x8081dc12dd5495caULL},
  Vector{15,0x90a9714eb00e8d29ULL,0x1521a7f7a25f2682ULL},Vector{16,0xc6843cef99721174ULL,0xc577cc4938f6c5f8ULL},
  Vector{31,0xe4a0e629e519a4aeULL,0x64d5348c70897e2aULL},Vector{32,0xcc6b8aaada790b2dULL,0x859adddf0feabc85ULL},
  Vector{33,0x35ec49850475a832ULL,0x1d67c7ed4009c4f9ULL},Vector{63,0xbf9f0ba3cf95b28aULL,0x9dbd738ef4a30d54ULL},
  Vector{64,0x155ccce4bf32befcULL,0x3579a5f955c09b52ULL},Vector{65,0xda5ee441a595cfb8ULL,0x7eac391202a441e4ULL},
  Vector{255,0x178ea4a7d2319abeULL,0x1f8348d2e8d0e433ULL},Vector{256,0x43c92f09cb3e28cfULL,0x65b0eddac517ec9fULL},
  Vector{1024,0x3c8b642b9e1d662fULL,0x60f284345693de68ULL}};
 std::array<std::uint8_t,1024> input{};for(std::size_t i=0;i<input.size();++i)input[i]=static_cast<std::uint8_t>(i*37+11);
 for(const auto v:vectors){const auto data=std::span(input).first(v.length);check(xxhash64(data)==v.zero,"xxhash zero-seed vector");check(xxhash64(data,0x12345678)==v.seed,"xxhash seeded vector");}
 ProgramState golden{true,{{"a",1},{"b",-2},{"c",3}}};
 check(std::get<std::uint64_t>(hash_state(golden))==0xa4222fe2f3905eb7ULL,"state little-endian golden");
 check(hash_state(ProgramState{true,{{"x",1},{"y",2}}})==hash_state(ProgramState{true,{{"other",1},{"names",2}}}),"names not in state hash");
 check(hash_state(ProgramState{true,{{"x",1},{"y",2}}})!=hash_state(ProgramState{true,{{"y",2},{"x",1}}}),"declaration order affects state hash");
 check(std::get<StateError>(hash_state(ProgramState{}))==StateError::uninitialized,"uninitialized hash");
 check(std::get<StateError>(hash_state(ProgramState{true,{{"a",1},{"a",2}}}))==StateError::invalid_state,"duplicate hash schema");
 check(std::get<StateError>(hash_state(ProgramState{true,{{"",1}}}))==StateError::invalid_state,"empty state name");
 check(std::get<std::uint64_t>(hash_state(ProgramState{true,{}}))==0xef46db3751d8e999ULL,"empty state hash");
 constexpr std::string_view source="@state var count:i32=0; @state var score:i32=-2; fn tick()->i32 {count=count+1; score=score+count; return score;} tick()";
 const auto wire=compile_program_bytecode(source);check(std::holds_alternative<std::vector<std::uint8_t>>(wire),"compile state snapshot");
 ProgramState first,second,encoded;
 if(const auto* bytes=std::get_if<std::vector<std::uint8_t>>(&wire)){
  for(int i=1;i<=10000;++i){
   const auto a=run_stateful_program(source,first), b=run_stateful_program(source,second), c=run_stateful_program_bytecode(*bytes,encoded);
   if(!std::holds_alternative<NumericValue>(a) || !std::holds_alternative<NumericValue>(b) || !std::holds_alternative<NumericValue>(c) || first!=second || first!=encoded || hash_state(first)!=hash_state(second) || hash_state(first)!=hash_state(encoded)) {std::cerr<<"deterministic state tick "<<i<<'\n';++failures;break;}
   if(first.fields[0].value!=i || first.fields[1].value!=i*(i+1)/2-2){std::cerr<<"state result "<<i<<'\n';++failures;break;}
  }
 }
 const auto prior=first;
 auto trap=run_stateful_program("@state var count:i32=0; @state var score:i32=-2; fn f()->i32 {count=count+1;return 1/0;} f()",first);
 check(std::holds_alternative<ProgramDiagnostic>(trap) && std::get<ProgramDiagnostic>(trap).code=="divide_by_zero" && first==prior,"trapped tick rolls back");
 trap=run_stateful_program(source,first,ProgramOptions{0});check(std::holds_alternative<ProgramDiagnostic>(trap) && first==prior,"budget tick rolls back");
 trap=run_stateful_program("@state var other:i32=0; fn f()->i32{return other;} f()",first);
 check(std::holds_alternative<ProgramDiagnostic>(trap) && std::get<ProgramDiagnostic>(trap).code=="schema_mismatch" && first==prior,"schema mismatch rejected");
 ProgramState virgin;trap=run_stateful_program("@state var x:i32=1;fn f()->i32{x=2;return 1/0;} f()",virgin);check(!virgin.initialized && virgin.fields.empty(),"initial failure rolls back");
 ProgramState invalid{false,{{"x",1}}};trap=run_stateful_program("@state var x:i32=1;fn f()->i32{return x;} f()",invalid);check(std::get<ProgramDiagnostic>(trap).code=="invalid_state","invalid host state rejected");
 auto bad_init=ProgramState{true,{{"x",1}}};trap=run_stateful_program("@state var x:i32=2147483648;fn f()->i32{return x;} f()",bad_init);check(std::holds_alternative<ProgramDiagnostic>(trap) && bad_init.fields[0].value==1,"invalid initializer rejected on every tick");
 ProgramState shadow;auto result=run_stateful_program("@state var x:i32=5;fn f()->i32 {var x=9;x=x+1;return x;} f()",shadow);check(std::holds_alternative<NumericValue>(result) && std::get<std::int64_t>(std::get<NumericValue>(result).data)==10 && shadow.fields[0].value==5,"locals shadow state");
 ProgramState loop;result=run_stateful_program("@state var x:i32=0;fn f(n:i32)->i32 {if n==0{return x;} x=x+1;return f(n-1);} f(5)",loop);check(std::holds_alternative<NumericValue>(result) && loop.fields[0].value==5,"recursive global mutation");
 for(const auto bad:{"@state var x:i32=1; @state var x:i32=2; fn f()->i32{return 0;} f()", "@state var x:i32=1+2; fn f()->i32{return x;} f()", "@state var x:u32=1; fn f()->i32{return 0;} f()"}) check(std::holds_alternative<ProgramDiagnostic>(run_program(bad)),"invalid state declaration rejected");
 std::string wide;for(int i=0;i<256;++i)wide+="@state var x"+std::to_string(i)+":i32=0;";
 const auto full_source=wide+"fn f()->i32{return 0;} f()";ProgramState full;
 check(std::holds_alternative<NumericValue>(run_stateful_program(full_source,full)) && full.fields.size()==256 && std::holds_alternative<std::uint64_t>(hash_state(full)),"maximum state fields");
 wide+="@state var x256:i32=0;fn f()->i32{return 0;} f()";
 check(std::holds_alternative<ProgramDiagnostic>(run_program(wide)),"state field limit");
 // Declaration initializers are validated at compile, execution, and snapshot boundaries.
 for (const auto bad:{"@state var x:i32=2147483648;fn f()->i32{return x;}f()", "@state var x:i32=-2147483649;fn f()->i32{return x;}f()", "@state var x:i32=1u32;fn f()->i32{return x;}f()"}) {
  const auto compiled=compile_program_bytecode(bad);const auto executed=run_program(bad);
  const auto* c=std::get_if<ProgramDiagnostic>(&compiled);const auto* e=std::get_if<ProgramDiagnostic>(&executed);
  check(c && e && c->stage==e->stage && c->code==e->code && c->position.byte==e->position.byte && c->position.line==e->position.line && c->position.column==e->position.column,"invalid initializer compile/run parity");
 }
 const std::string valid_max="@state var x:i32=2147483647;fn f()->i32{return x;}f()";
 const auto valid_wire=compile_program_bytecode(valid_max);
 check(std::holds_alternative<std::vector<std::uint8_t>>(valid_wire),"valid maximum initializer compiles");
 if(const auto* encoded=std::get_if<std::vector<std::uint8_t>>(&valid_wire)) {
  auto forged=*encoded;const auto pos=std::search(forged.begin(),forged.end(),valid_max.begin(),valid_max.end());
  check(pos!=forged.end(),"embedded source found");
  if(pos!=forged.end()) {
   const auto digit=valid_max.find("2147483647")+9;*(pos+static_cast<std::ptrdiff_t>(digit))='8';
   check(std::holds_alternative<ProgramDiagnostic>(run_program_bytecode(forged)),"legacy invalid initializer wire rejected by execution");
   check(std::holds_alternative<ProgramDiagnostic>(disassemble_program_bytecode(forged)),"legacy invalid initializer wire rejected by disassembler");
  }
 }
 check(std::holds_alternative<std::vector<std::uint8_t>>(compile_program_bytecode("@state var x:i32=-2147483648;fn f()->i32{return x;}f()")),"minimum initializer compiles");
 const auto schema=inspect_program_state_schema(source);check(std::holds_alternative<std::vector<std::string>>(schema) && std::get<std::vector<std::string>>(schema)==std::vector<std::string>{"count","score"},"source schema inspection");
 const auto draft=make_pkb_schema_draft(source);
 // cbor2 5.6.5 canonical=True independent golden; unsigned schema preview only.
 const std::string hex="a4646b696e6475706f6b6f2e706b622e736368656d612d6472616674656472616674f5666669656c647382a2646e616d6565636f756e74647479706563693332a2646e616d656573636f72656474797065636933326776657273696f6e01";
 std::string got;constexpr char digits[]="0123456789abcdef";
 if(const auto* bytes=std::get_if<std::vector<std::uint8_t>>(&draft))for(auto b:*bytes){got+=digits[b>>4];got+=digits[b&15];}
 check(got==hex,"independent canonical CBOR schema draft golden");
 const auto again=make_pkb_schema_draft(source);
 check(std::holds_alternative<std::vector<std::uint8_t>>(draft) && std::holds_alternative<std::vector<std::uint8_t>>(again) && std::get<std::vector<std::uint8_t>>(draft)==std::get<std::vector<std::uint8_t>>(again),"schema draft deterministic");
 check(std::holds_alternative<ProgramDiagnostic>(make_pkb_schema_draft("@state var broken:u32=0; fn f()->i32{return 0;} f()")),"invalid schema cannot produce draft");
 return failures?1:0;
}
