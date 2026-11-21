# ENG-01–ENG-08 follow-up review

The owner requested another review before continuing to ENG-09. Existing platform, backend, resize, graph, shader and triangle tests were rerun on the Linux development host; see the ENG-09 report for exact current results and the earlier dated reports for the original target-device evidence. Review and tests reduce risk but are not proof that all defects or warnings are gone.

## Changes

- The experimental Vulkan triangle pass now binds its cached pipeline to the device that created it. Attempting to use that pass with a different device fails before further rendering or presentation. The renderer and diagnostics scope must outlive the pass, and the pass must be destroyed before renderer shutdown; reuse after renderer restart is unsupported (a raw pointer check cannot distinguish pointer-address reuse).
- The pass checks captured graphics errors after target binding, color/depth clearing and pipeline binding, stopping before subsequent GPU commands and presentation when an error is detected. Diligent can report errors asynchronously; the caller must continue monitoring diagnostics and teardown.
- Test-only Diligent doubles exercise the production pass, cache reuse and cross-device rejection, missing depth attachment, explicit depth state, draw sizes, and injected failures across shader/pipeline creation, binding, clearing and drawing. These are control-flow checks, not proof of real-driver behavior.

The original source organization, compatibility forwarding headers and existing assets remain in place. A new `engine/rhi/tests/fakes/triangle/` subfolder isolates declarations used only by the new test; production files remain in their respective RHI and render subfolders.

## Still open

Real Windows/MSVC, user hardware, Android, OpenGL/ES fallback and validation-layer acceptance are not established by this review. The graph remains CPU-only and does not manage GPU resources or barriers. Device-loss handling, general shader validation and production recovery are not implemented. Earlier infrastructure and phase gates remain open.
