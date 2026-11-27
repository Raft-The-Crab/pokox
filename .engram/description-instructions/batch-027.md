# Node Description Batch 28 of 207

Engram is running in assistant/skill mode (no API key). You are the host
assistant (Claude Code / Codex / Gemini CLI). Read the prompt below and write
your JSON answer to the answer file.

## Prompt

You are documenting nodes in a knowledge graph.
For each entry below, write ONE concise factual plain-language sentence
describing what it is or does. Use only the provided context.
For a code symbol (kind=code-symbol — a function, class, or constant),
describe what the function/symbol does based on its name, source location
and neighbors — e.g. "Resolves the configured ontology profile from graphify.yaml.".
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "moonclean_moon_map_ramp_w": "ramp_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L96 | neighbors=[moon_map.py, ground_shade(), H(), adiff(), ramp_half_len(), weight 0..1 of ramp k at (r, a) and the…]
- "moonclean_moon_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L183 | neighbors=[moon_map.py, crater_ramp(), craters(), hub(), scatter(), zone()]
- "moonclean_moon_map_zone_of": "zone_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L126 | neighbors=[moon_map.py, _crater_ok(), craters(), ground_shade(), H(), zone()]
- "moonclean_moon_props_gear_locker": "gear_locker()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L210 | neighbors=[moon_props.py, lathe(), station_base(), torus(), vac_pack(), SHOP: curved white locker wall with 3 v…]
- "moonclean_moon_props_moon_rover": "moon_rover()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L539 | neighbors=[moon_props.py, beam(), dish(), torus(), wheel(), abandoned lunar rover: tube chassis, 4 …]
- "mute_values": "values.hpp" | kind=code-symbol | source=mute/include/poko/mute/values.hpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, 5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, AggregateStore]
- "net_bit_buffer": "bit_buffer.hpp" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, BitBuffer, get_array(), get_delta(), put_array(), put_delta()]
- "net_crypto_aead_aead_seal": "aead_seal()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L219 | neighbors=[crypto_aead.hpp, chacha20_block(), chacha20_xor(), poly1305_mac(), store32_le(), store64_le()]
- "net_crypto_aead_chacha20_block": "chacha20_block()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L58 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), load32_le(), qr(), chacha20_xor()]
- "net_crypto_aead_store32_le": "store32_le()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L37 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), chacha20_xor(), poly1305_mac(), store64_le()]
- "oaktrees_gen_trees_branch": "Branch" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L331 | neighbors=[gen_trees.py, .at(), .__init__(), .length(), .grow(), .grow_roots()]
- "oaktrees_gen_trees_canvas_capsule_path": ".capsule_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L131 | neighbors=[Canvas, .grid(), .over(), leaf_atlas(), needle_atlas(), Tapered stroke along pts (px), clipped …]
- "oaktrees_gen_trees_card_quads": "card_quads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L549 | neighbors=[gen_trees.py, .at(), .length(), rand_unit(), .env(), Leaf-cluster cards (folded, 4 tris) or …]
- "oaktrees_gen_trees_fft_noise": "fft_noise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L33 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), leaf_atlas(), Periodic (tileable) gaussian-filtered n…]
- "oaktrees_gen_trees_leaf_atlas": "leaf_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L270 | neighbors=[gen_trees.py, Canvas, .capsule_path(), .finish(), .leaf(), fft_noise()]
- "oaktrees_gen_trees_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1038 | neighbors=[gen_trees.py, contact_sheet(), export_glb(), make_tree(), render_turntable(), setup_scene()]
- "oaktrees_gen_trees_tree_children_of": ".children_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L380 | neighbors=[Tree, .build(), .at(), .length(), .env(), .grow()]
- "oaktrees_gen_trees_tree_laterals": ".laterals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L474 | neighbors=[paired side sprays in the (roughly hori…, Tree, .build_conifer(), .at(), .length(), .grow()]
- "onsenvillage_onsen_map_village": "village()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L358 | neighbors=[onsen_map.py, build(), mirror(), place(), rail_run(), reserve()]
- "onsenvillage_onsen_props_flared_roof": "flared_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L47 | neighbors=[onsen_props.py, hip_roof(), pagoda(), Asian glazed roof: a lofted surface fro…, skirt_roof(), toro()]
- "onsenvillage_onsen_props_hip_roof": "hip_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L104 | neighbors=[onsen_props.py, bath_pavilion(), flared_roof(), house(), noodle_stall(), rectangular hip roof over a hw x hd (ha…]
- "opencode_test_hook_registration": "test-hook-registration.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-hook-registration.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, captureHooks(), event(), pluginURL, session()]
- "petsim_pet_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L202 | neighbors=[pet_map.py, breakables(), egg_stand(), hub(), link(), zone_bounds()]
- "petsim_pet_map_edge_pt": "edge_pt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L281 | neighbors=[pet_map.py, build(), isle_R(), fence_ring(), hub(), link()]
- "petsim_pet_map_isle_at": "isle_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L43 | neighbors=[pet_map.py, breakables(), H(), isle_R(), polar(), place_soft()]
- "petsim_pet_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L178 | neighbors=[pet_map.py, build(), clip_fail(), isle_at(), place(), unplace()]
- "petsim_pet_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L453 | neighbors=[pet_map.py, candy(), crystal(), meadow(), egg_stand(), path()]
- "petsim_pet_map_zone_bounds": "zone_bounds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L375 | neighbors=[pet_map.py, candy(), crystal(), hub(), meadow(), anchor()]
- "petsim_pet_props_egg_stand": "egg_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L566 | neighbors=[pet_props.py, egg(), puff(), rcyl(), soft(), fluted cake pedestal with a glowing rin…]
- "petsim_pet_props_fence": "fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1005 | neighbors=[pet_props.py, ell(), rbox(), rcyl(), soft(), chunky rail fence segment from x = 0 to…]
- "petsim_pet_props_lollipop": "lollipop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L892 | neighbors=[pet_props.py, ell(), flat(), rcyl(), soft(), giant swirl lollipop: two interleaved c…]
- "petsim_pet_props_paw": "paw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L127 | neighbors=[pet_props.py, ell(), soft(), paw-print icon: palm pad + 4 toe beans,…, spawn_pad(), zone_gate()]
- "petsim_pet_props_pet_shop": "pet_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L357 | neighbors=[pet_props.py, ell(), pill(), rcyl(), soft(), open-front kiosk: round dais, curved ba…]
- "petsim_pet_props_pet_statue": "pet_statue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L323 | neighbors=[pet_props.py, ell(), puff(), puffpaw(), soft(), the Puffpaw statue + its quilted cushio…]
- "petsim_pet_props_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L119 | neighbors=[pet_props.py, rainbow_arch(), a chunky star standing upright facing -…, star_poly(), star_lamp(), upgrade_machine()]
- "petsim_pet_props_trade_booth": "trade_booth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L486 | neighbors=[pet_props.py, round trade table with a big scalloped …, ell(), rbox(), rcyl(), soft()]
- "petsim_pet_props_vsh": "vsh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L47 | neighbors=[pet_props.py, bridge(), coin_pile(), flat(), pet_fountain(), soft()]
- "plusspeed_plus_map_dress_caps": "dress_caps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L88 | neighbors=[plus_map.py, place(), finish(), hub(), put theme props on cap tops (centre of …, zone()]
- "plusspeed_plus_map_finish": "finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L192 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]
- "plusspeed_plus_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L160 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-027.json

Keep each description factual and concise (one sentence). No markdown, no prose
outside the JSON object. It is acceptable to omit a node if context is
insufficient — but include every node you can ground confidently.

Example answer format:
```json
{
  "node_id_1": "Resolves the configured ontology profile from graphify.yaml.",
  "node_id_2": "Colonel James Barclay, an antagonist in The Crooked Man."
}
```
