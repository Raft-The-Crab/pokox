# Node Description Batch 174 of 209

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

- "oaktrees_gen_trees_lv": "LV()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L735 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_rationale_1": "Realistic alpha-card trees for Roblox (Trunk / Branches / Leaves MeshParts + Sur" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_rationale_101": "fir / spruce: scaly grey-brown plates with reddish fresh bark in the cracks, fai" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L101 | neighbors=[bark_fir()]
- "oaktrees_gen_trees_rationale_1023": "build one species into coll: [<prefix><name>_Trunk, _Branches, _Leaves] (shared" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1023 | neighbors=[make_tree()]
- "oaktrees_gen_trees_rationale_115": "RGBA + height painter; shapes composited 'over' with soft edges." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L115 | neighbors=[Canvas]
- "oaktrees_gen_trees_rationale_132": "Tapered stroke along pts (px), clipped to the cell rect clip=(x0,x1,y0,y1)." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L132 | neighbors=[.capsule_path()]
- "oaktrees_gen_trees_rationale_211": "4 x 4 fir sprays: a central twig with paired laterals (frond widest near the bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L211 | neighbors=[needle_atlas()]
- "oaktrees_gen_trees_rationale_34": "Periodic (tileable) gaussian-filtered noise, fx / fy = feature frequency in cycl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L34 | neighbors=[fft_noise()]
- "oaktrees_gen_trees_rationale_358": "<1 inside the lumpy crown envelope." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L358 | neighbors=[.env()]
- "oaktrees_gen_trees_rationale_427": "surface roots: leave the trunk foot outward and down, then snake along the groun" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L427 | neighbors=[.grow_roots()]
- "oaktrees_gen_trees_rationale_475": "paired side sprays in the (roughly horizontal) plane of the branch, shorter towa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L475 | neighbors=[.laterals()]
- "oaktrees_gen_trees_rationale_550": "Leaf-cluster cards (folded, 4 tris) or crossed twig cards (2 x 2 tris)." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L550 | neighbors=[card_quads()]
- "oaktrees_gen_trees_rationale_620": "needle-spray cards along every branch / lateral: most lie in the spray plane (no" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L620 | neighbors=[conifer_cards()]
- "oaktrees_gen_trees_rationale_67": "t array -> colour from [(pos, (r,g,b)), ...]." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L67 | neighbors=[ramp()]
- "oaktrees_gen_trees_rationale_977": "paint + save the texture, or (maps) load it from roblox/textures when it already" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L977 | neighbors=[_img()]
- "oaktrees_gen_trees_rationale_992": "Trunk / Branches / Leaves materials for a texture style (cached per style)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L992 | neighbors=[get_materials()]
- "oaktrees_gen_trees_tree_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L351 | neighbors=[Tree]
- "onsenvillage_onsen_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L82 | neighbors=[onsen_map.py]
- "onsenvillage_onsen_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L566 | neighbors=[onsen_map.py]
- "onsenvillage_onsen_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L574 | neighbors=[onsen_map.py]
- "onsenvillage_onsen_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L845 | neighbors=[onsen_props.py]
- "onsenvillage_onsen_props_rationale_169": "bronze onion cap (the signature post finial)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L169 | neighbors=[giboshi()]
- "onsenvillage_onsen_props_shrub": "shrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L869 | neighbors=[onsen_props.py]
- "onsenvillage_onsen_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L44 | neighbors=[onsen_props.py]
- "onsenvillage_onsen_props_stepping_stones": "stepping_stones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L771 | neighbors=[onsen_props.py]
- "opencode_test_bootstrap_caching_afterfirst": "afterFirst" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L41 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_aftersecond": "afterSecond" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L45 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_assertmappingconstants": "assertMappingConstants()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L172 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_assertmissingbootstrap": "assertMissingBootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L152 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_assertpresentbootstrap": "assertPresentBootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L120 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_assertteachesbareskillids": "assertTeachesBareSkillIds()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L214 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_assertv2bootstrap": "assertV2Bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L265 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_bootstraptext": "bootstrapText()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L114 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_countbootstrapparts": "countBootstrapParts()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L108 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_firstoutput": "firstOutput" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L39 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_isbootstrapskillpath": "isBootstrapSkillPath()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L95 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_makeoutput": "makeOutput()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L99 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_mappingfailures": "mappingFailures" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L37 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_result": "result" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L52 | neighbors=[test-bootstrap-caching.mjs]
- "opencode_test_bootstrap_caching_runv2contexthook": "runV2ContextHook()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L230 | neighbors=[test-bootstrap-caching.mjs]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-173.json

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
