// MUT-42: physics queries and body operations as hostcalls.
#include "poko/mute/stdlib_physics.hpp"

#include <array>
#include <utility>

namespace poko::mute {
namespace {

// Raw Q16.16 <-> Fixed conversions at the boundary. Registers carry the sim's
// native representation, so these are bit-exact in both directions.
math::Fixed fixed_from_raw(std::int32_t raw) noexcept {
  return math::Fixed::from_raw(raw);
}

// Fixed raycast implementation: sphere-probe march + bisection refine.
struct ProbeResult {
  bool hit = false;
  math::Fixed dist = math::Fixed::zero();
};

// probe_at reports whether a sphere of the character radius centered at `p`
// touches any collider (index order, first hit wins).
bool touching_at(const PhysicsHostContext& ctx, math::FixedVec3 p) {
  const physics::ConvexShape probe(
      std::vector<math::FixedVec3>{p},
      ctx.character_params.radius);
  for (const physics::ConvexShape& shape : ctx.colliders) {
    if (physics::collide(probe, shape).touching) return true;
  }
  return false;
}

}  // namespace

std::int32_t physics_raycast(const PhysicsHostContext& ctx,
                             math::FixedVec3 origin,
                             math::FixedVec3 dir,
                             math::Fixed max_dist) {
  if (ctx.colliders.empty()) return kRaycastMiss;
  const std::optional<math::FixedVec3> scaled = math::normalized(dir);
  if (!scaled) return kRaycastMiss;
  // March 16 uniform substeps; a probe sphere slides along the ray and the
  // first substep whose sphere touches a collider brackets the surface.
  constexpr std::int32_t kSteps = 16;
  const math::Fixed step = math::divide(max_dist, math::Fixed::from_raw(kSteps * 65536))
                               .value_or(max_dist);
  math::Fixed low = math::Fixed::zero();
  bool found = false;
  for (std::int32_t i = 1; i <= kSteps; ++i) {
    const math::Fixed t = step * math::Fixed::from_raw(i * 65536);
    const math::FixedVec3 p{
        origin.x + scaled->x * t,
        origin.y + scaled->y * t,
        origin.z + scaled->z * t};
    if (touching_at(ctx, p)) {
      found = true;
      break;
    }
    low = t;
  }
  if (!found) return kRaycastMiss;
  // 8-step bisection between the last clear distance (low) and the first
  // touching distance (low + step). Fixed caps, deterministic tie behavior.
  math::Fixed hi = low + step;
  for (std::int32_t i = 0; i < 8; ++i) {
    const math::Fixed mid = math::divide(low + hi, math::Fixed::from_raw(131072))
                                .value_or(low);
    const math::FixedVec3 p{
        origin.x + dir.x * mid,
        origin.y + dir.y * mid,
        origin.z + dir.z * mid};
    if (touching_at(ctx, p)) {
      hi = mid;
    } else {
      low = mid;
    }
  }
  return hi.raw();
}

std::vector<HostcallDef> physics_hostcall_defs(PhysicsHostContext& ctx) {
  std::vector<HostcallDef> defs;
  // Shared failure helper: authority rejections use HostcallError{failed},
  // which the VM turns into the hostcall_failed trap.
  const auto fail = [] { return HostcallResult{HostcallError{HostcallErrorCode::failed}}; };

  // raycast: 7 args (origin, dir, max_dist raw) -> hit distance raw.
  defs.push_back(HostcallDef{
      .id = static_cast<std::uint32_t>(PhysicsHostcall::raycast),
      .version = 1,
      .params = {HostType::integer, HostType::integer, HostType::integer,
                 HostType::integer, HostType::integer, HostType::integer,
                 HostType::integer},
      .result = HostType::integer,
      .capabilities = capability_physics,
      .handler = [&ctx](HostcallArgs a) -> HostcallResult {
        if (a.size() != 7) return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        const math::FixedVec3 origin{fixed_from_raw(a[0]), fixed_from_raw(a[1]),
                                     fixed_from_raw(a[2])};
        const math::FixedVec3 dir{fixed_from_raw(a[3]), fixed_from_raw(a[4]),
                                  fixed_from_raw(a[5])};
        return physics_raycast(ctx, origin, dir, fixed_from_raw(a[6]));
      }});

  // overlap: 4 args (origin, radius raw) -> count of touching colliders.
  defs.push_back(HostcallDef{
      .id = static_cast<std::uint32_t>(PhysicsHostcall::overlap),
      .version = 1,
      .params = {HostType::integer, HostType::integer, HostType::integer,
                 HostType::integer},
      .result = HostType::integer,
      .capabilities = capability_physics,
      .handler = [&ctx](HostcallArgs a) -> HostcallResult {
        if (a.size() != 4) return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        const math::FixedVec3 center{fixed_from_raw(a[0]), fixed_from_raw(a[1]),
                                     fixed_from_raw(a[2])};
        const physics::ConvexShape probe(std::vector<math::FixedVec3>{center},
                                         fixed_from_raw(a[3]));
        std::int32_t count = 0;
        for (const physics::ConvexShape& shape : ctx.colliders) {
          if (physics::collide(probe, shape).touching) ++count;
        }
        return HostcallResult{count};
      }});

  // body_query: (body_index, field) -> component raw. Fields: 0..2 position
  // xyz, 3..5 velocity xyz. Read-only; unknown field fails.
  defs.push_back(HostcallDef{
      .id = static_cast<std::uint32_t>(PhysicsHostcall::body_query),
      .version = 1,
      .params = {HostType::integer, HostType::integer},
      .result = HostType::integer,
      .capabilities = capability_physics,
      .handler = [&ctx](HostcallArgs a) -> HostcallResult {
        if (a.size() != 2 || ctx.solver == nullptr)
          return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        const physics::SimBody* body = ctx.solver->find_body(static_cast<std::uint32_t>(a[0]));
        if (body == nullptr || a[1] < 0 || a[1] > 5)
          return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        const std::array<const math::FixedVec3*, 2> vecs{&body->position, &body->velocity};
        const math::FixedVec3& v = *vecs[a[1] / 3];
        const math::Fixed component = v[a[1] % 3];
        return HostcallResult{component.raw()};
      }});

  // character_move: the approved write path. Drives the character controller
  // velocity target for one tick; returns the grounded flag. No position
  // write escapes the controller's capped depenetration.
  defs.push_back(HostcallDef{
      .id = static_cast<std::uint32_t>(PhysicsHostcall::character_move),
      .version = 1,
      .params = {HostType::integer, HostType::integer, HostType::integer,
                 HostType::boolean},
      .result = HostType::boolean,
      .capabilities = capability_physics,
      .handler = [&ctx](HostcallArgs a) -> HostcallResult {
        if (a.size() != 4 || ctx.solver == nullptr || ctx.character == nullptr)
          return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        if (ctx.solver->find_body(static_cast<std::uint32_t>(a[0])) == nullptr)
          return HostcallResult{HostcallError{HostcallErrorCode::failed}};
        const math::FixedVec3 wish{fixed_from_raw(a[1]), math::Fixed::zero(),
                                   fixed_from_raw(a[2])};
        ctx.character->update(*ctx.solver, ctx.dt, wish, a[3] != 0,
                              ctx.colliders);
        return HostcallResult{ctx.character->grounded() ? 1 : 0};
      }});

  // body_set_position: ALWAYS denied. Positions are ServerOwned — a client
  // script setting a body position bypasses the simulation's authority, so
  // the call fails (hostcall_failed trap) and the body is untouched.
  defs.push_back(HostcallDef{
      .id = static_cast<std::uint32_t>(PhysicsHostcall::body_set_position),
      .version = 1,
      .params = {HostType::integer, HostType::integer, HostType::integer,
                 HostType::integer},
      .result = HostType::unit,
      .capabilities = capability_physics,
      .handler = [&fail](HostcallArgs) -> HostcallResult { return fail(); }});

  return defs;
}

}  // namespace poko::mute
