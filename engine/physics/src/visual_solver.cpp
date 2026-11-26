// ENG-65: f32 visual physics solver — PGS mirror of SequentialImpulseSolver,
// analytic sphere/AABB narrowphase, and VisualWorld convenience layer.
#include "poko/physics/visual_solver.hpp"

#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <vector>

namespace poko::physics {
namespace {
using math::Vec3f;

constexpr float kBaumgarte = 0.2f;
constexpr float kSlop = 0.05f;
constexpr float kRestitutionThreshold = 1.0f;

void tangent_basis(Vec3f n, Vec3f& t1, Vec3f& t2) noexcept {
  const float ax = std::abs(n.x);
  const float ay = std::abs(n.y);
  const float az = std::abs(n.z);
  const Vec3f ref = (ax <= ay && ax <= az) ? Vec3f{1.0f, 0.0f, 0.0f}
                  : (ay <= az)             ? Vec3f{0.0f, 1.0f, 0.0f}
                                           : Vec3f{0.0f, 0.0f, 1.0f};
  t1 = math::normalized(math::cross(n, ref));
  t2 = math::cross(n, t1);
}

struct ContactState {
  const VisualContact* c = nullptr;
  VisualBody* a = nullptr;
  VisualBody* b = nullptr;
  Vec3f n;
  Vec3f t1;
  Vec3f t2;
  float kn = 0.0f;
  float lambda_n = 0.0f;
  float lambda_t1 = 0.0f;
  float lambda_t2 = 0.0f;
  float target_vn = 0.0f;
};

float clampf(float v, float lo, float hi) noexcept {
  return v < lo ? lo : (v > hi ? hi : v);
}

bool collide_sphere_sphere(const VisualBody& a, const VisualBody& b,
                           VisualContact& out) noexcept {
  const Vec3f d = a.position - b.position;
  const float r_sum = a.radius + b.radius;
  const float dist2 = math::lengthSquared(d);
  if (dist2 >= r_sum * r_sum) return false;
  const float dist = std::sqrt(dist2);
  if (dist > 1e-6f) {
    out.normal = d / dist;
    out.depth = r_sum - dist;
    out.point = b.position + out.normal * (b.radius - out.depth * 0.5f);
  } else {
    out.normal = Vec3f{0.0f, 1.0f, 0.0f};
    out.depth = r_sum;
    out.point = a.position;
  }
  return true;
}

bool collide_sphere_box(const VisualBody& sphere, const VisualBody& box,
                        VisualContact& out) noexcept {
  const Vec3f he{std::max(0.0f, box.half_extents.x),
                 std::max(0.0f, box.half_extents.y),
                 std::max(0.0f, box.half_extents.z)};
  const Vec3f rel = sphere.position - box.position;
  const Vec3f closest{clampf(rel.x, -he.x, he.x),
                      clampf(rel.y, -he.y, he.y),
                      clampf(rel.z, -he.z, he.z)};
  const Vec3f delta = rel - closest;
  const float dist2 = math::lengthSquared(delta);
  if (dist2 >= sphere.radius * sphere.radius) return false;

  if (dist2 > 1e-12f) {
    const float dist = std::sqrt(dist2);
    out.normal = delta / dist;
    out.depth = sphere.radius - dist;
    out.point = box.position + closest;
  } else {
    const float px = he.x - std::abs(rel.x);
    const float py = he.y - std::abs(rel.y);
    const float pz = he.z - std::abs(rel.z);
    if (px <= py && px <= pz) {
      out.normal = Vec3f{rel.x >= 0.0f ? 1.0f : -1.0f, 0.0f, 0.0f};
      out.depth = sphere.radius + px;
    } else if (py <= pz) {
      out.normal = Vec3f{0.0f, rel.y >= 0.0f ? 1.0f : -1.0f, 0.0f};
      out.depth = sphere.radius + py;
    } else {
      out.normal = Vec3f{0.0f, 0.0f, rel.z >= 0.0f ? 1.0f : -1.0f};
      out.depth = sphere.radius + pz;
    }
    out.point = sphere.position - out.normal * sphere.radius;
  }
  return true;
}

bool collide_box_box(const VisualBody& a, const VisualBody& b,
                     VisualContact& out) noexcept {
  const Vec3f d = a.position - b.position;
  const float ox = (std::max(0.0f, a.half_extents.x) +
                    std::max(0.0f, b.half_extents.x)) -
                   std::abs(d.x);
  const float oy = (std::max(0.0f, a.half_extents.y) +
                    std::max(0.0f, b.half_extents.y)) -
                   std::abs(d.y);
  const float oz = (std::max(0.0f, a.half_extents.z) +
                    std::max(0.0f, b.half_extents.z)) -
                   std::abs(d.z);
  if (ox <= 0.0f || oy <= 0.0f || oz <= 0.0f) return false;

  if (ox <= oy && ox <= oz) {
    out.normal = Vec3f{d.x >= 0.0f ? 1.0f : -1.0f, 0.0f, 0.0f};
    out.depth = ox;
  } else if (oy <= oz) {
    out.normal = Vec3f{0.0f, d.y >= 0.0f ? 1.0f : -1.0f, 0.0f};
    out.depth = oy;
  } else {
    out.normal = Vec3f{0.0f, 0.0f, d.z >= 0.0f ? 1.0f : -1.0f};
    out.depth = oz;
  }
  out.point = 0.5f * (a.position + b.position);
  return true;
}
}  // namespace

void VisualSolver::upsert_body(const VisualBody& body) {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), body.index,
                             [](const VisualBody& b, std::uint32_t i) {
                               return b.index < i;
                             });
  if (it != bodies_.end() && it->index == body.index) *it = body;
  else bodies_.insert(it, body);
}

void VisualSolver::remove_body(std::uint32_t index) {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const VisualBody& b, std::uint32_t i) {
                               return b.index < i;
                             });
  if (it != bodies_.end() && it->index == index) bodies_.erase(it);
}

void VisualSolver::clear() noexcept {
  bodies_.clear();
  contacts_.clear();
  warm_.clear();
}

const VisualBody* VisualSolver::find_body(std::uint32_t index) const noexcept {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const VisualBody& b, std::uint32_t i) {
                               return b.index < i;
                             });
  return (it != bodies_.end() && it->index == index) ? &*it : nullptr;
}

void VisualSolver::begin_step() {
  contacts_.clear();
  step_keys_.clear();
}

bool VisualSolver::add_contact(const VisualContact& c) {
  if (c.body_a == c.body_b) return false;
  if (!step_keys_.insert(c.key).second) return false;
  contacts_.push_back(c);
  return true;
}

void VisualSolver::solve(float dt_seconds, std::uint32_t iterations) {
  std::sort(contacts_.begin(), contacts_.end(),
            [](const VisualContact& x, const VisualContact& y) {
              const auto kx = std::minmax(x.body_a, x.body_b);
              const auto ky = std::minmax(y.body_a, y.body_b);
              if (kx.first != ky.first) return kx.first < ky.first;
              if (kx.second != ky.second) return kx.second < ky.second;
              return x.key < y.key;
            });

  std::map<std::uint32_t, std::uint32_t> parent;
  auto find = [&](std::uint32_t x) {
    auto it = parent.find(x);
    if (it == parent.end()) {
      parent[x] = x;
      return x;
    }
    std::uint32_t r = x;
    while (parent[r] != r) r = parent[r];
    while (parent[x] != r) {
      const auto nx = parent[x];
      parent[x] = r;
      x = nx;
    }
    return r;
  };
  for (const auto& c : contacts_) {
    parent.try_emplace(c.body_a, c.body_a);
    parent.try_emplace(c.body_b, c.body_b);
    const auto ra = find(c.body_a);
    const auto rb = find(c.body_b);
    if (ra != rb) parent[std::max(ra, rb)] = std::min(ra, rb);
  }
  std::map<std::uint32_t, std::uint32_t> island_min;
  for (const auto& [idx, _] : parent) {
    const std::uint32_t root = find(idx);
    auto [it, ins] = island_min.emplace(root, idx);
    if (!ins && idx < it->second) it->second = idx;
  }

  const float inv_dt = dt_seconds > 0.0f ? (1.0f / dt_seconds) : 0.0f;
  std::vector<ContactState> states;
  states.reserve(contacts_.size());

  for (const auto& c : contacts_) {
    auto it_a = std::lower_bound(bodies_.begin(), bodies_.end(), c.body_a,
                                 [](const VisualBody& b, std::uint32_t i) {
                                   return b.index < i;
                                 });
    auto it_b = std::lower_bound(bodies_.begin(), bodies_.end(), c.body_b,
                                 [](const VisualBody& b, std::uint32_t i) {
                                   return b.index < i;
                                 });
    if (it_a == bodies_.end() || it_a->index != c.body_a ||
        it_b == bodies_.end() || it_b->index != c.body_b) {
      continue;
    }
    const float n_len = math::length(c.normal);
    if (n_len <= 1e-12f) continue;
    const float im_sum = it_a->inv_mass + it_b->inv_mass;
    if (im_sum <= 0.0f) continue;

    ContactState s;
    s.c = &c;
    s.a = &*it_a;
    s.b = &*it_b;
    s.n = c.normal / n_len;
    tangent_basis(s.n, s.t1, s.t2);
    s.kn = 1.0f / im_sum;

    float target = 0.0f;
    const float pen = c.depth - kSlop;
    if (pen > 0.0f && inv_dt > 0.0f) {
      target += pen * kBaumgarte * inv_dt;
    }
    const float vn0 = math::dot(s.n, it_a->velocity - it_b->velocity);
    const float approach = -vn0;
    if (c.restitution > 0.0f && approach > kRestitutionThreshold) {
      target += approach * c.restitution;
    }
    s.target_vn = target;

    if (auto w = warm_.find(c.key); w != warm_.end()) {
      s.lambda_n = w->second.normal;
      s.lambda_t1 = w->second.tangent1;
      s.lambda_t2 = w->second.tangent2;
      auto apply = [&](Vec3f dir, float j) {
        s.a->velocity += dir * (j * s.a->inv_mass);
        s.b->velocity -= dir * (j * s.b->inv_mass);
      };
      if (s.lambda_n != 0.0f) apply(s.n, s.lambda_n);
      if (s.lambda_t1 != 0.0f) apply(s.t1, s.lambda_t1);
      if (s.lambda_t2 != 0.0f) apply(s.t2, s.lambda_t2);
    }
    states.push_back(s);
  }

  std::stable_sort(states.begin(), states.end(),
                   [&](const ContactState& x, const ContactState& y) {
                     const std::uint32_t rx = find(x.c->body_a);
                     const std::uint32_t ry = find(y.c->body_a);
                     return island_min.at(rx) < island_min.at(ry);
                   });

  for (std::uint32_t it = 0; it < iterations; ++it) {
    for (auto& s : states) {
      const Vec3f vrel = s.a->velocity - s.b->velocity;
      const float vn = math::dot(s.n, vrel);
      const float d_n = s.kn * (s.target_vn - vn);
      const float new_n = std::max(0.0f, s.lambda_n + d_n);
      const float applied_n = new_n - s.lambda_n;
      if (applied_n != 0.0f) {
        s.a->velocity += s.n * (applied_n * s.a->inv_mass);
        s.b->velocity -= s.n * (applied_n * s.b->inv_mass);
      }
      s.lambda_n = new_n;

      const float mu = std::max(0.0f, s.c->friction);
      const float max_f = mu * s.lambda_n;
      const Vec3f vrel_t = s.a->velocity - s.b->velocity;
      for (int axis = 0; axis < 2; ++axis) {
        const Vec3f t = axis == 0 ? s.t1 : s.t2;
        const float vt = math::dot(t, vrel_t);
        const float d_t = -s.kn * vt;
        float& lam = axis == 0 ? s.lambda_t1 : s.lambda_t2;
        const float dl = clampf(lam + d_t, -max_f, max_f);
        const float applied_t = dl - lam;
        if (applied_t != 0.0f) {
          s.a->velocity += t * (applied_t * s.a->inv_mass);
          s.b->velocity -= t * (applied_t * s.b->inv_mass);
        }
        lam = dl;
      }
    }
  }

  warm_.clear();
  for (const auto& s : states) {
    warm_[s.c->key] = ImpulseCache{s.lambda_n, s.lambda_t1, s.lambda_t2};
  }
}

void VisualSolver::integrate(float dt_seconds) noexcept {
  for (auto& b : bodies_) {
    if (b.inv_mass == 0.0f && !b.kinematic) continue;
    b.position += b.velocity * dt_seconds;
  }
}

bool collide_visual(const VisualBody& a, const VisualBody& b,
                    VisualContact& out) {
  out.body_a = a.index;
  out.body_b = b.index;
  out.friction = std::min(a.friction, b.friction);
  out.restitution = std::max(a.restitution, b.restitution);

  if (a.shape == VisualShape::kSphere && b.shape == VisualShape::kSphere) {
    return collide_sphere_sphere(a, b, out);
  }
  if (a.shape == VisualShape::kSphere && b.shape == VisualShape::kBox) {
    return collide_sphere_box(a, b, out);
  }
  if (a.shape == VisualShape::kBox && b.shape == VisualShape::kSphere) {
    if (!collide_sphere_box(b, a, out)) return false;
    out.normal = -out.normal;
    return true;
  }
  return collide_box_box(a, b, out);
}

std::uint32_t VisualWorld::add_body(VisualBody body) {
  if (body.index == 0) {
    while (find_body(next_auto_index_) != nullptr ||
           std::any_of(colliders_.begin(), colliders_.end(),
                       [&](const VisualBody& c) {
                         return c.index == next_auto_index_;
                       })) {
      ++next_auto_index_;
    }
    body.index = next_auto_index_++;
  } else if (body.index >= next_auto_index_) {
    next_auto_index_ = body.index + 1;
  }

  if (body.inv_mass == 0.0f && !body.kinematic) {
    auto it = std::lower_bound(colliders_.begin(), colliders_.end(), body.index,
                               [](const VisualBody& c, std::uint32_t i) {
                                 return c.index < i;
                               });
    if (it != colliders_.end() && it->index == body.index) *it = body;
    else colliders_.insert(it, body);
  } else {
    auto it = std::lower_bound(bodies_.begin(), bodies_.end(), body.index,
                               [](const VisualBody& b, std::uint32_t i) {
                                 return b.index < i;
                               });
    if (it != bodies_.end() && it->index == body.index) *it = body;
    else bodies_.insert(it, body);

    if (body.inv_mass > 0.0f &&
        std::find(dynamics_.begin(), dynamics_.end(), body.index) ==
            dynamics_.end()) {
      dynamics_.push_back(body.index);
    }
  }
  solver_.upsert_body(body);
  return body.index;
}

std::uint32_t VisualWorld::add_collider(math::Vec3f center,
                                        math::Vec3f half_extents) {
  VisualBody c;
  c.shape = VisualShape::kBox;
  c.position = center;
  c.half_extents = half_extents;
  c.inv_mass = 0.0f;
  c.kinematic = false;
  return add_body(c);
}

const VisualBody* VisualWorld::find_body(std::uint32_t index) const noexcept {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const VisualBody& b, std::uint32_t i) {
                               return b.index < i;
                             });
  return (it != bodies_.end() && it->index == index) ? &*it : nullptr;
}

VisualBody* VisualWorld::find_body(std::uint32_t index) noexcept {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const VisualBody& b, std::uint32_t i) {
                               return b.index < i;
                             });
  return (it != bodies_.end() && it->index == index) ? &*it : nullptr;
}

void VisualWorld::step(float dt_seconds) {
  for (auto& b : bodies_) {
    if (b.inv_mass > 0.0f && !b.kinematic) {
      b.velocity += gravity_ * dt_seconds;
    }
    solver_.upsert_body(b);
  }
  for (const auto& c : colliders_) {
    solver_.upsert_body(c);
  }

  solver_.begin_step();
  for (std::size_t i = 0; i < bodies_.size(); ++i) {
    for (const auto& col : colliders_) {
      VisualContact contact;
      if (collide_visual(bodies_[i], col, contact)) {
        contact.key =
            (static_cast<std::uint64_t>(bodies_[i].index) << 32) | col.index;
        solver_.add_contact(contact);
      }
    }
    for (std::size_t j = i + 1; j < bodies_.size(); ++j) {
      VisualContact contact;
      if (collide_visual(bodies_[i], bodies_[j], contact)) {
        const auto lo = std::min(bodies_[i].index, bodies_[j].index);
        const auto hi = std::max(bodies_[i].index, bodies_[j].index);
        contact.key = (static_cast<std::uint64_t>(lo) << 32) | hi;
        solver_.add_contact(contact);
      }
    }
  }

  solver_.solve(dt_seconds, VisualSolver::kDefaultIterations);
  solver_.integrate(dt_seconds);

  for (auto& b : bodies_) {
    if (const VisualBody* solved = solver_.find_body(b.index)) {
      b = *solved;
    }
  }
}

}  // namespace poko::physics
