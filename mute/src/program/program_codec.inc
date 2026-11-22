// MUTP v1 snapshot codec. The source is retained for metadata and validation:
// until MUT-27, only bytecode exactly reproduced by this compiler is executable.
constexpr std::size_t program_wire_limit=16*1024*1024;
Program parse_program_for_codec(std::string_view source) {
  auto lexed=lex(source,LexOptions{source_limit});
  if (const auto* e=std::get_if<Diagnostic>(&lexed)) fail("lex",name(e->code),e->position);
  const auto& tokens=std::get<std::vector<Token>>(lexed);
  if (tokens.size()>token_limit) fail("parse","token_limit",tokens.back().begin);
  return Parser(source,tokens).parse();
}
void wire_u32(std::vector<std::uint8_t>& out,std::uint32_t value) {
  for (unsigned i=0;i<4;++i) out.push_back(static_cast<std::uint8_t>(value>>(8*i)));
}
std::uint32_t bounded_u32(std::size_t value) {
  if (value>std::numeric_limits<std::uint32_t>::max()) fail("compile","bytecode_limit",Position{0,1,1});
  return static_cast<std::uint32_t>(value);
}
std::vector<std::uint8_t> encode_program(std::string_view source,const Program& program,const CompiledProgram& compiled) {
  std::vector<std::uint8_t> out{'M','U','T','P',1,0,0,0};
  wire_u32(out,bounded_u32(source.size()));
  out.insert(out.end(),source.begin(),source.end());
  wire_u32(out,bounded_u32(program.functions.size()));
  auto append_code=[&](const VmCode& code) {
    wire_u32(out,bounded_u32(code.size()));
    for (std::size_t pc=0;pc<code.size();++pc) {
      const auto& i=code[pc];
      out.push_back(static_cast<std::uint8_t>(i.op));
      auto a=bounded_u32(i.a),b=bounded_u32(i.b);
      // Snapshot branches use signed 32-bit instruction-relative offsets.
      if (i.op==VmOp::jump || i.op==VmOp::branch_false || i.op==VmOp::short_guard) {
        const auto target=i.op==VmOp::jump ? i.a : i.b;
        const auto delta=static_cast<std::int64_t>(target)-static_cast<std::int64_t>(pc)-1;
        if (delta<std::numeric_limits<std::int32_t>::min() || delta>std::numeric_limits<std::int32_t>::max())
          fail("compile","branch_range",i.pos);
        const auto bits=std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(delta));
        if (i.op==VmOp::jump) a=bits; else b=bits;
      }
      wire_u32(out,a);wire_u32(out,b);
      wire_u32(out,bounded_u32(i.pos.byte));wire_u32(out,bounded_u32(i.pos.line));wire_u32(out,bounded_u32(i.pos.column));
      wire_u32(out,bounded_u32(i.text.size()));
      out.insert(out.end(),i.text.begin(),i.text.end());
      if (out.size()>program_wire_limit) fail("compile","bytecode_limit",i.pos);
    }
  };
  for (const auto& code:compiled.functions) append_code(code);
  append_code(compiled.main);
  return out;
}
struct WireReader {
  std::span<const std::uint8_t> bytes;std::size_t at=0;
  [[noreturn]] static void bad() { fail("bytecode","invalid_program",Position{0,1,1}); }
  std::span<const std::uint8_t> take(std::size_t n) {
    if (n>bytes.size()-at) bad();
    const auto result=bytes.subspan(at,n);at+=n;return result;
  }
  std::uint32_t u32() {
    auto data=take(4);std::uint32_t value=0;
    for (unsigned i=0;i<4;++i) value|=static_cast<std::uint32_t>(data[i])<<(8*i);
    return value;
  }
};
struct DecodedProgram { Program program;CompiledProgram code; };
DecodedProgram decode_program(std::span<const std::uint8_t> bytes) {
  if (bytes.size()>program_wire_limit) WireReader::bad();
  WireReader r{bytes};const auto header=r.take(8);
  constexpr std::array<std::uint8_t,8> magic{'M','U','T','P',1,0,0,0};
  if (!std::equal(header.begin(),header.end(),magic.begin())) WireReader::bad();
  const auto source_size=r.u32();if (source_size>source_limit) WireReader::bad();
  const auto data=r.take(source_size);
  const std::string_view source(reinterpret_cast<const char*>(data.data()),data.size());
  // Recompile before decoding any instruction. This intentionally restrictive
  // integrity check protects the VM from unchecked instructions until MUT-27.
  Program parsed;
  std::vector<std::uint8_t> canonical;
  try {parsed=parse_program_for_codec(source);auto compiled=ProgramCompiler(parsed).compile();
    (void)prepare_globals(parsed,ProgramState{});canonical=encode_program(source,parsed,compiled);}
  catch (const Failure&) {WireReader::bad();}
  if (canonical.size()!=bytes.size() || !std::equal(canonical.begin(),canonical.end(),bytes.begin())) WireReader::bad();
  if (r.u32()!=parsed.functions.size()) WireReader::bad();
  auto read_code=[&]() {
    VmCode code;const auto count=r.u32();code.reserve(count);
    for (std::size_t pc=0;pc<count;++pc) {
      const auto op=static_cast<VmOp>(r.take(1)[0]);
      const auto a=r.u32(),b=r.u32();
      const Position pos{r.u32(),r.u32(),r.u32()};const auto text=r.take(r.u32());
      VmInstruction ins{op,pos,std::string_view(reinterpret_cast<const char*>(text.data()),text.size()),a,b};
      if (op==VmOp::jump || op==VmOp::branch_false || op==VmOp::short_guard) {
        const auto bits=op==VmOp::jump?a:b;
        const auto target=static_cast<std::int64_t>(pc)+1+std::bit_cast<std::int32_t>(bits);
        if (target<0 || target>=static_cast<std::int64_t>(count)) WireReader::bad();
        if (op==VmOp::jump) ins.a=static_cast<std::size_t>(target); else ins.b=static_cast<std::size_t>(target);
      }
      code.push_back(ins);
    }
    return code;
  };
  CompiledProgram code;code.functions.reserve(parsed.functions.size());
  for (std::size_t n=0;n<parsed.functions.size();++n) code.functions.push_back(read_code());
  code.main=read_code();if (r.at!=bytes.size()) WireReader::bad();
  return {std::move(parsed),std::move(code)};
}
std::string disassemble_program(const CompiledProgram& program,std::span<const std::uint8_t> bytes) {
  constexpr std::array names{"expr_enter","block_enter","depth_leave","step","literal","negative_literal","boolean",
    "load_local","unary","binary","short_guard","bool_copy","call_check","args_begin","arg_push","call",
    "decl_check","declare_local","assign_check","assign_local","scope_enter","scope_leave","branch_false","jump","ret","missing_return"};
  constexpr char hex[]="0123456789abcdef";
  std::string out="MUTP1 ";out.reserve(7+bytes.size()*2);
  for (const auto b:bytes) {out+=hex[b>>4];out+=hex[b&15];}
  out+='\n';
  auto listing=[&](const VmCode& code) {
    for (std::size_t pc=0;pc<code.size();++pc) {
      const auto& i=code[pc];
      out+=std::to_string(pc)+": "+names[static_cast<std::size_t>(i.op)]+" a="+std::to_string(i.a)+" b="+std::to_string(i.b)+" @"+std::to_string(i.pos.line)+":"+std::to_string(i.pos.column);
      if (!i.text.empty()) out+=" text="+std::string(i.text);
      out+='\n';
    }
  };
  for (std::size_t i=0;i<program.functions.size();++i) {out+="function "+std::to_string(i)+"\n";listing(program.functions[i]);}
  out+="main\n";listing(program.main);return out;
}
