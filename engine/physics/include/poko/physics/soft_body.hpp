#pragma once

#include "poko/foundation/build_flags.hpp"

#if POKO_SOFT_BODY

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include "poko/foundation/vec3f.hpp"

namespace poko::physics {

// ENG-65 / spec 24 "Soft body and cloth (AAA partial)" — VISUAL physics
// path only (f32, Verlet integration, mass-spring lattice and cloth grid).
// Feature-flagged via POKO_SOFT_BODY. Hard limit: 256 nodes per body.
// Never feeds validated/ServerOwned state (types are f32 Vec3f only).
inline constexpr std::size_t kMaxSoftBodyNodes = 256;

struct SoftBodyNode {
  math::Vec3f position = math::Vec3f::zero();
  math::Vec3f prev_position = math::Vec3f::zero();
  math::Vec3f acceleration = math::Vec3f::zero();
  float inv_mass = 1.0f;  // 0 = pinned
};

struct SpringConstraint {
  std::uint16_t a = 0;
  std::uint16_t b = 0;
  float rest_length = 0.0f;
  float stiffness = 0.8f;  // (0, 1] Verlet distance-relaxation factor
};

class SoftBody {
 public:
  static constexpr std::uint32_t kDefaultConstraintIterations = 6;

  // Creates a 3D mass-spring lattice (nx * ny * nz nodes). Returns nullopt
  // if dimensions are 0 or node count exceeds kMaxSoftBodyNodes (256).
  static std::optional<SoftBody> create_lattice(math::Vec3f origin,
                                                std::uint32_t nx,
                                                std::uint32_t ny,
                                                std::uint32_t nz,
                                                float spacing,
                                                float stiffness = 0.8f);

  bool add_node(math::Vec3f position, float inv_mass = 1.0f);
  bool add_spring(std::uint16_t a, std::uint16_t b, float stiffness = 0.8f);
  void pin_node(std::uint16_t index, bool pinned = true);
  void apply_acceleration(std::uint16_t index, math::Vec3f accel);

  void set_gravity(math::Vec3f g) noexcept { gravity_ = g; }
  math::Vec3f gravity() const noexcept { return gravity_; }
  void set_damping(float d) noexcept { damping_ = d; }
  float damping() const noexcept { return damping_; }

  void step(float dt_seconds,
            std::uint32_t constraint_iterations = kDefaultConstraintIterations);
  void collide_plane_y(float y) noexcept;
  void collide_sphere(math::Vec3f center, float radius) noexcept;

  std::size_t node_count() const noexcept { return nodes_.size(); }
  std::size_t spring_count() const noexcept { return springs_.size(); }
  const std::vector<SoftBodyNode>& nodes() const noexcept { return nodes_; }
  std::vector<SoftBodyNode>& nodes() noexcept { return nodes_; }
  const std::vector<SpringConstraint>& springs() const noexcept {
    return springs_;
  }

 private:
  std::vector<SoftBodyNode> nodes_;
  std::vector<SpringConstraint> springs_;
  math::Vec3f gravity_{0.0f, -9.81f, 0.0f};
  float damping_ = 0.99f;
};

// 2D cloth grid (cols * rows <= kMaxSoftBodyNodes) with structural + shear
// springs and wind driven by sim time.
class ClothGrid {
 public:
  static std::optional<ClothGrid> create(math::Vec3f origin,
                                         std::uint32_t cols,
                                         std::uint32_t rows,
                                         float spacing,
                                         float stiffness = 0.85f);

  void pin_node(std::uint32_t col, std::uint32_t row, bool pinned = true);
  void step(float dt_seconds, float sim_time_seconds, math::Vec3f wind_dir,
            float wind_strength,
            std::uint32_t constraint_iterations =
                SoftBody::kDefaultConstraintIterations);

  std::uint32_t cols() const noexcept { return cols_; }
  std::uint32_t rows() const noexcept { return rows_; }
  const SoftBody& body() const noexcept { return body_; }
  SoftBody& body() noexcept { return body_; }

 private:
  std::uint32_t cols_ = 0;
  std::uint32_t rows_ = 0;
  SoftBody body_;
};

}  // namespace poko::physics

#endif  // POKO_SOFT_BODY
