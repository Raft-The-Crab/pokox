#pragma once
// Test-only stand-in for Diligent's BasicPlatformDebug; tracks the flag so
// diagnostics scope save/restore behavior can be exercised without the SDK.
namespace Diligent {
struct BasicPlatformDebug {
  static bool GetBreakOnError() { return g_break_on_error; }
  static void SetBreakOnError(bool value) { g_break_on_error = value; }
  inline static bool g_break_on_error = true;
};
}  // namespace Diligent
