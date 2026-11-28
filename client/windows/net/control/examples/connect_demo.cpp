// DEMO-03: the console client. Joins a live host over WebSocket, prints every
// tick snapshot and streams one INPUT per snapshot — the manual counterpart of
// the automated session_client_test.
#include "poko/client/control/session_client.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

int main(int argc, char** argv) {
  std::string host = "127.0.0.1";
  std::uint16_t port = 7778;
  std::string uid = "demo-fb";
  int seconds = 6;

  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];
    const auto next = [&]() -> std::string { return (i + 1 < argc) ? argv[++i] : std::string(); };
    if (arg == "--host") host = next();
    else if (arg == "--port") port = static_cast<std::uint16_t>(std::stoul(next()));
    else if (arg == "--uid") uid = next();
    else if (arg == "--seconds") seconds = std::stoi(next());
    else {
      std::cerr << "usage: pokox_ws_client [--host 127.0.0.1] [--port 7778] [--uid demo-fb] [--seconds 6]\n";
      return 2;
    }
  }

  try {
    poko::client::control::SessionClient client;
    client.connect(host, port);
    std::cout << "connected ws://" << host << ":" << port << " (101 Switching Protocols)\n";

    std::cout << "signin: " << client.sign_in(uid) << "\n";
    std::cout << "join:   " << client.join("demo-request-1") << "\n";
    if (!client.joined()) {
      std::cerr << "not joined: " << client.last_error() << "\n";
      return 1;
    }

    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
    std::int64_t sent = 0;
    while (std::chrono::steady_clock::now() < deadline) {
      const std::string snap = client.poll(200);
      if (snap.empty()) continue;
      std::cout << "snap:   " << snap << "\n";
      std::cout << "ack:    " << client.send_input(1, sent++) << "\n";
    }
    std::cout << "leave:  " << client.send_leave() << "\n";
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "error: " << e.what() << "\n";
    return 1;
  }
}
