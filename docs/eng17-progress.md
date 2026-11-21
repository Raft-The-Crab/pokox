# ENG-17 — Async load queue

Status: implemented and verified in both build trees.

## What was built

Extends `poko::resource` (ENG-16) with non-blocking loads:

- `AssetStore::request_async(key, loader)` — enqueues a job on the store's
  single worker thread and returns immediately. Duplicate requests for a
  key already queued/running are deduplicated.
- `AssetStore::poll_async()` — call once per frame; installs finished
  payloads into the asset map and records failures. Cheap when idle.
- `load_state(key)` / `is_loading(key)` / `last_error(key)` —
  `LoadState::{none, loading, ready, failed}`.
- `acquire()` on an in-flight key fails fast with "still loading"
  instead of blocking or double-loading; the sync `acquire()` path is
  unchanged for callers that want it.

## Concurrency design

- Worker thread lives in `AssetStore::State`; `~State` sets `stop`,
  notifies, and joins — clean shutdown even with queued/running jobs.
- The worker only produces `Job::payload`/`error` and publishes
  `Job::phase` with release ordering; `poll_async`/`load_state` read with
  acquire ordering. **All map and refcount mutation stays on the calling
  thread** — ENG-16's single-threaded invariants are preserved; no mutex
  is needed on `assets`/`jobs`/`failures`.
- Job objects are `shared_ptr` so worker and poller can both hold them
  after `jobs_` entries are erased.

## Verification

- `pokox_asset_store_test` new cases: async load completes without
  blocking, dedup, acquire-during-flight fails fast, `poll_async` install,
  failed loader → `failed` + `last_error`, explicit retry, store teardown
  with a sleeping job.
- `build/` 30/30 (excluding `version_integration`, verified separately)
  and `build-full/` build + asset test pass.

## Audit round — defects found and fixed

- **`ensure_worker` flag ordering**: `worker_started` was set before
  `std::thread` construction; a throwing ctor would leave it stuck true
  with jobs never running. Flag now set only after the thread exists.
- **`request_async` re-loaded ready assets**: no check for an installed
  payload — now returns early when the key is already `ready`.
- **Dedup gap (phase 2)**: a done-awaiting-`poll_async` job did not dedup,
  enqueueing a duplicate; dedup now covers phases 0–2 (phase 3 failed
  still allows explicit retry).
- **`acquire` guard gap**: phase-2 jobs fell through to the sync loader,
  double-loading; now treated as busy like phases 0–1.
- **`poll_async` noexcept + `bad_alloc`**: `assets[key]` could throw
  inside a `noexcept` function → terminate. Install is now wrapped; a
  failed install records `failures[key]` instead, and `failures.erase`
  only runs on success.
- **Thread affinity** (documented, unchanged): `request_async`,
  `poll_async`, `acquire`, and the counters must be called from one
  owner thread; only the worker runs concurrently and it touches only
  `Job` fields published via release/acquire ordering.

## Not done / future

- Single worker thread — a pool can be added if profiling shows queue
  starvation; the job interface already supports it.
- Completed-but-never-acquired async loads stay resident until store
  destruction (same cache semantics as sync loads).
- No priority lanes, cancellation, or progress reporting yet.
