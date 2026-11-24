#include "poko/mute/scheduler.hpp"
#include <utility>
namespace poko::mute {
Scheduler::Task* Scheduler::find(TaskId id) {
  if (id==no_task || id>tasks_.size()) return nullptr;
  return &tasks_[id-1];
}
TaskId Scheduler::spawn(TaskStep step) {
  if (tasks_.size()>=limits_.max_tasks || tasks_.size()>=0xFFFFFFFEu) return no_task;
  tasks_.push_back(Task{std::move(step),TaskState::ready,no_task});
  const auto id=static_cast<TaskId>(tasks_.size());
  ready_.push_back(id);
  return id;
}
void Scheduler::cancel(TaskId id) {
  auto* t=find(id); if (!t) return;
  if (t->state==TaskState::done || t->state==TaskState::cancelled) return;
  t->state=TaskState::cancelled;
  // Wake waiters on this task so they can observe the terminal state.
  for (std::size_t i=0;i<tasks_.size();++i) {
    auto& other=tasks_[i];
    if (other.waiting_on==id && other.state==TaskState::waiting) {
      other.waiting_on=no_task; other.state=TaskState::ready;
      ready_.push_back(static_cast<TaskId>(i+1));
    }
  }
}
TaskState Scheduler::state(TaskId id) const {
  if (id==no_task || id>tasks_.size()) return TaskState::cancelled;
  return tasks_[id-1].state;
}
ScheduleResult Scheduler::run() {
  while (!ready_.empty()) {
    if (steps_>=limits_.max_steps) return ScheduleError{ScheduleErrorCode::budget_exceeded,steps_};
    const auto id=ready_.front(); ready_.pop_front();
    auto* t=find(id); if (!t) continue;
    if (t->state==TaskState::cancelled) { ++completed_; continue; }
    if (t->state!=TaskState::ready) continue;
    t->state=TaskState::running; ++steps_;
    StepResult result;
    try { result=t->step(*this,id); }
    catch (...) { t->state=TaskState::cancelled; ++completed_; continue; }
    switch (result.kind) {
      case StepKind::finish:
        t->state=TaskState::done; ++completed_;
        // Wake all waiters in FIFO order of their task ids for determinism.
        for (std::size_t i=0;i<tasks_.size();++i)
          if (tasks_[i].waiting_on==id && tasks_[i].state==TaskState::waiting) {
            tasks_[i].waiting_on=no_task; tasks_[i].state=TaskState::ready;
            ready_.push_back(static_cast<TaskId>(i+1));
          }
        break;
      case StepKind::await_task: {
        auto* target=find(result.target);
        if (!target || result.target==id) { t->state=TaskState::cancelled; ++completed_; break; }
        if (target->state==TaskState::done || target->state==TaskState::cancelled) {
          t->state=TaskState::ready; ready_.push_back(id); // already terminal: resume next slice
        } else {
          t->state=TaskState::waiting; t->waiting_on=result.target;
        }
        break;
      }
      case StepKind::yield:
        t->state=TaskState::ready; ready_.push_back(id);
        break;
    }
  }
  // Tasks may remain waiting on cancelled targets only if the target was
  // cancelled before they started waiting — cancel() already wakes them.
  return std::monostate{};
}
} // namespace poko::mute
