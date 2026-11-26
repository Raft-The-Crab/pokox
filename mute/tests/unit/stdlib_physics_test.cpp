// MUT-42: physics queries and body operations — authority policy tests.
// Builds the hostcall table over a real solver + character controller and
// checks: queries dispatch, character_move is the only write path, and
// body_set_position is denied with the body untouched.
#include "poko/mute/stdlib_physics.hpp"

#include <cstdio>
#include <optional>
#include <string>
#include <variant>

namespace poko::mute {
namespace {
int failures = 0;
#define CHECK(cond)                                                    \
  do {                                                                 \
    if (!(cond)) {                                                     \
      std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond);     \
      ++failures;                                                      \
    }                                                                  \
  } while (0)

math::FixedVec3 box_at(math::Fixed x, math::Fixed y, math::Fixed z) {
  return math::FixedVec3{x, y, z};
}
}  // namespace

int test_physics_hostcalls() {
  using physics::ConvexShape;

  // One static box collider at (2, 0, 0) (half-extent 0.5 => spans 1.5..2.5).
  PhysicsHostContext ctx;
  physics::SequentialImpulseSolver solver;
  physics::CharacterController character{1, physics::CharacterParams{}};
  ctx.solver = &solver;
  ctx.character = &character;

  physics::SimBody body;
  body.index = 7;
  body.inv_mass = math::Fixed::zero();  // static
  body.position = box_at(math::Fixed::from_raw(2 * 65536), math::Fixed::zero(),
                         math::Fixed::zero());
  solver.upsert_body(body);

  const math::Fixed half = math::Fixed::from_raw(32768);  // 0.5
  const math::Fixed cx = math::Fixed::from_raw(2 * 65536);  // box center x=2
  const math::Fixed c0 = math::Fixed::zero();
  ctx.colliders.push_back(
      ConvexShape({box_at(cx + half, half, half), box_at(cx - half, half, half),
                   box_at(cx + half, c0 - half, half), box_at(cx - half, c0 - half, half),
                   box_at(cx + half, half, c0 - half), box_at(cx - half, half, c0 - half),
                   box_at(cx + half, c0 - half, c0 - half), box_at(cx - half, c0 - half, c0 - half)},
                  math::Fixed::zero()));

  const std::vector<HostcallDef> defs = physics_hostcall_defs(ctx);
  HostcallTable table;
  for (const HostcallDef& def : defs) {
    CHECK(table.add(def) == HostcallTable::AddError::ok);
  }
  CHECK(table.size() == 5);

  const HostcallDef* ray = table.find(static_cast<std::uint32_t>(PhysicsHostcall::raycast));
  CHECK(ray != nullptr);
  CHECK(ray->capabilities == capability_physics);

  // Raycast from origin straight at the box: hit before max_dist.
  {
    std::array<std::int32_t, 7> args{0, 0, 0,              // origin
                                     65536, 0, 0,          // +x direction
                                     10 * 65536};          // max 10
    const HostcallResult r = ray->handler(args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    const std::int32_t hit = std::get<std::int32_t>(r);
    CHECK(hit != kRaycastMiss);
    // Surface at 1.5; march step is 10/16 = 0.625, bisection refines hi.
    CHECK(hit > 0);
    CHECK(hit <= 2 * 65536);
  }
  // Raycast away from the box: miss.
  {
    std::array<std::int32_t, 7> args{0, 0, 0, -65536, 0, 0, 10 * 65536};
    const HostcallResult r = ray->handler(args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    CHECK(std::get<std::int32_t>(r) == kRaycastMiss);
  }
  // Zero-length direction: miss, never traps.
  {
    std::array<std::int32_t, 7> args{0, 0, 0, 0, 0, 0, 10 * 65536};
    const HostcallResult r = ray->handler(args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    CHECK(std::get<std::int32_t>(r) == kRaycastMiss);
  }

  // Overlap: a sphere at the box center overlaps; far away does not.
  {
    const HostcallDef* ov = table.find(static_cast<std::uint32_t>(PhysicsHostcall::overlap));
    CHECK(ov != nullptr);
    std::array<std::int32_t, 4> hit_args{2 * 65536, 0, 0, 65536};
    const HostcallResult r = ov->handler(hit_args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    CHECK(std::get<std::int32_t>(r) == 1);
    std::array<std::int32_t, 4> miss_args{20 * 65536, 0, 0, 65536};
    const HostcallResult r2 = ov->handler(miss_args);
    CHECK(std::holds_alternative<std::int32_t>(r2));
    CHECK(std::get<std::int32_t>(r2) == 0);
  }

  // body_query: read position components of body 7.
  {
    const HostcallDef* q = table.find(static_cast<std::uint32_t>(PhysicsHostcall::body_query));
    CHECK(q != nullptr);
    std::array<std::int32_t, 2> args{7, 0};
    const HostcallResult r = q->handler(args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    CHECK(std::get<std::int32_t>(r) == 2 * 65536);
    std::array<std::int32_t, 2> bad{7, 6};  // unknown field
    const HostcallResult r2 = q->handler(bad);
    CHECK(std::holds_alternative<HostcallError>(r2));
    std::array<std::int32_t, 2> no_body{99, 0};
    const HostcallResult r3 = q->handler(no_body);
    CHECK(std::holds_alternative<HostcallError>(r3));
  }

  // body_set_position: denied, body untouched.
  {
    const HostcallDef* set =
        table.find(static_cast<std::uint32_t>(PhysicsHostcall::body_set_position));
    CHECK(set != nullptr);
    CHECK(set->result == HostType::unit);
    std::array<std::int32_t, 4> args{7, 99 * 65536, 0, 0};
    const HostcallResult r = set->handler(args);
    CHECK(std::holds_alternative<HostcallError>(r));
    const physics::SimBody* after = solver.find_body(7);
    CHECK(after != nullptr);
    CHECK(after->position.x.raw() == 2 * 65536);
  }

  // character_move with a live kinematic character body: the approved write
  // path drives a velocity target; grounded starts false with no ground.
  {
    physics::SimBody avatar;
    avatar.index = 1;
    avatar.kinematic = true;
    avatar.inv_mass = math::Fixed::zero();
    avatar.position = math::FixedVec3{math::Fixed::zero(),
                                      math::Fixed::from_raw(10 * 65536),
                                      math::Fixed::zero()};
    solver.upsert_body(avatar);
    const HostcallDef* move =
        table.find(static_cast<std::uint32_t>(PhysicsHostcall::character_move));
    CHECK(move != nullptr);
    CHECK(move->result == HostType::boolean);
    std::array<std::int32_t, 4> args{1, 65536, 0, 0};  // wish +x, no jump
    const HostcallResult r = move->handler(args);
    CHECK(std::holds_alternative<std::int32_t>(r));
    CHECK(std::get<std::int32_t>(r) == 0);
    const physics::SimBody* after = solver.find_body(1);
    CHECK(after != nullptr);
    // The controller wrote a velocity target (approved), never a position.
    CHECK(after->position.y.raw() == 10 * 65536);
    CHECK(after->velocity.x != math::Fixed::zero());
  }

  // Capability gating: a def requiring Physics must be denied when the grant
  // lacks it — check via the bind-time helper.
  CHECK((capability_physics & capability_physics) != 0);
  CHECK(effective_capabilities(capability_physics, 0) == 0);
  CHECK(effective_capabilities(capability_all, capability_physics) ==
        capability_physics);

  if (failures == 0) std::printf("physics hostcalls: all checks passed\n");
  return failures;
}

}  // namespace poko::mute

int main() { return poko::mute::test_physics_hostcalls() == 0 ? 0 : 1; }
