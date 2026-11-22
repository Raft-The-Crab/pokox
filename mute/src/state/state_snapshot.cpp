#include "poko/mute/state_snapshot.hpp"
#include "poko/mute/program.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <limits>

namespace poko::mute {
namespace {
constexpr std::array<std::uint8_t, 4> magic{'M','U','T','S'};
constexpr std::size_t header_size = 14, checksum_size = 8;
void append_le(std::vector<std::uint8_t>& out, std::uint64_t value, unsigned count) {
  for (unsigned i=0;i<count;++i) out.push_back(static_cast<std::uint8_t>(value >> (i*8)));
}
std::uint64_t read_le(std::span<const std::uint8_t> bytes, std::size_t offset, unsigned count) {
  std::uint64_t result=0;
  for (unsigned i=0;i<count;++i) result |= static_cast<std::uint64_t>(bytes[offset+i]) << (i*8);
  return result;
}
using SchemaResult = std::variant<std::vector<std::string>, SnapshotError>;
SchemaResult schema_for(std::string_view source) {
  if (source.size()>max_snapshot_source_bytes) return SnapshotError{SnapshotErrorCode::source_too_large,0};
  auto schema=inspect_program_state_schema(source);
  if (std::holds_alternative<ProgramDiagnostic>(schema)) return SnapshotError{SnapshotErrorCode::invalid_source,0};
  // Compile as well as parse. This is not a full static type or security verifier.
  if (std::holds_alternative<ProgramDiagnostic>(compile_program_bytecode(source))) return SnapshotError{SnapshotErrorCode::invalid_source,0};
  return std::get<std::vector<std::string>>(std::move(schema));
}
}
SaveStateResult save_state_snapshot(std::string_view source,const ProgramState& state) {
  auto parsed=schema_for(source);
  if (const auto* error=std::get_if<SnapshotError>(&parsed)) return *error;
  const auto& names=std::get<std::vector<std::string>>(parsed);
  if (!state.initialized || names.size()!=state.fields.size()) return SnapshotError{SnapshotErrorCode::invalid_state,0};
  for (std::size_t i=0;i<names.size();++i)
    if (names[i]!=state.fields[i].name) return SnapshotError{SnapshotErrorCode::invalid_state,i};
  std::vector<std::uint8_t> out;
  out.reserve(header_size+source.size()+names.size()*4+checksum_size);
  out.insert(out.end(),magic.begin(),magic.end());
  append_le(out,1,2); append_le(out,0,2); append_le(out,source.size(),4); append_le(out,names.size(),2);
  for (const unsigned char c: source) out.push_back(c);
  for (const auto& field:state.fields) append_le(out,static_cast<std::uint32_t>(field.value),4);
  append_le(out,xxhash64(out),8);
  return out;
}
LoadStateResult load_state_snapshot(std::string_view expected_source,std::span<const std::uint8_t> bytes) {
  if (expected_source.size()>max_snapshot_source_bytes) return SnapshotError{SnapshotErrorCode::source_too_large,0};
  if (bytes.size()<header_size+checksum_size || bytes.size()>max_snapshot_bytes) return SnapshotError{SnapshotErrorCode::invalid_format,0};
  if (!std::equal(magic.begin(),magic.end(),bytes.begin())) return SnapshotError{SnapshotErrorCode::invalid_format,0};
  if (read_le(bytes,4,2)!=1 || read_le(bytes,6,2)!=0) return SnapshotError{SnapshotErrorCode::invalid_format,4};
  const auto source_size=static_cast<std::size_t>(read_le(bytes,8,4));
  const auto count=static_cast<std::size_t>(read_le(bytes,12,2));
  if (source_size>max_snapshot_source_bytes || count>max_state_fields) return SnapshotError{SnapshotErrorCode::invalid_format,8};
  const auto expected_size=header_size+source_size+count*4+checksum_size;
  if (bytes.size()!=expected_size) return SnapshotError{SnapshotErrorCode::invalid_format,bytes.size()};
  if (read_le(bytes,bytes.size()-checksum_size,8)!=xxhash64(bytes.first(bytes.size()-checksum_size))) return SnapshotError{SnapshotErrorCode::checksum_mismatch,bytes.size()-checksum_size};
  if (source_size!=expected_source.size() || !std::equal(expected_source.begin(),expected_source.end(),bytes.begin()+header_size,
      [](char a,std::uint8_t b){return static_cast<unsigned char>(a)==b;})) return SnapshotError{SnapshotErrorCode::source_mismatch,header_size};
  auto parsed=schema_for(expected_source);
  if (const auto* error=std::get_if<SnapshotError>(&parsed)) return *error;
  auto& names=std::get<std::vector<std::string>>(parsed);
  if (count!=names.size()) return SnapshotError{SnapshotErrorCode::invalid_format,12};
  ProgramState result; result.initialized=true; result.fields.reserve(count);
  for (std::size_t i=0;i<count;++i) {
    auto bits=static_cast<std::uint32_t>(read_le(bytes,header_size+source_size+i*4,4));
    result.fields.push_back(StateField{std::move(names[i]),std::bit_cast<std::int32_t>(bits)});
  }
  return result;
}
} // namespace poko::mute
