// ENG-62: GJK/EPA narrowphase — separated, touching, penetrating cases,
// manifold order, determinism.
#include "poko/physics/narrowphase.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using namespace poko::physics;
using namespace poko::math;

ConvexShape sphere(FixedVec3 c, double r) {
  return ConvexShape{std::vector<FixedVec3>{c}, Fixed::from_raw(
      static_cast<std::int32_t>(std::llround(r * 65536.0)))};
}
ConvexShape aabb(FixedVec3 lo, FixedVec3 hi) {
  std::vector<FixedVec3> v;
  for (int i = 0; i < 8; ++i)
    v.push_back(FixedVec3{(i & 1) ? hi.x : lo.x, (i & 2) ? hi.y : lo.y,
                          (i & 4) ? hi.z : lo.z});
  return ConvexShape{std::move(v), Fixed::zero()};
}
FixedVec3 v3(double x, double y, double z) {
  return FixedVec3{Fixed::from_raw(static_cast<std::int32_t>(std::llround(x * 65536.0))),
                   Fixed::from_raw(static_cast<std::int32_t>(std::llround(y * 65536.0))),
                   Fixed::from_raw(static_cast<std::int32_t>(std::llround(z * 65536.0)))};
}
double tod(Fixed f) { return static_cast<double>(f.raw()) / 65536.0; }
double todv(FixedVec3 v) { return tod(v.x); }
}  // namespace

int main() {
  {  // separated spheres: no contact
    auto m = collide(sphere(v3(0, 0, 0), 1.0), sphere(v3(5, 0, 0), 1.0));
    CHECK(!m.touching && m.count == 0);
  }
  {  // overlapping spheres along +Y: centers 1 apart, radii sum 2 -> depth ~1
    auto m = collide(sphere(v3(0, 1, 0), 1.0), sphere(v3(0, 0, 0), 1.0));
    CHECK(m.touching);
    CHECK(m.count >= 1 && m.count <= 4);
    CHECK(tod(m.depth) > 0.9 && tod(m.depth) < 1.1);   // ~1.0 (polytope approx)
    CHECK(m.normal.y > Fixed::from_raw(58982));        // ~0.9 in raw units
    CHECK(std::abs(tod(m.normal.x)) < 0.2 && std::abs(tod(m.normal.z)) < 0.2);
  }
  {  // identical spheres: deep overlap, depth ~ 2R
    auto m = collide(sphere(v3(1, 1, 1), 1.0), sphere(v3(1, 1, 1), 1.0));
    CHECK(m.touching);
    CHECK(tod(m.depth) > 1.5 && tod(m.depth) <= 2.01);
  }
  {  // AABB vs sphere: center 1.2 above the box top, r=1.5 -> depth ~0.3
    auto m = collide(aabb(v3(-1, -1, -1), v3(1, 1, 1)),
                     sphere(v3(0, 2.2, 0), 1.5));
    CHECK(m.touching);
    CHECK(tod(m.depth) > 0.15 && tod(m.depth) < 0.45);
  }
  {  // AABB vs sphere fully separated -> no contact
    auto m = collide(aabb(v3(-1, -1, -1), v3(1, 1, 1)),
                     sphere(v3(0, 3, 0), 1.5));
    CHECK(!m.touching);
  }
  {  // touching exactly (surface contact, depth ~ 0)
    auto m = collide(sphere(v3(0, 0, 0), 1.0), sphere(v3(2, 0, 0), 1.0));
    CHECK(m.touching);
    CHECK(tod(m.depth) < 0.02);
    CHECK(m.count >= 1);
  }
  {  // determinism: identical inputs -> identical manifold
    auto m1 = collide(sphere(v3(0, 1, 0), 1.0), sphere(v3(0, 0, 0), 1.0));
    auto m2 = collide(sphere(v3(0, 1, 0), 1.0), sphere(v3(0, 0, 0), 1.0));
    CHECK(m1.touching == m2.touching && m1.depth == m2.depth &&
          m1.count == m2.count);
    for (int i = 0; i < m1.count; ++i)
      CHECK(m1.points[i].point_a == m2.points[i].point_a &&
            m1.points[i].point_b == m2.points[i].point_b);
  }
  {  // empty shape -> no contact
    ConvexShape empty;
    CHECK(!collide(empty, sphere(v3(0, 0, 0), 1.0)).touching);
  }
  {  // capsule vs sphere (2-vertex shape + radius)
    ConvexShape cap{std::vector<FixedVec3>{v3(0, -1, 0), v3(0, 1, 0)},
                    Fixed::from_raw(32768)};  // radius 0.5
    auto m = collide(cap, sphere(v3(0.9, 0, 0), 0.5));  // axis dist 0.9 < 1.0
    CHECK(m.touching);  // penetration ~0.1
    CHECK(m.count >= 1);
  }
  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_narrowphase_test: all checks passed");
  return 0;
}
