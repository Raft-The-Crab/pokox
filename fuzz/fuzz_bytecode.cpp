#include "poko/mute/bytecode.hpp"
#include <cstdint>
#include <cstddef>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  (void)poko::mute::decode_bytecode({data, size});
  (void)poko::mute::assemble_bytecode({reinterpret_cast<const char*>(data), size});
  return 0;
}
