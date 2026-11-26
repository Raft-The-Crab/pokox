#pragma once

#include <cstdint>
#include <span>
#include <vector>

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"

namespace poko::physics {

// ENG-62: convex collision shape for the sim narrowphase. A shape is a set
// of world-space vertices plus an optional sphere-sweep radius, which
// covers every spec-24 sim primitive uniformly:
//   sphere   = 1 vertex (center) + radius
//   capsule  = 2 vertices (segment ends) + radius
//   AABB/box = 8 vertices, radius 0
//   hull     = up to 64 vertices, radius 0
// Vertices are stored in world space: the caller bakes position and
// orientation into the vertex list when building narrowphase inputs
// (per-tick transform application is O(vertices), trivial at <= 64).
// Spec "sphere and box fast paths" are covered by construction — a sphere
// support() scans one vertex, a box eight; dedicated analytic paths can
// replace the scan later without changing the narrowphase contract.
//
// Support function (spec-24 narrowphase): support(d) returns the point on
// the shape furthest along d — argmax over vertices of dot(v, d), plus
// radius * normalize(d). Deterministic: ties resolve to the lowest vertex
// index, and normalize() is the fixed-point routine from fixed_vec.hpp.
class ConvexShape {
 public:
  ConvexShape() = default;
  ConvexShape(std::vector<math::FixedVec3> vertices, math::Fixed radius)
      : vertices_(std::move(vertices)), radius_(radius) {}

  std::span<const math::FixedVec3> vertices() const noexcept {
    return vertices_;
  }
  math::Fixed radius() const noexcept { return radius_; }
  bool empty() const noexcept { return vertices_.empty(); }

  // Fails (returns nullopt) only when the shape has no vertices; a zero
  // direction degenerates to the +X axis so support is always defined.
  std::optional<math::FixedVec3> support(math::FixedVec3 dir) const;

 private:
  std::vector<math::FixedVec3> vertices_;
  math::Fixed radius_ = math::Fixed::zero();
};

}  // namespace poko::physics
