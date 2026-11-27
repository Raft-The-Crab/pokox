# Node Description Batch 173 of 209

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

- "mute_input_snapshot_inputtimeline": "InputTimeline" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L132 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_pack_device_code": "pack_device_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L47 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_pack_gamepad_code": "pack_gamepad_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L53 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_unpack_device_code": "unpack_device_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L50 | neighbors=[input_snapshot.hpp]
- "mute_optimize": "optimize.hpp" | kind=code-symbol | source=mute/include/poko/mute/optimize.hpp:L1 | neighbors=[e499073 Add MUT-29 dead-code eliminatio…]
- "mute_parser_ast_ast": ".Ast()" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L47 | neighbors=[Ast]
- "mute_parser_expressionparser": "ExpressionParser" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L44 | neighbors=[parser.hpp]
- "mute_parser_to_arithmetic": "to_arithmetic()" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L64 | neighbors=[parser.hpp]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-172.json

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
