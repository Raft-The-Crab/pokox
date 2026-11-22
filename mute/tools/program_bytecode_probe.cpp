// Portable evidence probe: emit the canonical bytes for a loop program after
// verifying it executes to 78. Compile with the same flags as the Mute runtime.
#include "poko/mute/program.hpp"
#include <iomanip>
#include <iostream>
#include <variant>
int main() {
  using namespace poko::mute;
  constexpr auto source="fn f(n:i32)->i32 {var v=0; var k=n; while k>0 {v=v+k; k=k-1;} return v;} f(12)";
  auto binary=compile_program_bytecode(source);
  if (!std::holds_alternative<std::vector<std::uint8_t>>(binary)) return 1;
  const auto& bytes=std::get<std::vector<std::uint8_t>>(binary);
  auto result=run_program_bytecode(bytes);
  if (!std::holds_alternative<NumericValue>(result) || std::get<std::int64_t>(std::get<NumericValue>(result).data)!=78) return 2;
  for (auto b:bytes) std::cout<<std::hex<<std::setfill('0')<<std::setw(2)<<static_cast<unsigned>(b);
  std::cout<<'\n';
}
