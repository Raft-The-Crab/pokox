#include "poko/physics/sap_broadphase.hpp"

#include <algorithm>

namespace poko::physics {

void SapBroadphase::insert(std::uint32_t index, const Bounds& bounds) {
  commands_.push_back(Command{Command::Kind::insert, index, bounds});
}

void SapBroadphase::remove(std::uint32_t index) {
  commands_.push_back(Command{Command::Kind::remove, index, Bounds{}});
}

void SapBroadphase::commit() {
  for (const Command& cmd : commands_) {
    const auto it = std::lower_bound(
        bodies_.begin(), bodies_.end(), cmd.index,
        [](const Body& b, std::uint32_t i) { return b.index < i; });
    if (cmd.kind == Command::Kind::remove) {
      if (it != bodies_.end() && it->index == cmd.index) bodies_.erase(it);
      continue;
    }
    // Normalized component-wise so min <= max on every axis regardless of
    // the corner order the caller supplied.
    const math::FixedVec3 lower =
        math::min(cmd.bounds.lower, cmd.bounds.upper);
    const math::FixedVec3 upper =
        math::max(cmd.bounds.lower, cmd.bounds.upper);
    if (it != bodies_.end() && it->index == cmd.index) {
      it->lower = lower;
      it->upper = upper;
    } else {
      bodies_.insert(it, Body{cmd.index, lower, upper});
    }
  }
  commands_.clear();

  // Endpoint sort key: (x, min-before-max, body slot). bodies_ is sorted
  // by index, so slot order is index order — every comparison is a strict
  // total order and the sweep cannot depend on insertion history.
  std::vector<Endpoint> endpoints;
  endpoints.reserve(bodies_.size() * 2);
  for (std::uint32_t slot = 0; slot < bodies_.size(); ++slot) {
    const Body& b = bodies_[slot];
    endpoints.push_back(Endpoint{b.lower.x, slot, true});
    endpoints.push_back(Endpoint{b.upper.x, slot, false});
  }
  std::sort(endpoints.begin(), endpoints.end(),
            [](const Endpoint& a, const Endpoint& b) {
              if (a.x != b.x) return a.x < b.x;
              if (a.is_min != b.is_min) return a.is_min;  // mins first: inclusive
              return a.slot < b.slot;
            });

  pairs_.clear();
  std::vector<std::uint32_t> active;  // slots whose min seen, max not yet
  active.reserve(bodies_.size());
  for (const Endpoint& ep : endpoints) {
    if (ep.is_min) {
      const std::uint32_t hi_index = bodies_[ep.slot].index;
      for (const std::uint32_t a_slot : active) {
        const std::uint32_t a_index = bodies_[a_slot].index;
        pairs_.push_back(
            a_index < hi_index ? Pair{a_index, hi_index}
                               : Pair{hi_index, a_index});
      }
      active.push_back(ep.slot);
    } else {
      const auto it = std::find(active.begin(), active.end(), ep.slot);
      if (it != active.end()) active.erase(it);
    }
  }
  std::sort(pairs_.begin(), pairs_.end());
}

void SapBroadphase::clear() noexcept {
  bodies_.clear();
  commands_.clear();
  pairs_.clear();
}

}  // namespace poko::physics
