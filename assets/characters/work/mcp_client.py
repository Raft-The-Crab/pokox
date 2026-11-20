"""Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876."""
import json
import socket
import sys

HOST, PORT = "127.0.0.1", 9876


def send(command_type, params=None, timeout=120):
    payload = json.dumps({"type": command_type, "params": params or {}}).encode("utf-8")
    sock = socket.create_connection((HOST, PORT), timeout=timeout)
    sock.settimeout(timeout)
    sock.sendall(payload)
    chunks = []
    while True:
        try:
            data = sock.recv(65536)
        except socket.timeout:
            break
        if not data:
            break
        chunks.append(data)
        try:
            json.loads(b"".join(chunks).decode("utf-8"))
            break
        except (json.JSONDecodeError, UnicodeDecodeError):
            continue
    sock.close()
    return json.loads(b"".join(chunks).decode("utf-8"))


if __name__ == "__main__":
    cmd = sys.argv[1]
    params = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    print(json.dumps(send(cmd, params), indent=2, ensure_ascii=False))
