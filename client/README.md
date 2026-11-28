# Client

PokoX player application shells. Platform-specific folders live in `android/` and `windows/`; shared application code remains under `../applications/shared/` and `../applications/common/`. These directories are placeholders.

The first real client module is `windows/net/control` (DEMO-03): `SessionClient`
joins a live host over WebSocket (upgrade, `SIGNIN`, `JOIN`, framed `INPUT`,
SNAP polling, `LEAVE`), with a console demo at `windows/net/control/examples/connect_demo.cpp`
(`pokox_ws_client`). See `../server/host/README.md` for the wire contract.

Build and test the client/host pair on Windows (MSVC from `tools/msvc`; run these
from a shell with the environment `tools/msvc/msvcenv.bat` sets — its `MSVC`/`SDK`/
`PATH`/`INCLUDE`/`LIB` lines — but invoke cmake directly, that script ends in a full build):

```
cmake -S . -B .tmp-build/nmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_STANDARD=20 -DBUILD_TESTING=ON
cmake --build .tmp-build/nmake --target pokox_ws_client pokox_host pokox_client_control_test
ctest --test-dir .tmp-build/nmake -R pokox_client_control_test --output-on-failure
```

The NMake generator is used here because ninja cannot run any child process on this
machine: it prints no progress, uses no CPU and never exits — even for a three-line
`build.ninja` whose only rule is `cmd /c echo` — while `cl`, `link` and cmake
configure/`-n` dry runs work normally. The stall is in ninja's child spawning, not in
the project, so do not wait on a ninja build here; use NMake.

Resource/library tests, same directory:

```
cmake --build .tmp-build/nmake --target pokox_pokomesh_test pokox_asset_store_test \
      pokox_asset_allocation_test pokox_ktx2_test
ctest --test-dir .tmp-build/nmake -R "pokox_pokomesh_test|pokox_asset|pokox_ktx2" --output-on-failure
```

See the [client plan](../docs/plan/14-client.md) and [app interface plan](../docs/plan/12-app-interface.md).
