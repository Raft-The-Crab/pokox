#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {

// Aggregate VM values and lifetimes (MUT-22 foundation). Values are either
// scalars or handles into an AggregateStore. Strings and arrays live in a
// per-tick bump arena; values reachable past the tick are promoted to a
// reference-counted heap. All external input is bounded; violations trap
// with the documented codes rather than corrupting state.

enum class ValueKind : std::uint8_t { integer, boolean, string, array };
enum class ValueErrorCode : std::uint8_t {
  ok, not_aggregate, wrong_kind, bounds, heap_exceeded, arena_exceeded,
  depth_exceeded, invalid_handle
};
struct ValueError { ValueErrorCode code{}; };

struct Value {
  ValueKind kind{ValueKind::integer};
  std::int64_t scalar{};   // integer/boolean payload
  std::uint32_t handle{};  // string/array object index + 1; 0 = none
};

[[nodiscard]] Value make_int(std::int64_t v) noexcept;
[[nodiscard]] Value make_bool(bool v) noexcept;

class AggregateStore {
 public:
  struct Limits {
    std::size_t max_string_bytes{1'048'576};
    std::size_t max_array_length{65'536};
    std::size_t max_depth{64};
    std::size_t heap_objects{65'536};
    std::size_t heap_bytes{67'108'864}; // 64 MiB
  };
  explicit AggregateStore(Limits limits = {}) : limits_(limits) {}

  // Creation. Strings copy bytes into the arena; arrays fill with `fill`.
  [[nodiscard]] std::variant<Value,ValueError> make_string(std::string_view text);
  [[nodiscard]] std::variant<Value,ValueError> make_array(std::size_t length, Value fill = make_int(0));

  // Access. Bounds and kind violations are errors, never UB.
  [[nodiscard]] std::variant<Value,ValueError> get_index(const Value& array, std::int64_t index) const;
  [[nodiscard]] std::variant<Value,ValueError> set_index(const Value& array, std::int64_t index, Value item);
  [[nodiscard]] std::variant<std::string_view,ValueError> as_string(const Value& v) const;
  [[nodiscard]] std::variant<std::size_t,ValueError> length(const Value& v) const;

  // Copies are deep for arrays/strings; scalars copy trivially.
  [[nodiscard]] std::variant<Value,ValueError> copy(const Value& v);

  // Releases decrement the refcount; objects die at zero. Arena objects are
  // released wholesale by reset_tick(). Promoted objects persist.
  void release(const Value& v);
  // End-of-tick: frees every arena object. Promoted (RC heap) objects survive.
  void reset_tick();
  // Promote a value reachable from @state: moves it (and its children) to the
  // RC heap so reset_tick cannot free it.
  [[nodiscard]] std::variant<Value,ValueError> promote(const Value& v, std::size_t depth = 0);

  [[nodiscard]] std::size_t live_objects() const noexcept { return live_; }
  [[nodiscard]] std::size_t heap_bytes_used() const noexcept { return heap_bytes_; }

 private:
  struct Object {
    ValueKind kind{};
    bool arena{true};
    std::uint32_t handle{0}; // 1-based slot index; 0 = dead
    std::uint32_t refs{1};
    std::size_t bytes{};
    std::string text;                 // string payload
    std::vector<Value> items;         // array payload
  };
  [[nodiscard]] std::variant<std::uint32_t,ValueError> alloc(ValueKind kind, std::size_t bytes);
  [[nodiscard]] Object* object(const Value& v) const;
  void free_object(std::uint32_t handle);
  Limits limits_;
  std::vector<Object> objects_;
  std::size_t live_{}, heap_bytes_{};
  std::size_t arena_bytes_{};
};

} // namespace poko::mute
