#include "poko/physics/convex_shape.hpp"

namespace poko::physics {

std::optional<math::FixedVec3> ConvexShape::support(math::FixedVec3 dir) const {
  if (vertices_.empty()) return std::nullopt;
  math::Fixed best_dot = math::dot(vertices_[0], dir);
  std::size_t best = 0;
  for (std::size_t i = 1; i < vertices_.size(); ++i) {
    const math::Fixed d = math::dot(vertices_[i], dir);
    if (d > best_dot) {  // strict > keeps the lowest index on ties
      best_dot = d;
      best = i;
    }
  }
  math::FixedVec3 point = vertices_[best];
  if (!radius_.is_zero()) {
    if (auto unit = math::normalized(dir)) point = point + *unit * radius_;
    // zero dir: normalized() is nullopt; the vertex itself is the support
  }
  return point;
}

}  // namespace poko::physics
