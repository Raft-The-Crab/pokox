#pragma once

#include "poko/mute/hostcall.hpp"

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"
#include "poko/physics/character_controller.hpp"
#include "poko/physics/convex_shape.gpp"
#include "poko/physics/narrowphase.hpp"
#include "poko/physics/solver.hpp"

#include <cstdint>
#include <vector>

namespace poko::mute {

// MUT-42: physics queries and body operations behind the MUT-35 hostcall
// boundary. All values cross the boundary as raw Q16.16 i32 registers — the
// same Fixed representation the sim uses — so no rounding enters at the edge
// and results are bit-identical to direct engine calls.
//
// Authority policy (MUT-42 acceptance: "follow authority policy; denied
// writes fail"):
//   - Queries (raycast, overlap, body_query) are read-only and available
//     with the Physics capability granted.
//   - Character movement is the approved write path: it goes through
//     CharacterController::update, which only ever writes a velocity target
//     (plus capped depenetration in resolve), never a raw position.
//   - Direct position writes are rejected: the handler fails the call, the
//     VM traps with hostcall_failed, and the body state is untouched.
//     Positions and solver-owned state are ServerOwned — clients observe
//     them, they do not set them.
//   - Engine objects (solver, controller, colliders) stay host-side in
//     PhysicsHostContext. Guests receive no handles; v1 registers cannot
//     carry them, which keeps the ServerOwned boundary total.
enum class PhysicsHostcall : std::uint32_t {
  raycast = 121,           // (ox,oy,oz,dx,dy,dz,max_dist) -> hit distance raw or miss sentinel
  overlap = 122,           // (ox,oy,oz,radius) -> touching-collider count
  body_query = 123,        // (body_index, field 0..5) -> position/velocity component raw
  character_move = 124,    // (body_index, wish_x, wish_z, jump) -> grounded flag
  body_set_position = 125, // (body_index, x,y,z) -> always denied (authority)
};

// Miss sentinel for raycast: Q16.16 distances are non-negative, so INT32_MIN
// can never collide with a real hit.
inline constexpr std::int32_t kRaycastMiss = -2147483647 - 1;

// Host-owned physics view the handlers close over. The host fills it once
// per run; a null solver/controller leaves queries erroring and writes
// failing rather than dereferencing.
struct PhysicsHostContext {
  physics::SequentialImpulseSolver* solver = nullptr;
  physics::CharacterController* character = nullptr;
  physics::CharacterParams character_params;
  math::Fixed dt = math::Fixed::from_raw(65536);  // 1.0 s default; host sets its sim dt
  std::vector<physics::ConvexShape> colliders;
};

// Deterministic ray march: 16 fixed substeps of sphere probes against the
// colliders in index order, then an 8-step bisection to refine the first
// touching distance. Fixed-point only, fixed iteration caps — replay-safe.
// Returns the hit distance raw (Q16.16) or kRaycastMiss.
[[nodiscard]] std::int32_t physics_raycast(const PhysicsHostContext& ctx,
                                           math::FixedVec3 origin,
                                           math::FixedVec3 dir,
                                           math::Fixed max_dist);

[[nodiscard]] std::vector<HostcallDef> physics_hostcall_defs(PhysicsHostContext& ctx);

}  // namespace poko::mute
