#include "poko/resource/asset_store.hpp"
#include <atomic>
#include <chrono>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <new>
#include <string>
namespace { std::atomic<bool> fail_next{false}; }
void* operator new(std::size_t size) {
  if (fail_next.exchange(false)) throw std::bad_alloc();
  if (void* p = std::malloc(size ? size : 1)) return p;
  throw std::bad_alloc();
}
void operator delete(void* p) noexcept { std::free(p); }
void operator delete(void* p, std::size_t) noexcept { std::free(p); }
int main() {
  using namespace poko::resource;
  AssetStore store;
  const std::string key(100, 'x');
  const AssetLoader loader = [](const std::string&) -> AssetPayload { return std::make_shared<int>(42); };
  auto first = store.acquire(key, loader);
  if (!first.valid()) return 1;
  bool threw = false;
  fail_next.store(true);
  try { auto other = store.acquire(key, loader); }
  catch (const std::bad_alloc&) { threw = true; }
  fail_next.store(false);
  first = AssetHandle{};
  if (!threw || store.resident_count() != 0 || store.unload_count() != 1) {
    std::fputs("FAIL: throwing handle construction leaked a reference\n", stderr);
    return 1;
  }
  // The worker has completed before allocation injection is armed, so the
  // failure happens in poll_async on the owner thread, not in the loader.
  const std::string async_key(100, 'y');
  store.request_async(async_key, [](const std::string&) -> AssetPayload { return {}; });
  for (int i = 0; i < 200 && store.is_loading(async_key); ++i)
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  if (store.load_state(async_key) != LoadState::failed) return 1;
  fail_next.store(true);
  store.poll_async();  // must not terminate; failed job must remain observable
  fail_next.store(false);
  if (store.load_state(async_key) != LoadState::failed) return 1;
  store.poll_async();  // retry recording the failure after memory recovers
  if (store.last_error(async_key).empty()) return 1;
  fail_next.store(true);
  bool copy_threw = false;
  try { auto error = store.last_error(async_key); }
  catch (const std::bad_alloc&) { copy_threw = true; }
  fail_next.store(false);
  if (!copy_threw) return 1;
  const std::string ready_key(100, 'z');
  store.request_async(ready_key, loader);
  for (int i = 0; i < 200 && store.is_loading(ready_key); ++i)
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  if (store.load_state(ready_key) != LoadState::awaiting_install) return 1;
  fail_next.store(true);
  store.poll_async();  // map insertion fails; payload stays queued
  fail_next.store(false);
  if (store.load_state(ready_key) != LoadState::awaiting_install) return 1;
  store.poll_async();
  if (store.load_state(ready_key) != LoadState::ready) return 1;
  auto recovered = store.acquire(ready_key, loader);
  if (!recovered.valid()) return 1;
  std::puts("PASS: asset handle and async allocation-failure handling");
  return 0;
}
