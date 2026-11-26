// ENG-65: visual f32 solver, analytic sphere/AABB narrowphase, VisualWorld,
// and f32/Fixed type-split boundary checks.
#include "poko/physics/visual_solver.hpp"
#include "poko/foundation/fixed_vec.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <type_traits>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using namespace poko::physics;
using namespace poko::math;

static_assert(!std::is_same_v<Vec3f, FixedVec3>,
              "Visual Vec3f must stay distinct from deterministic FixedVec3");
static_assert(!std::is_convertible_v<Vec3f, FixedVec3>,
              "Visual Vec3f must not implicitly convert to FixedVec3");

VisualBody dyn_sphere(std::uint32_t i, Vec3f p, Vec3f v, float r = 0.5f,
                      float mass = 1.0f) {
  VisualBody b;
  b.index = i;
  b.shape = VisualShape::kSphere;
  b.position = p;
  b.velocity = v;
  b.radius = r;
  b.inv_mass = mass > 0.0f ? 1.0f / mass : 0.0f;
  return b;
}

VisualBody static_box(std::uint32_t i, Vec3f p, Vec3f he) {
  VisualBody b;
  b.index = i;
  b.shape = VisualShape::kBox;
  b.position = p;
  b.half_extents = he;
  b.inv_mass = 0.0f;
  return b;
}
}  // namespace

int main() {
  constexpr float dt = 1.0f / 60.0f;
  const Vec3f up{0.0f, 1.0f, 0.0f};

  {  // Dynamic sphere resting on static floor: solver pushes it up.
    VisualSolver s;
    s.upsert_body(static_box(0, Vec3f{0.0f, -0.5f, 0.0f}, Vec3f{5.0f, 0.5f, 5.0f}));
    s.upsert_body(dyn_sphere(1, Vec3f{0.0f, 0.3f, 0.0f}, Vec3f::zero()));
    s.begin_step();
    VisualContact c;
    c.key = 7;
    c.body_a = 1;
    c.body_b = 0;
    c.normal = up;
    c.depth = 0.2f;
    c.friction = 0.5f;
    s.add_contact(c);
    s.solve(dt);
    const VisualBody* a = s.find_body(1);
    CHECK(a != nullptr);
    CHECK(a->velocity.y > 0.5f);
    CHECK(std::abs(a->velocity.x) < 1e-5f);
    s.integrate(dt);
    CHECK(a->position.y > 0.3f);
  }

  {  // Already separating faster than target: untouched.
    VisualSolver s;
    s.upsert_body(static_box(0, Vec3f::zero(), Vec3f{1.0f, 1.0f, 1.0f}));
    s.upsert_body(dyn_sphere(1, Vec3f{0.0f, 1.8f, 0.0f}, Vec3f{0.0f, 5.0f, 0.0f}));
    s.begin_step();
    VisualContact c;
    c.key = 7;
    c.body_a = 1;
    c.body_b = 0;
    c.normal = up;
    c.depth = 0.2f;
    s.add_contact(c);
    s.solve(dt);
    CHECK(std::abs(s.find_body(1)->velocity.y - 5.0f) < 1e-5f);
  }

  {  // Restitution: fast approach bounces back.
    VisualSolver s;
    s.upsert_body(static_box(0, Vec3f::zero(), Vec3f{1.0f, 1.0f, 1.0f}));
    s.upsert_body(dyn_sphere(1, Vec3f{0.0f, 1.0f, 0.0f}, Vec3f{0.0f, -4.0f, 0.0f}));
    s.begin_step();
    VisualContact c;
    c.key = 11;
    c.body_a = 1;
    c.body_b = 0;
    c.normal = up;
    c.depth = 0.02f;
    c.restitution = 0.5f;
    s.add_contact(c);
    s.solve(dt);
    CHECK(s.find_body(1)->velocity.y > 1.8f);
  }

  {  // Friction slows horizontal slide.
    VisualSolver s;
    s.upsert_body(static_box(0, Vec3f::zero(), Vec3f{5.0f, 0.5f, 5.0f}));
    s.upsert_body(dyn_sphere(1, Vec3f{0.0f, 0.9f, 0.0f}, Vec3f{4.0f, -2.0f, 0.0f}));
    s.begin_step();
    VisualContact c;
    c.key = 13;
    c.body_a = 1;
    c.body_b = 0;
    c.normal = up;
    c.depth = 0.1f;
    c.friction = 0.8f;
    s.add_contact(c);
    s.solve(dt);
    CHECK(s.find_body(1)->velocity.x < 3.0f);
    CHECK(s.find_body(1)->velocity.x >= 0.0f);
  }

  {  // Kinematic body integrates without receiving solver impulses.
    VisualSolver s;
    s.upsert_body(static_box(0, Vec3f::zero(), Vec3f{1.0f, 1.0f, 1.0f}));
    VisualBody k = dyn_sphere(1, Vec3f{0.0f, 0.9f, 0.0f}, Vec3f{0.0f, -2.0f, 0.0f});
    k.inv_mass = 0.0f;
    k.kinematic = true;
    s.upsert_body(k);
    s.begin_step();
    VisualContact c;
    c.key = 17;
    c.body_a = 1;
    c.body_b = 0;
    c.normal = up;
    c.depth = 0.1f;
    s.add_contact(c);
    s.solve(dt);
    CHECK(std::abs(s.find_body(1)->velocity.y - (-2.0f)) < 1e-5f);
    s.integrate(dt);
    CHECK(s.find_body(1)->position.y < 0.9f);
  }

  {  // Analytic narrowphase: sphere-sphere, sphere-box, box-sphere, box-box.
    VisualContact out;
    const VisualBody s1 = dyn_sphere(1, Vec3f{0.0f, 0.8f, 0.0f}, Vec3f::zero(), 0.5f);
    const VisualBody s2 = dyn_sphere(2, Vec3f{0.0f, 0.0f, 0.0f}, Vec3f::zero(), 0.5f);
    CHECK(collide_visual(s1, s2, out));
    CHECK(out.normal.y > 0.99f);
    CHECK(std::abs(out.depth - 0.2f) < 1e-4f);

    const VisualBody s_far = dyn_sphere(3, Vec3f{2.0f, 0.0f, 0.0f}, Vec3f::zero(), 0.5f);
    CHECK(!collide_visual(s_far, s2, out));

    const VisualBody b1 = static_box(4, Vec3f{0.0f, -0.5f, 0.0f}, Vec3f{2.0f, 0.5f, 2.0f});
    const VisualBody s_on_b = dyn_sphere(5, Vec3f{0.0f, 0.4f, 0.0f}, Vec3f::zero(), 0.5f);
    CHECK(collide_visual(s_on_b, b1, out));
    CHECK(out.normal.y > 0.99f);
    CHECK(std::abs(out.depth - 0.1f) < 1e-4f);

    CHECK(collide_visual(b1, s_on_b, out));
    CHECK(out.normal.y < -0.99f);
    CHECK(std::abs(out.depth - 0.1f) < 1e-4f);

    const VisualBody b2 = static_box(6, Vec3f{0.0f, 0.4f, 0.0f}, Vec3f{0.5f, 0.5f, 0.5f});
    CHECK(collide_visual(b2, b1, out));
    CHECK(out.normal.y > 0.99f);
    CHECK(std::abs(out.depth - 0.1f) < 1e-4f);
  }

  {  // VisualWorld: sphere falls onto static floor and settles; two bodies bounce.
    VisualWorld world;
    world.add_collider(Vec3f{0.0f, -0.5f, 0.0f}, Vec3f{10.0f, 0.5f, 10.0f});
    const auto id = world.add_body(
        dyn_sphere(0, Vec3f{0.0f, 2.0f, 0.0f}, Vec3f::zero(), 0.5f, 1.0f));
    CHECK(id != 0);
    for (int i = 0; i < 180; ++i) {
      world.step(dt);
    }
    const VisualBody* settled = world.find_body(id);
    CHECK(settled != nullptr);
    CHECK(settled->position.y > 0.4f && settled->position.y < 0.65f);
    CHECK(std::abs(settled->velocity.y) < 0.25f);
  }

  if (failures != 0) return 1;
  std::printf("visual_solver_test: all checks passed\n");
  return 0;
}
