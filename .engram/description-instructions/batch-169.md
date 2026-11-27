# Node Description Batch 170 of 207

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

- "mute_events_eventbus": "EventBus" | kind=code-symbol | source=mute/include/poko/mute/events.hpp:L35 | neighbors=[events.hpp]
- "mute_fold": "fold.hpp" | kind=code-symbol | source=mute/include/poko/mute/fold.hpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…]
- "mute_hostcall_capability_from_name": "capability_from_name()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L48 | neighbors=[hostcall.hpp]
- "mute_hostcall_capability_name": "capability_name()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L52 | neighbors=[hostcall.hpp]
- "mute_hostcall_effective_capabilities": "effective_capabilities()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L96 | neighbors=[hostcall.hpp]
- "mute_hostcall_hostcalltable": "HostcallTable" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L78 | neighbors=[hostcall.hpp]
- "mute_input_snapshot_inputreplay_inputreplay": ".InputReplay()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L162 | neighbors=[InputReplay]
- "mute_input_snapshot_inputtimeline": "InputTimeline" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L132 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_pack_device_code": "pack_device_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L47 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_pack_gamepad_code": "pack_gamepad_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L53 | neighbors=[input_snapshot.hpp]
- "mute_input_snapshot_unpack_device_code": "unpack_device_code()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L50 | neighbors=[input_snapshot.hpp]
- "mute_lexer": "lexer.hpp" | kind=code-symbol | source=mute/include/poko/mute/lexer.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "mute_optimize": "optimize.hpp" | kind=code-symbol | source=mute/include/poko/mute/optimize.hpp:L1 | neighbors=[e499073 Add MUT-29 dead-code eliminatio…]
- "mute_parser_ast_ast": ".Ast()" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L47 | neighbors=[Ast]
- "mute_parser_expressionparser": "ExpressionParser" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L44 | neighbors=[parser.hpp]
- "mute_parser_to_arithmetic": "to_arithmetic()" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L64 | neighbors=[parser.hpp]
- "mute_pkb_draft": "pkb_draft.hpp" | kind=code-symbol | source=mute/include/poko/mute/pkb_draft.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "mute_program": "program.hpp" | kind=code-symbol | source=mute/include/poko/mute/program.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "mute_scheduler_scheduler_scheduler": ".Scheduler()" | kind=code-symbol | source=mute/include/poko/mute/scheduler.hpp:L47 | neighbors=[Scheduler]
- "mute_semantic": "semantic.hpp" | kind=code-symbol | source=mute/include/poko/mute/semantic.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "mute_state": "state.hpp" | kind=code-symbol | source=mute/include/poko/mute/state.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "mute_state_snapshot": "state_snapshot.hpp" | kind=code-symbol | source=mute/include/poko/mute/state_snapshot.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-169.json

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
