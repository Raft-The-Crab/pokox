// BAK-06 acceptance: no rule exceeds budget. Rules parse into bounded ASTs
// (node count and depth capped at parse time; the language has no loops, so
// evaluation cost is fixed per rule), and a Validated proposal that breaks
// its .pkB rule is discarded with suspicion rising while an honest proposal
// passes through the same path. Also covers the spec-05 rule section's
// examples: a velocity cap of length(value) <= 12.0 + 0.5 and a
// move-limit of distance(value, prev) <= speed * dt, plus parser rejection
// paths and the div-by-zero-is-0 convention.
#include "poko/authority/pkb_schema.hpp"

#include <iostream>

using namespace poko::authority;

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
} // namespace

int main() {
  const std::string pkb_text =
      "game poko-bakery\n"
      "seed 777\n"
      "field player.position.x int Validated bits=12 initial=100\n"
      "field player.position.y int Validated bits=12 initial=200\n"
      "field player.velocity float Validated bits=12 min=-40.0 max=40.0 initial=0.0\n"
      "field player.score int Validated bits=20 initial=0\n";
  PkbSchema schema;
  check(load_pkb_schema(pkb_text, schema).code == PkbLoadError::Code::none, "schema loads");

  const std::string rules_text =
      "# spec 05 rule section examples\n"
      "rule \"velocity_cap\" on player.velocity\n"
      "assert le(length(value), add(12.0, 0.5))\n"
      "rule \"move_limit\" on player.position.x\n"
      "assert le(abs(sub(value, previous)), 12.0)\n"
      "rule \"monotone_score\" on player.score\n"
      "assert ge(value, previous)\n";

  PkbAuthority pa(schema, 0x1234);
  const auto rerr = pa.load_rules(rules_text);
  check(rerr.code == RuleLoadError::Code::none, "rules parse");
  check(pa.rules().size() == 3, "three rules loaded");

  const std::uint32_t client = pa.authority().add_client();
  const std::uint32_t pos_x = pa.field_id("player.position.x");
  const std::uint32_t vel = pa.field_id("player.velocity");
  const std::uint32_t score = pa.field_id("player.score");

  // Honest proposals pass the rules. Velocity quantizes to world units
  // (12 bits over -40..40): 2686 -> 12.49, inside the 12.5 cap; 3000 ->
  // 18.6, over it.
  check(pa.propose(client, vel, 2686).code == ProposalResult::Code::accepted, "in-cap velocity accepted");
  check(pa.propose(client, score, 5).code == ProposalResult::Code::accepted, "monotone score accepted");
  check(pa.propose(client, pos_x, 105).code == ProposalResult::Code::accepted, "small move accepted");
  check(pa.authority().tick().tick == 2, "commit tick 2 (construction commits snapshot 1)");
  check(pa.suspicion() == 0, "no suspicion from honest play");

  // Rule breakers are discarded, suspicion rises, state is unchanged.
  check(pa.propose(client, vel, 3000).code == ProposalResult::Code::discarded,
        "velocity over 12.5 discarded by rule");
  check(pa.propose(client, score, 4).code == ProposalResult::Code::discarded,
        "score regression discarded by rule");
  check(pa.propose(client, pos_x, 505).code == ProposalResult::Code::discarded,
        "jump beyond 12/tick discarded by rule");
  check(pa.suspicion() == 3, "each rule rejection raises suspicion");
  check(*pa.authority().value_of(pos_x) == 105, "discarded proposal never committed");

  // The failure is generic: no field or rule name leaves the authority.
  const auto rejected = pa.propose(client, score, 3);
  check(rejected.code == ProposalResult::Code::discarded &&
            rejected.policy == Policy::validated,
        "rejection reports only the field's policy");

  // Budget: node count and depth caps reject pathological rules at parse
  // time; the language has no loops so parse-time caps bound run cost.
  {
    std::unordered_map<std::string, std::uint32_t> ids;
    for (std::uint32_t i = 0; i < schema.fields.size(); ++i) ids.emplace(schema.fields[i].name, i + 1);
    std::vector<Rule> rules;
    RuleParser p(ids);
    // Deep chain: 13 nested adds exceeds kMaxRuleDepth 12.
    std::string deep;
    for (int i = 0; i < 13; ++i) deep += "(add 1.0 ";
    deep += "1.0";
    for (int i = 0; i < 13; ++i) deep += ")";
    check(p.parse("rule \"deep\" on player.score\nassert " + deep + "\n", rules).code ==
              RuleLoadError::Code::too_deep,
          "over-deep rule refused at parse time");
    // Wide chain: 65 nodes exceeds kMaxRuleNodes 64.
    std::string wide = "(add 1.0 1.0";
    for (int i = 0; i < 70; ++i) wide += " 1.0"; // each literal is a node
    wide += ")";
    check(p.parse("rule \"wide\" on player.score\nassert " + wide + "\n", rules).code ==
              RuleLoadError::Code::too_many_nodes,
          "over-wide rule refused at parse time");
    check(p.parse("rule \"x\" on player.nope\nassert eq(value, 1.0)\n", rules).code ==
              RuleLoadError::Code::unknown_field,
          "rule on unknown field refused");
    check(p.parse("junk\n", rules).code == RuleLoadError::Code::malformed,
          "non-rule input refused");
  }

  // div by zero is 0, not a trap: le(div(1.0, previous), 100.0) stays true
  // when previous == 0.
  {
    std::unordered_map<std::string, std::uint32_t> ids{{"player.score", 4}};
    std::vector<Rule> rules;
    check(RuleParser(ids).parse("rule \"safe_div\" on player.score\nassert le(div(1.0, previous), 100.0)\n", rules).code ==
              RuleLoadError::Code::none,
          "div rule parses");
    RuleEvaluator::Env env;
    env.previous = 0.0; // zero denominator
    env.value = 0.0;
    check(RuleEvaluator::check(rules, 4, env).ok, "div by zero evaluates to 0, rule holds");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "rule evaluator tests passed\n";
  return 0;
}
