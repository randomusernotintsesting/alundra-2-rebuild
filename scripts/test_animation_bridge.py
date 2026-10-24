import math
import unittest

from a2.animation_bridge import (part_matrices, transform, multiply, inverse,
                                 fixed_vertex, convert_submission, validate_live_rtp)


class SpaceContractTests(unittest.TestCase):
    def test_rotated_pretranslation_and_root_applied_once(self):
        r = [0, -4096, 0, 4096, 0, 0, 0, 0, 4096]
        actor, part = part_matrices(r, [1, 2, 3], [10, 20, 30], [4, 5, 6],
                                    [4096, 8192, 12288])
        self.assertEqual(transform(part, [2, 3, 4]), [8, 26, 40])
        self.assertEqual(transform(multiply(actor, part), [2, 3, 4]), [9, 28, 43])
        for camera in ([100, -200, 10], [-99, 78, 11]):
            fixed = fixed_vertex([2, 3, 4], r, [1, 2, 3], [10, 20, 30], [4, 5, 6], camera)
            self.assertEqual([fixed[k] + camera[k] for k in range(3)], [9, 28, 43])

    def test_full_inverse_preserves_non_orthonormal_reference(self):
        a, b = part_matrices([4095, 10, 0, 0, 4097, 0, 0, 0, 4096],
                            [0, 0, 0], [-174, 0, 24], [0, 5, 0], [-716768, 0, 99664])
        identity = multiply(b, inverse(b))
        for i, x in enumerate(identity):
            self.assertAlmostEqual(x, int(i % 5 == 0), places=12)
        self.assertAlmostEqual(transform(multiply(a, b), [0, 0, 0])[0], -174)

    def test_signed16_wrap_and_negative_floor_are_not_float_oracle(self):
        r = [4095, 0, 0, 0, 4096, 0, 0, 0, 4096]
        self.assertEqual(fixed_vertex([-1, 32767, 0], r, [0, 1, 0],
                         [0, 0, 32768], [0, 0, 0], [0, 0, 0]), [-1, -32768, -32768])
        _, p = part_matrices(r, [0, 1, 0], [0, 0, 32768], [0, 0, 0], [0, 0, 0])
        self.assertNotEqual(transform(p, [-1, 32767, 0]), [-1, -32768, -32768])

    def test_rejects_nonfinite_bad_shapes_and_singular_bind(self):
        for matrix in ([0] * 15, [math.nan] * 16, [math.inf] * 16):
            with self.assertRaises(ValueError):
                transform(matrix, [0, 0, 0])
        with self.assertRaises(ValueError):
            inverse([0] * 16)
        with self.assertRaises(ValueError):
            part_matrices([4096] * 8, [0] * 3, [0] * 3, [0] * 3, [0] * 3)


class SnapshotContractTests(unittest.TestCase):
    def snapshot(self):
        return dict(schema='a2.animation_bridge.v1', sequence=10, guest_frame=3000,
            valid=True, shadow_pass=False, capture_monotonic_ns=1000000000,
            camera=dict(origin_q12=[0, 0, 0]), instances=[dict(entity_address=1234,
            instance_generation=0, generation_known=False, valid=True,
            actor_world_q12=[4096, 8192, 12288], renderer_root_q12=[4096, 8192, 12288],
            action_id=0, animation=dict(frame=1, length=20, loops=0, selector=0,
            entity_update_calls=10, advance_calls=11), parts=[dict(source_mesh_index=0,
            matrix_q12=[4096,0,0,0,4096,0,0,0,4096],pretranslation=[0,0,0],
            translation0=[1,2,3],translation1=[0,0,0],flags=0,valid=True,visible=True)])])

    def test_missing_pose_stays_null_and_generation_is_not_invented(self):
        s = convert_submission(self.snapshot(), 1234, [0,1])
        self.assertEqual(s['valid_mask'], 1)
        self.assertIsNone(s['parts'][1]['part_to_actor'])
        self.assertIsNone(s['actor_instance_id']['generation'])
        self.assertFalse(s['actor_instance_id']['generation_known'])

    def test_shadow_duplicate_and_nonfinite_rejected(self):
        f = self.snapshot(); f['shadow_pass'] = True
        self.assertIsNone(convert_submission(f,1234,[0]))
        f = self.snapshot(); f['instances'][0]['parts'] *= 2
        with self.assertRaises(ValueError): convert_submission(f,1234,[0])
        f = self.snapshot(); f['instances'][0]['parts'][0]['matrix_q12'][0] = math.nan
        with self.assertRaises(ValueError): convert_submission(f,1234,[0])

    def test_deformation_flag_is_explicit(self):
        f = self.snapshot(); f['instances'][0]['parts'][0]['flags'] = 0x1000
        s = convert_submission(f,1234,[0])
        self.assertTrue(s['parts'][0]['deformed_source'])
        self.assertFalse(s['parts'][0]['matrix_only_reproduction_valid'])

    def test_missing_root_cannot_become_identity_pose(self):
        f = self.snapshot(); f['instances'][0]['fallback'] = 4
        f['instances'][0]['renderer_root_q12'] = [0,0,0]
        with self.assertRaisesRegex(ValueError, 'root'):
            convert_submission(f,1234,[0])

    def test_live_rtp_requires_same_submission_and_exact_coordinates(self):
        import copy
        f = self.snapshot(); f['draw_object_address']=55; f['draw_flags']=0x1800000
        p=f['instances'][0]['parts'][0]
        f['instances'][0]['parts']=[dict(copy.deepcopy(p),source_mesh_index=i) for i in range(16)]
        geometry={i:dict(vertices_local=[[i,0,0]]) for i in range(16)}
        b=dict(frame=3000,object=55,flags=0x1800000,camera_q12=[0,0,0],
               inputs=[[i+1,2,3] for i in range(16)])
        self.assertEqual(validate_live_rtp(f,b,geometry,1234),16)
        b['inputs'][10][0]+=1
        with self.assertRaisesRegex(ValueError,'mismatch'):
            validate_live_rtp(f,b,geometry,1234)
        b['frame']=2999
        with self.assertRaisesRegex(ValueError,'provenance'):
            validate_live_rtp(f,b,geometry,1234)


if __name__ == '__main__':
    unittest.main()
