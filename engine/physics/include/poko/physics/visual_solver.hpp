#pragma once

#include <cstdint>
#include <map>
#include <set>
#include <span>
#include <vector>

#include "poko/foundation/vec3f.hpp"

namespace poko::physics {

// ENG-65 / spec 24 "Two solvers, one contract" — VISUAL physics path:
// f32, client-only, trusted cosmetic state. This is a SEPARATE solver
// from the Q16.16 sim path (solver.hpp): the types below share no
// representation with SimBody/FixedVec3, so visual results cannot be
// written into validated state by construction. The mute/compiler half
// of "cannot write validated state" (ServerOwned binding rejection) is
// MUT-42 scope; the engine half is this type split.
//
// Scope (limitations contractual):
//   - Translational dynamics only — no rotation/inertia (same v1 scope
//     as the sim solver).
//   - Shapes: sphere and axis-aligned box. No oriented boxes, hulls or
//     meshes — visual proxies stay cheap.
//   - Dynamic-dynamic contacts: all shape pairs reduce to sphere-vs-AABB
//     or AABB-vs-AABB analytic tests (single-point manifolds).
//   - Warm starting and Baumgarte stabilization mirror the sim solver;
//     iteration count is fixed (default 12 = spec visual default).
//   - f32 throughout: results are NOT bit-deterministic across platforms
//     and must never feed validated state.
enum class VisualShape : std::uint8_t { kSphere = 0, kBox = 1 };

struct VisualBody {
  std::uint32_t index = 0;
  VisualShape shape = VisualShape::kSphere;
  math::Vec3f position = math::Vec3f::zero();  // sphere center / box center
  math::Vec3f velocity = math::Vec3f::zero();
  math::Vec3f half_extents{0.5f, 0.5f, 0.5f};   // kBox only (AABB)
  float radius = 0.5f;                          // kSphere only
  float inv_mass = 1.0f;   // 0 = static; kinematic flag moves it anyway
  bool kinematic = false;  // inv_mass = 0 but integrates under velocity
  float restitution = 0.0f;
  float friction = 0.5f;
};

// One contact point. normal points from B to A (same convention as the
// sim ContactManifold). point is a single world-space witness — the
// translational solver does not need lever arms.
struct VisualContact {
  std::uint64_t key = 0;        // warm-start cache identity (caller-stable)
  std::uint32_t body_a = 0;
  std::uint32_t body_b = 0;
  math::Vec3f normal;
  math::Vec3f point = math::Vec3f::zero();
  float depth = 0.0f;
  float friction = 0.5f;
  float restitution = 0.0f;
};

class VisualSolver {
 public:
  // spec default: 12 iterations for visual (vs 8 for sim).
  static constexpr std::uint32_t kDefaultIterations = 12;

  void upsert_body(const VisualBody& body);
  void remove_body(std::uint32_t index);
  void clear() noexcept;

  void begin_step();
  // Same rules as SequentialImpulseSolver::add_contact: self-contacts and
  // keys already added this step are dropped and return false.
  bool add_contact(const VisualContact& c);
  void solve(float dt_seconds,
             std::uint32_t iterations = kDefaultIterations);
  void integrate(float dt_seconds) noexcept;

  const VisualBody* find_body(std::uint32_t index) const noexcept;
  const std::vector<VisualBody>& bodies() const noexcept { return bodies_; }
  std::size_t contact_count() const noexcept { return contacts_.size(); }

 private:
  struct ImpulseCache {
    float normal = 0.0f;
    float tangent1 = 0.0f;
    float tangent2 = 0.0f;
  };

  std::vector<VisualBody> bodies_;                    // sorted by index
  std::vector<VisualContact> contacts_;               // canonical order
  std::map<std::uint64_t, ImpulseCache> warm_;        // persists across steps
  std::set<std::uint64_t> step_keys_;                 // keys added this step
};

// Analytic f32 narrowphase for the supported shape set. All functions
// return true and fill `out` (key/body indices/friction/restitution
// copied from the inputs) when the shapes overlap; false when separated.
// `a`/`b` are the colliding bodies; the contact normal points B -> A.
bool collide_visual(const VisualBody& a, const VisualBody& b,
                    VisualContact& out);

// Convenience world: owns bodies + static colliders, generates contacts
// each step (dynamics vs statics and dynamics vs dynamics, sorted pair
// order), applies gravity, solves and integrates. For client-side
// cosmetic debris, particles and proxy rigid bodies.
class VisualWorld {
 public:
  // Registers a body. inv_mass = 0 bodies act as static colliders unless
  // kinematic = true. Returns the body index (caller-assigned or
  // auto-assigned when index == 0 is not desired — see below).
  std::uint32_t add_body(VisualBody body);
  // Static axis-aligned box collider shortcut.
  std::uint32_t add_collider(math::Vec3f center, math::Vec3f half_extents);

  void set_gravity(math::Vec3f g) noexcept { gravity_ = g; }
  math::Vec3f gravity() const noexcept { return gravity_; }

  // One visual step: gravity -> narrowphase -> solve(12) -> integrate.
  void step(float dt_seconds);

  const VisualBody* find_body(std::uint32_t index) const noexcept;
  VisualBody* find_body(std::uint32_t index) noexcept;
  std::size_t body_count() const noexcept { return bodies_.size(); }
  std::size_t collider_count() const noexcept { return colliders_.size(); }

 private:
  std::vector<VisualBody> bodies_;       // dynamic + kinematic, index order
  std::vector<std::uint32_t> dynamics_;  // indices with inv_mass != 0
  std::vector<VisualBody> colliders_;    // static AABBs (inv_mass = 0)
  VisualSolver solver_;
  math::Vec3f gravity_{0.0f, -9.81f, 0.0f};
  std::uint32_t next_auto_index_ = 1;
};

}  // namespace poko::physics
