// Inject individual allocation failures into the public noexcept config API.
#include "poko/foundation/config.hpp"
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <new>
#include <string>
#include <system_error>

namespace {
std::atomic<long> fail_after{-1};
std::atomic<unsigned> injected{0};
}
namespace {
void* allocate_or_throw(std::size_t size) {
  const auto n = fail_after.load();
  if (n >= 0) {
    if (n == 0) { fail_after.store(-1); ++injected; throw std::bad_alloc(); }
    fail_after.store(n - 1);
  }
  if (void* p = std::malloc(size ? size : 1)) return p;
  throw std::bad_alloc();
}
}
void* operator new(std::size_t size) { return allocate_or_throw(size); }
void* operator new[](std::size_t size) { return allocate_or_throw(size); }
void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
  try { return allocate_or_throw(size); } catch (...) { return nullptr; }
}
void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
  try { return allocate_or_throw(size); } catch (...) { return nullptr; }
}
#if defined(_MSC_VER)
#include <malloc.h>
#endif
#if defined(_MSC_VER)
// MSVC's debug STL uses aligned allocation for over-aligned types; leaving
// these un-overridden pairs mismatched alloc/free paths and trips the CRT.
void* operator new(std::size_t size, std::align_val_t alignment) {
  const auto n = fail_after.load();
  if (n >= 0) {
    if (n == 0) { fail_after.store(-1); ++injected; throw std::bad_alloc(); }
    fail_after.store(n - 1);
  }
  const auto al = static_cast<std::size_t>(alignment);
  if (void* p = _aligned_malloc(size ? size : 1, al)) return p;
  throw std::bad_alloc();
}
void* operator new[](std::size_t size, std::align_val_t alignment) {
  return operator new(size, alignment);
}
void operator delete(void* p, std::align_val_t) noexcept { _aligned_free(p); }
void operator delete[](void* p, std::align_val_t) noexcept { _aligned_free(p); }
#endif
void operator delete(void* p) noexcept { std::free(p); }
void operator delete(void* p, std::size_t) noexcept { std::free(p); }
void operator delete[](void* p) noexcept { std::free(p); }
void operator delete[](void* p, std::size_t) noexcept { std::free(p); }

int main() {
#if defined(_MSC_VER) && (!defined(_ITERATOR_DEBUG_LEVEL) || _ITERATOR_DEBUG_LEVEL > 0)
  // With MSVC's default debug iterator level every STL container construction
  // allocates a proxy, so no noexcept path using the STL can survive injected
  // failures; the project only guarantees this contract at level 0, which is
  // impossible when linking prebuilt C++ dependencies. Report a CTest skip.
  std::puts("config allocation injection requires _ITERATOR_DEBUG_LEVEL=0");
  return 77;
#endif
  const auto path = std::filesystem::temp_directory_path() / "poko_config_oom.cbor";
  // One unknown, long text key: exercises CBOR strings and unknown-key lists.
  std::string data{"\xa1\x78\x64", 3}; data.append(100, 'x'); data.push_back('\x01');
  { std::ofstream out(path, std::ios::binary); out.write(data.data(), data.size()); }
  auto baseline = poko::config::load_file(path);
  if (baseline.error || baseline.unknown_keys.size() != 1) return 1;
  for (long n = 0; n < 100; ++n) {
    fail_after.store(n);
    const auto result = poko::config::load_file(path);
    fail_after.store(-1);
    // A failure or a complete successful parse are both valid; process
    // termination or a partial successful result violates the contract.
    if (!result.error && result.unknown_keys.size() != 1) {
      std::fprintf(stderr, "partial config at allocation %ld\n", n); return 1;
    }
  }
  // Best-effort cleanup: a throwing remove would terminate via the noexcept
  // boundary under some sanitizers/AV scanners that briefly lock the file.
  std::error_code ec;
  std::filesystem::remove(path, ec);
  if (injected.load() == 0) return 1;
  std::printf("PASS: %u injected allocation failures\n", injected.load());
  return 0;
}
