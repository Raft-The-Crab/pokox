#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace poko::mute {
// Experimental MUT-08/10 subset; not the production .pkB format or a complete verifier.
// Each instruction is op:a:b:c (one byte each). Branch displacement is signed
// 16-bit b:c relative to the next word. Extended branches use ext_prefix and
// one payload word with a signed 32-bit displacement relative to the word after it.
enum class Opcode : std::uint8_t {
  add=0x00, sub=0x01, mul=0x02, div=0x03, mod=0x04, neg=0x05,
  eq=0x20, ne=0x21, lt=0x22, le=0x23, gt=0x24, ge=0x25,
  jump=0x28, branch_true=0x29, branch_false=0x2a,
  move=0x31, ret=0x42, halt=0x4f, ext_prefix=0x60, load_imm=0x70
};
struct Instruction { Opcode op; std::uint8_t a, b, c; bool operator==(const Instruction&) const = default; };
enum class BytecodeErrorCode { bad_header, unsupported_version, truncated, size_limit, invalid_opcode, invalid_operands, invalid_target, invalid_assembly };
// Framing errors use byte offsets; invalid instruction errors use instruction indices.
struct BytecodeError { BytecodeErrorCode code; std::size_t offset; };
using Bytecode = std::vector<Instruction>;
using DecodeResult = std::variant<Bytecode, BytecodeError>;
using EncodeResult = std::variant<std::vector<std::uint8_t>, BytecodeError>;
// Wire format: MUTB, version 1, three zero bytes, little-endian u32 count,
// followed by count op/a/b/c words. Max 65536 instructions; no trailing bytes.
[[nodiscard]] std::variant<std::monostate, BytecodeError> validate_bytecode(std::span<const Instruction> instructions);
[[nodiscard]] EncodeResult encode_bytecode(std::span<const Instruction> instructions);
[[nodiscard]] DecodeResult decode_bytecode(std::span<const std::uint8_t> bytes);
[[nodiscard]] DecodeResult assemble_bytecode(std::string_view listing);
[[nodiscard]] std::variant<std::string, BytecodeError> disassemble_bytecode(std::span<const Instruction> instructions);
[[nodiscard]] std::int32_t branch_offset(const Instruction& instruction);
} // namespace poko::mute
