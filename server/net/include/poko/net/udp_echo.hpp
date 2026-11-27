// NET-01: UDP socket echo. The first network primitive per spec 06: raw UDP
// datagrams between two processes, max 1,200 bytes per datagram (inside
// IPv6's 1,280-byte minimum MTU). POSIX sockets wrapped in a thin RAII
// surface; Windows winsock support lands with the desktop acceptance task.
#ifndef POKO_NET_UDP_ECHO_HPP
#define POKO_NET_UDP_ECHO_HPP

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <cerrno>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#endif
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace poko::net {

inline constexpr std::size_t kMaxDatagramBytes = 1200;

enum class SocketError {
  none = 0,
  would_block,    // no data within the timeout
  closed,         // socket not open
  network_down,   // sendto/recvfrom failed for a real reason
};

struct RecvResult {
  SocketError error = SocketError::none;
  std::vector<std::uint8_t> payload;
  std::string sender_host;
  std::uint16_t sender_port = 0;
};

#ifdef _WIN32
inline void ensure_wsa_started() {
  struct WsaInit {
    WsaInit() {
      WSADATA wsa{};
      if (::WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        throw std::runtime_error("WSAStartup failed");
    }
    ~WsaInit() { ::WSACleanup(); }
  };
  static WsaInit init;
}

inline std::string last_socket_error_string() {
  return "wsa error " + std::to_string(::WSAGetLastError());
}
#else
inline std::string last_socket_error_string() {
  return std::strerror(errno);
}
#endif

class UdpSocket {
public:
  UdpSocket() = default;
  ~UdpSocket() { close(); }
  UdpSocket(const UdpSocket&) = delete;
  UdpSocket& operator=(const UdpSocket&) = delete;

  void open() {
    close();
#ifdef _WIN32
    ensure_wsa_started();
    fd_ = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (fd_ == INVALID_SOCKET) throw std::runtime_error("udp socket creation failed");
#else
    fd_ = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (fd_ < 0) throw std::runtime_error("udp socket creation failed");
#endif
  }

  void bind(std::uint16_t port) {
    if (!is_open()) throw std::runtime_error("socket not open");
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (::bind(fd_, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
      throw std::runtime_error("udp bind failed: " + last_socket_error_string());
  }

  void close() {
#ifdef _WIN32
    if (fd_ != INVALID_SOCKET) ::closesocket(fd_);
    fd_ = INVALID_SOCKET;
#else
    if (fd_ >= 0) ::close(fd_);
    fd_ = -1;
#endif
  }

  bool is_open() const {
#ifdef _WIN32
    return fd_ != INVALID_SOCKET;
#else
    return fd_ >= 0;
#endif
  }

  void send_to(const std::string& host, std::uint16_t port, const std::vector<std::uint8_t>& payload) {
    if (!is_open()) throw std::runtime_error("socket not open");
    if (payload.size() > kMaxDatagramBytes) throw std::runtime_error("datagram exceeds 1200 bytes");
    sockaddr_in dest{};
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    if (::inet_pton(AF_INET, host.c_str(), &dest.sin_addr) != 1)
      throw std::runtime_error("invalid ipv4 address: " + host);
#ifdef _WIN32
    int sent = ::sendto(fd_, reinterpret_cast<const char*>(payload.data()),
                        static_cast<int>(payload.size()), 0,
                        reinterpret_cast<sockaddr*>(&dest), sizeof(dest));
#else
    ssize_t sent = ::sendto(fd_, payload.data(), payload.size(), 0,
                            reinterpret_cast<sockaddr*>(&dest), sizeof(dest));
#endif
    if (sent < 0) throw std::runtime_error("sendto failed: " + last_socket_error_string());
  }

  // Waits up to timeout_ms for one datagram; would_block on timeout.
  RecvResult receive(int timeout_ms) {
    RecvResult result;
    if (!is_open()) {
      result.error = SocketError::closed;
      return result;
    }
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(fd_, &read_fds);
    timeval timeout{timeout_ms / 1000, (timeout_ms % 1000) * 1000};
#ifdef _WIN32
    int ready = ::select(0, &read_fds, nullptr, nullptr, &timeout);
#else
    int ready = ::select(fd_ + 1, &read_fds, nullptr, nullptr, &timeout);
#endif
    if (ready == 0) {
      result.error = SocketError::would_block;
      return result;
    }
    if (ready < 0) {
      result.error = SocketError::network_down;
      return result;
    }
    sockaddr_in peer{};
    socklen_t peer_len = sizeof(peer);
    std::vector<std::uint8_t> buffer(kMaxDatagramBytes + 1);
#ifdef _WIN32
    int received = ::recvfrom(fd_, reinterpret_cast<char*>(buffer.data()),
                              static_cast<int>(buffer.size()), 0,
                              reinterpret_cast<sockaddr*>(&peer), &peer_len);
#else
    ssize_t received = ::recvfrom(fd_, buffer.data(), buffer.size(), 0,
                                  reinterpret_cast<sockaddr*>(&peer), &peer_len);
#endif
    if (received < 0) {
      result.error = SocketError::network_down;
      return result;
    }
    char host[INET_ADDRSTRLEN];
    ::inet_ntop(AF_INET, &peer.sin_addr, host, sizeof(host));
    result.sender_host = host;
    result.sender_port = ntohs(peer.sin_port);
    if (static_cast<std::size_t>(received) > kMaxDatagramBytes) received = kMaxDatagramBytes;
    result.payload.assign(buffer.begin(), buffer.begin() + received);
    return result;
  }

private:
#ifdef _WIN32
  SOCKET fd_ = INVALID_SOCKET;
#else
  int fd_ = -1;
#endif
};

// Echo server body: replying each datagram to its sender's address until
// should_stop() is true. One process can host this while the test acts as
// the client.
template <typename ShouldStop>
void echo_server_loop(UdpSocket& socket, std::uint16_t port, ShouldStop should_stop) {
  socket.open();
  socket.bind(port);
  while (!should_stop()) {
    RecvResult recv = socket.receive(100);
    if (recv.error == SocketError::none && !recv.payload.empty())
      socket.send_to(recv.sender_host, recv.sender_port, recv.payload);
  }
}

} // namespace poko::net

#endif
