// NET-06 acceptance: 1 loss recovered, 2 detected. XOR parity over a group
// of 4 recovers any single loss byte-exact; two losses are detected as
// unrecoverable; parity packets carry the same HMAC protection (a corrupted
// parity frame fails verification and never enters recovery).
#include "poko/net/frame.hpp"
#include "poko/net/xor_fec.hpp"

#include <iostream>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  const std::vector<std::uint8_t> key(32, 0x33);

  // Four gameplay frames with distinct payloads.
  std::vector<std::vector<std::uint8_t>> payloads;
  for (int i = 0; i < 4; ++i)
    payloads.push_back({static_cast<std::uint8_t>(0xA0 + i), 0x01, 0x02, static_cast<std::uint8_t>(i * 17)});
  auto parity = make_parity(payloads);
  check(parity.size() == payloads[0].size(), "parity is payload-width");

  // Loss pattern 1: packet 2 lost, parity arrives -> byte-exact recovery.
  {
    FecGroup group;
    group.init(payloads[0].size());
    for (std::size_t i = 0; i < 4; ++i) { group.data[i] = payloads[i]; group.received[i] = (i != 2); }
    check(attach_parity(group, parity), "single-loss group is recoverable");
    auto recovered = recover_loss(group);
    check(recovered == payloads[2], "lost packet 2 recovered byte-exact");
  }

  // Loss pattern 2: a different slot lost (packet 0) — rotation relevance.
  {
    FecGroup group;
    group.init(payloads[0].size());
    for (std::size_t i = 0; i < 4; ++i) { group.data[i] = payloads[i]; group.received[i] = (i != 0); }
    attach_parity(group, parity);
    auto recovered = recover_loss(group);
    check(recovered == payloads[0], "lost packet 0 recovered byte-exact");
  }

  // Two losses: detected, unrecoverable, no partial state.
  {
    FecGroup group;
    group.init(payloads[0].size());
    for (std::size_t i = 0; i < 4; ++i) { group.data[i] = payloads[i]; group.received[i] = (i != 2 && i != 3); }
    check(!attach_parity(group, parity), "two-loss group is not marked recoverable");
    bool threw = false;
    try { recover_loss(group); } catch (const std::runtime_error&) { threw = true; }
    check(threw, "recover_loss refuses a two-loss group");
  }

  // Parity corruption: the frame check drops it before recovery sees it.
  {
    FrameHeader header;
    header.seq = 10;
    auto parity_frame = pack_frame(header, parity, key);
    auto corrupted = parity_frame;
    corrupted[kHeaderBytes] ^= 0x04; // flip a parity payload bit
    std::deque<std::uint32_t> seen;
    auto parsed = unpack_frame(corrupted, key, seen);
    check(!parsed.ok && parsed.reject_reason == "hmac mismatch", "corrupted parity frame fails HMAC and is dropped");

    auto good = unpack_frame(parity_frame, key, seen);
    check(good.ok && good.payload == parity, "intact parity frame verifies");
  }

  // Rotation: 4 consecutive groups start at different offsets (burst loss
  // hits different positions).
  {
    auto g0 = rotated_group(0, 16), g1 = rotated_group(1, 16), g2 = rotated_group(2, 16);
    check(g0.size() == 4 && g1.size() == 4 && g2.size() == 4, "full groups hold 4 members");
    check(g0[0] == 0 && g1[0] == 4 && g2[0] == 8, "group starts rotate by 4");
    auto tail = rotated_group(5, 17); // (5*4)%16 = 4 -> members 4,5,6,7 of a 17-packet stream
    check(tail.size() == 4 && tail[0] == 4, "rotated start wraps mod 16");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "xor fec tests passed\n";
  return 0;
}
