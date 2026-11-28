// DEMO-01: the runnable PokoX server host (Dec 22 milestone).
//
//   pokox_host [--port N] [--ws-port N] [--tick-hz N] [--slots N]
//              [--schema file.pkb] [--secret S]
//
// --secret (or $POKO_TICKET_SECRET) is required: the HMAC ticket signer
// fails closed on an empty secret, and the host refuses to start without
// one. Ctrl+C stops the loop cleanly.
//
// Two transports, one protocol machine (spec 06): UDP datagrams and the
// DEMO-03 WebSocket listener both feed HostServer, so a client picks whichever
// its network allows. This file only owns sockets, timing and logging.
#include "poko/host/host.hpp"
#include "poko/host/ws_host.hpp"

#include "poko/net/udp_echo.hpp"

#include <algorithm>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace {

volatile std::sig_atomic_t g_stop = 0;
void on_signal(int) { g_stop = 1; }

std::string trim(const std::string& s) {
  std::size_t b = s.find_first_not_of(" \t\r\n");
  if (b == std::string::npos) return {};
  std::size_t e = s.find_last_not_of(" \t\r\n");
  return s.substr(b, e - b + 1);
}

std::uint64_t elapsed_ms_since(const std::chrono::steady_clock::time_point& t0) {
  return static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t0).count());
}

} // namespace

int main(int argc, char** argv) {
  poko::host::HostConfig cfg;
  std::string schema_path;

  std::uint16_t port = 7777;
  std::uint16_t ws_port = 7778; // 0 disables the WebSocket listener
  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];
    const auto next = [&]() -> std::string {
      return i + 1 < argc ? std::string(argv[++i]) : std::string();
    };
    if (arg == "--port") {
      const std::string v = next();
      if (v.empty() || v.find_first_not_of("0123456789") != std::string::npos || v.size() > 5) {
        std::cerr << "--port needs a numeric value\n";
        return 2;
      }
      port = static_cast<std::uint16_t>(std::strtoul(v.c_str(), nullptr, 10));
    } else if (arg == "--ws-port") {
      const std::string v = next();
      if (v.empty() || v.find_first_not_of("0123456789") != std::string::npos || v.size() > 5) {
        std::cerr << "--ws-port needs a numeric value (0 disables)\n";
        return 2;
      }
      ws_port = static_cast<std::uint16_t>(std::strtoul(v.c_str(), nullptr, 10));
    } else if (arg == "--tick-hz") {
      const std::string v = next();
      if (v.empty()) { std::cerr << "--tick-hz needs a value\n"; return 2; }
      cfg.tick_hz = std::strtoul(v.c_str(), nullptr, 10);
      if (cfg.tick_hz == 0) { std::cerr << "--tick-hz must be >= 1\n"; return 2; }
    } else if (arg == "--slots") {
      const std::string v = next();
      if (v.empty()) { std::cerr << "--slots needs a value\n"; return 2; }
      cfg.platform_slots = std::strtoul(v.c_str(), nullptr, 10);
    } else if (arg == "--schema") {
      schema_path = next();
      if (schema_path.empty()) { std::cerr << "--schema needs a path\n"; return 2; }
    } else if (arg == "--secret") {
      cfg.ticket_secret = next();
    } else if (arg == "--help" || arg == "-h") {
      std::cout << "usage: pokox_host [--port N] [--ws-port N] [--tick-hz N] [--slots N]"
                   " [--schema file] [--secret S]   (secret falls back to $POKO_TICKET_SECRET,"
                   " --ws-port 0 disables the WebSocket listener)\n";
      return 0;
    } else {
      std::cerr << "unknown argument: " << arg << "\n";
      return 2;
    }
  }

  if (cfg.ticket_secret.empty()) {
    if (const char* env = std::getenv("POKO_TICKET_SECRET")) cfg.ticket_secret = env;
  }
  if (cfg.ticket_secret.empty()) {
    std::cerr << "error: no ticket secret. Pass --secret S or set $POKO_TICKET_SECRET "
                 "(the signer fails closed without one).\n";
    return 2;
  }

  if (!schema_path.empty()) {
    std::ifstream in(schema_path, std::ios::binary);
    if (!in) { std::cerr << "error: cannot read " << schema_path << "\n"; return 2; }
    std::stringstream ss;
    ss << in.rdbuf();
    if (const auto err = poko::authority::load_pkb_schema(ss.str(), cfg.schema); err.code != poko::authority::PkbLoadError::Code::none) {
      std::cerr << "error: schema load failed: " << err.detail << "\n";
      return 2;
    }
  } else if (const auto err = poko::authority::load_pkb_schema(poko::host::kDemoSchemaText, cfg.schema);
             err.code != poko::authority::PkbLoadError::Code::none) {
    std::cerr << "error: built-in demo schema is invalid: " << err.detail << "\n";
    return 2;
  }

  poko::host::HostServer host(std::move(cfg));
  for (std::uint32_t i = 1; i <= std::min<std::uint32_t>(host.config().platform_slots,
                                                         poko::matchmaker::SlotRegistry::kPlatformSlotsPerGame);
       ++i)
    host.add_slot(i, 0);

  std::signal(SIGINT, on_signal);
  std::signal(SIGTERM, on_signal);

  const auto& schema = host.config().schema;
  std::cout << "pokox host: game=" << schema.game_id << " version=" << host.config().game_version
            << " port=" << port << " tick_hz=" << host.config().tick_hz
            << " slots=" << host.config().platform_slots << " fields=" << schema.fields.size() << "\n";
  for (std::size_t i = 0; i < schema.fields.size(); ++i)
    std::cout << "  field " << (i + 1) << ": " << schema.fields[i].name << "\n";
  std::cout << "listening on udp/" << port << "\n";

  poko::net::UdpSocket sock;
  try {
    sock.open();
    sock.bind(port);
  } catch (const std::exception& e) {
    std::cerr << "error: cannot bind udp/" << port << ": " << e.what() << "\n";
    return 1;
  }

  std::unique_ptr<poko::host::WsHost> ws;
  if (ws_port != 0) {
    try {
      ws = std::make_unique<poko::host::WsHost>(host, ws_port);
    } catch (const std::exception& e) {
      std::cerr << "error: cannot listen on ws/" << ws_port << ": " << e.what() << "\n";
      return 1;
    }
    std::cout << "listening on ws/" << ws->port() << "\n";
  }

  const auto t0 = std::chrono::steady_clock::now();
  std::uint64_t last_tick = 0;
  while (g_stop == 0) {
    if (ws) {
      const auto ws_handled =
          ws->poll(elapsed_ms_since(t0) * host.config().tick_hz / 1000, 0);
      if (ws_handled > 0) std::cout << "ws: " << ws_handled << " payload(s)\n";
    }
    const auto now_ms = elapsed_ms_since(t0);
    const auto now_tick = now_ms * host.config().tick_hz / 1000;
    if (now_tick > last_tick) {
      last_tick = now_tick;
      for (const auto& out : host.tick(now_tick)) {
        if (ws && ws->deliver(out)) continue;
        const auto sep = out.peer_key.rfind(':');
        if (sep == std::string::npos) continue;
        sock.send_to(out.peer_key.substr(0, sep),
                     static_cast<std::uint16_t>(std::strtoul(out.peer_key.c_str() + sep + 1, nullptr, 10)),
                     out.bytes);
      }
    }
    const auto now_ms2 = elapsed_ms_since(t0);
    const auto next_tick_ms = (last_tick + 1) * 1000 / host.config().tick_hz;
    const auto wait = next_tick_ms > now_ms2 ? next_tick_ms - now_ms2 : 0;
    // With WebSocket peers the UDP wait is capped so their frames are serviced
    // at a few milliseconds' latency instead of one tick.
    const auto limit = ws ? std::min<std::uint64_t>(wait, 5) : wait;
    auto recv = sock.receive(static_cast<int>(std::min<std::uint64_t>(limit, 50)));
    if (recv.error != poko::net::SocketError::none || recv.payload.empty()) continue;
    const std::string peer_key = recv.sender_host + ":" + std::to_string(recv.sender_port);
    auto reply = host.handle_datagram(peer_key, recv.payload.data(), recv.payload.size(),
                                      elapsed_ms_since(t0) * host.config().tick_hz / 1000);
    std::cout << peer_key << " " << std::string(recv.payload.begin(), recv.payload.end()).substr(0, 32) << " -> "
              << (reply.empty() ? std::string("(silence)") : std::string(reply.begin(), reply.end()).substr(0, 48))
              << "\n";
    if (!reply.empty()) sock.send_to(recv.sender_host, recv.sender_port, reply);
  }

  std::cout << "shutting down\n";
  return 0;
}
