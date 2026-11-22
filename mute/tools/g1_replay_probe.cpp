// G1 recorded-input replay probe: runs a fixture program for 10,000 ticks and
// prints "tick value hash" per line (decimal tick/value, 16-digit lowercase hex
// state hash). Identical programs must produce byte-identical LF traces on
// every target; compare the whole trace, not only a final hash.
// Usage: g1_replay_probe <source.mute> [ticks]
#include "poko/mute/program.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <variant>
int main(int argc, char** argv) {
  if (argc < 2) return 64;
  const int ticks = argc > 2 ? std::stoi(argv[2]) : 10000;
  std::ifstream in(argv[1], std::ios::binary);
  if (!in) return 66;
  const std::string source{std::istreambuf_iterator<char>(in), {}};
  using namespace poko::mute;
  ProgramState state;
  for (int tick = 1; tick <= ticks; ++tick) {
    auto value = run_stateful_program(source, state);
    const auto* number = std::get_if<NumericValue>(&value);
    if (!number || number->type != NumericType::i32) return 1;
    auto hash = hash_state(state);
    if (!std::holds_alternative<std::uint64_t>(hash)) return 2;
    std::cout << tick << ' ' << std::get<std::int64_t>(number->data) << ' '
              << std::hex << std::setfill('0') << std::setw(16)
              << std::get<std::uint64_t>(hash) << std::dec << '\n';
  }
}
