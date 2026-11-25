// MUT-54: deterministic lifecycle/game event order, subscriptions, teardown.
#include "poko/mute/events.hpp"

#include <cstdio>
#include <string>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

GameEvent event(EventPhase phase, std::uint64_t tick, std::uint32_t type, std::uint32_t source = 0) {
  GameEvent e;
  e.phase = phase;
  e.tick = tick;
  e.type = type;
  e.source = source;
  e.payload = {1, 2, 3, 4};
  return e;
}

EventBus configured(std::vector<std::string>* trace) {
  EventBus bus;
  auto a = bus.subscribe(EventPhase::startup, 10,
    [trace](const GameEvent& e) { trace->push_back("startup-a:" + std::to_string(e.tick)); });
  auto b = bus.subscribe(EventPhase::startup, 10,
    [trace](const GameEvent& e) { trace->push_back("startup-b:" + std::to_string(e.tick)); });
  auto c = bus.subscribe(EventPhase::simulation, 20,
    [trace](const GameEvent& e) { trace->push_back("sim-c:" + std::to_string(e.tick)); });
  auto d = bus.subscribe(EventPhase::teardown, 30,
    [trace](const GameEvent& e) { trace->push_back("teardown-d:" + std::to_string(e.tick)); });
  CHECK(std::holds_alternative<SubscriptionId>(a) && std::get<SubscriptionId>(a) == 1);
  CHECK(std::holds_alternative<SubscriptionId>(b) && std::get<SubscriptionId>(b) == 2);
  CHECK(std::holds_alternative<SubscriptionId>(c) && std::get<SubscriptionId>(c) == 3);
  CHECK(std::holds_alternative<SubscriptionId>(d) && std::get<SubscriptionId>(d) == 4);
  return bus;
}
}  // namespace

int main() {
  std::vector<std::string> trace;
  auto bus = configured(&trace);
  CHECK(bus.emit(event(EventPhase::startup, 0, 10)) == EventError::ok);
  CHECK(bus.emit(event(EventPhase::simulation, 1, 20)) == EventError::ok);
  CHECK(bus.emit(event(EventPhase::simulation, 2, 20)) == EventError::ok);
  CHECK(bus.emit(event(EventPhase::teardown, 3, 30)) == EventError::ok);
  CHECK(bus.emit(event(EventPhase::simulation, 1, 20)) == EventError::non_monotonic_tick);
  CHECK(bus.queued() == 4);
  const auto pre_dispatch_hash = bus.hash();
  const auto startup = bus.dispatch(EventPhase::startup, 0);
  const auto sim1 = bus.dispatch(EventPhase::simulation, 1);
  const auto sim2 = bus.dispatch(EventPhase::simulation, 2);
  const auto teardown = bus.dispatch(EventPhase::teardown, 3);
  CHECK((startup == std::vector<SubscriptionId>{1, 2}));
  CHECK((sim1 == std::vector<SubscriptionId>{3}));
  CHECK((sim2 == std::vector<SubscriptionId>{3}));
  CHECK((teardown == std::vector<SubscriptionId>{4}));
  const std::vector<std::string> expected{
    "startup-a:0", "startup-b:0", "sim-c:1", "sim-c:2", "teardown-d:3"};
  CHECK(trace == expected);
  CHECK(bus.queued() == 0);

  // Replay with the same subscription setup and event order is hash-identical.
  std::vector<std::string> replay_trace;
  auto replay = configured(&replay_trace);
  CHECK(replay.emit(event(EventPhase::startup, 0, 10)) == EventError::ok);
  CHECK(replay.emit(event(EventPhase::simulation, 1, 20)) == EventError::ok);
  CHECK(replay.emit(event(EventPhase::simulation, 2, 20)) == EventError::ok);
  CHECK(replay.emit(event(EventPhase::teardown, 3, 30)) == EventError::ok);
  CHECK(replay.hash() == pre_dispatch_hash);
  CHECK((replay.dispatch(EventPhase::startup, 0) == std::vector<SubscriptionId>{1, 2}));
  CHECK((replay.dispatch(EventPhase::simulation, 1) == std::vector<SubscriptionId>{3}));
  CHECK((replay.dispatch(EventPhase::simulation, 2) == std::vector<SubscriptionId>{3}));
  CHECK((replay.dispatch(EventPhase::teardown, 3) == std::vector<SubscriptionId>{4}));
  CHECK(replay_trace == expected);

  CHECK(bus.unsubscribe(4) == EventError::ok);
  CHECK(bus.unsubscribe(4) == EventError::unknown_subscription);
  CHECK(bus.emit(event(EventPhase::teardown, 4, 30)) == EventError::ok);
  CHECK(bus.dispatch(EventPhase::teardown, 4).empty());
  CHECK(bus.clear_phase(EventPhase::startup) == 2);
  CHECK((bus.subscriptions() == std::vector<SubscriptionId>{3}));
  CHECK(name(EventError::queue_full) == "queue_full" && name(EventPhase::teardown) == "teardown");

  if (failures) { std::fprintf(stderr, "%d MUT-54 check(s) failed\n", failures); return 1; }
  std::puts("PASS: lifecycle event order, subscriptions, teardown and replay");
  return 0;
}
