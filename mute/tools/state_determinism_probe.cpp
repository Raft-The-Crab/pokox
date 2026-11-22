// 10,000-tick i32-state probe. Prints each tick's hash, one lowercase hex line.
#include "poko/mute/program.hpp"
#include <iomanip>
#include <iostream>
#include <variant>
int main() {
 using namespace poko::mute;
 constexpr auto source="@state var count:i32=0; @state var sum:i32=0; fn tick()->i32 {count=count+1;sum=sum+count;return sum;} tick()";
 ProgramState state;
 for(int tick=1;tick<=10000;++tick) {
  auto value=run_stateful_program(source,state);
  if(!std::holds_alternative<NumericValue>(value) || std::get<std::int64_t>(std::get<NumericValue>(value).data)!=tick*(tick+1)/2) return 1;
  auto hash=hash_state(state);if(!std::holds_alternative<std::uint64_t>(hash)) return 2;
  std::cout<<std::hex<<std::setfill('0')<<std::setw(16)<<std::get<std::uint64_t>(hash)<<'\n';
 }
}
