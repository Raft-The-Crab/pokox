#include "poko/rhi/device/clear_backend_selection.hpp"
#include <array>
#include <cstdio>
#include <vector>
using namespace poko::rhi;
#define CHECK(x) do { if (!(x)) { std::fprintf(stderr,"FAIL %d: %s\n",__LINE__,#x); return 1; } } while(false)
struct Fake final : ClearBackend {
  int id; std::vector<int>& calls; RenderError init = RenderError::none, draw = RenderError::none;
  bool clean = true; std::array<float,4> seen{};
  Fake(int n, std::vector<int>& c) : id(n), calls(c) {}
  RenderError initialize() noexcept override { calls.push_back(id*10+1); return init; }
  RenderError clear_and_present(const std::array<float,4>& color) noexcept override { calls.push_back(id*10+2); seen=color; return draw; }
  bool shutdown() noexcept override { calls.push_back(id*10+3); return clean; }
};
int main() {
  std::vector<int> calls; Fake primary{1,calls}, fallback{2,calls};
  const std::array<float,4> blue{0.035f,0.12f,0.28f,1.f};
  {
    ClearBackendSelection s{primary,fallback};
    CHECK(s.clear_and_present(blue)==RenderError::not_initialized);
    auto r=s.start(); CHECK(r.status==StartStatus::success && r.selected==SelectedBackend::primary && !r.fallback_attempted);
    CHECK(s.start().status==StartStatus::already_started);
    CHECK(s.clear_and_present(blue)==RenderError::none && primary.seen==blue);
    primary.draw=RenderError::resize_required;
    CHECK(s.clear_and_present(blue)==RenderError::resize_required && s.selected()==SelectedBackend::primary);
    CHECK(s.shutdown() && s.shutdown());
    CHECK((calls==std::vector<int>{11,12,12,13}));
    calls.clear(); primary.init=RenderError::device_creation_failed; primary.draw=RenderError::none;
    r=s.start(); CHECK(r.status==StartStatus::success && r.primary_error==RenderError::device_creation_failed && r.fallback_attempted && r.selected==SelectedBackend::fallback);
    CHECK((calls==std::vector<int>{11,13,21}));
    CHECK(s.clear_and_present(blue)==RenderError::none && fallback.seen==blue);
    CHECK(s.shutdown());
    calls.clear(); primary.init=RenderError::not_drawable;
    r=s.start(); CHECK(r.status==StartStatus::deferred && !r.fallback_attempted);
    CHECK((calls==std::vector<int>{11,13}));
    calls.clear(); primary.init=RenderError::device_creation_failed; fallback.init=RenderError::factory_unavailable;
    r=s.start(); CHECK(r.status==StartStatus::failed && r.fallback_error==RenderError::factory_unavailable && r.fallback_attempted);
    CHECK((calls==std::vector<int>{11,13,21,23}));
    calls.clear(); primary.clean=false;
    r=s.start(); CHECK(r.status==StartStatus::cleanup_failed && !r.fallback_attempted);
    CHECK(s.start().status==StartStatus::cleanup_failed);
    CHECK(s.clear_and_present(blue)==RenderError::not_initialized);
    CHECK((calls==std::vector<int>{11,13}));
    primary.clean=true; CHECK(s.shutdown());
    calls.clear(); fallback.clean=false;
    r=s.start(); CHECK(r.status==StartStatus::cleanup_failed && r.fallback_attempted);
    CHECK((calls==std::vector<int>{11,13,21,23}));
    CHECK(!s.shutdown()); fallback.clean=true; CHECK(s.shutdown());
  }
  calls.clear(); primary.init=RenderError::none; fallback.init=RenderError::none;
  { ClearBackendSelection s{primary,fallback}; CHECK(s.start().status==StartStatus::success); }
  CHECK((calls==std::vector<int>{11,13}));
  std::puts("PASS: startup fallback selection, teardown and failure paths (backend doubles)");
  return 0;
}
