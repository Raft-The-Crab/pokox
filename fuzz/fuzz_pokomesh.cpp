#include "poko/resource/pokomesh.hpp"
#include <cstdint>
#include <cstddef>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  (void)poko::resource::parse_pokomesh(data, size, nullptr);
  return 0;
}
