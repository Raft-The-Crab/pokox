#include "poko/mute/program.hpp"
#include "poko/mute/register_vm.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <limits>
#include <span>
#include <cstdint>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace poko::mute {
namespace {
constexpr std::size_t source_limit=65'536, token_limit=8192, parse_depth_limit=64;
constexpr std::size_t call_limit=64, eval_depth_limit=128;
constexpr std::size_t function_limit=256, parameter_limit=32, local_limit=256;
struct Failure { ProgramDiagnostic diagnostic; };
[[noreturn]] void fail(std::string_view stage, std::string_view code, Position pos) {
  throw Failure{{std::string(stage),std::string(code),pos}};
}
struct Depth {
  std::size_t& value;
  Depth(std::size_t& v, std::size_t limit, std::string_view stage, Position pos):value(v) {
    if (value>=limit) fail(stage,"depth_exceeded",pos);
    ++value;
  }
  ~Depth() { --value; }
  Depth(const Depth&)=delete;
  Depth& operator=(const Depth&)=delete;
};
struct Expr {
  enum class Kind { integer, boolean, variable, unary, binary, call } kind;
  Position pos;
  std::string_view text;
  std::size_t left=0, right=0;
  std::vector<std::size_t> args;
};
struct Stmt {
  enum class Kind { declare_let, declare_var, assign, ret, conditional, while_loop } kind;
  Position pos;
  std::string_view text;
  std::size_t expr=0, rhs=0;
  std::vector<Stmt> yes, no;
};
struct Function { std::string_view name; Position pos; std::vector<std::string_view> params; std::vector<Stmt> body; };
struct StateDecl {std::string_view name, literal;Position pos;bool negative=false;};
struct Program { std::vector<Expr> exprs; std::vector<Function> functions; std::vector<StateDecl> states; std::size_t main=0; };
class Parser {
 public:
  Parser(std::string_view source, const std::vector<Token>& tokens):source_(source),tokens_(tokens) {}
  Program parse() {
    while (is("@")) {
      const auto pos=current().begin;take();expect("state");expect("var");
      if (program_.states.size()>=max_state_fields) fail("parse","state_limit",pos);
      const auto name=identifier();
      for (const auto& prior:program_.states) if (prior.name==name) fail("parse","duplicate_state",pos);
      expect(":");expect("i32");expect("=");
      const bool negative=accept("-");if (!negative) (void)accept("+");
      if (current().kind!=TokenKind::integer) fail("parse","expected_state_literal",current().begin);
      const auto literal=text(current());take();expect(";");
      program_.states.push_back(StateDecl{name,literal,pos,negative});
    }
    while (is("fn")) {
      if (program_.functions.size()>=function_limit) fail("parse","function_limit",current().begin);
      Function f{}; take(); f.pos=current().begin; f.name=identifier();
      for (const auto& other:program_.functions) if (f.name==other.name) fail("parse","duplicate_function",f.pos);
      expect("(");
      if (!is(")")) do {
        if (f.params.size()>=parameter_limit) fail("parse","parameter_limit",current().begin);
        auto pos=current().begin; auto param=identifier();
        if (std::find(f.params.begin(),f.params.end(),param)!=f.params.end()) fail("parse","duplicate_parameter",pos);
        expect(":"); expect("i32"); f.params.push_back(param);
      } while (accept(","));
      expect(")"); expect("->"); expect("i32"); f.body=block();
      program_.functions.push_back(std::move(f));
    }
    if (program_.functions.empty()) fail("parse","expected_function",current().begin);
    program_.main=expression(0);
    if (current().kind!=TokenKind::end) fail("parse","unexpected_token",current().begin);
    return std::move(program_);
  }
 private:
  const Token& current() const { return tokens_[at_]; }
  std::string_view text(const Token& t) const { return source_.substr(t.begin.byte,t.end_byte-t.begin.byte); }
  bool is(std::string_view s) const { return text(current())==s && current().kind!=TokenKind::end; }
  bool accept(std::string_view s) { if (!is(s)) return false; ++at_; return true; }
  void take() { if (current().kind!=TokenKind::end) ++at_; }
  void expect(std::string_view s) { if (!accept(s)) fail("parse","unexpected_token",current().begin); }
  std::string_view identifier() {
    if (current().kind!=TokenKind::identifier) fail("parse","expected_identifier",current().begin);
    auto result=text(current()); take(); return result;
  }
  std::size_t add(Expr e) { program_.exprs.push_back(std::move(e)); return program_.exprs.size()-1; }
  int precedence() const {
    if (is("||")) return 1;
    if (is("&&")) return 2;
    if (is("==") || is("!=")) return 3;
    if (is("<") || is("<=") || is(">") || is(">=")) return 4;
    if (is("+") || is("-")) return 5;
    if (is("*") || is("/") || is("%")) return 6;
    return 0;
  }
  std::size_t expression(int minimum) {
    Depth depth(parse_depth_,parse_depth_limit,"parse",current().begin);
    auto pos=current().begin;
    std::size_t lhs;
    if (is("+") || is("-") || is("!")) {
      auto op=text(current()); take(); auto child=expression(6);
      lhs=add(Expr{Expr::Kind::unary,pos,op,child,0,{}});
    } else if (accept("(")) { lhs=expression(0); expect(")"); }
    else if (is("true") || is("false")) {
      auto literal=text(current()); take(); lhs=add(Expr{Expr::Kind::boolean,pos,literal,0,0,{}});
    } else if (current().kind==TokenKind::integer) {
      auto literal=text(current()); take(); lhs=add(Expr{Expr::Kind::integer,pos,literal,0,0,{}});
    } else if (current().kind==TokenKind::identifier) {
      auto id=identifier();
      if (accept("(")) {
        Expr call{Expr::Kind::call,pos,id,0,0,{}};
        if (!is(")")) do {
          if (call.args.size()>=parameter_limit) fail("parse","argument_limit",current().begin);
          call.args.push_back(expression(0));
        } while (accept(","));
        expect(")"); lhs=add(std::move(call));
      } else lhs=add(Expr{Expr::Kind::variable,pos,id,0,0,{}});
    } else fail("parse","expected_expression",pos);
    while (precedence()>minimum) {
      auto op=text(current()); auto op_pos=current().begin; auto prec=precedence(); take();
      auto rhs=expression(prec); lhs=add(Expr{Expr::Kind::binary,op_pos,op,lhs,rhs,{}});
    }
    return lhs;
  }
  std::vector<Stmt> block() {
    Depth depth(parse_depth_,parse_depth_limit,"parse",current().begin);
    expect("{"); std::vector<Stmt> result;
    while (!is("}") && current().kind!=TokenKind::end) {
      const auto pos=current().begin;
      if (is("let") || is("var")) {
        bool mut=is("var"); take(); auto id=identifier();
        if (accept(":")) expect("i32");
        expect("="); auto expr=expression(0); expect(";");
        result.push_back(Stmt{mut?Stmt::Kind::declare_var:Stmt::Kind::declare_let,pos,id,expr,0,{},{}});
      } else if (accept("return")) {
        auto expr=expression(0); expect(";"); result.push_back(Stmt{Stmt::Kind::ret,pos,{},expr,0,{},{}});
      } else if (accept("if")) {
        auto condition=expression(0); auto yes=block(); std::vector<Stmt> no;
        if (accept("else")) no=block();
        result.push_back(Stmt{Stmt::Kind::conditional,pos,{},condition,0,std::move(yes),std::move(no)});
      } else if (accept("while")) {
        auto condition=expression(0); auto body=block();
        result.push_back(Stmt{Stmt::Kind::while_loop,pos,{},condition,0,std::move(body),{}});
      } else if (current().kind==TokenKind::identifier) {
        auto id=identifier(); expect("="); auto expr=expression(0); expect(";");
        result.push_back(Stmt{Stmt::Kind::assign,pos,id,expr,0,{},{}});
      } else fail("parse","unsupported_statement",pos);
    }
    expect("}"); return result;
  }
  std::string_view source_; const std::vector<Token>& tokens_; std::size_t at_=0,parse_depth_=0; Program program_;
};
struct Local { std::string_view name; NumericValue value; bool mut; };
using Scope=std::vector<Local>;
struct Frame { std::vector<Scope> scopes; std::size_t local_count=0; };
using Value = std::variant<NumericValue, bool>;
class Runner {
 public:
  explicit Runner(const Program& p,std::size_t max_steps,Scope* globals=nullptr):p_(p),max_steps_(max_steps),globals_(globals) {}
  NumericValue run() { Frame frame; frame.scopes.emplace_back(); return as_number(eval(p_.main,frame),p_.exprs[p_.main].pos); }
 public:
  void step(Position pos) { if (steps_>=max_steps_) fail("runtime","budget_exceeded",pos); ++steps_; }
  static NumericValue checked(EvalResult result,Position pos) {
    if (auto* e=std::get_if<EvalDiagnostic>(&result)) fail("eval",name(e->code),pos);
    auto value=std::get<NumericValue>(std::move(result));
    if (value.type!=NumericType::i32) fail("eval","type_mismatch",pos);
    return value;
  }
  static NumericValue arithmetic(std::string_view source,Position pos,std::span<const NumericBinding> bindings={}) {
    auto parsed=parse_arithmetic(source);
    if (!std::holds_alternative<Ast>(parsed)) fail("parse","invalid_arithmetic",pos);
    return checked(evaluate_arithmetic(std::get<Ast>(parsed),{},bindings),pos);
  }
  Local* find(Frame& f,std::string_view name) {
    for (auto scope=f.scopes.rbegin();scope!=f.scopes.rend();++scope)
      for (auto& local:*scope) if (local.name==name) return &local;
    if (globals_) for (auto& global:*globals_) if (global.name==name) return &global;
    return nullptr;
  }
  static NumericValue as_number(const Value& value,Position pos) {
    if (const auto* n=std::get_if<NumericValue>(&value)) return *n;
    fail("eval","type_mismatch",pos);
  }
  static bool as_bool(const Value& value,Position pos) {
    if (const auto* b=std::get_if<bool>(&value)) return *b;
    fail("eval","type_mismatch",pos);
  }
  Value eval(std::size_t index,Frame& frame) {
    const auto& e=p_.exprs[index]; step(e.pos); Depth depth(eval_depth_,eval_depth_limit,"runtime",e.pos);
    switch (e.kind) {
      case Expr::Kind::integer: return arithmetic(e.text,e.pos);
      case Expr::Kind::boolean: return e.text=="true";
      case Expr::Kind::variable: {
        auto* local=find(frame,e.text); if (!local) fail("runtime","unknown_local",e.pos); return local->value;
      }
      case Expr::Kind::unary: {
        const auto& child=p_.exprs[e.left];
        if (e.text=="-" && child.kind==Expr::Kind::integer) {
          return arithmetic(std::string("-")+std::string(child.text),e.pos);
        }
        auto operand=eval(e.left,frame);
        if (e.text=="!") return !as_bool(operand,e.pos);
        auto v=as_number(operand,e.pos); std::array<NumericBinding,1> b{{{"A",v}}};
        return arithmetic(std::string(e.text)+"A",e.pos,b);
      }
      case Expr::Kind::binary: {
        auto left=eval(e.left,frame);
        if (e.text=="&&" || e.text=="||") {
          bool a=as_bool(left,e.pos);
          if ((e.text=="&&" && !a) || (e.text=="||" && a)) return a;
          return as_bool(eval(e.right,frame),e.pos);
        }
        auto right=eval(e.right,frame);
        if (e.text=="==" || e.text=="!=") {
          bool equal;
          if (const auto* a=std::get_if<bool>(&left)) equal=*a==as_bool(right,e.pos);
          else equal=std::get<std::int64_t>(as_number(left,e.pos).data)==std::get<std::int64_t>(as_number(right,e.pos).data);
          return e.text=="==" ? equal : !equal;
        }
        auto a=as_number(left,e.pos); auto b=as_number(right,e.pos);
        if (e.text=="<" || e.text=="<=" || e.text==">" || e.text==">=") {
          auto x=std::get<std::int64_t>(a.data), y=std::get<std::int64_t>(b.data);
          if (e.text=="<") return x<y;
          if (e.text=="<=") return x<=y;
          if (e.text==">") return x>y;
          return x>=y;
        }
        std::array<NumericBinding,2> bindings{{{"A",a},{"B",b}}};
        return arithmetic(std::string("A")+std::string(e.text)+"B",e.pos,bindings);
      }
      case Expr::Kind::call: {
        auto it=std::find_if(p_.functions.begin(),p_.functions.end(),[&](const auto& f){return f.name==e.text;});
        if (it==p_.functions.end()) fail("runtime","unknown_function",e.pos);
        if (it->params.size()!=e.args.size()) fail("runtime","wrong_arity",e.pos);
        std::vector<NumericValue> args; args.reserve(e.args.size());
        for (auto arg:e.args) args.push_back(as_number(eval(arg,frame),p_.exprs[arg].pos));
        Depth call(call_depth_,call_limit,"runtime",e.pos);
        Frame callee; callee.scopes.emplace_back();
        for (std::size_t i=0;i<args.size();++i) callee.scopes.back().push_back(Local{it->params[i],args[i],false});
        callee.local_count=args.size();
        auto result=statements(it->body,callee,it->pos);
        if (!result) fail("runtime","missing_return",it->pos);
        return *result;
      }
    }
    fail("runtime","invalid_expression",e.pos);
  }
  std::optional<NumericValue> statements(const std::vector<Stmt>& body,Frame& frame,Position pos) {
    Depth depth(eval_depth_,eval_depth_limit,"runtime",pos);
    for (const auto& s:body) {
      step(s.pos);
      switch (s.kind) {
        case Stmt::Kind::declare_let: case Stmt::Kind::declare_var: {
          for (const auto& l:frame.scopes.back()) if (l.name==s.text) fail("runtime","duplicate_local",s.pos);
          if (frame.local_count>=local_limit) fail("runtime","local_limit",s.pos);
          auto value=as_number(eval(s.expr,frame),p_.exprs[s.expr].pos); frame.scopes.back().push_back(Local{s.text,value,s.kind==Stmt::Kind::declare_var}); ++frame.local_count; break;
        }
        case Stmt::Kind::assign: {
          auto* l=find(frame,s.text); if (!l) fail("runtime","unknown_local",s.pos);
          if (!l->mut) fail("runtime","immutable_local",s.pos);
          auto value=as_number(eval(s.expr,frame),p_.exprs[s.expr].pos); l->value=value; break;
        }
        case Stmt::Kind::ret: return as_number(eval(s.expr,frame),p_.exprs[s.expr].pos);
        case Stmt::Kind::conditional: {
          bool condition=as_bool(eval(s.expr,frame),p_.exprs[s.expr].pos);
          frame.scopes.emplace_back(); auto result=statements(condition?s.yes:s.no,frame,s.pos);
          frame.local_count-=frame.scopes.back().size(); frame.scopes.pop_back();
          if (result) return result;
          break;
        }
        case Stmt::Kind::while_loop: {
          for (;;) {
            // Charge every condition check, including empty-body iterations.
            step(s.pos);
            if (!as_bool(eval(s.expr,frame),p_.exprs[s.expr].pos)) break;
            frame.scopes.emplace_back(); auto result=statements(s.yes,frame,s.pos);
            frame.local_count-=frame.scopes.back().size(); frame.scopes.pop_back();
            if (result) return result;
          }
          break;
        }
      }
    }
    return std::nullopt;
  }
  const Program& p_; std::size_t max_steps_,steps_=0,call_depth_=0,eval_depth_=0;Scope* globals_;
};
Scope prepare_globals(const Program& program,const ProgramState& state) {
  if (!state.initialized && !state.fields.empty()) fail("state","invalid_state",Position{0,1,1});
  if (state.initialized && state.fields.size()!=program.states.size()) fail("state","schema_mismatch",Position{0,1,1});
  Scope globals;globals.reserve(program.states.size());
  for (std::size_t i=0;i<program.states.size();++i) {
    const auto& decl=program.states[i];
    const auto literal=(decl.negative?std::string("-"):std::string{})+std::string(decl.literal);
    auto value=Runner::arithmetic(literal,decl.pos);
    if (state.initialized) {
      if (state.fields[i].name!=decl.name) fail("state","schema_mismatch",decl.pos);
      value=NumericValue{NumericType::i32,static_cast<std::int64_t>(state.fields[i].value)};
    }
    globals.push_back(Local{decl.name,value,true});
  }
  return globals;
}
void commit_globals(ProgramState& state,const Scope& globals) {
  ProgramState next;next.initialized=true;next.fields.reserve(globals.size());
  for (const auto& global:globals) next.fields.push_back(StateField{std::string(global.name),static_cast<std::int32_t>(std::get<std::int64_t>(global.value.data))});
  state=std::move(next);
}
#include "program_vm.inc"
#include "program_codec.inc"
} // namespace
ProgramResult run_stateful_program(std::string_view source,ProgramState& state,ProgramOptions options) {
  try {
    if (options.max_steps>ProgramOptions::max_allowed_steps) fail("runtime","invalid_options",Position{0,1,1});
    auto program=parse_program_for_codec(source);
    auto compiled=ProgramCompiler(program).compile();
    auto globals=prepare_globals(program,state);
    auto result=ProgramVm(program,compiled,options.max_steps,&globals).run();
    commit_globals(state,globals);return result;
  } catch (const Failure& failure) { return failure.diagnostic; }
}
ProgramResult run_program(std::string_view source,ProgramOptions options) {
  ProgramState state;return run_stateful_program(source,state,options);
}
std::variant<std::vector<std::string>,ProgramDiagnostic> inspect_program_state_schema(std::string_view source) {
  try {
    auto program=parse_program_for_codec(source);(void)prepare_globals(program,ProgramState{});
    std::vector<std::string> names;names.reserve(program.states.size());
    for (const auto& state:program.states) names.emplace_back(state.name);
    return names;
  } catch (const Failure& failure) {return failure.diagnostic;}
}
ProgramBytecodeResult compile_program_bytecode(std::string_view source) {
  try { auto parsed=parse_program_for_codec(source);auto compiled=ProgramCompiler(parsed).compile();
    (void)prepare_globals(parsed,ProgramState{});return encode_program(source,parsed,compiled); }
  catch (const Failure& failure) { return failure.diagnostic; }
}
ProgramResult run_stateful_program_bytecode(std::span<const std::uint8_t> bytes,ProgramState& state,ProgramOptions options) {
  try {
    if (options.max_steps>ProgramOptions::max_allowed_steps) fail("runtime","invalid_options",Position{0,1,1});
    auto decoded=decode_program(bytes);
    auto globals=prepare_globals(decoded.program,state);
    auto result=ProgramVm(decoded.program,decoded.code,options.max_steps,&globals).run();
    commit_globals(state,globals);return result;
  } catch (const Failure& failure) { return failure.diagnostic; }
}
ProgramResult run_program_bytecode(std::span<const std::uint8_t> bytes,ProgramOptions options) {
  ProgramState state;return run_stateful_program_bytecode(bytes,state,options);
}
std::variant<std::string,ProgramDiagnostic> disassemble_program_bytecode(std::span<const std::uint8_t> bytes) {
  try {auto decoded=decode_program(bytes);return disassemble_program(decoded.code,bytes);}
  catch (const Failure& failure) {return failure.diagnostic;}
}
ProgramBytecodeResult assemble_program_bytecode(std::string_view listing) {
  try {
    if (!listing.starts_with("MUTP1 ")) WireReader::bad();
    const auto end=listing.find('\n');
    if (end==std::string_view::npos || end<6 || (end-6)%2 || (end-6)/2>program_wire_limit || listing.size()>96*1024*1024) WireReader::bad();
    auto digit=[](char c)->int {if (c>='0'&&c<='9') return c-'0';if (c>='a'&&c<='f') return c-'a'+10;return -1;};
    std::vector<std::uint8_t> bytes;bytes.reserve((end-6)/2);
    for (std::size_t i=6;i<end;i+=2) {const int a=digit(listing[i]),b=digit(listing[i+1]);if (a<0 || b<0) WireReader::bad();bytes.push_back(static_cast<std::uint8_t>(a*16+b));}
    auto decoded=decode_program(bytes);
    if (disassemble_program(decoded.code,bytes)!=listing) WireReader::bad();
    return bytes;
  } catch (const Failure& failure) {return failure.diagnostic;}
}
namespace testing {
ProgramResult run_program_reference(std::string_view source,ProgramOptions options) {
  try {
    if (options.max_steps>ProgramOptions::max_allowed_steps) fail("runtime","invalid_options",Position{0,1,1});
    auto lexed=lex(source,LexOptions{source_limit});
    if (const auto* e=std::get_if<Diagnostic>(&lexed)) fail("lex",name(e->code),e->position);
    const auto& tokens=std::get<std::vector<Token>>(lexed);
    if (tokens.size()>token_limit) fail("parse","token_limit",tokens.back().begin);
    auto program=Parser(source,tokens).parse();
    auto globals=prepare_globals(program,ProgramState{});
    return Runner(program,options.max_steps,&globals).run();
  } catch (const Failure& failure) { return failure.diagnostic; }
}
} // namespace testing
} // namespace poko::mute
