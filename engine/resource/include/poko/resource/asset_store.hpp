#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

namespace poko::resource {

// ENG-16: refcounted asset handles. Single-threaded seed — the async load
// queue (ENG-17) will own concurrency later. A handle keeps its store state
// alive, so handles may outlive the AssetStore object safely.

// Type-erased payload; the loader decides the concrete type. Recover it with
// AssetHandle::typed<T>() or payload().
using AssetPayload = std::shared_ptr<void>;
// Returns nullptr (or throws) when the asset cannot be produced.
using AssetLoader = std::function<AssetPayload(const std::string& key)>;

// Observable load state for one key (ENG-17 async loads).
enum class LoadState : std::uint8_t { none, loading, ready, failed };

class AssetHandle;

class AssetStore {
 public:
  AssetStore();
  ~AssetStore();
  AssetStore(const AssetStore&) = delete;
  AssetStore& operator=(const AssetStore&) = delete;
  AssetStore(AssetStore&&) noexcept;
  AssetStore& operator=(AssetStore&&) noexcept;

  // Acquires a refcounted handle for `key`. The first acquire (or the first
  // after the last handle released) invokes `loader` exactly once; concurrent
  // holders share the same payload. Returns an invalid handle on loader
  // failure; `error` receives a human-readable reason when provided.
  [[nodiscard]] AssetHandle acquire(const std::string& key,
                                    const AssetLoader& loader,
                                    std::string* error = nullptr);

  [[nodiscard]] std::size_t resident_count() const noexcept;
  [[nodiscard]] std::size_t load_count() const noexcept;    // loader invocations
  [[nodiscard]] std::size_t unload_count() const noexcept;  // payload destructions

  // ENG-17 async loads. request_async enqueues `loader` on the store's
  // single worker thread and returns immediately — the frame never blocks.
  // Repeated requests for a key already loading return the same job.
  // poll_async() must be called once per frame (cheap): it installs finished
  // payloads into the store and records failures. All map/refcount mutation
  // stays on the calling thread; the worker only produces payloads.
  void request_async(const std::string& key, const AssetLoader& loader);
  void poll_async() noexcept;
  [[nodiscard]] LoadState load_state(const std::string& key) const noexcept;
  [[nodiscard]] std::string last_error(const std::string& key) const noexcept;
  // True while a job for `key` is queued or running.
  [[nodiscard]] bool is_loading(const std::string& key) const noexcept;

 private:
  struct State;
  std::shared_ptr<State> state_;
  friend class AssetHandle;
};

class AssetHandle {
 public:
  AssetHandle() = default;
  ~AssetHandle();
  AssetHandle(const AssetHandle& other);
  AssetHandle& operator=(const AssetHandle& other);
  AssetHandle(AssetHandle&& other) noexcept;
  AssetHandle& operator=(AssetHandle&& other) noexcept;

  [[nodiscard]] bool valid() const noexcept { return state_ != nullptr; }
  [[nodiscard]] std::string key() const;
  // The shared payload, or nullptr when invalid.
  [[nodiscard]] AssetPayload payload() const;
  // Typed view of the payload; nullptr when invalid or the type differs.
  template <typename T>
  [[nodiscard]] std::shared_ptr<T> typed() const {
    auto p = payload();
    return p ? std::static_pointer_cast<T>(p) : nullptr;
  }

 private:
  friend class AssetStore;
  AssetHandle(std::shared_ptr<AssetStore::State> state, std::string key);
  void release() noexcept;
  std::shared_ptr<AssetStore::State> state_;
  std::string key_;
};

}  // namespace poko::resource
