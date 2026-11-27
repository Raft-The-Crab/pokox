# Node Description Batch 123 of 209

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "onsenvillage_onsen_props_rationale_609": "drying rack: two cedar uprights with feet, three poles, folded towels draped ove" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L609 | neighbors=[towel_rack(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_633": "yatai cart: two spoked wheels, cedar counter cabin with a plank top, small persi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L633 | neighbors=[noodle_stall(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_668": "sake cask: straw-wrapped body, rope bands, lid; lying casks rest on their side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L668 | neighbors=[taru(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_682": "cluster: cedar pallet, three standing casks, one on top, one lying in a chock, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L682 | neighbors=[sake_barrels(), Palette] | lang=pt
- "onsenvillage_onsen_props_rationale_696": "stack: slatted cedar crates with corner battens, a rope-tied sack pile and a bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L696 | neighbors=[crates(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_718": "thick cedar bench: two planks, cross battens, iron bolts, carved stone feet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L718 | neighbors=[bench(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_728": "two-wheeled hand cart: plank bed with side boards, long handles, spoked wheels," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L728 | neighbors=[hand_cart(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_746": "cedar lamp post with a crossarm and a hanging paper lantern, stone footing" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L746 | neighbors=[paper_lantern_post(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_757": "shrine gate: two cedar columns on stone bases, double lintel (kasagi with upswep" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L757 | neighbors=[torii(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_780": "Japanese black pine: thick leaning trunk with a kink, horizontal limbs ending in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L780 | neighbors=[jp_pine(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_807": "broadleaf in the garden style: flared forked trunk, 5 boughs, a dense rounded cr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L807 | neighbors=[cloud_tree(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_835": "mountain cedar for the backdrop: straight trunk, stacked drooping sage skirts (n" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L835 | neighbors=[cedar(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_852": "tall framing crag: 4-5 overlapping tapered rock columns of different heights (on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L852 | neighbors=[crag(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_878": "low clump of sage fronds for wall feet and banks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L878 | neighbors=[fern_tuft(), Palette] | lang=en
- "onsenvillage_onsen_props_stair_flight": "stair_flight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L546 | neighbors=[onsen_props.py, stone stair: bevelled sand treads with …] | lang=en
- "onsenvillage_onsen_props_torii": "torii()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L756 | neighbors=[onsen_props.py, shrine gate: two cedar columns on stone…] | lang=en
- "package_build_tool_after_token": "after_token()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L39 | neighbors=[build_tool.cpp, declared_identity()] | lang=en
- "package_build_tool_name": "name()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L141 | neighbors=[build_tool.cpp, build_project()] | lang=en
- "package_build_tool_next_quoted": "next_quoted()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L43 | neighbors=[build_tool.cpp, declared_identity()] | lang=en
- "package_package_inner_position": "inner_position()" | kind=code-symbol | source=mute/src/package/package.cpp:L21 | neighbors=[package.cpp, resolve_packages()] | lang=en
- "package_package_parse_import_spec": "parse_import_spec()" | kind=code-symbol | source=mute/src/package/package.cpp:L37 | neighbors=[package.cpp, resolve_packages()] | lang=en
- "package_package_unquote": "unquote()" | kind=code-symbol | source=mute/src/package/package.cpp:L30 | neighbors=[package.cpp, resolve_packages()] | lang=en
- "parser_declaration_decl_fail": "decl_fail()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L13 | neighbors=[declaration.cpp, Depth()] | lang=en
- "parser_declaration_decl_quoted": "decl_quoted()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L16 | neighbors=[declaration.cpp, dump_declaration_ast()] | lang=en
- "parser_declaration_declarationparser": "DeclarationParser" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L25 | neighbors=[declaration.cpp, .DeclarationParser()] | lang=en
- "parser_declaration_depth": "Depth()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L75 | neighbors=[declaration.cpp, decl_fail()] | lang=en
- "parser_declaration_dump_declaration_ast": "dump_declaration_ast()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L449 | neighbors=[declaration.cpp, decl_quoted()] | lang=en
- "parser_parser_expressionparser": "ExpressionParser" | kind=code-symbol | source=mute/src/parser/parser.cpp:L86 | neighbors=[parser.cpp, .ExpressionParser()] | lang=en
- "parser_parser_op_spelling": "op_spelling()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L9 | neighbors=[parser.cpp, dump_ast()] | lang=en
- "parser_parser_quoted": "quoted()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L70 | neighbors=[parser.cpp, dump_ast()] | lang=en
- "parser_statement_depth": "Depth()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L59 | neighbors=[statement.cpp, stmt_fail()] | lang=en
- "parser_statement_dump_statement_ast": "dump_statement_ast()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L329 | neighbors=[statement.cpp, quoted()] | lang=en
- "parser_statement_quoted": "quoted()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L16 | neighbors=[statement.cpp, dump_statement_ast()] | lang=en
- "parser_statement_statementparser": "StatementParser" | kind=code-symbol | source=mute/src/parser/statement.cpp:L25 | neighbors=[statement.cpp, .StatementParser()] | lang=en
- "parser_statement_stmt_fail": "stmt_fail()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L13 | neighbors=[statement.cpp, Depth()] | lang=en
- "passes_cube_demo_cube_indices": "cube_indices()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L62 | neighbors=[cube_demo.cpp, main()] | lang=en
- "passes_cube_demo_cube_vertices": "cube_vertices()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L39 | neighbors=[cube_demo.cpp, main()] | lang=en
- "passes_imgui_demo_build_demo_window": "build_demo_window()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L168 | neighbors=[imgui_demo.cpp, main()] | lang=en
- "passes_imgui_demo_composite": "composite()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L61 | neighbors=[imgui_demo.cpp, ensure_gpu_timer()] | lang=en
- "passes_imgui_demo_ensure_gpu_timer": "ensure_gpu_timer()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L44 | neighbors=[imgui_demo.cpp, composite()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-122.json

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
