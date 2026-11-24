# MUT-23 — cooperative async scheduling (foundation)

Status: runtime foundation implemented and unit-tested locally; `await`/`spawn`
syntax lowering and hosted/target gates remain open.

## What was added

- `mute/include/poko/mute/scheduler.hpp` and `mute/src/vm/scheduler.cpp`:
  `Scheduler` drives resumable tasks one step at a time on a single thread.
- `mute/tests/unit/scheduler_test.cpp` registered as CTest
  `mute_scheduler_unit`.

## Semantics

- `spawn(step)` appends to a FIFO ready queue; `TaskId`s are stable slot
  indices bounded by `max_tasks` (default 1024).
- A step returns `yield` (re-queue FIFO), `await_task(target)` (suspend until
  target reaches `done` or `cancelled`), or `finish`.
- Waiters wake in deterministic task order; awaiting an already-terminal
  task resumes on the next slice; self-await and unknown targets cancel the
  waiter instead of hanging.
- `cancel(id)` marks the task cancelled: ready tasks are dropped without
  running, waiters are woken to observe the terminal state.
- `run()` enforces `max_steps` (default 1,000,000) and returns
  `budget_exceeded`; thrown step exceptions cancel the task.
- Identical spawn/await sequences produce identical completion orders —
  verified by replay test.

## Evidence

- Debug MSVC build clean; `mute_scheduler_unit` passes (FIFO order, replay
  determinism, await suspend/resume ordering, await-on-done, cancellation
  propagation, budget and task-table caps, self-await).
- `tools/version` integration source list updated.

## Limits

- Not wired into `run_program`/bytecode or the `await`/`spawn` surface
  syntax; that lowering is MUT-26 and hostcall/event integration is
  MUT-54.
- Task steps are `std::function` callbacks, not compiled Mute coroutines;
  the deterministic ordering contract is what the compiler must target.
- Waiter wake order is task-id order (deterministic), not arrival order —
  acceptable for v1 replay but noted for the conformance suite.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.
