# Node Description Batch 176 of 209

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
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "parser_parser_is_assign_op": "is_assign_op()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L67 | neighbors=[parser.cpp]
- "parser_parser_name": "name()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L357 | neighbors=[parser.cpp]
- "parser_parser_parse_arithmetic": "parse_arithmetic()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L345 | neighbors=[parser.cpp]
- "parser_statement_loopscope": "LoopScope()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L69 | neighbors=[statement.cpp]
- "parser_statement_name": "name()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L322 | neighbors=[statement.cpp]
- "parser_statement_parse_statements": "parse_statements()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L302 | neighbors=[statement.cpp]
- "parser_statement_statementparser_statementparser": ".StatementParser()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L291 | neighbors=[StatementParser]
- "passes_imgui_demo_imguicontextguard": "ImGuiContextGuard()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L220 | neighbors=[imgui_demo.cpp]
- "passes_imgui_demo_print_to_console": "print_to_console()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L162 | neighbors=[imgui_demo.cpp]
- "passes_triangle_demo_main": "main()" | kind=code-symbol | source=engine/render/src/passes/triangle_demo.cpp:L37 | neighbors=[triangle_demo.cpp]
- "petsim_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/hooks_lua.py:L5 | neighbors=[hooks_lua.py]
- "petsim_pet_map_rationale_220": "distance to the nearest path edge (negative = on a path)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L220 | neighbors=[path_d()]
- "petsim_pet_map_rationale_307": "chunky fence round the rim, a gap at every bridge head (gaps = world points)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L307 | neighbors=[fence_ring()]
- "petsim_pet_props_rationale_101": "capsule from a to b (rounded ends)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L101 | neighbors=[pill()]
- "petsim_pet_props_rationale_1055": "rounded lagoon rock with a little grass cap (sits in the water as frame)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1055 | neighbors=[sea_rock()]
- "petsim_pet_props_rationale_714": "lilac rock base with 4-5 glowing hex crystals (tier 2 / tier 3)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L714 | neighbors=[crystal_clump()]
- "petsim_pet_props_rationale_828": "chunky clover tuft: 3 rounded leaf blobs (cheap)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L828 | neighbors=[grass_tuft()]
- "petsim_pet_props_rationale_886": "smooth pebble boulder (squashed soft lump)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L886 | neighbors=[soft_rock()]
- "petsim_pet_props_rationale_911": "hooked cane, red / cream diagonal stripes (fine rings so the stripes read)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L911 | neighbors=[candy_cane()]
- "petsim_pet_props_rationale_994": "trio of round-capped glow mushrooms (cyan caps glow)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L994 | neighbors=[glow_shroom()]
- "physics_character_controller_charactercontroller_charactercontroller": ".CharacterController()" | kind=code-symbol | source=engine/physics/include/poko/physics/character_controller.hpp:L85 | neighbors=[CharacterController]
- "physics_convex_shape_convexshape_convexshape": ".ConvexShape()" | kind=code-symbol | source=engine/physics/include/poko/physics/convex_shape.hpp:L32 | neighbors=[ConvexShape]
- "physics_narrowphase": "narrowphase.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/narrowphase.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…]
- "physics_sap_broadphase_sapbroadphase": "SapBroadphase" | kind=code-symbol | source=engine/physics/include/poko/physics/sap_broadphase.hpp:L36 | neighbors=[sap_broadphase.hpp]
- "physics_soft_body_clothgrid": "ClothGrid" | kind=code-symbol | source=engine/physics/include/poko/physics/soft_body.hpp:L81 | neighbors=[soft_body.hpp]
- "physics_soft_body_softbody": "SoftBody" | kind=code-symbol | source=engine/physics/include/poko/physics/soft_body.hpp:L36 | neighbors=[soft_body.hpp]
- "physics_solver_sequentialimpulsesolver": "SequentialImpulseSolver" | kind=code-symbol | source=engine/physics/include/poko/physics/solver.hpp:L80 | neighbors=[solver.hpp]
- "physics_visual_solver_visualsolver": "VisualSolver" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L61 | neighbors=[visual_solver.hpp]
- "physics_visual_solver_visualworld": "VisualWorld" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L106 | neighbors=[visual_solver.hpp]
- "pi_test_pi_extension_dirname": "__dirname" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L8 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_emit": "emit()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L39 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_extensionpath": "extensionPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L11 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_firsthandler": "firstHandler()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L31 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_loadextension": "loadExtension()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L18 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_packagejsonpath": "packageJsonPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L10 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_pitoolspath": "piToolsPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L12 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_readpackagejson": "readPackageJson()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L14 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_reporoot": "repoRoot" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L9 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_textof": "textOf()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L45 | neighbors=[test-pi-extension.mjs]
- "plugins_superpowers_bootstrapcache": "_bootstrapCache" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L114 | neighbors=[superpowers.js]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-175.json

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
