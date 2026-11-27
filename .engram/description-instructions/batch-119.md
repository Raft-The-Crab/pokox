# Node Description Batch 120 of 208

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

- "net_frame_payload_bit_length": "payload_bit_length()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L144 | neighbors=[frame.hpp, pack_frame()] | lang=en
- "net_frame_sha256": "Sha256" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L27 | neighbors=[frame.hpp, .Sha256()] | lang=en
- "net_jitter_buffer": "jitter_buffer.hpp" | kind=code-symbol | source=server/net/include/poko/net/jitter_buffer.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, JitterBuffer] | lang=en
- "net_jitter_buffer_jitterbuffer": "JitterBuffer" | kind=code-symbol | source=server/net/include/poko/net/jitter_buffer.hpp:L35 | neighbors=[jitter_buffer.hpp, .JitterBuffer()] | lang=en
- "net_udp_echo_udpsocket": "UdpSocket" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L38 | neighbors=[udp_echo.hpp, .UdpSocket()] | lang=en
- "net_ws_transport_ws_decode": "ws_decode()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L69 | neighbors=[ws_transport.hpp, ws_roundtrip()] | lang=en
- "net_xor_fec_attach_parity": "attach_parity()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L52 | neighbors=[xor_fec.hpp, losses()] | lang=en
- "net_xor_fec_make_parity": "make_parity()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L73 | neighbors=[xor_fec.hpp, xor_payloads()] | lang=en
- "net_xor_fec_recover_loss": "recover_loss()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L60 | neighbors=[xor_fec.hpp, losses()] | lang=en
- "net_xor_fec_xor_payloads": "xor_payloads()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L21 | neighbors=[xor_fec.hpp, make_parity()] | lang=en
- "oaktrees_gen_trees_export_glb": "export_glb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L943 | neighbors=[gen_trees.py, main()] | lang=en
- "oaktrees_gen_trees_load_px": "load_px()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L914 | neighbors=[gen_trees.py, contact_sheet()] | lang=en
- "oaktrees_gen_trees_make_object": "make_object()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L694 | neighbors=[gen_trees.py, make_tree()] | lang=en
- "oaktrees_gen_trees_material": "material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L710 | neighbors=[gen_trees.py, get_materials()] | lang=en
- "oaktrees_gen_trees_render_turntable": "render_turntable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L896 | neighbors=[gen_trees.py, main()] | lang=en
- "oaktrees_gen_trees_resize": "resize()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L921 | neighbors=[gen_trees.py, contact_sheet()] | lang=en
- "oaktrees_gen_trees_save_png": "save_png()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L52 | neighbors=[gen_trees.py, _img()] | lang=en
- "oaktrees_gen_trees_setup_scene": "setup_scene()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L853 | neighbors=[gen_trees.py, main()] | lang=en
- "oaktrees_gen_trees_tri_count": "tri_count()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L893 | neighbors=[gen_trees.py, make_tree()] | lang=en
- "oaktrees_gen_trees_tube_mesh": "tube_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L498 | neighbors=[gen_trees.py, make_tree()] | lang=en
- "onsenvillage_closeup": "closeup.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/closeup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "onsenvillage_onsen_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L145 | neighbors=[onsen_map.py, _inside_one()] | lang=en
- "onsenvillage_onsen_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L77 | neighbors=[onsen_map.py, place()] | lang=en
- "onsenvillage_onsen_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L517 | neighbors=[onsen_map.py, free()] | lang=en
- "onsenvillage_onsen_map_rationale_117": "the village is mirrored about x = 0: west copy as written, east copy at -x with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L117 | neighbors=[mirror(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_195": "stage ground (smooth: banks, stream bed, lawn) + mountains (flat faceted rock wi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L195 | neighbors=[ground(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_246": "distant peaks far behind the saddle (pale violet with snow caps) + low ridges at" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L246 | neighbors=[horizon(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_264": "stream + front pool surface: 4-stud cells kept only where the ground dips below" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L264 | neighbors=[water(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_283": "each terrace = running-bond flagstone top (inset stones, cream) + ashlar riser o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L283 | neighbors=[terraces(), MB] | lang=pt
- "onsenvillage_onsen_map_rationale_327": "flagstone path on the front bank from the bridge foot toward the camera, ragged" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L327 | neighbors=[bank_path(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_347": "SIGNATURE: railing bays along a terrace lip with gaps at stairs / bridge; stone" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L347 | neighbors=[rail_run(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_410": "clusters of 2-4 at the stairs and bridge; deliberately NOT mirrored (props break" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L410 | neighbors=[stories(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_492": "preview-only steam volumes over the hot water (Roblox: ParticleEmitters at these" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L492 | neighbors=[steam(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_61": "one height function for ground mesh AND placement (terrace tops are flat; risers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L61 | neighbors=[H(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_91": "auto-grounded props (y None) are fitted against everything built so far (see fit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L91 | neighbors=[place(), MB] | lang=en
- "onsenvillage_onsen_map_terrace_at": "terrace_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L40 | neighbors=[onsen_map.py, H()] | lang=en
- "onsenvillage_onsen_map_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L155 | neighbors=[onsen_map.py, fit_bad()] | lang=en
- "onsenvillage_onsen_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L717 | neighbors=[onsen_props.py, thick cedar bench: two planks, cross ba…] | lang=en
- "onsenvillage_onsen_props_crates": "crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L695 | neighbors=[onsen_props.py, stack: slatted cedar crates with corner…] | lang=en
- "onsenvillage_onsen_props_fern_tuft": "fern_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L877 | neighbors=[onsen_props.py, low clump of sage fronds for wall feet …] | lang=en

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
