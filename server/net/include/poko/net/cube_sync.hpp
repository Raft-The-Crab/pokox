// NET-05: two demos move each other's cube — the first multiplayer moment.
// Each "demo" (peer) owns a cube with a position it moves locally; each
// sends its cube's state inside NET-03 frames (NET-04 delta payloads) and
// applies the remote peer's state. Loopback UDP via NET-01 sockets is the
// transport in the acceptance test; the same CubeSync works over any
// send/recv pair. Deterministic: positions are caller-supplied fixed-point
// style values, no wall clock inside the sync layer.
#ifndef POKO_NET_CUBE_SYNC_HPP
#define POKO_NET_CUBE_SYNC_HPP

#include "poko/net/bit_buffer.hpp"
#include "poko/net/delta.hpp"
#include "poko/net/frame.hpp"
#include "poko/net/udp_echo.hpp"

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

// The shared cube schema: x,y,z each quantized to 12 bits over [-100,100]
// meters (about 4.9 cm resolution), yaw to 8 bits over [0,360) degrees.
inline DeltaSchema cube_schema() {
  DeltaSchema schema;
  schema.add_float("x", -100.0, 100.0, 12);
  schema.add_float("y", -100.0, 100.0, 12);
  schema.add_float("z", -100.0, 100.0, 12);
  schema.add_uint("yaw", 8);
  return schema;
}

// One peer's cube state.
struct CubeState {
  double x = 0.0, y = 0.0, z = 0.0;
  std::uint8_t yaw = 0;

  std::vector<std::uint64_t> to_values() const {
    double dx = x, dy = y, dz = z;
    std::uint64_t bx, by, bz;
    std::memcpy(&bx, &dx, sizeof(bx));
    std::memcpy(&by, &dy, sizeof(by));
    std::memcpy(&bz, &dz, sizeof(bz));
    return std::vector<std::uint64_t>{bx, by, bz, yaw};
  }
  static CubeState from_values(const std::vector<std::uint64_t>& v) {
    if (v.size() != 4) throw std::runtime_error("cube state must have 4 fields");
    CubeState s;
    std::memcpy(&s.x, &v[0], sizeof(s.x));
    std::memcpy(&s.y, &v[1], sizeof(s.y));
    std::memcpy(&s.z, &v[2], sizeof(s.z));
    s.yaw = static_cast<std::uint8_t>(v[3]);
    return s;
  }
};

// One demo peer: owns a cube, packs its state into frames, applies the
// remote peer's state. baseline_ is what the remote last received from us,
// so deltas stay minimal.
class CubePeer {
public:
  explicit CubePeer(std::uint32_t session_id) : session_id_(session_id), schema_(cube_schema()) {}

  void set_local(const CubeState& state) { local_ = state; }
  const CubeState& local() const { return local_; }
  const CubeState& remote() const { return remote_; }
  bool has_remote() const { return has_remote_; }

  // Builds the outgoing frame carrying a delta of the local cube against
  // what the remote last received from us.
  std::vector<std::uint8_t> make_frame(const std::vector<std::uint8_t>& session_key, std::uint32_t seq,
                                       std::uint32_t ack, std::uint32_t ack_bits) {
    BitBuffer out;
    encode_delta(schema_, out, baseline_, local_.to_values());
    baseline_ = local_.to_values();

    FrameHeader header;
    header.session_id = session_id_;
    header.seq = seq;
    header.ack = ack;
    header.ack_bits = ack_bits;
    return pack_frame(header, out.bytes(), session_key);
  }

  // Applies an incoming verified frame: decodes the remote cube.
  void apply_frame(const FrameParse& parsed) {
    if (!parsed.ok) throw std::runtime_error("apply_frame requires a verified frame");
    BitBuffer in;
    for (std::size_t i = 0; i < parsed.payload.size(); ++i)
      for (unsigned bit = 0; bit < 8; ++bit)
        in.put_uint((parsed.payload[i] >> bit) & 1, 1);
    remote_ = CubeState::from_values(decode_delta(schema_, in, remote_baseline_));
    remote_baseline_ = remote_.to_values();
    has_remote_ = true;
  }

private:
  std::uint32_t session_id_;
  DeltaSchema schema_;
  CubeState local_;
  CubeState remote_;
  std::vector<std::uint64_t> baseline_ = std::vector<std::uint64_t>(4, 0);
  std::vector<std::uint64_t> remote_baseline_ = std::vector<std::uint64_t>(4, 0);
  bool has_remote_ = false;
};

// Loopback exchange for the acceptance test: run both peers' frames across
// NET-01 UDP sockets.
inline void exchange_over_udp(CubePeer& a, UdpSocket& a_sock, const std::string& b_host, std::uint16_t b_port,
                              CubePeer& b, UdpSocket& b_sock, const std::string& a_host, std::uint16_t a_port,
                              const std::vector<std::uint8_t>& session_key, std::uint32_t seq) {
  std::deque<std::uint32_t> seen_a, seen_b;
  auto fa = a.make_frame(session_key, seq, 0, 0);
  a_sock.send_to(b_host, b_port, fa);
  auto in_b = b_sock.receive(1000);
  if (in_b.error == SocketError::none) {
    auto pb = unpack_frame(in_b.payload, session_key, seen_b);
    if (pb.ok) b.apply_frame(pb);
  }
  auto fb = b.make_frame(session_key, seq, 0, 0);
  // B replies to A's source address learned from the first recv; if A's
  // datagram never arrived (in_b timed out) there is nothing to reply to.
  if (in_b.error == SocketError::none && !in_b.sender_host.empty())
    b_sock.send_to(in_b.sender_host, in_b.sender_port, fb);
  auto in_a = a_sock.receive(1000);
  if (in_a.error == SocketError::none) {
    auto pa = unpack_frame(in_a.payload, session_key, seen_a);
    if (pa.ok) a.apply_frame(pa);
  }
}

} // namespace poko::net

#endif
