# Node Description Batch 115 of 207

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

- "input_input_snapshot_valid_event": "valid_event()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L56 | neighbors=[input_snapshot.cpp, append()]
- "integration_config_file_test_put_double": "put_double()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L50 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_float": "put_float()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L45 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_half": "put_half()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L42 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_null": "put_null()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L39 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_logging_guard_real_test": "config_logging_guard_real_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/config_logging_guard_real_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "integration_cube_golden_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L222 | neighbors=[cube_golden.py, run()]
- "integration_cube_golden_png_chunk": "png_chunk()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L26 | neighbors=[cube_golden.py, canonical_png()]
- "integration_cube_golden_x11_capture": ".capture()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L108 | neighbors=[run(), X11]
- "integration_cube_golden_x11_close": ".close()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L83 | neighbors=[run(), X11]
- "integration_cube_golden_x11_find_window": ".find_window()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L86 | neighbors=[run(), X11]
- "integration_logging_file_test_count_stamps": "count_stamps()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L15 | neighbors=[logging_file_test.cpp, main()]
- "integration_logging_file_test_read_file": "read_file()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L11 | neighbors=[logging_file_test.cpp, main()]
- "integration_public_header_compat": "public_header_compat.cpp" | kind=code-symbol | source=engine/rhi/tests/integration/public_header_compat.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "integration_sdl_platform_test": "sdl_platform_test.cpp" | kind=code-symbol | source=engine/platform/tests/integration/sdl_platform_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "integration_test_cube_fixed_view_x11": "test_cube_fixed_view_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_fixed_view_x11.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "integration_test_cube_golden_unit_goldenencodertests_test_reference_is_full_cube_with_three_lit_faces": ".test_reference_is_full_cube_with_three_lit_faces()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L101 | neighbors=[GoldenEncoderTests, decode()]
- "integration_test_cube_golden_unit_goldenencodertests_test_roundtrip_and_multiple_deflate_blocks": ".test_roundtrip_and_multiple_deflate_blocks()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L51 | neighbors=[GoldenEncoderTests, decode()]
- "integration_test_cube_x11_smoke_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_x11_smoke.py:L17 | neighbors=[test_cube_x11_smoke.py, main()]
- "integration_test_cube_x11_smoke_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_x11_smoke.py:L31 | neighbors=[test_cube_x11_smoke.py, find_window()]
- "integration_test_directional_light_x11": "test_directional_light_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_directional_light_x11.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "integration_test_imgui_inputs": "test_imgui_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_inputs.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Check the real ImGui demo rejects bad S…]
- "integration_test_imgui_toggle_x11_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_toggle_x11.py:L16 | neighbors=[test_imgui_toggle_x11.py, main()]
- "integration_test_imgui_toggle_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_toggle_x11.py:L23 | neighbors=[test_imgui_toggle_x11.py, find_window()]
- "integration_test_triangle_inputs": "test_triangle_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_inputs.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Check the real demo rejects bad SPIR-V …]
- "integration_test_version_command": "command()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L45 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()]
- "integration_test_version_copy_sources": "copy_sources()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L30 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()]
- "integration_test_version_main": "main()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L107 | neighbors=[test_version.py, parse_options()]
- "integration_test_version_parse_options": "parse_options()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L21 | neighbors=[test_version.py, main()]
- "integration_test_version_versionintegrationtests": "VersionIntegrationTests" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L54 | neighbors=[test_version.py, .test_real_binary_tracks_git_state()]
- "iplatform": "IPlatform" | kind=code-symbol | neighbors=[TestPlatform, ~SdlPlatform()]
- "lexer_lexer_decode": "decode()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L11 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_digit": "digit()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L43 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_digit_for": "digit_for()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L44 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_is_continue": "is_continue()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L51 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_is_start": "is_start()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L50 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_keyword": "keyword()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L52 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_string_body": "string_body()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L64 | neighbors=[lexer.cpp, lex()]
- "lexer_lexer_suffix": "suffix()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L56 | neighbors=[lexer.cpp, lex()]
- "lexer_unicode_xid": "unicode_xid.hpp" | kind=code-symbol | source=mute/src/lexer/unicode_xid.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, contains()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-114.json

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
