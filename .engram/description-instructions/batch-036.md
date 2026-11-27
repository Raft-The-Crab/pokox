# Node Description Batch 37 of 208

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

- "medievalbattle_battle_map_ground_shade": "ground_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L164 | neighbors=[battle_map.py, keep_w(), road_d(), trench_drop(), column per face (grass / road dirt / fo…]
- "medievalbattle_battle_map_road_d": "road_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L67 | neighbors=[battle_map.py, ground_shade(), H(), on_road(), seg_d()]
- "medievalbattle_battle_props_buttress": "buttress()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L717 | neighbors=[battle_props.py, merge(), stone(), stepped buttress in canonical orientati…, ruined_chapel()]
- "medievalbattle_battle_props_dead_tree": "dead_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1529 | neighbors=[battle_props.py, lerp(), log(), T(), charred, leafless tree: forked trunk, s…]
- "medievalbattle_battle_props_palisade": "palisade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L883 | neighbors=[battle_props.py, log(), sag(), T(), SIGNATURE: sharpened log stakes (bark b…]
- "medievalbattle_battle_props_pew": "pew()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L729 | neighbors=[battle_props.py, merge(), rot_mb(), T(), ruined_chapel()]
- "medievalbattle_battle_props_slit_frame": "slit_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L218 | neighbors=[battle_props.py, dressed frame round a CUT arrow slit (f…, T(), tower_body(), tower_face()]
- "medievalbattle_battle_props_tent": "tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1154 | neighbors=[battle_props.py, ridge tent (door at -Z): sagging canvas…, log(), T(), torus()]
- "migrations_0002_ledger_balances": "0002_ledger_balances.sql" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, balances, games, ledger_entries, share_entries]
- "moonclean_moon_map_on_ramp": "on_ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L185 | neighbors=[moon_map.py, adiff(), ramp_half_len(), scatter(), zone()]
- "moonclean_moon_map_peak": "peak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L474 | neighbors=[moon_map.py, build(), adiff(), place(), rail_ring()]
- "moonclean_moon_props_comms_dish": "comms_dish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L610 | neighbors=[moon_props.py, beam(), dish(), torus(), hub antenna: big dish on a yoke, turret…]
- "moonclean_moon_props_egg_incubator": "egg_incubator()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L269 | neighbors=[moon_props.py, egg(), station_base(), torus(), PETS: console with a screen, 3 cryo cag…]
- "moonclean_moon_props_floodlight": "floodlight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L592 | neighbors=[moon_props.py, beam(), lathe(), torus(), hub floodlight mast: tripod foot, taper…]
- "moonclean_moon_props_port": "port()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L101 | neighbors=[moon_props.py, moon_rocket(), torus(), round port window: steel frame ring + r…, reentry_pod()]
- "moonclean_moon_props_vac_pack": "vac_pack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L198 | neighbors=[moon_props.py, gear_locker(), vacuum backpack: twin tanks, frame, dus…, lathe(), torus()]
- "mute_parser": "parser.hpp" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Ast, ExpressionParser, to_arithmetic(), c7a411f Fix MUT-01-20 audit defects in …]
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
