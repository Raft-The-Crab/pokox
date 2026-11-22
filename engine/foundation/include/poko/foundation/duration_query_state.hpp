#pragma once

namespace poko::stats {
// Non-blocking single-query scheduler. A result must be collected before the
// query can be begun again; skipped frames simply do not produce samples.
class DurationQueryState {
 public:
  template <typename Begin>
  bool begin(Begin&& begin_query) {
    if (active_ || pending_) return false;
    begin_query();
    active_ = true;
    return true;
  }
  template <typename End>
  void end(End&& end_query) {
    if (!active_) return;
    end_query();
    active_ = false;
    pending_ = true;
  }
  template <typename Poll>
  bool poll(Poll&& poll_query) {
    if (!pending_ || !poll_query()) return false;
    pending_ = false;
    return true;
  }
 private:
  bool active_ = false;
  bool pending_ = false;
};
}  // namespace poko::stats
