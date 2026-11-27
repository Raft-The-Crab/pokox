# Graph Report - .  (2026-11-27)

## Corpus Check
- Large corpus: 6753 files · ~8,073,166 words. Semantic extraction will be expensive (many Claude tokens). Consider running on a subfolder, or use --no-semantic to run AST-only.

## Summary
- 8354 nodes · 16307 edges · 457 communities detected
- Extraction: 94% EXTRACTED · 6% INFERRED · 0% AMBIGUOUS · INFERRED: 980 edges (avg confidence: 0.5)
- Token cost: 0 input · 0 output
- Edge kinds: calls: 5874 · contains: 5393 · rationale_for: 1741 · MODIFIES: 1740 · uses: 980 · method: 373 · PARENT_OF: 81 · ON_BRANCH: 73 · inherits: 21 · imports_from: 17 · imports: 7 · references: 4 · implements: 2 · cites: 1


## Input Scope
- Requested: auto
- Resolved: committed (source: default-auto)
- Included files: 6753 · Candidates: 10644
- Excluded: 31 untracked · 3021 ignored · 23 sensitive · 15 missing committed
- Recommendation: Use --scope all or graphify.yaml inputs.corpus for a knowledge-base folder.

## Graph Freshness
- Built from Git commit: `b925296`
- Compare this hash to `git rev-parse HEAD` before trusting freshness-sensitive graph output.
## God Nodes (most connected - your core abstractions)
1. `Palette` - 627 edges
2. `MB` - 194 edges
3. `Sh` - 104 edges
4. `T()` - 58 edges
5. `rbox()` - 51 edges
6. `EffectSession` - 44 edges
7. `soft()` - 41 edges
8. `Prop` - 40 edges
9. `GridfinityBin` - 39 edges
10. `sh()` - 38 edges

## Surprising Connections (you probably didn't know these)
- `trails, plazas, river, castle hill, falls: nothing scattered there` --uses--> `MB`  [INFERRED]
  .agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py → .agents/skills/Map Pack/map-builder/scripts/pro_lib.py
- `one board tile: the polyline section s0..s1 (arc length) across `width`, draped` --uses--> `MB`  [INFERRED]
  .agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py → .agents/skills/Map Pack/map-builder/scripts/pro_lib.py
- `board-game tile runs (TILE long, 0.7 gaps) + sprinkles on them; round stop plaza` --uses--> `MB`  [INFERRED]
  .agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py → .agents/skills/Map Pack/map-builder/scripts/pro_lib.py
- `chocolate river surface (glossy, streaked) + graham-crumb banks` --uses--> `MB`  [INFERRED]
  .agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py → .agents/skills/Map Pack/map-builder/scripts/pro_lib.py
- `icing poured over the frosting hilltops: a draped sheet with a thick rounded lip` --uses--> `MB`  [INFERRED]
  .agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py → .agents/skills/Map Pack/map-builder/scripts/pro_lib.py

## Communities

### Community 152 - "Community 152"
Cohesion: 0.12
Nodes (15): tmp_stl(), good_script(), step_script(), bad_script(), empty_script(), Generate a watertight 10mm cube STL on demand., CadQuery script that writes a watertight cube next to itself., CadQuery script that writes both an STL and a STEP next to itself. (+7 more)

### Community 239 - "Community 239"
Cohesion: 0.20
Nodes (2): _write_ablation(), test_ablation_verdicts()

### Community 191 - "Community 191"
Cohesion: 0.29
Nodes (10): get_collection(), link(), capsule(), box(), sphere(), build(), report(), Parametric human blockout from measured sheet fractions.  Every dimension is a f (+2 more)

### Community 96 - "Community 96"
Cohesion: 0.12
Nodes (14): _fresh_col(), _mats(), build_explorer(), Explorer character — pass 2: garments, equipment, hair.  Builds on the blockout., Dim, assign(), shell_from(), loft() (+6 more)

### Community 218 - "Community 218"
Cohesion: 0.29
Nodes (10): _ensure_world(), _area(), _scene_bounds(), setup_camera(), setup_lighting(), setup_render(), render_turnaround(), Fixed-camera turnaround renders for reference comparison.  Sets one camera + a n (+2 more)

### Community 192 - "Community 192"
Cohesion: 0.26
Nodes (11): scene_bounds(), tri_count(), find_strays(), find_isolated(), landmarks(), validate(), Automated scene validation gate.  Catches the two defect classes that silently r, World-space bounds computed from evaluated vertices.      ob.bound_box is a cach (+3 more)

### Community 304 - "Community 304"
Cohesion: 0.43
Nodes (7): luminance(), image_change(), view_baseline(), analyse(), main(), Rank Godot graphics settings by frame-time cost against how much they change the, Full-scene GPU ms and noise floors for one view.

### Community 318 - "Community 318"
Cohesion: 0.39
Nodes (7): font(), figure(), mask(), frame(), main(), Contact-sheet hero for the README. One loop: a render closing on its reference., A small standing silhouette. Parameters are the things a bad first pass gets wro

### Community 36 - "Community 36"
Cohesion: 0.08
Nodes (40): _fit_size(), letterbox(), load_rgb(), _quad_basis(), background_fit_mask(), flood_background_mask(), subject_mask(), significant_components() (+32 more)

### Community 263 - "Community 263"
Cohesion: 0.36
Nodes (9): load(), subject_mask(), tight(), save_crop(), auto_front(), palette(), main(), Extract clean single-view reference panels from a concept sheet.  The sheet is a (+1 more)

### Community 400 - "Community 400"
Cohesion: 0.60
Nodes (4): _panel(), _overlay(), build(), Side-by-side diagnostic sheet.  Metrics tell you the score. This tells you what

### Community 174 - "Community 174"
Cohesion: 0.23
Nodes (14): hex_of(), hex_to_rgb(), subject_pixels(), kmeans(), extract(), delta_e(), load_palette(), compare_to_render() (+6 more)

### Community 154 - "Community 154"
Cohesion: 0.19
Nodes (16): load_gray(), blur(), high_pass(), derive_roughness(), derive_normal(), derive_ao(), save_gray(), save_rgb() (+8 more)

### Community 273 - "Community 273"
Cohesion: 0.31
Nodes (9): load_gray(), boundary_metrics(), assess(), write_tile_sheet(), print_report(), main(), Detect visible seams in a tiling texture.  The test is not "does it look OK when, Compare the wrap edge against every interior adjacent pair.      `percentile` an (+1 more)

### Community 274 - "Community 274"
Cohesion: 0.33
Nodes (9): parse_obj(), tri_area_3d(), tri_area_uv(), group_stats(), report(), print_report(), main(), Measure texel density across the parts of a mesh.  Density is linear: texture pi (+1 more)

### Community 142 - "Community 142"
Cohesion: 0.16
Nodes (16): parse_frontmatter(), find_skills(), collect_tech_ids(), check_coverage(), validate(), Validate the gamedev skills library.  Checks the things that silently rot in a s, Minimal YAML front-matter reader: enough for flat scalars and the     '>' folded, Locate SKILL.md files, accepting either layout.      `root/.agents/skills/` is t (+8 more)

### Community 25 - "Community 25"
Cohesion: 0.08
Nodes (48): sub(), seg_d(), poly_d(), resample(), smooth_pl(), dist_castle(), bump(), path_mask() (+40 more)

### Community 161 - "Community 161"
Cohesion: 0.14
Nodes (13): closed_torus(), WAF(), jelly_bean(), jelly_beans(), roblox_materials(), _pmat(), preview_mats(), explicitly closed torus grid (no seam). plane XZ = ring axis Y (lying), XY = rin (+5 more)

### Community 135 - "Community 135"
Cohesion: 0.15
Nodes (18): MS(), striped_tube(), drip_ring(), bakery_oven(), quest_stand(), drawbridge(), candy_cane(), cotton_candy_tree() (+10 more)

### Community 136 - "Community 136"
Cohesion: 0.15
Nodes (18): sugar(), lathe(), candy_egg(), bell_r(), icing_cap(), choco_falls(), gumdrop_bush(), gumdrop_mountain() (+10 more)

### Community 297 - "Community 297"
Cohesion: 0.25
Nodes (8): orient(), cupcake_liner(), swirl(), cupcake_fountain(), flip faces so normals point away from the vertical axis (lathe shells) / out of, pleated paper liner: frustum whose radius alternates in/out per pleat, two-colou, soft-serve swirl: a tube coiling up and in, SPAWN: giant cupcake in a cookie basin of strawberry milk; syrup arcs fall from

### Community 137 - "Community 137"
Cohesion: 0.13
Nodes (18): round_prof(), piping(), sign_plate(), gable_roof_bars(), sweet_shop(), gumball_machine(), biscuit_bridge(), marshmallow() (+10 more)

### Community 160 - "Community 160"
Cohesion: 0.20
Nodes (16): soft(), torus(), ring_pts(), waffle_lathe(), waffle_shade(), cone_tower(), candy_castle(), waffle_bridge() (+8 more)

### Community 278 - "Community 278"
Cohesion: 0.25
Nodes (9): ball(), egg_machine(), swirl_disc(), lollipop_tree(), candy_flower(), PET / EGG MACHINE: sugar-glass dome over a cotton-candy nest of three decorated, flat lollipop swirl: two interleaved Archimedean spiral ribbons (true spiral ban, swirl lollipop on a bent stick, disc tilted to face the path (-Z), plus a smalle (+1 more)

### Community 298 - "Community 298"
Cohesion: 0.25
Nodes (8): drip(), sprinkle(), sprinkles_on(), donut_arch(), a hanging icing drip: tapered neck from y 0 down to -length ending in a round be, one rod sprinkle (open-ended 5-sided rod, 10 tris), sprinkles lying on a surface: list of (point, normal), giant glazed donut standing on edge over the path, half sunk; glaze cap with dri

### Community 1 - "Community 1"
Cohesion: 0.02
Nodes (35): _hex(), paint_block(), font(), main(), Post pass for kraken.py (self-contained: copy kraken.py + kraken_post.py togethe, Contact sheet of the brick pipeline's *_fx.png renders (3 per row, 450 px tiles,, Preview post: single black silhouette outline + Neon-style glow bloom. py post_g, My Tool - Blender extension template (4.2+ extension format, verified on 5.3). (+27 more)

### Community 24 - "Community 24"
Cohesion: 0.09
Nodes (48): sub(), cx(), dcx(), hw(), shelf1(), levels(), wall(), tdist() (+40 more)

### Community 15 - "Community 15"
Cohesion: 0.05
Nodes (61): lerp(), dais(), cloth_sheet(), brass_lantern(), pot(), goods_pots(), fruit_pile(), stall() (+53 more)

### Community 20 - "Community 20"
Cohesion: 0.14
Nodes (54): sub(), sky_at(), shapes(), seg_d(), poly_d(), lake_d(), islet_d(), tunnel_d() (+46 more)

### Community 456 - "Community 456"
Cohesion: 0.67
Nodes (3): air(), build_dist(), signed distance (studs) to the cave wall at floor level: + inside the air, - ins

### Community 14 - "Community 14"
Cohesion: 0.04
Nodes (60): list of ellipsoids (centre, radii) whose union is the cave air, floor height: gentle cave earth, lake bed carved in, islet raised, nothing in th, solid props at once; soft ones (foliage / fungi / vines) deferred and placed aga, copy a prop part (Roblox-space MB) to its world placement (pieces built into sta, walkable floor heightfield (3 studs) everywhere under the air + 6 studs into the, layered rock masses along every wall foot (big in the hall, small in tunnels), h, stalactites over the whole vault (never low over paths), flowstone curtains near, geodes at chosen spots (glow by district: amber by the camp + forge, cyan round (+52 more)

### Community 145 - "Community 145"
Cohesion: 0.18
Nodes (16): _lump(), mound(), ore_lump(), druse(), shovel(), pickaxe(), ore_pile(), cart_load() (+8 more)

### Community 21 - "Community 21"
Cohesion: 0.07
Nodes (51): lerp(), smooth(), V(), FS(), rim_shade(), RS(), dot(), jitter() (+43 more)

### Community 45 - "Community 45"
Cohesion: 0.11
Nodes (32): logp(), blob(), W(), oil_lantern(), mine_frame(), rail_seg(), rail_buffer(), wheel() (+24 more)

### Community 46 - "Community 46"
Cohesion: 0.07
Nodes (33): boards(), shed_roof(), mine_shop(), crystal_forge(), camp_tent(), campfire_pit(), quest_board(), log_seat() (+25 more)

### Community 32 - "Community 32"
Cohesion: 0.10
Nodes (42): sub(), pol(), face_in(), sh_val(), H(), kit(), foot(), place() (+34 more)

### Community 3 - "Community 3"
Cohesion: 0.04
Nodes (154): lerp(), smooth(), ball(), rbox(), ring_seg(), merge_prop(), upright(), leaf_poly() (+146 more)

### Community 2 - "Community 2"
Cohesion: 0.02
Nodes (165): wing_outline(), roof_in_y(), lens-shaped leaf: length L along direction a (deg from +up, clockwise = +x), hal, the Bloom Paw: rounded paw pad (soft heart-ish blob) + three leaf toes fanned ab, capsule cradle slot: steel cup, glowing ring, capsule seated (used in the heal m, the Restoration Bay: plinth, white console with a tilted cradle deck of 6 capsul, open shelving: side panels, back panel, kick base, `rows` shelf heights; crown c, medical wall cabinet: open upper shelves with flasks, spray bottles, vials, jars (+157 more)

### Community 26 - "Community 26"
Cohesion: 0.09
Nodes (48): sub(), _seg_d(), pl_d(), dunes(), ring(), T_local(), H(), on_path() (+40 more)

### Community 224 - "Community 224"
Cohesion: 0.24
Nodes (10): campfire(), spike_flame(), oasis_pool(), grid_disc(), treasure_mound(), waystone_body(), stone ring, crossed logs, flame glow, a three-legged tripod with a hanging pot,, oasis: a round pool (r 10) with a turquoise water disc set below a rim of cut sa (+2 more)

### Community 146 - "Community 146"
Cohesion: 0.17
Nodes (17): lerp(), sheet(), peg_rope(), crate(), sack(), rolled_rug(), jar(), trader_tent() (+9 more)

### Community 124 - "Community 124"
Cohesion: 0.13
Nodes (19): smooth(), frustum(), disc(), sun_relief(), ruin_arch(), waystone(), spawn_dais(), quest_stele() (+11 more)

### Community 123 - "Community 123"
Cohesion: 0.13
Nodes (19): V(), uvsphere(), camel(), rug_spread(), outcrop(), dune_grass(), sand_drift(), wyrm_skull() (+11 more)

### Community 223 - "Community 223"
Cohesion: 0.24
Nodes (11): merge_into(), plinth(), _shaft(), obelisk(), obelisk_fallen(), obelisk_stump(), merge a temporary Prop's solid (+ glow) into P, optionally mapping every vertex, SHARED BASE: stepped sandstone plinth, a chamfered course per step, gold trim li (+3 more)

### Community 117 - "Community 117"
Cohesion: 0.11
Nodes (20): grid_quad(), zig_band(), block_wall(), column(), step_pyramid(), pylon_gate(), ruin_wall(), ruin_house() (+12 more)

### Community 9 - "Community 9"
Cohesion: 0.05
Nodes (53): fft_noise(), normal_from_height(), save_png(), ramp(), bark_oak(), bark_birch(), bark_fir(), Canvas (+45 more)

### Community 54 - "Community 54"
Cohesion: 0.14
Nodes (28): sub(), sh_val(), isle_d(), H(), kit(), foot(), place(), Hg() (+20 more)

### Community 280 - "Community 280"
Cohesion: 0.28
Nodes (5): merge_prop(), hay_bale(), hay_stack(), square hay bale: chamfered straw block, two twine bands, straw tufts on top, three bales stacked (2 + 1), a pitchfork-free story pile

### Community 195 - "Community 195"
Cohesion: 0.17
Nodes (13): lerp(), egg_profile(), egg_slice(), plot_slab(), lane_lamp(), foot_bridge(), windmill(), egg outline (r, y) bottom -> top: widest a little below the middle, narrower dom (+5 more)

### Community 125 - "Community 125"
Cohesion: 0.12
Nodes (19): rbox(), conveyor_seg(), conveyor_end(), gate_mat(), stall(), egg_shop(), upgrade_stand(), sell_stand() (+11 more)

### Community 300 - "Community 300"
Cohesion: 0.25
Nodes (8): upright(), fence_run(), coop(), barn(), 2D poly [(x, up)] standing upright facing -Z, extruded d toward the front (-Z) f, picket fence segment along +X (0..L), front -Z: a slim honey post with an accent, the nest-coop (the plot's base building): stone plinth, cream plaster walls with, backdrop red barn (seen from across the lake): stone plinth, red board walls wit

### Community 172 - "Community 172"
Cohesion: 0.13
Nodes (15): sh(), collect_pad(), flower_tub(), tree(), pine(), bush(), flower_patch(), silo() (+7 more)

### Community 184 - "Community 184"
Cohesion: 0.15
Nodes (14): egg(), straw_nest(), nest_pedestal(), feed_trough(), deco_egg(), hatchery(), nest_statue(), the identity Egg: faceted lathe egg; optional painted zigzag band (band colour) (+6 more)

### Community 206 - "Community 206"
Cohesion: 0.18
Nodes (12): egg_finial(), post(), fence_post(), gate_frame(), owner_sign(), egg_drain(), post-top egg knob: accent collar + cream egg with an accent band, square post with a stone footing (extends below ground) and a chamfered top (+4 more)

### Community 19 - "Community 19"
Cohesion: 0.09
Nodes (54): sub(), pos(), outward(), tangent(), lp(), islet_e(), H(), H_raw() (+46 more)

### Community 126 - "Community 126"
Cohesion: 0.12
Nodes (18): ring_band(), ring_rect(), ring_circ(), thatch_band(), thatch_cone(), reef_rock(), cloud(), buoy_stack() (+10 more)

### Community 196 - "Community 196"
Cohesion: 0.21
Nodes (13): lerp(), tropical_shrub(), barrel(), barrels(), boat_hull(), paint_hull(), skiff(), motor_boat() (+5 more)

### Community 185 - "Community 185"
Cohesion: 0.16
Nodes (14): smooth(), palm(), palm_planter(), _merge_prop(), _fern(), grass_tuft(), sea_stack(), hammock_palms() (+6 more)

### Community 253 - "Community 253"
Cohesion: 0.20
Nodes (10): ball(), lifebuoy_stand(), net_pile(), bench(), marker_buoy(), lighthouse(), heap of teal fishing net: lumpy mound with a rope mesh draped over its surface,, driftwood bench: two slab seat planks on X-legs with a stretcher, pegs (+2 more)

### Community 78 - "Community 78"
Cohesion: 0.11
Nodes (24): pole(), lash(), plank_floor(), tiki_torch(), rod(), rod_rack(), hut_body(), shutter() (+16 more)

### Community 302 - "Community 302"
Cohesion: 0.25
Nodes (8): rope(), rail_post(), _post(), rail_bay(), drying_rack(), teak rail post with the signature cap: a teal glass float in a rope net on a col, SIGNATURE edge module: post at -L/2, two rope swags to +L/2 (next bay's post), s, fish drying rack: two bamboo A-frames, a top pole, lines of hanging fish

### Community 301 - "Community 301"
Cohesion: 0.25
Nodes (8): loft(), awning(), bait_bucket(), bait_shop(), quads between successive rings (lists of Vector, same count); closed = each ring, striped canvas awning off a wall at z (front = -Z): slopes out `depth`, down `dr, metal bait bucket with handle, worms (red tubes) and shrimp curls inside, BAIT SHOP (lime): round hut of upright bamboo staves, cone thatch (4 layers), cu

### Community 118 - "Community 118"
Cohesion: 0.11
Nodes (20): fish(), thatch_hip(), sign_board(), coral_branch(), brain_coral(), cooler(), fish_market(), fish_index_wall() (+12 more)

### Community 254 - "Community 254"
Cohesion: 0.20
Nodes (10): mat_cell(), woven_wall(), local(), crate(), crate_stack(), quest_board(), woven palm-mat infill between posts: strips 0.55 tall, alternating tone and dept, wall panel L long, H high (local x -L/2..L/2), holes [(x0, x1, y0, y1)] left ope (+2 more)

### Community 67 - "Community 67"
Cohesion: 0.15
Nodes (22): sub(), segd(), path_info(), nearest_path_pt(), H(), keepout(), ground(), square() (+14 more)

### Community 12 - "Community 12"
Cohesion: 0.09
Nodes (58): snow_pine(), cabin(), roll_well(), fishing_hut(), frost_spire(), grove pine re-shaded: every up-facing tier face carries snow, log cabin: stacked logs with crossed corners, the door gap is left IN the log co, village-square roll well: stone ring, timber A-frame + roof, rope + bucket, glow (+50 more)

### Community 33 - "Community 33"
Cohesion: 0.11
Nodes (42): sub(), X(), Yw(), fordw(), channels(), seg_d(), trench_drop(), road_d() (+34 more)

### Community 6 - "Community 6"
Cohesion: 0.09
Nodes (86): smooth(), lerp(), T(), frame_to(), bar(), log(), lathe(), torus() (+78 more)

### Community 27 - "Community 27"
Cohesion: 0.10
Nodes (46): sub(), ramp_half_len(), adiff(), profile(), _crater_ok(), ramp_w(), H(), zone_of() (+38 more)

### Community 29 - "Community 29"
Cohesion: 0.11
Nodes (43): lerp(), lathe(), torus(), beam(), egg(), dish(), ShAng, Sh (+35 more)

### Community 13 - "Community 13"
Cohesion: 0.06
Nodes (45): fft_noise(), normal_from_height(), save_png(), ramp(), bark_oak(), bark_birch(), bark_fir(), Canvas (+37 more)

### Community 35 - "Community 35"
Cohesion: 0.10
Nodes (39): sub(), terrace_at(), mountains(), H(), kit(), place(), mirror(), free() (+31 more)

### Community 128 - "Community 128"
Cohesion: 0.11
Nodes (14): koi_pond(), planter(), stair_flight(), crates(), bench(), torii(), fern_tuft(), small round stone pond: dressed rim, water, three koi, lily pads, a moss boulder (+6 more)

### Community 210 - "Community 210"
Cohesion: 0.17
Nodes (12): lerp(), pool_outline(), hot_pool(), jp_pine(), cloud_tree(), cedar(), crag(), steaming rock pool: raised ashlar-and-boulder rim, cut-stone curb, milky water, (+4 more)

### Community 212 - "Community 212"
Cohesion: 0.20
Nodes (12): flared_roof(), skirt_roof(), plinth(), house(), pagoda(), toro(), Asian glazed roof: a lofted surface from the eave polygon `outer` (corners [(x,, pent roof around a storey (pagoda tiers, inn skirts): from the eave down to the (+4 more)

### Community 256 - "Community 256"
Cohesion: 0.22
Nodes (10): hip_roof(), paper_lantern(), bath_pavilion(), noodle_stall(), paper_lantern_post(), rectangular hip roof over a hw x hd (half sizes) wall box: ridge along X, ridge, chouchin: glowing ribbed paper body with dark wood top + bottom rings and a hang, open bath shelter over a pool: round cedar columns on stone bases, tie beams, br (+2 more)

### Community 211 - "Community 211"
Cohesion: 0.20
Nodes (12): holed_wall(), window(), doorway(), frame_storey(), storey_walls(), shopfront(), wall panel L long (x -L/2..L/2), H high, th thick, holes [(x0, x1, y0, y1)] cut, cut window: timber frame round the hole, sill, recessed shoji lattice with a war (+4 more)

### Community 228 - "Community 228"
Cohesion: 0.18
Nodes (11): giboshi(), balcony(), rail_post(), railing_post(), railing(), footbridge(), bronze onion cap (the signature post finial), deck on brackets along a wall at z (side = -1 front), cedar rail with giboshi po (+3 more)

### Community 283 - "Community 283"
Cohesion: 0.22
Nodes (9): bucket(), towel_rack(), taru(), sake_barrels(), hand_cart(), drying rack: two cedar uprights with feet, three poles, folded towels draped ove, sake cask: straw-wrapped body, rope bands, lid; lying casks rest on their side, cluster: cedar pallet, three standing casks, one on top, one lying in a chock, a (+1 more)

### Community 22 - "Community 22"
Cohesion: 0.13
Nodes (53): sub(), isle_R(), polar(), isle_at(), top_y(), H(), isle_mesh(), kit() (+45 more)

### Community 173 - "Community 173"
Cohesion: 0.20
Nodes (14): star_poly(), star(), lift(), egg_prof(), egg_r(), egg(), rainbow_arch(), egg_stand() (+6 more)

### Community 229 - "Community 229"
Cohesion: 0.22
Nodes (11): vsh(), flat(), pet_fountain(), coin_pile(), flower_patch(), mushroom(), stump(), hub hero: 3-tier pastel fountain (scalloped basin, water, mid bowl with a pale w (+3 more)

### Community 139 - "Community 139"
Cohesion: 0.12
Nodes (18): soft(), bubble_crown(), puff_tree(), cotton_tree(), crystal_tree(), grass_tuft(), gumdrops(), glow_shroom() (+10 more)

### Community 149 - "Community 149"
Cohesion: 0.16
Nodes (17): ell(), rbox(), trade_booth(), leaderboard(), bridge(), chest(), gift_box(), puff_bush() (+9 more)

### Community 129 - "Community 129"
Cohesion: 0.11
Nodes (19): puff(), puffpaw(), pet_statue(), crystal_clump(), picnic_set(), soft_rock(), crystal_spire(), cloud() (+11 more)

### Community 198 - "Community 198"
Cohesion: 0.17
Nodes (13): rcyl(), arc_pts(), disc_up(), paw(), trade_pad(), zone_gate(), spawn_pad(), lollipop() (+5 more)

### Community 261 - "Community 261"
Cohesion: 0.20
Nodes (10): pill(), pet_shop(), upgrade_machine(), giant_donut(), star_lamp(), capsule from a to b (rounded ends), open-front kiosk: round dais, curved back wall with toy shelves, 4 chubby pillar, giant gumball machine: rounded red drum base (coin plate, glowing up-chevron, ch (+2 more)

### Community 164 - "Community 164"
Cohesion: 0.35
Nodes (13): grp(), blk(), place(), walls(), kerb_z(), kerb_x(), oval_track(), floor() (+5 more)

### Community 97 - "Community 97"
Cohesion: 0.13
Nodes (17): stepped canyon: tier n is a row of 24-wide blocks with a 2-stud cap, each tier t, race kerb along Z: alternating colour/white blocks proud of the cap edge, wedge, running-track oval: red lane band, white inner/outer lines and 2 lane lines, put theme props on cap tops (centre of the 24-wide cap), skipping some for rhyth, v4 stadium hub: striped infield inside an oval running track, stations face in f, n blocks laid tangent around a circle (plane 'xy' = vertical ring facing Z, 'xz', gable roof along X: two wedges back to back + ridge trim, SPEED SHOP: platform with a ramp, panelled counter, back wall with shelves of sp (+9 more)

### Community 42 - "Community 42"
Cohesion: 0.05
Nodes (8): lamp_pillar(), zone_gate(), big_arch(), trophy(), the stacked-cube lamp pillar from the reference game, two lamp pillars at the track edges, a top beam with a sign board (name / price, START / FINISH arch: two chunky towers, a deep beam with a black/white checker b, finish hero: 1-2-3 podium with a giant blocky trophy on the top step

### Community 262 - "Community 262"
Cohesion: 0.20
Nodes (2): trophy(), finish hero: 1-2-3 podium + a giant cylinder-built trophy (base, stem, flared cu

### Community 89 - "Community 89"
Cohesion: 0.19
Nodes (22): chamfer_block(), octo(), cyl_v(), ring(), gable(), bulbs_frame(), framed_panel(), speed_shoe() (+14 more)

### Community 130 - "Community 130"
Cohesion: 0.22
Nodes (18): pixel_art(), raster(), kerb_lip(), plinth(), sneaker_shop(), egg_rows(), egg_hatchery(), portal_rows() (+10 more)

### Community 38 - "Community 38"
Cohesion: 0.14
Nodes (37): sub(), rim(), island_at(), H(), bridge_ends(), segd(), kit(), foot() (+29 more)

### Community 202 - "Community 202"
Cohesion: 0.21
Nodes (12): lumpy(), bevel_box(), puffy_tree(), blossom_tree(), snow_tree(), island_under(), zone_gate(), icosphere with noise displacement: chunky stylised foliage / cloud / rock lump (+4 more)

### Community 66 - "Community 66"
Cohesion: 0.09
Nodes (27): coin(), bottle(), planks(), coin_pile(), chest(), crystal_node(), _ribbed(), cactus() (+19 more)

### Community 201 - "Community 201"
Cohesion: 0.15
Nodes (12): mesa_rock(), lava_pool(), charred_tree(), bush(), lamp_post(), signpost(), sandstone butte: 3 eroded faceted tiers (lumpy hull rings, each narrower), darke, molten pool: ring of basalt boulders, glowing surface with dark crust plates flo (+4 more)

### Community 99 - "Community 99"
Cohesion: 0.11
Nodes (16): blade(), star(), grass_tuft(), wildflowers(), mushrooms(), dune_grass(), dry_shrub(), bridge() (+8 more)

### Community 31 - "Community 31"
Cohesion: 0.07
Nodes (39): lathe(), sphere(), torus(), gem(), island_under(), floating_rock(), cloud(), bridge() (+31 more)

### Community 151 - "Community 151"
Cohesion: 0.20
Nodes (14): sub(), kit(), place(), face(), local(), free(), on_hard(), plot() (+6 more)

### Community 23 - "Community 23"
Cohesion: 0.06
Nodes (49): dome(), sphere(), torus(), stripes(), subdiv_line(), plot_base(), fence(), fence_post() (+41 more)

### Community 132 - "Community 132"
Cohesion: 0.20
Nodes (17): _hex(), pnoise(), edge(), ramp(), hash2(), tile(), paint_glass(), block() (+9 more)

### Community 28 - "Community 28"
Cohesion: 0.10
Nodes (45): sub(), blocks(), kit(), place(), face(), rot(), free(), reserve() (+37 more)

### Community 40 - "Community 40"
Cohesion: 0.12
Nodes (37): lerp(), V3(), slab(), add(), ball(), blob(), ring_frame(), quad() (+29 more)

### Community 61 - "Community 61"
Cohesion: 0.07
Nodes (26): street_lamp(), traffic_light(), bench(), planter(), litter_bin(), hydrant(), dumpster(), trash_bags() (+18 more)

### Community 121 - "Community 121"
Cohesion: 0.17
Nodes (19): _smoothstep(), loft_closed(), body_shell(), body_shader(), wheels(), car(), taxi(), bus() (+11 more)

### Community 181 - "Community 181"
Cohesion: 0.21
Nodes (14): _hex(), fnoise(), stamps(), cracks(), paint_block(), atlas(), tri(), remap() (+6 more)

### Community 7 - "Community 7"
Cohesion: 0.06
Nodes (83): sub(), lake_R(), lake_d(), sand_w(), islet(), rim_s(), seg_d(), poly_d() (+75 more)

### Community 5 - "Community 5"
Cohesion: 0.05
Nodes (92): lerp(), smooth(), V(), flat(), rounded_mass(), moss_cap(), rim_shade(), RS() (+84 more)

### Community 41 - "Community 41"
Cohesion: 0.13
Nodes (38): sub(), ang(), Rfun(), island_of(), top_y(), H(), kit(), foot() (+30 more)

### Community 11 - "Community 11"
Cohesion: 0.07
Nodes (70): lerp(), V(), FS(), annulus(), disc(), shaft(), shard_rock(), chamfer_box() (+62 more)

### Community 357 - "Community 357"
Cohesion: 0.48
Nodes (5): _inb(), _inside_one(), _top(), fit_bad(), fit()

### Community 56 - "Community 56"
Cohesion: 0.09
Nodes (25): V(), B(), CY(), T(), glowbox(), Sub, lathe(), prism_x() (+17 more)

### Community 81 - "Community 81"
Cohesion: 0.09
Nodes (22): rail_run(), mezzanine(), site_office(), ibc_tote(), mesh_stillage(), conveyor(), packing_bench(), stretch_wrapper() (+14 more)

### Community 103 - "Community 103"
Cohesion: 0.17
Nodes (19): sub(), deck_y(), cull(), kit(), place(), anchor(), yaw_of(), shade() (+11 more)

### Community 69 - "Community 69"
Cohesion: 0.11
Nodes (26): pallet_sub(), carton(), load_cartons(), load_wrapped(), drum_bm(), load_drums(), load_sacks(), load_crates() (+18 more)

### Community 468 - "Community 468"
Cohesion: 1.00
Nodes (2): r2b(), light()

### Community 115 - "Community 115"
Cohesion: 0.10
Nodes (20): steel_column(), roof_truss(), high_bay(), dock_door(), personnel_door(), runway_beam(), crane_bridge(), crane_trolley() (+12 more)

### Community 358 - "Community 358"
Cohesion: 0.38
Nodes (6): wheel(), forklift(), pallet_jack(), tyre + rim + hub nuts, axle along x, centre c, outer face toward side (+1 = +x), electric counterbalance forklift: yellow body, rounded counterweight, overhead g, hand pallet truck: twin forks, pump body, tiller handle (forks toward -z)

### Community 104 - "Community 104"
Cohesion: 0.12
Nodes (19): axle_set(), truck_wheel(), wheel_arch(), truck_mirrors(), box_trailer(), tractor_unit(), fence_panel(), yard_light() (+11 more)

### Community 62 - "Community 62"
Cohesion: 0.14
Nodes (25): sub(), segd(), path_info(), stream_d(), H(), keepout(), ground(), plaza() (+17 more)

### Community 445 - "Community 445"
Cohesion: 0.67
Nodes (2): pill(), pair()

### Community 315 - "Community 315"
Cohesion: 0.29
Nodes (2): flat(), ground()

### Community 214 - "Community 214"
Cohesion: 0.24
Nodes (10): rgb_of(), shape_bm(), mesh_blocks(), neon_mat(), stud_material(), _f(), write_rbxmx(), one solid mesh (palette + studs) + one mesh per neon colour + one for transparen (+2 more)

### Community 177 - "Community 177"
Cohesion: 0.14
Nodes (9): r2b(), xf(), spike(), grid(), render(), rot = (pitch about X, yaw about Y, roll about Z) in degrees, a crystal / spire: prism up to h * shoulder, then a pyramid tip, heightfield quad grid (Roblox space): y = hfun(x, z) (+1 more)

### Community 405 - "Community 405"
Cohesion: 0.40
Nodes (4): clamp(), lerp(), smooth(), nz()

### Community 311 - "Community 311"
Cohesion: 0.32
Nodes (3): Out, named groups -> uploaded meshes. solid groups use the palette; glow groups carry, a glow piece: uv on the white strip

### Community 375 - "Community 375"
Cohesion: 0.40
Nodes (6): bevel(), box(), ngon_prism(), cyl(), poly = [(x, z), ...] counter-clockwise seen from above (+Y); extruded y0..y1, to, vertical prism / frustum from y0 to y0 + h

### Community 439 - "Community 439"
Cohesion: 0.50
Nodes (4): hull(), rock_pts(), rock(), points on a lumpy ellipsoid (radii r = (rx, ry, rz)); flat = cut the bottom at -

### Community 438 - "Community 438"
Cohesion: 0.50
Nodes (4): frames(), tube(), parallel-transport frames along a polyline (Vectors), swept polygon along pts; radii scalar or list; rough = random ring radius jitter

### Community 472 - "Community 472"
Cohesion: 1.00
Nodes (2): ribbon(), a flat strip on the ground following pts (x, y, z); widths per point

### Community 473 - "Community 473"
Cohesion: 1.00
Nodes (2): strip_surface(), a surface between a front curve z = zf(x) and a back curve zb(x) (quad strip ove

### Community 376 - "Community 376"
Cohesion: 0.33
Nodes (6): voronoi_cells(), clip_half(), clip_rect(), clip_fn(), jittered-grid Voronoi cells clipped to the rectangle: list of (site, polygon[(x,, keep the side of the bisector of s-o closer to s

### Community 440 - "Community 440"
Cohesion: 0.50
Nodes (3): split(), make_obj(), mesh in Blender space, origin = bbox centre; returns the part record (Roblox spa

### Community 37 - "Community 37"
Cohesion: 0.06
Nodes (25): collision_of(), r_pos(), clean_name(), base_of(), mat_color(), newobj(), _face_rgb(), material_split() (+17 more)

### Community 267 - "Community 267"
Cohesion: 0.31
Nodes (9): column_of(), _variant(), mat_for(), resolve(), preview(), write_map(), material for palette ramp `col` on object/mesh `name`: per-prop overrides ({pref, give every palette mesh one Blender material slot per Roblox material (by palett (+1 more)

### Community 281 - "Community 281"
Cohesion: 0.39
Nodes (8): _unit(), gill_base(), build(), gills(), idle(), walk(), swim(), happy()

### Community 70 - "Community 70"
Cohesion: 0.11
Nodes (16): put(), cap(), chain(), ix(), front_z(), side_x(), top_y(), cell() (+8 more)

### Community 158 - "Community 158"
Cohesion: 0.16
Nodes (8): newid(), put(), disc_x(), lin(), exposed(), build(), wheel(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p

### Community 43 - "Community 43"
Cohesion: 0.10
Nodes (28): unrec(), put(), sl_of(), full(), cap(), chain(), oell(), nrm() (+20 more)

### Community 76 - "Community 76"
Cohesion: 0.11
Nodes (12): put(), sd_cap(), sd_chain(), chain(), xo(), tri(), top_at(), lin() (+4 more)

### Community 134 - "Community 134"
Cohesion: 0.14
Nodes (8): chain_t(), chain(), lin(), exposed(), build(), B(), render_all(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p

### Community 106 - "Community 106"
Cohesion: 0.13
Nodes (12): cap(), chain(), ix(), newid(), catmull(), tentacle(), top_y(), lin() (+4 more)

### Community 51 - "Community 51"
Cohesion: 0.10
Nodes (24): put(), glow(), cap(), chain(), shift(), dil(), ero(), front_layer() (+16 more)

### Community 63 - "Community 63"
Cohesion: 0.10
Nodes (14): put(), cap(), chain(), shell(), flame(), tuft(), ring(), seam() (+6 more)

### Community 83 - "Community 83"
Cohesion: 0.12
Nodes (13): put(), newid(), body_to_world(), lid_to_body(), lid_to_world(), planks(), fang(), lin() (+5 more)

### Community 16 - "Community 16"
Cohesion: 0.05
Nodes (45): leaf_col(), trunk(), branch(), grass_base(), oak(), pine(), bush(), rocks() (+37 more)

### Community 53 - "Community 53"
Cohesion: 0.10
Nodes (21): frame(), put(), bx(), capd(), chaind(), chain(), h3(), newid() (+13 more)

### Community 116 - "Community 116"
Cohesion: 0.15
Nodes (14): put(), sd_ell(), cap(), chain(), newid(), seg(), joint(), lin() (+6 more)

### Community 75 - "Community 75"
Cohesion: 0.10
Nodes (11): chain_t(), chain(), unit(), arm(), fdir(), lin(), exposed(), build() (+3 more)

### Community 84 - "Community 84"
Cohesion: 0.15
Nodes (19): put(), box(), cap(), chain(), newid(), prof(), top_at(), pyramid() (+11 more)

### Community 85 - "Community 85"
Cohesion: 0.13
Nodes (16): put(), cap(), chain(), prof(), newid(), hide(), tooth(), edge() (+8 more)

### Community 107 - "Community 107"
Cohesion: 0.16
Nodes (16): put(), cap(), chain(), newid(), hourglass(), zsurf(), eye(), unit() (+8 more)

### Community 143 - "Community 143"
Cohesion: 0.14
Nodes (6): lin(), exposed(), build(), B(), render_all(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p

### Community 86 - "Community 86"
Cohesion: 0.12
Nodes (14): newid(), put(), obox(), cap(), pipe(), cell(), rivets(), finger() (+6 more)

### Community 144 - "Community 144"
Cohesion: 0.15
Nodes (8): cap(), chain(), lin(), exposed(), build(), B(), render_all(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p

### Community 186 - "Community 186"
Cohesion: 0.21
Nodes (13): assign(), limb(), _dilate6(), _greedy2d(), _quads(), export(), verify(), Rig + Roblox export for the BRICK pipeline (always run it: every brick model shi (+5 more)

### Community 402 - "Community 402"
Cohesion: 0.60
Nodes (4): concept_mask(), bbox(), main(), Overlay a render's silhouette on a concept view to check proportions 1:1. py com

### Community 404 - "Community 404"
Cohesion: 0.60
Nodes (4): outline(), main(), ffmpeg(), Post-process renders from studlib.py: black SILHOUETTE outline (like a Roblox Hi

### Community 57 - "Community 57"
Cohesion: 0.09
Nodes (26): lin(), box(), _emit(), wedge(), cyl(), ramp(), span(), sym() (+18 more)

### Community 60 - "Community 60"
Cohesion: 0.07
Nodes (27): argv(), emit(), parser(), cli(), add_common(), objects(), object_mode(), select_only() (+19 more)

### Community 392 - "Community 392"
Cohesion: 0.50
Nodes (2): MYTOOL_OT_offset_selected, Move selected objects along an axis

### Community 359 - "Community 359"
Cohesion: 0.33
Nodes (2): MYTOOL_PT_main, MYTOOL_AP_preferences

### Community 59 - "Community 59"
Cohesion: 0.07
Nodes (27): argv(), emit(), parser(), cli(), add_common(), objects(), object_mode(), select_only() (+19 more)

### Community 337 - "Community 337"
Cohesion: 0.52
Nodes (6): list_actions(), _assign(), _mute(), _root_motion(), run(), Bake animation clips from a control rig onto an export skeleton (visual keying),

### Community 310 - "Community 310"
Cohesion: 0.39
Nodes (7): _poses(), _diff(), _w(), _check(), run(), Check that a cycle loops: the pose at the last frame equals the first (no pop),, Signed angular velocity a -> b (deg, as a vector) so direction reversals are vis

### Community 287 - "Community 287"
Cohesion: 0.39
Nodes (8): _split(), _parts(), auto_map(), _rot(), run(), Retarget an animated skeleton (mocap/BVH/Mixamo/any rig) onto another rig, const, mixamorig:LeftUpLeg' -> ('upleg', 'L'); 'DEF-upper_arm.L' -> ('upperarm', 'L')., {(part, side): bone}, plus the spine chain (hips -> neck order).

### Community 199 - "Community 199"
Cohesion: 0.24
Nodes (12): _feeds(), _material_issues(), _mesh_world(), _islands(), _point_in_tri(), _uv_stats(), run(), _result() (+4 more)

### Community 441 - "Community 441"
Cohesion: 0.67
Nodes (3): _bounds(), run(), Render a multi-angle review contact sheet (headless-safe Workbench) for visual Q

### Community 232 - "Community 232"
Cohesion: 0.36
Nodes (10): _ctx(), unweighted(), _parent(), _proxy_weights(), _height(), _heat_scale(), cleanup(), run() (+2 more)

### Community 442 - "Community 442"
Cohesion: 0.67
Nodes (3): _mirror(), run(), Validate a skeleton + its skinned meshes for animation/engine export; optional s

### Community 266 - "Community 266"
Cohesion: 0.36
Nodes (9): _ensure_rigify(), _bounds(), _fit(), _remove_face(), _generate(), game_skeleton(), run(), Rigify pipeline: add + fit metarig, generate control rig, build an engine-ready (+1 more)

### Community 340 - "Community 340"
Cohesion: 0.43
Nodes (6): _side(), _find(), _rotate(), run(), Create a QA_Stress action with extreme poses to review deformation (elbows, knee, Rotate a pose bone about a WORLD axis through its head (rig-agnostic: ignores bo

### Community 175 - "Community 175"
Cohesion: 0.20
Nodes (14): _region(), _shell(), _transfer_weights(), _hide_body(), _drape(), transfer_morphs(), penetration(), run() (+6 more)

### Community 436 - "Community 436"
Cohesion: 0.67
Nodes (3): _gpu(), run(), Report Blender version, engines, GPU, add-ons, units and scene stats as JSON.  U

### Community 443 - "Community 443"
Cohesion: 0.67
Nodes (2): find_blender(), main()

### Community 309 - "Community 309"
Cohesion: 0.43
Nodes (7): _on_grid(), _pivot_target(), _texel_density(), _fix(), run(), Validate modular kit pieces so they snap together: applied transforms, footprint, Apply rotation+scale, then move the origin to the pivot without moving the geome

### Community 312 - "Community 312"
Cohesion: 0.39
Nodes (7): _on(), build_tree(), _instances(), run(), _layer_coll(), Biome scatter with Geometry Nodes: Poisson-disk instances of a collection on a s, Enabled socket by name: Random Value keeps one hidden Min/Max/Value per data typ

### Community 268 - "Community 268"
Cohesion: 0.33
Nodes (9): _noise_field(), _heightmap(), _erode(), _slope_deg(), _material(), _save_png16(), run(), Game-ready terrain: noise (fbm, ridged mountains, rolling hills) or a heightmap (+1 more)

### Community 265 - "Community 265"
Cohesion: 0.31
Nodes (9): glb_summary(), _gather(), _export(), _coerce(), _animated(), run(), Export objects/collections with engine presets, then verify the file.  Presets:, Parse the JSON chunk of a .glb (no import needed). (+1 more)

### Community 377 - "Community 377"
Cohesion: 0.53
Nodes (5): _keys(), _co(), _get(), run(), Shape-key toolkit for faces: create ARKit-52 / viseme sets, split symmetric keys

### Community 403 - "Community 403"
Cohesion: 0.50
Nodes (4): cleanup(), run(), Generate an LOD chain (<name>_LOD1..N) with Decimate, preserving UV seams/normal, Merge by distance, dissolve degenerate, delete loose. Returns removed vert count

### Community 437 - "Community 437"
Cohesion: 0.67
Nodes (3): _vram(), run(), Budget report: tris/verts per object, materials (draw calls), textures + VRAM, v

### Community 233 - "Community 233"
Cohesion: 0.29
Nodes (10): describe(), _sock(), build(), _layout(), apply(), _parse_val(), run(), Build node trees (Geometry Nodes, shader, compositor) from a compact JSON spec, (+2 more)

### Community 176 - "Community 176"
Cohesion: 0.24
Nodes (14): _assets(), _modifier(), hair_material(), groom(), _evaluated(), curve_stats(), _spaced(), build_cards() (+6 more)

### Community 435 - "Community 435"
Cohesion: 0.67
Nodes (3): _smooth_faces(), run(), Build (and optionally apply) a production hard-surface modifier stack.  Presets:

### Community 314 - "Community 314"
Cohesion: 0.43
Nodes (7): _bounds(), _clear(), _area(), _backdrop(), run(), _fcurves(), Look-dev scene in one call: framed camera, light rig (studio 3-point / HDRI / bo

### Community 308 - "Community 308"
Cohesion: 0.39
Nodes (7): _srgb_to_lin(), classify(), _find_textures(), _gltf_output_group(), run(), Build a correct metal/rough PBR material from texture files or a measured preset, Map type from filename tokens, scanning from the end (suffixes win).

### Community 338 - "Community 338"
Cohesion: 0.48
Nodes (6): gather(), load(), inventory(), _module(), run(), Batch over many files in one Blender process: convert formats, inventory report,

### Community 406 - "Community 406"
Cohesion: 0.60
Nodes (4): _gpu(), _frames(), run(), Render stills/animations with quality presets, per-camera batches, any output fo

### Community 401 - "Community 401"
Cohesion: 0.70
Nodes (4): _ctx(), _apply_all(), run(), Make a low-poly retopo copy of a dense mesh (sculpt/scan/AI-generated) at a tria

### Community 341 - "Community 341"
Cohesion: 0.43
Nodes (6): _islands(), _uv_area(), _measure(), run(), Measure (and optionally set) texel density in px/m for objects' active UV map., UV islands as lists of faces (connected through shared UV coords).

### Community 378 - "Community 378"
Cohesion: 0.47
Nodes (5): _seams_from_sharp(), _collapsed_ratio(), run(), Unwrap + pack UVs with production defaults; optional seams-from-sharp and lightm, Fraction of faces whose UV area is ~0 (failed unwrap).

### Community 444 - "Community 444"
Cohesion: 0.67
Nodes (3): _apply_rot_scale(), run(), Audit scene hygiene: units, transforms, naming, collections, materials, images,

### Community 407 - "Community 407"
Cohesion: 0.70
Nodes (4): _ctx(), _apply(), run(), Headless-safe sculpt preparation and procedural "sculpt" ops (no Sculpt Mode - i

### Community 313 - "Community 313"
Cohesion: 0.43
Nodes (7): _ctx(), _volume(), _asset_group(), _set_inputs(), _num(), run(), Set up and bake simulations: rigid bodies, classic cloth (presets), 5.2 node-bas

### Community 92 - "Community 92"
Cohesion: 0.19
Nodes (14): _lin(), _G, build_group(), _outline_material(), _key_light(), _drive_light(), _apply_mat(), _remove_mat() (+6 more)

### Community 213 - "Community 213"
Cohesion: 0.26
Nodes (11): _set_device(), _signal_override(), _restore(), _target_node(), _blur(), _curvature_from_normal(), run(), Bake texture maps with Cycles: high->low (selected-to-active) or self-bake proce (+3 more)

### Community 339 - "Community 339"
Cohesion: 0.43
Nodes (6): _material(), _gaps(), _grid(), run(), Mesh decal that conforms to a surface without z-fighting: a subdivided plane pla, World distance to the target at every evaluated triangle's centroid and corners-

### Community 109 - "Community 109"
Cohesion: 0.19
Nodes (12): _lin(), _G, build_group(), curvature_attribute(), _src(), _image_node(), _apply_mat(), _remove_mat() (+4 more)

### Community 98 - "Community 98"
Cohesion: 0.17
Nodes (21): _lerp_table(), lum(), _sun_dir(), _scene_bounds(), _clear(), _coll(), _light(), _norm() (+13 more)

### Community 408 - "Community 408"
Cohesion: 0.60
Nodes (4): _clip_area(), _solve(), run(), Automatic camera solve from footage: detect features at the start and end of the

### Community 342 - "Community 342"
Cohesion: 0.43
Nodes (6): _frames(), _add_clip(), _output(), run(), Assemble a video edit in the Video Sequencer headless: movies (with their audio), Sorted frame files for a folder or a # pattern, else None.

### Community 286 - "Community 286"
Cohesion: 0.33
Nodes (8): _clear(), _bolt_points(), _curve(), _envelope(), run(), Storm lightning: keyed multi-stroke flashes (a real strike is 3-4 return strokes, Midpoint displacement between top and bottom; returns a list of Vectors., {frame: intensity 0..1}. Each stroke: peak, 20% next frame, gone after ~3 frames

### Community 165 - "Community 165"
Cohesion: 0.22
Nodes (9): _T, _iface(), build_tree(), _material(), _camera_box(), run(), Rain, snow, dust, ash or embers as a seamlessly looping Geometry Nodes system (n, Minimal node-graph helper: n(type, inputs..., **props) -> node; sockets by enabl (+1 more)

### Community 120 - "Community 120"
Cohesion: 0.23
Nodes (11): _G, build_group(), _src(), _apply_mat(), _remove_mat(), _snow_tree(), _snow_material(), _vertex_mask() (+3 more)

### Community 168 - "Community 168"
Cohesion: 0.21
Nodes (15): mesh_object(), cube(), uv_sphere(), plane(), zfight_pair(), detached_part(), unwrap(), street() (+7 more)

### Community 289 - "Community 289"
Cohesion: 0.28
Nodes (8): skill_module(), fresh(), Skip, requires_gpu(), main(), In-Blender test runner. Discovers tests/test_*.py, runs each test_* on a fresh e, Import skills/<skill>/scripts/<script>.py fresh (tests call run() directly)., Skip when BAS_SKIP_GPU=1 (CI runners without GPU/EGL: EEVEE, Workbench renders).

### Community 65 - "Community 65"
Cohesion: 0.10
Nodes (15): Exception, push(), SDL_InitSubSystem(), SDL_QuitSubSystem(), main(), cube_vertices(), cube_indices(), main() (+7 more)

### Community 316 - "Community 316"
Cohesion: 0.32
Nodes (5): _walk(), test_bake_to_copy_with_root_motion_and_export(), _rig(), test_retarget_mixamo_to_rigify_names(), Keyframe the hips ('spine', child of root) moving dist metres toward -Y over 24

### Community 380 - "Community 380"
Cohesion: 0.47
Nodes (3): _mean_luma(), _render(), test_night_renders_darker_than_noon()

### Community 447 - "Community 447"
Cohesion: 0.83
Nodes (3): _pixels(), test_high_to_low_bake_normal_ao_curv_orm_basecolor(), test_self_bake_procedural_roughness()

### Community 348 - "Community 348"
Cohesion: 0.38
Nodes (5): _run_md_blocks(), test_bpy_patterns_snippets_run(), test_snippet_docs_across_skills(), Execute every ```python block of a reference doc on a fresh scene., Any reference doc tagged '(runs standalone)' must execute cleanly.

### Community 409 - "Community 409"
Cohesion: 0.50
Nodes (2): _trees(), test_scatter_respects_slope_height_and_realize()

### Community 410 - "Community 410"
Cohesion: 0.50
Nodes (2): _reimport_dims(), test_all_presets_roundtrip_scale()

### Community 448 - "Community 448"
Cohesion: 0.83
Nodes (3): _head(), test_groom_attached_masked_with_assets(), test_hair_cards_and_atlas()

### Community 449 - "Community 449"
Cohesion: 0.67
Nodes (2): _img(), test_texture_set_autowire_orm_dx_normal()

### Community 317 - "Community 317"
Cohesion: 0.43
Nodes (6): _scene(), _clusters(), _bands(), test_toon_hull_bands_lineart_roundtrip(), test_toon_scene_lighting_eevee(), Distinct flat colors (8-bit rounding splits a band into near-identical values).

### Community 79 - "Community 79"
Cohesion: 0.08
Nodes (1): Layer compiler, Core round trips, texture processing, recipe primitives and the

### Community 179 - "Community 179"
Cohesion: 0.24
Nodes (12): _qa(), test_clean_cube_passes(), test_detects_zfighting_between_objects_and_within_mesh(), test_slightly_offset_coplanar_is_zfighting_but_far_is_not(), test_detects_floating_parts_and_objects(), test_touching_parts_are_not_floating(), test_enclosed_part_is_not_floating(), test_detects_inverted_and_inconsistent_normals_and_back_to_back() (+4 more)

### Community 450 - "Community 450"
Cohesion: 0.67
Nodes (2): _camera(), test_render_stills_cycles_eevee_workbench()

### Community 291 - "Community 291"
Cohesion: 0.25
Nodes (7): _humanoid_mesh(), test_rigify_pipeline_bind_check_stress(), test_rig_check_dense_mesh(), test_bind_tiny_and_huge_rigs_get_real_weights(), Crude closed humanoid (torso, head, arms in T, legs) ~1.8 m, union of boxes (non, Issue #11: >= 4000 verts makes the symmetry sample step > 1 (bpy collections rej, Bone heat fails at mm/km world sizes (all weight on one bone); bind_mesh binds a

### Community 413 - "Community 413"
Cohesion: 0.60
Nodes (3): _grid(), test_classic_cloth_drapes_on_collider(), test_gn_cloth_52_asset()

### Community 382 - "Community 382"
Cohesion: 0.47
Nodes (4): _stepped_block(), test_smart_material_curvature_and_roundtrip(), test_smart_material_bakes_to_texture(), 1 m block with a 0.5 m step on top (convex outer edges + one concave inner edge)

### Community 111 - "Community 111"
Cohesion: 0.12
Nodes (14): _png(), test_vse_edit_crossfade_title_audio_mp4(), _footage(), test_track_camera_solves_in_ui_session(), 40 frames of a textured set seen by a dollying 35 mm camera (Workbench, textured, clip(), fake_unity(), test_unity_install_copies_the_package_and_draws_its_textures() (+6 more)

### Community 383 - "Community 383"
Cohesion: 0.40
Nodes (2): _instances(), test_precipitation_loops_and_stops_on_ground()

### Community 159 - "Community 159"
Cohesion: 0.16
Nodes (11): _Pocket, NamedTuple, _PolygonPocket, _Compartments, _CylinderPocket, _Notch, Gridfinity bin generator for CadQuery.  Vendored module: copy this file next to, Cavity with an arbitrary closed outline (list of (x, y) mm).          `clearance (+3 more)

### Community 220 - "Community 220"
Cohesion: 0.22
Nodes (7): GridfinityError, ValueError, _corner_radii(), Raised when a bin configuration cannot produce valid geometry., Normalize scalar / 2-tuple / 4-tuple corner radii.      Order: (+X+Y, -X+Y, -X-Y, Rounded-rect cavity cut from the top rim down `depth` mm.          `corner_r`: s, Feature footprint must leave MIN_WALL of outer wall.

### Community 247 - "Community 247"
Cohesion: 0.20
Nodes (5): _rounded_rect(), Draw a closed rounded-rect wire with per-corner radii on `workplane`.      `radi, Cutters (cavities) and additions (scoops, label shelves)., Concave quarter-round ramp along a compartment's front floor edge., 45-degree triangular label shelf hanging from a back wall.

### Community 52 - "Community 52"
Cohesion: 0.09
Nodes (14): _compound(), _fused(), GridfinityBin, Collect the solids of several workplanes/solids into one Compound.      Booleans, Combine cutter workplanes into one safe boolean tool.      Disjoint cutters ride, Builder for a spec-compatible Gridfinity bin.      Create the bin, add features,, Z of the interior floor: base profile plus solid floor., Deepest cavity possible from the top of the bin. (+6 more)

### Community 157 - "Community 157"
Cohesion: 0.17
Nodes (13): MatingError, AssertionError, overlap(), check_mating(), Fit checks for printed parts that go together (lids, joints, segments).  A previ, Volume in mm^3 shared by two CadQuery Workplanes (0 when apart)., Raise MatingError unless `moving` fits `fixed` with play only up to     `clearan, _socket() (+5 more)

### Community 248 - "Community 248"
Cohesion: 0.20
Nodes (9): load_mesh(), parse_bed(), bed_fit(), estimate_mass(), Pure trimesh STL loading with validation guards.  Kept separate from preview.py, Load an STL file via trimesh.      Raises ValueError if the file cannot be parse, Turn a printer name, "WxDxH" or a single "N" (cube) into (x, y, z) mm.      Rais, Check a part's bounding box against a build volume.      The part may be rotated (+1 more)

### Community 249 - "Community 249"
Cohesion: 0.29
Nodes (9): align_and_scale(), max_section_outline(), rotate_min_square(), recentered(), main(), Extract a 2D pocket outline from a 3D scan of an object.  Produces the max cross, PCA-align in XY, center on the origin, floor to Z=0, scale., Union of horizontal sections from Z=step/2 up to zmax. (+1 more)

### Community 71 - "Community 71"
Cohesion: 0.13
Nodes (25): _rotation_matrix(), _nice_spacing(), _build_grid(), _build_scene(), _add_edges(), _render_frame(), render_view(), _get_font() (+17 more)

### Community 296 - "Community 296"
Cohesion: 0.39
Nodes (7): _sibling(), _append_stderr(), _new_files_by_ext(), _process_stls(), main(), Return {ext: [paths]} in script_dir matching each *.{ext}     (case-insensitive), Load each STL once and optionally render a preview + check watertightness.

### Community 68 - "Community 68"
Cohesion: 0.11
Nodes (13): _mesh(), _volume(), _assert_footprint(), test_minimal_bin_no_lip(), test_bin_with_lip_magnets_screws(), test_compartments_scoop_label(), test_polygon_pocket_with_clearance_and_cylinder_well(), test_finger_notch_removes_material() (+5 more)

### Community 290 - "Community 290"
Cohesion: 0.22
Nodes (2): test_load_mesh_no_pyrender_import(), mesh_io must not pull in pyrender (it's the whole point of the split).

### Community 153 - "Community 153"
Cohesion: 0.21
Nodes (16): run(), test_happy_path(), test_strict_watertight(), test_strict_empty_fails(), test_bad_script_traceback(), test_json_shape_keys(), test_step_discovered(), test_preview_renders_png() (+8 more)

### Community 4 - "Community 4"
Cohesion: 0.02
Nodes (117): VFX_Dark_Vortex: Dark impact played where VFX_Projectile_Dark arrives: a black h, VFX_Fire_Explosion: Fire impact played where VFX_Projectile_Fire arrives.  Examp, VFX_Heal: Heal on the caster: no impact frame, a slow upward rise.  Example from, VFX_Hit_Heavy: Heavy melee hit: the blow lands on the target in place.  Example, VFX_Ice_Spikes: Ground ice eruption played where VFX_Projectile_Ice arrives.  Ex, VFX_Kaiju_Atomic_Beam: a sustained atomic breath that the game aims and sweeps (, VFX_Kaiju_Atomic_Charge: dorsal plates light up from the tail to the head before, VFX_Kaiju_Explosion: a photographic, building-sized fuel explosion for a kaiju b (+109 more)

### Community 147 - "Community 147"
Cohesion: 0.17
Nodes (15): _number(), _term(), _code(), _unknown(), validate_layer(), cutoff_easing(), layer_schema(), compile_effect() (+7 more)

### Community 194 - "Community 194"
Cohesion: 0.32
Nodes (3): LayerBuilder, Bind a texture slot and optionally scroll it; speeds are UV units per frame., Optional native features: dissolve, UV distortion, blend texture, fresnel, flipb

### Community 72 - "Community 72"
Cohesion: 0.13
Nodes (22): _emit(), _open(), _show(), _save(), _node_list(), _node_add(), _node_rename(), _node_remove() (+14 more)

### Community 252 - "Community 252"
Cohesion: 0.27
Nodes (9): editor_bin_directory(), runtime_config_path(), load_core(), export_binary(), Load the official Effekseer Core assembly through Python.NET., Return the configured directory containing ``EffekseerCore.dll``.      A release, Return the bundled .NET runtime configuration file., Load and return the official static ``Effekseer.Core`` type. (+1 more)

### Community 34 - "Community 34"
Cohesion: 0.07
Nodes (17): EffectSession, A handle to the single Core document hosted by this Python process., Add a Core node and return its AI-facing path., List every non-root node currently known to the session., Rename a node through its Core string value., Remove a node and its descendants from the current document., Move a node and return its new structural path., Read a public Core member without invoking arbitrary methods. (+9 more)

### Community 430 - "Community 430"
Cohesion: 0.50
Nodes (2): Discover editable leaf paths without walking parent/tree references., Discover parameters grouped as they are in the editor's setting panels.

### Community 354 - "Community 354"
Cohesion: 0.33
Nodes (4): timeline(), validate(), Design briefs (vfx/briefs/<ID>.json) live outside the strict Effekseer layer sch, Absolute first/last births, including parent emission intervals and random life.

### Community 155 - "Community 155"
Cohesion: 0.19
Nodes (16): owned(), eid(), check_output_dirs(), check_targets(), removable(), resource_inputs(), resource_names(), check_resource_conflicts() (+8 more)

### Community 355 - "Community 355"
Cohesion: 0.43
Nodes (6): parser(), recipes_for(), run(), main(), effekseer-vfx command line: one JSON object on stdout per command; progress and, (selected, context, unloaded): with --ids only the named sources must load; a fu

### Community 388 - "Community 388"
Cohesion: 0.47
Nodes (5): version(), setup_python(), doctor(), What this machine can do right now. Standard library only, so it runs before set, What setup.sh (setup.ps1 on Windows) would use for the toolchain: uv, else a Pyt

### Community 94 - "Community 94"
Cohesion: 0.22
Nodes (22): now(), store(), current_recipe(), prepared(), portable(), inputs(), outputs(), write_build() (+14 more)

### Community 245 - "Community 245"
Cohesion: 0.31
Nodes (10): catalog(), ids(), textures(), listing(), add(), show(), show_any(), Shipped example effects: four ranged pairs (projectile + impact), five single ef (+2 more)

### Community 425 - "Community 425"
Cohesion: 0.50
Nodes (4): reviewer_skill(), handoff(), Everything an independent reviewer needs for one capture, as a prompt the author, The vfx-review skill installed next to this one (both folders are installed side

### Community 190 - "Community 190"
Cohesion: 0.22
Nodes (12): HelperFinder, sources(), _forget_helpers(), load(), describe(), library(), partial(), get() (+4 more)

### Community 114 - "Community 114"
Cohesion: 0.16
Nodes (20): screen_errors(), release_frames(), documented_textures(), stem(), hot(), colours(), moves(), look() (+12 more)

### Community 156 - "Community 156"
Cohesion: 0.17
Nodes (16): valid_id(), digest(), owned(), unmanaged(), name_key(), same_name(), may_use(), inside() (+8 more)

### Community 275 - "Community 275"
Cohesion: 0.20
Nodes (9): initialized(), full_mode_platform(), setup_command(), godot(), Where the skill's own files live, where the toolchain is installed and which gam, `vfx init` has run here: a vfx/ folder that merely exists (another tool's output, Where build and render (EffekseerCore through .NET, the Effekseer Godot plugin), How to run setup on this system, as a command an agent can run from the project. (+1 more)

### Community 276 - "Community 276"
Cohesion: 0.38
Nodes (8): checked_id(), read(), analyse(), tiles(), import_clip(), frames(), compare(), Local reference clips, explicit time mapping and honest approximate pixel analys

### Community 101 - "Community 101"
Cohesion: 0.13
Nodes (21): front_app(), run_windowed(), sample_plan(), frame_state(), capture(), metrics(), dump_metrics(), diff() (+13 more)

### Community 356 - "Community 356"
Cohesion: 0.38
Nodes (6): toolchain_lock(), download(), initialize(), Create or refresh the project's vfx/ workspace from the skill's Lab template and, Serialise downloads into the shared EFFEKSEER_VFX_HOME across projects and proce, A verified copy of `url` at `target`: downloaded to a private temporary file, ch

### Community 170 - "Community 170"
Cohesion: 0.21
Nodes (15): profile(), _map(), _frames(), _life(), _time(), _space(), _layers(), apply() (+7 more)

### Community 55 - "Community 55"
Cohesion: 0.15
Nodes (30): sequence_id(), path(), gate_path(), read(), store(), rubric(), criteria(), recipe_hashes() (+22 more)

### Community 426 - "Community 426"
Cohesion: 0.70
Nodes (4): content(), cell_report(), audit(), Pixel observations grouped by texture role; stylistic warnings are not build fai

### Community 102 - "Community 102"
Cohesion: 0.14
Nodes (21): spectral(), worley(), masks(), _sample(), swirl(), flame_band(), speed_streaks(), helix() (+13 more)

### Community 95 - "Community 95"
Cohesion: 0.15
Nodes (22): _project(), _save(), _mask(), _inner_gradient(), _periodic(), _tile_noise(), _polar(), _blob() (+14 more)

### Community 48 - "Community 48"
Cohesion: 0.11
Nodes (33): _ffmpeg(), _decode(), _png(), _in_project(), _resolve_output(), _resolve_sheet(), _portable(), _report_dir() (+25 more)

### Community 217 - "Community 217"
Cohesion: 0.23
Nodes (6): file_hash(), relative(), absolute(), snapshot(), unchanged(), Shared portable storage and a reentrant, cross-process workspace lock.

### Community 131 - "Community 131"
Cohesion: 0.15
Nodes (11): recipe(), test_lint_passes_the_library_and_reports_each_hard_rule(), test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape(), test_lint_warns_about_craft_problems(), frames(), test_review_metrics_accept_a_well_formed_effect(), test_review_metrics_flag_off_peak_flash_flat_colour_and_wrong_direction(), test_short_effect_with_an_empty_second_half_is_a_dead_tail() (+3 more)

### Community 272 - "Community 272"
Cohesion: 0.20
Nodes (3): test_editor_bin_directory_requires_an_explicit_configuration(), The vendored effekseer_ai bridge: portable CLI surface and an explicit, never-gu, A public release must never probe a contributor's local disks.

### Community 238 - "Community 238"
Cohesion: 0.22
Nodes (4): example_ids(), test_catalog_lists_every_shipped_example_as_pairs_singles_and_sets(), test_lint_of_all_examples_has_no_errors(), Shipped example effects: complete, valid, self-consistent with their briefs and

### Community 93 - "Community 93"
Cohesion: 0.12
Nodes (12): vfx(), system_python(), test_doctor_runs_through_the_wrapper_on_a_bare_system_python(), test_doctor_reports_an_initialised_workspace(), test_cli_init_examples_and_lint_in_a_fresh_project(), test_examples_add_does_not_overwrite_without_force(), test_examples_list_and_show_without_a_workspace(), test_rubric_and_layer_schema_commands() (+4 more)

### Community 50 - "Community 50"
Cohesion: 0.11
Nodes (26): files(), publisher_allowed(), attribution_allowed(), private_terms(), text_hits(), png_metadata(), jpeg_metadata(), file_hits() (+18 more)

### Community 44 - "Community 44"
Cohesion: 0.07
Nodes (15): game(), test_a_full_build_of_an_empty_library_refuses_before_touching_anything(), test_a_broken_source_only_blocks_itself(), test_project_files_never_shadow_modules(), test_a_full_build_prunes_only_effects_it_built(), test_init_fills_missing_math_textures_without_replacing_edited_ones(), test_helpers_never_shadow_built_in_modules(), test_a_build_never_replaces_a_resource_another_built_effect_uses() (+7 more)

### Community 110 - "Community 110"
Cohesion: 0.11
Nodes (6): recipe_with(), test_scale_character_is_a_no_op_and_records_nothing(), test_lint_scales_its_craft_limits_with_the_recipe(), test_beam_recipe_lints_with_hold_and_needs_a_release(), test_lint_counts_repeatedly_emitted_painted_shapes_as_restruck(), World scale, game-driven bind equations, beams, charge chains and soft particles

### Community 215 - "Community 215"
Cohesion: 0.33
Nodes (8): vfx(), workspace(), test_blockout_lint_holds_recipes_to_math_textures(), test_screen_feedback_is_validated(), test_detail_needs_the_blockout_gate_and_steal_lists(), test_a_blockout_sequence_needs_blockout_effects(), test_game_frames_become_evidence_and_a_blockout_ship_opens_the_gate(), Sequences (combos), the blockout gate, screen feedback and the stylized hard-edg

### Community 112 - "Community 112"
Cohesion: 0.14
Nodes (12): isolated(), captured(), report(), test_evidence_is_stored_in_the_workspace_work_folder(), test_build_and_render_reject_changed_sources_assets_outputs_and_templates(), test_independent_report_binds_images_scores_and_observed_frames(), test_completion_requires_brief_review_and_overview_instead_of_no_flags(), test_reference_compare_requires_exact_fresh_render_frames() (+4 more)

### Community 264 - "Community 264"
Cohesion: 0.27
Nodes (9): rule_origin(), describe_rule(), analyze(), main(), Analyzes R8 keep rule radius JSON output and computes optimization scores., Returns the file, line and Maven coordinate a keep rule comes from., Returns a rule's source text, origin, and whether the app can edit it., Computes R8 optimization scores and rule impacts from keep radius JSON. (+1 more)

### Community 374 - "Community 374"
Cohesion: 0.40
Nodes (5): convert_pb_to_json(), main(), Converts R8 keep radius protobuf files into JSON format., Reads an R8 BlastRadiusContainer protobuf and writes it as JSON., Entry point for CLI execution.

### Community 90 - "Community 90"
Cohesion: 0.14
Nodes (22): run_scraper(), strip_emojis(), format_code_link(), render_table(), parse_boolean(), parse_disclosure_status(), clean_severity(), render_finding_card() (+14 more)

### Community 30 - "Community 30"
Cohesion: 0.07
Nodes (46): _strip_inline_comment(), _candidate_project_roots(), load_gradle_properties(), load_version_catalog(), load_app_plugin_aliases(), _build_app_plugin_alias_pattern(), load_custom_gradle_versions(), _load_json_file() (+38 more)

### Community 91 - "Community 91"
Cohesion: 0.11
Nodes (14): fetch_html(), PlayStoreMetadataParser, PlayStoreDataSafetyParser, load_taxonomy(), extract_metadata(), extract_data_safety(), scrape_app_details(), Fetches HTML content from a URL with a realistic User-Agent. (+6 more)

### Community 200 - "Community 200"
Cohesion: 0.26
Nodes (12): get_scanner_config(), get_supported_extensions(), collect_target_files(), _identify_semantic_files(), _scan_single_file(), perform_scan(), Loads the scanner configuration from scanner_config.json with caching., Returns a tuple of supported file extensions from config. (+4 more)

### Community 49 - "Community 49"
Cohesion: 0.09
Nodes (21): get_nested_val(), Node, TextNode, VarNode, IfNode, strip_nodes(), EachNode, _ParserFrame (+13 more)

### Community 361 - "Community 361"
Cohesion: 0.47
Nodes (5): download_or_get_cached(), get_perfetto_prebuilt(), run_perfetto_prebuilt(), Downloads a prebuilt or returns a cached version    The first time this is invok, Downloads the prebuilt, if necessary, and returns its path on disk.

### Community 305 - "Community 305"
Cohesion: 0.39
Nodes (7): _skills_dir(), _strip_frontmatter(), _frontmatter_value(), _build_bootstrap(), register(), Locate the stock skills/ tree for either supported install layout.      - git-cl, Return a flat ``key: value`` scalar from a SKILL.md frontmatter block.      Herm

### Community 231 - "Community 231"
Cohesion: 0.24
Nodes (9): __dirname, superpowersSkillsDir, extractAndStripFrontmatter(), _bootstrapCache, getBootstrapContent(), _childSessionCache, _cacheChildSession(), isChildSession() (+1 more)

### Community 225 - "Community 225"
Cohesion: 0.22
Nodes (7): extensionDir, packageRoot, skillsDir, bootstrapSkillPath, getBootstrapContent(), stripFrontmatter(), piToolMapping()

### Community 285 - "Community 285"
Cohesion: 0.33
Nodes (5): sessionKey(), websocketUrl(), reloadAfterRecovery(), setStatus(), connect()

### Community 391 - "Community 391"
Cohesion: 0.53
Nodes (4): extractDotBlocks(), combineGraphs(), renderToSvg(), main()

### Community 105 - "Community 105"
Cohesion: 0.14
Nodes (18): { spawn }, http, WebSocket, fs, path, assert, SERVER_PATH, CONTENT_DIR (+10 more)

### Community 74 - "Community 74"
Cohesion: 0.14
Nodes (21): { spawn }, http, fs, path, assert, REPO_ROOT, SERVER_PATH, cleanup() (+13 more)

### Community 429 - "Community 429"
Cohesion: 0.50
Nodes (2): assert, {
  browserLauncherForPlatform
}

### Community 277 - "Community 277"
Cohesion: 0.22
Nodes (6): assert, fs, path, HELPER, src, moduleShim

### Community 82 - "Community 82"
Cohesion: 0.13
Nodes (20): { spawn }, http, WebSocket, fs, path, assert, SERVER_PATH, CONTENT_DIR (+12 more)

### Community 330 - "Community 330"
Cohesion: 0.29
Nodes (5): assert, crypto, path, SERVER_PATH, RFC-6455

### Community 163 - "Community 163"
Cohesion: 0.23
Nodes (5): _load(), _bootstrap(), TestStripFrontmatter, TestSkillsDirResolution, TestBootstrapContent

### Community 73 - "Community 73"
Cohesion: 0.14
Nodes (9): _load_plugin(), _fire_pre_llm(), TestPluginRegistration, TestBootstrapInjection, TestLayoutResolution, TestSkillDescriptions, Re-import plugin module fresh., Copy the plugin module + a minimal skills tree in the given layout. (+1 more)

### Community 148 - "Community 148"
Cohesion: 0.12
Nodes (6): mappingFailures, firstOutput, afterFirst, secondOutput, afterSecond, result

### Community 119 - "Community 119"
Cohesion: 0.10
Nodes (14): pluginURL, rootEvent, checkpoint, freshRootEvent, childEvent, originalChild, unknownChild, recoveredChild (+6 more)

### Community 257 - "Community 257"
Cohesion: 0.20
Nodes (8): pluginPath, skillsDir, failures, added, survived, frontmatterFixtures, fixtureRoot, result

### Community 230 - "Community 230"
Cohesion: 0.18
Nodes (5): __dirname, repoRoot, packageJsonPath, extensionPath, piToolsPath

### Community 295 - "Community 295"
Cohesion: 0.32
Nodes (5): ease(), interp(), foot(), Generate separate R6 clips from untouched full adapted bases. Requires Blender 5, Continuous velocity at footfall and toe-off; -Y movement during stance.

### Community 0 - "Community 0"
Cohesion: 0.02
Nodes (34): Quarter-frame ground and stance-target diagnostics for editable rigs., floats(), capture(), Checks sampled positions after reopening each clip. Does not certify artistry., Preservation-first R6 export. Never overwrites source or prior outputs.  Blender, Read-only Blender GLB round-trip check. Run in a separate background process.  b, Regression tests independent of Blender: python test_uv_overlap.py., Validate the opened R6 .blend. Run with Blender background mode.  Example: blend (+26 more)

### Community 360 - "Community 360"
Cohesion: 0.40
Nodes (2): smooth(), interp()

### Community 457 - "Community 457"
Cohesion: 1.00
Nodes (2): floats(), capture()

### Community 469 - "Community 469"
Cohesion: 0.67
Nodes (1): Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).  Run:

### Community 470 - "Community 470"
Cohesion: 0.67
Nodes (1): Adapt BoyR6 for PokoX.  Fixes:   1. Head shading: collapse the dead customFaces

### Community 471 - "Community 471"
Cohesion: 0.67
Nodes (1): Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876.

### Community 328 - "Community 328"
Cohesion: 0.25
Nodes (1): OverlapTests

### Community 329 - "Community 329"
Cohesion: 0.36
Nodes (7): _cross(), _signed_area(), intersection_area(), find_cross_mesh_overlaps(), Test positive-area overlap between triangles belonging to different meshes.  Sha, Return the UV area common to two triangles, independent of winding., Input: iterable of (mesh_name, triangle of three (u,v) pairs).      Returns coun

### Community 333 - "Community 333"
Cohesion: 0.29
Nodes (1): ReservationMigrationTests

### Community 17 - "Community 17"
Cohesion: 0.04
Nodes (26): users, games, assets, ledger_entries, balances, share_entries, games, cases (+18 more)

### Community 394 - "Community 394"
Cohesion: 0.40
Nodes (1): DurationQueryState

### Community 303 - "Community 303"
Cohesion: 0.32
Nodes (4): Fixed, sine_lookup(), sin(), cos()

### Community 207 - "Community 207"
Cohesion: 0.27
Nodes (7): saturate_raw64(), isqrt_u64(), raw_length_sq(), dot(), lengthSquared(), length(), normalized()

### Community 10 - "Community 10"
Cohesion: 0.03
Nodes (33): FixedStepLoop, near(), main(), Exercise the real host compiler and CMake shader rule in an isolated build., parse_runtime(), classify(), run_step(), main() (+25 more)

### Community 331 - "Community 331"
Cohesion: 0.43
Nodes (4): dot(), length(), lengthSquared(), normalized()

### Community 344 - "Community 344"
Cohesion: 0.57
Nodes (6): valid_utf8(), fail(), read_argument(), half_to_double(), decode_item(), decode()

### Community 270 - "Community 270"
Cohesion: 0.44
Nodes (9): fail(), find_key(), read_u32(), read_bool(), read_text(), parse_level(), collect_unknown(), load_file() (+1 more)

### Community 345 - "Community 345"
Cohesion: 0.43
Nodes (4): window_mean(), fps(), cpu_ms(), gpu_ms()

### Community 234 - "Community 234"
Cohesion: 0.33
Nodes (9): to_spdlog(), emit(), init(), trace(), debug(), info(), warn(), error() (+1 more)

### Community 288 - "Community 288"
Cohesion: 0.33
Nodes (5): to_ns(), FixedStepLoop(), valid_limits(), advance(), alpha()

### Community 127 - "Community 127"
Cohesion: 0.30
Nodes (18): head(), put_u(), put_n(), put_t(), put_b(), put_bool(), put_null(), put_arr() (+10 more)

### Community 431 - "Community 431"
Cohesion: 0.83
Nodes (3): read_file(), count_stamps(), main()

### Community 193 - "Community 193"
Cohesion: 0.22
Nodes (10): fx(), isqrt_ref(), main(), XorShift128Plus, SimClock, near(), near_vec(), main() (+2 more)

### Community 350 - "Community 350"
Cohesion: 0.57
Nodes (6): raw3(), v3(), naive_dot(), naive_in_range(), len_d(), main()

### Community 460 - "Community 460"
Cohesion: 1.00
Nodes (2): near(), main()

### Community 64 - "Community 64"
Cohesion: 0.15
Nodes (25): CharacterController, planar(), length_of(), translated(), shape_bound(), spheres_disjoint(), touches_uncached(), append_shape_raws() (+17 more)

### Community 18 - "Community 18"
Cohesion: 0.05
Nodes (33): ConvexShape, SapBroadphase, SoftBody, ClothGrid, SequentialImpulseSolver, VisualSolver, VisualWorld, insert() (+25 more)

### Community 100 - "Community 100"
Cohesion: 0.20
Nodes (21): centroid(), cso_support(), dist_sq_of(), closest_segment(), closest_triangle(), origin_in_tetra(), closest_on_hull(), gjk_distance() (+13 more)

### Community 235 - "Community 235"
Cohesion: 0.31
Nodes (7): clamp01(), create_lattice(), add_node(), add_spring(), apply_acceleration(), step(), create()

### Community 141 - "Community 141"
Cohesion: 0.23
Nodes (16): tangent_basis(), clampf(), collide_sphere_sphere(), collide_sphere_box(), collide_box_box(), upsert_body(), clear(), find_body() (+8 more)

### Community 293 - "Community 293"
Cohesion: 0.47
Nodes (8): v3(), fx(), tod(), todv(), aabb(), wedge(), params(), main()

### Community 352 - "Community 352"
Cohesion: 0.52
Nodes (6): sphere(), aabb(), v3(), tod(), todv(), main()

### Community 421 - "Community 421"
Cohesion: 0.80
Nodes (4): lo(), box(), sorted_pairs(), main()

### Community 324 - "Community 324"
Cohesion: 0.57
Nodes (7): v3(), fx(), tod(), body(), statics(), contact(), main()

### Community 197 - "Community 197"
Cohesion: 0.19
Nodes (7): ~SdlPlatform(), IPlatform, shutdown(), destroy_window(), get_window_size(), poll_event(), TestPlatform

### Community 396 - "Community 396"
Cohesion: 0.40
Nodes (4): ClientData, ClientMessage, XEvent, Optional Linux/X11 host smoke test; not a Windows or Android test.  Usage: DISPL

### Community 282 - "Community 282"
Cohesion: 0.28
Nodes (4): FrameGraph, build_plan(), compile(), execute()

### Community 343 - "Community 343"
Cohesion: 0.43
Nodes (4): perspective(), look_at(), multiply(), view_proj()

### Community 208 - "Community 208"
Cohesion: 0.27
Nodes (7): png_chunk(), canonical_png(), XImage, X11, run(), main(), RGB8 PNG with filter 0 and explicit uncompressed DEFLATE blocks.

### Community 306 - "Community 306"
Cohesion: 0.32
Nodes (2): decode(), GoldenEncoderTests

### Community 8 - "Community 8"
Cohesion: 0.04
Nodes (52): Scheduler, AggregateStore, ProjectionGate, SessionAuthority, TicketIssuanceGate, ByoRegistration, MatchQueue, PartyBook (+44 more)

### Community 452 - "Community 452"
Cohesion: 0.83
Nodes (3): near(), transform(), main()

### Community 373 - "Community 373"
Cohesion: 0.33
Nodes (2): AssetHandle, AssetStore

### Community 167 - "Community 167"
Cohesion: 0.14
Nodes (4): load_state(), is_loading(), AssetHandle(), release()

### Community 446 - "Community 446"
Cohesion: 0.83
Nodes (3): fail(), in_bounds(), load_ktx2()

### Community 346 - "Community 346"
Cohesion: 0.57
Nodes (6): fail(), read_u32(), read_f32(), finite_vec3(), parse_pokomesh(), load_pokomesh()

### Community 458 - "Community 458"
Cohesion: 1.00
Nodes (2): counting_loader(), main()

### Community 322 - "Community 322"
Cohesion: 0.46
Nodes (7): put32(), put64(), set32(), set64(), make_ktx2(), write(), main()

### Community 386 - "Community 386"
Cohesion: 0.67
Nodes (5): put32(), putf(), make_pmes(), write(), main()

### Community 183 - "Community 183"
Cohesion: 0.23
Nodes (5): PokoActivity, Activity, SurfaceHolder, Callback, SurfaceView

### Community 221 - "Community 221"
Cohesion: 0.27
Nodes (7): VulkanDiagnostics(), totals(), since(), start(), start_with_factory(), messages(), stop()

### Community 299 - "Community 299"
Cohesion: 0.32
Nodes (4): ClearBackend, ClearBackendSelection(), start(), shutdown()

### Community 171 - "Community 171"
Cohesion: 0.14
Nodes (4): VulkanClearBackend, ClearBackend, OpenGLClearBackend, OpenGLESClearBackend

### Community 250 - "Community 250"
Cohesion: 0.29
Nodes (7): SdlPlatform, OpenGLClearRenderer(), default_framebuffer_is_srgb(), native_window(), initialize(), clear_and_present(), shutdown()

### Community 205 - "Community 205"
Cohesion: 0.24
Nodes (6): OpenGLClearESRenderer(), initialize(), initialize_window(), initialize_impl(), shutdown(), shutdown_checked()

### Community 122 - "Community 122"
Cohesion: 0.16
Nodes (11): VulkanClearAndroidRenderer(), make_instance(), make_surface(), pick_device(), pick_surface_format(), make_device_objects(), make_swapchain(), initialize() (+3 more)

### Community 222 - "Community 222"
Cohesion: 0.29
Nodes (9): SdlPlatform, VulkanClearRenderer(), native_window(), Impl(), initialize(), clear_and_present(), draw_and_present(), shutdown() (+1 more)

### Community 364 - "Community 364"
Cohesion: 0.33
Nodes (2): VulkanDiagnostics, VulkanImGuiPass()

### Community 251 - "Community 251"
Cohesion: 0.22
Nodes (4): VulkanDiagnostics, VulkanMeshPass(), draw_and_present(), draw()

### Community 279 - "Community 279"
Cohesion: 0.28
Nodes (6): VulkanDiagnostics, VulkanTrianglePass(), draw_and_present(), draw(), set_texture(), set_texture_mips()

### Community 362 - "Community 362"
Cohesion: 0.47
Nodes (5): linear_to_srgb_byte(), FailingPrimaryBackend, rhi::ClearBackend, report_pixel(), main()

### Community 363 - "Community 363"
Cohesion: 0.60
Nodes (4): write_line(), run_probe(), Java_com_poko_glesclear_PokoActivity_nativeInit(), Java_com_poko_glesclear_PokoActivity_nativeSetSurface()

### Community 384 - "Community 384"
Cohesion: 0.47
Nodes (3): reset(), write_spirv(), main()

### Community 180 - "Community 180"
Cohesion: 0.16
Nodes (1): EvidenceTests

### Community 353 - "Community 353"
Cohesion: 0.38
Nodes (3): draw_and_present(), reset(), main()

### Community 432 - "Community 432"
Cohesion: 0.50
Nodes (2): DeclarationParser, DeclarationAst

### Community 87 - "Community 87"
Cohesion: 0.13
Nodes (17): int_scalar(), eval_binary(), eval_unary(), eval_compare(), fold_constants(), is_terminator(), verify(), check() (+9 more)

### Community 227 - "Community 227"
Cohesion: 0.22
Nodes (6): gamepad_slot(), gamepad_control(), touch_display(), touch_id(), InputTimeline, InputReplay

### Community 138 - "Community 138"
Cohesion: 0.18
Nodes (12): is_terminator_pub(), alu(), mk(), mov(), br16(), br32(), emit_bytecode(), is_terminator() (+4 more)

### Community 399 - "Community 399"
Cohesion: 0.40
Nodes (2): ExpressionParser, Ast

### Community 433 - "Community 433"
Cohesion: 0.50
Nodes (2): StatementParser, StatementAst

### Community 219 - "Community 219"
Cohesion: 0.47
Nodes (10): mnemonic(), branch(), long_offset(), long_payload(), branch_offset(), validate_bytecode(), encode_bytecode(), decode_bytecode() (+2 more)

### Community 162 - "Community 162"
Cohesion: 0.24
Nodes (13): diagnostic(), rebased(), number(), numeric(), spelling(), decode_string(), evaluate_console(), execute_console_impl() (+5 more)

### Community 77 - "Community 77"
Cohesion: 0.24
Nodes (20): is_unsigned(), is_float(), width(), unsigned_max(), signed_max(), signed_min(), magnitude(), negative() (+12 more)

### Community 47 - "Community 47"
Cohesion: 0.13
Nodes (32): put8(), put16(), put32(), read_bytes(), get8(), get16(), get32(), is_axis_device() (+24 more)

### Community 255 - "Community 255"
Cohesion: 0.27
Nodes (5): slot_in_use(), connect(), find_native(), route_count(), routes()

### Community 58 - "Community 58"
Cohesion: 0.16
Nodes (25): put8(), put16(), put32(), put64(), put_event(), read_bytes(), get8(), get16() (+17 more)

### Community 226 - "Community 226"
Cohesion: 0.33
Nodes (9): decode(), digit(), digit_for(), is_start(), is_continue(), keyword(), suffix(), string_body() (+1 more)

### Community 398 - "Community 398"
Cohesion: 0.70
Nodes (4): supported(), calculate(), deterministic_sin(), deterministic_cos()

### Community 258 - "Community 258"
Cohesion: 0.42
Nodes (9): trim(), quoted(), string_array(), after_token(), next_quoted(), parse_manifest(), declared_identity(), build_project() (+1 more)

### Community 336 - "Community 336"
Cohesion: 0.43
Nodes (4): inner_position(), unquote(), parse_import_spec(), resolve_packages()

### Community 284 - "Community 284"
Cohesion: 0.28
Nodes (5): decl_fail(), decl_quoted(), DeclarationParser, Depth(), dump_declaration_ast()

### Community 259 - "Community 259"
Cohesion: 0.24
Nodes (4): op_spelling(), quoted(), ExpressionParser, dump_ast()

### Community 260 - "Community 260"
Cohesion: 0.24
Nodes (5): stmt_fail(), quoted(), StatementParser, Depth(), dump_statement_ast()

### Community 434 - "Community 434"
Cohesion: 1.00
Nodes (3): head(), text(), make_pkb_schema_draft()

### Community 140 - "Community 140"
Cohesion: 0.20
Nodes (13): fail(), Depth(), Parser, Runner, prepare_globals(), commit_globals(), run_stateful_program(), run_program() (+5 more)

### Community 269 - "Community 269"
Cohesion: 0.22
Nodes (3): Analyzer, name(), dump_determinism()

### Community 150 - "Community 150"
Cohesion: 0.16
Nodes (7): unit_t(), convert_type(), requires_mask(), Lowerer, lower_function(), lower_function_ex(), lower_module()

### Community 166 - "Community 166"
Cohesion: 0.16
Nodes (8): same_type(), accepts(), is_integer_scalar(), is_float_scalar(), numeric(), Analyzer, name(), dump_semantic()

### Community 347 - "Community 347"
Cohesion: 0.48
Nodes (5): read64(), read32(), merge(), xxhash64(), hash_state()

### Community 379 - "Community 379"
Cohesion: 0.60
Nodes (5): append_le(), read_le(), schema_for(), save_state_snapshot(), load_state_snapshot()

### Community 271 - "Community 271"
Cohesion: 0.22
Nodes (2): mix(), hash()

### Community 187 - "Community 187"
Cohesion: 0.18
Nodes (6): hash_bytes(), push_back(), erase(), hash(), remove(), keys()

### Community 236 - "Community 236"
Cohesion: 0.29
Nodes (7): rotr(), compress(), append_u32_be(), sha256(), hmac_sha256(), sign_detached(), verify_detached()

### Community 39 - "Community 39"
Cohesion: 0.07
Nodes (21): splitmix64(), det_sqrt(), det_lerp(), vec2_lerp(), vec2_dot(), vec2_length_squared(), vec2_normalize(), vec3_add() (+13 more)

### Community 237 - "Community 237"
Cohesion: 0.31
Nodes (6): decode(), valid_utf8(), codepoint_count(), slice_codepoints(), concat(), to_lower_ascii()

### Community 182 - "Community 182"
Cohesion: 0.22
Nodes (7): finish(), has_breakpoint(), step(), run(), pc(), result(), stack()

### Community 427 - "Community 427"
Cohesion: 0.70
Nodes (4): host_type(), add(), find(), unauthorized_hostcalls()

### Community 389 - "Community 389"
Cohesion: 0.47
Nodes (3): find(), cancel(), run()

### Community 133 - "Community 133"
Cohesion: 0.26
Nodes (17): make_int(), handle_for(), object(), free_slot(), alloc(), make_string(), make_array(), get_index() (+9 more)

### Community 390 - "Community 390"
Cohesion: 0.47
Nodes (3): VmCore, fail(), step()

### Community 169 - "Community 169"
Cohesion: 0.28
Nodes (15): key(), mouse_button(), wheel(), pad_button(), pad_axis(), touch(), kb(), mouse() (+7 more)

### Community 292 - "Community 292"
Cohesion: 0.44
Nodes (8): check(), i32(), compile(), run(), best_ns(), bench(), cases(), main()

### Community 240 - "Community 240"
Cohesion: 0.35
Nodes (10): check(), def(), run_err(), ceiling(), i32(), v(), pv(), narrowed_module() (+2 more)

### Community 319 - "Community 319"
Cohesion: 0.61
Nodes (7): check(), pay(), imm(), arith(), divzero(), cases(), main()

### Community 320 - "Community 320"
Cohesion: 0.54
Nodes (7): check(), tree(), error(), cases(), depth_guard(), randomized_input(), main()

### Community 416 - "Community 416"
Cohesion: 0.70
Nodes (4): ok(), error(), cases(), main()

### Community 241 - "Community 241"
Cohesion: 0.42
Nodes (10): event(), connect(), disconnect(), pad_button(), pad_axis(), touch_tap(), apply_events(), pos() (+2 more)

### Community 294 - "Community 294"
Cohesion: 0.47
Nodes (8): check(), compile(), total_words(), run(), same_result(), diff_case(), cases(), main()

### Community 188 - "Community 188"
Cohesion: 0.48
Nodes (13): check(), i32(), v(), pv(), arith_module(), calls_module(), hostcall_module(), wide_call_module() (+5 more)

### Community 459 - "Community 459"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 242 - "Community 242"
Cohesion: 0.47
Nodes (10): check(), eval(), signed_case(), unsigned_case(), error_case(), cases(), floating(), bindings() (+2 more)

### Community 321 - "Community 321"
Cohesion: 0.50
Nodes (7): check(), i32t(), run_source(), val(), count_op(), cases(), main()

### Community 417 - "Community 417"
Cohesion: 0.70
Nodes (4): check(), def(), run_err(), main()

### Community 216 - "Community 216"
Cohesion: 0.39
Nodes (11): key(), button(), motion(), wheel(), gamepad_button(), gamepad_axis(), touch(), simple() (+3 more)

### Community 351 - "Community 351"
Cohesion: 0.57
Nodes (6): check(), tokens(), diagnostic(), examples(), deterministic_streams(), main()

### Community 385 - "Community 385"
Cohesion: 0.73
Nodes (5): check(), error(), test_cases(), unicode_conformance(), main()

### Community 418 - "Community 418"
Cohesion: 0.70
Nodes (4): check(), compile_recursion(), run_recursion(), main()

### Community 204 - "Community 204"
Cohesion: 0.35
Nodes (12): check(), i32t(), lower_src(), module_of(), run_mod(), val(), count_op(), count_instrs() (+4 more)

### Community 419 - "Community 419"
Cohesion: 0.70
Nodes (4): expect_ok(), expect_error(), cases(), main()

### Community 323 - "Community 323"
Cohesion: 0.57
Nodes (7): check(), tree(), parse_error(), cases(), randomized_input(), stress(), main()

### Community 422 - "Community 422"
Cohesion: 0.70
Nodes (4): check(), fin(), cases(), main()

### Community 423 - "Community 423"
Cohesion: 0.70
Nodes (4): ok(), error(), cases(), main()

### Community 325 - "Community 325"
Cohesion: 0.54
Nodes (7): check(), has(), i32(), v(), valid_module(), cases(), main()

### Community 466 - "Community 466"
Cohesion: 1.00
Nodes (2): checksum(), main()

### Community 326 - "Community 326"
Cohesion: 0.57
Nodes (7): check(), dump(), error(), cases(), depth_guard(), randomized_input(), main()

### Community 243 - "Community 243"
Cohesion: 0.45
Nodes (10): check(), i32t(), lexer_limits(), program_limits(), bytecode_limits(), values_limits(), scheduler_limits(), package_limits() (+2 more)

### Community 244 - "Community 244"
Cohesion: 0.29
Nodes (1): TraceTests

### Community 424 - "Community 424"
Cohesion: 0.70
Nodes (4): check(), unwrap(), cases(), main()

### Community 349 - "Community 349"
Cohesion: 0.52
Nodes (5): _read(), load_corpus(), load_trace(), compare(), main()

### Community 393 - "Community 393"
Cohesion: 0.50
Nodes (3): is_protected_domain(), load_pkb_schema(), PkbAuthority

### Community 246 - "Community 246"
Cohesion: 0.36
Nodes (7): ReplayRing, cbor_head(), cbor_uint(), cbor_text(), cbor_bool(), emit_litlen(), encode_replay()

### Community 428 - "Community 428"
Cohesion: 0.50
Nodes (2): RuleParser, RuleEvaluator

### Community 462 - "Community 462"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 454 - "Community 454"
Cohesion: 0.83
Nodes (3): check(), same_generic(), main()

### Community 420 - "Community 420"
Cohesion: 0.70
Nodes (4): check(), same_event(), same_tick(), main()

### Community 465 - "Community 465"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 108 - "Community 108"
Cohesion: 0.10
Nodes (6): DeviceBindingService, AccountStore, InMemoryAccountStore, SignInService, StepUpService, 981b52c Crated IDN-01 to IDN-04

### Community 332 - "Community 332"
Cohesion: 0.29
Nodes (2): FirebaseTokenVerifier, SessionTickets

### Community 464 - "Community 464"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 327 - "Community 327"
Cohesion: 0.43
Nodes (6): check(), sign_input(), make_token(), test_key(), sample_ticket(), main()

### Community 397 - "Community 397"
Cohesion: 0.40
Nodes (2): TicketSigner, Matchmaker

### Community 451 - "Community 451"
Cohesion: 0.83
Nodes (3): check(), ready_platform(), main()

### Community 414 - "Community 414"
Cohesion: 0.70
Nodes (4): check(), req(), key(), main()

### Community 453 - "Community 453"
Cohesion: 0.83
Nodes (3): check(), req(), main()

### Community 461 - "Community 461"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 463 - "Community 463"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 455 - "Community 455"
Cohesion: 0.83
Nodes (3): check(), mk(), main()

### Community 467 - "Community 467"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 334 - "Community 334"
Cohesion: 0.29
Nodes (1): BitBuffer

### Community 209 - "Community 209"
Cohesion: 0.45
Nodes (11): rotl32(), load32_le(), store32_le(), store64_le(), qr(), chacha20_block(), chacha20_xor(), poly1305_mac() (+3 more)

### Community 307 - "Community 307"
Cohesion: 0.39
Nodes (6): Sha256, hmac_sha256(), constant_time_equal(), payload_bit_length(), pack_frame(), unpack_frame()

### Community 335 - "Community 335"
Cohesion: 0.43
Nodes (5): xor_payloads(), losses(), attach_parity(), recover_loss(), make_parity()

### Community 203 - "Community 203"
Cohesion: 0.37
Nodes (12): now(), write_log(), run_command(), normalize_lf(), sha256(), msvc_tools(), android_tools(), windows_leg() (+4 more)

### Community 371 - "Community 371"
Cohesion: 0.47
Nodes (5): first_difference(), update_golden(), main(), Return the first differing offset and sizes, or None if files match., Replace the reference atomically, only on an explicit update request.

### Community 178 - "Community 178"
Cohesion: 0.25
Nodes (2): run(), GoldenHarnessTests

## Knowledge Gaps
- **1013 isolated node(s):** `Parametric human blockout from measured sheet fractions.  Every dimension is a f`, `Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry.`, `Print measured bounds so the comparison step has numbers, not vibes.`, `Explorer character — pass 2: garments, equipment, hair, materials.  Reads the me`, `Duplicate meshes then scale about a pivot — cheap garment offset.` (+1008 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **Thin community `Community 239`** (2 nodes): `_write_ablation()`, `test_ablation_verdicts()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 262`** (2 nodes): `trophy()`, `finish hero: 1-2-3 podium + a giant cylinder-built trophy (base, stem, flared cu`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 468`** (2 nodes): `r2b()`, `light()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 445`** (2 nodes): `pill()`, `pair()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 315`** (2 nodes): `flat()`, `ground()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 472`** (2 nodes): `ribbon()`, `a flat strip on the ground following pts (x, y, z); widths per point`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 473`** (2 nodes): `strip_surface()`, `a surface between a front curve z = zf(x) and a back curve zb(x) (quad strip ove`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 392`** (2 nodes): `MYTOOL_OT_offset_selected`, `Move selected objects along an axis`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 359`** (2 nodes): `MYTOOL_PT_main`, `MYTOOL_AP_preferences`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 443`** (2 nodes): `find_blender()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 409`** (2 nodes): `_trees()`, `test_scatter_respects_slope_height_and_realize()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 410`** (2 nodes): `_reimport_dims()`, `test_all_presets_roundtrip_scale()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 449`** (2 nodes): `_img()`, `test_texture_set_autowire_orm_dx_normal()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 79`** (1 nodes): `Layer compiler, Core round trips, texture processing, recipe primitives and the`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 450`** (2 nodes): `_camera()`, `test_render_stills_cycles_eevee_workbench()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 383`** (2 nodes): `_instances()`, `test_precipitation_loops_and_stops_on_ground()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 290`** (2 nodes): `test_load_mesh_no_pyrender_import()`, `mesh_io must not pull in pyrender (it's the whole point of the split).`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 430`** (2 nodes): `Discover editable leaf paths without walking parent/tree references.`, `Discover parameters grouped as they are in the editor's setting panels.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 429`** (2 nodes): `assert`, `{
  browserLauncherForPlatform
}`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 360`** (2 nodes): `smooth()`, `interp()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 457`** (2 nodes): `floats()`, `capture()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 469`** (1 nodes): `Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).  Run:`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 470`** (1 nodes): `Adapt BoyR6 for PokoX.  Fixes:   1. Head shading: collapse the dead customFaces`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 471`** (1 nodes): `Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 328`** (1 nodes): `OverlapTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 333`** (1 nodes): `ReservationMigrationTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 394`** (1 nodes): `DurationQueryState`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 460`** (2 nodes): `near()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 306`** (2 nodes): `decode()`, `GoldenEncoderTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 373`** (2 nodes): `AssetHandle`, `AssetStore`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 458`** (2 nodes): `counting_loader()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 364`** (2 nodes): `VulkanDiagnostics`, `VulkanImGuiPass()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 180`** (1 nodes): `EvidenceTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 432`** (2 nodes): `DeclarationParser`, `DeclarationAst`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 399`** (2 nodes): `ExpressionParser`, `Ast`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 433`** (2 nodes): `StatementParser`, `StatementAst`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 271`** (2 nodes): `mix()`, `hash()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 459`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 466`** (2 nodes): `checksum()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 244`** (1 nodes): `TraceTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 428`** (2 nodes): `RuleParser`, `RuleEvaluator`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 462`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 465`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 332`** (2 nodes): `FirebaseTokenVerifier`, `SessionTickets`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 464`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 397`** (2 nodes): `TicketSigner`, `Matchmaker`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 461`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 463`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 467`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 334`** (1 nodes): `BitBuffer`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 178`** (2 nodes): `run()`, `GoldenHarnessTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `Palette` connect `Community 2` to `Community 135`, `Community 136`, `Community 161`, `Community 278`, `Community 137`, `Community 160`, `Community 298`, `Community 297`, `Community 15`, `Community 21`, `Community 3`, `Community 117`, `Community 223`, `Community 124`, `Community 123`, `Community 146`, `Community 224`, `Community 184`, `Community 206`, `Community 300`, `Community 172`, `Community 195`, `Community 280`, `Community 125`, `Community 254`, `Community 118`, `Community 196`, `Community 126`, `Community 253`, `Community 78`, `Community 301`, `Community 302`, `Community 185`, `Community 12`, `Community 29`, `Community 256`, `Community 212`, `Community 211`, `Community 228`, `Community 210`, `Community 128`, `Community 283`, `Community 149`, `Community 139`, `Community 129`, `Community 173`, `Community 198`, `Community 229`, `Community 261`, `Community 42`, `Community 177`, `Community 311`, `Community 31`, `Community 23`, `Community 40`, `Community 5`, `Community 11`, `Community 56`?**
  _High betweenness centrality (0.142) - this node is a cross-community bridge._
- **Why does `MB` connect `Community 14` to `Community 25`, `Community 24`, `Community 456`, `Community 20`, `Community 32`, `Community 26`, `Community 54`, `Community 19`, `Community 67`, `Community 33`, `Community 27`, `Community 35`, `Community 22`, `Community 97`, `Community 214`, `Community 177`, `Community 311`, `Community 440`, `Community 38`, `Community 151`, `Community 28`, `Community 7`, `Community 41`, `Community 103`, `Community 62`, `Community 12`, `Community 2`?**
  _High betweenness centrality (0.048) - this node is a cross-community bridge._
- **Why does `EffectSession` connect `Community 34` to `Community 194`, `Community 147`, `Community 72`, `Community 1`, `Community 430`?**
  _High betweenness centrality (0.013) - this node is a cross-community bridge._
- **Are the 622 inferred relationships involving `Palette` (e.g. with `cotton-candy tree: twisting pretzel trunk with 3 limbs, each holding a fluffy ma` and `3-5 sugar-coated gumdrops of different colours clustered on the ground (true gum`) actually correct?**
  _`Palette` has 622 INFERRED edges - model-reasoned connections that need verification._
- **What connects `Parametric human blockout from measured sheet fractions.  Every dimension is a f`, `Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry.`, `Print measured bounds so the comparison step has numbers, not vibes.` to the rest of the system?**
  _1013 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 152` be split into smaller, more focused modules?**
  _Cohesion score 0.11764705882352941 - nodes in this community are weakly interconnected._
- **Should `Community 96` be split into smaller, more focused modules?**
  _Cohesion score 0.11688311688311688 - nodes in this community are weakly interconnected._