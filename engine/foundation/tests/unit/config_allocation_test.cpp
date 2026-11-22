// Inject individual allocation failures into the public noexcept config API.
#include "poko/foundation/config.hpp"
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <new>
#include <string>

namespace {
std::atomic<long> fail_after{-1};
std::atomic<unsigned> injected{0};
}
void* operator new(std::size_t size) {
  const auto n = fail_after.load();
  if (n >= 0) {
    if (n == 0) { fail_after.store(-1); ++injected; throw std::bad_alloc(); }
    fail_after.store(n - 1);
  }
  if (void* p = std::malloc(size ? size : 1)) return p;
  throw std::bad_alloc();
}
void operator delete(void* p) noexcept { std::free(p); }
void operator delete(void* p, std::size_t) noexcept { std::free(p); }

int main() {
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
  std::filesystem::remove(path);
  if (injected.load() == 0) return 1;
  std::printf("PASS: %u injected allocation failures\n", injected.load());
  return 0;
}
