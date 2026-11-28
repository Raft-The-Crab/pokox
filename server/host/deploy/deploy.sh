#!/bin/sh
# DEMO-02: install or upgrade the PokoX host (server/host, DEMO-01) on a Linux VPS.
#
# The binary is built anywhere (Linux x86-64/arm64, Release); this script only
# ships it: service account, /opt/pokox, /etc/pokox/pokox-host.env (0600),
# systemd unit, firewall rule, restart and a health check.
#
#   cmake -S . -B build-linux -DCMAKE_BUILD_TYPE=Release
#   cmake --build build-linux -j --target pokox_host
#   server/host/deploy/deploy.sh --target poko@vps.example.com \
#       --secret-file ~/.poko/ticket-secret --port 7777
#
# Use --dry-run to print every remote command without running it.
set -eu

target=
binary=build-linux/pokox_host
secret_file=
port=7777
tick_hz=30
slots=3
service_user=pokox
remote_dir=/opt/pokox
sudo_cmd=${POKOX_SUDO:-sudo}
unit_name=pokox-host
manage_firewall=1
dry_run=0

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
unit_tpl="$script_dir/pokox-host.service.in"

usage() {
  cat <<'EOF'
usage: deploy.sh --target user@host [options]

  --target USER@HOST   ssh destination of the VPS (required)
  --binary PATH        Linux binary to ship (default build-linux/pokox_host)
  --secret-file PATH   file holding the HMAC ticket secret (required)
  --port N             UDP port to serve (default 7777)
  --tick-hz N          authority ticks per second (default 30)
  --slots N            platform slots, 1-3 (default 3)
  --service-user NAME  service account, created if missing (default pokox)
  --remote-dir PATH    install directory (default /opt/pokox)
  --no-firewall        skip the ufw rule for the UDP port
  --dry-run            print the commands, run nothing
  -h, --help           this text

The secret is generated once and reused;  openssl rand -hex 32 > secret
Override the privilege prefix with $POKOX_SUDO (default: sudo).
EOF
}

die() { printf 'deploy: %s\n' "$*" >&2; exit 2; }

need_value() { [ $# -ge 2 ] && [ -n "$2" ] || die "$1 needs a value"; }
numeric() { case "$2" in ''|*[!0-9]*) die "$1 must be numeric" ;; esac; }

while [ $# -gt 0 ]; do
  case "$1" in
    --target) need_value "$@"; target=$2; shift 2 ;;
    --binary) need_value "$@"; binary=$2; shift 2 ;;
    --secret-file) need_value "$@"; secret_file=$2; shift 2 ;;
    --port) need_value "$@"; numeric "$@"; port=$2; shift 2 ;;
    --tick-hz) need_value "$@"; numeric "$@"; tick_hz=$2; shift 2 ;;
    --slots) need_value "$@"; numeric "$@"; slots=$2; shift 2 ;;
    --service-user) need_value "$@"; service_user=$2; shift 2 ;;
    --remote-dir) need_value "$@"; remote_dir=$2; shift 2 ;;
    --no-firewall) manage_firewall=0; shift ;;
    --dry-run) dry_run=1; shift ;;
    -h|--help) usage; exit 0 ;;
    *) die "unknown argument: $1 (see --help)" ;;
  esac
done

[ -n "$target" ] || die "--target USER@HOST is required"
case "$target" in *@*) ;; *) die "--target must look like user@host" ;; esac
[ "$port" -ge 1 ] && [ "$port" -le 65535 ] || die "--port must be 1-65535"
[ "$tick_hz" -ge 1 ] && [ "$tick_hz" -le 240 ] || die "--tick-hz must be 1-240"
[ "$slots" -ge 1 ] && [ "$slots" -le 3 ] || die "--slots must be 1-3 (platform cap, slot_registry.hpp)"
case "$remote_dir" in /*) ;; *) die "--remote-dir must be absolute" ;; esac
case "$service_user" in ''|*[!a-z0-9_-]*) die "--service-user must be a plain account name" ;; esac
[ -f "$unit_tpl" ] || die "missing unit template: $unit_tpl"

if [ "$dry_run" -eq 0 ]; then
  [ -f "$binary" ] || die "binary not found: $binary (build it, or pass --binary)"
  [ -n "$secret_file" ] || die "--secret-file is required (openssl rand -hex 32 > secret)"
  [ -f "$secret_file" ] || die "secret file not found: $secret_file"
else
  [ -n "$secret_file" ] && [ -f "$secret_file" ] || secret_file=
fi

if [ -n "$secret_file" ]; then
  secret=$(tr -d '\r\n' < "$secret_file")
  [ -n "$secret" ] || die "secret file is empty: $secret_file"
  case "$secret" in *[!A-Za-z0-9._-]*) die "secret must be A-Za-z0-9._- only (no spaces or quotes)" ;; esac
  [ "${#secret}" -ge 16 ] || die "secret must be at least 16 characters"
else
  secret=DRY-RUN-NOT-A-SECRET
fi

if [ "$dry_run" -eq 0 ] && command -v od >/dev/null 2>&1; then
  magic=$(od -An -c -N4 "$binary" 2>/dev/null | tr -d ' \n')
  case "$magic" in
    177ELF|\\177ELF) ;;
    *) die "$binary is not an ELF binary; build it for Linux (this ships a Linux host)" ;;
  esac
fi

tmp=$(mktemp -d) || die "cannot create a temp directory"
trap 'rm -rf "$tmp"' EXIT INT TERM

sed -e "s|@USER@|$service_user|g" \
    -e "s|@REMOTE_DIR@|$remote_dir|g" \
    -e "s|@PORT@|$port|g" \
    -e "s|@TICK_HZ@|$tick_hz|g" \
    -e "s|@SLOTS@|$slots|g" \
    "$unit_tpl" > "$tmp/$unit_name.service"
printf 'POKO_TICKET_SECRET=%s\n' "$secret" > "$tmp/pokox-host.env"
chmod 600 "$tmp/pokox-host.env"

say() { printf '== %s\n' "$*"; }
run_remote() {
  if [ "$dry_run" -eq 1 ]; then printf '  ssh %s %s\n' "$target" "$1"
  else ssh "$target" "$1"; fi
}
run_scp() {
  if [ "$dry_run" -eq 1 ]; then printf '  scp %s %s:%s\n' "$1" "$target" "$2"
  else scp -q "$1" "$target:$2"; fi
}

say "preflight"
printf '  target %s  port/udp %s  tick %s Hz  slots %s  user %s  dir %s\n' \
  "$target" "$port" "$tick_hz" "$slots" "$service_user" "$remote_dir"
printf '  binary %s\n' "$binary"

say "service account and directories"
run_remote "id -u $service_user >/dev/null 2>&1 || $sudo_cmd useradd --system --no-create-home --shell /usr/sbin/nologin $service_user"
run_remote "$sudo_cmd install -d -m 0755 $remote_dir /etc/pokox"

say "binary"
run_scp "$binary" "/tmp/pokox_host.$$"
run_remote "$sudo_cmd install -m 0755 /tmp/pokox_host.$$ $remote_dir/pokox_host && rm -f /tmp/pokox_host.$$"

say "unit and secret"
if [ "$dry_run" -eq 1 ]; then
  printf '  -- %s --\n' "/etc/systemd/system/$unit_name.service"
  sed 's/^/  /' "$tmp/$unit_name.service"
fi
run_scp "$tmp/$unit_name.service" "/tmp/$unit_name.service.$$"
run_remote "$sudo_cmd install -m 0644 /tmp/$unit_name.service.$$ /etc/systemd/system/$unit_name.service && rm -f /tmp/$unit_name.service.$$"
if [ "$dry_run" -eq 1 ]; then
  printf '  ssh %s %s < %s\n' "$target" \
    "'$sudo_cmd install -m 0600 /dev/stdin /etc/pokox/pokox-host.env'" "$secret_file"
else
  ssh "$target" "$sudo_cmd install -m 0600 /dev/stdin /etc/pokox/pokox-host.env" < "$tmp/pokox-host.env"
fi

say "enable and restart"
run_remote "$sudo_cmd systemctl daemon-reload"
run_remote "$sudo_cmd systemctl enable $unit_name"
run_remote "$sudo_cmd systemctl restart $unit_name"

if [ "$manage_firewall" -eq 1 ]; then
  say "firewall (ufw, if present)"
  run_remote "command -v ufw >/dev/null 2>&1 && $sudo_cmd ufw allow $port/udp || echo 'no ufw; open udp/$port in the provider firewall'"
fi

say "health"
run_remote "$sudo_cmd systemctl is-active $unit_name"
run_remote "$sudo_cmd ss -lunp | grep -E ':$port\\b' || echo 'not listening yet'"
run_remote "$sudo_cmd journalctl -u $unit_name -n 15 --no-pager"

if [ "$dry_run" -eq 1 ]; then
  say "dry run: nothing was executed"
else
  say "deployed $binary to $target:$remote_dir/pokox_host (udp/$port)"
fi
