// ENG-61: SAP broadphase — deterministic command buffer, sorted pair
// output, insertion-order independence, brute-force cross-check.
#include "poko/physics/sap_broadphase.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <set>
#include <vector>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using poko::math::Fixed;
using poko::math::FixedVec3;
using poko::physics::SapBroadphase;

FixedVec3 lo(int x, int y, int z) {
  return FixedVec3{Fixed::from_int(x), Fixed::from_int(y), Fixed::from_int(z)};
}
SapBroadphase::Bounds box(int x0, int x1) {
  return SapBroadphase::Bounds{lo(x0, 0, 0), lo(x1, 10, 10)};
}

std::vector<SapBroadphase::Pair> sorted_pairs(
    const std::vector<SapBroadphase::Pair>& v) {
  auto out = v;
  std::sort(out.begin(), out.end());
  return out;
}
}  // namespace

int main() {
  {  // empty and single-body broadphases produce no pairs
    SapBroadphase bp;
    CHECK(bp.pairs().empty() && bp.body_count() == 0);
    bp.insert(7, box(0, 5));
    bp.commit();
    CHECK(bp.body_count() == 1 && bp.pairs().empty());
  }
  {  // two overlapping bodies -> exactly one canonical pair
    SapBroadphase bp;
    bp.insert(4, box(0, 10));
    bp.insert(2, box(5, 15));
    bp.commit();
    CHECK(bp.pairs().size() == 1);
    CHECK((bp.pairs()[0] == SapBroadphase::Pair{2, 4}));
  }
  {  // disjoint X intervals -> no pair; touching counts (inclusive)
    SapBroadphase bp;
    bp.insert(0, box(0, 1));
    bp.insert(1, box(2, 3));
    bp.insert(2, box(1, 2));  // touches body0 at x=1 and body1 at x=2? [1,2] vs [0,1] touch, vs [2,3] touch
    bp.commit();
    CHECK(bp.pairs().size() == 2);
    CHECK((bp.pairs()[0] == SapBroadphase::Pair{0, 2}));
    CHECK((bp.pairs()[1] == SapBroadphase::Pair{1, 2}));
  }
  {  // Y/Z separation does not matter: SAP is X-only by design
    SapBroadphase bp;
    SapBroadphase::Bounds a{lo(0, 0, 0), lo(5, 1, 1)};
    SapBroadphase::Bounds b{lo(1, 100, 100), lo(6, 101, 101)};
    bp.insert(0, a);
    bp.insert(1, b);
    bp.commit();
    CHECK(bp.pairs().size() == 1);  // narrowphase rejects later
  }
  {  // command buffer: pairs() reflects last commit only
    SapBroadphase bp;
    bp.insert(0, box(0, 1));
    bp.insert(1, box(0, 1));
    CHECK(bp.pairs().empty());       // nothing committed yet
    bp.commit();
    CHECK(bp.pairs().size() == 1);
    bp.remove(1);
    CHECK(bp.pairs().size() == 1);   // still stale until commit
    bp.commit();
    CHECK(bp.pairs().empty());
    bp.remove(99);                   // absent index: no-op
    bp.commit();
    CHECK(bp.body_count() == 1 && bp.pairs().empty());
  }
  {  // upsert: re-insert replaces bounds; same-tick insert+remove order
    SapBroadphase bp;
    bp.insert(0, box(0, 1));
    bp.insert(1, box(0, 1));
    bp.insert(0, box(50, 60));       // move body0 away
    bp.commit();
    CHECK(bp.pairs().empty());
    bp.insert(0, box(0, 2));
    bp.remove(0);
    bp.commit();                     // submission order: insert then remove
    CHECK(bp.body_count() == 1 && bp.pairs().empty());
    bp.insert(0, box(0, 2));
    bp.commit();
    CHECK(bp.pairs().size() == 1);
  }
  {  // bounds normalization: inverted corners still overlap correctly
    SapBroadphase bp;
    SapBroadphase::Bounds inv{lo(10, 10, 10), lo(0, 0, 0)};
    bp.insert(0, inv);
    bp.insert(1, box(5, 6));
    bp.commit();
    CHECK(bp.pairs().size() == 1);
  }
  {  // insertion-order independence: same final state, different order
    SapBroadphase bp_a, bp_b;
    const std::uint32_t idx[] = {9, 3, 7, 1, 8, 2, 6, 4, 5, 0};
    auto bounds_for = [](std::uint32_t index) {
      return box(static_cast<int>(index % 4) * 3,
                 static_cast<int>(index % 4) * 3 + 5);
    };
    for (std::uint32_t i = 0; i < 10; ++i) {
      // Bounds are a pure function of the body index so both orders build
      // the identical final state.
      bp_a.insert(idx[i], bounds_for(idx[i]));
      bp_b.insert(idx[9 - i], bounds_for(idx[9 - i]));
    }
    bp_a.commit();
    bp_b.commit();
    CHECK(bp_a.pairs().size() == bp_b.pairs().size() &&
          std::equal(bp_a.pairs().begin(), bp_a.pairs().end(),
                     bp_b.pairs().begin()));
    const auto want = sorted_pairs(
        std::vector<SapBroadphase::Pair>(bp_a.pairs().begin(), bp_a.pairs().end()));
    CHECK(bp_a.pairs().size() == want.size() &&
          std::equal(bp_a.pairs().begin(), bp_a.pairs().end(), want.begin()));
  }
  {  // brute-force cross-check: 200 deterministic pseudo-random bodies
    SapBroadphase bp;
    std::vector<std::pair<std::uint32_t, std::pair<int, int>>> bodies;
    std::uint64_t state = 0x123456789abcdef0ull;
    auto next = [&]() {
      state = state * 6364136223846793005ull + 1442695040888963407ull;
      return static_cast<int>((state >> 33) % 400);
    };
    for (std::uint32_t i = 0; i < 200; ++i) {
      const int x0 = next() - 100, x1 = next() - 100;
      const int lo_x = x0 < x1 ? x0 : x1, hi_x = x0 < x1 ? x1 : x0;
      bodies.push_back({i, {lo_x, hi_x}});
      bp.insert(i, box(lo_x, hi_x));
    }
    bp.commit();
    std::set<std::pair<std::uint32_t, std::uint32_t>> want;
    for (std::size_t i = 0; i < bodies.size(); ++i)
      for (std::size_t j = i + 1; j < bodies.size(); ++j)
        if (bodies[i].second.first <= bodies[j].second.second &&
            bodies[j].second.first <= bodies[i].second.second)
          want.insert({bodies[i].first, bodies[j].first});
    CHECK(bp.pairs().size() == want.size());
    std::size_t k = 0;
    bool ordered = true;
    for (const auto& p : want) {
      if (k >= bp.pairs().size() ||
          bp.pairs()[k].a != p.first || bp.pairs()[k].b != p.second) {
        ordered = false;
        break;
      }
      ++k;
    }
    CHECK(ordered);
  }
  {  // multi-tick churn: inserts/removes/updates stay consistent
    SapBroadphase bp;
    for (int tick = 0; tick < 50; ++tick) {
      for (std::uint32_t i = 0; i < 20; ++i) {
        if ((i + tick) % 7 == 0) bp.remove(i);
        else bp.insert(i, box((i * 7 + tick) % 30, (i * 7 + tick) % 30 + 4));
      }
      bp.commit();
      // verify sorted + canonical + no duplicates every tick
      for (std::size_t i = 1; i < bp.pairs().size(); ++i)
        CHECK(bp.pairs()[i - 1] < bp.pairs()[i]);
      for (const auto& p : bp.pairs()) CHECK(p.a < p.b);
    }
  }

  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_sap_broadphase_test: all checks passed");
  return 0;
}
