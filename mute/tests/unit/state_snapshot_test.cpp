#include "poko/mute/state_snapshot.hpp"
#include "poko/mute/program.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <variant>
#include <vector>
using namespace poko::mute;
namespace {
void checksum(std::vector<std::uint8_t>& b) {
 const auto h=xxhash64(std::span(b).first(b.size()-8));
 for (unsigned i=0;i<8;++i) b[b.size()-8+i]=static_cast<std::uint8_t>(h>>(8*i));
}
}
int main() {
 int failures=0;auto check=[&](bool ok,const char* message){if(!ok){std::cerr<<message<<'\n';++failures;}};
 const std::string source="@state var count:i32=0;@state var score:i32=-2;fn tick()->i32{count=count+1;score=score+count;return score;}tick()";
 ProgramState state;check(std::holds_alternative<NumericValue>(run_stateful_program(source,state)),"initialize state");
 const auto saved=save_state_snapshot(source,state);check(std::holds_alternative<std::vector<std::uint8_t>>(saved),"save");
 if (!std::holds_alternative<std::vector<std::uint8_t>>(saved)) return 1;
 const auto bytes=std::get<std::vector<std::uint8_t>>(saved);
 const auto restored=load_state_snapshot(source,bytes);
 check(std::holds_alternative<ProgramState>(restored) && std::get<ProgramState>(restored)==state,"roundtrip");
 // Binary disk round-trip; file ownership/atomic replacement are host responsibilities.
 std::unique_ptr<std::FILE,decltype(&std::fclose)> file(std::tmpfile(),&std::fclose);
 if(!file) check(false,"temporary file creation");
 else {
  bool disk_ok=std::fwrite(bytes.data(),1,bytes.size(),file.get())==bytes.size() && std::fflush(file.get())==0 && std::fseek(file.get(),0,SEEK_SET)==0;
  std::vector<std::uint8_t> readback(bytes.size());
  disk_ok=disk_ok && std::fread(readback.data(),1,readback.size(),file.get())==readback.size();
  if(disk_ok){auto loaded=load_state_snapshot(source,readback);disk_ok=std::holds_alternative<ProgramState>(loaded) && std::get<ProgramState>(loaded)==state;}
  check(disk_ok,"binary file save/load roundtrip");
 }
 const auto repeat=save_state_snapshot(source,state);
 check(std::holds_alternative<std::vector<std::uint8_t>>(repeat) && std::get<std::vector<std::uint8_t>>(repeat)==bytes,"canonical deterministic output");
 // Python struct + xxhash 3.5.0 independent v1 golden.
 const std::string golden_source="@state var x:i32=0;fn f()->i32{return x;}f()";
 const auto golden=std::get<std::vector<std::uint8_t>>(save_state_snapshot(golden_source,ProgramState{true,{{"x",-42}}}));
 const std::string golden_hex="4d555453010000002c00000001004073746174652076617220783a6933323d303b666e206628292d3e6933327b72657475726e20783b7d662829d6ffffffd1db234bd551ce15";
 constexpr char digits[]="0123456789abcdef";std::string hex;
 for(auto byte:golden){hex+=digits[byte>>4];hex+=digits[byte&15];}
 check(hex==golden_hex,"independent wire golden");
 check(bytes.size()==14+source.size()+8+8 && bytes[0]=='M' && bytes[4]==1 && bytes[12]==2,"header layout");
 check(bytes[14+source.size()]==1 && bytes[14+source.size()+4]==0xff && bytes[14+source.size()+7]==0xff,"signed little endian");
 ProgramState extreme{true,{{"count",std::numeric_limits<std::int32_t>::min()},{"score",std::numeric_limits<std::int32_t>::max()}}};
 const auto extreme_bytes=std::get<std::vector<std::uint8_t>>(save_state_snapshot(source,extreme));
 check(std::get<ProgramState>(load_state_snapshot(source,extreme_bytes))==extreme,"signed limits");
 check(std::holds_alternative<SnapshotError>(save_state_snapshot(source,ProgramState{})),"uninitialized denied");
 check(std::holds_alternative<SnapshotError>(save_state_snapshot(source,ProgramState{true,{{"score",1},{"count",2}}})),"wrong schema denied");
 check(std::holds_alternative<SnapshotError>(save_state_snapshot("invalid",state)),"invalid program denied");
 check(std::get<SnapshotError>(load_state_snapshot(source+" ",bytes)).code==SnapshotErrorCode::source_mismatch,"exact program identity required");
 check(std::get<SnapshotError>(save_state_snapshot(std::string(max_snapshot_source_bytes+1,'x'),state)).code==SnapshotErrorCode::source_too_large,"source limit");
 for(std::size_t i=0;i<bytes.size();++i) {
   check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,std::span(bytes).first(i))),"truncation rejected");
   auto altered=bytes;altered[i]^=1;
   check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,altered)),"single-bit damage rejected");
 }
 auto trailing=bytes;trailing.push_back(0);check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,trailing)),"trailing bytes rejected");
 auto wrong_count=bytes;wrong_count[12]=1;wrong_count.erase(wrong_count.end()-12,wrong_count.end()-8);checksum(wrong_count);
 check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,wrong_count)),"rechecks schema despite valid checksum");
 auto forged=bytes;forged[14+source.size()]=42;checksum(forged);
 auto forged_state=load_state_snapshot(source,forged);
 check(std::holds_alternative<ProgramState>(forged_state) && std::get<ProgramState>(forged_state).fields[0].value==42,"checksum is not authentication");
 auto reserved=bytes;reserved[6]=1;checksum(reserved);check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,reserved)),"reserved bits rejected");
 auto version=bytes;version[4]=2;checksum(version);check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,version)),"unknown version rejected");
 auto huge=bytes;huge[8]=0xff;huge[9]=0xff;huge[10]=0xff;huge[11]=0xff;check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,huge)),"source length bound");
 auto too_many=bytes;too_many[12]=1;too_many[13]=1;check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,too_many)),"field count bound");
 std::string exact=source+" //";exact.append(max_snapshot_source_bytes-exact.size(),'a');
 const auto exact_save=save_state_snapshot(exact,state);
 check(std::holds_alternative<std::vector<std::uint8_t>>(exact_save) && std::holds_alternative<ProgramState>(load_state_snapshot(exact,std::get<std::vector<std::uint8_t>>(exact_save))),"maximum source size");
 const std::string empty_source="fn f()->i32{return 0;}f()"; ProgramState empty{true,{}};
 const auto empty_bytes=std::get<std::vector<std::uint8_t>>(save_state_snapshot(empty_source,empty));
 check(std::get<ProgramState>(load_state_snapshot(empty_source,empty_bytes))==empty,"zero fields");
 const std::string unicode="@state var café:i32=0;fn f()->i32{return café;}f()";
 ProgramState u{true,{{"café",-1}}};const auto ub=std::get<std::vector<std::uint8_t>>(save_state_snapshot(unicode,u));
 check(std::get<ProgramState>(load_state_snapshot(unicode,ub))==u,"unicode field");
 std::string many;ProgramState full{true,{}};
 for(int i=0;i<256;++i){const auto name="x"+std::to_string(i);many+="@state var "+name+":i32=0;";full.fields.push_back({name,i});}
 many+="fn f()->i32{return 0;}f()";auto full_bytes=std::get<std::vector<std::uint8_t>>(save_state_snapshot(many,full));
 check(std::get<ProgramState>(load_state_snapshot(many,full_bytes))==full,"256 fields roundtrip");
 ProgramState continuous,periodic;
 for(int i=0;i<10000;++i){
  auto a=run_stateful_program(source,continuous),b=run_stateful_program(source,periodic);
  if(!std::holds_alternative<NumericValue>(a)||!std::holds_alternative<NumericValue>(b)||continuous!=periodic){check(false,"replay tick mismatch");break;}
  if(i%101==0){auto s=save_state_snapshot(source,periodic);if(!std::holds_alternative<std::vector<std::uint8_t>>(s)){check(false,"replay save");break;}auto l=load_state_snapshot(source,std::get<std::vector<std::uint8_t>>(s));if(!std::holds_alternative<ProgramState>(l)){check(false,"replay load");break;}periodic=std::get<ProgramState>(std::move(l));check(hash_state(periodic)==hash_state(continuous),"replay hash");}
 }
 std::mt19937 rng(12345);
 for(int i=0;i<5000;++i){std::vector<std::uint8_t> fuzz(rng()%512);for(auto& v:fuzz)v=static_cast<std::uint8_t>(rng());check(std::holds_alternative<SnapshotError>(load_state_snapshot(source,fuzz)),"random data rejected");}
 return failures?1:0;
}
