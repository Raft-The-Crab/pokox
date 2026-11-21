#include "poko/resource/asset_store.hpp"

#include <atomic>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

namespace poko::resource {

struct AssetStore::State {
  struct Entry {
    AssetPayload payload;
    std::uint32_t refs = 0;
  };
  // ENG-17 async job. The worker writes payload/error, then publishes phase
  // with release ordering; poll_async reads with acquire ordering. Job
  // objects are shared_ptr so the worker and poll_async can both hold them
  // safely after jobs_ entries are erased.
  struct Job {
    std::string key;
    AssetLoader loader;
    std::atomic<int> phase{0};  // 0 queued, 1 running, 2 done, 3 failed
    AssetPayload payload;
    std::string error;
  };
  std::unordered_map<std::string, Entry> assets;
  std::size_t loads = 0;
  std::size_t unloads = 0;

  // Async machinery — only touched under `mutex` except Job::phase/payload.
  std::mutex mutex;
  std::condition_variable cv;
  std::deque<std::shared_ptr<Job>> queue;
  std::vector<std::shared_ptr<Job>> jobs;      // main thread only
  std::unordered_map<std::string, std::string> failures;  // main thread only
  bool stop = false;
  bool worker_started = false;
  std::thread worker;

  ~State() {
    {
      std::lock_guard lock(mutex);
      stop = true;
    }
    cv.notify_all();
    if (worker.joinable()) worker.join();
  }

  void run_worker() {
    for (;;) {
      std::shared_ptr<Job> job;
      {
        std::unique_lock lock(mutex);
        cv.wait(lock, [&] { return stop || !queue.empty(); });
        if (stop) return;
        job = std::move(queue.front());
        queue.pop_front();
      }
      job->phase.store(1, std::memory_order_relaxed);
      AssetPayload produced;
      std::string error;
      try {
        produced = job->loader ? job->loader(job->key) : AssetPayload{};
      } catch (const std::exception& e) {
        error = e.what();
      } catch (...) {
        error = "asset loader threw an unknown exception";
      }
      if (produced) {
        job->payload = std::move(produced);
        job->phase.store(2, std::memory_order_release);
      } else {
        job->error = error.empty() ? "asset loader produced no payload" : error;
        job->phase.store(3, std::memory_order_release);
      }
    }
  }

  void ensure_worker() {
    // Flag set only after the thread exists: a throwing std::thread ctor
    // must not leave worker_started stuck true with jobs never running.
    if (!worker_started) {
      worker = std::thread([this] { run_worker(); });
      worker_started = true;
    }
  }
};

AssetStore::AssetStore() : state_(std::make_shared<State>()) {}
AssetStore::~AssetStore() = default;
AssetStore::AssetStore(AssetStore&&) noexcept = default;
AssetStore& AssetStore::operator=(AssetStore&&) noexcept = default;

std::size_t AssetStore::resident_count() const noexcept {
  return state_ ? state_->assets.size() : 0;
}
std::size_t AssetStore::load_count() const noexcept { return state_ ? state_->loads : 0; }
std::size_t AssetStore::unload_count() const noexcept { return state_ ? state_->unloads : 0; }

void AssetStore::request_async(const std::string& key, const AssetLoader& loader) {
  if (!state_) state_ = std::make_shared<State>();
  auto& s = *state_;
  {
    std::lock_guard lock(s.mutex);
    s.ensure_worker();
    // Already installed: nothing to do.
    if (const auto it = s.assets.find(key);
        it != s.assets.end() && it->second.payload)
      return;
    // Dedup: one job per key while queued/running or done-awaiting-install.
    // Phase 3 (failed) jobs are replaced by an explicit retry request.
    for (const auto& job : s.jobs)
      if (job->key == key && job->phase.load(std::memory_order_acquire) != 3)
        return;
    auto job = std::make_shared<State::Job>();
    job->key = key;
    job->loader = loader;
    s.queue.push_back(job);
    s.jobs.push_back(job);
  }
  s.cv.notify_one();
}

void AssetStore::poll_async() noexcept {
  if (!state_) return;
  auto& s = *state_;
  // jobs_ is main-thread only; Job::phase/payload are published by the worker.
  for (auto it = s.jobs.begin(); it != s.jobs.end();) {
    auto& job = *it;
    const int phase = job->phase.load(std::memory_order_acquire);
    if (phase == 0 || phase == 1) { ++it; continue; }
    if (phase == 2 && job->payload) {
      bool installed = false;
      try {
        auto& entry = s.assets[job->key];
        if (!entry.payload) {
          entry.payload = std::move(job->payload);
          ++s.loads;
        }
        installed = true;
      } catch (...) {
        s.failures[job->key] = "failed to install async payload";
      }
      if (installed) s.failures.erase(job->key);
    } else {
      s.failures[job->key] = job->error;
    }
    it = s.jobs.erase(it);
  }
}

LoadState AssetStore::load_state(const std::string& key) const noexcept {
  if (!state_) return LoadState::none;
  const auto& s = *state_;
  if (const auto it = s.assets.find(key);
      it != s.assets.end() && it->second.payload)
    return LoadState::ready;
  for (const auto& job : s.jobs) {
    if (job->key != key) continue;
    const int phase = job->phase.load(std::memory_order_acquire);
    if (phase == 0 || phase == 1) return LoadState::loading;
    if (phase == 2) return LoadState::ready;  // awaiting poll_async install
    return LoadState::failed;
  }
  return s.failures.count(key) ? LoadState::failed : LoadState::none;
}

std::string AssetStore::last_error(const std::string& key) const noexcept {
  if (!state_) return {};
  const auto it = state_->failures.find(key);
  return it == state_->failures.end() ? std::string{} : it->second;
}

bool AssetStore::is_loading(const std::string& key) const noexcept {
  return load_state(key) == LoadState::loading;
}

AssetHandle AssetStore::acquire(const std::string& key, const AssetLoader& loader,
                                std::string* error) {
  if (error) error->clear();
  if (!state_) state_ = std::make_shared<State>();  // moved-from store reuse
  if (key.empty()) {
    if (error) *error = "asset key is empty";
    return {};
  }
  // Fast path: live entry, no loader call, no reference held across it.
  if (const auto it = state_->assets.find(key);
      it != state_->assets.end() && it->second.payload) {
    ++it->second.refs;
    return AssetHandle{state_, key};
  }
  // An in-flight async load must not be duplicated or blocked on. Phase 2
  // (done, awaiting poll_async install) counts as busy too.
  for (const auto& job : state_->jobs) {
    if (job->key == key && job->phase.load(std::memory_order_acquire) != 3) {
      if (error) *error = "asset is still loading asynchronously";
      return {};
    }
  }
  // Load outside any map-reference scope: a loader may recursively acquire
  // other assets, which can rehash the map and would dangle a held reference.
  AssetPayload produced;
  try {
    produced = loader ? loader(key) : AssetPayload{};
  } catch (const std::exception& e) {
    if (error) *error = e.what();
    return {};
  } catch (...) {
    if (error) *error = "asset loader threw an unknown exception";
    return {};
  }
  if (!produced) {
    if (error) *error = "asset loader produced no payload";
    return {};
  }
  // Re-find after the loader ran: the map may have changed underneath us.
  auto& entry = state_->assets[key];
  if (!entry.payload) {
    entry.payload = std::move(produced);
    ++state_->loads;
  }
  ++entry.refs;
  return AssetHandle{state_, key};
}

AssetHandle::AssetHandle(std::shared_ptr<AssetStore::State> state, std::string key)
    : state_(std::move(state)), key_(std::move(key)) {}

void AssetHandle::release() noexcept {
  if (!state_) return;
  auto& state = *state_;
  const auto it = state.assets.find(key_);
  if (it == state.assets.end()) return;  // store-side reset (not used yet)
  if (--it->second.refs == 0) {
    state.assets.erase(it);
    ++state.unloads;
  }
}

AssetHandle::~AssetHandle() { release(); }

AssetHandle::AssetHandle(const AssetHandle& other)
    : state_(other.state_), key_(other.key_) {
  if (state_) {
    const auto it = state_->assets.find(key_);
    if (it != state_->assets.end()) ++it->second.refs;
  }
}

AssetHandle& AssetHandle::operator=(const AssetHandle& other) {
  if (this == &other) return *this;
  // Copy the key before releasing: if the string assignment throws, this
  // handle must remain fully consistent (state_ and key_ still paired).
  std::string new_key = other.key_;
  release();
  state_ = other.state_;   // shared_ptr copy is noexcept
  key_ = std::move(new_key);
  if (state_) {
    const auto it = state_->assets.find(key_);
    if (it != state_->assets.end()) ++it->second.refs;
  }
  return *this;
}

AssetHandle::AssetHandle(AssetHandle&& other) noexcept
    : state_(std::move(other.state_)), key_(std::move(other.key_)) {}

AssetHandle& AssetHandle::operator=(AssetHandle&& other) noexcept {
  if (this == &other) return *this;
  release();
  state_ = std::move(other.state_);
  key_ = std::move(other.key_);
  return *this;
}

std::string AssetHandle::key() const { return state_ ? key_ : std::string{}; }

AssetPayload AssetHandle::payload() const {
  if (!state_) return {};
  const auto it = state_->assets.find(key_);
  return it == state_->assets.end() ? AssetPayload{} : it->second.payload;
}

}  // namespace poko::resource
