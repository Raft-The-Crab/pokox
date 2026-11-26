#pragma once

#include <array>
#include <cstdint>

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"
#include "poko/physics/convex_shape.hpp"

namespace poko::physics {

// ENG-62 / spec 24 "Narrowphase": GJK distance + EPA penetration for
// convex-convex pairs, producing a deterministic contact manifold.
//
// Determinism contract:
//   - All arithmetic is Q16.16 Fixed; no float, no libm, fixed iteration
//     caps (GJK 64, EPA 64) with geometric termination — never
//     convergence-count dependent.
//   - Manifold points are sorted by (penetration depth, witness
//     coordinates) — "stable contact order" per the ENG-62 acceptance.
//   - Contact points are genuine touch pairs (a on A's surface, b on B's)
//     recovered from EPA face barycentrics; coincident points closer than
//     the fixed merge tolerance are merged.
//   - normal points from B toward A (the direction that separates B
//     from A); depth is the EPA penetration distance >= 0.
struct ContactPoint {
  math::FixedVec3 point_a;  // on shape A
  math::FixedVec3 point_b;  // on shape B
};

struct ContactManifold {
  bool touching = false;
  math::Fixed depth = math::Fixed::zero();
  math::FixedVec3 normal = math::FixedVec3{};  // B -> A
  std::array<ContactPoint, 4> points{};
  std::uint8_t count = 0;
};

// Narrowphase entry point. Shapes are world-space (see ConvexShape).
// touching=false means separated (or degenerate); depth/normal/points are
// then meaningless. At most 4 manifold points, always sorted.
ContactManifold collide(const ConvexShape& a, const ConvexShape& b);

}  // namespace poko::physics
