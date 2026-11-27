# Node Description Batch 37 of 207

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

- "moonclean_moon_props_comms_dish": "comms_dish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L610 | neighbors=[moon_props.py, beam(), dish(), torus(), hub antenna: big dish on a yoke, turret…]
- "moonclean_moon_props_egg_incubator": "egg_incubator()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L269 | neighbors=[moon_props.py, egg(), station_base(), torus(), PETS: console with a screen, 3 cryo cag…]
- "moonclean_moon_props_floodlight": "floodlight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L592 | neighbors=[moon_props.py, beam(), lathe(), torus(), hub floodlight mast: tripod foot, taper…]
- "moonclean_moon_props_port": "port()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L101 | neighbors=[moon_props.py, moon_rocket(), torus(), round port window: steel frame ring + r…, reentry_pod()]
- "moonclean_moon_props_vac_pack": "vac_pack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L198 | neighbors=[moon_props.py, gear_locker(), vacuum backpack: twin tanks, frame, dus…, lathe(), torus()]
- "namedtuple": "NamedTuple" | kind=code-symbol | neighbors=[_Compartments, _CylinderPocket, _Notch, _Pocket, _PolygonPocket]
- "net_crypto_aead_chacha20_xor": "chacha20_xor()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L81 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), chacha20_block(), store32_le()]
- "net_crypto_aead_poly1305_mac": "poly1305_mac()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L93 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), load32_le(), store32_le()]
- "net_delta": "delta.hpp" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, decode_delta(), DeltaSchema, encode_delta(), ResendWindow]
- "net_ws_transport": "ws_transport.hpp" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, ws_decode(), ws_encode_client(), ws_encode_server(), ws_roundtrip()]
- "oaktrees_gen_trees_bark_fir": "bark_fir()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L100 | neighbors=[gen_trees.py, fft_noise(), normal_from_height(), ramp(), fir / spruce: scaly grey-brown plates w…]
- "oaktrees_gen_trees_branch_length": ".length()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L343 | neighbors=[Branch, card_quads(), conifer_cards(), .children_of(), .laterals()]
- "oaktrees_gen_trees_canvas_finish": ".finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L186 | neighbors=[Canvas, normal_from_height(), leaf_atlas(), needle_atlas(), twig_atlas()]
- "oaktrees_gen_trees_conifer_cards": "conifer_cards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L619 | neighbors=[gen_trees.py, .at(), .length(), rand_unit(), needle-spray cards along every branch /…]
- "oaktrees_gen_trees_get_materials": "get_materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L991 | neighbors=[gen_trees.py, _img(), material(), make_tree(), Trunk / Branches / Leaves materials for…]
- "oaktrees_gen_trees_needle_atlas": "needle_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L210 | neighbors=[gen_trees.py, Canvas, .capsule_path(), .finish(), 4 x 4 fir sprays: a central twig with p…]
- "oaktrees_gen_trees_normal_from_height": "normal_from_height()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L42 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), .finish()]
- "oaktrees_gen_trees_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L66 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), t array -> colour from [(pos, (r,g,b)),…]
- "oaktrees_gen_trees_rand_unit": "rand_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L346 | neighbors=[gen_trees.py, card_quads(), conifer_cards(), .grow(), .grow_roots()]
- "oaktrees_gen_trees_tree_build_conifer": ".build_conifer()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L450 | neighbors=[Tree, .build(), .at(), .grow(), .laterals()]
- "oaktrees_gen_trees_tree_grow_roots": ".grow_roots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L426 | neighbors=[surface roots: leave the trunk foot out…, Tree, .build(), Branch, rand_unit()]
- "onsenvillage_onsen_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L119 | neighbors=[onsen_map.py, add_owner(), look(), nature(), steam()]
- "onsenvillage_onsen_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L194 | neighbors=[onsen_map.py, build(), mountains(), static(), stage ground (smooth: banks, stream bed…]
- "onsenvillage_onsen_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L120 | neighbors=[onsen_map.py, build(), nature(), stories(), village()]
- "onsenvillage_onsen_map_stories": "stories()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L409 | neighbors=[onsen_map.py, build(), clusters of 2-4 at the stairs and bridg…, place(), reserve()]
- "onsenvillage_onsen_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L263 | neighbors=[onsen_map.py, build(), stream + front pool surface: 4-stud cel…, H(), static()]
- "onsenvillage_onsen_props_balcony": "balcony()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L176 | neighbors=[onsen_props.py, giboshi(), lerp(), house(), deck on brackets along a wall at z (sid…]
- "onsenvillage_onsen_props_skirt_roof": "skirt_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L118 | neighbors=[onsen_props.py, house(), pagoda(), pent roof around a storey (pagoda tiers…, flared_roof()]
- "passes_cube_demo": "cube_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Exception, cube_indices(), cube_vertices(), main()]
- "petsim_pet_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L194 | neighbors=[pet_map.py, crystal(), egg_stand(), hub(), link()]
- "petsim_pet_map_frame": "frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L537 | neighbors=[pet_map.py, build(), place(), seg_d(), clouds + rocks on the lagoon round the …]
- "petsim_pet_map_isle_mesh": "isle_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L59 | neighbors=[pet_map.py, build(), isle_R(), top_y(), polar top (dome) + rounded icing should…]
- "petsim_pet_map_path": "path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L217 | neighbors=[pet_map.py, build(), hub(), catmull(), zone()]
- "petsim_pet_map_plaza": "plaza()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L255 | neighbors=[pet_map.py, hub(), H(), static(), polar tile disc: rings of soft tiles al…]
- "petsim_pet_map_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L48 | neighbors=[pet_map.py, H(), isle_mesh(), isle_R(), polar()]
- "petsim_pet_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1032 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby rounded bench: two soft seat sla…]
- "petsim_pet_props_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L682 | neighbors=[pet_props.py, ell(), rbox(), soft(), rounded treasure chest: plank body, dom…]
- "petsim_pet_props_giant_donut": "giant_donut()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L943 | neighbors=[pet_props.py, flat(), pill(), soft(), pink-frosted donut lying tilted on the …]
- "petsim_pet_props_gift_box": "gift_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L702 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby present: soft box, crossing ribb…]
- "petsim_pet_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L837 | neighbors=[pet_props.py, ell(), flat(), soft(), chubby toadstool: bulgy stem, domed cap…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-036.json

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
