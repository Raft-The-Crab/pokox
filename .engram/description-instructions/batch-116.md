# Node Description Batch 117 of 209

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

- "frostpeak_frost_props_roll_well": "roll_well()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L172 | neighbors=[frost_props.py, village-square roll well: stone ring, t…]
- "frostpeak_frost_props_snow_pine": "snow_pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L34 | neighbors=[frost_props.py, grove pine re-shaded: every up-facing t…]
- "gles_clear_pokoactivity_pokoactivity_nativeinit": ".nativeInit()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L16 | neighbors=[PokoActivity, .onCreate()]
- "gles_clear_pokoactivity_pokoactivity_oncreate": ".onCreate()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L20 | neighbors=[PokoActivity, .nativeInit()]
- "gles_clear_pokoactivity_pokoactivity_ondestroy": ".onDestroy()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L46 | neighbors=[PokoActivity, .nativeSurfaceDestroyed()]
- "gles_clear_pokoactivity_pokoactivity_surfacechanged": ".surfaceChanged()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L36 | neighbors=[PokoActivity, .nativeSetSurface()]
- "gles_clear_pokoactivity_pokoactivity_surfacecreated": ".surfaceCreated()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L29 | neighbors=[PokoActivity, .nativeSetSurface()]
- "gles_clear_pokoactivity_pokoactivity_surfacedestroyed": ".surfaceDestroyed()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L41 | neighbors=[PokoActivity, .nativeSurfaceDestroyed()]
- "godot_ablation_report_luminance": "luminance()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L40 | neighbors=[ablation_report.py, image_change()]
- "godot_ablation_report_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L118 | neighbors=[ablation_report.py, analyse()]
- "hermes_init": "__init__.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "hermes_plugin_init_strip_frontmatter": "_strip_frontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L35 | neighbors=[__init__.py, _build_bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_contains_using_superpowers_body": ".test_contains_using_superpowers_body()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L64 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_frontmatter_stripped": ".test_frontmatter_stripped()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L71 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_marker_and_wrapper": ".test_marker_and_wrapper()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L58 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_skill_view_guidance_present": ".test_skill_view_guidance_present()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L88 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_under_hermes_context_spill_limit": ".test_under_hermes_context_spill_limit()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L92 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testskillsdirresolution": "TestSkillsDirResolution" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L46 | neighbors=[test_bootstrap.py, .test_repo_layout_resolves()]
- "hermes_test_bootstrap_testskillsdirresolution_test_repo_layout_resolves": ".test_repo_layout_resolves()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L47 | neighbors=[TestSkillsDirResolution, _load()]
- "hermes_test_bootstrap_teststripfrontmatter_test_no_frontmatter_returns_trimmed_content": ".test_no_frontmatter_returns_trimmed_content()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L35 | neighbors=[TestStripFrontmatter, _load()]
- "hermes_test_bootstrap_teststripfrontmatter_test_strips_surrounding_whitespace_from_body": ".test_strips_surrounding_whitespace_from_body()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L40 | neighbors=[TestStripFrontmatter, _load()]
- "hermes_test_bootstrap_teststripfrontmatter_test_strips_yaml_block": ".test_strips_yaml_block()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L30 | neighbors=[TestStripFrontmatter, _load()]
- "hermes_test_plugin_testlayoutresolution_test_missing_skills_raises_loudly": ".test_missing_skills_raises_loudly()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L155 | neighbors=[TestLayoutResolution, ._load_from()]
- "hermes_test_plugin_testpluginregistration_test_register_attaches_only_pre_llm_call_hook": ".test_register_attaches_only_pre_llm_call_hook()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L42 | neighbors=[TestPluginRegistration, _load_plugin()]
- "hermes_test_plugin_testpluginregistration_test_register_registers_every_stock_skill_as_path": ".test_register_registers_every_stock_skill_as_path()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L47 | neighbors=[TestPluginRegistration, _load_plugin()]
- "hermes_test_plugin_testpluginregistration_test_registered_skills_match_skill_directories": ".test_registered_skills_match_skill_directories()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L61 | neighbors=[TestPluginRegistration, _load_plugin()]
- "hermes_test_plugin_testskilldescriptions_test_descriptions_match_the_skill_frontmatter": ".test_descriptions_match_the_skill_frontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L176 | neighbors=[TestSkillDescriptions, _load_plugin()]
- "hermes_test_plugin_testskilldescriptions_test_every_stock_skill_registers_a_description": ".test_every_stock_skill_registers_a_description()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L169 | neighbors=[TestSkillDescriptions, _load_plugin()]
- "hermes_test_plugin_testskilldescriptions_test_frontmatter_value_parsing": ".test_frontmatter_value_parsing()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L194 | neighbors=[TestSkillDescriptions, _load_plugin()]
- "identity_device_binding": "device_binding.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/device_binding.hpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, DeviceBindingService]
- "identity_device_binding_devicebindingservice": "DeviceBindingService" | kind=code-symbol | source=server/identity/include/poko/identity/device_binding.hpp:L40 | neighbors=[device_binding.hpp, .DeviceBindingService()]
- "identity_revocation_gate": "revocation_gate.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/revocation_gate.hpp:L1 | neighbors=[6568dc9 Update from ML AI Code, TicketIssuanceGate]
- "identity_revocation_gate_ticketissuancegate": "TicketIssuanceGate" | kind=code-symbol | source=server/identity/include/poko/identity/revocation_gate.hpp:L46 | neighbors=[revocation_gate.hpp, .TicketIssuanceGate()]
- "identity_sign_in_inmemoryaccountstore": "InMemoryAccountStore" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L31 | neighbors=[sign_in.hpp, AccountStore]
- "identity_sign_in_signinservice": "SignInService" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L69 | neighbors=[sign_in.hpp, .SignInService()]
- "identity_step_up": "step_up.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/step_up.hpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, StepUpService]
- "identity_step_up_stepupservice": "StepUpService" | kind=code-symbol | source=server/identity/include/poko/identity/step_up.hpp:L21 | neighbors=[step_up.hpp, .StepUpService()]
- "identity_velocity_loginvelocityservice": "LoginVelocityService" | kind=code-symbol | source=server/identity/include/poko/identity/velocity.hpp:L63 | neighbors=[velocity.hpp, .LoginVelocityService()]
- "identity_worker_auth_firebasetokenverifier": "FirebaseTokenVerifier" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L107 | neighbors=[worker_auth.hpp, .FirebaseTokenVerifier()]
- "identity_worker_auth_sessiontickets": "SessionTickets" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L229 | neighbors=[worker_auth.hpp, .SessionTickets()]

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
