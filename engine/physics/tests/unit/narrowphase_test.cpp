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
  // Off-origin regression (review 2026-11-26 H2): the narrowphase used to
  // pick its fixed-point rescale from ABSOLUTE coordinates, so the 0.1-unit
  // near-touch window and depth precision degraded with distance from the
  // world origin (spheres 5 apart "touching" at x=100, a 0.01 floor
  // penetration reading as 0 at x=100). Results must not depend on where
  // the pair sits in the world.
  {
    const double offsets[] = {0.0, 10.0, -10.0, 100.0, 1000.0, 10000.0, -20000.0};
    for (const double ox : offsets) {
      const double oz = ox / 2;
      // spheres r=1: gap 0.5 and gap 5 -> separated; overlap 0.2 -> depth 0.2
      CHECK(!collide(sphere(v3(ox, 0, oz), 1.0), sphere(v3(ox + 2.5, 0, oz), 1.0)).touching);
      CHECK(!collide(sphere(v3(ox, 0, oz), 1.0), sphere(v3(ox + 7, 0, oz), 1.0)).touching);
      {
        auto m = collide(sphere(v3(ox, 0, oz), 1.0), sphere(v3(ox + 1.8, 0, oz), 1.0));
        CHECK(m.touching);
        CHECK(std::abs(tod(m.depth) - 0.2) < 0.001);
      }
      // unit box over a 20x1x20 floor slab (top at y=0) centred under it
      const auto floor_small = aabb(v3(ox - 10, -1, oz - 10), v3(ox + 10, 0, oz + 10));
      CHECK(!collide(aabb(v3(ox - 0.5, 0.3, oz - 0.5), v3(ox + 0.5, 1.3, oz + 0.5)),
                     floor_small).touching);
      {
        auto m = collide(aabb(v3(ox - 0.5, -0.01, oz - 0.5), v3(ox + 0.5, 0.99, oz + 0.5)),
                         floor_small);
        CHECK(m.touching);
        CHECK(tod(m.depth) > 0.005 && tod(m.depth) < 0.015);
        CHECK(m.normal.y > Fixed::from_raw(64880));  // ~0.99 up
      }
      // large 200x1x200 static floor: precision is bounded by the shape
      // size (fixed shift), never by the world position.
      const auto floor_big = aabb(v3(ox - 100, -1, oz - 100), v3(ox + 100, 0, oz + 100));
      CHECK(!collide(aabb(v3(ox - 0.5, 0.3, oz - 0.5), v3(ox + 0.5, 1.3, oz + 0.5)),
                     floor_big).touching);
      {
        auto m = collide(aabb(v3(ox - 0.5, -0.05, oz - 0.5), v3(ox + 0.5, 0.95, oz + 0.5)),
                         floor_big);
        CHECK(m.touching);
        CHECK(tod(m.depth) > 0.03 && tod(m.depth) < 0.07);
      }
      // sphere resting 0.01 into the small floor
      {
        auto m = collide(sphere(v3(ox, 0.99, oz), 1.0), floor_small);
        CHECK(m.touching);
        CHECK(tod(m.depth) > 0.005 && tod(m.depth) < 0.015);
      }
    }
  }
  {  // exact translation invariance: same pair shifted by whole raw units
    const auto a0 = aabb(v3(-0.5, -0.03, -0.5), v3(0.5, 0.97, 0.5));
    const auto b0 = aabb(v3(-10, -1, -10), v3(10, 0, 10));
    const auto m0 = collide(a0, b0);
    CHECK(m0.touching);
    const double offsets[] = {7.25, 100.0, 1234.5, 10000.0, -30000.0};
    for (const double ox : offsets) {
      const FixedVec3 t = v3(ox, ox / 4, -ox / 2);
      auto shifted = [&](const ConvexShape& s) {
        std::vector<FixedVec3> v;
        for (const auto& p : s.vertices()) v.push_back(p + t);
        return ConvexShape{std::move(v), s.radius()};
      };
      const auto m = collide(shifted(a0), shifted(b0));
      CHECK(m.touching == m0.touching && m.depth == m0.depth &&
            m.normal == m0.normal && m.count == m0.count);
      for (int i = 0; i < m.count && i < m0.count; ++i)
        CHECK(m.points[i].point_a == m0.points[i].point_a + t &&
              m.points[i].point_b == m0.points[i].point_b + t);
    }
  }
  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_narrowphase_test: all checks passed");
  return 0;
}
