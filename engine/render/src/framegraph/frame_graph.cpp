#include "poko/render/framegraph/frame_graph.hpp"

#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace poko::render {
struct FrameGraph::Compiled {
  FrameGraphError error = FrameGraphError::none;
  std::string detail;
  std::vector<std::size_t> order;
};

FrameGraphError FrameGraph::import_resource(std::string name) {
  if (executing_) return FrameGraphError::busy;
  imports_.push_back(std::move(name));
  return FrameGraphError::none;
}
FrameGraphError FrameGraph::add_pass(FramePass pass) {
  if (executing_) return FrameGraphError::busy;
  passes_.push_back(std::move(pass));
  return FrameGraphError::none;
}
FrameGraphError FrameGraph::clear() noexcept {
  if (executing_) return FrameGraphError::busy;
  imports_.clear(); passes_.clear();
  return FrameGraphError::none;
}
FrameGraph::Compiled FrameGraph::build_plan() const {
  if (executing_) return {FrameGraphError::busy, {}, {}};
  std::unordered_set<std::string> imported;
  for (const auto& name : imports_) {
    if (name.empty()) return {FrameGraphError::empty_name, name, {}};
    if (!imported.insert(name).second) return {FrameGraphError::duplicate_import, name, {}};
  }
  std::unordered_map<std::string, std::size_t> names, writers;
  for (std::size_t i = 0; i < passes_.size(); ++i) {
    const auto& pass = passes_[i];
    if (pass.name.empty()) return {FrameGraphError::empty_name, pass.name, {}};
    if (!names.emplace(pass.name, i).second) return {FrameGraphError::duplicate_pass, pass.name, {}};
    if (!pass.execute) return {FrameGraphError::missing_callback, pass.name, {}};
    std::unordered_set<std::string> used;
    for (const auto* resources : {&pass.reads, &pass.writes}) {
      for (const auto& resource : *resources) {
        if (resource.empty()) return {FrameGraphError::empty_name, pass.name, {}};
        if (!used.insert(resource).second) return {FrameGraphError::duplicate_resource_use, resource, {}};
      }
    }
    for (const auto& resource : pass.writes)
      if (!writers.emplace(resource, i).second) return {FrameGraphError::multiple_writers, resource, {}};
  }
  std::vector<std::vector<std::size_t>> edges(passes_.size());
  std::vector<std::size_t> indegree(passes_.size(), 0);
  // A set avoids counting the same dependency twice when it is both explicit
  // and implied by multiple resources. Iteration order is never used to sort.
  std::vector<std::unordered_set<std::size_t>> predecessors(passes_.size());
  const auto add_edge = [&](std::size_t from, std::size_t to) {
    if (predecessors[to].insert(from).second) { edges[from].push_back(to); ++indegree[to]; }
  };
  for (std::size_t i = 0; i < passes_.size(); ++i) {
    const auto& pass = passes_[i];
    for (const auto& resource : pass.reads) {
      const auto writer = writers.find(resource);
      if (writer != writers.end()) add_edge(writer->second, i);
      else if (!imported.contains(resource)) return {FrameGraphError::unproduced_resource, resource, {}};
    }
    for (const auto& name : pass.after) {
      if (name.empty()) return {FrameGraphError::empty_name, pass.name, {}};
      const auto predecessor = names.find(name);
      if (predecessor == names.end()) return {FrameGraphError::unknown_dependency, name, {}};
      add_edge(predecessor->second, i);
    }
  }
  std::priority_queue<std::size_t, std::vector<std::size_t>, std::greater<>> ready;
  for (std::size_t i = 0; i < indegree.size(); ++i) if (indegree[i] == 0) ready.push(i);
  Compiled result;
  while (!ready.empty()) {
    const auto current = ready.top(); ready.pop();
    result.order.push_back(current);
    for (const auto next : edges[current]) if (--indegree[next] == 0) ready.push(next);
  }
  if (result.order.size() != passes_.size()) return {FrameGraphError::dependency_cycle, {}, {}};
  return result;
}
FrameGraphPlan FrameGraph::compile() const {
  const auto compiled = build_plan();
  FrameGraphPlan result{compiled.error, compiled.detail, {}};
  for (const auto index : compiled.order) result.order.push_back(passes_[index].name);
  return result;
}
FrameGraphExecution FrameGraph::execute() {
  const auto compiled = build_plan();
  if (compiled.error != FrameGraphError::none) return {compiled.error, compiled.detail, 0};
  struct Guard {
    bool& value;
    explicit Guard(bool& flag) : value(flag) { value = true; }
    ~Guard() { value = false; }
  } guard{executing_};
  std::size_t completed = 0;
  for (const auto index : compiled.order) {
    try { passes_[index].execute(); }
    catch (...) { return {FrameGraphError::callback_failed, passes_[index].name, completed}; }
    ++completed;
  }
  return {FrameGraphError::none, {}, completed};
}
} // namespace poko::render
