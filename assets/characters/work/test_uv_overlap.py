"""Regression tests independent of Blender: python test_uv_overlap.py."""
import unittest
from uv_overlap import find_cross_mesh_overlaps, intersection_area

class OverlapTests(unittest.TestCase):
    def test_identical_cross_mesh_triangles_are_detected(self):
        tri = ((0, 0), (1, 0), (0, 1))
        result = find_cross_mesh_overlaps([('A', tri), ('B', tri)])
        self.assertEqual(result['overlapping_triangle_pairs'], 1)
        self.assertAlmostEqual(result['examples'][0]['area'], 0.5)

    def test_partial_overlap_with_opposite_winding(self):
        a = ((0, 0), (1, 0), (0, 1))
        b = ((0.25, 0.25), (0.25, 0.75), (0.75, 0.25))
        self.assertAlmostEqual(intersection_area(a, b), 0.125)
        self.assertEqual(find_cross_mesh_overlaps([('A', a), ('B', b)])['overlapping_triangle_pairs'], 1)

    def test_edge_and_point_contact_are_not_overlap(self):
        a = ((0, 0), (1, 0), (0, 1))
        for b in [((1, 0), (1, 1), (0, 1)), ((1, 0), (2, 0), (2, 1))]:
            self.assertEqual(find_cross_mesh_overlaps([('A', a), ('B', b)])['overlapping_triangle_pairs'], 0)

    def test_bounding_boxes_overlap_but_triangles_do_not(self):
        a = ((0, 0), (1, 0), (0, 1))
        b = ((0.8, 0.8), (0.8, 0.3), (0.3, 0.8))
        self.assertEqual(find_cross_mesh_overlaps([('A', a), ('B', b)])['overlapping_triangle_pairs'], 0)

    def test_same_mesh_is_not_counted(self):
        tri = ((0, 0), (1, 0), (0, 1))
        self.assertEqual(find_cross_mesh_overlaps([('A', tri), ('A', tri)])['overlapping_triangle_pairs'], 0)

    def test_outside_atlas_and_degenerate(self):
        tri = ((2, 2), (3, 2), (2, 3))
        self.assertEqual(find_cross_mesh_overlaps([('A', tri), ('B', tri)])['overlapping_triangle_pairs'], 1)
        self.assertEqual(find_cross_mesh_overlaps([('A', tri), ('B', ((2, 2), (2.5, 2.5), (3, 3)))])['overlapping_triangle_pairs'], 0)

    def test_invalid_values_rejected(self):
        with self.assertRaises(ValueError):
            find_cross_mesh_overlaps([('A', ((0, 0), (1, 0), (float('nan'), 1)))])

if __name__ == '__main__':
    unittest.main(verbosity=2)
