// DEMO-03: the client's control-plane session. One WebSocket connection
// carries SIGNIN, JOIN, framed INPUT and the per-tick SNAP broadcasts, so the
// client joins a live session on a network that drops UDP — the same payloads
// the UDP plane carries, per spec 06.
#ifndef POKO_CLIENT_CONTROL_SESSION_CLIENT_HPP
#define POKO_CLIENT_CONTROL_SESSION_CLIENT_HPP

#include "poko/net/frame.hpp"
#include "poko/net/tcp_socket.hpp"

#include <cstdint>
#include <deque>
#include <string>
#include <string_view>
#include <vector>

namespace poko::client::control {

// What a JOIN (or RECONNECT) reply hands the client: the session identity and
// the per-client frame key the INPUT channel is MAC'd with.
struct JoinTicket {
  std::uint32_t session_id = 0;
  std::uint32_t slot_id = 0;
  std::uint32_t version = 0;
  std::uint64_t nonce = 0;
  std::vector<std::uint8_t> frame_key;
  std::uint64_t tick = 0;
};

class SessionClient {
public:
  SessionClient() = default;
  ~SessionClient() { close(); }
  SessionClient(const SessionClient&) = delete;
  SessionClient& operator=(const SessionClient&) = delete;

  // Opens the TCP connection and performs the RFC 6455 upgrade. Throws on a
  // refused connection or a handshake the server did not accept.
  void connect(const std::string& host, std::uint16_t port, int timeout_ms = 5000);

  // Text verbs. Each waits up to `timeout_ms` for the reply that is not a tick
  // broadcast. Empty string means the server stayed silent.
  std::string sign_in(const std::string& firebase_uid, int timeout_ms = 4000);
  std::string join(const std::string& request_id, int timeout_ms = 4000);
  std::string request_state(int timeout_ms = 4000);
  std::string send_leave(int timeout_ms = 4000);

  // Framed game input inside the ticket's session; returns the ACK text.
  std::string send_input(std::uint32_t field_id, std::int64_t value, int timeout_ms = 4000);

  // Reads whatever the server pushed during `timeout_ms`. Returns the newest
  // SNAP payload seen ("" when the tick broadcast was quiet).
  std::string poll(int timeout_ms);

  void close();

  [[nodiscard]] bool connected() const { return sock_.is_open(); }
  [[nodiscard]] bool joined() const { return ticket_.session_id != 0; }
  [[nodiscard]] const JoinTicket& ticket() const { return ticket_; }
  [[nodiscard]] const std::string& last_snap() const { return latest_snap_; }
  [[nodiscard]] const std::string& last_error() const { return last_error_; }

private:
  std::string transact(const std::string& text, int timeout_ms);
  void send_payload(const std::string& text);
  void feed();
  bool handle_frame(const std::vector<std::uint8_t>& payload);
  void adopt_ticket(const std::vector<std::string>& words);
  void read_handshake_response(std::string_view key, int timeout_ms);

  net::TcpSocket sock_;
  std::string in_;
  std::string pending_reply_;
  JoinTicket ticket_;
  std::string latest_snap_;
  std::string last_error_;
  std::uint32_t next_seq_ = 1;
  std::uint32_t mask_counter_ = 0x9e3779b9u;
  std::deque<std::uint32_t> seen_;
};

} // namespace poko::client::control

#endif
