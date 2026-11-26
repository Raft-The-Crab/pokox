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
// with typed errors rather than corrupting state.
//
// Ownership: every aggregate Value produced by make_*/copy/promote owns one
// reference and must be released exactly once. Values returned by get_index
// are borrowed (owned=false): they alias a container slot, cannot be
// released, and are invalidated when the container or store slot dies.
// Handles are generation-tagged so stale Values always fail validation
// instead of aliasing a recycled slot.

enum class ValueKind : std::uint8_t { integer, boolean, string, array };
enum class ValueErrorCode : std::uint8_t {
  ok, not_aggregate, wrong_kind, bounds, heap_exceeded, arena_exceeded,
  depth_exceeded, invalid_handle, cycle
};
struct ValueError { ValueErrorCode code{}; };

struct Value {
  ValueKind kind{ValueKind::integer};
  std::int64_t scalar{};    // integer/boolean payload
  std::uint64_t handle{};   // (generation << 32) | (slot_index + 1); 0 = none
  bool owned{true};         // false = borrowed container element
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
  AggregateStore() : AggregateStore(Limits{}) {}
  explicit AggregateStore(Limits limits) : limits_(limits) {}

  // Creation. Strings copy bytes into the arena; arrays fill with `fill`.
  [[nodiscard]] std::variant<Value,ValueError> make_string(std::string_view text);
  [[nodiscard]] std::variant<Value,ValueError> make_array(std::size_t length, Value fill = make_int(0));

  // Access. Bounds, kind, staleness and cycle violations are errors, never UB.
  // get_index returns a borrowed Value (owned=false).
  [[nodiscard]] std::variant<Value,ValueError> get_index(const Value& array, std::int64_t index) const;
  [[nodiscard]] std::variant<Value,ValueError> set_index(const Value& array, std::int64_t index, Value item);
  [[nodiscard]] std::variant<std::string_view,ValueError> as_string(const Value& v) const;
  [[nodiscard]] std::variant<std::size_t,ValueError> length(const Value& v) const;

  // Copies are deep for arrays/strings; scalars copy trivially.
  [[nodiscard]] std::variant<Value,ValueError> copy(const Value& v);

  // Releases an owned reference; borrowed Values are ignored. Objects die at
  // zero refs. Arena objects are reclaimed wholesale by reset_tick().
  void release(const Value& v);
  // End-of-tick: frees every arena object and releases their refs on heap
  // children. Promoted (RC heap) objects survive.
  void reset_tick();
  // Promote a value reachable from @state: moves it (and its children) to the
  // RC heap so reset_tick cannot free it. Ownership flag is preserved.
  [[nodiscard]] std::variant<Value,ValueError> promote(const Value& v, std::size_t depth = 0);

  [[nodiscard]] std::size_t live_objects() const noexcept { return live_; }
  [[nodiscard]] std::size_t heap_bytes_used() const noexcept { return heap_bytes_; }

 private:
  struct Object {
    ValueKind kind{};
    bool arena{true};
    bool occupied{false};        // slot in use
    std::uint32_t generation{0}; // bumped on every (re)allocation of this slot
    std::uint32_t refs{1};
    std::size_t bytes{};
    std::string text;                 // string payload
    std::vector<Value> items;         // array payload
  };
  [[nodiscard]] Object* object(const Value& v) const;
  [[nodiscard]] std::uint64_t handle_for(std::size_t slot) const noexcept;
  [[nodiscard]] std::variant<std::uint32_t,ValueError> alloc(ValueKind kind, std::size_t bytes); // 1-based slot
  [[nodiscard]] std::variant<Value,ValueError> copy_impl(const Value& v, std::size_t depth);
  [[nodiscard]] bool reaches(const Value& from, const Value& target) const;
  void free_slot(std::uint32_t slot); // 1-based slot index, iterative
  Limits limits_;
  std::vector<Object> objects_;
  std::size_t live_{}, heap_bytes_{};
  std::size_t arena_bytes_{};
};

} // namespace poko::mute
