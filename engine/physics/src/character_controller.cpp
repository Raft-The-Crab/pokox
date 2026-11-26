// ENG-64: kinematic character controller — capsule ground detection by
// shape cast, slope limit, step-up, bounded depenetration, velocity
// target through the sequential impulse solver. All Q16.16 Fixed.
#include "poko/physics/character_controller.hpp"

#include <algorithm>
#include <optional>

namespace poko::physics {
namespace {
using math::Fixed;
using math::FixedVec3;

// Cast tuning (Q16.16 raw). Substeps keep each probe within ~0.25 units so
// thin features cannot be skipped; bisection resolves the impact fraction
// to ~1e-5 units. Both counts are derived from the sweep length by a fixed
// formula — deterministic for identical inputs.
constexpr std::int32_t kCastSubstepRaw = 16384;    // 0.25 units
constexpr int kCastMaxSubsteps = 64;
constexpr int kCastBisectIters = 16;
// A pose counts as "touching" for casts when the manifold depth is at
// least this — below it the contact is a tangent graze, not a blocker.
constexpr std::int32_t kCastDepthRaw = 8;         // ~0.0001 units
// A contact must penetrate at least this to count as a wall/blocker —
// tangent grazes and degenerate EPA manifolds (depth ~0, garbage normal)
// must not trigger slide blocking or step-up probes.
constexpr std::int32_t kBlockDepthRaw = 131;      // ~0.002 units

FixedVec3 planar(FixedVec3 v) {
  return FixedVec3{v.x, Fixed::zero(), v.z};
}

Fixed length_of(FixedVec3 v) {
  return math::length(v);
}

ConvexShape translated(const ConvexShape& s, FixedVec3 offset) {
  std::vector<FixedVec3> v;
  v.reserve(s.vertices().size());
  for (const auto& p : s.vertices()) v.push_back(p + offset);
  return ConvexShape{std::move(v), s.radius()};
}

// Bounding-sphere data, computed once per colliders span: the prune in
// the helpers below is conservative (the sphere covers every vertex plus
// the sweep radius), so results are bit-identical with and without it.
struct Bound {
  FixedVec3 center;
  Fixed radius;
};

Bound shape_bound(const ConvexShape& s) {
  Bound b{FixedVec3::zero(), s.radius()};
  for (const auto& p : s.vertices()) b.center = b.center + p;
  const auto n = s.vertices().size();
  if (n == 0) return b;
  const auto inv = math::divide(Fixed::one(), Fixed::from_int(static_cast<std::int32_t>(n)));
  if (inv) b.center = FixedVec3{b.center.x * *inv, b.center.y * *inv, b.center.z * *inv};
  for (const auto& p : s.vertices()) {
    const FixedVec3 d = p - b.center;
    const Fixed ls = math::lengthSquared(d);
    if (ls > b.radius * b.radius) b.radius = math::sqrt(ls);
  }
  return b;
}

bool spheres_disjoint(const Bound& a, const Bound& b) {
  const Fixed r = a.radius + b.radius;
  return math::lengthSquared(a.center - b.center) > r * r;
}

// True when `shape` overlaps (or comes within min_depth of) any collider.
// Deterministic: fixed-point collide, colliders scanned in index order.
bool touches_uncached(const ConvexShape& shape,
                      std::span<const ConvexShape> colliders,
                      Fixed min_depth = Fixed::zero()) {
  const Bound sb = shape_bound(shape);
  for (const auto& c : colliders) {
    if (spheres_disjoint(sb, shape_bound(c))) continue;
    const ContactManifold m = collide(shape, c);
    if (m.touching && m.depth >= min_depth) return true;
  }
  return false;
}
// --- Cast-path touch memo -------------------------------------------
// touches() is pure: collide() is deterministic fixed-point over the
// exact shape values, so identical pose queries always produce identical
// answers. Stationary and blocked ticks re-query byte-identical poses,
// and each miss burns full GJK+EPA on near-contact colliders — the
// dominant cast-path cost. Memoize the boolean on exact raw values; a
// hash bucket is scanned with full key comparison, so equal hashes on
// different poses cannot cross-hit.

constexpr std::size_t kTouchCacheMaxEntries = 8192;

void append_shape_raws(std::vector<std::int32_t>& raws,
                       const ConvexShape& s) {
  raws.push_back(s.radius().raw());
  raws.push_back(static_cast<std::int32_t>(s.vertices().size()));
  for (const auto& v : s.vertices()) {
    raws.push_back(v.x.raw());
    raws.push_back(v.y.raw());
    raws.push_back(v.z.raw());
  }
}

TouchCacheKey touch_key(const ConvexShape& shape,
                        std::span<const ConvexShape> colliders,
                        Fixed min_depth) {
  std::size_t vert_total = 0;
  for (const auto& c : colliders) vert_total += c.vertices().size();
  std::vector<std::int32_t> raws;
  raws.reserve(3 + 3 * shape.vertices().size() +
               3 * vert_total);
  raws.push_back(min_depth.raw());
  append_shape_raws(raws, shape);
  for (const auto& c : colliders) append_shape_raws(raws, c);
  std::uint64_t h = 1469598103934665603ULL;  // FNV-1a 64 offset basis
  for (const std::int32_t v : raws) {
    h ^= static_cast<std::uint32_t>(v);
    h *= 1099511628211ULL;  // FNV-1a 64 prime
  }
  return TouchCacheKey{static_cast<std::size_t>(h), std::move(raws)};
}

bool touches(const ConvexShape& shape, std::span<const ConvexShape> colliders,
             Fixed min_depth, TouchCache& cache) {
  const TouchCacheKey key = touch_key(shape, colliders, min_depth);
  if (const auto it = cache.buckets.find(key.hash); it != cache.buckets.end()) {
    for (const auto& e : it->second)
      if (e.key.raws == key.raws) return e.touching;
  }
  const bool touching = touches_uncached(shape, colliders, min_depth);
  if (cache.entries >= kTouchCacheMaxEntries) {
    cache.buckets.clear();
    cache.entries = 0;
  }
  cache.buckets[key.hash].push_back(TouchCacheEntry{key, touching});
  ++cache.entries;
  return touching;
}
}  // namespace

ConvexShape CharacterController::capsule_at(FixedVec3 position,
                                            const CharacterParams& p) {
  return ConvexShape{
      std::vector<FixedVec3>{position + FixedVec3{Fixed::zero(), -p.half_length, Fixed::zero()},
                             position + FixedVec3{Fixed::zero(), p.half_length, Fixed::zero()}},
      p.radius};
}

std::optional<ContactManifold> CharacterController::deepest_contact(
    const ConvexShape& shape, std::span<const ConvexShape> colliders) const {
  std::optional<ContactManifold> best;
  const Bound sb = shape_bound(shape);
  for (const auto& c : colliders) {
    if (spheres_disjoint(sb, shape_bound(c))) continue;
    const ContactManifold m = collide(shape, c);
    if (m.touching && (!best || m.depth > best->depth)) best = m;
  }
  return best;
}

std::optional<Fixed> CharacterController::cast_fraction(
    const ConvexShape& shape, FixedVec3 delta,
    std::span<const ConvexShape> colliders) const {
  const Fixed len = length_of(delta);
  if (len.is_zero()) {
    // Degenerate sweep: report contact at t=0 only.
    return touches(shape, colliders, Fixed::zero(), touch_cache_)
               ? std::optional<Fixed>{Fixed::zero()}
               : std::nullopt;
  }
  // Substep count: ceil(len / kCastSubstep), clamped to [1, 64].
  const auto per = math::divide(len, Fixed::from_raw(kCastSubstepRaw));
  int n = per ? static_cast<int>(per->raw() >> 16) + 1 : 1;
  if (n < 1) n = 1;
  if (n > kCastMaxSubsteps) n = kCastMaxSubsteps;
  const Fixed inv_n = math::divide(Fixed::one(), Fixed::from_int(n)).value_or(Fixed::zero());

  Fixed lo = Fixed::zero();   // last free fraction
  bool have_lo = false;
  for (int i = 1; i <= n; ++i) {
    const Fixed t = inv_n * Fixed::from_int(i);
    if (touches(translated(shape, delta * t), colliders,
                Fixed::from_raw(kCastDepthRaw), touch_cache_)) {
      // Bisect (lo, t]: invariant — lo free (or start), t touching.
      Fixed a = have_lo ? lo : Fixed::zero();
      Fixed b = t;
      for (int it = 0; it < kCastBisectIters; ++it) {
        const Fixed mid = (a + b) * Fixed::from_raw(32768);  // *0.5
        if (touches(translated(shape, delta * mid), colliders,
                    Fixed::from_raw(kCastDepthRaw), touch_cache_))
          b = mid;
        else
          a = mid;
      }
      return b;
    }
    lo = t;
    have_lo = true;
  }
  return std::nullopt;
}

void CharacterController::update(SequentialImpulseSolver& solver, Fixed dt,
                                 FixedVec3 wish_dir, bool jump,
                                 std::span<const ConvexShape> colliders) {
  grounded_ = false;
  const SimBody* body = solver.find_body(body_index_);
  if (!body) return;
  const FixedVec3 pos = body->position;
  const FixedVec3 vel = body->velocity;
  const ConvexShape capsule = capsule_at(pos, params_);

  // --- Ground detection: downward shape cast -------------------------
  // grounded requires the cast to come to rest within kGroundSnap of the
  // capsule — a distant floor below does NOT ground the character (that
  // would zero gravity mid-air). Slope classification uses the same hit.
  constexpr std::int32_t kGroundSnapRaw = 19661;  // ~0.3 units
  FixedVec3 ground_n{Fixed::zero(), Fixed::one(), Fixed::zero()};
  const FixedVec3 down{Fixed::zero(), -params_.ground_distance, Fixed::zero()};
  if (const auto t = cast_fraction(capsule, down, colliders)) {
    const Fixed drop = down.y.abs() * *t;
    const ConvexShape at = translated(capsule, down * *t);
    if (drop <= Fixed::from_raw(kGroundSnapRaw)) {
      if (const auto m = deepest_contact(at, colliders)) {
        // normal is B->A with A=capsule: points out of the world toward us.
        if (m->normal.y >= params_.slope_cos) {
          grounded_ = true;
          ground_n = m->normal;
        }
      }
    }
  }
  ground_normal_ = ground_n;

  // --- Horizontal intent ---------------------------------------------
  FixedVec3 wish = planar(wish_dir);
  if (auto u = math::normalized(wish)) wish = *u;
  else wish = FixedVec3::zero();

  // Per-axis slide: test the destination pose for each nonzero wish
  // component independently; a component is blocked when the pose
  // touches a collider whose normal is not walkable ground (wall/ceiling).
  const Fixed kBlockDepth = Fixed::from_raw(kBlockDepthRaw);
  auto axis_blocked = [&](FixedVec3 delta) -> bool {
    const ConvexShape dst = translated(capsule, delta);
    const Bound sb = shape_bound(dst);
    for (const auto& c : colliders) {
      if (spheres_disjoint(sb, shape_bound(c))) continue;
      const ContactManifold m = collide(dst, c);
      if (m.touching && m.depth >= kBlockDepth && m.normal.y < params_.slope_cos)
        return true;
    }
    return false;
  };

  FixedVec3 move = FixedVec3::zero();
  if (!wish.x.is_zero()) {
    const FixedVec3 dx{wish.x * params_.move_speed * dt, Fixed::zero(), Fixed::zero()};
    if (!axis_blocked(dx)) move.x = wish.x * params_.move_speed;
  }
  if (!wish.z.is_zero()) {
    const FixedVec3 dz{Fixed::zero(), Fixed::zero(), wish.z * params_.move_speed * dt};
    if (!axis_blocked(dz)) move.z = wish.z * params_.move_speed;
  }

  // --- Step-up ---------------------------------------------------------
  // When grounded with horizontal intent and an axis blocked at foot
  // level, probe a lifted path: the capsule raised by step_height must be
  // clear (headroom), the raised destination must be wall-free, and a
  // downward cast from the raised destination must land MORE than ~0.02
  // below it — i.e. the obstacle top sits below the raised capsule, so the
  // ledge is within step_height (a higher ledge intersects the raised
  // capsule and reports ~zero drop -> rejected). The lift is applied as a
  // bounded POSITIONAL correction (step_height, once per tick, only when
  // the probe passes) — NOT as a velocity: a one-tick vy=step_height/dt
  // would persist as body velocity and launch the capsule ballistically.
  Fixed step_lift = Fixed::zero();
  if (grounded_) {
    const bool x_blocked = !wish.x.is_zero() && move.x.is_zero();
    const bool z_blocked = !wish.z.is_zero() && move.z.is_zero();
    if (x_blocked || z_blocked) {
      const FixedVec3 lift{Fixed::zero(), params_.step_height, Fixed::zero()};
      const ConvexShape raised = capsule_at(pos + lift, params_);
      if (!touches(raised, colliders, kBlockDepth, touch_cache_)) {
        const FixedVec3 dest_delta =
            FixedVec3{wish.x * params_.move_speed * dt, Fixed::zero(),
                      wish.z * params_.move_speed * dt};
        const ConvexShape dest = translated(raised, dest_delta);
        const FixedVec3 down2{Fixed::zero(),
                              -(params_.step_height + params_.ground_distance),
                              Fixed::zero()};
        bool wall_free = true;
        for (const auto& c : colliders) {
          const ContactManifold m = collide(dest, c);
          if (m.touching && m.depth >= kBlockDepth && m.normal.y < params_.slope_cos) {
            wall_free = false;
            break;
          }
        }
        // drop = distance from the raised destination down to the first
        // surface. drop > eps means the landing is below the raised pose
        // (obstacle shorter than step_height); drop ~ 0 means the raised
        // capsule already intersects something (ledge taller than
        // step_height) -> reject.
        constexpr std::int32_t kLandEpsRaw = 1311;  // ~0.02 units
        bool landing_ok = false;
        if (wall_free) {
          if (const auto t2 = cast_fraction(dest, down2, colliders)) {
            const Fixed drop = down2.y.abs() * *t2;
            landing_ok = drop > Fixed::from_raw(kLandEpsRaw);
          }
        }
        if (landing_ok) {
          if (x_blocked) move.x = wish.x * params_.move_speed;
          if (z_blocked) move.z = wish.z * params_.move_speed;
          step_lift = params_.step_height;
        }
      }
    }
  }

  // --- Velocity target ---------------------------------------------------
  // Gravity always applies; the terminal clamp keeps per-tick fall distance
  // inside the depenetration budget (|vy|*dt <= max_depenetration for the
  // default 0.2 @ 60 Hz). When grounded the controller switches to a small
  // downward "stick" velocity: constant per tick, so it presses gently into
  // the ground without accumulating, and resolve() cancels the ~0.008 u/tick
  // penetration — no floating, no tunneling.
  constexpr std::int32_t kTerminalRaw = -655360;   // -10.0 u/s
  constexpr std::int32_t kStickRaw = -32768;       // -0.5 u/s
  Fixed vy = vel.y - params_.gravity * dt;
  if (vy < Fixed::from_raw(kTerminalRaw)) vy = Fixed::from_raw(kTerminalRaw));
  if (jump && grounded_ && params_.jump_speed > Fixed::zero()) {
    vy = params_.jump_speed;
  } else if (grounded_ && vy < Fixed::from_raw(kStickRaw)) {
    vy = Fixed::from_raw(kStickRaw);
  }
  const FixedVec3 target{move.x, vy, move.z};

  SimBody nb = *body;
  nb.velocity = target;
  if (!step_lift.is_zero())
    nb.position = nb.position + FixedVec3{Fixed::zero(), step_lift, Fixed::zero()};
  solver.upsert_body(nb);
}

void CharacterController::resolve(SequentialImpulseSolver& solver,
                                  std::span<const ConvexShape> colliders) {
  const SimBody* body = solver.find_body(body_index_);
  if (!body) return;
  const ConvexShape capsule = capsule_at(body->position, params_);
  FixedVec3 push = FixedVec3::zero();
  for (const auto& c : colliders) {
    const ContactManifold m = collide(capsule, c);
    if (m.touching && m.depth > Fixed::zero())
      push = push + m.normal * std::min(m.depth, params_.max_depenetration);
  }
  const Fixed plen = length_of(push);
  if (plen.is_zero()) return;
  const Fixed cap = params_.max_depenetration;
  const FixedVec3 applied =
      plen > cap ? push * math::divide(cap, plen).value_or(Fixed::zero()) : push;
  SimBody nb = *body;
  nb.position = nb.position + applied;
  solver.upsert_body(nb);
}

}  // namespace poko::physics