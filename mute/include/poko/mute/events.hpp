#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {

// MUT-54: tick-tagged lifecycle/game event dispatch. Delivery order is part
// of the replay contract: events are FIFO by (tick, emit sequence), and
// subscribers for one phase/type are called in ascending subscription id.
// No wall clock, thread scheduling or unbounded queue is exposed.
enum class EventPhase : std::uint8_t { startup = 1, simulation = 2, teardown = 3 };

struct GameEvent {
  EventPhase phase{EventPhase::simulation};
  std::uint64_t tick{0};
  std::uint32_t type{0};
  std::uint32_t source{0};
  std::array<std::int32_t, 4> payload{};
};

using EventHandler = std::function<void(const GameEvent&)>;
using SubscriptionId = std::uint32_t;

enum class EventError { ok, duplicate_subscription, unknown_subscription, non_monotonic_tick, queue_full };

template <class T>
using EventResult = std::variant<T, EventError>;

class EventBus {
 public:
  static constexpr std::size_t max_events = 4'096;
  static constexpr std::size_t max_subscriptions = 1'024;

  [[nodiscard]] EventResult<SubscriptionId> subscribe(EventPhase phase, std::uint32_t type,
                                                      EventHandler handler);
  [[nodiscard]] EventError unsubscribe(SubscriptionId id) noexcept;
  [[nodiscard]] std::size_t clear_phase(EventPhase phase) noexcept;
  [[nodiscard]] EventError emit(GameEvent event);

  // Delivers queued events of `phase` with tick <= up_to_tick. Returns the
  // subscription ids in exact delivery order for replay verification.
  [[nodiscard]] std::vector<SubscriptionId> dispatch(EventPhase phase, std::uint64_t up_to_tick);

  [[nodiscard]] std::size_t queued() const noexcept { return queue_.size(); }
  [[nodiscard]] std::vector<SubscriptionId> subscriptions() const;
  [[nodiscard]] std::uint64_t hash() const noexcept;

 private:
  struct Subscription {
    SubscriptionId id{0};
    EventPhase phase{EventPhase::simulation};
    std::uint32_t type{0};
    EventHandler handler;
  };

  std::vector<Subscription> subscriptions_;
  std::vector<GameEvent> queue_;
  SubscriptionId next_id_{1};
  std::uint64_t last_tick_{0};
  std::uint64_t sequence_{0};
};

[[nodiscard]] std::string_view name(EventError error) noexcept;
[[nodiscard]] std::string_view name(EventPhase phase) noexcept;

}  // namespace poko::mute
