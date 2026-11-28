#include "poko/client/control/session_client.hpp"

#include "poko/net/ws_handshake.hpp"
#include "poko/net/ws_transport.hpp"

#include <array>
#include <random>
#include <stdexcept>

namespace poko::client::control {
namespace {

std::vector<std::string> split_ws(const std::string& text) {
  std::vector<std::string> out;
  std::size_t pos = 0;
  while (pos <= text.size()) {
    const auto next = text.find(' ', pos);
    const auto end = next == std::string::npos ? text.size() : next;
    if (end > pos) out.push_back(text.substr(pos, end - pos));
    if (next == std::string::npos) break;
    pos = next + 1;
  }
  return out;
}

std::string as_text(const std::vector<std::uint8_t>& bytes) {
  return std::string(bytes.begin(), bytes.end());
}

std::string make_handshake_key() {
  std::array<std::uint8_t, 16> nonce{};
  std::random_device device;
  for (auto& byte : nonce) byte = static_cast<std::uint8_t>(device());
  return poko::net::base64_encode(nonce.data(), nonce.size());
}

bool is_tick_broadcast(const std::string& payload) {
  return payload.rfind("SNAP ", 0) == 0;
}

} // namespace

void SessionClient::connect(const std::string& host, std::uint16_t port, int timeout_ms) {
  close();
  sock_ = net::tcp_connect(host, port, timeout_ms);
  const std::string key = make_handshake_key();
  const std::string request = net::ws_build_request(host, port, key);
  sock_.write_all(reinterpret_cast<const std::uint8_t*>(request.data()), request.size(), timeout_ms);
  read_handshake_response(key, timeout_ms);
  mask_counter_ ^= static_cast<std::uint32_t>(port);
}

void SessionClient::read_handshake_response(std::string_view key, int timeout_ms) {
  std::uint8_t buf[1024];
  for (;;) {
    const auto at = in_.find("\r\n\r\n");
    if (at != std::string::npos) {
      const std::string head = in_.substr(0, at + 4);
      in_.erase(0, at + 4);
      std::string error;
      if (!net::ws_validate_response(head, key, error))
        throw std::runtime_error("websocket handshake rejected: " + error);
      return;
    }
    if (in_.size() > 16384) throw std::runtime_error("websocket handshake response too large");
    if (sock_.wait_readable(timeout_ms) <= 0) throw std::runtime_error("websocket handshake timed out");
    const auto read = sock_.read_some(buf, sizeof(buf));
    if (read.bytes > 0) {
      in_.append(reinterpret_cast<const char*>(buf), static_cast<std::size_t>(read.bytes));
      continue;
    }
    if (read.would_block) continue;
    throw std::runtime_error("websocket handshake: connection closed" +
                             (read.detail.empty() ? std::string() : ": " + read.detail));
  }
}

void SessionClient::send_payload(const std::string& text) {
  if (!sock_.is_open()) throw std::runtime_error("session client not connected");
  const std::vector<std::uint8_t> payload(text.begin(), text.end());
  mask_counter_ = mask_counter_ * 1664525u + 1013904223u;
  const auto frame = net::ws_encode_client(payload, mask_counter_);
  sock_.write_all(frame.data(), frame.size());
}

std::string SessionClient::transact(const std::string& text, int timeout_ms) {
  send_payload(text);
  const int deadline_ms = timeout_ms;
  int waited = 0;
  std::uint8_t buf[4096];
  while (waited < deadline_ms) {
    if (!in_.empty() || sock_.wait_readable(10) > 0) {
      const auto read = sock_.read_some(buf, sizeof(buf));
      if (read.bytes > 0) {
        in_.append(reinterpret_cast<const char*>(buf), static_cast<std::size_t>(read.bytes));
        feed();
        if (!pending_reply_.empty()) {
          std::string reply;
          reply.swap(pending_reply_);
          return reply;
        }
        continue;
      }
      if (read.closed || read.error) {
        last_error_ = "connection lost while waiting for a reply";
        return {};
      }
    }
    waited += 10;
  }
  last_error_ = "timed out waiting for a reply";
  return {};
}

void SessionClient::feed() {
  for (;;) {
    if (in_.empty()) return;
    std::string frame_error;
    const auto* raw = reinterpret_cast<const std::uint8_t*>(in_.data());
    const std::size_t size = net::ws_frame_size(raw, in_.size(), &frame_error);
    if (size == 0) {
      if (!frame_error.empty()) {
        last_error_ = "server frame refused: " + frame_error;
        in_.clear();
        sock_.close();
      }
      return;
    }
    const std::uint8_t opcode = net::ws_frame_opcode(raw);
    if (opcode == net::kWsOpcodeClose) {
      last_error_ = "server closed the websocket";
      in_.clear();
      sock_.close();
      return;
    }
    std::size_t consumed = 0;
    const auto decoded = net::ws_decode(raw, size, &consumed);
    in_.erase(0, size);
    if (!decoded.ok) continue; // pong/unknown control: nothing to surface
    handle_frame(decoded.payload);
  }
}

bool SessionClient::handle_frame(const std::vector<std::uint8_t>& payload) {
  if (ticket_.session_id != 0 && !ticket_.frame_key.empty()) {
    const auto parsed = net::unpack_frame(payload, ticket_.frame_key, seen_);
    if (parsed.ok) {
      const std::string text = as_text(parsed.payload);
      if (is_tick_broadcast(text)) {
        latest_snap_ = text;
        return false;
      }
      pending_reply_ = text;
      return true;
    }
  }
  const std::string text = as_text(payload);
  if (is_tick_broadcast(text)) {
    latest_snap_ = text;
    return false;
  }
  pending_reply_ = text;
  return true;
}

std::string SessionClient::poll(int timeout_ms) {
  latest_snap_.clear();
  if (!sock_.is_open()) return {};
  int waited = 0;
  std::uint8_t buf[4096];
  do {
    while (sock_.wait_readable(waited == 0 && timeout_ms > 0 ? timeout_ms : 0) > 0) {
      const auto read = sock_.read_some(buf, sizeof(buf));
      if (read.bytes <= 0) {
        if (read.closed || read.error) {
          last_error_ = "connection lost during poll";
          sock_.close();
          return latest_snap_;
        }
        break;
      }
      in_.append(reinterpret_cast<const char*>(buf), static_cast<std::size_t>(read.bytes));
    }
    feed();
    if (!latest_snap_.empty() || !sock_.is_open() || timeout_ms <= 0) break;
    waited += 20;
  } while (waited < timeout_ms);
  return latest_snap_;
}

void SessionClient::adopt_ticket(const std::vector<std::string>& words) {
  // OK JOIN <session> <slot> <version> <nonce> <key_hex> <tick>
  if (words.size() < 8) {
    last_error_ = "malformed JOIN reply";
    return;
  }
  JoinTicket next;
  next.session_id = static_cast<std::uint32_t>(std::stoul(words[2]));
  next.slot_id = static_cast<std::uint32_t>(std::stoul(words[3]));
  next.version = static_cast<std::uint32_t>(std::stoul(words[4]));
  next.nonce = std::stoull(words[5]);
  const std::string& hex = words[6];
  for (std::size_t i = 0; i + 1 < hex.size(); i += 2)
    next.frame_key.push_back(static_cast<std::uint8_t>(std::stoul(hex.substr(i, 2), nullptr, 16)));
  next.tick = std::stoull(words[7]);
  ticket_ = std::move(next);
  next_seq_ = 1;
  seen_.clear();
}

std::string SessionClient::sign_in(const std::string& firebase_uid, int timeout_ms) {
  return transact("SIGNIN " + firebase_uid, timeout_ms);
}

std::string SessionClient::join(const std::string& request_id, int timeout_ms) {
  const std::string reply = transact("JOIN " + request_id, timeout_ms);
  const auto words = split_ws(reply);
  if (!words.empty() && words[0] == "OK" && words.size() > 1 && words[1] == "JOIN") adopt_ticket(words);
  return reply;
}

std::string SessionClient::request_state(int timeout_ms) {
  return transact("STATE", timeout_ms);
}

std::string SessionClient::send_leave(int timeout_ms) {
  const std::string reply = transact("LEAVE", timeout_ms);
  if (reply == "OK LEAVE") {
    ticket_ = JoinTicket{};
    seen_.clear();
  }
  return reply;
}

std::string SessionClient::send_input(std::uint32_t field_id, std::int64_t value, int timeout_ms) {
  if (!joined()) {
    last_error_ = "send_input before JOIN";
    return {};
  }
  net::FrameHeader header;
  header.session_id = ticket_.session_id;
  header.seq = next_seq_++;
  header.priority = 0;
  const std::string text = "INPUT " + std::to_string(field_id) + " " + std::to_string(value);
  const std::vector<std::uint8_t> payload(text.begin(), text.end());
  const auto frame = net::pack_frame(header, payload, ticket_.frame_key);
  mask_counter_ = mask_counter_ * 1664525u + 1013904223u;
  const auto wire = net::ws_encode_client(frame, mask_counter_);
  sock_.write_all(wire.data(), wire.size());

  std::uint8_t buf[4096];
  int waited = 0;
  while (waited < timeout_ms) {
    if (!in_.empty() || sock_.wait_readable(10) > 0) {
      const auto read = sock_.read_some(buf, sizeof(buf));
      if (read.bytes > 0) {
        in_.append(reinterpret_cast<const char*>(buf), static_cast<std::size_t>(read.bytes));
        feed();
        if (!pending_reply_.empty()) {
          std::string reply;
          reply.swap(pending_reply_);
          return reply;
        }
        continue;
      }
      if (read.closed || read.error) {
        last_error_ = "connection lost while sending input";
        return {};
      }
    }
    waited += 10;
  }
  last_error_ = "input ack timed out";
  return {};
}

void SessionClient::close() {
  sock_.close();
  in_.clear();
  ticket_ = JoinTicket{};
  latest_snap_.clear();
  pending_reply_.clear();
  seen_.clear();
  next_seq_ = 1;
}

} // namespace poko::client::control
