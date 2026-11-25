#include "poko/mute/build_tool.hpp"

#include "poko/mute/state.hpp"

#include <algorithm>
#include <array>
#include <cctype>

namespace poko::mute {
namespace {
std::string_view trim(std::string_view text) noexcept {
  while (!text.empty() && std::isspace(static_cast<unsigned char>(text.front()))) text.remove_prefix(1);
  while (!text.empty() && std::isspace(static_cast<unsigned char>(text.back()))) text.remove_suffix(1);
  return text;
}
bool quoted(std::string_view text, std::string& out) noexcept {
  text = trim(text);
  if (text.size() < 2 || text.front() != '"' || text.back() != '"') return false;
  out.assign(text.substr(1, text.size() - 2));
  return !out.empty();
}
bool string_array(std::string_view text, std::vector<std::string>& out) noexcept {
  text = trim(text);
  if (text.size() < 2 || text.front() != '[' || text.back() != ']') return false;
  text = trim(text.substr(1, text.size() - 2));
  if (text.empty()) return true;
  std::size_t at = 0;
  while (at < text.size()) {
    const auto comma = text.find(',', at);
    const auto part = comma == std::string_view::npos ? text.substr(at) : text.substr(at, comma - at);
    std::string value;
    if (!quoted(part, value)) return false;
    out.push_back(value);
    if (comma == std::string_view::npos) break;
    at = comma + 1;
  }
  return true;
}
std::string_view after_token(std::string_view source, std::string_view token) noexcept {
  const auto at = source.find(token);
  return at == std::string_view::npos ? std::string_view{} : source.substr(at + token.size());
}
bool next_quoted(std::string_view text, std::string& out) noexcept {
  const auto first = text.find('"');
  if (first == std::string_view::npos) return false;
  const auto last = text.find('"', first + 1);
  if (last == std::string_view::npos) return false;
  out.assign(text.substr(first + 1, last - first - 1));
  return !out.empty();
}
}  // namespace

std::optional<Manifest> parse_manifest(std::string_view text, std::string* diagnostic) {
  Manifest manifest;
  std::size_t line_no = 0;
  std::size_t at = 0;
  while (at < text.size()) {
    const auto end = text.find('\n', at);
    const auto line = trim(end == std::string_view::npos ? text.substr(at) : text.substr(at, end - at));
    ++line_no;
    at = end == std::string_view::npos ? text.size() : end + 1;
    if (line.empty() || line.front() == '#') continue;
    const auto eq = line.find('=');
    if (eq == std::string_view::npos) {
      if (diagnostic) *diagnostic = "line " + std::to_string(line_no) + ": expected key = value";
      return std::nullopt;
    }
    const auto key = trim(line.substr(0, eq));
    const auto value = line.substr(eq + 1);
    if (key == "name") {
      if (!quoted(value, manifest.name)) {
        if (diagnostic) *diagnostic = "line " + std::to_string(line_no) + ": invalid name";
        return std::nullopt;
      }
    } else if (key == "version") {
      if (!quoted(value, manifest.version)) {
        if (diagnostic) *diagnostic = "line " + std::to_string(line_no) + ": invalid version";
        return std::nullopt;
      }
    } else if (key == "sources") {
      if (!string_array(value, manifest.sources)) {
        if (diagnostic) *diagnostic = "line " + std::to_string(line_no) + ": invalid sources";
        return std::nullopt;
      }
    } else {
      if (diagnostic) *diagnostic = "line " + std::to_string(line_no) + ": unknown key";
      return std::nullopt;
    }
  }
  if (manifest.name.empty() || manifest.version.empty() || manifest.sources.empty()) {
    if (diagnostic) *diagnostic = "missing name, version or sources";
    return std::nullopt;
  }
  return manifest;
}

bool declared_identity(std::string_view source, std::string& name,
                       std::string& version) noexcept {
  return next_quoted(after_token(source, "package "), name) &&
         next_quoted(after_token(source, "version "), version);
}

BuildResult build_project(const Manifest& manifest, std::span<const ProjectSource> sources,
                          std::optional<std::string_view> expected_lock) {
  BuildResult result;
  std::vector<PackageInput> inputs;
  inputs.reserve(manifest.sources.size());
  for (const auto& path : manifest.sources) {
    const auto found = std::find_if(sources.begin(), sources.end(),
                                    [&](const auto& s) { return s.path == path; });
    if (found == sources.end()) {
      result.error = BuildToolError::io;
      result.diagnostic = "missing source: " + path;
      return result;
    }
    std::string name, version;
    if (!declared_identity(found->source, name, version)) {
      result.error = BuildToolError::invalid_source;
      result.diagnostic = "missing package identity: " + path;
      return result;
    }
    inputs.push_back({name, version, found->source});
  }
  const auto resolved = resolve_packages(inputs);
  if (!resolved.ok()) {
    result.error = BuildToolError::resolve_failed;
    const auto& first = resolved.diagnostics.front();
    result.diagnostic = std::string(name(first.code)) + " " + first.detail;
    return result;
  }
  result.packages = resolved.packages;
  result.lock_text = dump_lockfile(resolved);
  if (expected_lock && *expected_lock != result.lock_text) {
    result.error = BuildToolError::lock_mismatch;
    result.diagnostic = "mute.lock does not match resolved sources";
    return result;
  }
  return result;
}

std::string_view name(BuildToolError error) noexcept {
  switch (error) {
    case BuildToolError::ok: return "ok";
    case BuildToolError::io: return "io";
    case BuildToolError::invalid_manifest: return "invalid_manifest";
    case BuildToolError::invalid_source: return "invalid_source";
    case BuildToolError::invalid_lock: return "invalid_lock";
    case BuildToolError::lock_mismatch: return "lock_mismatch";
    case BuildToolError::resolve_failed: return "resolve_failed";
  }
  return {};
}

}  // namespace poko::mute
