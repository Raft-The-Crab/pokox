#include "poko/mute/package.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;

void expect_ok(std::vector<PackageInput> inputs,std::size_t package_count) {
  const auto result=resolve_packages(inputs);
  if (!result.ok()) {
    std::cerr << "unexpected diagnostic " << name(result.diagnostics.front().code)
              << " detail=" << result.diagnostics.front().detail << '\n';
    ++failures; return;
  }
  if (result.packages.size()!=package_count) {
    std::cerr << "expected " << package_count << " packages, got " << result.packages.size() << '\n';
    ++failures;
  }
}
void expect_error(PackageErrorCode code,std::vector<PackageInput> inputs) {
  const auto result=resolve_packages(inputs);
  const auto found=std::find_if(result.diagnostics.begin(),result.diagnostics.end(),
    [&](const PackageDiagnostic& d){ return d.code==code; });
  if (found==result.diagnostics.end()) {
    std::cerr << "missing " << name(code) << " (got:";
    for (const auto& d:result.diagnostics) std::cerr << ' ' << name(d.code) << ':' << d.detail;
    std::cerr << ")\n"; ++failures;
  }
}

void cases() {
  // Single module, no imports.
  expect_ok({{"app","V1?","package \"app\" version \"V1?\"\n"}},1);

  // Pinned import resolves; lockfile pins word and content hash.
  {
    const std::string_view dep_src="package \"poko/ui\" version \"WobblyMango\"\nfn noop() -> i32 { return 0; }";
    const std::vector<PackageInput> inputs{
      {"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/ui@WobblyMango\" as ui\n"},
      {"poko/ui","WobblyMango",dep_src}};
    auto result=resolve_packages(inputs);
    if (!result.ok() || result.packages.size()!=2) { std::cerr << "pinned import failed\n"; ++failures; }
    else {
      if (result.packages[0].name!="app" || result.packages[1].name!="poko/ui") {
        std::cerr << "package order not deterministic\n"; ++failures;
      }
      const auto lock=dump_lockfile(result);
      const auto app_pos=lock.find("app@V1? ");
      const auto ui_pos=lock.find("poko/ui@WobblyMango ");
      if (lock.rfind("# mute.lock v1\n",0)!=0 || app_pos==std::string::npos ||
          ui_pos==std::string::npos || app_pos>ui_pos ||
          lock.back()!='\n' || lock.find("\r")!=std::string::npos) {
        std::cerr << "bad lockfile:\n" << lock; ++failures;
      }
      if (result.packages[1].source_hash==0) { std::cerr << "zero source hash\n"; ++failures; }
      const auto& imports=result.packages[0].imports;
      if (imports.size()!=1 || imports[0].name!="poko/ui" ||
          imports[0].version!="WobblyMango" || imports[0].alias!="ui") {
        std::cerr << "resolved import mismatch\n"; ++failures;
      }
    }
  }

  // Unpinned import binds the single available version.
  expect_ok({{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/ui\" as ui\n"},
             {"poko/ui","WobblyMango","package \"poko/ui\" version \"WobblyMango\"\n"}},2);

  // Missing dependency.
  expect_error(PackageErrorCode::missing_dependency,
    {{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/missing@X\" as m\n"}});

  // Pinned version absent but name exists -> conflict.
  expect_error(PackageErrorCode::version_conflict,
    {{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/ui@Other\" as ui\n"},
     {"poko/ui","WobblyMango","package \"poko/ui\" version \"WobblyMango\"\n"}});

  // Two versions of one name -> unpinned import is ambiguous.
  expect_error(PackageErrorCode::ambiguous_version,
    {{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/ui\" as ui\n"},
     {"poko/ui","WobblyMango","package \"poko/ui\" version \"WobblyMango\"\n"},
     {"poko/ui","SecretV1?","package \"poko/ui\" version \"SecretV1?\"\n"}});

  // Diamond requiring two different versions of one name -> conflict.
  expect_error(PackageErrorCode::version_conflict,
    {{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://a@A1\" as a\nimport \"pkg://b@B1\" as b\n"},
     {"a","A1","package \"a\" version \"A1\"\nimport \"pkg://shared@S1\" as s\n"},
     {"b","B1","package \"b\" version \"B1\"\nimport \"pkg://shared@S2\" as s\n"},
     {"shared","S1","package \"shared\" version \"S1\"\n"},
     {"shared","S2","package \"shared\" version \"S2\"\n"}});

  // Cycle: a -> b -> a.
  expect_error(PackageErrorCode::cyclic_import,
    {{"a","A1","package \"a\" version \"A1\"\nimport \"pkg://b@B1\" as b\n"},
     {"b","B1","package \"b\" version \"B1\"\nimport \"pkg://a@A1\" as a\n"}});

  // Self import is a cycle.
  expect_error(PackageErrorCode::cyclic_import,
    {{"a","A1","package \"a\" version \"A1\"\nimport \"pkg://a@A1\" as self\n"}});

  // Duplicate package identity.
  expect_error(PackageErrorCode::duplicate_package,
    {{"a","A1","package \"a\" version \"A1\"\n"},
     {"a","A1","package \"a\" version \"A1\"\n"}});

  // Declared identity must match the claimed input identity.
  expect_error(PackageErrorCode::identity_mismatch,
    {{"a","A1","package \"a\" version \"A2\"\n"}});

  // Missing declarations.
  expect_error(PackageErrorCode::missing_package_decl,
    {{"a","A1","version \"A1\"\n"}});
  expect_error(PackageErrorCode::missing_version_decl,
    {{"a","A1","package \"a\"\n"}});

  // Malformed import spec and parse failure.
  expect_error(PackageErrorCode::invalid_import_spec,
    {{"a","A1","package \"a\" version \"A1\"\nimport \"https://x\" as x\n"}});
  expect_error(PackageErrorCode::parse_failed,
    {{"a","A1","package \"a\" version \"A1\"\nfn broken( {\n"}});

  // Lockfile is byte-identical across input order.
  {
    const PackageInput x{"app","V1?","package \"app\" version \"V1?\"\nimport \"pkg://poko/ui@WobblyMango\" as ui\n"};
    const PackageInput y{"poko/ui","WobblyMango","package \"poko/ui\" version \"WobblyMango\"\n"};
    const std::vector<PackageInput> xy{x,y}, yx{y,x};
    const auto a=dump_lockfile(resolve_packages(xy));
    const auto b=dump_lockfile(resolve_packages(yx));
    if (a!=b) { std::cerr << "lockfile differs by input order\n" << a << b; ++failures; }
    if (!resolve_packages(xy).ok()) { std::cerr << "reordered inputs failed\n"; ++failures; }
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " package test(s) failed\n"; return 1; }
  std::cout << "package tests passed\n";
  return 0;
}
