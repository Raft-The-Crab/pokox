# ENG-16 — Asset handle with refcount

Status: implemented and verified in both build trees.

## What was built

- `engine/resource/include/poko/resource/asset_store.hpp` +
  `src/asset_store.cpp` — `poko::resource`, dependency-free, single-threaded
  (ENG-17 owns the async load queue later):
  - `AssetStore::acquire(key, loader, error)` — first acquire (or first after
    full release) invokes the loader once; concurrent holders share one
    type-erased `AssetPayload` (`shared_ptr<void>`). Loader failure
    (empty key, null/throwing loader, null payload) returns an invalid
    handle with an error string; no resident entry is left behind.
  - `AssetHandle` — RAII copyable/movable guard. Copies share the entry
    refcount; the last release erases the entry and destroys the payload.
    Handles keep the store `State` alive via `shared_ptr`, so they are safe
    after the `AssetStore` object is destroyed.
  - Diagnostics: `resident_count()`, `load_count()`, `unload_count()`.
- `poko_resource` CMake target (always built) + `pokox_asset_store_test`
  (both trees): shared acquire, copy/move ownership, failure paths,
  store-teardown safety, and a 1000-cycle leak-balance check.

## Defect found by the new test during implementation

`AssetHandle::operator=` called `this->~AssetHandle()` explicitly — which
runs the *full* destructor including member destruction — then assigned
into the destroyed `state_`/`key_` members. Result: double-release of the
`State` control block (use_count went negative → heap-use-after-free,
observed as `0xfeeefeee` freed-memory reads and SIGSEGV in
`unordered_map::find`). Fixed by extracting a `release()` helper that only
decrements the entry refcount; `~AssetHandle()` and both assignment
operators now call it instead of the explicit destructor.

## Audit round 2 — additional defects found and fixed

- **Re-entrant loader use-after-free**: `acquire()` held an
  `unordered_map` element reference across the `loader(key)` call; a loader
  that recursively acquires assets can rehash the map and dangle it.
  Restructured: fast-path `find` for live entries, loader runs with no map
  reference held, entry re-found afterwards.
- **Copy-assign exception safety**: `key_ = other.key_` (can throw
  `bad_alloc`) ran after `state_` was overwritten, leaving a mismatched
  state/key pair. Now copies the key first, then releases, then assigns
  (shared_ptr assign is noexcept).
- **Moved-from `AssetStore` crash**: default move leaves `state_` null;
  `acquire()` now lazily re-initializes and the counters return 0.
- **`error` out-param** is now cleared on entry so stale text can't mislead.
- **`version_integration` regression (since ENG-14)**: the test copies a
  fixed source manifest; unconditional `poko_config`/`poko_stats`/
  `poko_resource` libraries referenced files absent from it. Manifest
  updated; test passes again (was masked by excluding it as "slow").

## Verification

- `pokox_asset_store_test` passes in `build/` (31/31) and `build-full/`
  (32/32), including re-entrant-loader, moved-from-store, and error-clear
  regression cases.

## Not done / future

- Single-threaded only; ENG-17 adds the async load queue and will need
  internal synchronization.
- No typed asset registry, hot reload, or chunk reader yet (spec 21 lists
  those under `resource`; later ENG tasks).
- `typed<T>()` is an unchecked `static_pointer_cast` — caller must match
  the loader's concrete type.
