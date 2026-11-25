#include "poko/mute/bytecode.hpp"
#include <limits>
#include <bit>
#include <charconv>
#include <array>
#include <string_view>

namespace poko::mute {
namespace {
constexpr std::size_t max_words=65'536, header=12;
std::string_view mnemonic(Opcode op) {
  switch (op) {
    case Opcode::add:return "add"; case Opcode::sub:return "sub"; case Opcode::mul:return "mul";
    case Opcode::div:return "div"; case Opcode::mod:return "mod"; case Opcode::neg:return "neg";
    case Opcode::eq:return "eq"; case Opcode::ne:return "ne"; case Opcode::lt:return "lt";
    case Opcode::le:return "le"; case Opcode::gt:return "gt"; case Opcode::ge:return "ge";
    case Opcode::jump:return "jmp"; case Opcode::branch_true:return "br_true";
    case Opcode::branch_false:return "br_false"; case Opcode::move:return "mov";
    case Opcode::call:return "call";
    case Opcode::ret:return "ret"; case Opcode::call_host:return "call_host";
    case Opcode::halt:return "halt";
    case Opcode::ext_prefix:return "ext";
    case Opcode::load_imm:return "li";
  }
  return {};
}
bool branch(Opcode op) { return op==Opcode::jump || op==Opcode::branch_true || op==Opcode::branch_false; }
std::int32_t long_offset(const Instruction& i) {
  const auto u=static_cast<std::uint32_t>(i.op) | (static_cast<std::uint32_t>(i.a)<<8) |
    (static_cast<std::uint32_t>(i.b)<<16) | (static_cast<std::uint32_t>(i.c)<<24);
  return std::bit_cast<std::int32_t>(u);
}
Instruction long_payload(std::int32_t offset) {
  const auto u=std::bit_cast<std::uint32_t>(offset);
  return {static_cast<Opcode>(u&255U),static_cast<std::uint8_t>(u>>8),static_cast<std::uint8_t>(u>>16),static_cast<std::uint8_t>(u>>24)};
}
}
std::int32_t branch_offset(const Instruction& i) {
  const auto u=(static_cast<std::uint32_t>(i.b)<<8) | i.c;
  return u<0x8000U ? static_cast<std::int32_t>(u) : static_cast<std::int32_t>(u)-65536;
}
std::variant<std::monostate, BytecodeError> validate_bytecode(std::span<const Instruction> code) {
  if (code.empty()) return BytecodeError{BytecodeErrorCode::invalid_operands,0};
  if (code.size()>max_words) return BytecodeError{BytecodeErrorCode::size_limit,0};
  std::vector<bool> payload(code.size(),false);
  for (std::size_t pc=0;pc<code.size();++pc) {
    const auto& i=code[pc];
    if (i.op==Opcode::load_imm) {
      if (i.a==0 || i.b!=0 || i.c!=0) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
      if (pc+1>=code.size()) return BytecodeError{BytecodeErrorCode::truncated,pc};
      payload[++pc]=true; continue;
    }
    if (i.op!=Opcode::ext_prefix) continue;
    if (i.a<1 || i.a>3 || i.c!=0 || (i.a==1 && i.b!=0)) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    if (pc+1>=code.size()) return BytecodeError{BytecodeErrorCode::truncated,pc};
    payload[++pc]=true;
  }
  for (std::size_t pc=0;pc<code.size();++pc) {
    if (payload[pc]) continue;
    const auto& i=code[pc];
    if (mnemonic(i.op).empty()) return BytecodeError{BytecodeErrorCode::invalid_opcode,pc};
    if (branch(i.op) || i.op==Opcode::ext_prefix) {
      if (i.op==Opcode::jump && i.a!=0) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
      const bool extended=i.op==Opcode::ext_prefix;
      const auto delta=extended ? long_offset(code[pc+1]) : branch_offset(i);
      const auto target=static_cast<std::int64_t>(pc)+(extended?2:1)+delta;
      if (target<0 || target>=static_cast<std::int64_t>(code.size()) || payload[static_cast<std::size_t>(target)]) return BytecodeError{BytecodeErrorCode::invalid_target,pc};
    } else if (i.op==Opcode::ret) {
      if (i.b || i.c) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    } else if (i.op==Opcode::call) {
      // a=function index, b=argument window base, c=return register (0 discards).
      if (i.b>call_arg_base) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    } else if (i.op==Opcode::halt) {
      if (i.a || i.b || i.c) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    } else if (i.op==Opcode::load_imm) {
      // handled by payload pass; nothing else to check
    } else if (i.op==Opcode::call_host) {
      // a=id, b=arg base, c=return register; arity is table-defined at runtime
    } else if (i.op==Opcode::move || i.op==Opcode::neg) {
      if (i.a==0 || i.c!=0) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    } else if (i.a==0) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
  }
  // The last real instruction must not fall through past the end of the
  // stream: ret/halt terminate, jump and unconditional long jumps (ext
  // mode 1) transfer unconditionally. Conditional ext modes may fall
  // through, so they cannot be last.
  for (std::size_t pc=code.size();pc-- >0;) {
    if (payload[pc]) continue;
    const auto& last=code[pc];
    const bool terminator=last.op==Opcode::ret || last.op==Opcode::halt ||
      last.op==Opcode::jump || (last.op==Opcode::ext_prefix && last.a==1);
    if (!terminator) return BytecodeError{BytecodeErrorCode::invalid_operands,pc};
    break;
  }
  return std::monostate{};
}
EncodeResult encode_bytecode(std::span<const Instruction> code) {
  auto valid=validate_bytecode(code); if (auto* e=std::get_if<BytecodeError>(&valid)) return *e;
  std::vector<std::uint8_t> out{'M','U','T','B',1,0,0,0};
  const auto n=static_cast<std::uint32_t>(code.size());
  for (unsigned shift=0;shift<32;shift+=8) out.push_back(static_cast<std::uint8_t>(n>>shift));
  out.reserve(header+code.size()*4);
  for (auto i:code) {out.push_back(static_cast<std::uint8_t>(i.op));out.push_back(i.a);out.push_back(i.b);out.push_back(i.c);}
  return out;
}
DecodeResult decode_bytecode(std::span<const std::uint8_t> bytes) {
  if (bytes.size()<header) return BytecodeError{BytecodeErrorCode::truncated,bytes.size()};
  if (bytes[0]!='M'||bytes[1]!='U'||bytes[2]!='T'||bytes[3]!='B') return BytecodeError{BytecodeErrorCode::bad_header,0};
  if (bytes[4]!=1) return BytecodeError{BytecodeErrorCode::unsupported_version,4};
  if (bytes[5]||bytes[6]||bytes[7]) return BytecodeError{BytecodeErrorCode::bad_header,5};
  std::uint32_t count=0;
  for (unsigned j=0;j<4;++j) count|=static_cast<std::uint32_t>(bytes[8+j])<<(8*j);
  if (count>max_words) return BytecodeError{BytecodeErrorCode::size_limit,8};
  if (bytes.size()!=header+static_cast<std::size_t>(count)*4) return BytecodeError{BytecodeErrorCode::truncated,bytes.size()};
  Bytecode code;code.reserve(count);
  for (std::size_t off=header;off<bytes.size();off+=4)
    code.push_back({static_cast<Opcode>(bytes[off]),bytes[off+1],bytes[off+2],bytes[off+3]});
  auto valid=validate_bytecode(code); if (auto* e=std::get_if<BytecodeError>(&valid)) return *e;
  return code;
}
DecodeResult assemble_bytecode(std::string_view listing) {
  // Accept exactly the canonical listing emitted by disassemble_bytecode.
  if (listing.size()>4*1024*1024) return BytecodeError{BytecodeErrorCode::size_limit,0};
  const auto original=listing;
  constexpr std::array ops{Opcode::add,Opcode::sub,Opcode::mul,Opcode::div,Opcode::mod,Opcode::neg,
    Opcode::eq,Opcode::ne,Opcode::lt,Opcode::le,Opcode::gt,Opcode::ge,Opcode::load_imm,Opcode::jump,
    Opcode::branch_true,Opcode::branch_false,Opcode::move,Opcode::call,Opcode::ret,Opcode::call_host,Opcode::halt};
  Bytecode code;
  auto bad=[&] { return DecodeResult{BytecodeError{BytecodeErrorCode::invalid_assembly,code.size()}}; };
  while (!listing.empty()) {
    const auto newline=listing.find('\n');
    auto line=listing.substr(0,newline);
    listing=newline==std::string_view::npos ? std::string_view{} : listing.substr(newline+1);
    if (code.size()>=max_words) return BytecodeError{BytecodeErrorCode::size_limit,code.size()};
    auto number=[&](int& result) {
      if (line.empty()) return false;
      const auto [end,ec]=std::from_chars(line.data(),line.data()+line.size(),result);
      if (ec!=std::errc{} || end==line.data()) return false;
      line.remove_prefix(static_cast<std::size_t>(end-line.data()));return true;
    };
    auto take=[&](std::string_view token) {
      if (!line.starts_with(token)) return false;
      line.remove_prefix(token.size());return true;
    };
    auto reg=[&](std::uint8_t& output) {
      int v=0;if (!take("r") || !number(v) || v<0 || v>255) return false;
      output=static_cast<std::uint8_t>(v);return true;
    };
    int pc=0;if (!number(pc) || pc!=static_cast<int>(code.size()) || !take(": ")) return bad();
    const auto name_end=line.find(' ');const auto text=line.substr(0,name_end);
    auto found=ops.end();for (auto it=ops.begin();it!=ops.end();++it) if (mnemonic(*it)==text) {found=it;break;}
    const auto ext=text=="jmp_long"?1U:text=="br_true_long"?2U:text=="br_false_long"?3U:0U;
    if (found==ops.end() && ext==0) return bad();
    line.remove_prefix(text.size()); Instruction ins{ext?Opcode::ext_prefix:*found,0,0,0};
    if (ext) {
      ins.a=static_cast<std::uint8_t>(ext);
      if (ext!=1 && (!take(" ") || !reg(ins.b) || !take(","))) return bad();
      int displacement=0;if (!take(" ") || !number(displacement) || !line.empty() || code.size()+2>max_words) return bad();
      code.push_back(ins);code.push_back(long_payload(displacement));continue;
    }
    if (branch(ins.op)) {
      if (ins.op!=Opcode::jump && (!take(" ") || !reg(ins.a) || !take(","))) return bad();
      int displacement=0;if (!take(" ") || !number(displacement) || displacement < -32768 || displacement > 32767) return bad();
      const auto packed=static_cast<std::uint16_t>(displacement);
      ins.b=static_cast<std::uint8_t>(packed>>8);ins.c=static_cast<std::uint8_t>(packed);
    } else if (ins.op==Opcode::ret) {
      if (!take(" ") || !reg(ins.a)) return bad();
    } else if (ins.op==Opcode::call) {
      int fn=0;
      if (!take(" ") || !number(fn) || fn<0 || fn>255 || !take(", ") || !reg(ins.b) || !take(", ") || !reg(ins.c)) return bad();
      ins.a=static_cast<std::uint8_t>(fn);
    } else if (ins.op==Opcode::call_host) {
      int id=0;
      if (!take(" ") || !number(id) || id<0 || id>255 || !take(", ") || !reg(ins.b) || !take(", ") || !reg(ins.c)) return bad();
      ins.a=static_cast<std::uint8_t>(id);
    } else if (ins.op==Opcode::load_imm) {
      int imm=0;if (!take(" ") || !reg(ins.a) || !take(", ") || !number(imm)) return bad();
      ins.b=0;ins.c=0;code.push_back(ins);code.push_back(long_payload(imm));continue;
    } else if (ins.op!=Opcode::halt) {
      if (!take(" ") || !reg(ins.a) || !take(", ") || !reg(ins.b)) return bad();
      if (ins.op!=Opcode::move && ins.op!=Opcode::neg && (!take(", ") || !reg(ins.c))) return bad();
    }
    if (!line.empty()) return bad();
    code.push_back(ins);
  }
  auto valid=validate_bytecode(code);if (auto* e=std::get_if<BytecodeError>(&valid)) return *e;
  const auto canonical=disassemble_bytecode(code);
  if (std::get<std::string>(canonical)!=original) return bad();
  return code;
}
std::variant<std::string,BytecodeError> disassemble_bytecode(std::span<const Instruction> code) {
  auto valid=validate_bytecode(code); if (auto* e=std::get_if<BytecodeError>(&valid)) return *e;
  std::string out;
  for (std::size_t pc=0;pc<code.size();++pc) {
    const auto i=code[pc];
    if (i.op==Opcode::ext_prefix) {
      out+=std::to_string(pc)+": "+(i.a==1?"jmp_long":i.a==2?"br_true_long":"br_false_long");
      if (i.a!=1) out+=" r"+std::to_string(i.b)+",";
      out+=" "+std::to_string(long_offset(code[++pc]))+"\n";continue;
    }
    out+=std::to_string(pc)+": "+std::string(mnemonic(i.op));
    if (branch(i.op)) { if (i.op!=Opcode::jump) out+=" r"+std::to_string(i.a)+","; out+=" "+std::to_string(branch_offset(i)); }
    else if (i.op==Opcode::load_imm) { out+=" r"+std::to_string(i.a)+", "+std::to_string(long_offset(code[++pc])); continue; }
    else if (i.op==Opcode::ret) out+=" r"+std::to_string(i.a);
    else if (i.op==Opcode::call) out+=" "+std::to_string(i.a)+", r"+std::to_string(i.b)+", r"+std::to_string(i.c);
    else if (i.op==Opcode::call_host) out+=" "+std::to_string(i.a)+", r"+std::to_string(i.b)+", r"+std::to_string(i.c);
    else if (i.op!=Opcode::halt) {
      out+=" r"+std::to_string(i.a)+", r"+std::to_string(i.b);
      if (i.op!=Opcode::move && i.op!=Opcode::neg) out+=", r"+std::to_string(i.c);
    }
    out+='\n';
  }
  return out;
}
} // namespace poko::mute
