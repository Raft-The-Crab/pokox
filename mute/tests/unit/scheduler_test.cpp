#include "poko/mute/scheduler.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
StepResult fin() { return {StepKind::finish}; }

void cases() {
  // FIFO spawn order and deterministic replay.
  {
    std::vector<int> order;
    auto make=[&](int tag){ return [&,tag](Scheduler&,TaskId){ order.push_back(tag); return fin(); }; };
    Scheduler s;
    s.spawn(make(1)); s.spawn(make(2)); s.spawn(make(3));
    check(s.run().index()==0,"fifo run");
    check((order==std::vector<int>{1,2,3}),"fifo order");
    order.clear(); Scheduler s2;
    s2.spawn(make(1)); s2.spawn(make(2)); s2.spawn(make(3));
    s2.run();
    check((order==std::vector<int>{1,2,3}),"replay identical");
  }
  // Await suspends the waiter until the target finishes; resume order is
  // deterministic and the waiter observes the completed target.
  {
    std::vector<std::string> log;
    Scheduler s;
    TaskId slow=no_task;
    int slow_steps=0;
    slow=s.spawn([&](Scheduler&,TaskId){
      log.push_back("slow"+std::to_string(++slow_steps));
      return slow_steps<2 ? StepResult{StepKind::yield} : fin();
    });
    int waiter_steps=0;
    s.spawn([&,slow](Scheduler&,TaskId self){
      if (++waiter_steps==1) return StepResult{StepKind::await_task,slow};
      log.push_back("waiter done, slow="+std::to_string(s.state(slow)==TaskState::done));
      return fin();
    });
    check(s.run().index()==0,"await run");
    check((log==std::vector<std::string>{"slow1","slow2","waiter done, slow=1"}),"await order");
  }
  // Await on an already-finished task resumes immediately next slice.
  {
    Scheduler s; std::vector<int> seq;
    TaskId done=no_task;
    done=s.spawn([&](Scheduler&,TaskId){ seq.push_back(0); return fin(); });
    int awaiter_calls=0;
    s.spawn([&,done](Scheduler&,TaskId){
      if (++awaiter_calls==1) return StepResult{StepKind::await_task,done};
      seq.push_back(1); return fin();
    });
    s.spawn([&](Scheduler&,TaskId){ seq.push_back(2); return fin(); });
    check(s.run().index()==0,"await-done run");
    check((seq==std::vector<int>{0,2,1}),"await-done order");
  }
  // Cancellation: a cancelled ready task never runs; waiters wake and observe.
  {
    std::vector<int> ran;
    Scheduler s;
    TaskId victim=no_task, watcher=no_task;
    victim=s.spawn([&](Scheduler&,TaskId){ ran.push_back(1); return fin(); });
    watcher=s.spawn([&,victim](Scheduler&,TaskId){
      static int n=0; ++n;
      if (n==1) return StepResult{StepKind::await_task,victim};
      ran.push_back(s.state(victim)==TaskState::cancelled ? 3 : 4);
      return fin();
    });
    s.cancel(victim);
    check(s.run().index()==0,"cancel run");
    check((ran==std::vector<int>{3}),"cancelled task skipped, waiter observed");
    (void)watcher;
  }
  // Step budget is enforced.
  {
    Scheduler s{Scheduler::Limits{.max_tasks=8,.max_steps=3}};
    s.spawn([](Scheduler&,TaskId){ return StepResult{StepKind::yield}; });
    auto r=s.run();
    check(r.index()==1 && std::get<ScheduleError>(r).code==ScheduleErrorCode::budget_exceeded,"budget");
  }
  // Task table cap.
  {
    Scheduler s{Scheduler::Limits{.max_tasks=2,.max_steps=100}};
    s.spawn([](Scheduler&,TaskId){ return fin(); });
    s.spawn([](Scheduler&,TaskId){ return fin(); });
    check(s.spawn([](Scheduler&,TaskId){ return fin(); })==no_task,"task limit");
  }
  // Awaiting self or an unknown task cancels the waiter rather than hanging.
  {
    Scheduler s; bool waiter_ran=false;
    TaskId self=no_task;
    self=s.spawn([&](Scheduler&,TaskId id){
      if (!waiter_ran) { waiter_ran=true; return StepResult{StepKind::await_task,id}; }
      return fin();
    });
    check(s.run().index()==0,"self-await run");
    check(s.state(self)==TaskState::cancelled,"self-await cancels");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " scheduler test(s) failed\n"; return 1; }
  std::cout << "scheduler tests passed\n";
  return 0;
}
