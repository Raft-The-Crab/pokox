// ENG-63: sequential impulse solver — translational dynamics, warm start,
// Baumgarte stabilization, island-ordered deterministic constraint solve.
#include "poko/physics/solver.hpp"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <map>
#include <vector>

namespace poko::physics {
namespace {
using math::Fixed;
using math::FixedVec3;

// Tuning constants (Q16.16 raw). Baumgarte beta 0.2 and slop 0.05 follow
// the standard sequential-impulse defaults; the restitution gate is 1.0
// (velocity units) so resting jitter never triggers bounce.
constexpr std::int32_t kBaumgarteRaw = 13107;        // 0.2
constexpr std::int32_t kSlopRaw = 3277;              // ~0.05
constexpr std::int32_t kRestitutionThresholdRaw = 65536;  // 1.0

// Deterministic tangent basis: pick the coordinate axis least aligned
// with n, cross to get t1, then t2 = n x t1. Fixed, no data branching
// beyond the three-way compare.
void tangent_basis(FixedVec3 n, FixedVec3& t1, FixedVec3& t2) {
  const Fixed ax = n.x.abs(), ay = n.y.abs(), az = n.z.abs();
  FixedVec3 ref = ax <= ay && ax <= az ? FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()}
               : ay <= az ? FixedVec3{Fixed::zero(), Fixed::one(), Fixed::zero()}
                          : FixedVec3{Fixed::zero(), Fixed::zero(), Fixed::one()};
  t1 = math::cross(n, ref);
  if (auto u = math::normalized(t1)) t1 = *u;
  t2 = math::cross(n, t1);
}

// Per-contact solve state, built once per solve() in canonical order.
struct ContactState {
  const ContactConstraint* c = nullptr;
  SimBody* a = nullptr;
  SimBody* b = nullptr;
  FixedVec3 n, t1, t2;
  Fixed kn = Fixed::zero();        // effective mass = 1/(imA + imB)
  Fixed lambda_n = Fixed::zero();  // accumulated normal impulse >= 0
  Fixed lambda_t1 = Fixed::zero();
  Fixed lambda_t2 = Fixed::zero();
  Fixed target_vn = Fixed::zero(); // bias + restitution velocity target
};
}  // namespace

void SequentialImpulseSolver::upsert_body(const SimBody& body) {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), body.index,
                             [](const SimBody& b, std::uint32_t i) { return b.index < i; });
  if (it != bodies_.end() && it->index == body.index) *it = body;
  else bodies_.insert(it, body);
}

void SequentialImpulseSolver::remove_body(std::uint32_t index) {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const SimBody& b, std::uint32_t i) { return b.index < i; });
  if (it != bodies_.end() && it->index == index) bodies_.erase(it);
}

void SequentialImpulseSolver::clear() noexcept {
  bodies_.clear();
  contacts_.clear();
  warm_.clear();
}

const SimBody* SequentialImpulseSolver::find_body(std::uint32_t index) const noexcept {
  auto it = std::lower_bound(bodies_.begin(), bodies_.end(), index,
                             [](const SimBody& b, std::uint32_t i) { return b.index < i; });
  return (it != bodies_.end() && it->index == index) ? &*it : nullptr;
}

void SequentialImpulseSolver::begin_step() {
  contacts_.clear();
  step_keys_.clear();
}

bool SequentialImpulseSolver::add_contact(const ContactConstraint& c) {
  if (c.body_a == c.body_b) return false;
  if (!step_keys_.insert(c.key).second) return false;
  contacts_.push_back(c);
  return true;
}

void SequentialImpulseSolver::solve(math::Fixed dt, std::uint32_t iterations) {
  // Canonical constraint order: (min body index, max body index, key).
  std::sort(contacts_.begin(), contacts_.end(),
            [](const ContactConstraint& x, const ContactConstraint& y) {
              const auto kx = std::minmax(x.body_a, x.body_b);
              const auto ky = std::minmax(y.body_a, y.body_b);
              if (kx.first != ky.first) return kx.first < ky.first;
              if (kx.second != ky.second) return kx.second < ky.second;
              return x.key < y.key;
            });

  // Union-find over contact-linked bodies -> island id per contact.
  // Island order key = lowest member body index (deterministic).
  std::map<std::uint32_t, std::uint32_t> parent;
  auto find = [&](std::uint32_t x) {
    auto it = parent.find(x);
    if (it == parent.end()) { parent[x] = x; return x; }
    std::uint32_t r = x;
    while (parent[r] != r) r = parent[r];
    while (parent[x] != r) { auto nx = parent[x]; parent[x] = r; x = nx; }
    return r;
  };
  for (const auto& c : contacts_) {
    parent.try_emplace(c.body_a, c.body_a);
    parent.try_emplace(c.body_b, c.body_b);
    const auto ra = find(c.body_a), rb = find(c.body_b);
    if (ra != rb) parent[std::max(ra, rb)] = std::min(ra, rb);
  }
  std::map<std::uint32_t, std::uint32_t> island_min;
  for (const auto& [idx, _] : parent) {
    const std::uint32_t root = find(idx);
    auto [it, ins] = island_min.emplace(root, idx);
    if (!ins && idx < it->second) it->second = idx;
  }

  // Build per-contact state; degenerate contacts (missing body, zero
  // normal, both-static, non-finite effective mass) are skipped but
  // still occupy their canonical slot so ordering is unaffected.
  const Fixed baumgarte = Fixed::from_raw(kBaumgarteRaw);
  const Fixed slop = Fixed::from_raw(kSlopRaw);
  const Fixed rest_thresh = Fixed::from_raw(kRestitutionThresholdRaw);
  const auto inv_dt = dt > Fixed::zero() ? math::divide(Fixed::one(), dt) : std::nullopt;

  std::vector<ContactState> states;
  states.reserve(contacts_.size());
  for (const auto& c : contacts_) {
    ContactState s;
    s.c = &c;
    auto it_a = std::lower_bound(bodies_.begin(), bodies_.end(), c.body_a,
                                 [](const SimBody& b, std::uint32_t i) { return b.index < i; });
    auto it_b = std::lower_bound(bodies_.begin(), bodies_.end(), c.body_b,
                                 [](const SimBody& b, std::uint32_t i) { return b.index < i; });
    if (it_a == bodies_.end() || it_a->index != c.body_a ||
        it_b == bodies_.end() || it_b->index != c.body_b)
      continue;
    auto un = math::normalized(c.normal);
    if (!un.has_value()) continue;
    const Fixed im_sum = it_a->inv_mass + it_b->inv_mass;
    if (im_sum.is_zero()) continue;  // both static: nothing to solve
    auto kn = math::divide(Fixed::one(), im_sum);
    if (!kn.has_value()) continue;

    s.a = &*it_a;
    s.b = &*it_b;
    s.n = *un;
    tangent_basis(s.n, s.t1, s.t2);
    s.kn = *kn;

    // Target separating velocity along n: Baumgarte on penetration beyond
    // slop plus restitution on fast enough approach. vn = dot(n, vA - vB);
    // positive vn separates (n points B -> A).
    Fixed target = Fixed::zero();
    const Fixed pen = c.depth - slop;
    if (pen > Fixed::zero() && inv_dt.has_value())
      target = target + pen * baumgarte * *inv_dt;
    const Fixed vn0 = math::dot(s.n, it_a->velocity - it_b->velocity);
    const Fixed approach = -vn0;
    if (c.restitution > Fixed::zero() && approach > rest_thresh)
      target = target + approach * c.restitution;
    s.target_vn = target;

    // Warm start: replay the persisted accumulated impulses once.
    if (auto w = warm_.find(c.key); w != warm_.end()) {
      s.lambda_n = w->second.normal;
      s.lambda_t1 = w->second.tangent1;
      s.lambda_t2 = w->second.tangent2;
      auto apply = [&](FixedVec3 dir, Fixed j) {
        s.a->velocity += dir * (j * s.a->inv_mass);
        s.b->velocity -= dir * (j * s.b->inv_mass);
      };
      if (!s.lambda_n.is_zero()) apply(s.n, s.lambda_n);
      if (!s.lambda_t1.is_zero()) apply(s.t1, s.lambda_t1);
      if (!s.lambda_t2.is_zero()) apply(s.t2, s.lambda_t2);
    }
    states.push_back(s);
  }

  // Island-ordered solve: stable sort by island min body index keeps the
  // canonical contact order inside each island.
  std::stable_sort(states.begin(), states.end(), [&](const ContactState& x,
                                                     const ContactState& y) {
    const std::uint32_t rx = find(x.c->body_a), ry = find(y.c->body_a);
    return island_min.at(rx) < island_min.at(ry);
  });

  // PGS iterations. Per contact:
  //   normal:  lambda_n += kn * (target_vn - vn), clamped >= 0
  //   friction: lambda_t += -kn * vt, clamped to +/- mu * lambda_n
  // Impulse J along dir gives dvA = +dir*J*imA, dvB = -dir*J*imB, so
  // d(dot(dir, vA - vB)) = J / kn.
  for (std::uint32_t it = 0; it < iterations; ++it) {
    for (auto& s : states) {
      const FixedVec3 vrel = s.a->velocity - s.b->velocity;
      const Fixed vn = math::dot(s.n, vrel);
      const Fixed d_n = s.kn * (s.target_vn - vn);
      const Fixed new_n = std::max(Fixed::zero(), s.lambda_n + d_n);
      const Fixed applied_n = new_n - s.lambda_n;
      if (!applied_n.is_zero()) {
        s.a->velocity += s.n * (applied_n * s.a->inv_mass);
        s.b->velocity -= s.n * (applied_n * s.b->inv_mass);
      }
      s.lambda_n = new_n;

      const Fixed mu = s.c->friction < Fixed::zero() ? Fixed::zero() : s.c->friction;
      const Fixed max_f = mu * s.lambda_n;
      const FixedVec3 vrel_t = s.a->velocity - s.b->velocity;
      for (int axis = 0; axis < 2; ++axis) {
        const FixedVec3 t = axis == 0 ? s.t1 : s.t2;
        const Fixed vt = math::dot(t, vrel_t);
        const Fixed d_t = -s.kn * vt;
        Fixed& lam = axis == 0 ? s.lambda_t1 : s.lambda_t2;
        Fixed dl = lam + d_t;
        if (dl > max_f) dl = max_f;
        if (dl < -max_f) dl = -max_f;
        const Fixed applied_t = dl - lam;
        if (!applied_t.is_zero()) {
          s.a->velocity += t * (applied_t * s.a->inv_mass);
          s.b->velocity -= t * (applied_t * s.b->inv_mass);
        }
        lam = dl;
      }
    }
  }

  // Persist warm-start caches; keys absent this step are evicted.
  warm_.clear();
  for (const auto& s : states) {
    warm_[s.c->key] = ImpulseCache{s.lambda_n, s.lambda_t1, s.lambda_t2};
  }
}

void SequentialImpulseSolver::integrate(math::Fixed dt) noexcept {
  for (auto& b : bodies_) {
    if (b.inv_mass.is_zero() && !b.kinematic) continue;  // static
    const FixedVec3 step = b.velocity * dt;
    for (std::size_t i = 0; i < 3; ++i) {
      const std::int64_t sum = static_cast<std::int64_t>(b.position[i].raw()) + step[i].raw();
      b.position[i] = Fixed::from_raw(static_cast<std::int32_t>(std::clamp<std::int64_t>(
          sum, std::numeric_limits<std::int32_t>::min(), std::numeric_limits<std::int32_t>::max())));
    }
  }
}

}  // namespace poko::physics
