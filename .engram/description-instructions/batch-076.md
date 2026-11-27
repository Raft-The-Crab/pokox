# Node Description Batch 77 of 209

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

- "mute_state_snapshot": "state_snapshot.hpp" | kind=code-symbol | source=mute/include/poko/mute/state_snapshot.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_stdlib_collections": "stdlib_collections.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_collections.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, ByteArray, OrderedStringMap]
- "net_crypto_aead_load32_le": "load32_le()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L32 | neighbors=[crypto_aead.hpp, chacha20_block(), poly1305_mac()]
- "net_crypto_aead_qr": "qr()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L50 | neighbors=[crypto_aead.hpp, chacha20_block(), rotl32()]
- "net_frame_hmac_sha256": "hmac_sha256()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L114 | neighbors=[frame.hpp, pack_frame(), unpack_frame()]
- "net_frame_pack_frame": "pack_frame()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L161 | neighbors=[frame.hpp, hmac_sha256(), payload_bit_length()]
- "net_frame_unpack_frame": "unpack_frame()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L191 | neighbors=[frame.hpp, constant_time_equal(), hmac_sha256()]
- "net_udp_echo": "udp_echo.hpp" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, echo_server_loop(), UdpSocket]
- "net_ws_transport_ws_encode_client": "ws_encode_client()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L47 | neighbors=[ws_transport.hpp, ws_encode_server(), ws_roundtrip()]
- "net_ws_transport_ws_encode_server": "ws_encode_server()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L28 | neighbors=[ws_transport.hpp, ws_encode_client(), ws_roundtrip()]
- "net_xor_fec_losses": "losses()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L44 | neighbors=[xor_fec.hpp, attach_parity(), recover_loss()]
- "oaktrees_gen_trees_canvas_grid": ".grid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L127 | neighbors=[Canvas, .capsule_path(), .leaf()]
- "oaktrees_gen_trees_canvas_over": ".over()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L120 | neighbors=[Canvas, .capsule_path(), .leaf()]
- "oaktrees_gen_trees_twig_atlas": "twig_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L308 | neighbors=[gen_trees.py, Canvas, .finish()]
- "onsenvillage_onsen_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L180 | neighbors=[onsen_map.py, fit_bad(), place()]
- "onsenvillage_onsen_map_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L146 | neighbors=[onsen_map.py, fit_bad(), _inb()]
- "onsenvillage_onsen_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L23 | neighbors=[onsen_map.py, place(), static()]
- "onsenvillage_onsen_props_cedar": "cedar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L834 | neighbors=[onsen_props.py, lerp(), mountain cedar for the backdrop: straig…]
- "onsenvillage_onsen_props_cloud_tree": "cloud_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L806 | neighbors=[onsen_props.py, lerp(), broadleaf in the garden style: flared f…]
- "onsenvillage_onsen_props_crag": "crag()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L851 | neighbors=[onsen_props.py, lerp(), tall framing crag: 4-5 overlapping tape…]
- "onsenvillage_onsen_props_doorway": "doorway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L153 | neighbors=[onsen_props.py, cut doorway: heavy posts + lintel, a sl…, storey_walls()]
- "onsenvillage_onsen_props_footbridge": "footbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L570 | neighbors=[onsen_props.py, giboshi(), arched cedar footbridge: plank deck on …]
- "onsenvillage_onsen_props_hand_cart": "hand_cart()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L727 | neighbors=[onsen_props.py, taru(), two-wheeled hand cart: plank bed with s…]
- "onsenvillage_onsen_props_jp_pine": "jp_pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L779 | neighbors=[onsen_props.py, lerp(), Japanese black pine: thick leaning trun…]
- "onsenvillage_onsen_props_railing": "railing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L478 | neighbors=[onsen_props.py, rail_post(), SIGNATURE: cedar railing bay with gibos…]
- "onsenvillage_onsen_props_railing_post": "railing_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L474 | neighbors=[onsen_props.py, rail_post(), the closing post at the end of a railin…]
- "onsenvillage_onsen_props_toro": "toro()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L492 | neighbors=[onsen_props.py, stone lantern (kasuga-style): hex stepp…, flared_roof()]
- "package_build_tool_build_project": "build_project()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L103 | neighbors=[build_tool.cpp, declared_identity(), name()]
- "parser_parser_dump_ast": "dump_ast()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L361 | neighbors=[parser.cpp, op_spelling(), quoted()]
- "passes_cube_demo_main": "main()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L72 | neighbors=[cube_demo.cpp, cube_indices(), cube_vertices()]
- "passes_imgui_demo_main": "main()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L226 | neighbors=[imgui_demo.cpp, build_demo_window(), update_imgui_io()]
- "petsim_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, lua_attrs()]
- "petsim_pet_map_build_solid": "build_solid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L153 | neighbors=[pet_map.py, build(), free()]
- "petsim_pet_map_clip_fail": "clip_fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L167 | neighbors=[pet_map.py, inside(), place_soft()]
- "petsim_pet_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L613 | neighbors=[pet_map.py, free(), link()]
- "petsim_pet_map_ribbon_mesh": "ribbon_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L229 | neighbors=[pet_map.py, path_meshes(), H()]
- "petsim_pet_map_rim_points": "rim_points()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L322 | neighbors=[pet_map.py, isle_R(), scatter()]
- "petsim_pet_props_cotton_tree": "cotton_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L755 | neighbors=[pet_props.py, bubble_crown(), candy tree: candy-striped trunk (stripe…]
- "petsim_pet_props_egg_prof": "egg_prof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L139 | neighbors=[pet_props.py, egg(), egg_r()]
- "petsim_pet_props_gumdrops": "gumdrops()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L933 | neighbors=[pet_props.py, soft(), 3-4 sugar-dusted gumdrops in candy colo…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-076.json

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
