#pragma once

#include <cstddef>
#include <cstdint>
#include <deque>
#include <functional>
#include <variant>
#include <vector>

namespace poko::mute {

// Cooperative async scheduling (MUT-23 foundation). Tasks are resumable
// computations driven one step at a time on a single thread: spawn() appends
// to a FIFO ready queue, await suspends the running task until its target
// reaches a terminal state, and cancel() marks a task cancelled. Scheduling
// is fully deterministic — identical spawn/await sequences produce identical
// completion orders, which is what G1/G2 replay requires.
//
// This is the runtime the future `spawn`/`await` lowering (MUT-26) targets;
// it is not yet wired into run_program or bytecode.

enum class TaskState : std::uint8_t { ready, running, waiting, done, cancelled };
using TaskId = std::uint32_t;
inline constexpr TaskId no_task = 0;

enum class StepKind : std::uint8_t { yield, await_task, finish };
struct StepResult {
  StepKind kind{StepKind::yield};
  TaskId target{no_task}; // required for await_task
};
// A task step runs once per scheduling slice. Returning await_task(target)
// suspends until target is done or cancelled; finish() ends the task.
using TaskStep = std::function<StepResult(class Scheduler&, TaskId self)>;

enum class ScheduleErrorCode : std::uint8_t {
  budget_exceeded, task_limit, unknown_task, invalid_await, cancelled_target
};
struct ScheduleError { ScheduleErrorCode code{}; std::size_t step{}; };
using ScheduleResult = std::variant<std::monostate, ScheduleError>;

class Scheduler {
 public:
  struct Limits {
    std::size_t max_tasks{1024};
    std::size_t max_steps{1'000'000};
  };
  explicit Scheduler(Limits limits = {}) : limits_(limits) {}

  // FIFO spawn. Returns no_task when the task table is full.
  [[nodiscard]] TaskId spawn(TaskStep step);
  // Mark a task cancelled. Running/waiting tasks observe it at their next
  // slice; ready tasks are dropped without executing.
  void cancel(TaskId id);
  [[nodiscard]] TaskState state(TaskId id) const;
  [[nodiscard]] std::size_t completed() const noexcept { return completed_; }
  [[nodiscard]] std::size_t live_tasks() const noexcept { return tasks_.size(); }

  // Drive the scheduler until every task is terminal or the step budget is
  // exhausted. ready tasks run in FIFO order; waiters are re-queued in the
  // order they began waiting (deterministic).
  [[nodiscard]] ScheduleResult run();

 private:
  struct Task {
    TaskStep step;
    TaskState state{TaskState::ready};
    TaskId waiting_on{no_task};
  };
  [[nodiscard]] Task* find(TaskId id);
  Limits limits_;
  std::vector<Task> tasks_;
  std::deque<TaskId> ready_;
  std::size_t steps_{}, completed_{};
};

} // namespace poko::mute
