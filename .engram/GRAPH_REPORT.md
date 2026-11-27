# Graph Report - .  (2026-11-27)

## Corpus Check
- Large corpus: 6523 files · ~7,840,840 words. Semantic extraction will be expensive (many Claude tokens). Consider running on a subfolder, or use --no-semantic to run AST-only.

## Summary
- 8276 nodes · 15723 edges · 439 communities detected
- Extraction: 94% EXTRACTED · 6% INFERRED · 0% AMBIGUOUS · INFERRED: 980 edges (avg confidence: 0.5)
- Token cost: 0 input · 0 output
- Edge kinds: calls: 5849 · contains: 5345 · rationale_for: 1741 · MODIFIES: 1241 · uses: 980 · method: 365 · PARENT_OF: 79 · ON_BRANCH: 71 · inherits: 21 · imports_from: 17 · imports: 7 · references: 4 · implements: 2 · cites: 1


## Input Scope
- Requested: auto
- Resolved: committed (source: default-auto)
- Included files: 6523 · Candidates: 9611
- Excluded: 4 untracked · 2304 ignored · 23 sensitive · 15 missing committed
- Recommendation: Use --scope all or graphify.yaml inputs.corpus for a knowledge-base folder.

## Graph Freshness
- Built from Git commit: `6568dc9`
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

### Community 0 - "Community 0"
Cohesion: 0.01
Nodes (28): Quarter-frame ground and stance-target diagnostics for editable rigs., capture(), floats(), Checks sampled positions after reopening each clip. Does not certify artistry., c7a411f Fix MUT-01-20 audit defects in Mute parsers, RefCntAutoPtr, LogGuard, FrameStats (+20 more)

### Community 1 - "Community 1"
Cohesion: 0.02
Nodes (35): My Tool - Blender extension template (4.2+ extension format, verified on 5.3)., MYTOOL_PG_settings, Post pass for kraken.py (self-contained: copy kraken.py + kraken_post.py togethe, convert(), main(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs to .agents/skills, _hex() (+27 more)

### Community 2 - "Community 2"
Cohesion: 0.02
Nodes (165): lens-shaped leaf: length L along direction a (deg from +up, clockwise = +x), hal, rounded park tree: flared birch trunk splitting into two boughs, three-lobed chu, rounded bush with a few flower clusters (5-petal stars) on its top, long planter box (white with a teal kick + cream coping) with a row of clipped r, plaza lamp: round foot, slim white post with a mint collar, curved arm, glass la, the Bloom Paw: rounded paw pad (soft heart-ish blob) + three leaf toes fanned ab, indoor potted tree: tall white pot with a coloured band and foot, slim trunk, tw, berry-juice vending machine: rounded white cabinet, coloured side panels, glass (+157 more)

### Community 3 - "Community 3"
Cohesion: 0.04
Nodes (154): adeg(), arc_wall(), art_frame(), ball(), ball_lineup(), _ball_sh(), berry_baskets(), blossom_park() (+146 more)

### Community 4 - "Community 4"
Cohesion: 0.02
Nodes (117): VFX_Dark_Vortex: Dark impact played where VFX_Projectile_Dark arrives: a black h, VFX_Fire_Explosion: Fire impact played where VFX_Projectile_Fire arrives.  Examp, VFX_Heal: Heal on the caster: no impact frame, a slow upward rise.  Example from, VFX_Hit_Heavy: Heavy melee hit: the blow lands on the target in place.  Example, VFX_Ice_Spikes: Ground ice eruption played where VFX_Projectile_Ice arrives.  Ex, VFX_Kaiju_Atomic_Beam: a sustained atomic breath that the game aims and sweeps (, VFX_Kaiju_Atomic_Charge: dorsal plates light up from the tail to the head before, VFX_Kaiju_Explosion: a photographic, building-sized fuel explosion for a kaiju b (+109 more)

### Community 5 - "Community 5"
Cohesion: 0.05
Nodes (92): bark(), barrel(), basket(), blossom_tree(), boulder(), broadleaf(), bush(), canopy() (+84 more)

### Community 6 - "Community 6"
Cohesion: 0.03
Nodes (45): 13dbd75 Refresh graph after MUT-25 SSA IR, 335e0dc Add MUT-26 IR-to-bytecode emitter, 45151c3 Refresh graph after MUT-26 emitter, 85b7130 Close MUT-26 limits: AST-to-SSA lowering and load_imm literals, 952997e Audit MUT-01-55 and harden verification scripts, fd66d0d Add MUT-25 typed SSA IR and verifier, FixedStepLoop, Exercise the real host compiler and CMake shader rule in an isolated build. (+37 more)

### Community 7 - "Community 7"
Cohesion: 0.09
Nodes (86): add_into(), ammo_pile(), ash_sh(), ashlar(), ashlar_ring(), bar(), barrel(), battering_ram() (+78 more)

### Community 8 - "Community 8"
Cohesion: 0.06
Nodes (83): anchor(), beach(), build(), build_profile(), build_solid(), cliff_clear(), cliff_mesh(), cliffs() (+75 more)

### Community 9 - "Community 9"
Cohesion: 0.05
Nodes (53): bark_birch(), bark_fir(), bark_oak(), bark_palm(), Branch, Canvas, card_quads(), conifer_cards() (+45 more)

### Community 10 - "Community 10"
Cohesion: 0.05
Nodes (54): main, 037434c Add MUT-24 determinism and capability analysis, 038387e Character controller: value-keyed touch memo for the cast path, 0621f1d Merge pull request #1 from Raft-The-Crab/fix/review-2026-11-26, 06cfbe9 Narrowphase: local pair frame + exact 64-bit FixedVec3 math, 080a665 Refresh graph after MUT-21 package resolver, 0ab64e5 Refresh graph after lowering assignments/phis, 0be87b9 Merge pull request #4 from Raft-The-Crab/feat/character-touch-memo (+46 more)

### Community 11 - "Community 11"
Cohesion: 0.07
Nodes (70): annulus(), arena_rim(), brazier(), chamfer_box(), crystal_chips(), crystal_cluster(), crystal_lantern(), disc() (+62 more)

### Community 12 - "Community 12"
Cohesion: 0.09
Nodes (58): cabin(), fishing_hut(), frost_spire(), village-square roll well: stone ring, timber A-frame + roof, rope + bucket, glow, ice-fishing shanty: board walls on skids, door + window, stovepipe, ridge-capped, hero: stone terrace + a 60-stud ice crystal spire with orbiting shards and a run, grove pine re-shaded: every up-facing tier face carries snow, log cabin: stacked logs with crossed corners, the door gap is left IN the log co (+50 more)

### Community 13 - "Community 13"
Cohesion: 0.05
Nodes (41): 69287a0 Land ENG-60-65 deterministic sim physics, character controller, and visual/soft-body path, 87beff4 Sim solver: reject self/duplicate contacts, derive mass, clamp integration, 9eeb3ff Merge pull request #2 from Raft-The-Crab/fix/review-2026-11-26, ConvexShape, SapBroadphase, ClothGrid, SoftBody, SequentialImpulseSolver (+33 more)

### Community 14 - "Community 14"
Cohesion: 0.06
Nodes (45): bark_birch(), bark_fir(), bark_oak(), Branch, Canvas, card_quads(), conifer_cards(), contact_sheet() (+37 more)

### Community 15 - "Community 15"
Cohesion: 0.04
Nodes (60): floor height: gentle cave earth, lake bed carved in, islet raised, nothing in th, solid props at once; soft ones (foliage / fungi / vines) deferred and placed aga, copy a prop part (Roblox-space MB) to its world placement (pieces built into sta, walkable floor heightfield (3 studs) everywhere under the air + 6 studs into the, layered rock masses along every wall foot (big in the hall, small in tunnels), h, stalactites over the whole vault (never low over paths), flowstone curtains near, geodes at chosen spots (glow by district: amber by the camp + forge, cyan round, story clusters on the open hall floor (no dead space between light pools): a min (+52 more)

### Community 16 - "Community 16"
Cohesion: 0.05
Nodes (61): agave(), boulder(), brass_lantern(), brazier(), carved_stair(), cloth_sheet(), crate(), dais() (+53 more)

### Community 17 - "Community 17"
Cohesion: 0.05
Nodes (45): assault_rifle(), branch(), bush(), crimson_blade(), grass_base(), gym(), leaf_col(), oak() (+37 more)

### Community 18 - "Community 18"
Cohesion: 0.04
Nodes (26): 1dac49d Created NET-01 to NET-09, Started BAK-01, LoginVelocityService, assets, games, users, balances, games, ledger_entries (+18 more)

### Community 19 - "Community 19"
Cohesion: 0.09
Nodes (54): add_owner(), anchor(), arc_with_gaps(), bay_key(), beam(), build(), compass(), deck_rect() (+46 more)

### Community 20 - "Community 20"
Cohesion: 0.14
Nodes (54): anchor(), build(), build_solid(), bvh_of(), ceil_y(), clip_fail(), clusters(), crust() (+46 more)

### Community 21 - "Community 21"
Cohesion: 0.07
Nodes (51): add_crystal(), cap_shape(), crystal(), crystal_shards(), crystal_spray(), dot(), drip_profile(), flowstone_curtain() (+43 more)

### Community 22 - "Community 22"
Cohesion: 0.13
Nodes (53): anchor(), breakables(), build(), build_solid(), candy(), catmull(), clip_fail(), crystal() (+45 more)

### Community 23 - "Community 23"
Cohesion: 0.06
Nodes (49): buy_button(), candy_lamp(), candy_sacks(), cash_pad(), choc_bench(), choc_fountain(), coin_chute(), collector() (+41 more)

### Community 24 - "Community 24"
Cohesion: 0.09
Nodes (48): build(), cx(), dcx(), edge_rhythm(), foot(), free(), ground(), H() (+40 more)

### Community 25 - "Community 25"
Cohesion: 0.08
Nodes (48): add_owner(), anchor(), axis_coords(), build(), bump(), castle_h(), dist_castle(), drape_strip() (+40 more)

### Community 26 - "Community 26"
Cohesion: 0.09
Nodes (48): add_owner(), anchor(), build(), build_solid(), clip_fail(), dig_spots(), dunes(), face() (+40 more)

### Community 27 - "Community 27"
Cohesion: 0.10
Nodes (46): adiff(), build(), crater_at(), _crater_ok(), crater_ramp(), craters(), face(), foot() (+38 more)

### Community 28 - "Community 28"
Cohesion: 0.10
Nodes (45): alley(), anchor(), anchor_local(), bkit(), blocks(), build(), buildings(), check_rects() (+37 more)

### Community 29 - "Community 29"
Cohesion: 0.11
Nodes (43): airlock_gate(), beacon_post(), beacon_rail(), beam(), comms_dish(), crater(), dish(), dust_exchange() (+35 more)

### Community 30 - "Community 30"
Cohesion: 0.07
Nodes (46): _build_app_plugin_alias_pattern(), _candidate_project_roots(), determine_primary_identity(), extract_dotnet_android_details(), extract_manifest_details(), _filter_by_flavor(), generate_triage_summary(), load_app_plugin_aliases() (+38 more)

### Community 31 - "Community 31"
Cohesion: 0.07
Nodes (39): bridge(), bush(), cactus(), chest(), cloud(), coin_pile(), crystal_node(), egg_shrine() (+31 more)

### Community 32 - "Community 32"
Cohesion: 0.10
Nodes (42): anchor(), build(), catmull(), ceil_y(), exterior(), face_in(), foot(), free() (+34 more)

### Community 33 - "Community 33"
Cohesion: 0.11
Nodes (42): base(), build(), centre(), channels(), courtyard(), cull_hidden(), face(), field() (+34 more)

### Community 34 - "Community 34"
Cohesion: 0.07
Nodes (17): EffectSession, Read a public Core member without invoking arbitrary methods., Write an editable Core value or a public writable property., A handle to the single Core document hosted by this Python process., Set a batch of panel-relative editable fields., Read a scalar curve as JSON-friendly keyframe data., Replace scalar FCurve keys using Core's add/remove commands., Copy an image beside the effect and optionally bind its Core path. (+9 more)

### Community 35 - "Community 35"
Cohesion: 0.10
Nodes (39): add_owner(), bank_path(), build(), fit(), fit_bad(), free(), ground(), H() (+31 more)

### Community 36 - "Community 36"
Cohesion: 0.08
Nodes (40): background_fit_mask(), band_errors(), band_widths(), bbox_report(), _conv_sep(), evaluate(), _fit_size(), flood_background_mask() (+32 more)

### Community 37 - "Community 37"
Cohesion: 0.06
Nodes (25): at(), base_of(), big_part(), cast(), clean_name(), collision_of(), export(), _face_rgb() (+17 more)

### Community 38 - "Community 38"
Cohesion: 0.14
Nodes (37): bridge_ends(), build(), ext(), face(), foot(), free(), H(), Hm() (+29 more)

### Community 39 - "Community 39"
Cohesion: 0.07
Nodes (21): det_lerp(), det_sqrt(), next_i32(), next_u64(), quat_normalize(), quat_rotate(), splitmix64(), vec2_dot() (+13 more)

### Community 40 - "Community 40"
Cohesion: 0.12
Nodes (37): ac_unit(), add(), antenna(), awning_band(), ball(), blob(), building(), deco_window() (+29 more)

### Community 41 - "Community 41"
Cohesion: 0.13
Nodes (38): anchor(), ang(), bridges(), build(), build_paths(), clip_frac(), dressing(), edge_pt() (+30 more)

### Community 42 - "Community 42"
Cohesion: 0.05
Nodes (8): big_arch(), lamp_pillar(), the stacked-cube lamp pillar from the reference game, two lamp pillars at the track edges, a top beam with a sign board (name / price, START / FINISH arch: two chunky towers, a deep beam with a black/white checker b, finish hero: 1-2-3 podium with a giant blocky trophy on the top step, trophy(), zone_gate()

### Community 43 - "Community 43"
Cohesion: 0.10
Nodes (28): B(), build(), cap(), chain(), chest_z(), crack(), dil(), dspike() (+20 more)

### Community 44 - "Community 44"
Cohesion: 0.07
Nodes (23): Exception, cube_indices(), cube_vertices(), main(), build_demo_window(), composite(), ensure_gpu_timer(), feed_imgui_event() (+15 more)

### Community 45 - "Community 45"
Cohesion: 0.07
Nodes (15): conflict_setup(), game(), The skill never damages a project it was pointed at by mistake: no workspace sid, test_a_broken_source_only_blocks_itself(), test_a_build_mirrors_only_its_own_resources(), test_a_build_never_replaces_a_resource_another_built_effect_uses(), test_a_full_build_of_an_empty_library_refuses_before_touching_anything(), test_a_full_build_prunes_only_effects_it_built() (+7 more)

### Community 46 - "Community 46"
Cohesion: 0.11
Nodes (32): barrels(), blob(), cart_load(), crates(), logp(), mine_cart(), mine_frame(), mine_lantern_post() (+24 more)

### Community 47 - "Community 47"
Cohesion: 0.07
Nodes (33): boards(), brew_station(), camp_tent(), campfire_pit(), cave_falls(), crystal_forge(), deep_lift(), glow_puddle() (+25 more)

### Community 48 - "Community 48"
Cohesion: 0.13
Nodes (32): add_binding(), bindings(), bindings_conflict(), clamp_i32(), clear_bindings(), conflicts(), contains(), decode() (+24 more)

### Community 49 - "Community 49"
Cohesion: 0.11
Nodes (33): _decode(), _eval(), _ffmpeg(), first_frame(), flipbook(), grade(), _in_project(), _key() (+25 more)

### Community 50 - "Community 50"
Cohesion: 0.09
Nodes (21): compile_template(), EachNode, get_nested_val(), IfNode, Node, _ParserFrame, Represents standard iteration logic {{#EACH}} over lists/dicts., Helper to render nested children under a specific loop context. (+13 more)

### Community 51 - "Community 51"
Cohesion: 0.10
Nodes (24): B(), back_layer(), band_edge(), build(), cap(), chain(), ci(), cube_dil() (+16 more)

### Community 52 - "Community 52"
Cohesion: 0.09
Nodes (14): _compound(), _fused(), GridfinityBin, Collect the solids of several workplanes/solids into one Compound.      Booleans, Combine cutter workplanes into one safe boolean tool.      Disjoint cutters ride, Builder for a spec-compatible Gridfinity bin.      Create the bin, add features,, Z of the interior floor: base profile plus solid floor., Deepest cavity possible from the top of the bin. (+6 more)

### Community 53 - "Community 53"
Cohesion: 0.09
Nodes (15): 0d85dce Merge pull request #6 from Raft-The-Crab/mut-42-hostcalls, 1aefb72 MUT-42: physics hostcall boundary (header), 5106553 MUT-42: physics hostcall implementation, 72b9ac7 Merge branch 'main' into mini-code/b4d7e813-e93, 78dbd1e Merge pull request #7 from Raft-The-Crab/mut-42-followup, 7eabc2d Merge pull request #8 from Raft-The-Crab/mini-code/b4d7e813-e93, 981b52c Crated IDN-01 to IDN-04, DeviceBindingService (+7 more)

### Community 54 - "Community 54"
Cohesion: 0.10
Nodes (21): axd(), B(), build(), bx(), capd(), chain(), chaind(), exposed() (+13 more)

### Community 55 - "Community 55"
Cohesion: 0.14
Nodes (28): anchor(), build(), dressing(), foot(), free(), ground(), H(), hardscape() (+20 more)

### Community 56 - "Community 56"
Cohesion: 0.15
Nodes (30): capture(), concept_compare(), criteria(), _frame_number(), gate_path(), handoff(), issues(), _lab_capture() (+22 more)

### Community 57 - "Community 57"
Cohesion: 0.09
Nodes (25): B(), CY(), drop_bottom(), glowbox(), ibeam(), lathe(), pol(), prism_x() (+17 more)

### Community 58 - "Community 58"
Cohesion: 0.09
Nodes (26): apply(), box(), cyl(), _emit(), frame(), limb(), lin(), make() (+18 more)

### Community 59 - "Community 59"
Cohesion: 0.16
Nodes (25): append(), apply(), at(), decode(), encode(), gamepad_axis_value(), gamepad_button_down(), gamepad_connected() (+17 more)

### Community 60 - "Community 60"
Cohesion: 0.07
Nodes (27): add_common(), argv(), cli(), emit(), enum_ids(), mesh_tris(), node(), object_mode() (+19 more)

### Community 61 - "Community 61"
Cohesion: 0.07
Nodes (27): add_common(), argv(), cli(), emit(), enum_ids(), mesh_tris(), node(), object_mode() (+19 more)

### Community 62 - "Community 62"
Cohesion: 0.07
Nodes (26): bench(), dumpster(), flower_bed(), hydrant(), litter_bin(), pallets(), planter(), municipal bin: base, ribbed teal body, yellow band, dome lid with a dark mouth (+18 more)

### Community 63 - "Community 63"
Cohesion: 0.14
Nodes (25): build(), CAMP_PTS(), face(), foot(), free(), ground(), H(), horizon() (+17 more)

### Community 64 - "Community 64"
Cohesion: 0.10
Nodes (14): B(), build(), cap(), chain(), exposed(), flame(), lin(), put() (+6 more)

### Community 65 - "Community 65"
Cohesion: 0.09
Nodes (27): basalt_rocks(), bottle(), cactus(), chest(), coin(), coin_pile(), crystal_node(), egg_shrine() (+19 more)

### Community 66 - "Community 66"
Cohesion: 0.10
Nodes (15): 60d8044 Mute crypto hostcalls: fail explicitly instead of returning 0, 9b77990 Android GLES probe: no data race or dangling capture in the Vulkan worker, android_main(), run_frames(), write_result(), HostcallTable, append_u32_be(), compress() (+7 more)

### Community 67 - "Community 67"
Cohesion: 0.15
Nodes (22): build(), _drift(), face(), foot(), free(), front_to(), ground(), H() (+14 more)

### Community 68 - "Community 68"
Cohesion: 0.11
Nodes (13): _assert_footprint(), _mesh(), Rebuild the published D110 cradle; dimensions must match., B-rep volume, no tessellation round-trip., 1x1, 2U, no lip: exact box height, flat top., 2x1, 3U with lip and base holes., test_bin_with_lip_magnets_screws(), test_compartments_scoop_label() (+5 more)

### Community 69 - "Community 69"
Cohesion: 0.11
Nodes (26): beam_pair(), carton(), drum_bm(), floor_pallet(), load_cartons(), load_crates(), load_drums(), load_sacks() (+18 more)

### Community 70 - "Community 70"
Cohesion: 0.11
Nodes (16): B(), build(), cap(), cell(), chain(), exposed(), front_z(), ix() (+8 more)

### Community 71 - "Community 71"
Cohesion: 0.13
Nodes (25): _add_edges(), _build_grid(), _build_scene(), _get_font(), _info_lines(), main(), _nice_spacing(), Create a pyrender scene containing the mesh, lights, and optionally ground. (+17 more)

### Community 72 - "Community 72"
Cohesion: 0.13
Nodes (22): build_parser(), _curve_list(), _curve_set(), _emit(), _export(), _image_import(), main(), _node_add() (+14 more)

### Community 73 - "Community 73"
Cohesion: 0.14
Nodes (9): _fire_pre_llm(), _load_plugin(), Copy the plugin module + a minimal skills tree in the given layout., Hermes builds its skill catalogue from register_skill(description=...),     whic, Re-import plugin module fresh., TestBootstrapInjection, TestLayoutResolution, TestPluginRegistration (+1 more)

### Community 74 - "Community 74"
Cohesion: 0.14
Nodes (21): assert, assertBrandedFallbackText(), assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap(), assertLogoKeepsTransparentBackground(), assertTelemetryImage() (+13 more)

### Community 75 - "Community 75"
Cohesion: 0.10
Nodes (11): arm(), B(), build(), chain(), chain_t(), exposed(), fdir(), lin() (+3 more)

### Community 76 - "Community 76"
Cohesion: 0.11
Nodes (12): B(), build(), chain(), exposed(), lin(), put(), render_all(), sd_cap() (+4 more)

### Community 77 - "Community 77"
Cohesion: 0.24
Nodes (20): evaluate_arithmetic(), fail(), float_binary(), FloatEnvironment, integer_suffix(), is_float(), is_unsigned(), literal_float() (+12 more)

### Community 78 - "Community 78"
Cohesion: 0.11
Nodes (24): boat_house(), hook_icon(), hut_body(), lash(), plank_floor(), pole(), deck platform: planks along `along` with gaps, a dark skirt beam round it, bamboo torch: pole with nodes, lashings, woven cup, two-tongue flame. stilt > 0 (+16 more)

### Community 79 - "Community 79"
Cohesion: 0.08
Nodes (1): Layer compiler, Core round trips, texture processing, recipe primitives and the

### Community 81 - "Community 81"
Cohesion: 0.09
Nodes (22): charger_unit(), conveyor(), fire_point(), ibc_tote(), mesh_stillage(), mezzanine(), packing_bench(), rail_run() (+14 more)

### Community 82 - "Community 82"
Cohesion: 0.13
Nodes (20): assert, assertStartedOnExpectedPort(), cleanup(), CONTENT_DIR, ensureSymlinkWorks(), fs, http, path (+12 more)

### Community 83 - "Community 83"
Cohesion: 0.12
Nodes (13): B(), body_to_world(), build(), exposed(), fang(), lid_to_body(), lid_to_world(), lin() (+5 more)

### Community 84 - "Community 84"
Cohesion: 0.15
Nodes (19): B(), box(), build(), cap(), chain(), exposed(), leg(), lin() (+11 more)

### Community 85 - "Community 85"
Cohesion: 0.13
Nodes (16): B(), build(), cap(), chain(), colmax(), edge(), exposed(), hide() (+8 more)

### Community 86 - "Community 86"
Cohesion: 0.12
Nodes (14): B(), build(), cap(), cell(), exposed(), finger(), lin(), newid() (+6 more)

### Community 88 - "Community 88"
Cohesion: 0.19
Nodes (22): barrel(), bulbs_frame(), chamfer_block(), cyl_v(), framed_panel(), gable(), gift(), hatchery() (+14 more)

### Community 89 - "Community 89"
Cohesion: 0.14
Nodes (22): aggregate_findings(), clean_severity(), format_code_link(), load_json(), main(), parse_boolean(), parse_disclosure_status(), Safely converts boolean or sloppy string yes/no/true/false. (+14 more)

### Community 90 - "Community 90"
Cohesion: 0.11
Nodes (14): extract_data_safety(), extract_metadata(), fetch_html(), load_taxonomy(), PlayStoreDataSafetyParser, PlayStoreMetadataParser, Extracts visible text content from HTML structurally., Loads the valid data safety taxonomy from policies.json. (+6 more)

### Community 91 - "Community 91"
Cohesion: 0.19
Nodes (14): _apply_mat(), build_group(), _drive_light(), _G, _key_light(), _lin(), _line_art(), _outline_material() (+6 more)

### Community 92 - "Community 92"
Cohesion: 0.12
Nodes (12): Contracts specific to the self-contained skill package: CLI, workspace layout, r, Run the CLI with the test interpreter; returns (exit code, parsed JSON stdout)., system_python(), test_a_fresh_project_lints_a_recipe_that_uses_primitive_default_textures(), test_cli_init_examples_and_lint_in_a_fresh_project(), test_doctor_reports_an_initialised_workspace(), test_doctor_runs_through_the_wrapper_on_a_bare_system_python(), test_effect_verify_reports_missing_evidence_and_fails() (+4 more)

### Community 93 - "Community 93"
Cohesion: 0.22
Nodes (22): build_issues(), capture_issues(), context(), current_recipe(), dependencies(), inputs(), latest(), now() (+14 more)

### Community 94 - "Community 94"
Cohesion: 0.15
Nodes (22): _blob(), bottom_inset(), export(), _inner_gradient(), install(), _mask(), _periodic(), _polar() (+14 more)

### Community 95 - "Community 95"
Cohesion: 0.12
Nodes (14): build_explorer(), _fresh_col(), _mats(), Explorer character — pass 2: garments, equipment, hair.  Builds on the blockout., assign(), cylinder(), Dim, loft() (+6 more)

### Community 96 - "Community 96"
Cohesion: 0.13
Nodes (17): v4 stadium hub: striped infield inside an oval running track, stations face in f, stepped canyon: tier n is a row of 24-wide blocks with a 2-stud cap, each tier t, race kerb along Z: alternating colour/white blocks proud of the cap edge, wedge, running-track oval: red lane band, white inner/outer lines and 2 lane lines, put theme props on cap tops (centre of the 24-wide cap), skipping some for rhyth, SPEED SHOP: platform with a ramp, panelled counter, back wall with shelves of sp, REBIRTH portal: 8-sided stepped dais with rune ring, a standing ring portal (tan, wins pad: stepped round base with a gold rim, glowing ring and centre emblem, a (+9 more)

### Community 97 - "Community 97"
Cohesion: 0.17
Nodes (21): _clear(), _coll(), _fog(), _fog_box(), _grade(), _lerp_table(), _light(), lum() (+13 more)

### Community 98 - "Community 98"
Cohesion: 0.11
Nodes (16): blade(), bridge(), dry_shrub(), dune_grass(), grass_tuft(), mushrooms(), plaza_fountain(), one grass blade: thin tapered wedge (4 verts, 4 tris) leaning outward, tip bent (+8 more)

### Community 99 - "Community 99"
Cohesion: 0.20
Nodes (21): aabb_of(), centroid(), closest_on_hull(), closest_segment(), closest_triangle(), collide(), collide_local(), cso_support() (+13 more)

### Community 100 - "Community 100"
Cohesion: 0.13
Nodes (21): capture(), compare_sheet(), diff(), dump_metrics(), frame_state(), front_app(), metrics(), overview() (+13 more)

### Community 101 - "Community 101"
Cohesion: 0.14
Nodes (21): flame_band(), helix(), inspect(), inspect_all(), masks(), procedural(), Deterministic math primitives: glows, rings, tileable noise, trails, distortion, Band of flame tongues along U (tileable left-right): solid at the bottom, sharp (+13 more)

### Community 102 - "Community 102"
Cohesion: 0.17
Nodes (19): anchor(), build(), bx(), cull(), deck_y(), floors(), kit(), mesh_obj() (+11 more)

### Community 103 - "Community 103"
Cohesion: 0.12
Nodes (19): axle_set(), box_trailer(), dock_stair(), fence_panel(), truck wheel: deep-sidewall tyre with tread blocks, dished steel disc with 6 hand, cab-over tractor: high-roof raked cab with round front corners, wrap-round winds, 3D weld-mesh fence panel between two posts: vertical wires, double horizontals,, galvanised tapered column on a bolted base, outreach arm, two LED floodlight hea (+11 more)

### Community 104 - "Community 104"
Cohesion: 0.11
Nodes (11): is_protected_domain(), load_pkb_schema(), PkbAuthority, SessionAuthority, 6568dc9 Update from ML AI Code, 94d1546 Updated markdowns., TicketIssuanceGate, check() (+3 more)

### Community 105 - "Community 105"
Cohesion: 0.14
Nodes (18): assert, assertStartedOnExpectedPort(), cleanup(), CONTENT_DIR, EXPECTED_SECURITY_HEADERS, fs, http, path (+10 more)

### Community 106 - "Community 106"
Cohesion: 0.13
Nodes (12): B(), build(), cap(), catmull(), chain(), exposed(), ix(), lin() (+4 more)

### Community 107 - "Community 107"
Cohesion: 0.16
Nodes (16): B(), band(), build(), cap(), chain(), exposed(), eye(), hourglass() (+8 more)

### Community 108 - "Community 108"
Cohesion: 0.15
Nodes (15): 4cead55 Add MUT-27 bytecode verification and MUT-28 constant folding, eval_binary(), eval_compare(), eval_unary(), fold_constants(), int_scalar(), is_terminator(), verify() (+7 more)

### Community 109 - "Community 109"
Cohesion: 0.19
Nodes (12): _apply_mat(), build_group(), curvature_attribute(), _G, _image_node(), _lin(), Reversible "smart material" layers on existing Principled materials: edge wear (, TX_Curvature point attribute: 0.5 flat, -> 1 convex, -> 0 concave.      Mean ele (+4 more)

### Community 110 - "Community 110"
Cohesion: 0.11
Nodes (6): World scale, game-driven bind equations, beams, charge chains and soft particles, recipe_with(), test_beam_recipe_lints_with_hold_and_needs_a_release(), test_lint_counts_repeatedly_emitted_painted_shapes_as_restruck(), test_lint_scales_its_craft_limits_with_the_recipe(), test_scale_character_is_a_no_op_and_records_nothing()

### Community 111 - "Community 111"
Cohesion: 0.12
Nodes (14): clip(), fake_unity(), _footage(), _png(), Video-model flipbooks and the Unity pipeline, on a synthetic clip (a disc that g, Runs without a vfx/ workspace and prints only what a cp1252 Windows console can, 48 frames at 24 fps: black, a warm disc grows to the middle of the clip, then sh, 40 frames of a textured set seen by a dollying 35 mm camera (Workbench, textured (+6 more)

### Community 112 - "Community 112"
Cohesion: 0.14
Nodes (12): captured(), isolated(), Workflow contracts: no stale evidence, dropped key moments or unlabelled referen, Point the workspace-relative modules at an empty project (ROOT) and its work/ st, report(), test_build_and_render_reject_changed_sources_assets_outputs_and_templates(), test_completion_requires_brief_review_and_overview_instead_of_no_flags(), test_evidence_is_stored_in_the_workspace_work_folder() (+4 more)

### Community 114 - "Community 114"
Cohesion: 0.16
Nodes (20): colours(), compare_elements(), documented_textures(), features(), hot(), lint(), lint_library(), look() (+12 more)

### Community 115 - "Community 115"
Cohesion: 0.10
Nodes (20): crane_bridge(), crane_trolley(), dock_door(), high_bay(), personnel_door(), H-section column: base plate + anchor bolts + grout pad, cap plate, optional cra, single steel fire door with frame, vision panel, push bar, closer (wall prop, in, crane runway girder segment along x: I-beam 1.4 deep + square rail on top (rail (+12 more)

### Community 116 - "Community 116"
Cohesion: 0.15
Nodes (14): B(), ball(), build(), cap(), chain(), exposed(), joint(), lin() (+6 more)

### Community 117 - "Community 117"
Cohesion: 0.11
Nodes (20): block_wall(), column(), column_set(), grid_quad(), pylon_gate(), HERO / DUNGEON PORTAL: a columned temple front sunk 12 studs into the dunes, rea, raised zigzag band between two rails (centre c, length L along local x, facing -, wall of REAL bevelled blocks through the wall, running bond, broken top prof(x); (+12 more)

### Community 118 - "Community 118"
Cohesion: 0.11
Nodes (20): aquarium_dome(), brain_coral(), cooler(), coral_branch(), fish(), fish_index_wall(), fish_market(), AQUARIUM INDEX wall: plank backboard on teak posts, 3 x 4 oval plaques each with (+12 more)

### Community 119 - "Community 119"
Cohesion: 0.10
Nodes (14): checkpoint, childEvent, empty, freshRootEvent, newPromptAfterCheckpoint, originalChild, originalRetainedUserChild, pluginURL (+6 more)

### Community 120 - "Community 120"
Cohesion: 0.23
Nodes (11): _apply_mat(), build_group(), _G, Reversible weather layer on existing materials: wetness (porous darkening + wate, Color attribute ENV_Weather (R puddle, G snow, B wall/streak) for engine shaders, _remove_mat(), run(), _snow_material() (+3 more)

### Community 121 - "Community 121"
Cohesion: 0.17
Nodes (19): body_shader(), body_shell(), bus(), car(), _car_shell(), loft_closed(), city bus: lofted box body, raked windscreen, window band with pillars, two doors, carriage / cab section loft: rounded roof shoulders, raked nose at the front whe (+11 more)

### Community 122 - "Community 122"
Cohesion: 0.16
Nodes (11): 2960ac1 Android Vulkan clear: no fence deadlock on OUT_OF_DATE, bounded retry, initialize(), make_device_objects(), make_instance(), make_surface(), make_swapchain(), pick_device(), pick_surface_format() (+3 more)

### Community 123 - "Community 123"
Cohesion: 0.13
Nodes (19): camel(), dune_grass(), outcrop(), soft per-loop shade: height ramp + vertex-normal lift + low-frequency noise, stylised camel (smooth hide): ellipsoid body + single hump, S-curved neck, long, rest corner: a big patterned rug (border, field, medallion), three cushions, a b, sandstone outcrop: two or three wind-cut rock masses, layered (darker bands low,, tuft of tall pale dune grass: tapered folded blades arching out of a tight crown (+11 more)

### Community 124 - "Community 124"
Cohesion: 0.13
Nodes (19): colossus_head(), disc(), frustum(), quest_stele(), free-standing broken arch: block piers, round arch of voussoirs with a gold keys, path marker: weathered standing stone with a carved sun disc on its front, a gol, spawn: round three-step sandstone dais (r 13.4) with a gold sun mosaic (disc, 16, QUEST stand: tall carved tablet on the plinth with three BLANK recessed panels ( (+11 more)

### Community 125 - "Community 125"
Cohesion: 0.12
Nodes (19): bench(), conveyor_end(), conveyor_seg(), egg_shop(), gate_mat(), ranch_fence(), egg conveyor segment along -Z (z 0..-L): stone feet, honey side boards with an a, end cap block for the belt (roller drum + boards) (+11 more)

### Community 126 - "Community 126"
Cohesion: 0.12
Nodes (18): buoy_stack(), cloud(), closed rectangle loop with nx points on the X sides and nz_ on the Z sides, side, one layer of thatch: outer surface from ringA (eave, fringed) up to ringB, a thi, pale coral-stone rock: lumpy main mass, a second lump, barnacle bumps, dark wet, raised binding / hoop round a vertical pole of radius r, flat-bottomed cumulus for the horizon (SmoothPlastic white), trap floats and a coiled rope: stacked red/yellow/white buoys (+10 more)

### Community 127 - "Community 127"
Cohesion: 0.30
Nodes (18): head(), main(), put_arr(), put_b(), put_bool(), put_double(), put_float(), put_half() (+10 more)

### Community 128 - "Community 128"
Cohesion: 0.11
Nodes (14): bench(), crates(), fern_tuft(), koi_pond(), planter(), small round stone pond: dressed rim, water, three koi, lily pads, a moss boulder, stone trough planter (hollow, soil inside) with cloud-pruned sage shrubs and a f, stone stair: bevelled sand treads with tone variation and a nosing shadow, ashla (+6 more)

### Community 129 - "Community 129"
Cohesion: 0.11
Nodes (19): cloud(), crystal_clump(), crystal_spire(), mascot_test(), pet_statue(), picnic_set(), puff(), puffpaw() (+11 more)

### Community 130 - "Community 130"
Cohesion: 0.22
Nodes (18): egg_hatchery(), egg_rows(), hoarding(), kerb_lip(), medal_pad(), medal_rows(), pixel_art(), plinth() (+10 more)

### Community 131 - "Community 131"
Cohesion: 0.15
Nodes (11): frames(), Agent feedback loop: field validation, static lint, review metrics, iteration hi, plan: {frame: [(box, colour), ...]} with boxes relative to the review crop., recipe(), test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape(), test_lint_passes_the_library_and_reports_each_hard_rule(), test_lint_warns_about_craft_problems(), test_review_metrics_accept_a_well_formed_effect() (+3 more)

### Community 132 - "Community 132"
Cohesion: 0.20
Nodes (17): area(), atlas(), axes_of(), block(), clip(), edge(), hash2(), _hex() (+9 more)

### Community 133 - "Community 133"
Cohesion: 0.26
Nodes (17): alloc(), as_string(), copy(), copy_impl(), free_slot(), get_index(), handle_for(), length() (+9 more)

### Community 134 - "Community 134"
Cohesion: 0.14
Nodes (8): B(), build(), chain(), chain_t(), exposed(), lin(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p, render_all()

### Community 135 - "Community 135"
Cohesion: 0.15
Nodes (18): bakery_oven(), candy_cane(), candy_lamp(), cotton_candy_tree(), drawbridge(), drip_ring(), MS(), quest_stand() (+10 more)

### Community 136 - "Community 136"
Cohesion: 0.15
Nodes (18): bell_r(), candy_egg(), choco_falls(), gumdrop_bush(), gumdrop_mountain(), icing_cap(), lathe(), macaron_stack() (+10 more)

### Community 137 - "Community 137"
Cohesion: 0.13
Nodes (18): biscuit_bridge(), gable_roof_bars(), gumball_machine(), marshmallow(), piping(), stepping-stone marshmallow: rounded cylinder, pink or white, slightly toasted to, spawn medallion: giant sugar cookie with a crimped rim, a piped icing star and s, icing piping along a polyline: beaded (radius pulses, short runs) or a smooth ro (+10 more)

### Community 138 - "Community 138"
Cohesion: 0.18
Nodes (12): 2d01203 Final MUT-01..30 audit: stress test, emit trampoline fix, consolidate milestone docs, e499073 Add MUT-29 dead-code elimination and MUT-30 control-flow simplification, alu(), br16(), br32(), emit_bytecode(), is_terminator_pub(), mk() (+4 more)

### Community 139 - "Community 139"
Cohesion: 0.12
Nodes (18): bubble_crown(), cotton_tree(), crystal_tree(), glow_shroom(), grass_tuft(), gumdrops(), lamp_post(), puff_tree() (+10 more)

### Community 140 - "Community 140"
Cohesion: 0.20
Nodes (13): commit_globals(), compile_program_bytecode(), Depth(), fail(), inspect_program_state_schema(), Parser, prepare_globals(), run_program() (+5 more)

### Community 141 - "Community 141"
Cohesion: 0.23
Nodes (16): add_body(), add_collider(), add_contact(), begin_step(), clampf(), clear(), collide_box_box(), collide_sphere_box() (+8 more)

### Community 142 - "Community 142"
Cohesion: 0.16
Nodes (16): check_coverage(), check_skill(), collect_tech_ids(), find_skills(), frontmatter(), known_py(), main(), parse_frontmatter() (+8 more)

### Community 143 - "Community 143"
Cohesion: 0.14
Nodes (6): B(), build(), exposed(), lin(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p, render_all()

### Community 144 - "Community 144"
Cohesion: 0.15
Nodes (8): B(), build(), cap(), chain(), exposed(), lin(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p, render_all()

### Community 145 - "Community 145"
Cohesion: 0.18
Nodes (16): cart_load(), druse(), _lump(), mound(), ore_lump(), ore_pile(), pickaxe(), pick resting with its head on the ground and the haft leaning on the heap (+8 more)

### Community 146 - "Community 146"
Cohesion: 0.17
Nodes (17): cargo_pile(), crate(), dry_shrub(), jar(), lerp(), peg_rope(), a cloth sheet over a parametric surface fn(u, v) -> Vector (u, v in 0..1), solid, plank crate: bevelled body with plank grooves (thin proud boards), corner straps (+9 more)

### Community 147 - "Community 147"
Cohesion: 0.17
Nodes (15): _code(), compile_effect(), cutoff_easing(), layer_schema(), _number(), Reusable, discovered-property layer authoring. No GUI state is required., Field names accepted by layer specs, for agents that want to check a recipe befo, Fixed position/scale that a dynamic equation recomputes every frame from the gam (+7 more)

### Community 148 - "Community 148"
Cohesion: 0.12
Nodes (6): afterFirst, afterSecond, firstOutput, mappingFailures, result, secondOutput

### Community 149 - "Community 149"
Cohesion: 0.16
Nodes (17): bench(), bridge(), chest(), ell(), fence(), gift_box(), leaderboard(), puff_bush() (+9 more)

### Community 150 - "Community 150"
Cohesion: 0.16
Nodes (7): convert_type(), lower_function(), lower_function_ex(), lower_module(), Lowerer, requires_mask(), unit_t()

### Community 151 - "Community 151"
Cohesion: 0.20
Nodes (14): build(), face(), free(), ground(), horizon(), kit(), local(), look() (+6 more)

### Community 152 - "Community 152"
Cohesion: 0.12
Nodes (15): bad_script(), cli_env(), empty_script(), good_script(), project(), Shared test setup for the effekseer-vfx skill.  vfxkit.paths computes the projec, Generate a watertight 10mm cube STL on demand., CadQuery script that writes a watertight cube next to itself. (+7 more)

### Community 153 - "Community 153"
Cohesion: 0.21
Nodes (16): A non-watertight part that is also too big gets both errors in one run., All documented keys must be present in every response., run(), test_bad_script_traceback(), test_bed_empty_string_is_usage_error(), test_bed_fits(), test_bed_too_small_fails(), test_bed_unknown_printer_is_usage_error() (+8 more)

### Community 154 - "Community 154"
Cohesion: 0.19
Nodes (16): blur(), derive_ao(), derive_normal(), derive_roughness(), high_pass(), load_gray(), main(), process() (+8 more)

### Community 155 - "Community 155"
Cohesion: 0.14
Nodes (2): EvidenceTests, Evidence handling tests, not real SDK or GPU acceptance.

### Community 156 - "Community 156"
Cohesion: 0.19
Nodes (16): build(), check_output_dirs(), check_resource_conflicts(), check_targets(), eid(), owned(), Compile recipes through EffekseerCore into .efkefc sources, .efk runtime exports, Every folder init or a build writes into or deletes from must really be inside v (+8 more)

### Community 157 - "Community 157"
Cohesion: 0.17
Nodes (16): digest(), guard(), inside(), may_use(), name_key(), owned(), Which effects and files in a workspace this skill built, so it only ever deletes, Built by this skill, so a full build may remove it once its source is gone. (+8 more)

### Community 158 - "Community 158"
Cohesion: 0.17
Nodes (13): AssertionError, check_mating(), MatingError, overlap(), Fit checks for printed parts that go together (lids, joints, segments).  A previ, Volume in mm^3 shared by two CadQuery Workplanes (0 when apart)., Raise MatingError unless `moving` fits `fixed` with play only up to     `clearan, A 20 mm block sitting in a U socket whose opening is `gap` wide. (+5 more)

### Community 159 - "Community 159"
Cohesion: 0.16
Nodes (8): build(), disc_x(), exposed(), lin(), newid(), put(), exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p, wheel()

### Community 160 - "Community 160"
Cohesion: 0.16
Nodes (11): _Compartments, _CylinderPocket, _Notch, _Pocket, _PolygonPocket, Gridfinity bin generator for CadQuery.  Vendored module: copy this file next to, Cavity with an arbitrary closed outline (list of (x, y) mm).          `clearance, Round cavity cut from the top rim down `depth` mm.          Useful for finger we (+3 more)

### Community 161 - "Community 161"
Cohesion: 0.20
Nodes (16): candy_castle(), cone_tower(), giant_cone(), smooth lumpy ball: icosphere (sub 2 = 80, 3 = 320 tris) displaced by low-frequen, story prop: a toppled giant ice-cream cone, scoop slumped on the ground and melt, torus in the XZ plane (ring axis = Y), waffle grid: diagonal diamond pattern by alternating face shades (0 = ridge, 1 =, ice-cream-cone tower: waffle shaft, icing collar, big scoop with drips, upturned (+8 more)

### Community 162 - "Community 162"
Cohesion: 0.14
Nodes (13): closed_torus(), jelly_bean(), jelly_beans(), _pmat(), preview_mats(), a bean: tube along a gentle arc with rounded ends, rock' scatter: a heap of 6-9 glossy jelly beans, some speckled, palette column -> Enum.Material name, for roblox_materials.write_map (+5 more)

### Community 163 - "Community 163"
Cohesion: 0.24
Nodes (13): append(), decode_string(), decode_utf8(), diagnostic(), evaluate_console(), execute_console(), execute_console_impl(), execute_console_stateful() (+5 more)

### Community 164 - "Community 164"
Cohesion: 0.23
Nodes (5): _bootstrap(), _load(), TestBootstrapContent, TestSkillsDirResolution, TestStripFrontmatter

### Community 165 - "Community 165"
Cohesion: 0.35
Nodes (13): blk(), dress_caps(), finish(), floor(), grp(), hub(), kerb_x(), kerb_z() (+5 more)

### Community 166 - "Community 166"
Cohesion: 0.22
Nodes (9): build_tree(), _camera_box(), _iface(), _material(), Rain, snow, dust, ash or embers as a seamlessly looping Geometry Nodes system (n, World AABB of the camera's near frustum (0..distance) over the frame range., Minimal node-graph helper: n(type, inputs..., **props) -> node; sockets by enabl, run() (+1 more)

### Community 167 - "Community 167"
Cohesion: 0.16
Nodes (8): accepts(), Analyzer, dump_semantic(), is_float_scalar(), is_integer_scalar(), name(), numeric(), same_type()

### Community 168 - "Community 168"
Cohesion: 0.14
Nodes (4): AssetHandle(), is_loading(), load_state(), release()

### Community 169 - "Community 169"
Cohesion: 0.21
Nodes (15): cube(), detached_part(), mesh_object(), plane(), Procedural test fixtures (no binary .blend files in the repo)., Two coplanar overlapping planes in different objects + one inside a single mesh., A body with a floating island and a separate floating object., Smart-project UVs so bake/texel tests have a UV map. (+7 more)

### Community 170 - "Community 170"
Cohesion: 0.23
Nodes (2): GoldenHarnessTests, run()

### Community 171 - "Community 171"
Cohesion: 0.28
Nodes (15): apply_events(), axis(), game_map(), kb(), key(), main(), mouse(), mouse_button() (+7 more)

### Community 172 - "Community 172"
Cohesion: 0.21
Nodes (15): apply(), factors(), _frames(), _layers(), _life(), _map(), profile(), World scale: write a recipe at the Lab's character scale and build it for a much (+7 more)

### Community 173 - "Community 173"
Cohesion: 0.14
Nodes (4): ClearBackend, OpenGLClearBackend, VulkanClearBackend, OpenGLESClearBackend

### Community 174 - "Community 174"
Cohesion: 0.13
Nodes (15): bush(), collect_pad(), flower_patch(), flower_tub(), lily_pads(), pine(), cash collect pad: octagon stone ring, accent rim with a glow ring, cream disc wi, half-barrel planter: honey staves with iron hoops, soil, low-poly tulips (+7 more)

### Community 175 - "Community 175"
Cohesion: 0.20
Nodes (14): candy_cane(), egg(), egg_prof(), egg_r(), egg_stand(), lift(), rainbow_arch(), a chunky star standing upright facing -Z, centred at the origin, rounded front e (+6 more)

### Community 176 - "Community 176"
Cohesion: 0.23
Nodes (14): compare_to_render(), delta_e(), extract(), hex_of(), hex_to_rgb(), kmeans(), load_palette(), main() (+6 more)

### Community 177 - "Community 177"
Cohesion: 0.20
Nodes (14): _drape(), _hide_body(), penetration(), Game clothing from a body: extract a region as a garment shell (ease offset + th, Classic cloth: pin the top band, collide with the body, settle `frames`, apply t, Same-named garment shape key for every body shape key (Surface Deform bound at r, Body verts (evaluated pose) poking through: casting along the body normal, the g, Copy the region's faces in world space and push them out along the vertex normal (+6 more)

### Community 178 - "Community 178"
Cohesion: 0.24
Nodes (14): _assets(), build_cards(), card_material(), curve_stats(), _evaluated(), groom(), hair_material(), _modifier() (+6 more)

### Community 179 - "Community 179"
Cohesion: 0.14
Nodes (9): grid(), r2b(), rot = (pitch about X, yaw about Y, roll about Z) in degrees, a crystal / spire: prism up to h * shoulder, then a pyramid tip, heightfield quad grid (Roblox space): y = hfun(x, z), loc / tgt in Roblox space, render(), spike() (+1 more)

### Community 180 - "Community 180"
Cohesion: 0.32
Nodes (14): append_shape_raws(), capsule_at(), cast_fraction(), deepest_contact(), length_of(), planar(), resolve(), shape_bound() (+6 more)

### Community 181 - "Community 181"
Cohesion: 0.24
Nodes (14): attribution_allowed(), file_hits(), files(), jpeg_metadata(), png_metadata(), private_terms(), publisher_allowed(), The published package carries no personal, machine-specific or secret data, in t (+6 more)

### Community 182 - "Community 182"
Cohesion: 0.24
Nodes (12): _qa(), test_clean_cube_passes(), test_detects_floating_parts_and_objects(), test_detects_inverted_and_inconsistent_normals_and_back_to_back(), test_detects_zfighting_between_objects_and_within_mesh(), test_enclosed_part_is_not_floating(), test_mirrored_object_is_not_inside_out_and_empty_mesh_is_flagged(), test_roblox_profile_flags_open_mesh_and_ngons() (+4 more)

### Community 183 - "Community 183"
Cohesion: 0.21
Nodes (14): atlas(), cracks(), fnoise(), _hex(), install(), paint_block(), palette UVs (u column, v shade) -> atlas UVs, in place on an MB (Roblox-space ve, patch the grove machinery: atlas instead of the strip, UV remap in mesh_from (+6 more)

### Community 184 - "Community 184"
Cohesion: 0.22
Nodes (7): finish(), has_breakpoint(), pc(), result(), run(), stack(), step()

### Community 185 - "Community 185"
Cohesion: 0.23
Nodes (5): Activity, Callback, PokoActivity, SurfaceHolder, SurfaceView

### Community 186 - "Community 186"
Cohesion: 0.15
Nodes (14): deco_egg(), egg(), feed_trough(), hatchery(), nest_pedestal(), nest_statue(), chunky low-poly nest: a fat torus rim with a dished floor, straw wisps poking ou, incubator slot: octagon stone plinth with an accent ring + four gem studs, honey (+6 more)

### Community 187 - "Community 187"
Cohesion: 0.16
Nodes (14): _fern(), grass_tuft(), hammock_palms(), _merge_prop(), palm(), palm_planter(), coconut palm: curved ringed trunk (silver-tan), flared foot, boot sheaths, cocon, woven round planter (bamboo hoops) with a young palm and fern tufts (+6 more)

### Community 188 - "Community 188"
Cohesion: 0.21
Nodes (13): assign(), _dilate6(), export(), _greedy2d(), limb(), _quads(), Rig + Roblox export for the BRICK pipeline (always run it: every brick model shi, fresh session: import the GLB, check bones + rigid weights, pose, render rest + (+5 more)

### Community 189 - "Community 189"
Cohesion: 0.18
Nodes (6): erase(), hash(), hash_bytes(), keys(), push_back(), remove()

### Community 190 - "Community 190"
Cohesion: 0.48
Nodes (13): arith_module(), calls_module(), cases(), check(), compile_source(), hostcall_module(), i32(), main() (+5 more)

### Community 192 - "Community 192"
Cohesion: 0.22
Nodes (12): describe(), _forget_helpers(), get(), HelperFinder, library(), load(), partial(), The project's effect library: one recipe source per effect in vfx/src/<ID>.py. (+4 more)

### Community 193 - "Community 193"
Cohesion: 0.29
Nodes (10): box(), build(), capsule(), get_collection(), link(), Parametric human blockout from measured sheet fractions.  Every dimension is a f, Print measured bounds so the comparison step has numbers, not vibes., Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry. (+2 more)

### Community 194 - "Community 194"
Cohesion: 0.26
Nodes (11): find_isolated(), find_strays(), landmarks(), Automated scene validation gate.  Catches the two defect classes that silently r, Measured landmark heights, for proportion drift checks., World-space bounds computed from evaluated vertices.      ob.bound_box is a cach, Objects whose bounds break the envelope on the horizontal axes., Objects floating away from the body mass - the sideways-cylinder signature. (+3 more)

### Community 195 - "Community 195"
Cohesion: 0.32
Nodes (3): LayerBuilder, Bind a texture slot and optionally scroll it; speeds are UV units per frame., Optional native features: dissolve, UV distortion, blend texture, fresnel, flipb

### Community 196 - "Community 196"
Cohesion: 0.17
Nodes (13): egg_profile(), egg_slice(), foot_bridge(), lane_lamp(), lerp(), plot_slab(), the yard: chamfered stone footing + accent kerb, straw-cream ground, a paved sto, lane lamp: stone base, honey post with an iron arm, an egg-shaped glowing lanter (+5 more)

### Community 197 - "Community 197"
Cohesion: 0.21
Nodes (13): barrel(), barrels(), boat_hull(), lerp(), motor_boat(), paint_hull(), hollow lofted boat hull: U sections closed by the sheer line (solid), sharp bow, hull shading: bottom colour below the waterline, a stripe band under the sheer l (+5 more)

### Community 198 - "Community 198"
Cohesion: 0.19
Nodes (7): IPlatform, TestPlatform, destroy_window(), get_window_size(), poll_event(), ~SdlPlatform(), shutdown()

### Community 199 - "Community 199"
Cohesion: 0.17
Nodes (13): arc_pts(), disc_up(), lollipop(), paw(), paw-print icon: palm pad + 4 toe beans, built flat then stood up facing -Z (pitc, flat trade circle: cream disc with a pastel rim and two glowing curved swap arro, toll arch: two chubby stacked pillars with paw-ball finials, a rounded arch beam, round spawn dais: two soft tiers, mint rim, a big paw-print inlay. Walkable (pre (+5 more)

### Community 200 - "Community 200"
Cohesion: 0.24
Nodes (12): _feeds(), _islands(), _material_issues(), _mesh_world(), _point_in_tri(), Mesh/asset QA: z-fighting, detached parts, normals, topology, transforms, UVs, w, (node type, input name) pairs a socket reaches through up to `depth` nodes., [(severity_is_error, message)] for slots, faces and image textures. (+4 more)

### Community 201 - "Community 201"
Cohesion: 0.26
Nodes (12): collect_target_files(), get_scanner_config(), get_supported_extensions(), _identify_semantic_files(), perform_scan(), Maps files to semantic categories based on filename patterns., Internal worker to scan a single file for all signal categories., Orchestrates the parallel scanning of identified files. (+4 more)

### Community 202 - "Community 202"
Cohesion: 0.15
Nodes (12): bush(), charred_tree(), lamp_post(), lava_pool(), mesa_rock(), molten pool: ring of basalt boulders, glowing surface with dark crust plates flo, burnt tree: thick twisting trunk with 4 forked branches, glowing ember cracks, a, lumpy faceted bush: 4-6 clumps, lighter on top, with a few berries or flowers (+4 more)

### Community 203 - "Community 203"
Cohesion: 0.21
Nodes (12): bevel_box(), blossom_tree(), island_under(), lumpy(), puffy_tree(), icosphere with noise displacement: chunky stylised foliage / cloud / rock lump, underside: 16 rings to a rough tip, noise-displaced (no big flat triangles), ter, carved stone gate: stepped plinths, octagonal banded shafts with capitals, a vou (+4 more)

### Community 204 - "Community 204"
Cohesion: 0.37
Nodes (12): adb_shell(), android_compile(), android_leg(), android_tools(), main(), msvc_tools(), normalize_lf(), now() (+4 more)

### Community 205 - "Community 205"
Cohesion: 0.35
Nodes (12): cases(), check(), count_instrs(), count_op(), i32t(), lower_src(), main(), module_of() (+4 more)

### Community 206 - "Community 206"
Cohesion: 0.24
Nodes (6): initialize(), initialize_impl(), initialize_window(), OpenGLClearESRenderer(), shutdown(), shutdown_checked()

### Community 207 - "Community 207"
Cohesion: 0.18
Nodes (12): egg_drain(), egg_finial(), fence_post(), gate_frame(), owner_sign(), post(), post-top egg knob: accent collar + cream egg with an accent band, square post with a stone footing (extends below ground) and a chamfered top (+4 more)

### Community 208 - "Community 208"
Cohesion: 0.27
Nodes (7): dot(), isqrt_u64(), length(), lengthSquared(), normalized(), raw_length_sq(), saturate_raw64()

### Community 209 - "Community 209"
Cohesion: 0.27
Nodes (7): canonical_png(), main(), png_chunk(), RGB8 PNG with filter 0 and explicit uncompressed DEFLATE blocks., run(), X11, XImage

### Community 210 - "Community 210"
Cohesion: 0.45
Nodes (11): aead_open(), aead_seal(), chacha20_block(), chacha20_xor(), consttime_equal(), load32_le(), poly1305_mac(), qr() (+3 more)

### Community 211 - "Community 211"
Cohesion: 0.17
Nodes (12): cedar(), cloud_tree(), crag(), hot_pool(), jp_pine(), lerp(), pool_outline(), steaming rock pool: raised ashlar-and-boulder rim, cut-stone curb, milky water, (+4 more)

### Community 212 - "Community 212"
Cohesion: 0.20
Nodes (12): doorway(), frame_storey(), holed_wall(), wall panel L long (x -L/2..L/2), H high, th thick, holes [(x0, x1, y0, y1)] cut, cut window: timber frame round the hole, sill, recessed shoji lattice with a war, cut doorway: heavy posts + lintel, a sliding lattice door half open, warm lit in, dark cedar framing: corner posts, extra posts, a head beam (nageshi) and sill al, four plaster walls of one storey with cut openings; returns the x positions of w (+4 more)

### Community 213 - "Community 213"
Cohesion: 0.20
Nodes (12): flared_roof(), house(), pagoda(), plinth(), pent roof around a storey (pagoda tiers, inn skirts): from the eave down to the, SHARED BASE: sand-ashlar plinth (block faces) with a chamfered cap course, sunk, village house / inn: ashlar plinth, plaster storeys with cut windows + door, ced, HERO: five-tier bathhouse pagoda. Stepped ashlar platform + veranda, five storey (+4 more)

### Community 214 - "Community 214"
Cohesion: 0.26
Nodes (11): _blur(), _curvature_from_normal(), Bake texture maps with Cycles: high->low (selected-to-active) or self-bake proce, Divergence of the tangent normal field: convex > 0.5 (white), concave < 0.5 (dar, Route a per-material signal into an Emission shader. Returns an undo list., Ensure every low material has an active Image node pointing at img., _restore(), run() (+3 more)

### Community 215 - "Community 215"
Cohesion: 0.24
Nodes (10): _f(), mesh_blocks(), neon_mat(), palette material + procedural studs (one round stud per `studs` studs, on every, groups: {folder name: [Block, ...]} in world space. Writes a Model with one Fold, one solid mesh (palette + studs) + one mesh per neon colour + one for transparen, rgb_of(), shape_bm() (+2 more)

### Community 216 - "Community 216"
Cohesion: 0.33
Nodes (8): Sequences (combos), the blockout gate, screen feedback and the stylized hard-edg, test_a_blockout_sequence_needs_blockout_effects(), test_blockout_lint_holds_recipes_to_math_textures(), test_detail_needs_the_blockout_gate_and_steal_lists(), test_game_frames_become_evidence_and_a_blockout_ship_opens_the_gate(), test_screen_feedback_is_validated(), vfx(), workspace()

### Community 217 - "Community 217"
Cohesion: 0.39
Nodes (11): button(), gamepad_axis(), gamepad_button(), key(), main(), motion(), pos(), record_hashes() (+3 more)

### Community 218 - "Community 218"
Cohesion: 0.26
Nodes (1): TraceTests

### Community 219 - "Community 219"
Cohesion: 0.23
Nodes (6): absolute(), file_hash(), Shared portable storage and a reentrant, cross-process workspace lock., relative(), snapshot(), unchanged()

### Community 220 - "Community 220"
Cohesion: 0.29
Nodes (10): _area(), _ensure_world(), Fixed-camera turnaround renders for reference comparison.  Sets one camera + a n, Three-point rig scaled to subject height.      Energies scale with height square, World bounds from evaluated vertices: bound_box is stale after mesh edits., render_turnaround(), _scene_bounds(), setup_camera() (+2 more)

### Community 221 - "Community 221"
Cohesion: 0.47
Nodes (10): assemble_bytecode(), branch(), branch_offset(), decode_bytecode(), disassemble_bytecode(), encode_bytecode(), long_offset(), long_payload() (+2 more)

### Community 222 - "Community 222"
Cohesion: 0.22
Nodes (7): _corner_radii(), GridfinityError, Normalize scalar / 2-tuple / 4-tuple corner radii.      Order: (+X+Y, -X+Y, -X-Y, Rounded-rect cavity cut from the top rim down `depth` mm.          `corner_r`: s, Feature footprint must leave MIN_WALL of outer wall., Raised when a bin configuration cannot produce valid geometry., ValueError

### Community 223 - "Community 223"
Cohesion: 0.27
Nodes (7): messages(), since(), start(), start_with_factory(), stop(), totals(), VulkanDiagnostics()

### Community 224 - "Community 224"
Cohesion: 0.29
Nodes (9): clear_and_present(), draw_and_present(), Impl(), initialize(), native_window(), SdlPlatform, shutdown(), shutdown_checked() (+1 more)

### Community 225 - "Community 225"
Cohesion: 0.24
Nodes (11): merge_into(), obelisk(), obelisk_fallen(), obelisk_stump(), plinth(), SHARED BASE: stepped sandstone plinth, a chamfered course per step, gold trim li, square tapered shaft (w0 at 0 .. w1 at H) cut at y0..y1, in drums, relief column, standing obelisk on the stepped plinth: drummed tapered shaft, relief columns on (+3 more)

### Community 226 - "Community 226"
Cohesion: 0.24
Nodes (10): campfire(), grid_disc(), oasis_pool(), stone ring, crossed logs, flame glow, a three-legged tripod with a hanging pot,, oasis: a round pool (r 10) with a turquoise water disc set below a rim of cut sa, flat disc split into rings / sectors of ~cell (atlas-friendly), DIG SPOT anchors: tier 1 a low sand mound with a cracked jar and a marker stick,, spike_flame() (+2 more)

### Community 227 - "Community 227"
Cohesion: 0.22
Nodes (7): bootstrapSkillPath, extensionDir, getBootstrapContent(), packageRoot, piToolMapping(), skillsDir, stripFrontmatter()

### Community 228 - "Community 228"
Cohesion: 0.33
Nodes (9): decode(), digit(), digit_for(), is_continue(), is_start(), keyword(), lex(), string_body() (+1 more)

### Community 229 - "Community 229"
Cohesion: 0.22
Nodes (6): gamepad_control(), gamepad_slot(), InputReplay, InputTimeline, touch_display(), touch_id()

### Community 230 - "Community 230"
Cohesion: 0.18
Nodes (11): balcony(), footbridge(), giboshi(), rail_post(), railing(), railing_post(), bronze onion cap (the signature post finial), deck on brackets along a wall at z (side = -1 front), cedar rail with giboshi po (+3 more)

### Community 231 - "Community 231"
Cohesion: 0.22
Nodes (11): coin_pile(), flat(), flower_patch(), mushroom(), pet_fountain(), hub hero: 3-tier pastel fountain (scalloped basin, water, mid bowl with a pale w, low gold mound with a short coin stack and loose coins leaning on it, 5-7 chibi daisies: thin stem, leaf, scalloped petal disc, round centre (+3 more)

### Community 232 - "Community 232"
Cohesion: 0.18
Nodes (5): __dirname, extensionPath, packageJsonPath, piToolsPath, repoRoot

### Community 233 - "Community 233"
Cohesion: 0.24
Nodes (9): _bootstrapCache, _cacheChildSession(), _childSessionCache, __dirname, extractAndStripFrontmatter(), getBootstrapContent(), isChildSession(), setup() (+1 more)

### Community 234 - "Community 234"
Cohesion: 0.36
Nodes (10): cleanup(), _ctx(), _heat_scale(), _height(), _parent(), _proxy_weights(), Skin meshes to an armature with robust automatic weights, then clean them for en, Factor that brings the rig to ~1.8 m for bone heat; 1.0 when already 0.5-20 m ta (+2 more)

### Community 235 - "Community 235"
Cohesion: 0.29
Nodes (10): apply(), build(), describe(), _layout(), _parse_val(), Build node trees (Geometry Nodes, shader, compositor) from a compact JSON spec,, Column layout by longest path from inputs (readable trees for humans)., Inputs/outputs (name, type, default) of node types, from a throwaway tree. (+2 more)

### Community 236 - "Community 236"
Cohesion: 0.33
Nodes (9): critical(), debug(), emit(), error(), info(), init(), to_spdlog(), trace() (+1 more)

### Community 237 - "Community 237"
Cohesion: 0.31
Nodes (7): add_node(), add_spring(), apply_acceleration(), clamp01(), create(), create_lattice(), step()

### Community 238 - "Community 238"
Cohesion: 0.31
Nodes (6): codepoint_count(), concat(), decode(), slice_codepoints(), to_lower_ascii(), valid_utf8()

### Community 239 - "Community 239"
Cohesion: 0.22
Nodes (4): example_ids(), Shipped example effects: complete, valid, self-consistent with their briefs and, test_catalog_lists_every_shipped_example_as_pairs_singles_and_sets(), test_lint_of_all_examples_has_no_errors()

### Community 240 - "Community 240"
Cohesion: 0.20
Nodes (2): test_ablation_verdicts(), _write_ablation()

### Community 241 - "Community 241"
Cohesion: 0.35
Nodes (10): ceiling(), check(), def(), i32(), main(), narrowed_module(), pv(), run_err() (+2 more)

### Community 242 - "Community 242"
Cohesion: 0.42
Nodes (10): apply_events(), connect(), disconnect(), event(), main(), pad_axis(), pad_button(), pos() (+2 more)

### Community 243 - "Community 243"
Cohesion: 0.47
Nodes (10): bindings(), cases(), check(), deep(), error_case(), eval(), floating(), main() (+2 more)

### Community 244 - "Community 244"
Cohesion: 0.45
Nodes (10): bytecode_limits(), check(), i32t(), lexer_limits(), main(), package_limits(), pipeline_limits(), program_limits() (+2 more)

### Community 245 - "Community 245"
Cohesion: 0.31
Nodes (10): add(), catalog(), ids(), listing(), Shipped example effects: four ranged pairs (projectile + impact), five single ef, `show` for one effect, or for every effect of a named example (a pair shows proj, Layer plan with absolute frames, so an example can be read as a timeline before, show() (+2 more)

### Community 246 - "Community 246"
Cohesion: 0.20
Nodes (5): Draw a closed rounded-rect wire with per-corner radii on `workplane`.      `radi, Cutters (cavities) and additions (scoops, label shelves)., Concave quarter-round ramp along a compartment's front floor edge., 45-degree triangular label shelf hanging from a back wall., _rounded_rect()

### Community 247 - "Community 247"
Cohesion: 0.20
Nodes (9): bed_fit(), estimate_mass(), load_mesh(), parse_bed(), Pure trimesh STL loading with validation guards.  Kept separate from preview.py, Approximate printed mass in grams (default: PLA, 2 walls, 15% infill).      A sl, Load an STL file via trimesh.      Raises ValueError if the file cannot be parse, Turn a printer name, "WxDxH" or a single "N" (cube) into (x, y, z) mm.      Rais (+1 more)

### Community 248 - "Community 248"
Cohesion: 0.29
Nodes (9): align_and_scale(), main(), max_section_outline(), Extract a 2D pocket outline from a 3D scan of an object.  Produces the max cross, PCA-align in XY, center on the origin, floor to Z=0, scale., Union of horizontal sections from Z=step/2 up to zmax., Angle (deg) minimizing the bounding square of poly + clearance., recentered() (+1 more)

### Community 249 - "Community 249"
Cohesion: 0.29
Nodes (7): clear_and_present(), default_framebuffer_is_srgb(), initialize(), native_window(), OpenGLClearRenderer(), SdlPlatform, shutdown()

### Community 250 - "Community 250"
Cohesion: 0.22
Nodes (4): draw(), draw_and_present(), VulkanDiagnostics, VulkanMeshPass()

### Community 251 - "Community 251"
Cohesion: 0.27
Nodes (9): editor_bin_directory(), export_binary(), load_core(), Load the official Effekseer Core assembly through Python.NET., Return the configured directory containing ``EffekseerCore.dll``.      A release, Return the bundled .NET runtime configuration file., Load and return the official static ``Effekseer.Core`` type., Export the current Core document as an Effekseer runtime ``.efk`` file. (+1 more)

### Community 252 - "Community 252"
Cohesion: 0.20
Nodes (10): ball(), bench(), lifebuoy_stand(), lighthouse(), marker_buoy(), net_pile(), the lighthouse rising out of the dome: coral plinth, tapered tower in red / whit, heap of teal fishing net: lumpy mound with a rope mesh draped over its surface, (+2 more)

### Community 253 - "Community 253"
Cohesion: 0.20
Nodes (10): crate(), crate_stack(), local(), mat_cell(), quest_board(), QUEST BOARD: two bamboo posts with lashings, framed cork panel with blank pinned, woven palm-mat infill between posts: strips 0.55 tall, alternating tone and dept, wall panel L long, H high (local x -L/2..L/2), holes [(x0, x1, y0, y1)] left ope (+2 more)

### Community 254 - "Community 254"
Cohesion: 0.27
Nodes (5): connect(), find_native(), route_count(), routes(), slot_in_use()

### Community 255 - "Community 255"
Cohesion: 0.22
Nodes (10): bath_pavilion(), hip_roof(), noodle_stall(), paper_lantern(), paper_lantern_post(), rectangular hip roof over a hw x hd (half sizes) wall box: ridge along X, ridge, chouchin: glowing ribbed paper body with dark wood top + bottom rings and a hang, open bath shelter over a pool: round cedar columns on stone bases, tie beams, br (+2 more)

### Community 256 - "Community 256"
Cohesion: 0.20
Nodes (8): added, failures, fixtureRoot, frontmatterFixtures, pluginPath, result, skillsDir, survived

### Community 257 - "Community 257"
Cohesion: 0.42
Nodes (9): after_token(), build_project(), declared_identity(), name(), next_quoted(), parse_manifest(), quoted(), string_array() (+1 more)

### Community 258 - "Community 258"
Cohesion: 0.24
Nodes (4): dump_ast(), ExpressionParser, op_spelling(), quoted()

### Community 259 - "Community 259"
Cohesion: 0.24
Nodes (5): Depth(), dump_statement_ast(), quoted(), StatementParser, stmt_fail()

### Community 260 - "Community 260"
Cohesion: 0.20
Nodes (10): giant_donut(), pet_shop(), pill(), capsule from a to b (rounded ends), open-front kiosk: round dais, curved back wall with toy shelves, 4 chubby pillar, giant gumball machine: rounded red drum base (coin plate, glowing up-chevron, ch, pink-frosted donut lying tilted on the grass with sprinkles, lilac curled post (a hook at the top) holding a glowing star lantern (+2 more)

### Community 261 - "Community 261"
Cohesion: 0.20
Nodes (2): finish hero: 1-2-3 podium + a giant cylinder-built trophy (base, stem, flared cu, trophy()

### Community 262 - "Community 262"
Cohesion: 0.36
Nodes (9): auto_front(), load(), main(), palette(), Extract clean single-view reference panels from a concept sheet.  The sheet is a, Find the tallest narrow subject column inside a region — the front view., save_crop(), subject_mask() (+1 more)

### Community 263 - "Community 263"
Cohesion: 0.27
Nodes (9): analyze(), describe_rule(), main(), Analyzes R8 keep rule radius JSON output and computes optimization scores., Entry point for CLI execution., Returns a rule's source text, origin, and whether the app can edit it., Computes R8 optimization scores and rule impacts from keep radius JSON., Returns the file, line and Maven coordinate a keep rule comes from. (+1 more)

### Community 264 - "Community 264"
Cohesion: 0.31
Nodes (9): _animated(), _coerce(), _export(), _gather(), glb_summary(), Export objects/collections with engine presets, then verify the file.  Presets:, True if exporting o could carry animation (keys, NLA, drivers, constraints, shap, Parse the JSON chunk of a .glb (no import needed). (+1 more)

### Community 265 - "Community 265"
Cohesion: 0.36
Nodes (9): _bounds(), _ensure_rigify(), _fit(), game_skeleton(), _generate(), Rigify pipeline: add + fit metarig, generate control rig, build an engine-ready, root + DEF bones with DEF-only parenting, constrained to the control rig., _remove_face() (+1 more)

### Community 266 - "Community 266"
Cohesion: 0.31
Nodes (9): column_of(), mat_for(), preview(), material for palette ramp `col` on object/mesh `name`: per-prop overrides ({pref, give every palette mesh one Blender material slot per Roblox material (by palett, material_map.json for the exporter: palette column index -> Roblox material, + p, resolve(), _variant() (+1 more)

### Community 267 - "Community 267"
Cohesion: 0.33
Nodes (9): _erode(), _heightmap(), _material(), _noise_field(), Game-ready terrain: noise (fbm, ridged mountains, rolling hills) or a heightmap, Thermal erosion: material above the talus angle slides to lower neighbours (4-ne, run(), _save_png16() (+1 more)

### Community 268 - "Community 268"
Cohesion: 0.22
Nodes (3): Analyzer, dump_determinism(), name()

### Community 269 - "Community 269"
Cohesion: 0.44
Nodes (9): collect_unknown(), fail(), find_key(), load_file(), parse_level(), read_bool(), read_text(), read_u32() (+1 more)

### Community 270 - "Community 270"
Cohesion: 0.22
Nodes (2): hash(), mix()

### Community 271 - "Community 271"
Cohesion: 0.20
Nodes (3): The vendored effekseer_ai bridge: portable CLI surface and an explicit, never-gu, A public release must never probe a contributor's local disks., test_editor_bin_directory_requires_an_explicit_configuration()

### Community 272 - "Community 272"
Cohesion: 0.31
Nodes (9): assess(), boundary_metrics(), load_gray(), main(), print_report(), Detect visible seams in a tiling texture.  The test is not "does it look OK when, Tiled preview, so the seam can be looked at and not only measured., Compare the wrap edge against every interior adjacent pair.      `percentile` an (+1 more)

### Community 273 - "Community 273"
Cohesion: 0.33
Nodes (9): group_stats(), main(), parse_obj(), print_report(), Measure texel density across the parts of a mesh.  Density is linear: texture pi, Return groups -> list of (v_idx, vt_idx) triangles plus vertex positions.      O, report(), tri_area_3d() (+1 more)

### Community 274 - "Community 274"
Cohesion: 0.20
Nodes (9): full_mode_platform(), godot(), initialized(), Where the skill's own files live, where the toolchain is installed and which gam, `vfx init` has run here: a vfx/ folder that merely exists (another tool's output, Where build and render (EffekseerCore through .NET, the Effekseer Godot plugin), How to run setup on this system, as a command an agent can run from the project., Godot 4 executable: GODOT, then `godot` (or `godot4`) on PATH, then the standard (+1 more)

### Community 275 - "Community 275"
Cohesion: 0.38
Nodes (8): analyse(), checked_id(), compare(), frames(), import_clip(), Local reference clips, explicit time mapping and honest approximate pixel analys, read(), tiles()

### Community 276 - "Community 276"
Cohesion: 0.20
Nodes (2): OverlapTests, Regression tests independent of Blender: python test_uv_overlap.py.

### Community 277 - "Community 277"
Cohesion: 0.22
Nodes (6): assert, fs, HELPER, moduleShim, path, src

### Community 278 - "Community 278"
Cohesion: 0.25
Nodes (9): ball(), candy_flower(), egg_machine(), lollipop_tree(), patch of fondant flowers: lime stems, 6 soft petals, gum centres, PET / EGG MACHINE: sugar-glass dome over a cotton-candy nest of three decorated, flat lollipop swirl: two interleaved Archimedean spiral ribbons (true spiral ban, swirl lollipop on a bent stick, disc tilted to face the path (-Z), plus a smalle (+1 more)

### Community 279 - "Community 279"
Cohesion: 0.28
Nodes (6): draw(), draw_and_present(), set_texture(), set_texture_mips(), VulkanDiagnostics, VulkanTrianglePass()

### Community 280 - "Community 280"
Cohesion: 0.28
Nodes (5): hay_bale(), hay_stack(), merge_prop(), square hay bale: chamfered straw block, two twine bands, straw tufts on top, three bales stacked (2 + 1), a pitchfork-free story pile

### Community 281 - "Community 281"
Cohesion: 0.39
Nodes (8): build(), gill_base(), gills(), happy(), idle(), swim(), _unit(), walk()

### Community 282 - "Community 282"
Cohesion: 0.28
Nodes (4): build_plan(), compile(), execute(), FrameGraph

### Community 283 - "Community 283"
Cohesion: 0.22
Nodes (2): SQLite-level tests for the D1 word-reservation migration., ReservationMigrationTests

### Community 284 - "Community 284"
Cohesion: 0.22
Nodes (9): bucket(), hand_cart(), drying rack: two cedar uprights with feet, three poles, folded towels draped ove, sake cask: straw-wrapped body, rope bands, lid; lying casks rest on their side, cluster: cedar pallet, three standing casks, one on top, one lying in a chock, a, two-wheeled hand cart: plank bed with side boards, long handles, spoked wheels,, sake_barrels(), taru() (+1 more)

### Community 285 - "Community 285"
Cohesion: 0.28
Nodes (5): decl_fail(), decl_quoted(), DeclarationParser, Depth(), dump_declaration_ast()

### Community 286 - "Community 286"
Cohesion: 0.33
Nodes (5): connect(), reloadAfterRecovery(), sessionKey(), setStatus(), websocketUrl()

### Community 287 - "Community 287"
Cohesion: 0.33
Nodes (8): _bolt_points(), _clear(), _curve(), _envelope(), Storm lightning: keyed multi-stroke flashes (a real strike is 3-4 return strokes, Midpoint displacement between top and bottom; returns a list of Vectors., {frame: intensity 0..1}. Each stroke: peak, 20% next frame, gone after ~3 frames, run()

### Community 288 - "Community 288"
Cohesion: 0.39
Nodes (8): auto_map(), _parts(), Retarget an animated skeleton (mocap/BVH/Mixamo/any rig) onto another rig, const, mixamorig:LeftUpLeg' -> ('upleg', 'L'); 'DEF-upper_arm.L' -> ('upperarm', 'L')., {(part, side): bone}, plus the spine chain (hips -> neck order)., _rot(), run(), _split()

### Community 289 - "Community 289"
Cohesion: 0.33
Nodes (5): advance(), alpha(), FixedStepLoop(), to_ns(), valid_limits()

### Community 290 - "Community 290"
Cohesion: 0.22
Nodes (2): mesh_io must not pull in pyrender (it's the whole point of the split)., test_load_mesh_no_pyrender_import()

### Community 291 - "Community 291"
Cohesion: 0.25
Nodes (7): _humanoid_mesh(), Issue #11: >= 4000 verts makes the symmetry sample step > 1 (bpy collections rej, Bone heat fails at mm/km world sizes (all weight on one bone); bind_mesh binds a, Crude closed humanoid (torso, head, arms in T, legs) ~1.8 m, union of boxes (non, test_bind_tiny_and_huge_rigs_get_real_weights(), test_rig_check_dense_mesh(), test_rigify_pipeline_bind_check_stress()

### Community 292 - "Community 292"
Cohesion: 0.44
Nodes (8): bench(), best_ns(), cases(), check(), compile(), i32(), main(), run()

### Community 293 - "Community 293"
Cohesion: 0.47
Nodes (8): aabb(), fx(), main(), params(), tod(), todv(), v3(), wedge()

### Community 294 - "Community 294"
Cohesion: 0.47
Nodes (8): cases(), check(), compile(), diff_case(), main(), run(), same_result(), total_words()

### Community 295 - "Community 295"
Cohesion: 0.32
Nodes (5): ease(), foot(), interp(), Generate separate R6 clips from untouched full adapted bases. Requires Blender 5, Continuous velocity at footfall and toe-off; -Y movement during stance.

### Community 296 - "Community 296"
Cohesion: 0.39
Nodes (7): _append_stderr(), main(), _new_files_by_ext(), _process_stls(), Return {ext: [paths]} in script_dir matching each *.{ext}     (case-insensitive), Load each STL once and optionally render a preview + check watertightness., _sibling()

### Community 297 - "Community 297"
Cohesion: 0.25
Nodes (8): cupcake_fountain(), cupcake_liner(), orient(), pleated paper liner: frustum whose radius alternates in/out per pleat, two-colou, soft-serve swirl: a tube coiling up and in, SPAWN: giant cupcake in a cookie basin of strawberry milk; syrup arcs fall from, flip faces so normals point away from the vertical axis (lathe shells) / out of, swirl()

### Community 298 - "Community 298"
Cohesion: 0.25
Nodes (8): donut_arch(), drip(), a hanging icing drip: tapered neck from y 0 down to -length ending in a round be, one rod sprinkle (open-ended 5-sided rod, 10 tris), sprinkles lying on a surface: list of (point, normal), giant glazed donut standing on edge over the path, half sunk; glaze cap with dri, sprinkle(), sprinkles_on()

### Community 299 - "Community 299"
Cohesion: 0.32
Nodes (4): ClearBackend, ClearBackendSelection(), shutdown(), start()

### Community 300 - "Community 300"
Cohesion: 0.25
Nodes (8): barn(), coop(), fence_run(), picket fence segment along +X (0..L), front -Z: a slim honey post with an accent, the nest-coop (the plot's base building): stone plinth, cream plaster walls with, 2D poly [(x, up)] standing upright facing -Z, extruded d toward the front (-Z) f, backdrop red barn (seen from across the lake): stone plinth, red board walls wit, upright()

### Community 301 - "Community 301"
Cohesion: 0.25
Nodes (8): awning(), bait_bucket(), bait_shop(), loft(), striped canvas awning off a wall at z (front = -Z): slopes out `depth`, down `dr, quads between successive rings (lists of Vector, same count); closed = each ring, metal bait bucket with handle, worms (red tubes) and shrimp curls inside, BAIT SHOP (lime): round hut of upright bamboo staves, cone thatch (4 layers), cu

### Community 302 - "Community 302"
Cohesion: 0.25
Nodes (8): drying_rack(), _post(), rail_bay(), rail_post(), teak rail post with the signature cap: a teal glass float in a rope net on a col, SIGNATURE edge module: post at -L/2, two rope swags to +L/2 (next bay's post), s, fish drying rack: two bamboo A-frames, a top pole, lines of hanging fish, rope()

### Community 303 - "Community 303"
Cohesion: 0.32
Nodes (4): cos(), Fixed, sin(), sine_lookup()

### Community 304 - "Community 304"
Cohesion: 0.43
Nodes (7): analyse(), image_change(), luminance(), main(), Rank Godot graphics settings by frame-time cost against how much they change the, Full-scene GPU ms and noise floors for one view., view_baseline()

### Community 305 - "Community 305"
Cohesion: 0.39
Nodes (7): _build_bootstrap(), _frontmatter_value(), Return a flat ``key: value`` scalar from a SKILL.md frontmatter block.      Herm, Locate the stock skills/ tree for either supported install layout.      - git-cl, register(), _skills_dir(), _strip_frontmatter()

### Community 306 - "Community 306"
Cohesion: 0.32
Nodes (2): decode(), GoldenEncoderTests

### Community 307 - "Community 307"
Cohesion: 0.39
Nodes (6): constant_time_equal(), hmac_sha256(), pack_frame(), payload_bit_length(), Sha256, unpack_frame()

### Community 308 - "Community 308"
Cohesion: 0.39
Nodes (7): classify(), _find_textures(), _gltf_output_group(), Build a correct metal/rough PBR material from texture files or a measured preset, Map type from filename tokens, scanning from the end (suffixes win)., run(), _srgb_to_lin()

### Community 309 - "Community 309"
Cohesion: 0.43
Nodes (7): _fix(), _on_grid(), _pivot_target(), Validate modular kit pieces so they snap together: applied transforms, footprint, Apply rotation+scale, then move the origin to the pivot without moving the geome, run(), _texel_density()

### Community 310 - "Community 310"
Cohesion: 0.39
Nodes (7): _check(), _diff(), _poses(), Check that a cycle loops: the pose at the last frame equals the first (no pop),, Signed angular velocity a -> b (deg, as a vector) so direction reversals are vis, run(), _w()

### Community 311 - "Community 311"
Cohesion: 0.32
Nodes (3): Out, named groups -> uploaded meshes. solid groups use the palette; glow groups carry, a glow piece: uv on the white strip

### Community 312 - "Community 312"
Cohesion: 0.39
Nodes (7): build_tree(), _instances(), _layer_coll(), _on(), Biome scatter with Geometry Nodes: Poisson-disk instances of a collection on a s, Enabled socket by name: Random Value keeps one hidden Min/Max/Value per data typ, run()

### Community 313 - "Community 313"
Cohesion: 0.43
Nodes (7): _asset_group(), _ctx(), _num(), Set up and bake simulations: rigid bodies, classic cloth (presets), 5.2 node-bas, run(), _set_inputs(), _volume()

### Community 314 - "Community 314"
Cohesion: 0.43
Nodes (7): _area(), _backdrop(), _bounds(), _clear(), _fcurves(), Look-dev scene in one call: framed camera, light rig (studio 3-point / HDRI / bo, run()

### Community 315 - "Community 315"
Cohesion: 0.29
Nodes (2): flat(), ground()

### Community 316 - "Community 316"
Cohesion: 0.32
Nodes (5): Keyframe the hips ('spine', child of root) moving dist metres toward -Y over 24, _rig(), test_bake_to_copy_with_root_motion_and_export(), test_retarget_mixamo_to_rigify_names(), _walk()

### Community 317 - "Community 317"
Cohesion: 0.43
Nodes (6): _bands(), _clusters(), Distinct flat colors (8-bit rounding splits a band into near-identical values)., _scene(), test_toon_hull_bands_lineart_roundtrip(), test_toon_scene_lighting_eevee()

### Community 318 - "Community 318"
Cohesion: 0.39
Nodes (7): figure(), font(), frame(), main(), mask(), Contact-sheet hero for the README. One loop: a render closing on its reference., A small standing silhouette. Parameters are the things a bad first pass gets wro

### Community 319 - "Community 319"
Cohesion: 0.61
Nodes (7): arith(), cases(), check(), divzero(), imm(), main(), pay()

### Community 320 - "Community 320"
Cohesion: 0.54
Nodes (7): cases(), check(), depth_guard(), error(), main(), randomized_input(), tree()

### Community 321 - "Community 321"
Cohesion: 0.50
Nodes (7): cases(), check(), count_op(), i32t(), main(), run_source(), val()

### Community 322 - "Community 322"
Cohesion: 0.46
Nodes (7): main(), make_ktx2(), put32(), put64(), set32(), set64(), write()

### Community 323 - "Community 323"
Cohesion: 0.57
Nodes (7): cases(), check(), main(), parse_error(), randomized_input(), stress(), tree()

### Community 324 - "Community 324"
Cohesion: 0.54
Nodes (7): cases(), check(), has(), i32(), main(), v(), valid_module()

### Community 325 - "Community 325"
Cohesion: 0.57
Nodes (7): cases(), check(), depth_guard(), dump(), error(), main(), randomized_input()

### Community 326 - "Community 326"
Cohesion: 0.43
Nodes (6): check(), main(), make_token(), sample_ticket(), sign_input(), test_key()

### Community 327 - "Community 327"
Cohesion: 0.36
Nodes (7): _cross(), find_cross_mesh_overlaps(), intersection_area(), Test positive-area overlap between triangles belonging to different meshes.  Sha, Return the UV area common to two triangles, independent of winding., Input: iterable of (mesh_name, triangle of three (u,v) pairs).      Returns coun, _signed_area()

### Community 328 - "Community 328"
Cohesion: 0.29
Nodes (5): assert, crypto, path, SERVER_PATH, RFC-6455

### Community 329 - "Community 329"
Cohesion: 0.43
Nodes (4): dot(), length(), lengthSquared(), normalized()

### Community 330 - "Community 330"
Cohesion: 0.33
Nodes (3): AccountStore, InMemoryAccountStore, SignInService

### Community 331 - "Community 331"
Cohesion: 0.29
Nodes (2): FirebaseTokenVerifier, SessionTickets

### Community 332 - "Community 332"
Cohesion: 0.29
Nodes (1): BitBuffer

### Community 333 - "Community 333"
Cohesion: 0.43
Nodes (5): attach_parity(), losses(), make_parity(), recover_loss(), xor_payloads()

### Community 334 - "Community 334"
Cohesion: 0.43
Nodes (4): inner_position(), parse_import_spec(), resolve_packages(), unquote()

### Community 335 - "Community 335"
Cohesion: 0.52
Nodes (6): _assign(), list_actions(), _mute(), Bake animation clips from a control rig onto an export skeleton (visual keying),, _root_motion(), run()

### Community 336 - "Community 336"
Cohesion: 0.48
Nodes (6): gather(), inventory(), load(), _module(), Batch over many files in one Blender process: convert formats, inventory report,, run()

### Community 337 - "Community 337"
Cohesion: 0.43
Nodes (6): _gaps(), _grid(), _material(), Mesh decal that conforms to a surface without z-fighting: a subdivided plane pla, World distance to the target at every evaluated triangle's centroid and corners-, run()

### Community 338 - "Community 338"
Cohesion: 0.43
Nodes (6): _find(), Create a QA_Stress action with extreme poses to review deformation (elbows, knee, Rotate a pose bone about a WORLD axis through its head (rig-agnostic: ignores bo, _rotate(), run(), _side()

### Community 339 - "Community 339"
Cohesion: 0.43
Nodes (6): _islands(), _measure(), Measure (and optionally set) texel density in px/m for objects' active UV map., UV islands as lists of faces (connected through shared UV coords)., run(), _uv_area()

### Community 340 - "Community 340"
Cohesion: 0.43
Nodes (6): _add_clip(), _frames(), _output(), Assemble a video edit in the Video Sequencer headless: movies (with their audio), Sorted frame files for a folder or a # pattern, else None., run()

### Community 341 - "Community 341"
Cohesion: 0.43
Nodes (4): look_at(), multiply(), perspective(), view_proj()

### Community 342 - "Community 342"
Cohesion: 0.57
Nodes (6): decode(), decode_item(), fail(), half_to_double(), read_argument(), valid_utf8()

### Community 343 - "Community 343"
Cohesion: 0.43
Nodes (4): cpu_ms(), fps(), gpu_ms(), window_mean()

### Community 344 - "Community 344"
Cohesion: 0.57
Nodes (6): fail(), finite_vec3(), load_pokomesh(), parse_pokomesh(), read_f32(), read_u32()

### Community 345 - "Community 345"
Cohesion: 0.48
Nodes (5): hash_state(), merge(), read32(), read64(), xxhash64()

### Community 346 - "Community 346"
Cohesion: 0.38
Nodes (5): Execute every ```python block of a reference doc on a fresh scene., Any reference doc tagged '(runs standalone)' must execute cleanly., _run_md_blocks(), test_bpy_patterns_snippets_run(), test_snippet_docs_across_skills()

### Community 347 - "Community 347"
Cohesion: 0.52
Nodes (5): compare(), load_corpus(), load_trace(), main(), _read()

### Community 348 - "Community 348"
Cohesion: 0.57
Nodes (6): len_d(), main(), naive_dot(), naive_in_range(), raw3(), v3()

### Community 349 - "Community 349"
Cohesion: 0.57
Nodes (6): check(), deterministic_streams(), diagnostic(), examples(), main(), tokens()

### Community 350 - "Community 350"
Cohesion: 0.38
Nodes (3): draw_and_present(), main(), reset()

### Community 351 - "Community 351"
Cohesion: 0.33
Nodes (4): Design briefs (vfx/briefs/<ID>.json) live outside the strict Effekseer layer sch, Absolute first/last births, including parent emission intervals and random life., timeline(), validate()

### Community 352 - "Community 352"
Cohesion: 0.43
Nodes (6): main(), parser(), effekseer-vfx command line: one JSON object on stdout per command; progress and, (selected, context, unloaded): with --ids only the named sources must load; a fu, recipes_for(), run()

### Community 353 - "Community 353"
Cohesion: 0.38
Nodes (6): download(), initialize(), Create or refresh the project's vfx/ workspace from the skill's Lab template and, Serialise downloads into the shared EFFEKSEER_VFX_HOME across projects and proce, A verified copy of `url` at `target`: downloaded to a private temporary file, ch, toolchain_lock()

### Community 354 - "Community 354"
Cohesion: 0.48
Nodes (5): fit(), fit_bad(), _inb(), _inside_one(), _top()

### Community 355 - "Community 355"
Cohesion: 0.38
Nodes (6): forklift(), pallet_jack(), electric counterbalance forklift: yellow body, rounded counterweight, overhead g, tyre + rim + hub nuts, axle along x, centre c, outer face toward side (+1 = +x), hand pallet truck: twin forks, pump body, tiller handle (forks toward -z), wheel()

### Community 356 - "Community 356"
Cohesion: 0.33
Nodes (2): MYTOOL_AP_preferences, MYTOOL_PT_main

### Community 357 - "Community 357"
Cohesion: 0.40
Nodes (2): interp(), smooth()

### Community 358 - "Community 358"
Cohesion: 0.47
Nodes (5): download_or_get_cached(), get_perfetto_prebuilt(), Downloads a prebuilt or returns a cached version    The first time this is invok, Downloads the prebuilt, if necessary, and returns its path on disk., run_perfetto_prebuilt()

### Community 359 - "Community 359"
Cohesion: 0.47
Nodes (5): FailingPrimaryBackend, linear_to_srgb_byte(), main(), report_pixel(), rhi::ClearBackend

### Community 360 - "Community 360"
Cohesion: 0.60
Nodes (4): Java_com_poko_glesclear_PokoActivity_nativeInit(), Java_com_poko_glesclear_PokoActivity_nativeSetSurface(), run_probe(), write_line()

### Community 361 - "Community 361"
Cohesion: 0.33
Nodes (2): VulkanDiagnostics, VulkanImGuiPass()

### Community 368 - "Community 368"
Cohesion: 0.47
Nodes (5): first_difference(), main(), Return the first differing offset and sizes, or None if files match., Replace the reference atomically, only on an explicit update request., update_golden()

### Community 370 - "Community 370"
Cohesion: 0.33
Nodes (2): AssetHandle, AssetStore

### Community 371 - "Community 371"
Cohesion: 0.40
Nodes (5): convert_pb_to_json(), main(), Converts R8 keep radius protobuf files into JSON format., Reads an R8 BlastRadiusContainer protobuf and writes it as JSON., Entry point for CLI execution.

### Community 372 - "Community 372"
Cohesion: 0.40
Nodes (6): bevel(), box(), cyl(), ngon_prism(), poly = [(x, z), ...] counter-clockwise seen from above (+Y); extruded y0..y1, to, vertical prism / frustum from y0 to y0 + h

### Community 373 - "Community 373"
Cohesion: 0.33
Nodes (6): clip_fn(), clip_half(), clip_rect(), jittered-grid Voronoi cells clipped to the rectangle: list of (site, polygon[(x,, keep the side of the bisector of s-o closer to s, voronoi_cells()

### Community 374 - "Community 374"
Cohesion: 0.53
Nodes (5): _co(), _get(), _keys(), Shape-key toolkit for faces: create ARKit-52 / viseme sets, split symmetric keys, run()

### Community 375 - "Community 375"
Cohesion: 0.47
Nodes (5): _collapsed_ratio(), Unwrap + pack UVs with production defaults; optional seams-from-sharp and lightm, Fraction of faces whose UV area is ~0 (failed unwrap)., run(), _seams_from_sharp()

### Community 376 - "Community 376"
Cohesion: 0.60
Nodes (5): append_le(), load_state_snapshot(), read_le(), save_state_snapshot(), schema_for()

### Community 377 - "Community 377"
Cohesion: 0.47
Nodes (3): _mean_luma(), _render(), test_night_renders_darker_than_noon()

### Community 379 - "Community 379"
Cohesion: 0.47
Nodes (4): 1 m block with a 0.5 m step on top (convex outer edges + one concave inner edge), _stepped_block(), test_smart_material_bakes_to_texture(), test_smart_material_curvature_and_roundtrip()

### Community 380 - "Community 380"
Cohesion: 0.40
Nodes (2): _instances(), test_precipitation_loops_and_stops_on_ground()

### Community 381 - "Community 381"
Cohesion: 0.47
Nodes (3): main(), reset(), write_spirv()

### Community 382 - "Community 382"
Cohesion: 0.73
Nodes (5): check(), error(), main(), test_cases(), unicode_conformance()

### Community 383 - "Community 383"
Cohesion: 0.67
Nodes (5): main(), make_pmes(), put32(), putf(), write()

### Community 385 - "Community 385"
Cohesion: 0.47
Nodes (5): doctor(), What this machine can do right now. Standard library only, so it runs before set, What setup.sh (setup.ps1 on Windows) would use for the toolchain: uv, else a Pyt, setup_python(), version()

### Community 386 - "Community 386"
Cohesion: 0.47
Nodes (3): cancel(), find(), run()

### Community 387 - "Community 387"
Cohesion: 0.47
Nodes (3): fail(), step(), VmCore

### Community 388 - "Community 388"
Cohesion: 0.53
Nodes (4): combineGraphs(), extractDotBlocks(), main(), renderToSvg()

### Community 389 - "Community 389"
Cohesion: 0.50
Nodes (2): MYTOOL_OT_offset_selected, Move selected objects along an axis

### Community 390 - "Community 390"
Cohesion: 0.40
Nodes (1): DurationQueryState

### Community 392 - "Community 392"
Cohesion: 0.40
Nodes (4): ClientData, ClientMessage, Optional Linux/X11 host smoke test; not a Windows or Android test.  Usage: DISPL, XEvent

### Community 393 - "Community 393"
Cohesion: 0.70
Nodes (4): calculate(), deterministic_cos(), deterministic_sin(), supported()

### Community 394 - "Community 394"
Cohesion: 0.40
Nodes (2): Ast, ExpressionParser

### Community 395 - "Community 395"
Cohesion: 0.60
Nodes (4): build(), _overlay(), _panel(), Side-by-side diagnostic sheet.  Metrics tell you the score. This tells you what

### Community 396 - "Community 396"
Cohesion: 0.70
Nodes (4): _apply_all(), _ctx(), Make a low-poly retopo copy of a dense mesh (sculpt/scan/AI-generated) at a tria, run()

### Community 397 - "Community 397"
Cohesion: 0.60
Nodes (4): bbox(), concept_mask(), main(), Overlay a render's silhouette on a concept view to check proportions 1:1. py com

### Community 398 - "Community 398"
Cohesion: 0.50
Nodes (4): cleanup(), Generate an LOD chain (<name>_LOD1..N) with Decimate, preserving UV seams/normal, Merge by distance, dissolve degenerate, delete loose. Returns removed vert count, run()

### Community 399 - "Community 399"
Cohesion: 0.60
Nodes (4): ffmpeg(), main(), outline(), Post-process renders from studlib.py: black SILHOUETTE outline (like a Roblox Hi

### Community 400 - "Community 400"
Cohesion: 0.40
Nodes (4): clamp(), lerp(), nz(), smooth()

### Community 401 - "Community 401"
Cohesion: 0.60
Nodes (4): _frames(), _gpu(), Render stills/animations with quality presets, per-camera batches, any output fo, run()

### Community 402 - "Community 402"
Cohesion: 0.70
Nodes (4): _apply(), _ctx(), Headless-safe sculpt preparation and procedural "sculpt" ops (no Sculpt Mode - i, run()

### Community 403 - "Community 403"
Cohesion: 0.60
Nodes (4): _clip_area(), Automatic camera solve from footage: detect features at the start and end of the, run(), _solve()

### Community 404 - "Community 404"
Cohesion: 0.50
Nodes (2): test_scatter_respects_slope_height_and_realize(), _trees()

### Community 405 - "Community 405"
Cohesion: 0.50
Nodes (2): _reimport_dims(), test_all_presets_roundtrip_scale()

### Community 408 - "Community 408"
Cohesion: 0.60
Nodes (3): _grid(), test_classic_cloth_drapes_on_collider(), test_gn_cloth_52_asset()

### Community 410 - "Community 410"
Cohesion: 0.70
Nodes (4): check(), def(), main(), run_err()

### Community 411 - "Community 411"
Cohesion: 0.70
Nodes (4): check(), compile_recursion(), main(), run_recursion()

### Community 412 - "Community 412"
Cohesion: 0.70
Nodes (4): cases(), expect_error(), expect_ok(), main()

### Community 413 - "Community 413"
Cohesion: 0.80
Nodes (4): box(), lo(), main(), sorted_pairs()

### Community 414 - "Community 414"
Cohesion: 0.70
Nodes (4): cases(), check(), fin(), main()

### Community 415 - "Community 415"
Cohesion: 0.70
Nodes (4): cases(), error(), main(), ok()

### Community 416 - "Community 416"
Cohesion: 0.50
Nodes (4): handoff(), Everything an independent reviewer needs for one capture, as a prompt the author, The vfx-review skill installed next to this one (both folders are installed side, reviewer_skill()

### Community 417 - "Community 417"
Cohesion: 0.70
Nodes (4): audit(), cell_report(), content(), Pixel observations grouped by texture role; stylistic warnings are not build fai

### Community 418 - "Community 418"
Cohesion: 0.70
Nodes (4): add(), find(), host_type(), unauthorized_hostcalls()

### Community 419 - "Community 419"
Cohesion: 0.50
Nodes (2): assert, {
  browserLauncherForPlatform
}

### Community 420 - "Community 420"
Cohesion: 0.50
Nodes (2): Discover editable leaf paths without walking parent/tree references., Discover parameters grouped as they are in the editor's setting panels.

### Community 421 - "Community 421"
Cohesion: 0.83
Nodes (3): count_stamps(), main(), read_file()

### Community 422 - "Community 422"
Cohesion: 0.50
Nodes (2): DeclarationAst, DeclarationParser

### Community 423 - "Community 423"
Cohesion: 0.50
Nodes (2): StatementAst, StatementParser

### Community 424 - "Community 424"
Cohesion: 1.00
Nodes (3): head(), make_pkb_schema_draft(), text()

### Community 425 - "Community 425"
Cohesion: 0.67
Nodes (3): Build (and optionally apply) a production hard-surface modifier stack.  Presets:, run(), _smooth_faces()

### Community 426 - "Community 426"
Cohesion: 0.67
Nodes (3): _gpu(), Report Blender version, engines, GPU, add-ons, units and scene stats as JSON.  U, run()

### Community 427 - "Community 427"
Cohesion: 0.67
Nodes (3): Budget report: tris/verts per object, materials (draw calls), textures + VRAM, v, run(), _vram()

### Community 428 - "Community 428"
Cohesion: 0.50
Nodes (4): frames(), parallel-transport frames along a polyline (Vectors), swept polygon along pts; radii scalar or list; rough = random ring radius jitter, tube()

### Community 429 - "Community 429"
Cohesion: 0.50
Nodes (4): hull(), points on a lumpy ellipsoid (radii r = (rx, ry, rz)); flat = cut the bottom at -, rock(), rock_pts()

### Community 430 - "Community 430"
Cohesion: 0.50
Nodes (3): make_obj(), mesh in Blender space, origin = bbox centre; returns the part record (Roblox spa, split()

### Community 431 - "Community 431"
Cohesion: 0.67
Nodes (3): _bounds(), Render a multi-angle review contact sheet (headless-safe Workbench) for visual Q, run()

### Community 432 - "Community 432"
Cohesion: 0.67
Nodes (3): _mirror(), Validate a skeleton + its skinned meshes for animation/engine export; optional s, run()

### Community 433 - "Community 433"
Cohesion: 0.67
Nodes (2): find_blender(), main()

### Community 434 - "Community 434"
Cohesion: 0.67
Nodes (3): _apply_rot_scale(), Audit scene hygiene: units, transforms, naming, collections, materials, images,, run()

### Community 435 - "Community 435"
Cohesion: 0.67
Nodes (2): pair(), pill()

### Community 436 - "Community 436"
Cohesion: 0.83
Nodes (3): fail(), in_bounds(), load_ktx2()

### Community 437 - "Community 437"
Cohesion: 0.83
Nodes (3): _pixels(), test_high_to_low_bake_normal_ao_curv_orm_basecolor(), test_self_bake_procedural_roughness()

### Community 438 - "Community 438"
Cohesion: 0.83
Nodes (3): _head(), test_groom_attached_masked_with_assets(), test_hair_cards_and_atlas()

### Community 439 - "Community 439"
Cohesion: 0.67
Nodes (2): _img(), test_texture_set_autowire_orm_dx_normal()

### Community 440 - "Community 440"
Cohesion: 0.67
Nodes (2): _camera(), test_render_stills_cycles_eevee_workbench()

### Community 441 - "Community 441"
Cohesion: 0.83
Nodes (3): main(), near(), transform()

### Community 442 - "Community 442"
Cohesion: 0.83
Nodes (3): dyn_sphere(), main(), static_box()

### Community 443 - "Community 443"
Cohesion: 0.67
Nodes (3): air(), build_dist(), signed distance (studs) to the cave wall at floor level: + inside the air, - ins

### Community 444 - "Community 444"
Cohesion: 1.00
Nodes (2): capture(), floats()

### Community 445 - "Community 445"
Cohesion: 1.00
Nodes (2): counting_loader(), main()

### Community 446 - "Community 446"
Cohesion: 1.00
Nodes (2): check(), main()

### Community 447 - "Community 447"
Cohesion: 1.00
Nodes (2): main(), near()

### Community 448 - "Community 448"
Cohesion: 1.00
Nodes (2): checksum(), main()

### Community 450 - "Community 450"
Cohesion: 1.00
Nodes (2): light(), r2b()

### Community 451 - "Community 451"
Cohesion: 0.67
Nodes (1): IPlatform

### Community 452 - "Community 452"
Cohesion: 0.67
Nodes (1): Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).  Run:

### Community 453 - "Community 453"
Cohesion: 0.67
Nodes (1): Adapt BoyR6 for PokoX.  Fixes:   1. Head shading: collapse the dead customFaces

### Community 454 - "Community 454"
Cohesion: 0.67
Nodes (1): Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876.

### Community 455 - "Community 455"
Cohesion: 1.00
Nodes (2): a flat strip on the ground following pts (x, y, z); widths per point, ribbon()

### Community 456 - "Community 456"
Cohesion: 1.00
Nodes (2): a surface between a front curve z = zf(x) and a back curve zb(x) (quad strip ove, strip_surface()

## Knowledge Gaps
- **1009 isolated node(s):** `Parametric human blockout from measured sheet fractions.  Every dimension is a f`, `Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry.`, `Print measured bounds so the comparison step has numbers, not vibes.`, `Explorer character — pass 2: garments, equipment, hair, materials.  Reads the me`, `Duplicate meshes then scale about a pivot — cheap garment offset.` (+1004 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **Thin community `Community 79`** (1 nodes): `Layer compiler, Core round trips, texture processing, recipe primitives and the`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 155`** (2 nodes): `EvidenceTests`, `Evidence handling tests, not real SDK or GPU acceptance.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 170`** (2 nodes): `GoldenHarnessTests`, `run()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 218`** (1 nodes): `TraceTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 240`** (2 nodes): `test_ablation_verdicts()`, `_write_ablation()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 261`** (2 nodes): `finish hero: 1-2-3 podium + a giant cylinder-built trophy (base, stem, flared cu`, `trophy()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 270`** (2 nodes): `hash()`, `mix()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 276`** (2 nodes): `OverlapTests`, `Regression tests independent of Blender: python test_uv_overlap.py.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 283`** (2 nodes): `SQLite-level tests for the D1 word-reservation migration.`, `ReservationMigrationTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 290`** (2 nodes): `mesh_io must not pull in pyrender (it's the whole point of the split).`, `test_load_mesh_no_pyrender_import()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 306`** (2 nodes): `decode()`, `GoldenEncoderTests`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 315`** (2 nodes): `flat()`, `ground()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 331`** (2 nodes): `FirebaseTokenVerifier`, `SessionTickets`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 332`** (1 nodes): `BitBuffer`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 356`** (2 nodes): `MYTOOL_AP_preferences`, `MYTOOL_PT_main`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 357`** (2 nodes): `interp()`, `smooth()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 361`** (2 nodes): `VulkanDiagnostics`, `VulkanImGuiPass()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 370`** (2 nodes): `AssetHandle`, `AssetStore`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 380`** (2 nodes): `_instances()`, `test_precipitation_loops_and_stops_on_ground()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 389`** (2 nodes): `MYTOOL_OT_offset_selected`, `Move selected objects along an axis`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 390`** (1 nodes): `DurationQueryState`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 394`** (2 nodes): `Ast`, `ExpressionParser`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 404`** (2 nodes): `test_scatter_respects_slope_height_and_realize()`, `_trees()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 405`** (2 nodes): `_reimport_dims()`, `test_all_presets_roundtrip_scale()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 419`** (2 nodes): `assert`, `{
  browserLauncherForPlatform
}`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 420`** (2 nodes): `Discover editable leaf paths without walking parent/tree references.`, `Discover parameters grouped as they are in the editor's setting panels.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 422`** (2 nodes): `DeclarationAst`, `DeclarationParser`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 423`** (2 nodes): `StatementAst`, `StatementParser`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 433`** (2 nodes): `find_blender()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 435`** (2 nodes): `pair()`, `pill()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 439`** (2 nodes): `_img()`, `test_texture_set_autowire_orm_dx_normal()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 440`** (2 nodes): `_camera()`, `test_render_stills_cycles_eevee_workbench()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 444`** (2 nodes): `capture()`, `floats()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 445`** (2 nodes): `counting_loader()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 446`** (2 nodes): `check()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 447`** (2 nodes): `main()`, `near()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 448`** (2 nodes): `checksum()`, `main()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 450`** (2 nodes): `light()`, `r2b()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 451`** (1 nodes): `IPlatform`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 452`** (1 nodes): `Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).  Run:`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 453`** (1 nodes): `Adapt BoyR6 for PokoX.  Fixes:   1. Head shading: collapse the dead customFaces`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 454`** (1 nodes): `Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876.`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 455`** (2 nodes): `a flat strip on the ground following pts (x, y, z); widths per point`, `ribbon()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.
- **Thin community `Community 456`** (2 nodes): `a surface between a front curve z = zf(x) and a back curve zb(x) (quad strip ove`, `strip_surface()`
  Too small to be a meaningful cluster - may be noise or needs more connections extracted.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `Palette` connect `Community 2` to `Community 135`, `Community 136`, `Community 162`, `Community 278`, `Community 137`, `Community 161`, `Community 298`, `Community 297`, `Community 16`, `Community 21`, `Community 3`, `Community 117`, `Community 225`, `Community 124`, `Community 123`, `Community 146`, `Community 226`, `Community 186`, `Community 207`, `Community 300`, `Community 174`, `Community 196`, `Community 280`, `Community 125`, `Community 253`, `Community 118`, `Community 197`, `Community 126`, `Community 252`, `Community 78`, `Community 301`, `Community 302`, `Community 187`, `Community 12`, `Community 29`, `Community 255`, `Community 213`, `Community 212`, `Community 230`, `Community 211`, `Community 128`, `Community 284`, `Community 149`, `Community 139`, `Community 129`, `Community 175`, `Community 199`, `Community 231`, `Community 260`, `Community 42`, `Community 179`, `Community 311`, `Community 31`, `Community 23`, `Community 40`, `Community 5`, `Community 11`, `Community 57`?**
  _High betweenness centrality (0.144) - this node is a cross-community bridge._
- **Why does `MB` connect `Community 15` to `Community 25`, `Community 24`, `Community 443`, `Community 20`, `Community 32`, `Community 26`, `Community 55`, `Community 19`, `Community 67`, `Community 33`, `Community 27`, `Community 35`, `Community 22`, `Community 96`, `Community 215`, `Community 179`, `Community 311`, `Community 430`, `Community 38`, `Community 151`, `Community 28`, `Community 8`, `Community 41`, `Community 102`, `Community 63`, `Community 12`, `Community 2`?**
  _High betweenness centrality (0.049) - this node is a cross-community bridge._
- **Why does `EffectSession` connect `Community 34` to `Community 195`, `Community 147`, `Community 72`, `Community 1`, `Community 420`?**
  _High betweenness centrality (0.013) - this node is a cross-community bridge._
- **Are the 622 inferred relationships involving `Palette` (e.g. with `cotton-candy tree: twisting pretzel trunk with 3 limbs, each holding a fluffy ma` and `3-5 sugar-coated gumdrops of different colours clustered on the ground (true gum`) actually correct?**
  _`Palette` has 622 INFERRED edges - model-reasoned connections that need verification._
- **Are the 187 inferred relationships involving `MB` (e.g. with `trails, plazas, river, castle hill, falls: nothing scattered there` and `one board tile: the polyline section s0..s1 (arc length) across `width`, draped`) actually correct?**
  _`MB` has 187 INFERRED edges - model-reasoned connections that need verification._
- **What connects `Parametric human blockout from measured sheet fractions.  Every dimension is a f`, `Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry.`, `Print measured bounds so the comparison step has numbers, not vibes.` to the rest of the system?**
  _1009 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.00858276235124414 - nodes in this community are weakly interconnected._