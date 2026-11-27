# Node Description Batch 70 of 209

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

- "dunedesert_dune_map_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L232 | neighbors=[dune_map.py, fit(), _inside_one()]
- "dunedesert_dune_map_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L223 | neighbors=[dune_map.py, fit_bad(), _inb()]
- "dunedesert_dune_map_soft": "soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L163 | neighbors=[dune_map.py, nature(), foliage: deferred, placed last against …]
- "dunedesert_dune_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L24 | neighbors=[dune_map.py, place(), static()]
- "dunedesert_dune_map_t_local": "T_local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L74 | neighbors=[dune_map.py, H(), temple-local (lx across the trench, lz …]
- "dunedesert_dune_props_campfire": "campfire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L720 | neighbors=[dune_props.py, spike_flame(), stone ring, crossed logs, flame glow, a…]
- "dunedesert_dune_props_column_set": "column_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L342 | neighbors=[dune_props.py, column(), kind 0 standing column, 1 broken column…]
- "dunedesert_dune_props_dry_shrub": "dry_shrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L871 | neighbors=[dune_props.py, lerp(), desert scrub: a woody tangle of forking…]
- "dunedesert_dune_props_dune_grass": "dune_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L883 | neighbors=[dune_props.py, V(), tuft of tall pale dune grass: tapered f…]
- "dunedesert_dune_props_grid_disc": "grid_disc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L791 | neighbors=[dune_props.py, oasis_pool(), flat disc split into rings / sectors of…]
- "dunedesert_dune_props_jar": "jar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L571 | neighbors=[dune_props.py, cargo_pile(), trader_tent()]
- "dunedesert_dune_props_oasis_pool": "oasis_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L754 | neighbors=[dune_props.py, grid_disc(), oasis: a round pool (r 10) with a turqu…]
- "dunedesert_dune_props_peg_rope": "peg_rope()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L546 | neighbors=[dune_props.py, sleep_tent(), trader_tent()]
- "dunedesert_dune_props_rock_stack": "rock_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L959 | neighbors=[dune_props.py, wind-cut sandstone stack: 3-5 rounded s…, V()]
- "dunedesert_dune_props_ruin_arch": "ruin_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L321 | neighbors=[dune_props.py, free-standing broken arch: block piers,…, sun_relief()]
- "dunedesert_gen_trees_with_palms_canvas_grid": ".grid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L127 | neighbors=[Canvas, .capsule_path(), .leaf()]
- "dunedesert_gen_trees_with_palms_canvas_over": ".over()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L120 | neighbors=[Canvas, .capsule_path(), .leaf()]
- "dunedesert_gen_trees_with_palms_twig_atlas": "twig_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L308 | neighbors=[gen_trees_with_palms.py, Canvas, .finish()]
- "dunedesert_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, lua_attrs()]
- "effekseer_ai_authoring_cutoff_easing": "cutoff_easing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L80 | neighbors=[authoring.py, .advanced(), {'start','end','easing'} equivalent of …]
- "effekseer_ai_authoring_layerbuilder_curve": ".curve()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L137 | neighbors=[LayerBuilder, .scalar(), .layer()]
- "effekseer_ai_cli_build_parser": "build_parser()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L129 | neighbors=[cli.py, main(), Build the CLI parser without accessing …]
- "effekseer_ai_cli_main": "main()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L210 | neighbors=[cli.py, build_parser(), _emit()]
- "effekseer_ai_init": "__init__.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Python access to the official Effekseer…]
- "effekseer_ai_runtime_editor_bin_directory": "editor_bin_directory()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L14 | neighbors=[runtime.py, load_core(), Return the configured directory contain…]
- "effekseer_ai_runtime_export_binary": "export_binary()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L66 | neighbors=[runtime.py, load_core(), Export the current Core document as an …]
- "effekseer_ai_runtime_runtime_config_path": "runtime_config_path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L35 | neighbors=[runtime.py, load_core(), Return the bundled .NET runtime configu…]
- "effekseer_ai_session_effectsession_add_node": ".add_node()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L56 | neighbors=[EffectSession, ._node(), Add a Core node and return its AI-facin…]
- "effekseer_ai_session_effectsession_assign_value": "._assign_value()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L352 | neighbors=[EffectSession, .property_set(), Write scalar values through nested Core…]
- "effekseer_ai_session_effectsession_curve_keys": ".curve_keys()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L207 | neighbors=[EffectSession, ._object_at_path(), Read a scalar curve as JSON-friendly ke…]
- "effekseer_ai_session_effectsession_rename_node": ".rename_node()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L78 | neighbors=[EffectSession, ._node(), Rename a node through its Core string v…]
- "effekseer_ai_session_effectsession_settings_list": ".settings_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L181 | neighbors=[EffectSession, .property_list(), Discover parameters grouped as they are…]
- "effekseer_ai_session_effectsession_settings_set": ".settings_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L196 | neighbors=[EffectSession, .property_set(), Set a batch of panel-relative editable …]
- "effekseer_ai_settings": "settings.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/settings.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Names of node setting panels exposed by…]
- "eggplots_egg_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L93 | neighbors=[egg_map.py, dressing(), look()]
- "eggplots_egg_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L53 | neighbors=[egg_map.py, isle_d(), Hg()]
- "eggplots_egg_map_isle_d": "isle_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L49 | neighbors=[egg_map.py, dressing(), H()]
- "eggplots_egg_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L22 | neighbors=[egg_map.py, place(), static()]
- "eggplots_egg_map_to_world": "to_world()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L99 | neighbors=[egg_map.py, plot(), spawn_area()]
- "eggplots_egg_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L787 | neighbors=[egg_props.py, rbox(), sh()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-069.json

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
