# SHL-07 Windows Verification & Audit Note (2026-11-27)

## 1. SHL-01..SHL-07 Windows MSVC Verification

- **Rust staticlib (`poko_shell`)**: Built cleanly on Windows with `cargo +stable-x86_64-pc-windows-msvc build --release --manifest-path client/windows/bridge/poko-shell/Cargo.toml` (produced `client/windows/bridge/poko-shell/target/release/poko_shell.lib`).
- **C++ bridge tests (compiled directly with MSVC `cl /std:c++20 /EHsc /MD` against `poko_shell.lib` + `ws2_32.lib userenv.lib bcrypt.lib ntdll.lib advapi32.lib psapi.lib`)**:
  - `c_abi_link_test`: **PASS** (`OK: all shell bridge link checks passed`)
  - `shell_create_test`: **PASS** (`OK: all shell create checks passed`)
  - `shell_events_test`: **PASS** (`OK: all shell event checks passed`)
  - `shell_frame_test`: **PASS** (`OK: all shell frame checks passed`)
  - `shell_mesh_test`: **PASS** (`OK: all shell mesh and texture checks passed`)
  - `shell_raii_test`: **PASS** (`rss before=7163904 after=7213056 delta=49152 bytes`, `cycles delta=-98304 bytes`, `OK: all shell RAII and flat-memory checks passed`)

## 2. Audit Findings for Next Agent

### A. `client/windows/bridge/poko-shell/src/lib.rs` Docstring vs Implementation
- **`poko_shell_mesh` sizing-call condition (lines 406–408 vs 448–451)**:
  - Docstring states: *"Sizing call: null `out_vertices` **and** `out_indices` write only the counts"*.
  - Implementation checks: `if out_vertices.is_null() || out_indices.is_null()` (`||` instead of `&&`).
  - Meanwhile `poko_shell_texture_delta` (lines 481–482 vs 509) states *"null `out_updates` **and** `out_pixels`"* and implements `out_updates.is_null() && out_pixels.is_null()`.
  - **Recommendation**: Align `poko_shell_mesh` to `&&` (matching its docstring and `poko_shell_texture_delta`) so passing one null and one non-null output buffer fails with `-2` rather than silently succeeding as a sizing call.
- Other exports (`poko_shell_create`, `poko_shell_destroy`, `poko_shell_push_event`, `poko_shell_drain_events`, `poko_shell_frame`) match their docstrings and unit tests.

### B. Windows CMake & Build Issues Blocking Full-Suite Parity
1. **`CMakeLists.txt` (`POKO_WITH_SHELL_BRIDGE`, lines 1475–1566)**:
   - Hardcodes `libpoko_shell.a` (Linux/MinGW staticlib name). On Windows MSVC, Cargo outputs `poko_shell.lib`, and linking into MSVC C++ requires `ws2_32`, `userenv`, `bcrypt`, `ntdll`, `advapi32`, plus `psapi` (for `GetProcessMemoryInfo` in `shell_raii_test.cpp`).
   - Requires `cbindgen` unconditionally (`find_program(POKO_CBINDGEN_EXECUTABLE NAMES cbindgen REQUIRED)`), even though `client/windows/bridge/c_abi/poko_shell.h` is already checked in.
   - Default `cargo` toolchain on this Windows host is `stable-x86_64-pc-windows-gnu` (fails on `parking_lot_core` because `dlltool.exe` is not installed); `stable-x86_64-pc-windows-msvc` works.
2. **`server/net/include/poko/net/udp_echo.hpp(8)`**:
   - Unconditionally includes `<arpa/inet.h>`, failing MSVC dependency scanning (`C1083`) for `pokox_net_udp_echo_test`, `pokox_net_cube_sync_test`, and `pokox_net_ws_transport_test`, which halts the Ninja build before building the remaining `server/*` test targets.
3. **MSVC `ctest --test-dir build-msvc` status**:
   - `106/137` passed (including `mute_g1_replay` in 57.94s and `pokox_character_controller_test` in 380.11s), `1` failed (`version_integration` — `cl.exe` not on ambient `PATH` in temp CMake configure), `30` `Not Run` due to the `<arpa/inet.h>` build stop.

### C. Next Row Readiness
- **SHL-07** is verified on Windows MSVC.
- **SHL-08** (panic boundary on all exports, forced panic returns `-3`) is clear to proceed; note `poko_shell_create` and `poko_shell_destroy` currently do not wrap `catch_unwind` (unlike `push_event`, `drain_events`, `frame`, `mesh`, `texture_delta`).
- Real windowed Vulkan UI render remains pending (`SHL-11`).

## 3. Directory Scaffold Created
Created full directory trees under `client/windows/`, `studio/` (`windows/`, `android/`, `shared/`), and `backend/` (`config/`, `docs/`, `infra/`, `jobs/`, `observability/`, `storage/`, `tests/`, `workers/`):
- `client/`: 269 directories (excluding Rust `target/`)
- `studio/`: 241 directories
- `backend/`: 228 directories
- **Total**: 738 directories
