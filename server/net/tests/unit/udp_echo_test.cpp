// NET-01 acceptance: two logical processes echo — a server loop on one
// socket, a client on another (its own socket = its own process endpoint),
// a datagram goes out and the exact bytes come back; oversized datagrams
// are rejected; a quiet socket times out with would_block.
#include "poko/net/udp_echo.hpp"

#include <atomic>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  std::atomic<bool> stop_server{false};

  // Server endpoint: echo loop on port 39001.
  UdpSocket server;
  std::thread server_thread([&] {
    try { echo_server_loop(server, 39001, [&] { return stop_server.load(); }); }
    catch (const std::exception& e) { std::cerr << "server error: " << e.what() << "\n"; ++errors; }
  });

  // Client endpoint (its own socket, i.e. its own process address).
  // Wait for the server socket to be bound before the client sends: bind
  // happens on the server thread; without this the first datagram can land
  // on an unbound port and the round-trip loses bytes (the flake).
  bool server_ready = false;
  for (int i = 0; i < 50 && !server_ready; ++i) {
    FILE* probe = popen("ss -u -l 2>/dev/null | grep -c 39001", "r");
    if (probe) {
      int bound = 0;
      if (std::fscanf(probe, "%d", &bound) == 1 && bound > 0) server_ready = true;
      pclose(probe);
    }
    if (!server_ready) std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  check(server_ready, "echo server socket is bound before the client sends");

  UdpSocket client;
  client.open();
  std::vector<std::uint8_t> payload{'p', 'o', 'k', 'o', '-', 'e', 'c', 'h', 'o'};
  for (int round = 0; round < 3; ++round) {
    client.send_to("127.0.0.1", 39001, payload);
    RecvResult reply = client.receive(2000);
    check(reply.error == SocketError::none, "echo reply arrived");
    check(reply.payload == payload, "echo bytes are exact");
  }

  // Oversized datagram rejected client-side before it touches the wire.
  bool oversized_rejected = false;
  try { client.send_to("127.0.0.1", 39001, std::vector<std::uint8_t>(kMaxDatagramBytes + 1, 0)); }
  catch (const std::exception&) { oversized_rejected = true; }
  check(oversized_rejected, ">1200-byte datagram rejected");

  // Quiet socket: nothing sent to us, receive times out.
  RecvResult quiet = client.receive(50);
  check(quiet.error == SocketError::would_block, "no data yields would_block");

  // Max-size (1200 bytes) datagram round-trips.
  std::vector<std::uint8_t> max_payload(kMaxDatagramBytes, 0xAB);
  client.send_to("127.0.0.1", 39001, max_payload);
  RecvResult max_reply = client.receive(2000);
  check(max_reply.error == SocketError::none && max_reply.payload == max_payload, "1200-byte datagram round-trips");

  stop_server = true;
  server_thread.join();
  client.close();
  server.close();

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "udp echo tests passed\n";
  return 0;
}
