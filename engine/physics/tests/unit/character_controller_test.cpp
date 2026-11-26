// ENG-64: character controller — kinematic capsule through the solver:
// ground detection by shape cast, slope limit, step-up, wall blocking,
// jump, bounded depenetration, position_step-consistent displacement.
#include "poko/physics/character_controller.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using namespace poko::physics;
using namespace poko::math;

FixedVec3 v3(double x, double y, double z) {
  return FixedVec3{Fixed::from_raw(static_cast<std::int32_t>(std::llround(x * 65536.0))),
                   Fixed::from_raw(static_cast<std::int32_t>(std::llround(y * 65536.0))),
                   Fixed::from_raw(static_cast<std::int32_t>(std::llround(z * 65536.0)))};
}
Fixed fx(double x) {
  return Fixed::from_raw(static_cast<std::int32_t>(std::llround(x * 65536.0)));
}
double tod(Fixed f) { return static_cast<double>(f.raw()) / 65536.0; }
double todv(FixedVec3 v) { return tod(v.y); }

ConvexShape aabb(FixedVec3 c, FixedVec3 h) {
  std::vector<FixedVec3> v;
  for (int i = 0; i < 8; ++i)
    v.push_back(c + FixedVec3{(i & 1) ? h.x : -h.x,
                              (i & 2) ? h.y : -h.y,
                              (i & 4) ? h.z : -h.z});
  return ConvexShape{std::move(v), Fixed::zero()};
}

// Inclined prism (wedge): triangle cross-section in X/Y extruded along Z.
// pts are (x,y) pairs; z half-width zhalf.
ConvexShape wedge(double x0, double y0, double x1, double y1,
                  double x2, double y2, double zhalf) {
  const double xs[3] = {x0, x1, x2}, ys[3] = {y0, y1, y2};
  std::vector<FixedVec3> v;
  for (int i = 0; i < 3; ++i) {
    v.push_back(v3(xs[i], ys[i], -zhalf));
    v.push_back(v3(xs[i], ys[i], zhalf));
  }
  return ConvexShape{std::move(v), Fixed::zero()};
}

struct World {
  SequentialImpulseSolver solver;
  std::vector<ConvexShape> colliders;   // index order == collider order
  std::uint32_t char_index = 1;

  void add_collider(ConvexShape s) { colliders.push_back(std::move(s)); }

  void spawn_character(double x, double y, double z,
                       const CharacterParams& p) {
    SimBody b;
    b.index = char_index;
    b.position = v3(x, y, z);
    b.inv_mass = Fixed::zero();
    b.kinematic = true;
    solver.upsert_body(b);
  }

  // One full sim tick: controller velocity target -> narrowphase
  // contacts -> solve -> integrate -> bounded depenetration.
  void tick(CharacterController& cc, Fixed dt, FixedVec3 wish, bool jump) {
    cc.update(solver, dt, wish, jump, colliders);
    solver.begin_step();
    const SimBody* body = solver.find_body(cc.body_index());
    if (body) {
      const ConvexShape cap = CharacterController::capsule_at(body->position, cc.params());
      for (const auto& c : colliders) {
        const ContactManifold m = collide(cap, c);
        if (!m.touching || m.count == 0) continue;
        ContactConstraint con;
        con.key = 1;
        con.body_a = cc.body_index();
        con.body_b = 0;  // dummy static partner; im_sum = 0 -> skipped
        con.normal = m.normal;
        con.point_a = m.points[0].point_a;
        con.point_b = m.points[0].point_b;
        con.depth = m.depth;
        solver.add_contact(con);
      }
    }
    solver.solve(dt);
    solver.integrate(dt);
    cc.resolve(solver, colliders);
  }

  FixedVec3 pos() const {
    const SimBody* b = solver.find_body(1);
    return b ? b->position : FixedVec3::zero();
  }
};

CharacterParams params() {
  CharacterParams p;
  p.radius = fx(0.4);
  p.half_length = fx(0.3);
  p.move_speed = fx(6.0);
  p.jump_speed = fx(10.0);
  p.gravity = fx(9.8);
  p.ground_distance = fx(2.0);
  p.step_height = fx(0.5);
  p.slope_cos = fx(0.7071);
  p.max_depenetration = fx(0.2);
  return p;
}

const Fixed kDt = Fixed::from_raw(1092);  // ~1/60 s
}  // namespace

int main() {
  // World: floor (top y=0), 0.3 step at x~2.5, 0.9 block at x~5.5,
  // 30-degree walkable ramp at x 8..10, 56-degree steep ramp at x 14..15.
  auto build_world = [&]() {
    World w;
    w.add_collider(aabb(v3(0, -1, 0), v3(40, 1, 40)));          // 0 floor
    w.add_collider(aabb(v3(2.5, -0.35, 0), v3(0.5, 0.65, 3))); // 1 step top 0.3
    w.add_collider(aabb(v3(5.5, -0.05, 0), v3(0.5, 0.95, 3))); // 2 block top 0.9
    // 30 deg ramp rising +X: (8,0)->(10,1.1547)
    w.add_collider(wedge(8, -0.5, 10, -0.5, 10, 0.6547, 3));   // 3 low apron
    w.add_collider(wedge(8, -0.5, 10, 0.6547, 10, 1.1547, 3)); // 4 slope
    // steep ~56 deg ramp at x 14..15
    w.add_collider(wedge(14, -0.5, 15, -0.5, 15, 0.5, 3));      // 5
    w.add_collider(wedge(14, -0.5, 15, 0.5, 15, 1.5, 3));      // 6 slope
    return w;
  };

  {  // Fall and land: rests at capsule rest height ~0.7, grounded.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(-5, 3.0, -8, cc.params());
    // Run past first contact: the 0.3 ground-snap reports grounded while
    // still settling, so keep ticking until the stick velocity seats it.
    for (int i = 0; i < 140; ++i)
      w.tick(cc, kDt, FixedVec3::zero(), false);
    CHECK(cc.grounded());
    CHECK(std::abs(todv(w.pos()) - 0.7) < 0.08);
    CHECK(std::abs(tod(w.pos().x) - (-5.0)) < 0.05);
  }

  {  // Walk +X: mounts the 0.3 step, blocked by the 0.9 block.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(-5, 0.7, 0, cc.params());
    const FixedVec3 wish{Fixed::one(), Fixed::zero(), Fixed::zero()};
    Fixed max_step = Fixed::zero(), prev = w.pos().x;
    double peak_y = 0.0;
    for (int i = 0; i < 260; ++i) {
      w.tick(cc, kDt, wish, false);
      const Fixed d = (w.pos().x - prev).abs();
      if (d > max_step) max_step = d;
      prev = w.pos().x;
      peak_y = std::max(peak_y, todv(w.pos()));
    }
    // Climbed onto the 0.3 step (peak ~1.0+ during the step-up), crossed
    // its far edge back to the floor, and stopped before the 0.9 block
    // (face x=5.0 minus radius 0.4 -> ~4.6).
    CHECK(peak_y > 0.9);
    CHECK(todv(w.pos()) > 0.55 && todv(w.pos()) < 0.85);
    CHECK(tod(w.pos().x) > 3.5 && tod(w.pos().x) < 4.75);
    // position_step consistency: per-tick |dx| <= speed*dt + corrections.
    // speed*dt = 0.1; step-up adds <= step_height once -> bound 0.65.
    CHECK(tod(max_step) < 0.7);
  }

  {  // Walk into tall block from close range: hard stop, no climb.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(4.0, 0.7, 0, cc.params());
    const FixedVec3 wish{Fixed::one(), Fixed::zero(), Fixed::zero()};
    for (int i = 0; i < 100; ++i) w.tick(cc, kDt, wish, false);
    CHECK(tod(w.pos().x) < 4.75);
    CHECK(todv(w.pos()) < 0.85);  // never mounted the 0.9 block
  }

  {  // Jump: leaves ground, rises, returns, grounded again.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(-5, 0.7, -8, cc.params());
    for (int i = 0; i < 40; ++i) w.tick(cc, kDt, FixedVec3::zero(), false);
    CHECK(cc.grounded());
    w.tick(cc, kDt, FixedVec3::zero(), true);
    double peak = todv(w.pos());
    for (int i = 0; i < 170; ++i) {  // ~61 up + ~61 down + settle
      w.tick(cc, kDt, FixedVec3::zero(), false);
      peak = std::max(peak, todv(w.pos()));
    }
    CHECK(peak > 1.6);                    // ~v^2/2g = 5.1 above rest 0.7
    CHECK(cc.grounded());
    CHECK(std::abs(todv(w.pos()) - 0.7) < 0.1);
  }

  {  // Depenetration: spawned inside the floor, pushed out <= max_dep/tick.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(-5, 0.5, -8, cc.params());  // bottom at -0.2
    for (int i = 0; i < 30; ++i)
      w.tick(cc, kDt, FixedVec3::zero(), false);
    CHECK(std::abs(todv(w.pos()) - 0.7) < 0.1);
  }

  {  // Slope limit: 30-deg ramp is walkable, 56-deg is not.
    World w = build_world();
    CharacterController cc(1, params());
    w.spawn_character(8.5, 1.2, 0, cc.params());  // above walkable ramp
    for (int i = 0; i < 140; ++i)
      w.tick(cc, kDt, FixedVec3::zero(), false);
    CHECK(cc.grounded());
    // Steep ramp: spawn above it; should NOT report walkable grounding.
    World w2 = build_world();
    CharacterController cc2(1, params());
    w2.spawn_character(14.5, 1.6, 0, cc2.params());
    bool saw_steep_grounded = false;
    for (int i = 0; i < 140; ++i) {
      w2.tick(cc2, kDt, FixedVec3::zero(), false);
      // Only count grounding while over the ramp footprint: sliding off
      // its downhill edge onto the flat floor legitimately grounds.
      const double x = tod(w2.pos().x);
      if (cc2.grounded() && x >= 14.0 && x <= 15.0) saw_steep_grounded = true;
    }
    CHECK(!saw_steep_grounded);
  }

  {  // Determinism: identical walk runs produce identical positions.
    auto run = [&]() {
      World w = build_world();
      CharacterController cc(1, params());
      w.spawn_character(-5, 0.7, 0, cc.params());
      const FixedVec3 wish{Fixed::one(), Fixed::zero(), Fixed::zero()};
      for (int i = 0; i < 200; ++i) w.tick(cc, kDt, wish, false);
      return w.pos();
    };
    CHECK(run() == run());
  }

  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_character_controller_test: all checks passed");
  return 0;
}
