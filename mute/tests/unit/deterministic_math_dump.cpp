#include "poko/mute/deterministic_math.hpp"
#include <bit>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <variant>
using namespace poko::mute;
int main() {
  std::uint64_t bits=0;
  while (std::cin>>std::hex>>bits) {
    double x=std::bit_cast<double>(bits);
    const auto a=deterministic_sin(x),b=deterministic_cos(x);
    if (!std::holds_alternative<double>(a) || !std::holds_alternative<double>(b)) return 1;
    std::cout<<std::hex<<std::setfill('0')<<std::setw(16)<<std::bit_cast<std::uint64_t>(std::get<double>(a))<<' '
             <<std::setw(16)<<std::bit_cast<std::uint64_t>(std::get<double>(b))<<'\n';
  }
  return std::cin.eof()?0:1;
}
