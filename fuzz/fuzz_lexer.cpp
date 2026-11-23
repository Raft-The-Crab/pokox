#include "poko/mute/lexer.hpp"
#include <cstdint>
#include <cstddef>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  (void)poko::mute::lex({reinterpret_cast<const char*>(data), size});
  return 0;
}
