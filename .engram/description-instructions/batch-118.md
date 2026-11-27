# Node Description Batch 119 of 209

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

- "integration_test_imgui_toggle_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_toggle_x11.py:L23 | neighbors=[test_imgui_toggle_x11.py, find_window()] | lang=en
- "integration_test_version_command": "command()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L45 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()] | lang=en
- "integration_test_version_copy_sources": "copy_sources()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L30 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()] | lang=en
- "integration_test_version_main": "main()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L107 | neighbors=[test_version.py, parse_options()] | lang=en
- "integration_test_version_parse_options": "parse_options()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L21 | neighbors=[test_version.py, main()] | lang=en
- "integration_test_version_versionintegrationtests": "VersionIntegrationTests" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L54 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()] | lang=en
- "iplatform": "IPlatform" | kind=code-symbol | neighbors=[TestPlatform, ~SdlPlatform()] | lang=en
- "lexer_lexer_decode": "decode()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L11 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_digit": "digit()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L43 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_digit_for": "digit_for()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L44 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_is_continue": "is_continue()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L51 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_is_start": "is_start()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L50 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_keyword": "keyword()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L52 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_string_body": "string_body()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L64 | neighbors=[lexer.cpp, lex()] | lang=en
- "lexer_lexer_suffix": "suffix()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L56 | neighbors=[lexer.cpp, lex()] | lang=en
- "matchmaker_allocator_matchmaker": "Matchmaker" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/allocator.hpp:L114 | neighbors=[allocator.hpp, .Matchmaker()] | lang=en
- "matchmaker_allocator_ticketsigner": "TicketSigner" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/allocator.hpp:L28 | neighbors=[allocator.hpp, .TicketSigner()] | lang=en
- "matchmaker_byo_registration": "byo_registration.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/byo_registration.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., ByoRegistration] | lang=en
- "matchmaker_byo_registration_byoregistration": "ByoRegistration" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/byo_registration.hpp:L39 | neighbors=[byo_registration.hpp, .ByoRegistration()] | lang=en
- "matchmaker_match_queue": "match_queue.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/match_queue.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., MatchQueue] | lang=en
- "matchmaker_party_book": "party_book.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/party_book.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., PartyBook] | lang=en
- "matchmaker_party_book_partybook": "PartyBook" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/party_book.hpp:L29 | neighbors=[party_book.hpp, .PartyBook()] | lang=en
- "matchmaker_reconnect": "reconnect.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/reconnect.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., ReconnectFlow] | lang=en
- "matchmaker_reconnect_reconnectflow": "ReconnectFlow" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/reconnect.hpp:L33 | neighbors=[reconnect.hpp, .ReconnectFlow()] | lang=en
- "matchmaker_slot_registry": "slot_registry.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/slot_registry.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., SlotRegistry] | lang=en
- "matchmaker_wake_lock": "wake_lock.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/wake_lock.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., WakeLock] | lang=en
- "matchmaker_wake_lock_wakelock": "WakeLock" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/wake_lock.hpp:L29 | neighbors=[wake_lock.hpp, .WakeLock()] | lang=en
- "math_deterministic_math_deterministic_cos": "deterministic_cos()" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L27 | neighbors=[deterministic_math.cpp, calculate()] | lang=en
- "math_deterministic_math_deterministic_sin": "deterministic_sin()" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L26 | neighbors=[deterministic_math.cpp, calculate()] | lang=en
- "math_deterministic_math_supported": "supported()" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L9 | neighbors=[deterministic_math.cpp, calculate()] | lang=en
- "medievalbattle_battle_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L157 | neighbors=[battle_map.py, field()] | lang=en
- "medievalbattle_battle_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L128 | neighbors=[battle_map.py, place()] | lang=en
- "medievalbattle_battle_map_fordw": "fordw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L37 | neighbors=[battle_map.py, channels()] | lang=en
- "medievalbattle_battle_map_isle_y": "isle_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L85 | neighbors=[battle_map.py, H()] | lang=en
- "medievalbattle_battle_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L481 | neighbors=[battle_map.py, free()] | lang=en
- "medievalbattle_battle_map_on_road": "on_road()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L161 | neighbors=[battle_map.py, road_d()] | lang=en
- "medievalbattle_battle_map_rationale_109": "drop faces buried inside the prop's own solid parts (block bases inside a wall," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L109 | neighbors=[cull_hidden(), MB] | lang=en
- "medievalbattle_battle_map_rationale_138": "height of the built ground MESH (4-stud grid) at x, z: props sit on what the pla" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L138 | neighbors=[Hm(), MB] | lang=en
- "medievalbattle_battle_map_rationale_165": "column per face (grass / road dirt / ford gravel / under-water mud), value per V" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L165 | neighbors=[ground_shade(), MB] | lang=it
- "medievalbattle_battle_map_rationale_229": "roads as smooth ribbon meshes draped on H (+0.08): ragged soft edges and a light" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L229 | neighbors=[roads(), MB] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-118.json

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
