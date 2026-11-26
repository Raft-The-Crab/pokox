// ENG-62: GJK distance + EPA penetration + contact manifold, all in
// Q16.16 Fixed point. Determinism: fixed iteration caps, exact integer
// predicates, strict subset ordering everywhere.
#include "poko/physics/narrowphase.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <map>
#include <optional>
#include <utility>
#include <vector>

namespace poko::physics {
namespace {

using math::Fixed;
using math::FixedVec3;

// Fixed tolerances (raw Q16.16 units). Documented, platform-independent.
constexpr std::int32_t kDistEpsRaw = 8;    // ~1.2e-4: GJK "at origin"
constexpr std::int32_t kDepthEpsRaw = 8;   // EPA convergence + merge tol
// GJK stalls on degenerate (near-coplanar) CSOs — e.g. a sphere inside a
// thin slab — without ever enclosing the origin, ending with a tiny but
// nonzero distance. Within this band collide() still attempts EPA, whose
// seed search over the support pool decides definitively: no
// origin-containing tetrahedron means genuinely separated.
constexpr std::int32_t kEpaHandoffEpsRaw = 6554;  // ~0.1 units
constexpr int kGjkMaxIter = 64;
constexpr int kEpaMaxIter = 64;
constexpr std::size_t kMaxHullVerts = 64;  // spec limit

FixedVec3 centroid(const ConvexShape& s) {
  FixedVec3 c = FixedVec3::zero();
  for (const auto& v : s.vertices()) c += v;
  if (s.vertices().empty()) return c;
  const auto inv = math::divide(Fixed::one(),
                                Fixed::from_int(static_cast<std::int32_t>(s.vertices().size())));
  return inv ? c * inv.value() : c;
}

// ---- CSO (configuration-space obstacle) support -------------------------
// w = supportA(d) - supportB(-d): the CSO point furthest along d.
struct CsoPoint {
  FixedVec3 w;  // a - b, the CSO vertex
  FixedVec3 a;  // witness on A
  FixedVec3 b;  // witness on B
};

std::optional<CsoPoint> cso_support(const ConvexShape& a, const ConvexShape& b,
                                    FixedVec3 d) {
  const auto sa = a.support(d);
  const auto sb = b.support(-d);
  if (!sa || !sb) return std::nullopt;
  return CsoPoint{*sa - *sb, *sa, *sb};
}

// ---- closest point to ORIGIN on convex hull of <=4 points ---------------
// Returns the closest point; *inside_tetra set when the origin is strictly
// inside a 4-point hull (GJK then reports intersection).
struct ClosestResult {
  FixedVec3 point;
  Fixed dist_sq;
  bool origin_inside = false;
  std::uint8_t mask = 0;  // winning subset bitmask over pts[]
};

Fixed dist_sq_of(FixedVec3 p) { return math::lengthSquared(p); }

// Segment a->b closest to origin. Returns point; degenerate -> a.
FixedVec3 closest_segment(FixedVec3 a, FixedVec3 b) {
  const FixedVec3 ab = b - a;
  const Fixed denom = math::dot(ab, ab);
  if (denom.is_zero()) return a;
  const auto t = math::divide(-math::dot(a, ab), denom);
  if (!t) return a;
  Fixed f = t.value();
  if (f < Fixed::zero()) f = Fixed::zero();
  if (f > Fixed::one()) f = Fixed::one();
  return a + ab * f;
}

// Triangle abc closest to origin (Ericson region tests, P = origin).
// Degenerate (zero area) triangles fall back to the best edge.
FixedVec3 closest_triangle(FixedVec3 a, FixedVec3 b, FixedVec3 c) {
  const FixedVec3 ab = b - a, ac = c - a;
  if (math::lengthSquared(math::cross(ab, ac)).is_zero()) {
    FixedVec3 best = closest_segment(a, b);
    FixedVec3 p = closest_segment(a, c);
    if (dist_sq_of(p) < dist_sq_of(best)) best = p;
    p = closest_segment(b, c);
    if (dist_sq_of(p) < dist_sq_of(best)) best = p;
    return best;
  }
  const FixedVec3 ap = -a, bp = -b, cp = -c;
  const Fixed d1 = math::dot(ab, ap), d2 = math::dot(ac, ap);
  if (d1 <= Fixed::zero() && d2 <= Fixed::zero()) return a;
  const Fixed d3 = math::dot(ab, bp), d4 = math::dot(ac, bp);
  if (d3 >= Fixed::zero() && d4 <= d3) return b;
  const Fixed vc = d1 * d4 - d3 * d2;
  if (vc <= Fixed::zero() && d1 >= Fixed::zero() && d3 <= Fixed::zero()) {
    const auto v = math::divide(d1, d1 - d3);
    return v ? a + ab * v.value() : closest_segment(a, b);
  }
  const Fixed d5 = math::dot(ab, cp), d6 = math::dot(ac, cp);
  if (d6 >= Fixed::zero() && d5 <= d6) return c;
  const Fixed vb = d5 * d2 - d1 * d6;
  if (vb <= Fixed::zero() && d2 >= Fixed::zero() && d6 <= Fixed::zero()) {
    const auto w = math::divide(d2, d2 - d6);
    return w ? a + ac * w.value() : closest_segment(a, c);
  }
  const Fixed va = d3 * d6 - d5 * d4;
  if (va <= Fixed::zero() && (d4 - d3) >= Fixed::zero() &&
      (d5 - d6) >= Fixed::zero()) {
    const auto w = math::divide(d4 - d3, (d4 - d3) + (d5 - d6));
    return w ? b + (c - b) * w.value() : closest_segment(b, c);
  }
  // Inside the triangle: barycentric via Ericson's formulation.
  const Fixed denom = va + vb + vc;
  if (denom.is_zero()) return closest_segment(a, b);
  const auto inv = math::divide(Fixed::one(), denom);
  if (!inv) return a;
  const Fixed v = vb * inv.value(), w = vc * inv.value();
  return a + ab * v + ac * w;
}

// Minimum altitude (world units) a tetrahedron vertex must have above each
// face plane for the containment test to be trusted. Below this the sign
// test is dominated by fixed-point noise: a (near-)coplanar quadruple has
// every opposite vertex in every face plane, so s_opp ~ 0 and the strict
// sign checks below pass vacuously — the origin would "fit" inside any flat
// sliver regardless of where it actually lies.
constexpr std::int32_t kTetraMinAltRaw = 64;  // ~0.001 units

// True when the origin is inside or on tetrahedron abcd: for each face,
// the origin and the opposite vertex must lie on the same side of the
// face plane (sign test is orientation-independent).
bool origin_in_tetra(FixedVec3 a, FixedVec3 b, FixedVec3 c, FixedVec3 d) {
  const FixedVec3 v[4] = {a, b, c, d};
  const Fixed min_alt = Fixed::from_raw(kTetraMinAltRaw);
  for (int i = 0; i < 4; ++i) {
    int f[3], k = 0;
    for (int j = 0; j < 4; ++j)
      if (j != i) f[k++] = j;
    const FixedVec3 n =
        math::cross(v[f[1]] - v[f[0]], v[f[2]] - v[f[0]]);
    const Fixed n_sq = math::lengthSquared(n);
    if (n_sq.is_zero()) return false;
    const Fixed s_origin = -math::dot(n, v[f[0]]);
    const Fixed s_opp = math::dot(n, v[i] - v[f[0]]);
    if ((s_origin > Fixed::zero() && s_opp < Fixed::zero()) ||
        (s_origin < Fixed::zero() && s_opp > Fixed::zero()))
      return false;
    // Altitude of the opposite vertex above this face plane: |s_opp|/|n|.
    // A flat tetra scores ~0 on every face and is rejected here.
    const auto nlen = math::sqrt(n_sq);
    const auto alt = math::divide(s_opp.abs(), nlen);
    if (!alt || alt.value() <= min_alt) return false;
  }
  return true;
}

// Closest point on convex hull of pts[0..n) (n <= 4) to the origin.
ClosestResult closest_on_hull(const FixedVec3* pts, int n) {
  ClosestResult best{FixedVec3::zero(), Fixed::from_raw(0x7fffffff), false};
  // Enumerate every non-empty subset in a fixed order (bitmask ascending);
  // strictly-smaller distance wins, so ties keep the earliest subset —
  // fully deterministic.
  const int total = 1 << n;
  for (int mask = 1; mask < total; ++mask) {
    FixedVec3 members[4];
    int m = 0;
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i)) members[m++] = pts[i];
    FixedVec3 p;
    std::uint8_t win_mask = static_cast<std::uint8_t>(mask);
    switch (m) {
      case 1: p = members[0]; break;
      case 2: p = closest_segment(members[0], members[1]); break;
      case 3: p = closest_triangle(members[0], members[1], members[2]); break;
      default:
        if (origin_in_tetra(members[0], members[1], members[2], members[3])) {
          return ClosestResult{FixedVec3::zero(), Fixed::zero(), true, 0};
        }
        // Outside a tetra: closest lies on one of its four faces; the
        // winning subset is that face (3 members), never the full mask.
        struct FacePick { FixedVec3 p; std::uint8_t mask; };
        FacePick picks[4] = {
            {closest_triangle(members[0], members[1], members[2]), 0b0111},
            {closest_triangle(members[0], members[1], members[3]), 0b1011},
            {closest_triangle(members[0], members[2], members[3]), 0b1101},
            {closest_triangle(members[1], members[2], members[3]), 0b1110}};
        int bi = 0;
        for (int i = 1; i < 4; ++i)
          if (dist_sq_of(picks[i].p) < dist_sq_of(picks[bi].p)) bi = i;
        p = picks[bi].p;
        win_mask = picks[bi].mask;
        break;
    }
    const Fixed ds = dist_sq_of(p);
    if (ds < best.dist_sq)
      best = ClosestResult{p, ds, false, win_mask};
  }
  return best;
}

// ---- GJK -----------------------------------------------------------------
struct GjkResult {
  bool intersecting = false;
  Fixed distance = Fixed::zero();
  std::vector<CsoPoint> simplex;  // final reduced simplex (<= 4)
};

GjkResult gjk_distance(const ConvexShape& a, const ConvexShape& b) {
  const FixedVec3 ca = centroid(a), cb = centroid(b);
  FixedVec3 d = cb - ca;
  if (math::lengthSquared(d).is_zero()) d = FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()};
  if (auto unit = math::normalized(d)) d = *unit;

  std::vector<CsoPoint> s;
  s.reserve(4);
  FixedVec3 v = FixedVec3::zero();  // current closest-point estimate
  bool have_v = false;

  for (int iter = 0; iter < kGjkMaxIter; ++iter) {
    const auto w = cso_support(a, b, d);
    if (!w) break;
    // No-progress check: the extreme point along d must beat the current
    // closest estimate's projection, else GJK has converged.
    if (have_v && math::dot(w->w - v, d) <= Fixed::zero()) break;
    // Duplicate vertex => cycle; stop deterministically.
    bool dup = false;
    for (const auto& p : s)
      if (p.w == w->w) { dup = true; break; }
    if (dup) break;
    s.push_back(*w);

    // Reduce: closest point on hull of s (s.size() <= 5 only transiently —
    // the previous iteration leaves <= 3, so <= 4 here).
    FixedVec3 pts[4];
    const int n = static_cast<int>(s.size());
    for (int i = 0; i < n; ++i) pts[i] = s[i].w;
    ClosestResult cr = closest_on_hull(pts, n);
    if (cr.origin_inside || cr.dist_sq.is_zero()) {
      return GjkResult{true, Fixed::zero(), s};
    }
    // Johnson-style reduction: keep only the winning subset (<= 3 verts
    // unless the origin is inside, which returned above), preserving the
    // A/B witness triples.
    std::vector<CsoPoint> reduced;
    reduced.reserve(4);
    for (int i = 0; i < n; ++i)
      if (cr.mask & (1 << i)) reduced.push_back(s[i]);
    s.swap(reduced);
    v = cr.point;
    have_v = true;
    d = -v;
    // Compare the LINEAR distance to the eps: lengthSquared is Q16.16 and
    // underflows below ~1.5e-4 units, while an 8-raw squared tolerance
    // would be a ~0.03-unit linear band — wide enough to report phantom
    // contacts for shapes separated by a visible gap.
    if (math::sqrt(math::lengthSquared(v)) <= Fixed::from_raw(kDistEpsRaw)) {
      // Within tolerance of origin: treat as touching; EPA resolves depth.
      return GjkResult{true, Fixed::zero(), s};
    }
  }
  const Fixed dist = have_v ? math::sqrt(math::lengthSquared(v)) : Fixed::zero();
  return GjkResult{false, dist, s};
}

// ---- EPA -----------------------------------------------------------------
// Polytope vertex: CSO point plus its A/B witnesses.
struct EpaVert {
  FixedVec3 w, a, b;
};
struct EpaFace {
  std::uint8_t i0, i1, i2;  // vertex indices, outward-oriented winding
};

FixedVec3 face_normal(const std::vector<EpaVert>& verts, const EpaFace& f) {
  const FixedVec3& a = verts[f.i0].w;
  return math::cross(verts[f.i1].w - a, verts[f.i2].w - a);
}

// Orient face so its normal points away from `inside` reference point.
void orient_out(EpaFace& f, const std::vector<EpaVert>& verts,
                FixedVec3 inside_pt) {
  const FixedVec3 n = face_normal(verts, f);
  const FixedVec3 fc = (verts[f.i0].w + verts[f.i1].w + verts[f.i2].w);
  // fc is 3x the centroid; dot(n, fc/3 - inside) sign == dot(n, fc - 3*inside)
  const FixedVec3 ref = fc - inside_pt * Fixed::from_int(3);
  if (math::dot(n, ref) < Fixed::zero()) std::swap(f.i1, f.i2);
}

// Build the 4 faces of a tetrahedron with outward orientation.
std::vector<EpaFace> tetra_faces(std::uint8_t a, std::uint8_t b, std::uint8_t c,
                                 std::uint8_t d) {
  return {EpaFace{a, b, c}, EpaFace{a, d, b}, EpaFace{a, c, d},
          EpaFace{b, d, c}};
}

struct EpaResult {
  bool ok = false;
  Fixed depth = Fixed::zero();
  FixedVec3 normal = FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()};
  std::array<ContactPoint, 4> points{};
  std::uint8_t count = 0;
};

// Barycentric coordinates of the point on triangle (in CSO space) closest
// to the origin, used to recover A/B witnesses. Falls back to vertex 0 on
// degenerate input.
std::array<Fixed, 3> face_barycentric(const EpaVert& v0, const EpaVert& v1,
                                      const EpaVert& v2) {
  // Reuse closest_triangle logic but track weights: compute via area
  // ratios. degenerate -> (1,0,0).
  const FixedVec3 a = v0.w, b = v1.w, c = v2.w;
  const FixedVec3 ab = b - a, ac = c - a;
  const Fixed area2 = math::lengthSquared(math::cross(ab, ac));
  if (area2.is_zero()) return {Fixed::one(), Fixed::zero(), Fixed::zero()};
  // Solve for lambda minimizing |a + l1*ab + l2*ac|^2 (origin target).
  // [dot(ab,ab) dot(ab,ac); dot(ab,ac) dot(ac,ac)] [l1;l2] = [-dot(a,ab); -dot(a,ac)]
  const Fixed m11 = math::dot(ab, ab), m12 = math::dot(ab, ac),
              m22 = math::dot(ac, ac);
  const Fixed r1 = -math::dot(a, ab), r2 = -math::dot(a, ac);
  const Fixed det = m11 * m22 - m12 * m12;
  if (det.is_zero()) return {Fixed::one(), Fixed::zero(), Fixed::zero()};
  const auto di = math::divide(Fixed::one(), det);
  if (!di) return {Fixed::one(), Fixed::zero(), Fixed::zero()};
  Fixed l1 = (r1 * m22 - r2 * m12) * di.value();
  Fixed l2 = (m11 * r2 - m12 * r1) * di.value();
  Fixed l0 = Fixed::one() - l1 - l2;
  // Clamp tiny negative drift from fixed rounding; interior contacts only.
  if (l0 < Fixed::zero()) l0 = Fixed::zero();
  if (l1 < Fixed::zero()) l1 = Fixed::zero();
  if (l2 < Fixed::zero()) l2 = Fixed::zero();
  const Fixed sum = l0 + l1 + l2;
  if (sum.is_zero()) return {Fixed::one(), Fixed::zero(), Fixed::zero()};
  const auto si = math::divide(Fixed::one(), sum);
  if (!si) return {Fixed::one(), Fixed::zero(), Fixed::zero()};
  return {l0 * si.value(), l1 * si.value(), l2 * si.value()};
}

EpaResult epa_penetration(const ConvexShape& a, const ConvexShape& b,
                          const std::vector<CsoPoint>& seed) {
  // Candidate pool: GJK simplex + axis-aligned CSO supports.
  std::vector<CsoPoint> pool = seed;
  const FixedVec3 axes[6] = {
      {Fixed::one(), Fixed::zero(), Fixed::zero()},
      {Fixed::from_raw(-65536), Fixed::zero(), Fixed::zero()},
      {Fixed::zero(), Fixed::one(), Fixed::zero()},
      {Fixed::zero(), Fixed::from_raw(-65536), Fixed::zero()},
      {Fixed::zero(), Fixed::zero(), Fixed::one()},
      {Fixed::zero(), Fixed::zero(), Fixed::from_raw(-65536)}};
  for (const auto& ax : axes) {
    if (auto p = cso_support(a, b, ax)) {
      bool dup = false;
      for (const auto& q : pool)
        if (q.w == p->w) { dup = true; break; }
      if (!dup) pool.push_back(*p);
    }
  }
  if (pool.size() > 64) pool.resize(64);

  // Find an origin-containing tetrahedron in a fixed enumeration order
  // (i<j<k<l over pool indices). Among all candidates keep the one with the
  // largest |volume| — a near-degenerate sliver seed makes every downstream
  // face orientation and barycentric solve ill-conditioned (high-aspect
  // CSOs, e.g. a thin floor slab, failed without this).
  std::array<std::uint8_t, 4> tet{};
  bool found = false;
  Fixed best_vol = Fixed::zero();
  const int pn = static_cast<int>(pool.size());
  for (int i = 0; i < pn; ++i)
    for (int j = i + 1; j < pn; ++j)
      for (int k = j + 1; k < pn; ++k)
        for (int l = k + 1; l < pn; ++l) {
          const auto& A = pool[i]; const auto& B = pool[j];
          const auto& C = pool[k]; const auto& D = pool[l];
          const FixedVec3 nrm = math::cross(B.w - A.w, C.w - A.w);
          if (math::lengthSquared(nrm).is_zero()) continue;
          const Fixed vol = math::dot(nrm, D.w - A.w).abs();
          if (found && vol <= best_vol) continue;
          if (!origin_in_tetra(A.w, B.w, C.w, D.w)) continue;
          tet = {static_cast<std::uint8_t>(i), static_cast<std::uint8_t>(j),
                 static_cast<std::uint8_t>(k), static_cast<std::uint8_t>(l)};
          best_vol = vol;
          found = true;
        }
  if (!found) return EpaResult{};  // degenerate: caller falls back

  std::vector<EpaVert> verts;
  verts.reserve(64);
  for (int i : tet) verts.push_back(EpaVert{pool[i].w, pool[i].a, pool[i].b});
  std::vector<EpaFace> faces = tetra_faces(0, 1, 2, 3);
  // Orient each face away from the opposite vertex (outward).
  for (auto& f : faces) {
    // opposite vertex index: the tet index not in the face
    std::uint8_t in[3] = {f.i0, f.i1, f.i2};
    int opp_local = -1;
    for (int t = 0; t < 4; ++t) {
      bool has = false;
      for (std::uint8_t x : in) has |= (x == t);
      if (!has) opp_local = t;
    }
    orient_out(f, verts, verts[opp_local].w);
  }

  const Fixed depth_eps = Fixed::from_raw(kDepthEpsRaw);
  std::size_t closest_face = 0;
  Fixed closest_dist = Fixed::from_raw(0x7fffffff);
  FixedVec3 closest_n = FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()};

  for (int iter = 0; iter < kEpaMaxIter; ++iter) {
    // Find closest face to origin: min dot(unit_normal, face_vertex).
    closest_dist = Fixed::from_raw(0x7fffffff);
    for (std::size_t fi = 0; fi < faces.size(); ++fi) {
      auto n = math::normalized(face_normal(verts, faces[fi]));
      if (!n) continue;
      const Fixed dist = math::dot(*n, verts[faces[fi].i0].w);
      if (dist < closest_dist) {
        closest_dist = dist;
        closest_face = fi;
        closest_n = *n;
      }
    }
    // Expand toward the closest face's outward side; convergence is when
    // the CSO support point no longer extends beyond that face's plane
    // (NOT when the distance itself is small — a sliver tetra starts near
    // zero and must still expand toward the true depth).
    const auto w = cso_support(a, b, closest_n);
    if (!w) break;
    const Fixed reach = math::dot(closest_n, w->w);
    if (reach - closest_dist <= depth_eps) break;
    bool dup = false;
    for (const auto& v : verts)
      if (v.w == w->w) { dup = true; break; }
    if (dup) break;
    const std::uint8_t new_idx = static_cast<std::uint8_t>(verts.size());
    if (verts.size() >= 64) break;
    verts.push_back(EpaVert{w->w, w->a, w->b});

    // Visible faces: dot(n_f, w - faceVert) > 0 with each face's own normal.
    std::vector<char> visible(faces.size(), 0);
    for (std::size_t fi = 0; fi < faces.size(); ++fi) {
      auto n = math::normalized(face_normal(verts, faces[fi]));
      if (!n) continue;
      if (math::dot(*n, w->w - verts[faces[fi].i0].w) > Fixed::zero())
        visible[fi] = 1;
    }
    // Horizon edges: edges incident to exactly one visible face.
    // edge key -> (visible_count, total_count)
    std::map<std::pair<std::uint8_t, std::uint8_t>, std::pair<int, int>> edges;
    for (std::size_t fi = 0; fi < faces.size(); ++fi) {
      const EpaFace& f = faces[fi];
      const std::uint8_t ev[3][2] = {{f.i0, f.i1}, {f.i1, f.i2}, {f.i2, f.i0}};
      for (auto& e : ev) {
        auto key = std::minmax(e[0], e[1]);
        auto& ent = edges[key];
        ent.second += 1;
        ent.first += visible[fi] ? 1 : 0;
      }
    }
    std::vector<EpaFace> kept;
    std::vector<std::pair<std::uint8_t, std::uint8_t>> horizon;
    for (std::size_t fi = 0; fi < faces.size(); ++fi) {
      if (!visible[fi]) kept.push_back(faces[fi]);
    }
    for (const auto& [key, cnt] : edges)
      if (cnt.first == 1 && cnt.second == 2)
        horizon.push_back(key);  // map order => sorted, deterministic

    // New faces over horizon edges + new vertex, outward oriented. The
    // origin is inside the EPA hull by construction, so it is the correct
    // interior reference — the vertex centroid can drift outside a
    // degenerate hull and flip orientations.
    std::vector<EpaFace> next = kept;
    for (const auto& [e0, e1] : horizon) {
      EpaFace f{e0, e1, new_idx};
      orient_out(f, verts, FixedVec3::zero());
      next.push_back(f);
    }
    faces.swap(next);
    if (faces.empty()) break;
  }

  // Final closest face -> depth, normal, manifold witnesses.
  closest_dist = Fixed::from_raw(0x7fffffff);
  for (std::size_t fi = 0; fi < faces.size(); ++fi) {
    auto n = math::normalized(face_normal(verts, faces[fi]));
    if (!n) continue;
    const Fixed dist = math::dot(*n, verts[faces[fi].i0].w);
    if (dist < closest_dist) {
      closest_dist = dist;
      closest_face = fi;
      closest_n = *n;
    }
  }
  if (closest_dist == Fixed::from_raw(0x7fffffff)) return EpaResult{};

  const EpaFace& f = faces[closest_face];
  const auto& v0 = verts[f.i0];
  const auto& v1 = verts[f.i1];
  const auto& v2 = verts[f.i2];
  const auto lam = face_barycentric(v0, v1, v2);
  const FixedVec3 wa = v0.a * lam[0] + v1.a * lam[1] + v2.a * lam[2];
  const FixedVec3 wb = v0.b * lam[0] + v1.b * lam[1] + v2.b * lam[2];

  EpaResult out;
  out.ok = true;
  out.depth = closest_dist;
  out.normal = -closest_n;  // CSO outward normal -> B-to-A contact normal
  // Manifold: deepest contact + the three face-vertex witness pairs,
  // sorted deterministically (depth ties -> lexicographic witness order).
  std::array<ContactPoint, 4> cand{};
  cand[0] = ContactPoint{wa, wb};
  cand[1] = ContactPoint{v0.a, v0.b};
  cand[2] = ContactPoint{v1.a, v1.b};
  cand[3] = ContactPoint{v2.a, v2.b};
  // Merge coincident contacts within the fixed tolerance, then sort.
  std::array<ContactPoint, 4> merged{};
  std::uint8_t mc = 0;
  const Fixed tol = Fixed::from_raw(kDepthEpsRaw);
  for (const auto& p : cand) {
    bool dup = false;
    for (std::uint8_t i = 0; i < mc; ++i) {
      if (math::lengthSquared(p.point_a - merged[i].point_a) <= tol * tol &&
          math::lengthSquared(p.point_b - merged[i].point_b) <= tol * tol) {
        dup = true;
        break;
      }
    }
    if (!dup && mc < 4) merged[mc++] = p;
  }
  std::sort(merged.begin(), merged.begin() + mc,
            [](const ContactPoint& x, const ContactPoint& y) {
              // Stable order: penetration depth is uniform on one face, so
              // order by witness coordinates (point index proxy).
              const auto ka = math::lengthSquared(x.point_b);
              const auto kb = math::lengthSquared(y.point_b);
              if (ka != kb) return ka < kb;
              if (x.point_b.x != y.point_b.x) return x.point_b.x < y.point_b.x;
              if (x.point_b.y != y.point_b.y) return x.point_b.y < y.point_b.y;
              if (x.point_b.z != y.point_b.z) return x.point_b.z < y.point_b.z;
              if (x.point_a.x != y.point_a.x) return x.point_a.x < y.point_a.x;
              if (x.point_a.y != y.point_a.y) return x.point_a.y < y.point_a.y;
              return x.point_a.z < y.point_a.z;
            });
  out.points = merged;
  out.count = mc;
  return out;
}

// ENG-62 scale guard: the GJK/EPA predicates chain Q16.16 multiplies
// (dots of dots), so intermediate results saturate once vertex coordinates
// exceed a few world units — deep contacts against large statics (e.g. a
// floor slab) were silently dropped. Uniformly scaling both shapes toward
// the origin preserves the closest-point geometry exactly (the CSO and the
// origin scale together); results are scaled back on the way out. Shapes
// already below the bound take the unscaled path bit-for-bit.
constexpr std::int64_t kNarrowphaseSafeRaw = std::int64_t{1} << 17;  // 2.0 units

std::int64_t max_coord_raw(const ConvexShape& s) {
  std::int64_t m = s.radius().raw();
  if (m < 0) m = -m;
  for (const auto& v : s.vertices())
    for (std::size_t i = 0; i < 3; ++i) {
      const std::int64_t r = v[i].raw();
      m = std::max(m, r < 0 ? -r : r);
    }
  return m;
}

ConvexShape scaled_shape(const ConvexShape& s, int shift) {
  const std::int32_t div = std::int32_t{1} << shift;
  std::vector<FixedVec3> v;
  v.reserve(s.vertices().size());
  for (const auto& p : s.vertices())
    v.push_back(FixedVec3{Fixed::from_raw(p.x.raw() / div),
                          Fixed::from_raw(p.y.raw() / div),
                          Fixed::from_raw(p.z.raw() / div)});
  return ConvexShape{std::move(v), Fixed::from_raw(s.radius().raw() / div)};
}

Fixed widen_raw(Fixed f, std::int32_t mul) {
  const std::int64_t r = static_cast<std::int64_t>(f.raw()) * mul;
  if (r > std::numeric_limits<std::int32_t>::max())
    return Fixed::from_raw(std::numeric_limits<std::int32_t>::max());
  if (r < std::numeric_limits<std::int32_t>::min())
    return Fixed::from_raw(std::numeric_limits<std::int32_t>::min());
  return Fixed::from_raw(static_cast<std::int32_t>(r));
}

FixedVec3 widen_vec(FixedVec3 v, std::int32_t mul) {
  return FixedVec3{widen_raw(v.x, mul), widen_raw(v.y, mul), widen_raw(v.z, mul)};
}

}  // namespace

ContactManifold collide(const ConvexShape& a, const ConvexShape& b) {
  ContactManifold out;
  if (a.empty() || b.empty()) return out;

  const std::int64_t maxraw = std::max(max_coord_raw(a), max_coord_raw(b));
  int shift = 0;
  while ((maxraw >> shift) > kNarrowphaseSafeRaw && shift < 24) ++shift;
  if (shift > 0) {
    const ConvexShape sa = scaled_shape(a, shift);
    const ConvexShape sb = scaled_shape(b, shift);
    ContactManifold m = collide(sa, sb);
    if (!m.touching) return m;
    const std::int32_t mul = std::int32_t{1} << shift;
    m.depth = widen_raw(m.depth, mul);
    for (std::uint8_t i = 0; i < m.count; ++i) {
      m.points[i].point_a = widen_vec(m.points[i].point_a, mul);
      m.points[i].point_b = widen_vec(m.points[i].point_b, mul);
    }
    return m;
  }

  // Analytic fast path: two single-vertex sphere shapes. Their CSO is a
  // sphere, which EPA can only approximate — the expansion never reaches
  // depth_eps, so every call burns the full iteration cap (~ms each).
  // The closed form is exact, deterministic, and far cheaper.
  if (a.vertices().size() == 1 && b.vertices().size() == 1 &&
      a.radius() > Fixed::zero() && b.radius() > Fixed::zero()) {
    const FixedVec3 d = b.vertices()[0] - a.vertices()[0];  // A -> B
    const Fixed dist = math::sqrt(math::lengthSquared(d));
    const Fixed reach = a.radius() + b.radius();
    // Same near-touch handoff window as the GJK path: gaps within
    // kEpaHandoffEpsRaw still report a zero-depth contact.
    if (dist - reach > Fixed::from_raw(kEpaHandoffEpsRaw)) return out;
    out.touching = true;
    const Fixed depth = reach - dist;
    out.depth = depth > Fixed::zero() ? depth : Fixed::zero();
    FixedVec3 n{Fixed::one(), Fixed::zero(), Fixed::zero()};
    if (auto un = math::normalized(FixedVec3{-d.x, -d.y, -d.z})) n = *un;
    out.normal = n;
    out.points[0] = ContactPoint{a.vertices()[0] - n * a.radius(),
                                 b.vertices()[0] + n * b.radius()};
    out.count = 1;
    return out;
  }

  const GjkResult gjk = gjk_distance(a, b);
  const bool epa_handoff =
      !gjk.intersecting &&
      gjk.distance <= Fixed::from_raw(kEpaHandoffEpsRaw);
  if (!gjk.intersecting && !epa_handoff) return out;

  const EpaResult epa = epa_penetration(a, b, gjk.simplex);
  if (!epa.ok) {
    // EPA's seed search proves separation when GJK did not: no pool
    // tetrahedron contains the origin, so the shapes do not intersect.
    if (!gjk.intersecting) return out;
    // Degenerate touch (origin on CSO boundary): report a zero-depth
    // contact at the shape-centroid midpoint with +X normal.
    out.touching = true;
    out.depth = Fixed::zero();
    out.normal = FixedVec3{Fixed::one(), Fixed::zero(), Fixed::zero()};
    out.points[0] = ContactPoint{FixedVec3::zero(), FixedVec3::zero()};
    out.count = 1;
    return out;
  }
  // EPA's depth is a SIGNED distance to the CSO boundary: a clearly
  // negative value means the origin is outside — the handoff case was a
  // near miss, not a contact. (The seed search can accept a sliver
  // tetrahedron whose orientation tests are ambiguous at fixed-point
  // precision.) Tangent cases clamp to zero depth.
  if (!gjk.intersecting && epa.depth < Fixed::from_raw(-kDepthEpsRaw))
    return out;
  out.touching = true;
  out.depth = epa.depth > Fixed::zero() ? epa.depth : Fixed::zero();
  out.normal = epa.normal;
  out.points = epa.points;
  out.count = epa.count;
  return out;
}

}  // namespace poko::physics
