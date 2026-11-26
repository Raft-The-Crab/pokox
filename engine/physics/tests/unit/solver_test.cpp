// ENG-63: sequential impulse solver — separation, restitution, friction,
// determinism, warm-start persistence across steps.
#include "poko/physics/solver.hpp"

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

SimBody body(std::uint32_t i, FixedVec3 p, FixedVec3 v, double mass) {
  return SimBody{i, p, v, fx(mass > 0 ? 1.0 / mass : 0.0)};
}
// Static floor: inv_mass 0 (infinite mass).
SimBody statics(std::uint32_t i, FixedVec3 p) {
  SimBody b = body(i, p, FixedVec3::zero(), 1.0);
  b.inv_mass = Fixed::zero();
  return b;
}
ContactConstraint contact(std::uint64_t key, std::uint32_t a, std::uint32_t b,
                          FixedVec3 n, double depth, double friction = 0.0,
                          double restitution = 0.0) {
  ContactConstraint c;
  c.key = key; c.body_a = a; c.body_b = b; c.normal = n;
  c.point_a = FixedVec3::zero(); c.point_b = FixedVec3::zero();
  c.depth = fx(depth); c.friction = fx(friction); c.restitution = fx(restitution);
  return c;
}
}  // namespace

int main() {
  const Fixed dt = fx(1.0 / 60.0);
  const FixedVec3 up{Fixed::zero(), Fixed::one(), Fixed::zero()};

  {  // dynamic sphere resting on static floor: solver pushes it up
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1.8, 0), FixedVec3::zero(), 1.0));
    s.begin_step();
    s.add_contact(contact(7, 1, 0, up, 0.2, 0.5, 0.0));
    s.solve(dt);
    const SimBody* a = s.find_body(1);
    CHECK(a != nullptr);
    CHECK(tod(a->velocity.y) > 0.5);          // separating velocity gained
    CHECK(a->velocity.x.is_zero() && a->velocity.z.is_zero());
    s.integrate(dt);
    CHECK(tod(a->position.y) > 1.8);          // moved away from floor
  }
  {  // already separating faster than target: no impulse added
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1.8, 0), v3(0, 5.0, 0), 1.0));
    s.begin_step();
    s.add_contact(contact(7, 1, 0, up, 0.2));
    s.solve(dt);
    const SimBody* a = s.find_body(1);
    CHECK(tod(a->velocity.y) == 5.0);         // untouched
  }
  {  // restitution: fast approach bounces back at ~e*approach
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1.01, 0), v3(0, -3.0, 0), 1.0));
    s.begin_step();
    s.add_contact(contact(9, 1, 0, up, 0.01, 0.0, 0.8));
    s.solve(dt);
    const SimBody* a = s.find_body(1);
    CHECK(tod(a->velocity.y) > 1.5);          // bounced upward (~2.4)
    CHECK(tod(a->velocity.y) < 3.0);
  }
  {  // two dynamic bodies share the impulse symmetrically
    SequentialImpulseSolver s;
    s.upsert_body(body(0, v3(0, 1, 0), FixedVec3::zero(), 1.0));
    s.upsert_body(body(1, v3(0, 0, 0), FixedVec3::zero(), 1.0));
    s.begin_step();
    // normal B->A = +Y (body 0 above body 1)
    s.add_contact(contact(3, 0, 1, up, 0.2));
    s.solve(dt);
    const SimBody* a = s.find_body(0);
    const SimBody* b = s.find_body(1);
    CHECK(tod(a->velocity.y) > 0.0);
    CHECK(tod(b->velocity.y) < 0.0);
    CHECK(std::abs(tod(a->velocity.y) + tod(b->velocity.y)) < 0.01);
  }
  {  // friction bleeds off tangential velocity on a loaded contact
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1.8, 0), v3(1.0, 0, 0), 1.0));
    s.begin_step();
    s.add_contact(contact(7, 1, 0, up, 0.2, 0.5, 0.0));
    s.solve(dt, 16);
    const SimBody* a = s.find_body(1);
    CHECK(tod(a->velocity.x) < 0.9);          // friction acted
    CHECK(tod(a->velocity.x) > -0.2);         // but did not reverse hard
  }
  {  // resting contact stays stable over 60 warm-started steps
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1.0, 0), FixedVec3::zero(), 1.0));
    for (int step = 0; step < 60; ++step) {
      s.begin_step();
      s.add_contact(contact(7, 1, 0, up, 0.05, 0.4, 0.0));
      s.solve(dt);
      s.integrate(dt);
    }
    const SimBody* a = s.find_body(1);
    CHECK(std::abs(tod(a->velocity.y)) < 2.0);   // bounded, no energy blowup
    CHECK(std::abs(tod(a->velocity.x)) < 0.5);
    CHECK(tod(a->position.y) > 0.5);             // stayed near floor
  }
  {  // determinism: identical runs -> bit-identical velocities
    auto run = [&]() {
      SequentialImpulseSolver s;
      s.upsert_body(statics(0, v3(0, 0, 0)));
      s.upsert_body(body(1, v3(0, 1.8, 0), v3(0.3, -1.0, 0.2), 1.0));
      s.upsert_body(body(2, v3(-3, 0, 0), FixedVec3::zero(), 2.0));
      for (int step = 0; step < 10; ++step) {
        s.begin_step();
        s.add_contact(contact(7, 1, 0, up, 0.1, 0.3, 0.2));
        s.add_contact(contact(8, 1, 2, FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()}, 0.05));
        s.solve(dt, 8);
        s.integrate(dt);
      }
      std::vector<std::int32_t> out;
      for (std::uint32_t i = 0; i < 3; ++i) {
        const SimBody* b = s.find_body(i);
        out.push_back(b->velocity.x.raw());
        out.push_back(b->velocity.y.raw());
        out.push_back(b->velocity.z.raw());
        out.push_back(b->position.x.raw());
        out.push_back(b->position.y.raw());
        out.push_back(b->position.z.raw());
      }
      return out;
    };
    CHECK(run() == run());
  }
  {  // body bookkeeping: upsert replace, remove, empty solve is safe
    SequentialImpulseSolver s;
    s.upsert_body(body(5, v3(0, 0, 0), FixedVec3::zero(), 1.0));
    s.upsert_body(body(5, v3(1, 0, 0), v3(0, 1, 0), 2.0));  // replace
    CHECK(s.body_count() == 1);
    CHECK(s.find_body(5)->position.x == fx(1.0));
    s.remove_body(5);
    CHECK(s.find_body(5) == nullptr);
    s.begin_step();
    s.add_contact(contact(1, 0, 5, up, 0.1));   // missing bodies skipped
    s.solve(dt);                               // must not crash
    s.integrate(dt);
  }
  {  // review L1: self-contacts and duplicate keys are rejected, not merged
    SequentialImpulseSolver s;
    s.upsert_body(statics(0, v3(0, 0, 0)));
    s.upsert_body(body(1, v3(0, 1, 0), FixedVec3::zero(), 1.0));
    s.upsert_body(body(2, v3(2, 1, 0), FixedVec3::zero(), 1.0));
    s.begin_step();
    CHECK(!s.add_contact(contact(5, 1, 1, up, 0.1)));       // self contact
    CHECK(s.add_contact(contact(6, 1, 0, up, 0.1)));
    CHECK(!s.add_contact(contact(6, 2, 0, up, 0.1)));       // same key again
    CHECK(s.add_contact(contact(7, 2, 0, up, 0.1)));
    CHECK(s.contact_count() == 2);
    s.begin_step();                                          // keys reset per step
    CHECK(s.add_contact(contact(6, 1, 0, up, 0.1)));
  }
  {  // review L2: mass is derived from inv_mass, never a second source
    SimBody b;
    b.set_mass(fx(4.0));
    CHECK(b.inv_mass == fx(0.25));
    CHECK(b.mass() == fx(4.0));
    b.set_mass(Fixed::zero());
    CHECK(b.inv_mass.is_zero() && b.mass().is_zero());
    b.inv_mass = fx(0.5);
    CHECK(b.mass() == fx(2.0));
  }
  {  // review M2: integrating past the world edge clamps, never wraps
    SequentialImpulseSolver s;
    s.upsert_body(body(1, v3(32767, -32767, 0), v3(600, -600, 0), 1.0));
    s.integrate(dt);  // +-10 units this tick
    const SimBody* b = s.find_body(1);
    CHECK(b && b->position.x.raw() == 2147483647);   // was -32759 (wrapped)
    CHECK(b && b->position.y.raw() == -2147483647 - 1);
    CHECK(b && b->position.z.is_zero());
  }
  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_solver_test: all checks passed");
  return 0;
}
