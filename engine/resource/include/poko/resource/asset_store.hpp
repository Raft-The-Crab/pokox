#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

namespace poko::resource {

// ENG-16/17: refcounted asset handles and a single async loader worker.
// Store and handle operations belong to one owner thread. A handle keeps its
// store state alive, so handles may outlive the AssetStore object safely.

// Type-erased payload; the loader decides the concrete type. Recover it with
// AssetHandle::typed<T>() or payload().
using AssetPayload = std::shared_ptr<void>;
// Returns nullptr (or throws) when the asset cannot be produced.
using AssetLoader = std::function<AssetPayload(const std::string& key)>;

// Observable load state for one key (ENG-17 async loads).
// ready means installed and acquirable; awaiting_install requires poll_async().
enum class LoadState : std::uint8_t { none, loading, ready, failed, awaiting_install };

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
  [[nodiscard]] std::size_t load_count() const noexcept;    // payloads installed
  [[nodiscard]] std::size_t unload_count() const noexcept;  // resident entries removed

  // ENG-17 async loads. request_async enqueues `loader` on the store's
  // single worker thread without waiting for the loader. Thread startup and
  // allocation can still take time or throw. Empty keys throw invalid_argument.
  // Calls and handle operations must stay on one owner thread; only the loader
  // runs on the worker. Repeated requests for an active key are deduplicated.
  // poll_async() installs completed payloads and records failures; call it
  // regularly, including when load_state() is awaiting_install. Destruction of
  // the shared store state joins the worker and may wait for a running loader.
  void request_async(const std::string& key, const AssetLoader& loader);
  // Memory-pressure failures remain queued for a later poll.
  void poll_async() noexcept;
  [[nodiscard]] LoadState load_state(const std::string& key) const noexcept;
  // Returns the most recent failure after poll_async; retry/success clears it.
  // Returns a copy and may throw on allocation failure.
  [[nodiscard]] std::string last_error(const std::string& key) const;
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
  // Unchecked typed view; caller must use the payload's actual type.
  // Returns nullptr only when the payload is absent.
  template <typename T>
  [[nodiscard]] std::shared_ptr<T> typed() const {
    auto p = payload();
    return p ? std::static_pointer_cast<T>(p) : nullptr;
  }

 private:
  friend class AssetStore;
  AssetHandle(std::shared_ptr<AssetStore::State> state, std::string key) noexcept;
  void release() noexcept;
  std::shared_ptr<AssetStore::State> state_;
  std::string key_;
};

}  // namespace poko::resource
