#pragma once

#include <cstdint>
#include <span>
#include <vector>

#include "poko/foundation/fixed_vec.hpp"

namespace poko::physics {

// ENG-61 / spec 24 "Broadphase": sweep-and-prune on the X axis with sorted
// pair output. Bodies carry an axis-aligned bounds volume; only the X
// interval participates in the sweep (Y/Z culling is the narrowphase's
// job). All arithmetic is Q16.16 Fixed — no float in the sim path.
//
// Determinism contract:
//   - Bodies are identified by a caller-assigned u32 index (the future ECS
//     entity index). The broadphase never invents ordering: bodies_ is
//     kept sorted by index and every sort below uses a strict total order
//     with index tie-breaks, so results cannot depend on insertion order,
//     command order across ticks, or thread scheduling.
//   - insert()/remove() are a deterministic command buffer: they queue
//     commands applied in submission order by commit(). insert on a live
//     index replaces its bounds (upsert); remove of an absent index is a
//     no-op. pairs() reflects the last commit() only.
//   - Pairs are axis-overlap candidates on X, emitted once each as
//     (min(index), max(index)), and the final list is sorted by (a, b).
//     Touching intervals count as overlapping (max_x == min_x pairs).
//   - Endpoint ties at equal X order min-endpoints before max-endpoints
//     (inclusive overlap) and then by body index, so the sweep is total.
//
// Spec note: endpoints are fully re-sorted each commit rather than
// incrementally; the pair set is identical either way, and incremental
// resort is a pure performance optimization deferred until profiling
// demands it (spec body cap is 512, so O(n log n) per tick is cheap).
class SapBroadphase {
 public:
  // Axis-aligned bounds. lower/upper are normalized component-wise on
  // insert, so callers may pass corners in any order.
  struct Bounds {
    math::FixedVec3 lower;
    math::FixedVec3 upper;
  };

  // One overlapping X-interval pair; a < b always.
  struct Pair {
    std::uint32_t a;
    std::uint32_t b;
    constexpr bool operator==(const Pair& o) const noexcept {
      return a == o.a && b == o.b;
    }
    constexpr auto operator<=>(const Pair& o) const noexcept {
      if (a != o.a) return a <=> o.a;
      return b <=> o.b;
    }
  };

  // Queue a body insert or bounds replacement. Applied at commit().
  void insert(std::uint32_t index, const Bounds& bounds);
  // Queue a body removal. Applied at commit(); absent index is a no-op.
  void remove(std::uint32_t index);
  // Apply queued commands in order, re-sort endpoints, rebuild pairs_.
  void commit();
  // Drop all bodies, queued commands and pairs.
  void clear() noexcept;

  std::span<const Pair> pairs() const noexcept { return pairs_; }
  std::size_t body_count() const noexcept { return bodies_.size(); }

 private:
  struct Body {
    std::uint32_t index;
    math::FixedVec3 lower;
    math::FixedVec3 upper;
  };
  struct Command {
    enum class Kind : std::uint8_t { insert, remove };
    Kind kind;
    std::uint32_t index;
    Bounds bounds;
  };
  struct Endpoint {
    math::Fixed x;
    std::uint32_t slot;   // position in bodies_
    bool is_min;
  };

  std::vector<Body> bodies_;       // sorted by index
  std::vector<Command> commands_;  // FIFO, applied at commit()
  std::vector<Pair> pairs_;
};

}  // namespace poko::physics
