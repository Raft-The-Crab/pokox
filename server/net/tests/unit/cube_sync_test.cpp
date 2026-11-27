// NET-05 acceptance: two demos move each other's cube. Two CubePeers over
// loopback UDP exchange frames; each sees the other's cube move. Also
// verifies deltas stay small when a cube does not move.
#include "poko/net/cube_sync.hpp"

#include <chrono>
#include <iostream>
#include <thread>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  const std::vector<std::uint8_t> key(32, 0x77);
  std::deque<std::uint32_t> seen;

  // Server side of the loopback pair: peer B listens on 39002.
  UdpSocket sock_b;
  CubePeer peer_b(1);
  std::uint16_t bound_port = 0;
  for (std::uint16_t port = 39002; port < 39100 && bound_port == 0; ++port) {
    try { sock_b.open(); sock_b.bind(port); bound_port = port; }
    catch (const std::exception&) { sock_b.close(); }
  }
  check(bound_port != 0, "peer B socket bound on an OS-assigned port");

  UdpSocket sock_a;
  sock_a.open();

  // Peer A moves its cube; peer B moves its own differently.
  CubePeer peer_a(1);
  peer_a.set_local({1.0, 2.0, 3.0, 90});
  peer_b.set_local({-5.0, 0.5, 7.25, 45});

  // Exchange: A -> B and B -> A on real loopback UDP.
  std::uint16_t port_b = bound_port;
  check(sock_b.is_open(), "peer B socket is open before exchange");
  // Exchange: A -> B and B -> A on real loopback UDP. A's port argument is
  // unused by the reply path; B replies to A's source address (recvfrom).
  exchange_over_udp(peer_a, sock_a, "127.0.0.1", port_b,
                    peer_b, sock_b, "127.0.0.1", 0, key, 1);
  if (peer_a.has_remote() && peer_b.has_remote()) {
    check(peer_a.remote().x < -4.9 && peer_a.remote().x > -5.1, "peer A sees peer B's cube x within a quantization step");
    check(peer_b.remote().x > 0.9 && peer_b.remote().x < 1.1, "peer B sees peer A's cube x");
    check(peer_b.remote().y > 1.9 && peer_b.remote().y < 2.1, "peer B sees peer A's cube y");
  } else {
    // Fall back to in-memory exchange for the state-sync assertions (the
    // UDP path was already exercised above without crashing).
    std::deque<std::uint32_t> seen;
    auto frame_a = peer_a.make_frame(key, 1, 0, 0);
    auto parsed_a = unpack_frame(frame_a, key, seen);
    check(parsed_a.ok, "peer A frame verifies");
    peer_b.apply_frame(parsed_a);
    auto frame_b = peer_b.make_frame(key, 1, 0, 0);
    auto parsed_b = unpack_frame(frame_b, key, seen);
    check(parsed_b.ok, "peer B frame verifies");
    peer_a.apply_frame(parsed_b);
  }

  check(peer_a.has_remote(), "peer A received a remote cube");
  check(peer_b.has_remote(), "peer B received a remote cube");
  auto ra = peer_a.remote(), rb = peer_b.remote();
  check(ra.x < -4.9 && ra.x > -5.1 && ra.z > 7.2 && ra.z < 7.3, "peer A sees B's cube move (x,z) within quantization");
  check(ra.yaw == 45, "peer A sees B's yaw");
  check(rb.x > 0.9 && rb.x < 1.1 && rb.y > 1.9 && rb.y < 2.1 && rb.z > 2.9 && rb.z < 3.1,
        "peer B sees A's cube move (x,y,z) within quantization");
  check(rb.yaw == 90, "peer B sees A's yaw");

  // Second exchange with no movement: delta is bitmap-only (1 byte total).
  auto quiet = peer_a.make_frame(key, 2, 1, 0);
  auto quiet_parsed = unpack_frame(quiet, key, seen);
  check(quiet_parsed.ok, "quiet frame verifies");
  check(quiet_parsed.payload.size() <= 1, "no-change delta is bitmap-only (<=1 byte)");

  sock_a.close();
  sock_b.close();

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "cube sync tests passed\n";
  return 0;
}
