# Node Description Batch 108 of 209

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

- "creaturelab_lab_props_rationale_340": "mart counter: white body, coral front panels, glass display case on the customer" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L340 | neighbors=[shop_counter(), Palette] | lang=en
- "creaturelab_lab_props_rationale_376": "capsule gondola: four shelves of stepped display risers, one tier per shelf (min" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L376 | neighbors=[capsule_shelf(), Palette] | lang=en
- "creaturelab_lab_props_rationale_392": "potion shelf: flasks, spray tonics, vials and berry jars in four colour runs, cr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L392 | neighbors=[potion_shelf(), Palette] | lang=en
- "creaturelab_lab_props_rationale_406": "tiered birch crate stand with three woven baskets heaped with berries (pink, gol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L406 | neighbors=[berry_baskets(), Palette] | lang=en
- "creaturelab_lab_props_rationale_423": "round three-tier display rack: steel pole, coral discs, boxed capsules on each t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L423 | neighbors=[display_rack(), Palette] | lang=en
- "creaturelab_lab_props_rationale_443": "storage terminal: rounded pedestal, angled neck, big framed screen (blank glow)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L443 | neighbors=[pc_terminal(), Palette] | lang=en
- "creaturelab_lab_props_rationale_482": "trade / battle registration desk: white desk with sky panels, a raised arch with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L482 | neighbors=[trade_desk(), Palette] | lang=en
- "creaturelab_lab_props_rationale_524": "specimen tank: steel base drum with a teal band + front control panel, glass cyl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L524 | neighbors=[specimen_tank(), Palette] | lang=en
- "creaturelab_lab_props_rationale_554": "HERO: the Bloom Chamber (evolution / scan chamber). Two-step round dais with tea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L554 | neighbors=[evo_chamber(), Palette] | lang=en
- "creaturelab_lab_props_rationale_56": "rounded box (bevel with `seg` segments); r clamped to the smallest half size" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L56 | neighbors=[rbox(), Palette] | lang=en
- "creaturelab_lab_props_rationale_621": "lab table: white top with a teal edge, steel legs with feet, a stretcher, cream" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L621 | neighbors=[lab_table(), Palette] | lang=en
- "creaturelab_lab_props_rationale_637": "lab workbench: table + test-tube rack with coloured tubes, conical + round flask" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L637 | neighbors=[workbench(), Palette] | lang=en
- "creaturelab_lab_props_rationale_669": "small lab table with a modelled microscope (base, curved arm, stage with clips," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L669 | neighbors=[microscope_bench(), Palette] | lang=en
- "creaturelab_lab_props_rationale_69": "solid annular sector: radii r0..r1, heights y0..y1, angles a0..a1 (deg; x = cos," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L69 | neighbors=[ring_seg(), Palette] | lang=en
- "creaturelab_lab_props_rationale_692": "rolling whiteboard: two T legs on casters, aluminium frame, blank board, marker" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L692 | neighbors=[whiteboard(), Palette] | lang=en
- "creaturelab_lab_props_rationale_716": "starter-capsule table: round white pedestal table with a teal apron, three cushi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L716 | neighbors=[starter_table(), Palette] | lang=en
- "creaturelab_lab_props_rationale_754": "pendant lamp hung from the ceiling (origin = the ceiling point, hangs DOWN to -d" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L754 | neighbors=[pendant_lamp(), Palette] | lang=en
- "creaturelab_lab_props_rationale_766": "little rest area for recovering creatures: oval rug, two round cushion beds (tea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L766 | neighbors=[rest_nook(), Palette] | lang=en
- "creaturelab_lab_props_rationale_797": "curved wall from angle a0..a1 split into cells; holes = [(ha0, ha1, hy0, hy1)] s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L797 | neighbors=[arc_wall(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_808": "HERO shell: the care hall. Ring wall (inner r 44) with a curved glass facade rou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L808 | neighbors=[rotunda(), Palette] | lang=en
- "creaturelab_lab_props_rationale_86": "copy a built Prop's geometry into P (moved / scaled / turned), keeping UVs + glo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L86 | neighbors=[merge_prop(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_861": "lathe without the flat end caps (rings stay open: roofs, eaves, collars over ope" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L861 | neighbors=[lathe_open(), Palette] | lang=en
- "creaturelab_lab_props_rationale_868": "rotunda roof (no collision, hide it for cutaways): mint shallow dome with white" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L868 | neighbors=[rotunda_roof(), Palette] | lang=en
- "creaturelab_lab_props_rationale_900": "plan polygon (x, z) of the lab wing interior: from (-hw, z0) to (-hw, zc), half" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L900 | neighbors=[wing_outline(), Palette] | lang=en
- "creaturelab_lab_props_rationale_910": "HERO shell: research wing walls: straight sides + half-round north end, tall win" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L910 | neighbors=[lab_wing(), Palette] | lang=en
- "creaturelab_lab_props_rationale_948": "lab wing roof (no collision; hide it for cutaways): flat white slab built in 1-s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L948 | neighbors=[wing_roof(), Palette] | lang=en
- "creaturelab_lab_props_rationale_96": "2D poly [(x, up)] standing upright facing -Z, extruded d toward the front (-Z) f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L96 | neighbors=[upright(), Palette] | lang=en
- "creaturelab_lab_props_rationale_991": "automatic sliding doors for the south entrance (14 wide x 13): steel header with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L991 | neighbors=[sliding_doors(), Palette] | lang=en
- "creaturelab_lab_props_reeds": "reeds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1546 | neighbors=[lab_props.py, .add()] | lang=en
- "creaturelab_lab_props_roof_in_y": "roof_in_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1277 | neighbors=[lab_props.py, underside of the rotunda roof at radius…] | lang=en
- "creaturelab_lab_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L46 | neighbors=[lab_props.py, heal_corner()] | lang=en
- "creaturelab_lab_props_stepping_stone": "stepping_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1556 | neighbors=[lab_props.py, .add()] | lang=en
- "creaturelab_lab_props_to_v": "to_v()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1628 | neighbors=[lab_props.py, supply_boxes()] | lang=en
- "creaturelab_lab_props_wing_outline": "wing_outline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L899 | neighbors=[lab_props.py, plan polygon (x, z) of the lab wing int…] | lang=en
- "creaturelab_turntable": "turntable.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/turntable.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "debug_vulkan_diagnostics_filter": "vulkan_diagnostics_filter.cpp" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics_filter.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, is_environment_layer_version_warning()] | lang=en
- "debug_vulkan_diagnostics_messages": "messages()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L126 | neighbors=[vulkan_diagnostics.cpp, since()] | lang=en
- "debug_vulkan_diagnostics_start": "start()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L78 | neighbors=[vulkan_diagnostics.cpp, start_with_factory()] | lang=en
- "debug_vulkan_diagnostics_stop": "stop()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L127 | neighbors=[vulkan_diagnostics.cpp, since()] | lang=en
- "debug_vulkan_diagnostics_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L76 | neighbors=[vulkan_diagnostics.cpp, .VulkanDiagnostics()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-107.json

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
