#include "poko/mute/bytecode.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/program.hpp"
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <variant>
#include <vector>
using namespace poko::mute;
int main() {
  int failures=0;
  auto check=[&](bool ok,const char* label) { if (!ok) { std::cerr<<label<<'\n'; ++failures; } };
  using O=Opcode; using I=Instruction;
  Bytecode code{{O::add,3,1,2},{O::ret,3,0,0}};
  auto encoded=encode_bytecode(code);
  check(std::holds_alternative<std::vector<std::uint8_t>>(encoded),"encode valid");
  if (auto* bytes=std::get_if<std::vector<std::uint8_t>>(&encoded)) {
    const std::vector<std::uint8_t> golden{'M','U','T','B',1,0,0,0,2,0,0,0,0,3,1,2,0x42,3,0,0};
    check(*bytes==golden,"wire golden");
    auto decoded=decode_bytecode(*bytes);
    check(std::holds_alternative<Bytecode>(decoded) && std::get<Bytecode>(decoded)==code,"round trip");
    for (std::size_t n=0;n<bytes->size();++n)
      check(std::holds_alternative<BytecodeError>(decode_bytecode(std::span(*bytes).first(n))),"truncation rejected");
    auto bad=*bytes;bad.push_back(0);check(std::holds_alternative<BytecodeError>(decode_bytecode(bad)),"trailing bytes rejected");
    bad=*bytes;bad[4]=2;check(std::get<BytecodeError>(decode_bytecode(bad)).code==BytecodeErrorCode::unsupported_version,"version rejected");
    bad=*bytes;bad[0]=0;check(std::get<BytecodeError>(decode_bytecode(bad)).code==BytecodeErrorCode::bad_header,"header rejected");
    bad=*bytes;bad[12]=0xff;check(std::get<BytecodeError>(decode_bytecode(bad)).code==BytecodeErrorCode::invalid_opcode,"opcode rejected");
    bad=*bytes;bad[8]=1;bad[9]=0;bad[10]=1;check(std::get<BytecodeError>(decode_bytecode(bad)).code==BytecodeErrorCode::size_limit,"size cap before allocation");
  }
  auto listing=disassemble_bytecode(code);
  check(std::holds_alternative<std::string>(listing) && std::get<std::string>(listing)=="0: add r3, r1, r2\n1: ret r3\n","disassembly golden");
  if (auto* text=std::get_if<std::string>(&listing)) {
    auto assembled=assemble_bytecode(*text);
    check(std::holds_alternative<Bytecode>(assembled) && std::get<Bytecode>(assembled)==code,"disassembly/assembly roundtrip");
  }
  for (const auto bad:{"0: add r0, r1, r2\n", "0: jmp 32768\n", "0: ret r256\n", "1: halt\n", "0: halt extra\n", "0: no_such_op\n", "00: halt\n", "0: halt"})
    check(std::holds_alternative<BytecodeError>(assemble_bytecode(bad)),"bad assembly rejected");
  const Bytecode asm_branch{{O::branch_false,1,0,1},{O::jump,0,0xff,0xfe},{O::ret,1,0,0}};
  const auto asm_text=std::get<std::string>(disassemble_bytecode(asm_branch));
  check(std::get<Bytecode>(assemble_bytecode(asm_text))==asm_branch,"branch assembly roundtrip");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{static_cast<O>(0xff),0,0,0}})),"unknown opcode");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::add,0,1,2}})),"r0 readonly");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::move,1,2,1}})),"reserved operand");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::jump,0,0xff,0xff}}))==false,"self branch valid");
  check(std::get<BytecodeError>(validate_bytecode(Bytecode{{O::jump,0,0,0}})).code==BytecodeErrorCode::invalid_target,"branch at end rejected");
  check(branch_offset(I{O::jump,0,0x80,0})==-32768 && branch_offset(I{O::jump,0,0x7f,0xff})==32767,"signed branch boundaries");
  Bytecode forward(32769,I{O::halt,0,0,0});forward[0]=I{O::jump,0,0x7f,0xff};
  check(std::holds_alternative<std::monostate>(validate_bytecode(forward)),"maximum forward branch");
  Bytecode backward(32768,I{O::halt,0,0,0});backward.back()=I{O::jump,0,0x80,0};
  check(std::holds_alternative<std::monostate>(validate_bytecode(backward)),"maximum backward branch");
  // Long branches are two words; their payload is never an instruction target.
  auto payload=[](std::int32_t delta) {const auto x=std::bit_cast<std::uint32_t>(delta);return I{static_cast<O>(x&255U),static_cast<std::uint8_t>(x>>8),static_cast<std::uint8_t>(x>>16),static_cast<std::uint8_t>(x>>24)};};
  Bytecode long_forward(40003,I{O::halt,0,0,0});
  long_forward[0]={O::ext_prefix,1,0,0};long_forward[1]=payload(40000);long_forward[40002]={O::ret,1,0,0};
  std::array<std::int32_t,256> long_regs{};long_regs[1]=42;
  check(std::get<std::int32_t>(run_register_vm(long_forward,long_regs))==42,"long forward execution");
  const auto long_encoded=encode_bytecode(long_forward);
  check(std::get<Bytecode>(decode_bytecode(std::get<std::vector<std::uint8_t>>(long_encoded)))==long_forward,"long binary roundtrip");
  const auto long_text=std::get<std::string>(disassemble_bytecode(long_forward));
  check(long_text.starts_with("0: jmp_long 40000\n2:") && std::get<Bytecode>(assemble_bytecode(long_text))==long_forward,"long assembly roundtrip");
  Bytecode long_backward(40003,I{O::halt,0,0,0});
  long_backward[0]={O::ext_prefix,1,0,0};long_backward[1]=payload(39999);long_backward[2]={O::ret,1,0,0};
  long_backward[40001]={O::ext_prefix,1,0,0};long_backward[40002]=payload(-40001);
  check(std::get<std::int32_t>(run_register_vm(long_backward,long_regs))==42,"long backward execution");
  long_forward[0]={O::ext_prefix,2,2,0};long_forward[2]={O::ret,0,0,0};
  check(std::get<std::int32_t>(run_register_vm(long_forward,long_regs))==0,"untaken long conditional");
  long_regs[2]=1;check(std::get<std::int32_t>(run_register_vm(long_forward,long_regs))==42,"taken long conditional");
  long_forward[0]={O::ext_prefix,3,2,0};
  check(std::get<std::int32_t>(run_register_vm(long_forward,long_regs))==0,"untaken long false conditional");
  long_regs[2]=0;check(std::get<std::int32_t>(run_register_vm(long_forward,long_regs))==42,"taken long false conditional");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::ext_prefix,1,0,0}})),"truncated long branch");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::ext_prefix,4,0,0},{O::halt,0,0,0}})),"unknown extension");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::ext_prefix,1,1,0},{O::halt,0,0,0}})),"reserved extension operand");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::jump,0,0,1},{O::ext_prefix,1,0,0},payload(-2),{O::ret,1,0,0}})),"short branch into payload rejected");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::ext_prefix,1,0,0},payload(-1),{O::ret,1,0,0}})),"long branch into payload rejected");
  const Bytecode small_long{{O::ext_prefix,1,0,0},payload(0),{O::ret,1,0,0}};
  const std::vector<std::uint8_t> long_golden{'M','U','T','B',1,0,0,0,3,0,0,0,0x60,1,0,0,0,0,0,0,0x42,1,0,0};
  check(std::get<std::vector<std::uint8_t>>(encode_bytecode(small_long))==long_golden,"extended wire golden");
  check(std::get<Bytecode>(assemble_bytecode("0: jmp_long 0\n2: ret r1\n"))==small_long,"extended text golden");
  for (const auto offset:{std::numeric_limits<std::int32_t>::min(),std::numeric_limits<std::int32_t>::max()})
    check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{O::ext_prefix,1,0,0},payload(offset),{O::ret,1,0,0}})),"out-of-range long target");
  Bytecode largest(65536,I{O::halt,0,0,0});
  auto largest_wire=encode_bytecode(largest);
  check(std::holds_alternative<std::vector<std::uint8_t>>(largest_wire) && std::get<Bytecode>(decode_bytecode(std::get<std::vector<std::uint8_t>>(largest_wire)))==largest,"maximum word count roundtrip");
  Bytecode huge(65537,I{O::halt,0,0,0});
  check(std::get<BytecodeError>(validate_bytecode(huge)).code==BytecodeErrorCode::size_limit,"instruction limit");
  std::array<std::int32_t,256> r{};r[1]=17;r[2]=-5;r[0]=7;
  auto value=run_register_vm(code,r);
  check(std::holds_alternative<std::int32_t>(value) && std::get<std::int32_t>(value)==12,"vm addition");
  check(std::get<std::int32_t>(run_register_vm(Bytecode{{O::ret,0,0,0}},r))==0,"r0 zeroed");
  Bytecode sum{{O::lt,4,1,2},{O::branch_false,4,0,3},{O::add,3,3,1},{O::add,1,1,5},{O::jump,0,0xff,0xfb},{O::ret,3,0,0}};
  r={};r[2]=11;r[5]=1;
  auto sum_result=run_register_vm(sum,r);
  check(std::holds_alternative<std::int32_t>(sum_result) && std::get<std::int32_t>(sum_result)==55,"loop result");
  auto loop=Bytecode{{O::jump,0,0xff,0xff}};
  check(std::get<VmError>(run_register_vm(loop,{},4)).code==VmErrorCode::budget_exceeded,"infinite loop budget");
  check(std::get<VmError>(run_register_vm(code,r,100001)).code==VmErrorCode::invalid_budget,"budget cap");
  check(std::get<VmError>(run_register_vm(code,r,0)).code==VmErrorCode::budget_exceeded,"zero budget");
  r={};r[1]=std::numeric_limits<std::int32_t>::max();r[2]=1;
  check(std::get<VmError>(run_register_vm(code,r)).code==VmErrorCode::overflow,"add overflow");
  r[1]=std::numeric_limits<std::int32_t>::min();r[2]=-1;
  for (auto op:{O::div,O::mod}) check(std::get<VmError>(run_register_vm(Bytecode{{op,3,1,2},{O::ret,3,0,0}},r)).code==VmErrorCode::overflow,"min / -1 overflow");
  r[2]=0;check(std::get<VmError>(run_register_vm(Bytecode{{O::div,3,1,2},{O::ret,3,0,0}},r)).code==VmErrorCode::divide_by_zero,"divide by zero");
  std::mt19937 rng(0x4d555438);
  for (int k=0;k<2000;++k) {
    auto a=static_cast<std::int32_t>(rng()%20001)-10000, b=static_cast<std::int32_t>(rng()%20001)-10000;
    r={};r[1]=a;r[2]=b;
    auto actual=run_register_vm(code,r);
    auto source="fn f(a:i32,b:i32)->i32 {return a+b;} f("+std::to_string(a)+","+std::to_string(b)+")";
    auto reference=run_program(source);
    check(std::holds_alternative<std::int32_t>(actual) && std::holds_alternative<NumericValue>(reference) && std::get<std::int32_t>(actual)==std::get<std::int64_t>(std::get<NumericValue>(reference).data),"tree-walk differential");
  }
  const std::array<std::pair<O,std::string_view>,5> operations{{{O::add,"A+B"},{O::sub,"A-B"},{O::mul,"A*B"},{O::div,"A/B"},{O::mod,"A%B"}}};
  for (const auto& [op,expression]:operations) {
    const auto ast=std::get<Ast>(parse_arithmetic(expression));
    for (int k=0;k<2000;++k) {
      const auto a=static_cast<std::int32_t>(static_cast<std::int64_t>(rng()%200001)-100000);
      const auto b=static_cast<std::int32_t>(static_cast<std::int64_t>(rng()%200001)-100000);
      r={};r[1]=a;r[2]=b;
      const std::array<NumericBinding,2> bindings{{{"A",{NumericType::i32,static_cast<std::int64_t>(a)}},{"B",{NumericType::i32,static_cast<std::int64_t>(b)}}}};
      auto oracle=evaluate_arithmetic(ast,{},bindings);
      auto actual=run_register_vm(Bytecode{{op,3,1,2},{O::ret,3,0,0}},r);
      if (const auto* n=std::get_if<NumericValue>(&oracle))
        check(std::holds_alternative<std::int32_t>(actual) && std::get<std::int32_t>(actual)==std::get<std::int64_t>(n->data),"arithmetic differential result");
      else {
        const auto* err=std::get_if<VmError>(&actual);
        const auto expected=std::get<EvalDiagnostic>(oracle).code==EvalErrorCode::divide_by_zero ? VmErrorCode::divide_by_zero : VmErrorCode::overflow;
        check(err && err->code==expected,"arithmetic differential error");
      }
    }
  }
  for (int k=0;k<1000;++k) {
    Bytecode sample;
    for (int n=0;n<16;++n) {
      const auto op=operations[rng()%operations.size()].first;
      sample.push_back(I{op,static_cast<std::uint8_t>(1+rng()%255),static_cast<std::uint8_t>(rng()),static_cast<std::uint8_t>(rng())});
    }
    sample.push_back(I{O::ret,static_cast<std::uint8_t>(rng()),0,0});
    const auto text=disassemble_bytecode(sample);
    if (auto* value=std::get_if<std::string>(&text)) {
      const auto roundtrip=assemble_bytecode(*value);
      check(std::holds_alternative<Bytecode>(roundtrip) && std::get<Bytecode>(roundtrip)==sample,"random textual roundtrip");
    } else check(false,"random disassembly");
  }
  for (int k=0;k<3000;++k) {
    auto candidate=std::get<std::vector<std::uint8_t>>(encoded);
    const auto mutations=1+rng()%5;
    for (unsigned j=0;j<mutations;++j) candidate[rng()%candidate.size()]=static_cast<std::uint8_t>(rng());
    auto result=decode_bytecode(candidate);
    if (auto* instructions=std::get_if<Bytecode>(&result)) {
      auto out=encode_bytecode(*instructions);
      check(std::holds_alternative<std::vector<std::uint8_t>>(out) && std::get<std::vector<std::uint8_t>>(out)==candidate,"mutated accepted input re-encodes");
      (void)run_register_vm(*instructions,{},20);
    }
  }
  for (int k=0;k<10000;++k) {
    std::vector<std::uint8_t> random(rng()%96);for (auto& v:random) v=static_cast<std::uint8_t>(rng());
    auto result=decode_bytecode(random);
    if (auto* instructions=std::get_if<Bytecode>(&result)) {
      auto out=encode_bytecode(*instructions);
      check(std::holds_alternative<std::vector<std::uint8_t>>(out) && std::get<std::vector<std::uint8_t>>(out)==random,"accepted input re-encodes");
    }
  }
  return failures?1:0;
}
