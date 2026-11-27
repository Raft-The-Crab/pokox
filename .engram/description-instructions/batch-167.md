# Node Description Batch 168 of 208

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

- "frostpeak_frost_props_market_stall": "market_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L195 | neighbors=[frost_props.py] | lang=en
- "frostpeak_frost_props_sled": "sled()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L153 | neighbors=[frost_props.py] | lang=en
- "frostpeak_frost_props_snowman": "snowman()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L138 | neighbors=[frost_props.py] | lang=en
- "fuzz_fuzz_bytecode_llvmfuzzertestoneinput": "LLVMFuzzerTestOneInput()" | kind=code-symbol | source=fuzz/fuzz_bytecode.cpp:L4 | neighbors=[fuzz_bytecode.cpp] | lang=en
- "fuzz_fuzz_cbor_llvmfuzzertestoneinput": "LLVMFuzzerTestOneInput()" | kind=code-symbol | source=fuzz/fuzz_cbor.cpp:L4 | neighbors=[fuzz_cbor.cpp] | lang=en
- "fuzz_fuzz_lexer_llvmfuzzertestoneinput": "LLVMFuzzerTestOneInput()" | kind=code-symbol | source=fuzz/fuzz_lexer.cpp:L4 | neighbors=[fuzz_lexer.cpp] | lang=en
- "fuzz_fuzz_pokomesh_llvmfuzzertestoneinput": "LLVMFuzzerTestOneInput()" | kind=code-symbol | source=fuzz/fuzz_pokomesh.cpp:L4 | neighbors=[fuzz_pokomesh.cpp] | lang=en
- "godot_ablation_report_rationale_1": "Rank Godot graphics settings by frame-time cost against how much they change the" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L1 | neighbors=[ablation_report.py] | lang=en
- "godot_ablation_report_rationale_54": "Full-scene GPU ms and noise floors for one view." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L54 | neighbors=[view_baseline()] | lang=en
- "harness_golden_rationale_17": "Return the first differing offset and sizes, or None if files match." | kind=entity | source=tools/testutils/harness/golden.py:L17 | neighbors=[first_difference()] | lang=en
- "harness_golden_rationale_36": "Replace the reference atomically, only on an explicit update request." | kind=entity | source=tools/testutils/harness/golden.py:L36 | neighbors=[update_golden()] | lang=en
- "hermes_conftest_mock_ctx": "mock_ctx()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/conftest.py:L8 | neighbors=[conftest.py] | lang=en
- "hermes_plugin_init_rationale_41": "Return a flat ``key: value`` scalar from a SKILL.md frontmatter block.      Herm" | kind=entity | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L41 | neighbors=[_frontmatter_value()] | lang=pt
- "hermes_plugin_init_rationale_9": "Locate the stock skills/ tree for either supported install layout.      - git-cl" | kind=entity | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L9 | neighbors=[_skills_dir()] | lang=en
- "hermes_test_plugin_rationale_119": "Copy the plugin module + a minimal skills tree in the given layout." | kind=entity | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L119 | neighbors=[._stage()] | lang=en
- "hermes_test_plugin_rationale_165": "Hermes builds its skill catalogue from register_skill(description=...),     whic" | kind=entity | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L165 | neighbors=[TestSkillDescriptions] | lang=en
- "hermes_test_plugin_rationale_21": "Re-import plugin module fresh." | kind=entity | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L21 | neighbors=[_load_plugin()] | lang=en
- "identity_account_record": "account_record.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/account_record.hpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04] | lang=en
- "identity_device_binding_devicebindingservice_devicebindingservice": ".DeviceBindingService()" | kind=code-symbol | source=server/identity/include/poko/identity/device_binding.hpp:L42 | neighbors=[DeviceBindingService] | lang=en
- "identity_revocation_gate_ticketissuancegate_ticketissuancegate": ".TicketIssuanceGate()" | kind=code-symbol | source=server/identity/include/poko/identity/revocation_gate.hpp:L51 | neighbors=[TicketIssuanceGate] | lang=en
- "identity_sign_in_accountstore_accountstore": ".AccountStore()" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L22 | neighbors=[AccountStore] | lang=en
- "identity_sign_in_format_user_id": "format_user_id()" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L64 | neighbors=[sign_in.hpp] | lang=en
- "identity_sign_in_signinservice_signinservice": ".SignInService()" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L71 | neighbors=[SignInService] | lang=en
- "identity_step_up_stepupservice_stepupservice": ".StepUpService()" | kind=code-symbol | source=server/identity/include/poko/identity/step_up.hpp:L23 | neighbors=[StepUpService] | lang=en
- "identity_velocity_haversine_km": "haversine_km()" | kind=code-symbol | source=server/identity/include/poko/identity/velocity.hpp:L34 | neighbors=[velocity.hpp] | lang=en
- "identity_velocity_loginvelocityservice_loginvelocityservice": ".LoginVelocityService()" | kind=code-symbol | source=server/identity/include/poko/identity/velocity.hpp:L65 | neighbors=[LoginVelocityService] | lang=en
- "identity_worker_auth_base64url_decode": "base64url_decode()" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L42 | neighbors=[worker_auth.hpp] | lang=en
- "identity_worker_auth_base64url_encode": "base64url_encode()" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L65 | neighbors=[worker_auth.hpp] | lang=en
- "identity_worker_auth_firebasetokenverifier_firebasetokenverifier": ".FirebaseTokenVerifier()" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L114 | neighbors=[FirebaseTokenVerifier] | lang=en
- "identity_worker_auth_sessiontickets_sessiontickets": ".SessionTickets()" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L243 | neighbors=[SessionTickets] | lang=en
- "imgui_enginefactoryvk_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L10 | neighbors=[EngineFactoryVk.h] | lang=en
- "imgui_enginefactoryvk_graphicspipeline": "GraphicsPipeline()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L60 | neighbors=[EngineFactoryVk.h] | lang=en
- "imgui_enginefactoryvk_ideviceobject": "IDeviceObject()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L82 | neighbors=[EngineFactoryVk.h] | lang=en
- "imgui_enginefactoryvk_ienginefactory": "IEngineFactory()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L124 | neighbors=[EngineFactoryVk.h] | lang=en
- "imgui_enginefactoryvk_rtvformats": "RTVFormats()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L58 | neighbors=[EngineFactoryVk.h] | lang=en
- "imgui_refcntautoptr_refcntautoptr_refcntautoptr": ".RefCntAutoPtr()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/RefCntAutoPtr.hpp:L9 | neighbors=[RefCntAutoPtr] | lang=en
- "input_action_map_name": "name()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L337 | neighbors=[action_map.cpp] | lang=en
- "input_device_router_clear": "clear()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L103 | neighbors=[device_router.cpp] | lang=en
- "input_device_router_disconnect": "disconnect()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L47 | neighbors=[device_router.cpp] | lang=en
- "input_device_router_find": "find()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L62 | neighbors=[device_router.cpp] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-167.json

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
