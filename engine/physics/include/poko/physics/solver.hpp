#pragma once

#include <cstdint>
#include <map>
#include <set>
#include <span>
#include <vector>

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"

namespace poko::physics {

// ENG-63 / spec 24 "Constraint solver" + spec 21 job-system rules:
// sequential impulse with warm starting and Baumgarte stabilization.
//
// Scope of THIS milestone (limitations are contractual — see
// docs/eng-progress.md ENG-63 entry):
//   - Translational dynamics only. Bodies carry mass/invMass and linear
//     velocity; there is NO angular velocity, inertia tensor or torque.
//     Rotational contacts are approximated as point contacts at the
//     manifold witness — correct for spheres, approximate for boxes/hulls.
//   - No sleep/wake, no split impulses, no joint constraints, no island
//     parallelism. Islands ARE computed (union-find over contacts) and
//     solved in island-id order with constraints sorted by body index —
//     that part of the determinism contract is implemented.
//   - Iteration count is fixed per solve() call (default 8 = spec sim
//     default); there is no convergence-based early exit.
//   - Warm-start impulse caches persist across solve() calls keyed by the
//     caller-supplied contact_key; a key that disappears has its cache
//     entry evicted deterministically at the next solve(). Keys must be
//     unique within one step's contact set (e.g. pair key + point index).
//   - All arithmetic is Q16.16 Fixed; friction/restitution are Fixed
//     coefficients; no float anywhere in the solve path.
struct SimBody {
  std::uint32_t index = 0;
  math::FixedVec3 position = math::FixedVec3::zero();
  math::FixedVec3 velocity = math::FixedVec3::zero();
  // inv_mass is the only stored mass quantity (review L2: separate `mass`
  // and `inv_mass` fields drifted apart silently). 0 = infinite mass.
  math::Fixed inv_mass = math::Fixed::one();  // caller sets 0 for static
  // ENG-64: kinematic bodies have inv_mass = 0 (infinite mass — solver
  // impulses never change their velocity) but DO integrate under their
  // velocity, unlike static bodies. Used by the character controller,
  // which drives movement as a velocity target through the solver.
  bool kinematic = false;

  // Derived mass; zero means infinite (static or kinematic).
  math::Fixed mass() const noexcept {
    return inv_mass.is_zero()
               ? math::Fixed::zero()
               : math::divide(math::Fixed::one(), inv_mass).value_or(math::Fixed::zero());
  }
  // Sets inv_mass = 1/m; m <= 0 makes the body infinitely massive.
  void set_mass(math::Fixed m) noexcept {
    inv_mass = m > math::Fixed::zero()
                   ? math::divide(math::Fixed::one(), m).value_or(math::Fixed::zero())
                   : math::Fixed::zero();
  }
};

// One contact point constraint derived from a narrowphase manifold.
// normal points from B to A (same convention as ContactManifold).
// point_a/point_b are carried for the future rotational solve; the
// translational solver does not use them (lever arms need inertia).
// Mass comes from the referenced SimBody::inv_mass — there is no
// per-constraint mass override.
struct ContactConstraint {
  std::uint64_t key = 0;        // warm-start cache identity (caller-stable)
  std::uint32_t body_a = 0;     // index into solver bodies
  std::uint32_t body_b = 0;
  math::FixedVec3 normal;       // B -> A, normalized by the solver
  math::FixedVec3 point_a;      // world witness on A (unused translational)
  math::FixedVec3 point_b;      // world witness on B (unused translational)
  math::Fixed depth = math::Fixed::zero();   // penetration >= 0
  math::Fixed friction = math::Fixed::zero();
  math::Fixed restitution = math::Fixed::zero();
};

class SequentialImpulseSolver {
 public:
  // spec default: 8 iterations for sim.
  static constexpr std::uint32_t kDefaultIterations = 8;

  // Register/replace a dynamic body. Static bodies use inv_mass = 0.
  void upsert_body(const SimBody& body);
  void remove_body(std::uint32_t index);
  void clear() noexcept;

  // Queue this tick's contacts (from narrowphase manifolds). Contact
  // indices must reference bodies already upserted. Returns false and
  // drops the contact when body_a == body_b or when `key` was already
  // added this step (it would silently share one warm-start cache entry).
  void begin_step();
  bool add_contact(const ContactConstraint& c);
  // Run the sequential impulse solve. Contacts and bodies are read
  // post-solve; positions are NOT integrated here — call integrate().
  void solve(math::Fixed dt_seconds,
             std::uint32_t iterations = kDefaultIterations);
  // position += velocity * dt for every non-static body. Deterministic.
  // The add saturates per axis at the Q16.16 range (+-32768 units): a body
  // pushed past the world edge clamps there instead of wrapping to the
  // opposite side (Fixed +/- itself wraps, per spec 24).
  void integrate(math::Fixed dt_seconds) noexcept;

  const SimBody* find_body(std::uint32_t index) const noexcept;
  std::size_t body_count() const noexcept { return bodies_.size(); }
  std::size_t contact_count() const noexcept { return contacts_.size(); }

 private:
  // Accumulated impulses (normal + two friction tangents) for one
  // contact, persisted across solve() calls keyed by contact_key.
  struct ImpulseCache {
    math::Fixed normal = math::Fixed::zero();
    math::Fixed tangent1 = math::Fixed::zero();
    math::Fixed tangent2 = math::Fixed::zero();
  };

  std::vector<SimBody> bodies_;                    // sorted by index
  std::vector<ContactConstraint> contacts_;        // sorted canonically
  std::map<std::uint64_t, ImpulseCache> warm_;     // persists across steps
  std::set<std::uint64_t> step_keys_;              // keys added this step
};

}  // namespace poko::physics
