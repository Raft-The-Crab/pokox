#pragma once

#include "poko/mute/state.hpp"
#include <cstddef>
#include <deque>
#include <span>
#include <string>
#include <string_view>

namespace poko::mute {
// One call borrows text only until write returns. A false return reports failure.
// The host owns the sink and context; neither may be retained by the callee.
struct PrintHost {
  bool (*write)(std::string_view text, void* context) = nullptr;
  void* context = nullptr;
};
// Evaluate one arithmetic expression, without hostcalls. May throw on allocation failure.
[[nodiscard]] std::string evaluate_console(std::string_view expression);
// Execute a top-level print, arithmetic expression, or initial function program.
// Calls the sink exactly once only after successful validation/evaluation. Program state is fresh on each console call.
[[nodiscard]] std::string execute_console(std::string_view source, PrintHost host = {});
// Persists only @state programs in the supplied context; ordinary expressions,
// print calls and stateless fn programs do not alter that context.
[[nodiscard]] std::string execute_console_stateful(std::string_view source, ProgramState& state, PrintHost host = {});

// Inspect only the terminated input text; stale bytes after NUL are ignored.
// A missing terminator or a zero-capacity buffer is treated as full.
[[nodiscard]] bool console_input_full(std::span<const char> buffer) noexcept;

// A bounded display log, not a general-purpose text sanitizer. ASCII control
// bytes and backslashes are escaped; other Unicode controls are not. Old entries
// are evicted FIFO to meet both budgets. Not a general logging/VM subsystem.
class ConsoleLog {
 public:
  ConsoleLog() = default;
  // The byte accounting and deque are one invariant; do not allow implicit
  // copies or moves to leave a partially updated or moved-from object usable.
  ConsoleLog(const ConsoleLog&) = delete;
  ConsoleLog& operator=(const ConsoleLog&) = delete;
  ConsoleLog(ConsoleLog&&) = delete;
  ConsoleLog& operator=(ConsoleLog&&) = delete;
  static constexpr std::size_t max_entries = 100;
  static constexpr std::size_t max_bytes = 65'536;
  static constexpr std::size_t max_input_bytes = 4095;
  [[nodiscard]] bool append(std::string_view text);
  void clear() noexcept;
  // Borrowed; entries can be invalidated by append, clear or destruction.
  [[nodiscard]] const std::deque<std::string>& entries() const noexcept { return entries_; }
  [[nodiscard]] std::size_t bytes() const noexcept { return bytes_; }
 private:
  std::deque<std::string> entries_;
  std::size_t bytes_ = 0;
};
} // namespace poko::mute
