// NET-06: XOR-FEC parity per spec 06. Gameplay packets go in groups of 4;
// the parity packet is pkt1^pkt2^pkt3^pkt4 and recovers any single loss in
// the group. Two losses in one group are unrecoverable (caller falls back
// to retransmit or interpolation). Groups are rotated so a burst loss hits
// different positions in different groups. XOR is integrity-oblivious, so
// parity packets carry the same HMAC as data packets: a corrupted parity is
// rejected by the frame check and never enters recovery.
#ifndef POKO_NET_XOR_FEC_HPP
#define POKO_NET_XOR_FEC_HPP

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

inline constexpr std::size_t kFecGroupSize = 4;

// XOR a set of equal-length byte vectors.
inline std::vector<std::uint8_t> xor_payloads(const std::vector<std::vector<std::uint8_t>>& payloads) {
  if (payloads.empty()) throw std::invalid_argument("no payloads to xor");
  std::size_t width = payloads[0].size();
  for (const auto& p : payloads)
    if (p.size() != width) throw std::invalid_argument("payloads must be equal length");
  std::vector<std::uint8_t> parity(width, 0);
  for (const auto& p : payloads)
    for (std::size_t i = 0; i < width; ++i) parity[i] ^= p[i];
  return parity;
}

struct FecGroup {
  std::vector<std::vector<std::uint8_t>> data;   // up to 4 payloads
  std::vector<bool> received;                    // which arrived
  std::vector<std::uint8_t> parity;              // XOR of all 4 (from parity packet)

  void init(std::size_t width) {
    data.assign(kFecGroupSize, std::vector<std::uint8_t>(width, 0));
    received.assign(kFecGroupSize, false);
    parity.clear();
  }
};

inline std::size_t losses(const FecGroup& group) {
  std::size_t lost = 0;
  for (bool r : group.received) if (!r) ++lost;
  return lost;
}

// Records the parity packet. Returns true when the group now has exactly
// one loss (recoverable).
inline bool attach_parity(FecGroup& group, std::vector<std::uint8_t> parity) {
  if (group.data.size() != kFecGroupSize) throw std::invalid_argument("group must hold 4 slots");
  group.parity = std::move(parity);
  return losses(group) == 1;
}

// Recovers the single lost payload from the parity. Throws when the group
// is complete or has more than one loss (unrecoverable).
inline std::vector<std::uint8_t> recover_loss(FecGroup& group) {
  if (losses(group) == 0) throw std::runtime_error("no loss to recover");
  if (losses(group) > 1) throw std::runtime_error("two losses in one group are unrecoverable");
  if (group.parity.empty()) throw std::runtime_error("parity packet not received");
  auto recovered = group.parity;
  for (std::size_t i = 0; i < kFecGroupSize; ++i)
    if (group.received[i])
      for (std::size_t b = 0; b < recovered.size(); ++b) recovered[b] ^= group.data[i][b];
  return recovered;
}

// Builds the parity packet payload for a group of gameplay datagrams
// (payloads only; each frame keeps its own HMAC).
inline std::vector<std::uint8_t> make_parity(const std::vector<std::vector<std::uint8_t>>& group_payloads) {
  if (group_payloads.size() != kFecGroupSize) throw std::invalid_argument("parity needs exactly 4 payloads");
  return xor_payloads(group_payloads);
}

// Rotates group membership across consecutive groups so a burst loss hits
// different positions: group g starts at (g*4) mod 16 in the 16-packet
// cycle. Returns the group's member stream indices (may be fewer at the
// stream tail).
inline std::vector<std::size_t> rotated_group(std::size_t group_index, std::size_t stream_length) {
  std::vector<std::size_t> members;
  std::size_t start = (group_index * kFecGroupSize) % (kFecGroupSize * kFecGroupSize);
  for (std::size_t i = 0; i < kFecGroupSize; ++i) {
    std::size_t idx = start + i;
    if (idx < stream_length) members.push_back(idx);
  }
  return members;
}

} // namespace poko::net

#endif
