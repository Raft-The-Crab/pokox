// DEMO-03: the host's WebSocket listener. Same protocol machine as the UDP
// loop — HANDLE_DATAGRAM in, replies out — with the NET-07 codec underneath
// and a per-connection peer key, so a client behind a blocking network can
// sign in, join a session and receive ticks over one TCP connection.
#ifndef POKO_HOST_WS_HOST_HPP
#define POKO_HOST_WS_HOST_HPP

#include "poko/host/host.hpp"

#include "poko/net/tcp_socket.hpp"
#include "poko/net/ws_handshake.hpp"

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace poko::host {

class WsHost {
public:
  WsHost(HostServer& host, std::uint16_t port, std::size_t max_connections = 32)
      : host_(host), max_connections_(max_connections) {
    listener_.listen(port);
  }

  WsHost(const WsHost&) = delete;
  WsHost& operator=(const WsHost&) = delete;

  [[nodiscard]] std::uint16_t port() const { return listener_.local_port(); }
  [[nodiscard]] std::size_t connection_count() const { return conns_.size(); }

  // Waits up to `timeout_ms` for the listener or a connection to become
  // readable, then drains every ready socket. Returns the number of payloads
  // handed to the protocol machine this call.
  std::size_t poll(std::uint64_t now_tick, int timeout_ms) {
    if (timeout_ms > 0) wait_once(timeout_ms);
    for (;;) {
      auto accepted = listener_.accept();
      if (!accepted) break;
      if (conns_.size() >= max_connections_) continue;
      Conn conn;
      conn.sock = std::move(*accepted);
      conn.peer_key = "ws:" + net::tcp_peer_key(conn.sock);
      if (conn.peer_key == "ws:") conn.peer_key = "ws:conn-" + std::to_string(next_id_++);
      conns_.push_back(std::move(conn));
    }

    std::size_t handled = 0;
    for (std::size_t i = 0; i < conns_.size();) {
      if (service(i, now_tick, handled)) {
        ++i;
      } else {
        conns_.erase(conns_.begin() + static_cast<std::ptrdiff_t>(i));
      }
    }
    return handled;
  }

  // Routes one tick's outgoing frame when its peer came in over WebSocket.
  // Returns false for UDP peers so the caller's datagram path still sees them.
  bool deliver(const Outgoing& out) {
    for (auto& conn : conns_) {
      if (conn.peer_key != out.peer_key) continue;
      try {
        send_bytes(conn, net::ws_encode_server(out.bytes));
      } catch (const std::exception&) {
        conn.sock.close();
      }
      return true;
    }
    return false;
  }

  void close_all() {
    for (auto& conn : conns_) conn.sock.close();
    conns_.clear();
  }

private:
  struct Conn {
    net::TcpSocket sock;
    std::string peer_key;
    std::string in;
    bool handshaken = false;
  };

  void wait_once(int timeout_ms) const {
    fd_set set;
    FD_ZERO(&set);
    net::native_socket max_fd = listener_.native();
    if (listener_.is_open()) FD_SET(listener_.native(), &set);
    for (const auto& conn : conns_) {
      if (!conn.sock.is_open()) continue;
      FD_SET(conn.sock.native(), &set);
      if (conn.sock.native() > max_fd) max_fd = conn.sock.native();
    }
    timeval tv{};
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    ::select(static_cast<int>(max_fd) + 1, &set, nullptr, nullptr, &tv);
  }

  static void send_bytes(Conn& conn, const std::vector<std::uint8_t>& bytes) {
    conn.sock.write_all(bytes.data(), bytes.size());
  }

  // Returns false when the connection is finished (closed, refused or dead).
  bool service(std::size_t index, std::uint64_t now_tick, std::size_t& handled) {
    Conn& conn = conns_[index];
    if (!conn.sock.is_open()) return false;
    try {
      std::uint8_t buf[4096];
      for (;;) {
        const auto read = conn.sock.read_some(buf, sizeof(buf));
        if (read.bytes > 0) {
          conn.in.append(reinterpret_cast<const char*>(buf), static_cast<std::size_t>(read.bytes));
          continue;
        }
        if (read.would_block) break;
        return false; // closed or faulted
      }
    } catch (const std::exception&) {
      return false;
    }

    try {
      return drain(conn, now_tick, handled);
    } catch (const std::exception&) {
      return false;
    }
  }

  bool drain(Conn& conn, std::uint64_t now_tick, std::size_t& handled) {
    for (;;) {
      if (!conn.handshaken) {
        const auto head_end = conn.in.find("\r\n\r\n");
        if (head_end == std::string::npos) {
          if (conn.in.size() > 8192) return false; // unbounded header: refuse
          return true;
        }
        const std::string head = conn.in.substr(0, head_end + 4);
        conn.in.erase(0, head_end + 4);
        const auto request = net::ws_parse_request(head);
        if (!request.ok) return false;
        const std::string response = net::ws_build_response(request.key);
        send_bytes(conn, std::vector<std::uint8_t>(response.begin(), response.end()));
        conn.handshaken = true;
        continue;
      }

      if (conn.in.empty()) return true;
      std::string frame_error;
      const auto* raw = reinterpret_cast<const std::uint8_t*>(conn.in.data());
      const std::size_t size = net::ws_frame_size(raw, conn.in.size(), &frame_error);
      if (size == 0) return frame_error.empty(); // wait for more, or drop the connection

      const std::uint8_t opcode = net::ws_frame_opcode(raw);
      if (opcode == net::kWsOpcodeClose) {
        send_bytes(conn, net::ws_encode_control(net::kWsOpcodeClose, {}));
        conn.in.clear();
        return false;
      }
      if (opcode == net::kWsOpcodePing) {
        send_bytes(conn, net::ws_encode_control(net::kWsOpcodePong, echoed_payload(raw)));
        conn.in.erase(0, size);
        continue;
      }

      std::size_t consumed = 0;
      const auto decoded = net::ws_decode(raw, size, &consumed);
      conn.in.erase(0, size);
      if (!decoded.ok) return false;
      auto reply = host_.handle_datagram(conn.peer_key, decoded.payload.data(), decoded.payload.size(), now_tick);
      ++handled;
      if (!reply.empty()) send_bytes(conn, net::ws_encode_server(reply));
    }
  }

  // Unmasks a validated control frame's application data (RFC 6455 §5.5.2
  // wants a Pong to carry the Ping's payload back unchanged).
  static std::vector<std::uint8_t> echoed_payload(const std::uint8_t* raw) {
    const bool masked = (raw[1] & net::kWsMaskBit) != 0;
    std::size_t payload_len = raw[1] & 0x7F;
    std::size_t header = 2;
    if (payload_len == 126) {
      payload_len = (std::size_t(raw[2]) << 8) | raw[3];
      header = 4;
    }
    const std::size_t mask_offset = header;
    const std::size_t data_offset = header + (masked ? 4 : 0);
    std::vector<std::uint8_t> out(payload_len);
    for (std::size_t i = 0; i < payload_len; ++i) {
      out[i] = raw[data_offset + i];
      if (masked) out[i] ^= raw[mask_offset + (i % 4)];
    }
    return out;
  }

  HostServer& host_;
  net::TcpListener listener_;
  std::vector<Conn> conns_;
  std::size_t max_connections_ = 32;
  std::uint64_t next_id_ = 1;
};

} // namespace poko::host

#endif
