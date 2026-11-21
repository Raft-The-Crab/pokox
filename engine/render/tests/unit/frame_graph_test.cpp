#include "poko/render/framegraph/frame_graph.hpp"

#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace poko::render;
#define CHECK(condition) do { if (!(condition)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #condition); return 1; \
} } while (false)

int main() {
  using E = FrameGraphError;
  {
    // The consumer is registered first; resource dependencies, not insertion
    // order, must place the producer before it.
    FrameGraph graph;
    std::vector<std::string> seen;
    CHECK(graph.add_pass({"consumer", {"color"}, {}, {}, [&] { seen.push_back("consumer"); }}) == E::none);
    CHECK(graph.add_pass({"producer", {}, {"color"}, {}, [&] { seen.push_back("producer"); }}) == E::none);
    auto plan = graph.compile();
    CHECK(plan.error == E::none && (plan.order == std::vector<std::string>{"producer", "consumer"}));
    CHECK(seen.empty());
    auto result = graph.execute();
    CHECK(result.error == E::none && result.completed == 2);
    CHECK((seen == std::vector<std::string>{"producer", "consumer"}));
    CHECK(graph.execute().completed == 2 && seen.size() == 4);
  }
  {
    // Exercise many acyclic resource graphs with reverse registration.
    // A callback independently checks that every declared producer ran.
    for (std::uint32_t seed = 1; seed <= 64; ++seed) {
      constexpr std::size_t count = 8;
      FrameGraph graph;
      std::vector<bool> ran(count, false);
      bool valid = true;
      for (std::size_t rev = count; rev > 0; --rev) {
        const std::size_t id = rev - 1;
        std::vector<std::size_t> inputs;
        std::vector<std::string> reads;
        for (std::size_t prior = 0; prior < id; ++prior) {
          auto mix = seed ^ (static_cast<std::uint32_t>(id) * 0x9e3779b9U) ^
                     (static_cast<std::uint32_t>(prior) * 0x85ebca6bU);
          mix ^= mix >> 16U;
          mix *= 0x7feb352dU;
          mix ^= mix >> 15U;
          if ((mix & 3U) == 0) {
            inputs.push_back(prior);
            reads.push_back("r" + std::to_string(prior));
          }
        }
        CHECK(graph.add_pass({"p" + std::to_string(id), reads, {"r" + std::to_string(id)}, {},
          [&, id, inputs] {
            for (const auto dependency : inputs) if (!ran[dependency]) valid = false;
            if (ran[id]) valid = false;
            ran[id] = true;
          }}) == E::none);
      }
      const auto result = graph.execute();
      CHECK(result.error == E::none && result.completed == count && valid);
      for (const bool did_run : ran) CHECK(did_run);
    }
  }
  {
    // Stable tie breaking, imported inputs, explicit edges and duplicate edges.
    FrameGraph graph;
    std::vector<std::string> seen;
    CHECK(graph.import_resource("external") == E::none);
    CHECK(graph.add_pass({"later", {"x", "y"}, {}, {"first"}, [&] { seen.push_back("later"); }}) == E::none);
    CHECK(graph.add_pass({"independent", {"external"}, {}, {}, [&] { seen.push_back("independent"); }}) == E::none);
    CHECK(graph.add_pass({"first", {}, {"x", "y"}, {}, [&] { seen.push_back("first"); }}) == E::none);
    CHECK(graph.add_pass({"tail", {}, {}, {"later"}, [&] { seen.push_back("tail"); }}) == E::none);
    CHECK(graph.execute().error == E::none);
    CHECK((seen == std::vector<std::string>{"independent", "first", "later", "tail"}));
  }
  {
    // No callbacks may run for any invalid graph, including an independent
    // ready node next to a dependency cycle.
    FrameGraph graph;
    int called = 0;
    CHECK(graph.add_pass({"ok", {}, {}, {}, [&] { ++called; }}) == E::none);
    CHECK(graph.add_pass({"a", {"b-out"}, {"a-out"}, {}, [&] { ++called; }}) == E::none);
    CHECK(graph.add_pass({"b", {"a-out"}, {"b-out"}, {}, [&] { ++called; }}) == E::none);
    CHECK(graph.compile().error == E::dependency_cycle);
    auto result = graph.execute();
    CHECK(result.error == E::dependency_cycle && result.completed == 0 && called == 0);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"self", {}, {}, {"self"}, [&] { ++called; }}) == E::none);
    CHECK(graph.execute().error == E::dependency_cycle && called == 0);
  }
  {
    // An import with a writer still orders readers after that writer.
    FrameGraph graph;
    std::vector<std::string> seen;
    CHECK(graph.import_resource("external") == E::none);
    CHECK(graph.add_pass({"read", {"external"}, {}, {}, [&] { seen.push_back("read"); }}) == E::none);
    CHECK(graph.add_pass({"write", {}, {"external"}, {}, [&] { seen.push_back("write"); }}) == E::none);
    CHECK(graph.execute().error == E::none);
    CHECK((seen == std::vector<std::string>{"write", "read"}));
  }
  {
    FrameGraph graph;
    int called = 0;
    const auto action = [&] { ++called; };
    CHECK(graph.add_pass({"consumer", {"missing"}, {}, {}, action}) == E::none);
    auto result = graph.execute();
    CHECK(result.error == E::unproduced_resource && result.detail == "missing" && called == 0);
    CHECK(graph.import_resource("missing") == E::none);
    CHECK(graph.execute().error == E::none && called == 1);
    CHECK(graph.import_resource("missing") == E::none);
    CHECK(graph.compile().error == E::duplicate_import);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {}, {}, {"absent"}, action}) == E::none);
    CHECK(graph.execute().error == E::unknown_dependency && called == 1);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {}, {"x"}, {}, action}) == E::none);
    CHECK(graph.add_pass({"b", {}, {"x"}, {"a"}, action}) == E::none);
    CHECK(graph.compile().error == E::multiple_writers);
    CHECK(graph.execute().completed == 0 && called == 1);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {"x"}, {"x"}, {}, action}) == E::none);
    CHECK(graph.compile().error == E::duplicate_resource_use);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {"x", "x"}, {}, {}, action}) == E::none);
    CHECK(graph.compile().error == E::duplicate_resource_use);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {}, {}, {}, action}) == E::none);
    CHECK(graph.add_pass({"a", {}, {}, {}, action}) == E::none);
    CHECK(graph.compile().error == E::duplicate_pass);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {}, {}, {}, {}}) == E::none);
    CHECK(graph.compile().error == E::missing_callback);
    CHECK(graph.clear() == E::none);
    CHECK(graph.import_resource("") == E::none);
    CHECK(graph.compile().error == E::empty_name);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"", {}, {}, {}, action}) == E::none);
    CHECK(graph.compile().error == E::empty_name);
    CHECK(graph.clear() == E::none);
    CHECK(graph.add_pass({"a", {""}, {}, {}, action}) == E::none);
    CHECK(graph.compile().error == E::empty_name);
  }
  {
    // Callback errors stop execution, record only completed callbacks and
    // release the execution guard so callers may rebuild safely.
    FrameGraph graph;
    int called = 0;
    CHECK(graph.add_pass({"one", {}, {}, {}, [&] { ++called; }}) == E::none);
    CHECK(graph.add_pass({"bad", {}, {}, {"one"}, [] { throw std::runtime_error("fail"); }}) == E::none);
    CHECK(graph.add_pass({"never", {}, {}, {"bad"}, [&] { ++called; }}) == E::none);
    const auto result = graph.execute();
    CHECK(result.error == E::callback_failed && result.detail == "bad" && result.completed == 1 && called == 1);
    CHECK(graph.clear() == E::none);
    CHECK(graph.execute().error == E::none);
  }
  {
    FrameGraph graph;
    E add = E::none, imported = E::none, cleared = E::none, compiled = E::none, nested = E::none;
    CHECK(graph.add_pass({"reentrant", {}, {}, {}, [&] {
      add = graph.add_pass({"new", {}, {}, {}, [] {}});
      imported = graph.import_resource("x");
      cleared = graph.clear();
      compiled = graph.compile().error;
      nested = graph.execute().error;
    }}) == E::none);
    CHECK(graph.execute().error == E::none);
    CHECK(add == E::busy && imported == E::busy && cleared == E::busy && compiled == E::busy && nested == E::busy);
    CHECK((graph.compile().order == std::vector<std::string>{"reentrant"}));
  }
  std::puts("PASS: frame-graph dependency ordering, validation and execution control");
}
