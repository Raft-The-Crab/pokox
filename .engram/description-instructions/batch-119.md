# Node Description Batch 120 of 207

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

- "package_package_parse_import_spec": "parse_import_spec()" | kind=code-symbol | source=mute/src/package/package.cpp:L37 | neighbors=[package.cpp, resolve_packages()]
- "package_package_unquote": "unquote()" | kind=code-symbol | source=mute/src/package/package.cpp:L30 | neighbors=[package.cpp, resolve_packages()]
- "parser_declaration_decl_fail": "decl_fail()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L13 | neighbors=[declaration.cpp, Depth()]
- "parser_declaration_decl_quoted": "decl_quoted()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L16 | neighbors=[declaration.cpp, dump_declaration_ast()]
- "parser_declaration_declarationparser": "DeclarationParser" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L25 | neighbors=[declaration.cpp, .DeclarationParser()]
- "parser_declaration_depth": "Depth()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L75 | neighbors=[declaration.cpp, decl_fail()]
- "parser_declaration_dump_declaration_ast": "dump_declaration_ast()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L449 | neighbors=[declaration.cpp, decl_quoted()]
- "parser_parser_expressionparser": "ExpressionParser" | kind=code-symbol | source=mute/src/parser/parser.cpp:L86 | neighbors=[parser.cpp, .ExpressionParser()]
- "parser_parser_op_spelling": "op_spelling()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L9 | neighbors=[parser.cpp, dump_ast()]
- "parser_parser_quoted": "quoted()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L70 | neighbors=[parser.cpp, dump_ast()]
- "parser_statement_depth": "Depth()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L59 | neighbors=[statement.cpp, stmt_fail()]
- "parser_statement_dump_statement_ast": "dump_statement_ast()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L329 | neighbors=[statement.cpp, quoted()]
- "parser_statement_quoted": "quoted()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L16 | neighbors=[statement.cpp, dump_statement_ast()]
- "parser_statement_statementparser": "StatementParser" | kind=code-symbol | source=mute/src/parser/statement.cpp:L25 | neighbors=[statement.cpp, .StatementParser()]
- "parser_statement_stmt_fail": "stmt_fail()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L13 | neighbors=[statement.cpp, Depth()]
- "passes_cube_demo_cube_indices": "cube_indices()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L62 | neighbors=[cube_demo.cpp, main()]
- "passes_cube_demo_cube_vertices": "cube_vertices()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L39 | neighbors=[cube_demo.cpp, main()]
- "passes_imgui_demo_build_demo_window": "build_demo_window()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L168 | neighbors=[imgui_demo.cpp, main()]
- "passes_imgui_demo_composite": "composite()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L61 | neighbors=[imgui_demo.cpp, ensure_gpu_timer()]
- "passes_imgui_demo_ensure_gpu_timer": "ensure_gpu_timer()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L44 | neighbors=[imgui_demo.cpp, composite()]
- "passes_imgui_demo_feed_imgui_event": "feed_imgui_event()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L137 | neighbors=[imgui_demo.cpp, imgui_key()]
- "passes_imgui_demo_imgui_key": "imgui_key()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L113 | neighbors=[imgui_demo.cpp, feed_imgui_event()]
- "passes_imgui_demo_update_imgui_io": "update_imgui_io()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L82 | neighbors=[imgui_demo.cpp, main()]
- "petsim_pet_map_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L208 | neighbors=[pet_map.py, path()]
- "petsim_pet_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L122 | neighbors=[pet_map.py, place()]
- "petsim_pet_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L161 | neighbors=[pet_map.py, clip_fail()]
- "petsim_pet_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L117 | neighbors=[pet_map.py, place()]
- "petsim_pet_map_rationale_256": "polar tile disc: rings of soft tiles alternating cream / pink, inset grout, a sk" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L256 | neighbors=[plaza(), MB]
- "petsim_pet_map_rationale_330": "items = [(key, fn, scale_range)], n tries; keeps clear of paths + reserved spots" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L330 | neighbors=[scatter(), MB]
- "petsim_pet_map_rationale_341": "clusters of 3-5 breakables off the paths; tier rises with distance from the zone" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L341 | neighbors=[breakables(), MB]
- "petsim_pet_map_rationale_538": "clouds + rocks on the lagoon round the chain (outside every island, off the brid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L538 | neighbors=[frame(), MB]
- "petsim_pet_map_rationale_60": "polar top (dome) + rounded icing shoulder + sponge cliff down into the lagoon. C" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L60 | neighbors=[isle_mesh(), MB]
- "petsim_pet_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L556 | neighbors=[pet_map.py, frame()]
- "petsim_pet_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L651 | neighbors=[pet_map.py, link()]
- "petsim_pet_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L149 | neighbors=[pet_map.py, place_soft()]
- "petsim_pet_props_arc_pts": "arc_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L113 | neighbors=[pet_props.py, trade_pad()]
- "petsim_pet_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L910 | neighbors=[pet_props.py, hooked cane, red / cream diagonal strip…]
- "petsim_pet_props_disc_up": "disc_up()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L124 | neighbors=[pet_props.py, rcyl()]
- "petsim_pet_props_egg_r": "egg_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L147 | neighbors=[pet_props.py, egg_prof()]
- "petsim_pet_props_lift": "lift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L136 | neighbors=[pet_props.py, egg()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-119.json

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
