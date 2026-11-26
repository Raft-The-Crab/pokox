#pragma once

#include <cstdint>
#include <cstddef>
#include <span>
#include <unordered_map>
#include <vector>

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"
#include "poko/physics/convex_shape.hpp"
#include "poko/physics/narrowphase.hpp"
#include "poko/physics/solver.hpp"

namespace poko::physics {

// ENG-64 / spec 24 "Character controller": kinematic capsule driven through
// the sim solver as a velocity target — never by direct position writes
// outside this class. All arithmetic is Q16.16 Fixed.
//
// Contract (spec 24 + 05-pkb-validation "position_step"):
//   - The controlled SimBody must be registered with inv_mass = 0 and
//     kinematic = true: infinite mass for the solver (impulses never
//     change its velocity) but still integrated under its velocity.
//   - Movement is applied by writing the body's velocity target once per
//     tick in update() (pre-solve). The solver then resolves contacts
//     normally; dynamic bodies are pushed, the character is not.
//   - The ONLY positional writes the controller performs are bounded
//     corrections: the step-up lift in update() (exactly step_height,
//     once per tick, only when the lifted-path probe passes — applied as
//     a position delta, NOT a velocity, because a one-tick
//     vy = step_height/dt would persist as body velocity) and the
//     depenetration push in resolve() (post-integrate), capped per tick
//     by params.max_depenetration. Callers that keep move_speed,
//     step_height and max_depenetration inside their declared
//     "position_step" rule budget get rule-consistent motion; the engine
//     cannot enforce the pkB rule itself (that is MUT-side validation).
//   - "A direct position set outside the controller is rejected by the
//     authority" is an authority/policy rule (MUT-42); at engine level
//     this class simply offers no raw position API — position changes
//     flow through update()/resolve() only.
//
// Determinism: fixed cast substeps + fixed bisection iterations, colliders
// scanned in caller-supplied (index-sorted) order, all Fixed math.
struct CharacterParams {
  math::Fixed radius = math::Fixed::from_raw(26214);        // 0.4
  math::Fixed half_length = math::Fixed::from_raw(19660);   // 0.3 segment half
  math::Fixed move_speed = math::Fixed::from_raw(393216);   // 6.0 u/s
  math::Fixed jump_speed = math::Fixed::from_raw(655360);   // 10.0 u/s
  math::Fixed gravity = math::Fixed::from_raw(642253);      // ~9.8 u/s^2
  math::Fixed ground_distance = math::Fixed::from_raw(131072);  // 2.0
  math::Fixed step_height = math::Fixed::from_raw(32768);   // 0.5
  // Walkable when ground normal.y >= slope_cos (cos of max slope angle).
  math::Fixed slope_cos = math::Fixed::from_raw(46341);     // ~0.707 (45 deg)
  math::Fixed max_depenetration = math::Fixed::from_raw(13107);  // 0.2
};

// Cast-path touch memo. The controller's shape-cast boolean ("does this
// translated pose touch any collider?") is a pure function of the exact
// Fixed values of the pose, the colliders and the depth threshold:
// narrowphase collide() is deterministic fixed-point. Standing on ground
// or wedged against a wall re-queries byte-identical poses every tick,
// and each re-query costs a full GJK+EPA — the dominant cast-path cost.
// Keys are the exact raw values (never pointers or identities), so a hit
// returns the same answer the recompute would: results are bit-identical.
struct TouchCacheKey {
  std::size_t hash = 0;               // FNV-1a over raws; raws still compared
  std::vector<std::int32_t> raws;     // min_depth, shape, colliders — exact
};
struct TouchCacheEntry {
  TouchCacheKey key;
  bool touching = false;
};
struct TouchCache {
  std::unordered_map<std::size_t, std::vector<TouchCacheEntry>> buckets;
  std::size_t entries = 0;
};

class CharacterController {
 public:
  CharacterController(std::uint32_t body_index, CharacterParams params)
      : body_index_(body_index), params_(params) {}

  std::uint32_t body_index() const noexcept { return body_index_; }
  const CharacterParams& params() const noexcept { return params_; }

  // World-space capsule for a body position: vertical segment
  // position +/- half_length on Y plus sweep radius.
  static ConvexShape capsule_at(math::FixedVec3 position,
                                const CharacterParams& params);

  // PRE-SOLVE, once per tick. Reads the body, runs ground detection
  // (downward shape cast), slope classification, horizontal wall/slide
  // casts and the step-up probe against `colliders` (world-space convex
  // shapes in deterministic index order), then writes the velocity
  // target back through solver.upsert_body. wish_dir is a desired planar
  // (XZ) direction; it is normalized here — callers may pass unnormalized
  // input. jump requests a jump only when grounded.
  void update(SequentialImpulseSolver& solver, math::Fixed dt,
              math::FixedVec3 wish_dir, bool jump,
              std::span<const ConvexShape> colliders);

  // POST-INTEGRATE, once per tick. Pushes the capsule out of any
  // penetration against `colliders` along manifold normals, total
  // correction capped at params_.max_depenetration. This is the only
  // position write the controller performs.
  void resolve(SequentialImpulseSolver& solver,
               std::span<const ConvexShape> colliders);

  // Results of the most recent update() — for tests and debug draw.
  bool grounded() const noexcept { return grounded_; }
  math::FixedVec3 ground_normal() const noexcept { return ground_normal_; }

 private:
  // Sweep `shape` along `delta`; returns the earliest fraction t in
  // [0,1] (Q16.16) at which the translated shape touches any collider,
  // or nullopt when the whole sweep is clear. Fixed substeps + bisection.
  std::optional<math::Fixed> cast_fraction(
      const ConvexShape& shape, math::FixedVec3 delta,
      std::span<const ConvexShape> colliders) const;

  // Deepest contact normal of `shape` vs colliders, or nullopt.
  std::optional<ContactManifold> deepest_contact(
      const ConvexShape& shape, std::span<const ConvexShape> colliders) const;

  std::uint32_t body_index_;
  CharacterParams params_;
  bool grounded_ = false;
  math::FixedVec3 ground_normal_ = math::FixedVec3{math::Fixed::zero(),
                                                    math::Fixed::one(),
                                                    math::Fixed::zero()};
  // Pure-value memo of cast_fraction's touch queries (see TouchCache above).
  // Cleared wholesale when it grows past kTouchCacheMaxEntries so long runs
  // stay bounded; clearing only costs hit rate, never correctness.
  mutable TouchCache touch_cache_;
};

}  // namespace poko::physics
