// BAK-06: rule evaluator, fixed-cost (spec 05 "Rule language": expression
// only, no loops, allocation, hostcalls or function definitions; queue row
// BAK-06 acceptance "No rule exceeds budget").
//
// The .pkB declares rules as s-expression text, one per line (the generator
// form; the CBOR binary form parses to the same structures):
//
//   rule "velocity_cap" on player.velocity
//   assert le(length(value), add(12.0, 0.5))
//
// Evaluated per tick by the authority BEFORE committing Validated
// proposals: every assert in every rule on the proposed field must hold
// against (value = proposal, previous() = committed value, tick, dt) or the
// whole proposal is discarded. Evaluation is bounded by construction: a
// parsed rule is a finite AST whose node count the parser caps
// (kMaxRuleNodes) and whose depth it refuses beyond kMaxRuleDepth, so cost
// is fixed per rule — the language has no loops or recursion to hide cost
// in.
#pragma once

#include "poko/authority/pkb_schema.hpp"

#include <cmath>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace poko::authority {

struct RuleLimits {
  static constexpr std::size_t kMaxRuleNodes = 64;  // per rule; fixed-cost bound
  static constexpr std::size_t kMaxRules = 256;     // per schema
  static constexpr std::size_t kMaxRuleDepth = 12;  // parse-time recursion bound
};

struct RuleNode {
  enum class Op : std::uint8_t {
    num,          // leaf: numeric literal
    value,        // the proposed value (scalar)
    previous,     // previous committed value of the rule's field (scalar)
    field,        // named field's current value
    tick, dt,
    add, sub, mul, div,
    lt, le, gt, ge, eq, ne,
    and_, or_, not_,
    length,       // 2D length of the two scalar axes named in args
    distance,     // euclidean over two axis pairs via named fields
    dot,
    clamp, abs_, min_, max_,
    granted_this_tick, // 1.0 if the field got a proposal this tick, else 0
  };
  Op op = Op::num;
  double num = 0.0;
  std::uint32_t field_ref = 0;           // resolved field id for field/previous
  std::vector<std::unique_ptr<RuleNode>> args;
};

struct Rule {
  std::string name;
  std::uint32_t on_field = 0;            // field id the rule guards
  std::vector<std::unique_ptr<RuleNode>> asserts;
};

struct RuleLoadError {
  enum class Code : std::uint8_t { none, malformed, unknown_field, too_many_nodes, too_deep, too_many_rules };
  Code code = Code::none;
  std::string detail;
};

// S-expression parser. Tokens: ( ) atoms. Atoms are numbers, field names
// (dotted), or operator names.
class RuleParser {
public:
  explicit RuleParser(const std::unordered_map<std::string, std::uint32_t>& field_ids)
      : field_ids_(field_ids) {}

  [[nodiscard]] RuleLoadError parse(std::string_view text, std::vector<Rule>& out) {
    RuleLoadError err;
    out.clear();
    std::size_t pos = 0;
    std::size_t rule_count = 0;
    while (pos <= text.size()) {
      skip_ws(text, pos);
      if (pos >= text.size()) break;
      if (text[pos] == '#') { // comment to end of line
        while (pos < text.size() && text[pos] != '\n') ++pos;
        continue;
      }
      if (text.compare(pos, 4, "rule") != 0) {
        err.code = RuleLoadError::Code::malformed; err.detail = "expected rule"; return err;
      }
      pos += 4;
      Rule r;
      std::string name = read_atom(text, pos);
      if (name.size() < 2 || name.front() != '"' || name.back() != '"') {
        err.code = RuleLoadError::Code::malformed; err.detail = "rule name"; return err;
      }
      r.name = name.substr(1, name.size() - 2);
      skip_ws(text, pos);
      if (text.compare(pos, 2, "on") != 0) { err.code = RuleLoadError::Code::malformed; err.detail = "missing on"; return err; }
      pos += 2;
      const std::string on = read_atom(text, pos);
      const auto it = field_ids_.find(on);
      if (it == field_ids_.end()) { err.code = RuleLoadError::Code::unknown_field; err.detail = on; return err; }
      r.on_field = it->second;

      for (;;) {
        skip_ws(text, pos);
        if (pos >= text.size() || text[pos] == '#') break;
        if (text.compare(pos, 6, "assert") != 0) break;
        pos += 6;
        node_count_ = 0;
        auto node = parse_expr(text, pos, 0, err);
        if (err.code != RuleLoadError::Code::none) return err;
        if (!node) { err.code = RuleLoadError::Code::malformed; err.detail = "empty assert"; return err; }
        r.asserts.push_back(std::move(node));
      }
      if (++rule_count > RuleLimits::kMaxRules) {
        err.code = RuleLoadError::Code::too_many_rules; err.detail = r.name; return err;
      }
      out.push_back(std::move(r));
    }
    return err;
  }

private:
  static void skip_ws(std::string_view t, std::size_t& pos) {
    while (pos < t.size() && (t[pos] == ' ' || t[pos] == '\n' || t[pos] == '\t' || t[pos] == '\r')) ++pos;
  }
  [[nodiscard]] static std::string read_atom(std::string_view t, std::size_t& pos) {
    skip_ws(t, pos);
    const std::size_t start = pos;
    while (pos < t.size() && t[pos] != ' ' && t[pos] != '\n' && t[pos] != '\t' && t[pos] != '\r' &&
           t[pos] != '(' && t[pos] != ')' && t[pos] != ',') ++pos;
    return std::string(t.substr(start, pos - start));
  }

  [[nodiscard]] std::unique_ptr<RuleNode> parse_expr(std::string_view text, std::size_t& pos,
                                                     std::size_t depth, RuleLoadError& err) {
    if (depth > RuleLimits::kMaxRuleDepth) { err.code = RuleLoadError::Code::too_deep; return nullptr; }
    skip_ws(text, pos);
    if (pos >= text.size() || text[pos] == ',') { err.code = RuleLoadError::Code::malformed; err.detail = "expected expr"; return nullptr; }
    const std::string head = read_atom(text, pos);
    skip_ws(text, pos);
    if (head.empty()) {
      // S-expr form: (op args...) — the operator name sits after '('.
      if (pos >= text.size() || text[pos] != '(') { err.code = RuleLoadError::Code::malformed; err.detail = "empty atom"; return nullptr; }
      ++pos;
      skip_ws(text, pos);
      const std::string inner = read_atom(text, pos);
      if (inner.empty()) { err.code = RuleLoadError::Code::malformed; err.detail = "empty head"; return nullptr; }
      return parse_call(inner, text, pos, depth, err);
    }
    // Call form: an operator name followed by '('. In s-expr form a
    // non-operator atom before '(' is a completed arg (e.g. the 1.0 in
    // `(add 1.0 (add 1.0 1.0))`); the caller's arg loop consumes the '('.
    if (pos < text.size() && text[pos] == '(' && is_operator(head)) {
      ++pos; // consume '('
      return parse_call(head, text, pos, depth, err);
    }
    // Bare leaf: keyword, number, or field reference.
    return parse_leaf(head, err);
  }

  [[nodiscard]] static bool is_operator(const std::string& h) {
    return h == "add" || h == "+" || h == "sub" || h == "-" || h == "mul" || h == "*" ||
           h == "div" || h == "/" || h == "lt" || h == "le" || h == "gt" || h == "ge" ||
           h == "eq" || h == "ne" || h == "and" || h == "or" || h == "not" || h == "length" ||
           h == "distance" || h == "dot" || h == "clamp" || h == "abs" || h == "min" ||
           h == "max" || h == "grantedThisTick" || h == "tick" || h == "dt" || h == "value" ||
           h == "previous" || h == "prev";
  }

  [[nodiscard]] std::unique_ptr<RuleNode> parse_leaf(const std::string& head, RuleLoadError& err) {
    auto leaf = std::make_unique<RuleNode>();
    // Every AST node counts toward the budget, literals and keywords included.
    if (++node_count_ > RuleLimits::kMaxRuleNodes) { err.code = RuleLoadError::Code::too_many_nodes; return nullptr; }
    if (head == "value") { leaf->op = RuleNode::Op::value; return leaf; }
    if (head == "previous" || head == "prev") { leaf->op = RuleNode::Op::previous; leaf->field_ref = 0; return leaf; }
    if (head == "tick") { leaf->op = RuleNode::Op::tick; return leaf; }
    if (head == "dt") { leaf->op = RuleNode::Op::dt; return leaf; }
    if (head == "grantedThisTick") { leaf->op = RuleNode::Op::granted_this_tick; return leaf; }
    double v = 0;
    if (parse_double(head, v)) { leaf->op = RuleNode::Op::num; leaf->num = v; return leaf; }
    const auto fit = field_ids_.find(head);
    if (fit == field_ids_.end()) { err.code = RuleLoadError::Code::unknown_field; err.detail = head; return nullptr; }
    leaf->op = RuleNode::Op::field;
    leaf->field_ref = fit->second;
    return leaf;
  }

  [[nodiscard]] std::unique_ptr<RuleNode> parse_call(const std::string& head, std::string_view text,
                                                     std::size_t& pos, std::size_t depth, RuleLoadError& err) {
    auto node = std::make_unique<RuleNode>();
    // Caller consumed the '('; dispatch the operator head.
    if (head == "add" || head == "+") node->op = RuleNode::Op::add;
    else if (head == "sub" || head == "-") node->op = RuleNode::Op::sub;
    else if (head == "mul" || head == "*") node->op = RuleNode::Op::mul;
    else if (head == "div" || head == "/") node->op = RuleNode::Op::div;
    else if (head == "lt") node->op = RuleNode::Op::lt;
    else if (head == "le") node->op = RuleNode::Op::le;
    else if (head == "gt") node->op = RuleNode::Op::gt;
    else if (head == "ge") node->op = RuleNode::Op::ge;
    else if (head == "eq") node->op = RuleNode::Op::eq;
    else if (head == "ne") node->op = RuleNode::Op::ne;
    else if (head == "and") node->op = RuleNode::Op::and_;
    else if (head == "or") node->op = RuleNode::Op::or_;
    else if (head == "not") node->op = RuleNode::Op::not_;
    else if (head == "length") node->op = RuleNode::Op::length;
    else if (head == "distance") node->op = RuleNode::Op::distance;
    else if (head == "dot") node->op = RuleNode::Op::dot;
    else if (head == "clamp") node->op = RuleNode::Op::clamp;
    else if (head == "abs") node->op = RuleNode::Op::abs_;
    else if (head == "min") node->op = RuleNode::Op::min_;
    else if (head == "max") node->op = RuleNode::Op::max_;
    else if (head == "grantedThisTick") node->op = RuleNode::Op::granted_this_tick;
    else if (head == "tick") node->op = RuleNode::Op::tick;
    else if (head == "dt") node->op = RuleNode::Op::dt;
    else if (head == "value") node->op = RuleNode::Op::value;
    else if (head == "previous" || head == "prev") {
      node->op = RuleNode::Op::previous;
      node->field_ref = 0;
      skip_ws(text, pos);
      if (pos < text.size() && text[pos] != ')') {
        const std::string target = read_atom(text, pos);
        const auto it = field_ids_.find(target);
        if (it == field_ids_.end()) { err.code = RuleLoadError::Code::unknown_field; err.detail = target; return nullptr; }
        node->field_ref = it->second;
      }
    } else {
      err.code = RuleLoadError::Code::malformed; err.detail = "operator " + head; return nullptr;
    }
    if (++node_count_ > RuleLimits::kMaxRuleNodes) { err.code = RuleLoadError::Code::too_many_nodes; return nullptr; }
    for (;;) {
      skip_ws(text, pos);
      if (pos < text.size() && text[pos] == ',') { ++pos; continue; } // C-like arg separators
      if (pos < text.size() && text[pos] == ')') { ++pos; break; }
      if (pos >= text.size()) { err.code = RuleLoadError::Code::malformed; err.detail = "unterminated"; return nullptr; }
      auto child = parse_expr(text, pos, depth + 1, err);
      if (err.code != RuleLoadError::Code::none) return nullptr;
      node->args.push_back(std::move(child));
    }
    return node;
  }

  [[nodiscard]] static bool parse_double(const std::string& s, double& v) {
    try { std::size_t used = 0; v = std::stod(s, &used); return used == s.size(); }
    catch (const std::exception&) { return false; }
  }

  const std::unordered_map<std::string, std::uint32_t>& field_ids_;
  std::size_t node_count_ = 0;
};

// Fixed-cost evaluator. Every operator is O(1); the AST node count is capped
// at parse time, so a rule's cost is bounded by kMaxRuleNodes evaluations —
// the acceptance "no rule exceeds budget".
class RuleEvaluator {
public:
  struct Env {
    std::uint64_t tick = 0;
    double dt = 1.0 / 30.0;                 // 30 Hz simulation tick
    double value = 0.0;                     // proposal under validation
    double previous = 0.0;                  // committed value of the guarded field
    bool granted = false;                   // did this field get a proposal this tick
    const std::unordered_map<std::uint32_t, double>* field_values = nullptr; // current values by field id
  };

  struct Outcome {
    bool ok = true;
    std::string failed_rule; // first failing assert's rule name (generic elsewhere)
  };

  [[nodiscard]] static Outcome check(const std::vector<Rule>& rules, std::uint32_t proposed_field,
                                     const Env& env) {
    Outcome out;
    for (const Rule& r : rules) {
      if (r.on_field != proposed_field) continue;
      for (const auto& a : r.asserts) {
        if (eval(*a, env) == 0.0) { // assert holds when truthy (non-zero)
          out.ok = false;
          out.failed_rule = r.name;
          return out;
        }
      }
    }
    return out;
  }

  // Arity-checked child access: a malformed rule never reaches evaluation
  // (the parser builds exact arities), but a missing arg evaluates to 0.0
  // instead of reading out of bounds.
  [[nodiscard]] static double arg(const RuleNode& n, std::size_t i, const Env& env) {
    return i < n.args.size() ? eval(*n.args[i], env) : 0.0;
  }

  [[nodiscard]] static double eval(const RuleNode& n, const Env& env) {
    switch (n.op) {
      case RuleNode::Op::num: return n.num;
      case RuleNode::Op::value: return env.value;
      case RuleNode::Op::previous:
        // field_ref 0 = the guarded field's committed value (bare prev);
        // a named target resolves against the current field table.
        if (n.field_ref == 0) return env.previous;
        if (!env.field_values) return 0.0;
        {
          const auto it = env.field_values->find(n.field_ref);
          return it == env.field_values->end() ? 0.0 : it->second;
        }
      case RuleNode::Op::tick: return double(env.tick);
      case RuleNode::Op::dt: return env.dt;
      case RuleNode::Op::field: {
        if (!env.field_values) return 0.0;
        const auto it = env.field_values->find(n.field_ref);
        return it == env.field_values->end() ? 0.0 : it->second;
      }
      case RuleNode::Op::granted_this_tick: return env.granted ? 1.0 : 0.0;
      case RuleNode::Op::add: return arg(n, 0, env) + arg(n, 1, env);
      case RuleNode::Op::sub: return arg(n, 0, env) - arg(n, 1, env);
      case RuleNode::Op::mul: return arg(n, 0, env) * arg(n, 1, env);
      case RuleNode::Op::div: {
        const double d = arg(n, 1, env);
        return d == 0.0 ? 0.0 : arg(n, 0, env) / d; // div by zero is 0, not a trap
      }
      case RuleNode::Op::lt: return arg(n, 0, env) < arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::le: return arg(n, 0, env) <= arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::gt: return arg(n, 0, env) > arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::ge: return arg(n, 0, env) >= arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::eq: return arg(n, 0, env) == arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::ne: return arg(n, 0, env) != arg(n, 1, env) ? 1.0 : 0.0;
      case RuleNode::Op::and_: return arg(n, 0, env) != 0.0 && arg(n, 1, env) != 0.0 ? 1.0 : 0.0;
      case RuleNode::Op::or_: return arg(n, 0, env) != 0.0 || arg(n, 1, env) != 0.0 ? 1.0 : 0.0;
      case RuleNode::Op::not_: return arg(n, 0, env) == 0.0 ? 1.0 : 0.0;
      case RuleNode::Op::length: {
        const double x = arg(n, 0, env);
        const double y = n.args.size() > 1 ? arg(n, 1, env) : 0.0;
        return std::sqrt(x * x + y * y);
      }
      case RuleNode::Op::distance: {
        const double dx = arg(n, 0, env) - arg(n, 1, env);
        const double dy = arg(n, 2, env) - arg(n, 3, env);
        return std::sqrt(dx * dx + dy * dy);
      }
      case RuleNode::Op::dot: {
        const double ax = arg(n, 0, env), ay = arg(n, 1, env);
        const double bx = arg(n, 2, env), by = arg(n, 3, env);
        return ax * bx + ay * by;
      }
      case RuleNode::Op::clamp: {
        const double v = arg(n, 0, env);
        const double lo = arg(n, 1, env), hi = arg(n, 2, env);
        return v < lo ? lo : (v > hi ? hi : v);
      }
      case RuleNode::Op::abs_: return std::fabs(arg(n, 0, env));
      case RuleNode::Op::min_: return std::min(arg(n, 0, env), arg(n, 1, env));
      case RuleNode::Op::max_: return std::max(arg(n, 0, env), arg(n, 1, env));
    }
    return 0.0;
  }
};

} // namespace poko::authority
