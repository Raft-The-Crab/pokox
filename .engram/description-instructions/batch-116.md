# Node Description Batch 117 of 207

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

- "moonclean_moon_map_rationale_97": "weight 0..1 of ramp k at (r, a) and the ramp height there" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L97 | neighbors=[ramp_w(), MB]
- "moonclean_moon_props_dust_pile": "dust_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L694 | neighbors=[moon_props.py, sweepable heap: stacked mounds + a spar…]
- "moonclean_moon_props_earth": "earth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L742 | neighbors=[moon_props.py, Earth for the sky: faceted sphere, ocea…]
- "moonclean_moon_props_ice_shards": "ice_shards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L732 | neighbors=[moon_props.py, collectable ice: 3 short glowing shards…]
- "moonclean_moon_props_junk_heap": "junk_heap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L705 | neighbors=[moon_props.py, space junk to haul: bent hull panel, sn…]
- "musl_math_floor": "floor.cpp" | kind=code-symbol | source=mute/third_party/musl_math/floor.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, floor_value()]
- "musl_math_rem_pio2": "__rem_pio2.cpp" | kind=code-symbol | source=mute/third_party/musl_math/__rem_pio2.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, rem_pio2()]
- "musl_math_rem_pio2_large": "__rem_pio2_large.cpp" | kind=code-symbol | source=mute/third_party/musl_math/__rem_pio2_large.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, rem_pio2_large()]
- "musl_math_scalbn": "scalbn.cpp" | kind=code-symbol | source=mute/third_party/musl_math/scalbn.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, scalbn_value()]
- "mute_action_map_actionsampler": "ActionSampler" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L144 | neighbors=[action_map.hpp, .ActionSampler()]
- "mute_console": "console.hpp" | kind=code-symbol | source=mute/include/poko/mute/console.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, ConsoleLog]
- "mute_console_consolelog": "ConsoleLog" | kind=code-symbol | source=mute/include/poko/mute/console.hpp:L33 | neighbors=[console.hpp, .ConsoleLog()]
- "mute_debugger_vmdebugger": "VmDebugger" | kind=code-symbol | source=mute/include/poko/mute/debugger.hpp:L36 | neighbors=[debugger.hpp, .VmDebugger()]
- "mute_declaration_declarationast": "DeclarationAst" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L44 | neighbors=[declaration.hpp, .DeclarationAst()]
- "mute_determinism": "determinism.hpp" | kind=code-symbol | source=mute/include/poko/mute/determinism.hpp:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 952997e Audit MUT-01-55 and harden veri…]
- "mute_emit": "emit.hpp" | kind=code-symbol | source=mute/include/poko/mute/emit.hpp:L1 | neighbors=[335e0dc Add MUT-26 IR-to-bytecode emitt…, 952997e Audit MUT-01-55 and harden veri…]
- "mute_events": "events.hpp" | kind=code-symbol | source=mute/include/poko/mute/events.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, EventBus]
- "mute_input_snapshot_gamepad_control": "gamepad_control()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L59 | neighbors=[input_snapshot.hpp, touch_id()]
- "mute_input_snapshot_gamepad_slot": "gamepad_slot()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L56 | neighbors=[input_snapshot.hpp, touch_display()]
- "mute_input_snapshot_inputreplay": "InputReplay" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L160 | neighbors=[input_snapshot.hpp, .InputReplay()]
- "mute_input_snapshot_touch_display": "touch_display()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L62 | neighbors=[input_snapshot.hpp, gamepad_slot()]
- "mute_input_snapshot_touch_id": "touch_id()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L65 | neighbors=[input_snapshot.hpp, gamepad_control()]
- "mute_lower": "lower.hpp" | kind=code-symbol | source=mute/include/poko/mute/lower.hpp:L1 | neighbors=[85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…]
- "mute_package": "package.hpp" | kind=code-symbol | source=mute/include/poko/mute/package.hpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, c7e951a Add MUT-21 package, import and …]
- "mute_parser_ast": "Ast" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L45 | neighbors=[parser.hpp, .Ast()]
- "mute_register_vm": "register_vm.hpp" | kind=code-symbol | source=mute/include/poko/mute/register_vm.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_scheduler_scheduler": "Scheduler" | kind=code-symbol | source=mute/include/poko/mute/scheduler.hpp:L33 | neighbors=[scheduler.hpp, .Scheduler()]
- "mute_statement_statementast": "StatementAst" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L34 | neighbors=[statement.hpp, .StatementAst()]
- "mute_values_aggregatestore": "AggregateStore" | kind=code-symbol | source=mute/include/poko/mute/values.hpp:L43 | neighbors=[values.hpp, .AggregateStore()]
- "net_bit_buffer_bitbuffer": "BitBuffer" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L18 | neighbors=[bit_buffer.hpp, .BitBuffer()]
- "net_crypto_aead_consttime_equal": "consttime_equal()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L208 | neighbors=[crypto_aead.hpp, aead_open()]
- "net_crypto_aead_rotl32": "rotl32()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L30 | neighbors=[crypto_aead.hpp, qr()]
- "net_cube_sync_cubepeer": "CubePeer" | kind=code-symbol | source=server/net/include/poko/net/cube_sync.hpp:L62 | neighbors=[cube_sync.hpp, .CubePeer()]
- "net_frame_constant_time_equal": "constant_time_equal()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L132 | neighbors=[frame.hpp, unpack_frame()]
- "net_frame_payload_bit_length": "payload_bit_length()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L144 | neighbors=[frame.hpp, pack_frame()]
- "net_frame_sha256": "Sha256" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L27 | neighbors=[frame.hpp, .Sha256()]
- "net_jitter_buffer": "jitter_buffer.hpp" | kind=code-symbol | source=server/net/include/poko/net/jitter_buffer.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, JitterBuffer]
- "net_jitter_buffer_jitterbuffer": "JitterBuffer" | kind=code-symbol | source=server/net/include/poko/net/jitter_buffer.hpp:L35 | neighbors=[jitter_buffer.hpp, .JitterBuffer()]
- "net_udp_echo_udpsocket": "UdpSocket" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L38 | neighbors=[udp_echo.hpp, .UdpSocket()]
- "net_ws_transport_ws_decode": "ws_decode()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L69 | neighbors=[ws_transport.hpp, ws_roundtrip()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-116.json

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
