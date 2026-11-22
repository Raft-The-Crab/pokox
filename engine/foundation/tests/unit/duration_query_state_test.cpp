#include "poko/foundation/duration_query_state.hpp"
#include <cstdio>
int main() {
  poko::stats::DurationQueryState state;
  int begins = 0, ends = 0, polls = 0;
  auto begin = [&] { ++begins; };
  auto end = [&] { ++ends; };
  auto unavailable = [&] { ++polls; return false; };
  auto available = [&] { ++polls; return true; };
  // No draw (e.g. minimized) means no query can be polled or ended.
  if (state.poll(available)) return 1;
  state.end(end);
  if (polls || ends) return 2;
  if (!state.begin(begin) || state.begin(begin)) return 3;
  state.end(end);
  // Repeated unready results must never start a replacement query.
  for (int i = 0; i < 8; ++i) {
    if (state.poll(unavailable) || state.begin(begin)) return 4;
  }
  if (begins != 1 || ends != 1 || polls != 8) return 5;
  if (!state.poll(available) || !state.begin(begin)) return 6;
  state.end(end);
  // A completed query is consumed even if its frequency is unusable.
  if (!state.poll(available) || !state.begin(begin)) return 7;
  state.end(end);
  if (begins != 3 || ends != 3 || polls != 10) return 8;
  std::puts("PASS: delayed, skipped and rearmed duration queries");
}
