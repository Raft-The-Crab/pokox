#pragma once
#include "poko/mute/program.hpp"
namespace poko::mute {
// Non-authoritative schema preview only, NOT a .pkB and never valid for publication.
// Does not assign IDs, policies, rules, capabilities, signing keys or signatures.
// Its CBOR data is versioned independently of the future production format.
[[nodiscard]] ProgramBytecodeResult make_pkb_schema_draft(std::string_view source);
}
