// DEMO-03: TCP sockets under the WebSocket transport. NET-07 gave the WS
// frame codec; this is the byte pipe it rides on, both directions, so the
// host can listen and the client can connect on Windows and POSIX alike.
#ifndef POKO_NET_TCP_SOCKET_HPP
#define POKO_NET_TCP_SOCKET_HPP

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX // the protocol headers use std::min/std::max
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <cerrno>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <cstdint>
#include <cstring>
#include <optional>
#include <stdexcept>
#include <string>

#include "poko/net/udp_echo.hpp" // ensure_wsa_started, last_socket_error_string

namespace poko::net {

#ifdef _WIN32
using native_socket = SOCKET;
inline constexpr native_socket kInvalidSocket = INVALID_SOCKET;
#else
using native_socket = int;
inline constexpr native_socket kInvalidSocket = -1;
#endif

inline void close_native_socket(native_socket s) {
  if (s == kInvalidSocket) return;
#ifdef _WIN32
  ::closesocket(s);
#else
  ::close(s);
#endif
}

inline bool socket_would_block() {
#ifdef _WIN32
  return ::WSAGetLastError() == WSAEWOULDBLOCK;
#else
  return errno == EWOULDBLOCK || errno == EAGAIN || errno == EINTR;
#endif
}

// One read from a TCP socket. `bytes > 0` carries data; `closed` is the peer
// hanging up cleanly; `would_block` is "nothing yet"; `error` is a real fault.
struct SocketRead {
  int bytes = 0;
  bool would_block = false;
  bool closed = false;
  bool error = false;
  std::string detail;
};

class TcpSocket {
public:
  TcpSocket() = default;
  explicit TcpSocket(native_socket fd) : fd_(fd) {}
  ~TcpSocket() { close(); }
  TcpSocket(const TcpSocket&) = delete;
  TcpSocket& operator=(const TcpSocket&) = delete;
  TcpSocket(TcpSocket&& other) noexcept : fd_(other.fd_) { other.fd_ = kInvalidSocket; }
  TcpSocket& operator=(TcpSocket&& other) noexcept {
    if (this != &other) {
      close();
      fd_ = other.fd_;
      other.fd_ = kInvalidSocket;
    }
    return *this;
  }

  void close() {
    close_native_socket(fd_);
    fd_ = kInvalidSocket;
  }

  [[nodiscard]] bool is_open() const { return fd_ != kInvalidSocket; }
  [[nodiscard]] native_socket native() const { return fd_; }

  void set_nonblocking(bool on) {
    if (!is_open()) throw std::runtime_error("tcp socket not open");
#ifdef _WIN32
    u_long mode = on ? 1u : 0u;
    if (::ioctlsocket(fd_, FIONBIO, &mode) != 0)
      throw std::runtime_error("tcp nonblocking: " + last_socket_error_string());
#else
    const int flags = ::fcntl(fd_, F_GETFL, 0);
    if (flags < 0) throw std::runtime_error("tcp nonblocking: " + last_socket_error_string());
    const int next = on ? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK);
    if (::fcntl(fd_, F_SETFL, next) != 0)
      throw std::runtime_error("tcp nonblocking: " + last_socket_error_string());
#endif
  }

  void set_nodelay() {
    const int one = 1;
    ::setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&one), sizeof(one));
  }

  // Readable within `timeout_ms`: 1 ready, 0 timed out, -1 fault.
  int wait_readable(int timeout_ms) const { return wait(true, timeout_ms); }

  // Writable within `timeout_ms`: 1 ready, 0 timed out, -1 fault.
  int wait_writable(int timeout_ms) const { return wait(false, timeout_ms); }

  [[nodiscard]] SocketRead read_some(std::uint8_t* buf, std::size_t cap) {
    SocketRead out;
    if (!is_open()) {
      out.error = true;
      out.detail = "socket closed";
      return out;
    }
    const int n = ::recv(fd_, reinterpret_cast<char*>(buf), static_cast<int>(cap), 0);
    if (n > 0) {
      out.bytes = n;
      return out;
    }
    if (n == 0) {
      out.closed = true;
      return out;
    }
    if (socket_would_block()) {
      out.would_block = true;
      return out;
    }
    out.error = true;
    out.detail = last_socket_error_string();
    return out;
  }

  // Blocks until every byte is handed to the kernel buffer (bounded by
  // `timeout_ms` per stall). Throws only on a real fault or a dead peer.
  void write_all(const std::uint8_t* data, std::size_t len, int timeout_ms = 2000) {
    std::size_t sent = 0;
    while (sent < len) {
      const int n = ::send(fd_, reinterpret_cast<const char*>(data + sent),
                           static_cast<int>(len - sent), 0);
      if (n > 0) {
        sent += static_cast<std::size_t>(n);
        continue;
      }
      if (socket_would_block()) {
        if (wait_writable(timeout_ms) <= 0)
          throw std::runtime_error("tcp write timed out");
        continue;
      }
      throw std::runtime_error("tcp write failed: " + last_socket_error_string());
    }
  }

private:
  int wait(bool readable, int timeout_ms) const {
    if (!is_open()) return -1;
    fd_set set;
    FD_ZERO(&set);
    FD_SET(fd_, &set);
    timeval tv{};
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    const int rc = ::select(static_cast<int>(fd_) + 1, readable ? &set : nullptr,
                            readable ? nullptr : &set, nullptr, &tv);
    return rc;
  }

  native_socket fd_ = kInvalidSocket;
};

class TcpListener {
public:
  TcpListener() = default;
  ~TcpListener() { close(); }
  TcpListener(const TcpListener&) = delete;
  TcpListener& operator=(const TcpListener&) = delete;

  // Lists on every IPv4 interface. Port 0 asks the OS for an ephemeral port
  // (the test does this); local_port() then reports the real one.
  void listen(std::uint16_t port) {
    close();
#ifdef _WIN32
    ensure_wsa_started();
#endif
    fd_ = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd_ == kInvalidSocket) throw std::runtime_error("tcp socket creation failed");
    const int one = 1;
    ::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&one), sizeof(one));
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (::bind(fd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
      throw std::runtime_error("tcp bind failed: " + last_socket_error_string());
    if (::listen(fd_, 16) != 0)
      throw std::runtime_error("tcp listen failed: " + last_socket_error_string());
    set_nonblocking_for(fd_, true);
  }

  [[nodiscard]] std::uint16_t local_port() const {
    if (fd_ == kInvalidSocket) return 0;
    sockaddr_in addr{};
#ifdef _WIN32
    int len = sizeof(addr);
#else
    socklen_t len = sizeof(addr);
#endif
    if (::getsockname(fd_, reinterpret_cast<sockaddr*>(&addr), &len) != 0) return 0;
    return ntohs(addr.sin_port);
  }

  [[nodiscard]] bool is_open() const { return fd_ != kInvalidSocket; }
  [[nodiscard]] native_socket native() const { return fd_; }

  int wait_readable(int timeout_ms) const {
    if (!is_open()) return -1;
    fd_set set;
    FD_ZERO(&set);
    FD_SET(fd_, &set);
    timeval tv{};
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    return ::select(static_cast<int>(fd_) + 1, &set, nullptr, nullptr, &tv);
  }

  // Non-blocking accept: nullopt when no connection is pending.
  std::optional<TcpSocket> accept() {
    if (!is_open()) return std::nullopt;
    const native_socket fd = ::accept(fd_, nullptr, nullptr);
    if (fd == kInvalidSocket) return std::nullopt;
    set_nonblocking_for(fd, true);
    return TcpSocket(fd);
  }

  void close() {
    close_native_socket(fd_);
    fd_ = kInvalidSocket;
  }

private:
  static void set_nonblocking_for(native_socket fd, bool on) {
#ifdef _WIN32
    u_long mode = on ? 1u : 0u;
    ::ioctlsocket(fd, FIONBIO, &mode);
#else
    const int flags = ::fcntl(fd, F_GETFL, 0);
    if (flags >= 0) ::fcntl(fd, F_SETFL, on ? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK));
#endif
  }

  native_socket fd_ = kInvalidSocket;
};

// "host:port" for a connected socket, the peer key the host protocol uses.
inline std::string tcp_peer_key(const TcpSocket& sock) {
  sockaddr_in addr{};
#ifdef _WIN32
  int len = sizeof(addr);
#else
  socklen_t len = sizeof(addr);
#endif
  if (::getpeername(sock.native(), reinterpret_cast<sockaddr*>(&addr), &len) != 0) return {};
  char host[INET_ADDRSTRLEN] = {};
  if (::inet_ntop(AF_INET, &addr.sin_addr, host, sizeof(host)) == nullptr) return {};
  return std::string(host) + ":" + std::to_string(ntohs(addr.sin_port));
}

// Connects to `host`:`port` (name or dotted quad), non-blocking under the
// hood so an unreachable host fails in `timeout_ms` instead of minutes.
inline TcpSocket tcp_connect(const std::string& host, std::uint16_t port, int timeout_ms = 5000) {
#ifdef _WIN32
  ensure_wsa_started();
#endif
  addrinfo hints{};
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  addrinfo* results = nullptr;
  const std::string service = std::to_string(port);
  if (::getaddrinfo(host.c_str(), service.c_str(), &hints, &results) != 0 || results == nullptr)
    throw std::runtime_error("tcp connect: cannot resolve " + host + ":" + service);

  TcpSocket sock;
  std::string last_error = "no address";
  for (const addrinfo* it = results; it != nullptr; it = it->ai_next) {
    native_socket fd = ::socket(it->ai_family, it->ai_socktype, it->ai_protocol);
    if (fd == kInvalidSocket) continue;
    TcpSocket candidate(fd);
    try {
      candidate.set_nonblocking(true);
    } catch (const std::exception&) {
      continue;
    }
    const int rc = ::connect(fd, it->ai_addr, static_cast<int>(it->ai_addrlen));
    if (rc != 0 && !socket_would_block()) {
      last_error = last_socket_error_string();
      continue;
    }
    if (candidate.wait_writable(timeout_ms) <= 0) {
      last_error = "connect timed out";
      continue;
    }
    int so_error = 0;
#ifdef _WIN32
    int len = sizeof(so_error);
#else
    socklen_t len = sizeof(so_error);
#endif
    if (::getsockopt(fd, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&so_error), &len) != 0 ||
        so_error != 0) {
      last_error = "connect refused";
      continue;
    }
    candidate.set_nodelay();
    sock = std::move(candidate);
    break;
  }
  ::freeaddrinfo(results);
  if (!sock.is_open()) throw std::runtime_error("tcp connect to " + host + ":" + service + " failed: " + last_error);
  return sock;
}

} // namespace poko::net

#endif
