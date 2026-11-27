# Node Description Batch 172 of 208

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

- "mute_scheduler_scheduler_scheduler": ".Scheduler()" | kind=code-symbol | source=mute/include/poko/mute/scheduler.hpp:L47 | neighbors=[Scheduler]
- "mute_statement_statementast_statementast": ".StatementAst()" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L36 | neighbors=[StatementAst]
- "mute_statement_statementparser": "StatementParser" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L21 | neighbors=[statement.hpp]
- "mute_stdlib_collections_bytearray": "ByteArray" | kind=code-symbol | source=mute/include/poko/mute/stdlib_collections.hpp:L21 | neighbors=[stdlib_collections.hpp]
- "mute_stdlib_collections_orderedstringmap": "OrderedStringMap" | kind=code-symbol | source=mute/include/poko/mute/stdlib_collections.hpp:L37 | neighbors=[stdlib_collections.hpp]
- "mute_stdlib_crypto": "stdlib_crypto.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_crypto.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…]
- "mute_stdlib_math_simclock": "SimClock" | kind=code-symbol | source=mute/include/poko/mute/stdlib_math.hpp:L84 | neighbors=[stdlib_math.hpp]
- "mute_stdlib_math_xorshift128plus": "XorShift128Plus" | kind=code-symbol | source=mute/include/poko/mute/stdlib_math.hpp:L69 | neighbors=[stdlib_math.hpp]
- "mute_stdlib_string": "stdlib_string.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_string.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…]
- "mute_values_aggregatestore_aggregatestore": ".AggregateStore()" | kind=code-symbol | source=mute/include/poko/mute/values.hpp:L52 | neighbors=[AggregateStore]
- "net_bit_buffer_bitbuffer_bitbuffer": ".BitBuffer()" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L20 | neighbors=[BitBuffer]
- "net_bit_buffer_get_array": "get_array()" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L120 | neighbors=[bit_buffer.hpp]
- "net_bit_buffer_get_delta": "get_delta()" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L128 | neighbors=[bit_buffer.hpp]
- "net_bit_buffer_put_array": "put_array()" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L69 | neighbors=[bit_buffer.hpp]
- "net_bit_buffer_put_delta": "put_delta()" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L79 | neighbors=[bit_buffer.hpp]
- "net_cube_sync_cube_schema": "cube_schema()" | kind=code-symbol | source=server/net/include/poko/net/cube_sync.hpp:L26 | neighbors=[cube_sync.hpp]
- "net_cube_sync_cubepeer_cubepeer": ".CubePeer()" | kind=code-symbol | source=server/net/include/poko/net/cube_sync.hpp:L64 | neighbors=[CubePeer]
- "net_cube_sync_exchange_over_udp": "exchange_over_udp()" | kind=code-symbol | source=server/net/include/poko/net/cube_sync.hpp:L111 | neighbors=[cube_sync.hpp]
- "net_delta_decode_delta": "decode_delta()" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L84 | neighbors=[delta.hpp]
- "net_delta_deltaschema": "DeltaSchema" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L36 | neighbors=[delta.hpp]
- "net_delta_encode_delta": "encode_delta()" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L61 | neighbors=[delta.hpp]
- "net_delta_resendwindow": "ResendWindow" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L108 | neighbors=[delta.hpp]
- "net_frame_sha256_sha256": ".Sha256()" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L29 | neighbors=[Sha256]
- "net_jitter_buffer_jitterbuffer_jitterbuffer": ".JitterBuffer()" | kind=code-symbol | source=server/net/include/poko/net/jitter_buffer.hpp:L37 | neighbors=[JitterBuffer]
- "net_udp_echo_echo_server_loop": "echo_server_loop()" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L127 | neighbors=[udp_echo.hpp]
- "net_udp_echo_udpsocket_udpsocket": ".UdpSocket()" | kind=code-symbol | source=server/net/include/poko/net/udp_echo.hpp:L40 | neighbors=[UdpSocket]
- "net_xor_fec_rotated_group": "rotated_group()" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L82 | neighbors=[xor_fec.hpp]
- "oaktrees_gen_trees_arg": "arg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L17 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_basis_card": "basis_card()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L541 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_branch_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L332 | neighbors=[Branch]
- "oaktrees_gen_trees_canvas_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L116 | neighbors=[Canvas]
- "oaktrees_gen_trees_grade": "_grade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L970 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_lv": "LV()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L735 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_rationale_1": "Realistic alpha-card trees for Roblox (Trunk / Branches / Leaves MeshParts + Sur" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1 | neighbors=[gen_trees.py]
- "oaktrees_gen_trees_rationale_101": "fir / spruce: scaly grey-brown plates with reddish fresh bark in the cracks, fai" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L101 | neighbors=[bark_fir()]
- "oaktrees_gen_trees_rationale_1023": "build one species into coll: [<prefix><name>_Trunk, _Branches, _Leaves] (shared" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1023 | neighbors=[make_tree()]
- "oaktrees_gen_trees_rationale_115": "RGBA + height painter; shapes composited 'over' with soft edges." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L115 | neighbors=[Canvas]
- "oaktrees_gen_trees_rationale_132": "Tapered stroke along pts (px), clipped to the cell rect clip=(x0,x1,y0,y1)." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L132 | neighbors=[.capsule_path()]
- "oaktrees_gen_trees_rationale_211": "4 x 4 fir sprays: a central twig with paired laterals (frond widest near the bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L211 | neighbors=[needle_atlas()]
- "oaktrees_gen_trees_rationale_34": "Periodic (tileable) gaussian-filtered noise, fx / fy = feature frequency in cycl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L34 | neighbors=[fft_noise()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-171.json

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
