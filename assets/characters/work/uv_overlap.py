"""Test positive-area overlap between triangles belonging to different meshes.

Shared edges/points are not overlap. The grid is only a broad-phase index;
actual intersections are computed by convex polygon clipping. Coordinates need
not lie in [0, 1]. This detects cross-mesh overlaps, not same-mesh overlaps.
"""
import math
from collections import defaultdict

AREA_EPSILON = 1e-12
GRID_RESOLUTION = 64


def _cross(a, b, p):
    return (b[0] - a[0]) * (p[1] - a[1]) - (b[1] - a[1]) * (p[0] - a[0])


def _signed_area(poly):
    return 0.5 * sum(a[0] * b[1] - a[1] * b[0] for a, b in zip(poly, poly[1:] + poly[:1]))


def intersection_area(a, b):
    """Return the UV area common to two triangles, independent of winding."""
    if abs(_signed_area(list(a))) <= AREA_EPSILON or abs(_signed_area(list(b))) <= AREA_EPSILON:
        return 0.0
    orientation = 1 if _signed_area(list(b)) > 0 else -1
    result = list(a)
    for start, end in zip(b, b[1:] + b[:1]):
        previous_poly = result
        result = []
        if not previous_poly:
            break
        prev = previous_poly[-1]
        prev_d = orientation * _cross(start, end, prev)
        for cur in previous_poly:
            cur_d = orientation * _cross(start, end, cur)
            if (cur_d >= 0) != (prev_d >= 0):
                t = prev_d / (prev_d - cur_d)
                result.append((prev[0] + t * (cur[0] - prev[0]), prev[1] + t * (cur[1] - prev[1])))
            if cur_d >= 0:
                result.append(cur)
            prev, prev_d = cur, cur_d
    return abs(_signed_area(result)) if len(result) >= 3 else 0.0


def find_cross_mesh_overlaps(triangles, max_examples=20):
    """Input: iterable of (mesh_name, triangle of three (u,v) pairs).

    Returns count of overlapping triangle pairs, mesh pairs and examples. Areas
    at or below AREA_EPSILON are treated as zero. Reported areas are per pair;
    they are not the area of the union of overlaps.
    """
    triangles = [(name, tuple((float(u), float(v)) for u, v in points)) for name, points in triangles]
    grid = defaultdict(list)
    candidates = set()
    for i, (name, tri) in enumerate(triangles):
        if len(tri) != 3 or not all(math.isfinite(v) for p in tri for v in p):
            raise ValueError('UV triangles must contain three finite coordinates')
        xs, ys = zip(*tri)
        # Clamp broad-phase cells only, not UV values; this remains conservative
        # for out-of-range UVs while bounding the index to 64x64 cells.
        cell = lambda n: max(0, min(GRID_RESOLUTION - 1, math.floor(n * GRID_RESOLUTION)))
        for x in range(cell(min(xs)), cell(max(xs)) + 1):
            for y in range(cell(min(ys)), cell(max(ys)) + 1):
                for other in grid[(x, y)]:
                    if triangles[other][0] != name:
                        candidates.add((other, i))
                grid[(x, y)].append(i)
    counts = defaultdict(int)
    examples = []
    total = 0
    for i, k in sorted(candidates):
        name_a, a = triangles[i]
        name_b, b = triangles[k]
        area = intersection_area(a, b)
        if area > AREA_EPSILON:
            total += 1
            pair = tuple(sorted((name_a, name_b)))
            counts[pair] += 1
            if len(examples) < max_examples:
                examples.append({'meshes': [name_a, name_b], 'triangle_indices': [i, k], 'uv_triangles': [a, b], 'area': area})
    return {'method': 'triangle clipping after grid broad phase',
            'area_epsilon': AREA_EPSILON, 'triangle_count': len(triangles),
            'candidate_pairs': len(candidates), 'overlapping_triangle_pairs': total,
            'mesh_pairs': [{'meshes': list(k), 'overlapping_triangle_pairs': v} for k, v in sorted(counts.items())],
            'examples': examples}
