#include "poko/mute/events.hpp"

#include <algorithm>
#include <utility>

namespace poko::mute {
namespace {
constexpr std::uint64_t kFnvOffset = 14695981039346656037ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void mix(std::uint64_t& h, std::uint64_t value) noexcept {
  h ^= value;
  h *= kFnvPrime;
}
}  // namespace

EventResult<SubscriptionId> EventBus::subscribe(EventPhase phase, std::uint32_t type,
                                                EventHandler handler) {
  if (subscriptions_.size() >= max_subscriptions) return EventError::queue_full;
  if (!handler) return EventError::duplicate_subscription;
  subscriptions_.push_back({next_id_, phase, type, std::move(handler)});
  return next_id_++;
}

EventError EventBus::unsubscribe(SubscriptionId id) noexcept {
  const auto at = std::find_if(subscriptions_.begin(), subscriptions_.end(),
                               [&](const auto& s) { return s.id == id; });
  if (at == subscriptions_.end()) return EventError::unknown_subscription;
  subscriptions_.erase(at);
  return EventError::ok;
}

std::size_t EventBus::clear_phase(EventPhase phase) noexcept {
  const auto before = subscriptions_.size();
  subscriptions_.erase(
    std::remove_if(subscriptions_.begin(), subscriptions_.end(),
                   [&](const auto& s) { return s.phase == phase; }),
    subscriptions_.end());
  return before - subscriptions_.size();
}

EventError EventBus::emit(GameEvent event) {
  if (event.tick < last_tick_) return EventError::non_monotonic_tick;
  if (queue_.size() >= max_events) return EventError::queue_full;
  last_tick_ = event.tick;
  queue_.push_back(event);
  ++sequence_;
  return EventError::ok;
}

std::vector<SubscriptionId> EventBus::dispatch(EventPhase phase, std::uint64_t up_to_tick) {
  std::vector<SubscriptionId> delivered;
  std::vector<GameEvent> remaining;
  remaining.reserve(queue_.size());
  for (const auto& event : queue_) {
    if (event.phase != phase || event.tick > up_to_tick) {
      remaining.push_back(event);
      continue;
    }
    // subscriptions_ is kept in ascending id order exactly as delivered.
    for (const auto& sub : subscriptions_)
      if (sub.phase == event.phase && sub.type == event.type) {
        sub.handler(event);
        delivered.push_back(sub.id);
      }
  }
  queue_ = std::move(remaining);
  return delivered;
}

std::vector<SubscriptionId> EventBus::subscriptions() const {
  std::vector<SubscriptionId> ids;
  ids.reserve(subscriptions_.size());
  for (const auto& s : subscriptions_) ids.push_back(s.id);
  return ids;
}

std::uint64_t EventBus::hash() const noexcept {
  std::uint64_t h = kFnvOffset;
  mix(h, last_tick_);
  mix(h, sequence_);
  for (const auto& s : subscriptions_) {
    mix(h, s.id);
    mix(h, static_cast<std::uint8_t>(s.phase));
    mix(h, s.type);
    h ^= s.handler ? 1u : 0u;
    h *= kFnvPrime;
  }
  for (const auto& e : queue_) {
    mix(h, static_cast<std::uint8_t>(e.phase));
    mix(h, e.tick);
    mix(h, e.type);
    mix(h, e.source);
    for (const auto value : e.payload) mix(h, static_cast<std::uint64_t>(static_cast<std::int64_t>(value)));
  }
  return h;
}

std::string_view name(EventError error) noexcept {
  switch (error) {
    case EventError::ok: return "ok";
    case EventError::duplicate_subscription: return "duplicate_subscription";
    case EventError::unknown_subscription: return "unknown_subscription";
    case EventError::non_monotonic_tick: return "non_monotonic_tick";
    case EventError::queue_full: return "queue_full";
  }
  return {};
}

std::string_view name(EventPhase phase) noexcept {
  switch (phase) {
    case EventPhase::startup: return "startup";
    case EventPhase::simulation: return "simulation";
    case EventPhase::teardown: return "teardown";
  }
  return {};
}

}  // namespace poko::mute
