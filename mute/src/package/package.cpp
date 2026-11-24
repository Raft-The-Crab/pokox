#include "poko/mute/package.hpp"
#include "poko/mute/state.hpp"
#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <string>
#include <utility>

namespace poko::mute {
namespace {

struct ModuleInfo {
  std::size_t input{};
  std::string name, version;
  Position name_pos{}, version_pos{};
  bool has_name{}, has_version{};
  std::vector<ImportRef> imports;
};

Position inner_position(const DeclarationResult& result) {
  if (const auto* d=std::get_if<Diagnostic>(&result)) return d->position;
  if (const auto* d=std::get_if<ParseDiagnostic>(&result)) return d->position;
  if (const auto* d=std::get_if<StatementDiagnostic>(&result)) return d->position;
  if (const auto* d=std::get_if<DeclarationDiagnostic>(&result)) return d->position;
  return {};
}

// Declared spellings keep their source quotes; strip one surrounding pair.
std::string unquote(std::string_view spelling) {
  if (spelling.size()>=2 && spelling.front()=='"' && spelling.back()=='"')
    return std::string(spelling.substr(1,spelling.size()-2));
  return std::string(spelling);
}

// pkg://<name>[@<version>]; name is nonempty and cannot contain '@'.
bool parse_import_spec(std::string_view spec, std::string& name, std::string& version) {
  constexpr std::string_view prefix="pkg://";
  if (!spec.starts_with(prefix)) return false;
  const auto rest=spec.substr(prefix.size());
  const auto at=rest.rfind('@');
  name=std::string(at==std::string_view::npos ? rest : rest.substr(0,at));
  version=at==std::string_view::npos ? std::string{} : std::string(rest.substr(at+1));
  if (name.empty() || name.find('@')!=std::string::npos) return false;
  if (at!=std::string_view::npos && version.empty()) return false;
  return true;
}

} // namespace

PackageResult resolve_packages(std::span<const PackageInput> inputs) {
  PackageResult result;
  // Bound the graph so DFS recursion and diagnostic volume stay finite.
  constexpr std::size_t max_inputs=4096;
  if (inputs.size()>max_inputs) {
    result.diagnostics.push_back({PackageErrorCode::input_limit,{},std::to_string(inputs.size())});
    return result;
  }
  std::vector<ModuleInfo> modules;
  modules.reserve(inputs.size());

  for (std::size_t i=0;i<inputs.size();++i) {
    const auto& input=inputs[i];
    auto parsed=parse_declarations(input.source);
    const auto* ast=std::get_if<DeclarationAst>(&parsed);
    if (!ast) {
      result.diagnostics.push_back({PackageErrorCode::parse_failed,inner_position(parsed),input.name});
      continue;
    }
    ModuleInfo info; info.input=i;
    const auto nodes=ast->nodes();
    const auto root=ast->root();
    if (root<nodes.size()) {
      for (const auto child:nodes[root].children) {
        if (child>=nodes.size()) continue;
        const auto& node=nodes[child];
        if (node.kind==DeclarationKind::package && !info.has_name) {
          info.has_name=true; info.name=unquote(node.spelling); info.name_pos=node.begin;
        } else if (node.kind==DeclarationKind::version && !info.has_version) {
          info.has_version=true; info.version=unquote(node.spelling); info.version_pos=node.begin;
        } else if (node.kind==DeclarationKind::import) {
          ImportRef ref; ref.position=node.begin;
          const auto spec=unquote(node.spelling);
          if (!parse_import_spec(spec,ref.name,ref.version)) {
            result.diagnostics.push_back({PackageErrorCode::invalid_import_spec,node.begin,input.name});
            continue;
          }
          if (!node.children.empty() && node.children[0]<nodes.size())
            ref.alias=nodes[node.children[0]].spelling;
          info.imports.push_back(std::move(ref));
        }
      }
    }
    if (!info.has_name)
      result.diagnostics.push_back({PackageErrorCode::missing_package_decl,{},input.name});
    if (!info.has_version)
      result.diagnostics.push_back({PackageErrorCode::missing_version_decl,{},input.name});
    if (info.has_name && info.name!=input.name)
      result.diagnostics.push_back({PackageErrorCode::identity_mismatch,info.name_pos,input.name});
    if (info.has_version && info.version!=input.version)
      result.diagnostics.push_back({PackageErrorCode::identity_mismatch,info.version_pos,input.version});
    modules.push_back(std::move(info));
  }

  // Index available versions per name; duplicates of name+version rejected.
  std::map<std::string,std::set<std::string>> available;
  std::map<std::pair<std::string,std::string>,std::size_t> by_identity;
  for (std::size_t i=0;i<modules.size();++i) {
    const auto& m=modules[i];
    if (!m.has_name || !m.has_version) continue;
    const auto key=std::pair{m.name,m.version};
    if (!by_identity.emplace(key,i).second)
      result.diagnostics.push_back({PackageErrorCode::duplicate_package,m.name_pos,m.name+"@"+m.version});
    available[m.name].insert(m.version);
  }

  // Deterministic resolution order: name, then version.
  std::vector<std::size_t> order(modules.size());
  for (std::size_t i=0;i<order.size();++i) order[i]=i;
  std::sort(order.begin(),order.end(),[&](std::size_t a,std::size_t b){
    const auto& x=modules[a]; const auto& y=modules[b];
    return x.name!=y.name ? x.name<y.name : x.version<y.version;
  });

  // One version per name per build; unpinned imports adopt the already-bound
  // version when present, otherwise the single available version.
  std::map<std::string,std::string> bound;
  struct Edge { std::size_t from, to; const ImportRef* ref; };
  std::vector<Edge> edges;
  for (const auto idx:order) {
    const auto& m=modules[idx];
    if (!m.has_name || !m.has_version) continue;
    for (const auto& ref:m.imports) {
      const auto versions=available.find(ref.name);
      if (versions==available.end() || versions->second.empty()) {
        result.diagnostics.push_back({PackageErrorCode::missing_dependency,ref.position,ref.name});
        continue;
      }
      std::string resolved;
      if (!ref.version.empty()) {
        if (!versions->second.count(ref.version)) {
          result.diagnostics.push_back({PackageErrorCode::version_conflict,ref.position,
                                        ref.name+"@"+ref.version});
          continue;
        }
        resolved=ref.version;
      } else if (const auto it=bound.find(ref.name); it!=bound.end()) {
        resolved=it->second;
      } else if (versions->second.size()==1) {
        resolved=*versions->second.begin();
      } else {
        result.diagnostics.push_back({PackageErrorCode::ambiguous_version,ref.position,ref.name});
        continue;
      }
      if (const auto it=bound.find(ref.name); it!=bound.end() && it->second!=resolved) {
        result.diagnostics.push_back({PackageErrorCode::version_conflict,ref.position,
                                      ref.name+"@"+resolved});
        continue;
      }
      bound.emplace(ref.name,resolved);
      const auto dep=by_identity.find({ref.name,resolved});
      if (dep!=by_identity.end()) edges.push_back({idx,dep->second,&ref});
    }
  }

  // Cycle detection over resolved edges, deterministic DFS in sorted order.
  std::map<std::size_t,int> color; // 0 unvisited, 1 in stack, 2 done
  std::set<std::size_t> reported;
  auto visit=[&](auto&& self,std::size_t node)->void {
    color[node]=1;
    std::vector<const Edge*> out;
    for (const auto& e:edges) if (e.from==node) out.push_back(&e);
    std::sort(out.begin(),out.end(),[&](const Edge* a,const Edge* b){
      return modules[a->to].name!=modules[b->to].name ? modules[a->to].name<modules[b->to].name
                                                     : modules[a->to].version<modules[b->to].version;
    });
    for (const auto* e:out) {
      if (color[e->to]==1) {
        // Report the back edge once per target.
        if (reported.insert(e->to).second)
          result.diagnostics.push_back({PackageErrorCode::cyclic_import,e->ref->position,
                                        modules[e->to].name+"@"+modules[e->to].version});
      } else if (color[e->to]==0) {
        self(self,e->to);
      }
    }
    color[node]=2;
  };
  for (const auto idx:order) if (color[idx]==0 && modules[idx].has_name && modules[idx].has_version)
    visit(visit,idx);

  // Emit resolved packages in deterministic order with content hashes.
  std::vector<std::size_t> resolved;
  for (std::size_t i=0;i<modules.size();++i)
    if (modules[i].has_name && modules[i].has_version) resolved.push_back(i);
  std::sort(resolved.begin(),resolved.end(),[&](std::size_t a,std::size_t b){
    const auto& x=modules[a]; const auto& y=modules[b];
    return x.name!=y.name ? x.name<y.name : x.version<y.version;
  });
  for (const auto idx:resolved) {
    const auto& m=modules[idx];
    const auto& input=inputs[m.input];
    ResolvedPackage pkg;
    pkg.name=m.name; pkg.version=m.version;
    pkg.source_hash=xxhash64(
      std::span(reinterpret_cast<const std::uint8_t*>(input.source.data()),input.source.size()),0);
    for (const auto& ref:m.imports) {
      const auto spec_name=ref.name;
      const auto versions=available.find(spec_name);
      std::string bound_version;
      if (versions!=available.end()) {
        if (!ref.version.empty() && versions->second.count(ref.version)) bound_version=ref.version;
        else if (const auto it=bound.find(spec_name); it!=bound.end()) bound_version=it->second;
        else if (versions->second.size()==1) bound_version=*versions->second.begin();
      }
      pkg.imports.push_back({spec_name,bound_version,ref.alias,ref.position});
    }
    result.packages.push_back(std::move(pkg));
  }
  return result;
}

std::string dump_lockfile(const PackageResult& result) {
  constexpr char hex[]="0123456789abcdef";
  std::string out="# mute.lock v1\n";
  for (const auto& pkg:result.packages) {
    out+=pkg.name; out+='@'; out+=pkg.version; out+=' ';
    for (int shift=60;shift>=0;shift-=4) out+=hex[(pkg.source_hash>>shift)&0xF];
    out+='\n';
  }
  return out;
}

std::string_view name(PackageErrorCode code) {
  constexpr auto names=std::to_array<std::string_view>({
    "parse_failed","missing_package_decl","missing_version_decl",
    "identity_mismatch","duplicate_package","invalid_import_spec",
    "missing_dependency","version_conflict","ambiguous_version","cyclic_import","input_limit"});
  return names.at(static_cast<std::size_t>(code));
}
} // namespace poko::mute
