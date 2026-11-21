// ENG-16: refcounted asset handles — load once per live set, unload at zero,
// no leaks across copies, moves, failures, and store teardown.
#include "poko/resource/asset_store.hpp"

#include <chrono>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <thread>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

struct Payload { int tag = 0; };

poko::resource::AssetLoader counting_loader(int* loads) {
  return [loads](const std::string&) -> poko::resource::AssetPayload {
    ++*loads;
    return std::make_shared<Payload>();
  };
}
}

int main() {
  using namespace poko::resource;
  {
    // Shared acquire: one load, two refs, one unload.
    AssetStore store;
    int loads = 0;
    auto loader = counting_loader(&loads);
    auto a = store.acquire("tex", loader);
    auto b = store.acquire("tex", loader);
    CHECK(a.valid() && b.valid());
    CHECK(loads == 1 && store.load_count() == 1);
    CHECK(store.resident_count() == 1);
    CHECK(a.payload() && a.payload() == b.payload());  // same payload object
    auto typed = a.typed<Payload>();
    CHECK(typed && typed->tag == 0);
    b = AssetHandle{};
    CHECK(store.resident_count() == 1);   // still held by a
    a = AssetHandle{};
    CHECK(store.resident_count() == 0);
    CHECK(store.unload_count() == 1);
    // Re-acquire after full release reloads.
    auto c = store.acquire("tex", loader);
    CHECK(c.valid() && loads == 2 && store.load_count() == 2);
  }
  {  // Copies share ownership; move transfers without touching refs.
    AssetStore store;
    int loads = 0;
    auto a = store.acquire("mesh", counting_loader(&loads));
    AssetHandle copies[8];
    for (auto& h : copies) h = a;         // copy-assign: 9 refs total
    auto moved = std::move(a);
    CHECK(moved.valid() && !a.valid());
    for (auto& h : copies) h = AssetHandle{};
    CHECK(store.resident_count() == 1);   // moved still holds it
    moved = AssetHandle{};
    CHECK(store.resident_count() == 0 && store.unload_count() == 1);
  }
  {  // Loader failures produce invalid handles and no resident entry.
    AssetStore store;
    std::string error;
    auto bad = store.acquire("", [](const std::string&) { return AssetPayload{}; }, &error);
    CHECK(!bad.valid() && !error.empty());
    error.clear();
    auto nullp = store.acquire("k", [](const std::string&) { return AssetPayload{}; }, &error);
    CHECK(!nullp.valid() && !error.empty());
    error.clear();
    auto threw = store.acquire("k", [](const std::string&) -> AssetPayload {
      throw std::runtime_error("boom");
    }, &error);
    CHECK(!threw.valid() && error == "boom");
    CHECK(store.resident_count() == 0 && store.load_count() == 0);
  }
  {  // Handles outlive the store object safely.
    AssetHandle h;
    {
      AssetStore store;
      int loads = 0;
      h = store.acquire("late", counting_loader(&loads));
      CHECK(h.valid());
    }  // store destroyed; state kept alive by the handle
    CHECK(h.valid() && h.payload());
    h = AssetHandle{};                   // release into dead store state
    CHECK(h.payload() == nullptr);
  }
  {  // Leak check: many acquire/release cycles balance loads and unloads.
    AssetStore store;
    int loads = 0;
    auto loader = counting_loader(&loads);
    for (int i = 0; i < 1000; ++i) {
      auto h = store.acquire("churn", loader);
      CHECK(h.valid());
    }  // each h dies at iteration end: load + unload per cycle
    CHECK(loads == 1000 && store.load_count() == 1000);
    CHECK(store.unload_count() == 1000);
    CHECK(store.resident_count() == 0);
    // Holding many refs at once: one load, N refs, N-1 releases keep it.
    AssetHandle held[64];
    for (auto& h : held) h = store.acquire("bulk", loader);
    CHECK(loads == 1001 && store.resident_count() == 1);
    for (int i = 0; i < 63; ++i) held[i] = AssetHandle{};
    CHECK(store.resident_count() == 1 && store.unload_count() == 1000);
    held[63] = AssetHandle{};
    CHECK(store.resident_count() == 0 && store.unload_count() == 1001);
  }
  {  // Re-entrant loader: acquiring inside a loader must not corrupt state.
    AssetStore store;
    int loads = 0;
    AssetHandle inner;
    auto outer = store.acquire("outer", [&](const std::string&) -> AssetPayload {
      ++loads;
      inner = store.acquire("inner", counting_loader(&loads));  // re-enters map
      return std::make_shared<Payload>();
    });
    CHECK(outer.valid() && inner.valid() && loads == 2);
    CHECK(store.resident_count() == 2);
    inner = AssetHandle{}; outer = AssetHandle{};
    CHECK(store.resident_count() == 0 && store.unload_count() == 2);
  }
  {  // Moved-from store is safe to reuse and to query.
    AssetStore store;
    AssetStore moved{std::move(store)};
    CHECK(store.resident_count() == 0 && store.load_count() == 0);
    int loads = 0;
    auto h = store.acquire("revived", counting_loader(&loads));  // lazy re-init
    CHECK(h.valid() && loads == 1);
    CHECK(moved.resident_count() == 0);
  }
  {  // error out-param is cleared on success.
    AssetStore store;
    int loads = 0;
    std::string error = "stale";
    auto h = store.acquire("ok", counting_loader(&loads), &error);
    CHECK(h.valid() && error.empty());
  }
  {  // ENG-17: async load does not block; poll installs the payload.
    AssetStore store;
    int loads = 0;
    store.request_async("async_tex", counting_loader(&loads));
    CHECK(store.is_loading("async_tex"));
    CHECK(store.load_state("async_tex") == LoadState::loading);
    // Dedup: a second request while loading does not enqueue another job.
    store.request_async("async_tex", counting_loader(&loads));
    // acquire during flight fails fast instead of blocking.
    std::string error;
    auto early = store.acquire("async_tex", counting_loader(&loads), &error);
    CHECK(!early.valid() && !error.empty());
    // Wait for the worker (bounded), then poll.
    for (int i = 0; i < 200 && store.is_loading("async_tex"); ++i)
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    CHECK(!store.is_loading("async_tex"));
    store.poll_async();
    CHECK(store.load_state("async_tex") == LoadState::ready);
    auto h = store.acquire("async_tex", counting_loader(&loads));
    CHECK(h.valid() && loads == 1);   // loaded once, on the worker
    h = AssetHandle{};
    CHECK(store.unload_count() == 1);
  }
  {  // Failed async load records state + error; retry works.
    AssetStore store;
    store.request_async("bad", [](const std::string&) -> AssetPayload {
      throw std::runtime_error("io error");
    });
    for (int i = 0; i < 200 && store.is_loading("bad"); ++i)
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    store.poll_async();
    CHECK(store.load_state("bad") == LoadState::failed);
    CHECK(store.last_error("bad") == "io error");
    int loads = 0;
    store.request_async("bad", counting_loader(&loads));  // explicit retry
    for (int i = 0; i < 200 && store.is_loading("bad"); ++i)
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    store.poll_async();
    CHECK(store.load_state("bad") == LoadState::ready);
    auto h = store.acquire("bad", counting_loader(&loads));
    CHECK(h.valid());
  }
  {  // Store destruction with a queued/running job shuts down cleanly.
    {
      AssetStore store;
      store.request_async("pending", [](const std::string&) -> AssetPayload {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        return std::make_shared<Payload>();
      });
    }  // ~State stops and joins the worker
    CHECK(true);
  }
  if (failures) { std::fprintf(stderr, "%d check(s) failed\n", failures); return 1; }
  std::puts("PASS: asset store refcounting, shared payload, failure paths, leak balance");
  return 0;
}
