#pragma once

#include <cstddef>
#include <functional>
#include <string>
#include <vector>

namespace poko::render {
// This CPU-only skeleton uses logical names, not GPU resource handles.
// It is single-threaded; the graph and captured callback objects must outlive execution.
enum class FrameGraphError {
  none, busy, empty_name, duplicate_import, duplicate_pass, missing_callback,
  duplicate_resource_use, multiple_writers, unproduced_resource,
  unknown_dependency, dependency_cycle, callback_failed,
};

struct FramePass {
  std::string name;
  std::vector<std::string> reads;
  std::vector<std::string> writes;
  // Explicit predecessor pass names, for dependencies not expressed by resources.
  std::vector<std::string> after;
  std::function<void()> execute;
};

struct FrameGraphPlan {
  FrameGraphError error = FrameGraphError::none;
  // Offending name where applicable; a cycle may not identify one name.
  std::string detail;
  std::vector<std::string> order;
};

struct FrameGraphExecution {
  FrameGraphError error = FrameGraphError::none;
  std::string detail;
  // Only callbacks that returned normally count. Earlier side effects are not rolled back.
  std::size_t completed = 0;
};

// A logical resource has at most one writer. A reader runs after its writer,
// even if registered first. A resource with no writer must be imported.
// If an imported name is also written, all readers observe the writer's version;
// model the incoming and outgoing versions with distinct names if necessary.
// Reading and writing the same name in one pass is rejected: model versions
// as distinct names. This skeleton does not allocate GPU resources or barriers.
class FrameGraph final {
 public:
  FrameGraph() = default;
  FrameGraph(const FrameGraph&) = delete;
  FrameGraph& operator=(const FrameGraph&) = delete;
  FrameGraph(FrameGraph&&) = delete;
  FrameGraph& operator=(FrameGraph&&) = delete;

  // Build methods can allocate and throw. During a callback, mutation, compile
  // and nested execution return busy rather than invalidating the active plan.
  [[nodiscard]] FrameGraphError import_resource(std::string name);
  [[nodiscard]] FrameGraphError add_pass(FramePass pass);
  [[nodiscard]] FrameGraphError clear() noexcept;
  // Validate the complete graph before any callback runs. Unrelated ready passes
  // are ordered deterministically by their registration order.
  [[nodiscard]] FrameGraphPlan compile() const;
  [[nodiscard]] FrameGraphExecution execute();

 private:
  struct Compiled;
  [[nodiscard]] Compiled build_plan() const;
  std::vector<std::string> imports_;
  std::vector<FramePass> passes_;
  bool executing_ = false;
};
} // namespace poko::render
