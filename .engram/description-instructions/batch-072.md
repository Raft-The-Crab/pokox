# Node Description Batch 73 of 207

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

- "moonclean_moon_props_rationale_489": "faceted boulder sunk into a regolith skirt, with a small chipped pit; 2 satellit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L489 | neighbors=[moon_rock(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_49": "revolve [(r, y), ...] (bottom -> top) around Y; r == 0 collapses to a point" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L49 | neighbors=[lathe(), Palette, Sh] | lang=es
- "moonclean_moon_props_rationale_502": "split meteorite: two dark halves around a glowing molten core, in a raised impac" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L502 | neighbors=[meteorite(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_517": "ice cluster: 5-7 hex spikes leaning out from a frost-crusted rock, glowing cores" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L517 | neighbors=[ice_crystal(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_540": "abandoned lunar rover: tube chassis, 4 wire wheels with fenders, 2 seats, consol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L540 | neighbors=[moon_rover(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_563": "crashed satellite half-buried: foil bus, one bent solar wing (cells + frame), ti" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L563 | neighbors=[satellite_wreck(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_580": "3 horizontal tanks on cradles (2 bottom, 1 on top), orange end caps, pipe manifo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L580 | neighbors=[fuel_tanks(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_593": "hub floodlight mast: tripod foot, tapered pole, ring catwalk, 4-lamp head, red t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L593 | neighbors=[floodlight(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_611": "hub antenna: big dish on a yoke, turret drum, foil base, feed horn on 3 struts" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L611 | neighbors=[comms_dish(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_631": "stack of 3 white supply crates with orange corner caps and foil straps + a cylin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L631 | neighbors=[supply_crates(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_644": "modelled impact crater for R = 1 (place with s = R): smooth 36-sided lathe, rais" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L644 | neighbors=[crater(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_672": "sweepable dust drift: low lumpy pancake, lighter than the ground, rippled rings" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L672 | neighbors=[dust_patch(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_706": "space junk to haul: bent hull panel, snapped pipe, gear, bolts, broken box - bui" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L706 | neighbors=[junk_heap(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_724": "small glowing meteor fragment to collect: dark shell with molten seams, scorch d" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L724 | neighbors=[meteor_chunk(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_733": "collectable ice: 3 short glowing shards on a frost puddle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L733 | neighbors=[ice_shards(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_743": "Earth for the sky: faceted sphere, oceans / continents / cloud + polar caps by n" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L743 | neighbors=[earth(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_80": "parabolic dish opening up (+Y), thickness t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L80 | neighbors=[dish(), Palette, Sh] | lang=es
- "moonclean_moon_props_rivets": "rivets()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L96 | neighbors=[moon_props.py, dust_exchange(), moon_rocket()] | lang=en
- "moonclean_moon_props_supply_crates": "supply_crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L630 | neighbors=[moon_props.py, stack of 3 white supply crates with ora…, torus()] | lang=en
- "musl_math_cos": "cos.cpp" | kind=code-symbol | source=mute/third_party/musl_math/cos.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, cosine(), kernel_cos()] | lang=en
- "musl_math_sin": "sin.cpp" | kind=code-symbol | source=mute/third_party/musl_math/sin.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, kernel_sin(), sine()] | lang=en
- "mute_bytecode": "bytecode.hpp" | kind=code-symbol | source=mute/include/poko/mute/bytecode.hpp:L1 | neighbors=[85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "mute_debugger": "debugger.hpp" | kind=code-symbol | source=mute/include/poko/mute/debugger.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, VmCore, VmDebugger] | lang=en
- "mute_declaration": "declaration.hpp" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, DeclarationAst, DeclarationParser] | lang=en
- "mute_ssa": "ssa.hpp" | kind=code-symbol | source=mute/include/poko/mute/ssa.hpp:L1 | neighbors=[335e0dc Add MUT-26 IR-to-bytecode emitt…, 952997e Audit MUT-01-55 and harden veri…, fd66d0d Add MUT-25 typed SSA IR and ver…] | lang=en
- "mute_statement": "statement.hpp" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, StatementAst, StatementParser] | lang=en
- "mute_stdlib_collections": "stdlib_collections.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_collections.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, ByteArray, OrderedStringMap] | lang=en
- "net_crypto_aead_load32_le": "load32_le()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L32 | neighbors=[crypto_aead.hpp, chacha20_block(), poly1305_mac()] | lang=en
- "net_crypto_aead_qr": "qr()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L50 | neighbors=[crypto_aead.hpp, chacha20_block(), rotl32()] | lang=en
- "net_frame_hmac_sha256": "hmac_sha256()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L114 | neighbors=[frame.hpp, pack_frame(), unpack_frame()] | lang=en
- "net_frame_pack_frame": "pack_frame()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L161 | neighbors=[frame.hpp, hmac_sha256(), payload_bit_length()] | lang=en
- "net_frame_unpack_frame": "unpack_frame()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L191 | neighbors=[frame.hpp, constant_time_equal(), hmac_sha256()] | lang=en
- "net_udp_echo": "udp_echo.hpp" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, echo_server_loop(), UdpSocket] | lang=en
- "net_ws_transport_ws_encode_client": "ws_encode_client()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L47 | neighbors=[ws_transport.hpp, ws_encode_server(), ws_roundtrip()] | lang=en
- "net_ws_transport_ws_encode_server": "ws_encode_server()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L28 | neighbors=[ws_transport.hpp, ws_encode_client(), ws_roundtrip()] | lang=en
- "net_xor_fec_losses": "losses()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L44 | neighbors=[xor_fec.hpp, attach_parity(), recover_loss()] | lang=en
- "oaktrees_gen_trees_canvas_grid": ".grid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L127 | neighbors=[Canvas, .capsule_path(), .leaf()] | lang=en
- "oaktrees_gen_trees_canvas_over": ".over()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L120 | neighbors=[Canvas, .capsule_path(), .leaf()] | lang=en
- "oaktrees_gen_trees_twig_atlas": "twig_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L308 | neighbors=[gen_trees.py, Canvas, .finish()] | lang=en
- "onsenvillage_onsen_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L180 | neighbors=[onsen_map.py, fit_bad(), place()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-072.json

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
