// DEMO-03 acceptance: a real client joins a real host over a real loopback
// WebSocket — upgrade, SIGNIN, JOIN, tick snapshots, framed INPUT, LEAVE —
// and the listener survives handshakes it must refuse.
#include "poko/client/control/session_client.hpp"
#include "poko/host/ws_host.hpp"

#include <atomic>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

namespace {

int errors = 0;

void check(bool ok, const char* what) {
  if (ok) return;
  ++errors;
  std::cerr << "FAIL: " << what << "\n";
}

void eq(const std::string& got, const std::string& want, const char* what) {
  if (got == want) return;
  ++errors;
  std::cerr << "FAIL: " << what << " (got \"" << got << "\", want \"" << want << "\")\n";
}

void starts_with(const std::string& got, const std::string& prefix, const char* what) {
  if (got.rfind(prefix, 0) == 0) return;
  ++errors;
  std::cerr << "FAIL: " << what << " (got \"" << got << "\", want prefix \"" << prefix << "\")\n";
}

std::unique_ptr<poko::host::HostServer> make_host(std::uint32_t slots) {
  poko::host::HostConfig cfg;
  cfg.tick_hz = 1; // seconds are ticks, as in host_test: queue ETAs stay legible
  cfg.ticket_secret = "demo-secret";
  const auto err = poko::authority::load_pkb_schema(poko::host::kDemoSchemaText, cfg.schema);
  check(err.code == poko::authority::PkbLoadError::Code::none, "demo schema parses");
  auto host = std::make_unique<poko::host::HostServer>(std::move(cfg), 1);
  for (std::uint32_t i = 1; i <= slots; ++i) check(host->add_slot(i, 0), "slot registered");
  return host;
}

// The host's own loop: one thread servicing sockets and stepping ticks, the way
// main.cpp does with a UDP socket beside the WebSocket listener.
struct ServerLoop {
  poko::host::HostServer& host;
  poko::host::WsHost& ws;
  std::atomic<bool> running{true};
  std::uint64_t tick = 0;
  std::thread thread;

  void start() {
    thread = std::thread([this] { run(); });
  }

  void stop() {
    running = false;
    if (thread.joinable()) thread.join();
  }

  void run() {
    auto next_tick = std::chrono::steady_clock::now();
    while (running.load()) {
      ws.poll(tick, 2);
      const auto now = std::chrono::steady_clock::now();
      if (now >= next_tick) {
        ++tick;
        for (const auto& out : host.tick(tick)) ws.deliver(out);
        next_tick = now + std::chrono::milliseconds(250);
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
  }
};

std::string await_snapshot(poko::client::control::SessionClient& client, const std::string& needle) {
  std::string snap;
  for (int i = 0; i < 60; ++i) {
    snap = client.poll(50);
    if (!snap.empty() && snap.find(needle) != std::string::npos) return snap;
  }
  return snap;
}

} // namespace

int main() {
  auto host = make_host(1);
  poko::host::WsHost ws(*host, 0); // ephemeral port: parallel test runs never collide
  check(ws.port() != 0, "websocket listener bound an ephemeral port");

  ServerLoop loop{*host, ws};
  loop.start();

  poko::client::control::SessionClient client;
  try {
    client.connect("127.0.0.1", ws.port());
  } catch (const std::exception& e) {
    std::cerr << "FAIL: websocket connect: " << e.what() << "\n";
    loop.stop();
    return 1;
  }
  check(client.connected(), "client completed the websocket upgrade");

  eq(client.sign_in("alice-fb"), "OK SIGNIN u-000000000001", "sign-in over websocket");
  starts_with(client.join("req-1"), "OK JOIN 1 1 ", "join hands session 1 / slot 1");
  check(client.joined(), "client adopted the session ticket");
  check(client.ticket().frame_key.size() == 16, "ticket carries a 16-byte frame key");

  const std::string first_snap = await_snapshot(client, "SNAP ");
  starts_with(first_snap, "SNAP ", "tick snapshots arrive over the websocket");

  eq(client.send_input(1, 42), "ACK accepted 1", "framed input accepted over the websocket");
  const std::string projected = await_snapshot(client, "1=42");
  check(projected.find("1=42") != std::string::npos, "snapshot projects the accepted input");

  poko::client::control::SessionClient second;
  second.connect("127.0.0.1", ws.port());
  eq(second.sign_in("bob-fb"), "OK SIGNIN u-000000000002", "second client signs in");
  starts_with(second.join("req-2"), "OK JOIN 1 1 ", "a second client joins the same live session");
  check(second.joined() && second.ticket().frame_key != client.ticket().frame_key,
        "each client gets its own frame key");
  second.close();

  {
    // A plain HTTP request is not an upgrade: the listener must drop it and
    // keep serving.
    auto raw = poko::net::tcp_connect("127.0.0.1", ws.port());
    const std::string garbage = "GET / HTTP/1.1\r\nHost: x\r\n\r\n";
    raw.write_all(reinterpret_cast<const std::uint8_t*>(garbage.data()), garbage.size());
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }

  poko::client::control::SessionClient third;
  try {
    third.connect("127.0.0.1", ws.port());
  } catch (const std::exception& e) {
    std::cerr << "FAIL: reconnect after a refused handshake: " << e.what() << "\n";
    loop.stop();
    return 1;
  }
  eq(third.sign_in("carol-fb"), "OK SIGNIN u-000000000003", "listener survives a refused handshake");
  third.close();

  eq(client.send_leave(), "OK LEAVE", "leave over the websocket");

  client.close();
  loop.stop();
  ws.close_all();
  if (errors == 0) std::cout << "session_client_test: all checks passed\n";
  return errors == 0 ? 0 : 1;
}
