// ENG-65: visual soft-body mass-spring lattice and cloth grid (Verlet, <=256 nodes).
#include "poko/physics/soft_body.hpp"

#include <cmath>
#include <cstdio>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using namespace poko::physics;
using namespace poko::math;
}  // namespace

int main() {
  constexpr float dt = 1.0f / 60.0f;

  {  // Node cap enforcement (256 max).
    CHECK(kMaxSoftBodyNodes == 256);
    CHECK(!SoftBody::create_lattice(Vec3f::zero(), 5, 5, 11, 0.5f).has_value());
    auto ok = SoftBody::create_lattice(Vec3f::zero(), 4, 4, 4, 0.5f);
    CHECK(ok.has_value());
    CHECK(ok->node_count() == 64);

    SoftBody cap;
    for (std::size_t i = 0; i < kMaxSoftBodyNodes; ++i) {
      CHECK(cap.add_node(Vec3f{static_cast<float>(i), 0.0f, 0.0f}));
    }
    CHECK(!cap.add_node(Vec3f::zero()));
    CHECK(cap.node_count() == kMaxSoftBodyNodes);
  }

  {  // Lattice with pinned top corners sags under gravity without exploding.
    auto sb = SoftBody::create_lattice(Vec3f{0.0f, 4.0f, 0.0f}, 3, 3, 2, 0.5f);
    CHECK(sb.has_value());
    sb->pin_node(0, true);
    sb->pin_node(2, true);
    const Vec3f p0 = sb->nodes()[0].position;
    const float y_bottom_init = sb->nodes()[0].position.y;
    for (int i = 0; i < 60; ++i) {
      sb->step(dt);
      sb->collide_plane_y(0.0f);
    }
    CHECK(length(sb->nodes()[0].position - p0) < 1e-6f);
    CHECK(sb->nodes()[6].position.y < y_bottom_init + 1.1f);
    CHECK(sb->nodes()[6].position.y >= 0.0f);
  }

  {  // Sphere collision pushes soft-body nodes outside the sphere.
    auto sb = SoftBody::create_lattice(Vec3f{-0.5f, 1.5f, -0.5f}, 3, 2, 3, 0.5f);
    CHECK(sb.has_value());
    const Vec3f center{0.0f, 0.5f, 0.0f};
    const float radius = 0.8f;
    for (int i = 0; i < 90; ++i) {
      sb->step(dt);
      sb->collide_sphere(center, radius);
    }
    for (const auto& n : sb->nodes()) {
      CHECK(length(n.position - center) >= radius - 1e-3f);
    }
  }

  {  // ClothGrid: <=256 cap, top row pinned, wind from sim_time moves cloth.
    CHECK(!ClothGrid::create(Vec3f::zero(), 17, 16, 0.25f).has_value());
    auto cloth = ClothGrid::create(Vec3f{0.0f, 3.0f, 0.0f}, 8, 8, 0.25f);
    CHECK(cloth.has_value());
    CHECK(cloth->body().node_count() == 64);

    const Vec3f top0 = cloth->body().nodes()[0].position;
    const float z_bottom_init = cloth->body().nodes()[63].position.z;
    for (int i = 0; i < 90; ++i) {
      const float sim_time = static_cast<float>(i) * dt;
      cloth->step(dt, sim_time, Vec3f{0.0f, 0.0f, 1.0f}, 12.0f);
    }
    CHECK(length(cloth->body().nodes()[0].position - top0) < 1e-6f);
    CHECK(cloth->body().nodes()[63].position.z > z_bottom_init + 0.2f);
  }

  if (failures != 0) return 1;
  std::printf("soft_body_test: all checks passed\n");
  return 0;
}
