#include "poko/foundation/cbor.hpp"
#include <cstdint>
#include <cstddef>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  (void)poko::cbor::decode({reinterpret_cast<const char*>(data), size});
  return 0;
}
