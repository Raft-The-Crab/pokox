// G2 physics determinism probe: runs a fixed rigid-body scenario through the
// full sim chain — SAP broadphase -> GJK/EPA narrowphase -> sequential
// impulse solver (warm-started) -> integrate — for N ticks and prints
// "tick pairs contacts hash" per line. Identical builds must produce
// byte-identical LF traces on every gate target (Windows x64, Android arm64);
// compare the whole trace, not only a final hash.
//
// The scenario is compiled in (no fixture file): a static floor slab, a
// static pillar, eight spheres and four boxes dropped from staggered
// heights with varied mass, friction, restitution and initial horizontal
// velocity. Every tick applies gravity, rebuilds broadphase bounds from
// world-space shapes, solves contacts and integrates positions.
//
// Usage: g2_replay_probe [ticks]   (default 10000)
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

#include "poko/foundation/fixed.hpp"
#include "poko/foundation/fixed_vec.hpp"
#include "poko/physics/convex_shape.hpp"
#include "poko/physics/narrowphase.hpp"
#include "poko/physics/sap_broadphase.hpp"
#include "poko/physics/solver.hpp"

namespace {
namespace math = poko::math;
using namespace poko::math;
using namespace poko::physics;

// Q16.16 constants authored as decimal literals; conversion happens once at
// startup. The sim path itself is pure Fixed (spec 24 determinism rules).
Fixed fx(double v) {
  return Fixed::from_raw(static_cast<std::int32_t>(v * 65536.0 + (v >= 0 ? 0.5 : -0.5)));
}

constexpr Fixed kDt = Fixed::from_raw(1092);      // ~1/60 s (65536/60 = 1092.27)
constexpr Fixed kGravity = Fixed::from_raw(642253);  // ~9.8 m/s^2

enum class Kind : std::uint8_t { sphere, box };

struct Body {
  std::uint32_t index = 0;
  Kind kind = Kind::sphere;
  FixedVec3 position = FixedVec3::zero();
  FixedVec3 velocity = FixedVec3::zero();
  Fixed radius = Fixed::zero();        // sphere
  FixedVec3 half = FixedVec3::zero();  // box
  Fixed inv_mass = Fixed::one();
  Fixed friction = Fixed::zero();
  Fixed restitution = Fixed::zero();
  bool is_static = false;
};

// Axis-aligned world bounds for the SAP sweep.
SapBroadphase::Bounds bounds_of(const Body& b) {
  const FixedVec3 extent =
      b.kind == Kind::sphere ? FixedVec3{b.radius, b.radius, b.radius} : b.half;
  return SapBroadphase::Bounds{b.position - extent, b.position + extent};
}

// World-space convex shape for the narrowphase.
ConvexShape shape_of(const Body& b) {
  if (b.kind == Kind::sphere)
    return ConvexShape{std::vector<FixedVec3>{b.position}, b.radius};
  std::vector<FixedVec3> v;
  v.reserve(8);
  for (int i = 0; i < 8; ++i)
    v.push_back(b.position + FixedVec3{(i & 1) ? b.half.x : -b.half.x,
                                       (i & 2) ? b.half.y : -b.half.y,
                                       (i & 4) ? b.half.z : -b.half.z});
  return ConvexShape{std::move(v), Fixed::zero()};
}

SimBody sim_body(const Body& b) {
  SimBody s;
  s.index = b.index;
  s.position = b.position;
  s.velocity = b.velocity;
  s.mass = b.is_static ? Fixed::zero() : math::divide(Fixed::one(), b.inv_mass).value_or(Fixed::one());
  s.inv_mass = b.inv_mass;
  return s;
}

// Deterministic 64-bit FNV-1a over raw fixed-point bits; platform-independent
// because it touches only integer state, never pointers or floats.
std::uint64_t state_hash(const std::vector<Body>& bodies, std::uint32_t pairs,
                         std::uint32_t contacts) {
  std::uint64_t h = 14695981039346656037ull;
  auto mix = [&h](std::uint64_t v) {
    for (int i = 0; i < 8; ++i) {
      h ^= static_cast<std::uint8_t>(v & 0xffu);
      h *= 1099511628211ull;
      v >>= 8;
    }
  };
  mix(pairs);
  mix(contacts);
  for (const auto& b : bodies) {
    mix(b.index);
    mix(static_cast<std::uint32_t>(b.position.x.raw()));
    mix(static_cast<std::uint32_t>(b.position.y.raw()));
    mix(static_cast<std::uint32_t>(b.position.z.raw()));
    mix(static_cast<std::uint32_t>(b.velocity.x.raw()));
    mix(static_cast<std::uint32_t>(b.velocity.y.raw()));
    mix(static_cast<std::uint32_t>(b.velocity.z.raw()));
  }
  return h;
}

Fixed combine_friction(Fixed a, Fixed b) { return a < b ? a : b; }
Fixed combine_restitution(Fixed a, Fixed b) { return a > b ? a : b; }

}  // namespace

int main(int argc, char** argv) {
  const int ticks = argc > 1 ? std::atoi(argv[1]) : 10000;
  if (ticks <= 0) return 64;

  std::vector<Body> bodies;
  auto add = [&](Kind kind, double x, double y, double z, double radius,
                 double hx, double hy, double hz, double mass, double friction,
                 double restitution, double vx, double vz, bool is_static) {
    Body b;
    b.index = static_cast<std::uint32_t>(bodies.size());
    b.kind = kind;
    b.position = FixedVec3{fx(x), fx(y), fx(z)};
    b.velocity = FixedVec3{fx(vx), Fixed::zero(), fx(vz)};
    b.radius = fx(radius);
    b.half = FixedVec3{fx(hx), fx(hy), fx(hz)};
    b.inv_mass = is_static ? Fixed::zero()
                           : math::divide(Fixed::one(), fx(mass)).value_or(Fixed::one());
    b.friction = fx(friction);
    b.restitution = fx(restitution);
    b.is_static = is_static;
    bodies.push_back(b);
  };

  // Static world: floor slab (top at y=0) and an off-center pillar.
  add(Kind::box, 0, -1, 0, 0, 40, 1, 40, 0, 0.8, 0.0, 0, 0, true);
  add(Kind::box, 5, 2, -3, 0, 1, 2, 1, 0, 0.6, 0.0, 0, 0, true);

  // Dynamic spheres: staggered heights, varied mass/friction/restitution,
  // two with horizontal velocity to exercise friction bleed-off.
  add(Kind::sphere, -6, 8, 2, 0.6, 0, 0, 0, 1.0, 0.6, 0.5, 0, 0, false);
  add(Kind::sphere, -2, 11, -4, 0.5, 0, 0, 0, 2.0, 0.4, 0.0, 0.8, 0, false);
  add(Kind::sphere, 1, 9, 5, 0.7, 0, 0, 0, 1.5, 0.9, 0.2, 0, 0, false);
  add(Kind::sphere, 4, 13, 1, 0.45, 0, 0, 0, 1.0, 0.3, 0.6, -0.6, 0, false);
  add(Kind::sphere, 7, 10, -6, 0.55, 0, 0, 0, 3.0, 0.7, 0.0, 0, 0, false);
  add(Kind::sphere, -8, 14, -1, 0.4, 0, 0, 0, 0.8, 0.5, 0.4, 0.5, -0.4, false);
  add(Kind::sphere, 10, 12, 4, 0.65, 0, 0, 0, 2.5, 0.2, 0.0, 0, 0, false);
  add(Kind::sphere, -4, 16, 6, 0.5, 0, 0, 0, 1.2, 0.8, 0.3, 0, 0.7, false);

  // Dynamic boxes: axis-aligned, dropped around the pillar zone so box-box,
  // box-sphere and box-static contacts all occur.
  add(Kind::box, -1, 7, -1, 0, 0.5, 0.5, 0.5, 1.0, 0.5, 0.1, 0.3, 0, false);
  add(Kind::box, 3, 9, 2, 0, 0.6, 0.4, 0.6, 2.0, 0.4, 0.0, 0, -0.5, false);
  add(Kind::box, 8, 8, -4, 0, 0.4, 0.7, 0.4, 1.5, 0.7, 0.2, -0.4, 0.2, false);
  add(Kind::box, 6, 15, 7, 0, 0.55, 0.55, 0.55, 1.0, 0.6, 0.0, 0, 0, false);

  SapBroadphase sap;
  SequentialImpulseSolver solver;
  for (const auto& b : bodies) {
    solver.upsert_body(sim_body(b));
    sap.insert(b.index, bounds_of(b));
  }
  sap.commit();

  std::vector<ConvexShape> shapes;
  shapes.reserve(bodies.size());
  for (const auto& b : bodies) shapes.push_back(shape_of(b));

  for (int tick = 1; tick <= ticks; ++tick) {
    // Gravity, then refresh solver bodies and broadphase bounds.
    for (auto& b : bodies) {
      if (b.is_static) continue;
      b.velocity.y -= kGravity * kDt;
      solver.upsert_body(sim_body(b));
      sap.insert(b.index, bounds_of(b));
    }
    sap.commit();

    solver.begin_step();
    std::uint32_t contact_count = 0;
    for (const auto& p : sap.pairs()) {
      const ContactManifold m = collide(shapes[p.a], shapes[p.b]);
      if (!m.touching || m.count == 0) continue;
      const Body& ba = bodies[p.a];
      const Body& bb = bodies[p.b];
      for (std::uint8_t i = 0; i < m.count; ++i) {
        ContactConstraint c;
        c.key = (static_cast<std::uint64_t>(p.a) << 40) |
                (static_cast<std::uint64_t>(p.b) << 8) | i;
        c.body_a = p.a;
        c.body_b = p.b;
        c.normal = m.normal;
        c.point_a = m.points[i].point_a;
        c.point_b = m.points[i].point_b;
        c.depth = m.depth;
        c.friction = combine_friction(ba.friction, bb.friction);
        c.restitution = combine_restitution(ba.restitution, bb.restitution);
        solver.add_contact(c);
        ++contact_count;
      }
    }
    solver.solve(kDt);
    solver.integrate(kDt);

    // Read solved state back from the solver (single source of truth).
    for (auto& b : bodies) {
      if (const SimBody* s = solver.find_body(b.index)) {
        b.position = s->position;
        b.velocity = s->velocity;
      }
    }
    for (auto& b : bodies) shapes[b.index] = shape_of(b);

    std::cout << tick << ' ' << sap.pairs().size() << ' ' << contact_count << ' '
              << std::hex << std::setfill('0') << std::setw(16)
              << state_hash(bodies, static_cast<std::uint32_t>(sap.pairs().size()),
                            contact_count)
              << std::dec << '\n';
  }
  return 0;
}
