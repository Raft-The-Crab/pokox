// ENG-65: visual soft-body mass-spring lattice and cloth grid (Verlet).
#include "poko/physics/soft_body.hpp"

#if POKO_SOFT_BODY

#include <algorithm>
#include <cmath>

namespace poko::physics {
namespace {
using math::Vec3f;

float clamp01(float v) noexcept {
  return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v);
}
}  // namespace

std::optional<SoftBody> SoftBody::create_lattice(Vec3f origin,
                                                 std::uint32_t nx,
                                                 std::uint32_t ny,
                                                 std::uint32_t nz,
                                                 float spacing,
                                                 float stiffness) {
  if (nx == 0 || ny == 0 || nz == 0 || spacing <= 0.0f) return std::nullopt;
  const std::uint64_t total =
      static_cast<std::uint64_t>(nx) * ny * nz;
  if (total > kMaxSoftBodyNodes) return std::nullopt;

  SoftBody sb;
  sb.nodes_.reserve(static_cast<std::size_t>(total));
  auto idx = [&](std::uint32_t x, std::uint32_t y, std::uint32_t z) {
    return static_cast<std::uint16_t>((z * ny + y) * nx + x);
  };

  for (std::uint32_t z = 0; z < nz; ++z) {
    for (std::uint32_t y = 0; y < ny; ++y) {
      for (std::uint32_t x = 0; x < nx; ++x) {
        const Vec3f p = origin + Vec3f{static_cast<float>(x) * spacing,
                                       static_cast<float>(y) * spacing,
                                       static_cast<float>(z) * spacing};
        sb.add_node(p, 1.0f);
      }
    }
  }

  // Structural + face-diagonal shear springs for volume stability.
  for (std::uint32_t z = 0; z < nz; ++z) {
    for (std::uint32_t y = 0; y < ny; ++y) {
      for (std::uint32_t x = 0; x < nx; ++x) {
        const auto a = idx(x, y, z);
        if (x + 1 < nx) sb.add_spring(a, idx(x + 1, y, z), stiffness);
        if (y + 1 < ny) sb.add_spring(a, idx(x, y + 1, z), stiffness);
        if (z + 1 < nz) sb.add_spring(a, idx(x, y, z + 1), stiffness);
        if (x + 1 < nx && y + 1 < ny) {
          sb.add_spring(a, idx(x + 1, y + 1, z), stiffness);
          sb.add_spring(idx(x + 1, y, z), idx(x, y + 1, z), stiffness);
        }
        if (x + 1 < nx && z + 1 < nz) {
          sb.add_spring(a, idx(x + 1, y, z + 1), stiffness);
          sb.add_spring(idx(x + 1, y, z), idx(x, y, z + 1), stiffness);
        }
        if (y + 1 < ny && z + 1 < nz) {
          sb.add_spring(a, idx(x, y + 1, z + 1), stiffness);
          sb.add_spring(idx(x, y + 1, z), idx(x, y, z + 1), stiffness);
        }
      }
    }
  }
  return sb;
}

bool SoftBody::add_node(Vec3f position, float inv_mass) {
  if (nodes_.size() >= kMaxSoftBodyNodes) return false;
  SoftBodyNode n;
  n.position = position;
  n.prev_position = position;
  n.inv_mass = inv_mass;
  nodes_.push_back(n);
  return true;
}

bool SoftBody::add_spring(std::uint16_t a, std::uint16_t b, float stiffness) {
  if (a >= nodes_.size() || b >= nodes_.size() || a == b) return false;
  const float rest = math::length(nodes_[b].position - nodes_[a].position);
  springs_.push_back(
      SpringConstraint{a, b, rest, clamp01(stiffness)});
  return true;
}

void SoftBody::pin_node(std::uint16_t index, bool pinned) {
  if (index >= nodes_.size()) return;
  nodes_[index].inv_mass = pinned ? 0.0f : 1.0f;
}

void SoftBody::apply_acceleration(std::uint16_t index, Vec3f accel) {
  if (index >= nodes_.size()) return;
  nodes_[index].acceleration += accel;
}

void SoftBody::step(float dt_seconds, std::uint32_t constraint_iterations) {
  if (dt_seconds <= 0.0f) return;
  const float dt2 = dt_seconds * dt_seconds;
  const float damp = clamp01(damping_);

  for (auto& n : nodes_) {
    if (n.inv_mass <= 0.0f) {
      n.prev_position = n.position;
      n.acceleration = Vec3f::zero();
      continue;
    }
    const Vec3f vel = (n.position - n.prev_position) * damp;
    n.prev_position = n.position;
    n.position += vel + (gravity_ + n.acceleration) * dt2;
    n.acceleration = Vec3f::zero();
  }

  for (std::uint32_t it = 0; it < constraint_iterations; ++it) {
    for (const auto& s : springs_) {
      auto& na = nodes_[s.a];
      auto& nb = nodes_[s.b];
      const float w_sum = na.inv_mass + nb.inv_mass;
      if (w_sum <= 0.0f) continue;

      const Vec3f delta = nb.position - na.position;
      const float len = math::length(delta);
      if (len <= 1e-6f) continue;

      const float diff = (len - s.rest_length) / len;
      const Vec3f corr = delta * (diff * s.stiffness / w_sum);
      na.position += corr * na.inv_mass;
      nb.position -= corr * nb.inv_mass;
    }
  }
}

void SoftBody::collide_plane_y(float y) noexcept {
  for (auto& n : nodes_) {
    if (n.inv_mass <= 0.0f) continue;
    if (n.position.y < y) {
      n.position.y = y;
    }
  }
}

void SoftBody::collide_sphere(Vec3f center, float radius) noexcept {
  if (radius <= 0.0f) return;
  const float r2 = radius * radius;
  for (auto& n : nodes_) {
    if (n.inv_mass <= 0.0f) continue;
    const Vec3f d = n.position - center;
    const float dist2 = math::lengthSquared(d);
    if (dist2 < r2 && dist2 > 1e-12f) {
      const float dist = std::sqrt(dist2);
      n.position = center + d * (radius / dist);
    } else if (dist2 <= 1e-12f) {
      n.position = center + Vec3f{0.0f, radius, 0.0f};
    }
  }
}

std::optional<ClothGrid> ClothGrid::create(Vec3f origin,
                                           std::uint32_t cols,
                                           std::uint32_t rows,
                                           float spacing,
                                           float stiffness) {
  if (cols == 0 || rows == 0 || spacing <= 0.0f) return std::nullopt;
  const std::uint64_t total = static_cast<std::uint64_t>(cols) * rows;
  if (total > kMaxSoftBodyNodes) return std::nullopt;

  ClothGrid cloth;
  cloth.cols_ = cols;
  cloth.rows_ = rows;
  auto idx = [&](std::uint32_t c, std::uint32_t r) {
    return static_cast<std::uint16_t>(r * cols + c);
  };

  for (std::uint32_t r = 0; r < rows; ++r) {
    for (std::uint32_t c = 0; c < cols; ++c) {
      const Vec3f p = origin + Vec3f{static_cast<float>(c) * spacing,
                                     -static_cast<float>(r) * spacing,
                                     0.0f};
      cloth.body_.add_node(p, r == 0 ? 0.0f : 1.0f);
    }
  }

  for (std::uint32_t r = 0; r < rows; ++r) {
    for (std::uint32_t c = 0; c < cols; ++c) {
      const auto a = idx(c, r);
      if (c + 1 < cols) cloth.body_.add_spring(a, idx(c + 1, r), stiffness);
      if (r + 1 < rows) cloth.body_.add_spring(a, idx(c, r + 1), stiffness);
      if (c + 1 < cols && r + 1 < rows) {
        cloth.body_.add_spring(a, idx(c + 1, r + 1), stiffness * 0.8f);
        cloth.body_.add_spring(idx(c + 1, r), idx(c, r + 1), stiffness * 0.8f);
      }
    }
  }
  return cloth;
}

void ClothGrid::pin_node(std::uint32_t col, std::uint32_t row, bool pinned) {
  if (col >= cols_ || row >= rows_) return;
  body_.pin_node(static_cast<std::uint16_t>(row * cols_ + col), pinned);
}

void ClothGrid::step(float dt_seconds, float sim_time_seconds, Vec3f wind_dir,
                     float wind_strength,
                     std::uint32_t constraint_iterations) {
  const Vec3f dir = math::normalized(wind_dir);
  if (wind_strength != 0.0f && math::lengthSquared(dir) > 0.0f) {
    const std::size_t n = body_.node_count();
    for (std::size_t i = 0; i < n; ++i) {
      const float phase = static_cast<float>(i) * 0.37f;
      const float gust =
          0.7f + 0.3f * std::sin(sim_time_seconds * 2.5f + phase);
      body_.apply_acceleration(static_cast<std::uint16_t>(i),
                               dir * (wind_strength * gust));
    }
  }
  body_.step(dt_seconds, constraint_iterations);
}

}  // namespace poko::physics

#endif  // POKO_SOFT_BODY
