#include "poko/resource/gltf_import.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <utility>

namespace poko::resource {
namespace {

constexpr std::uint32_t kGlbMagic = 0x46546C67u;   // "glTF"
constexpr std::uint32_t kChunkJson = 0x4E4F534Au;  // "JSON"
constexpr std::uint32_t kChunkBin = 0x004E4942u;   // "BIN\0"
constexpr std::size_t kMaxFileBytes = 64ull * 1024 * 1024;
constexpr std::uint32_t kMaxVertices = 4u * 1024 * 1024;
constexpr std::uint32_t kMaxIndices = 16u * 1024 * 1024;
constexpr int kMaxJsonDepth = 24;

constexpr std::uint32_t kCompU8 = 5121;
constexpr std::uint32_t kCompU16 = 5123;
constexpr std::uint32_t kCompU32 = 5125;
constexpr std::uint32_t kCompF32 = 5126;

std::unique_ptr<PokoMesh> fail(std::string* error, const char* message) {
  if (error) *error = message;
  return nullptr;
}

std::uint32_t read_u32(const std::uint8_t* p) {
  std::uint32_t v;
  std::memcpy(&v, p, sizeof(v));
  return v;
}

float read_f32(const std::uint8_t* p) {
  float v;
  std::memcpy(&v, p, sizeof(v));
  return v;
}

// ---------------------------------------------------------------------------
// Minimal JSON reader (objects keep member order, so imports are stable).
// ---------------------------------------------------------------------------
struct Json {
  enum class Type { Null, Bool, Number, String, Array, Object };

  Type type = Type::Null;
  bool boolean = false;
  double number = 0.0;
  std::string text;
  std::vector<Json> items;
  std::vector<std::pair<std::string, Json>> members;

  const Json* get(const char* key) const {
    if (type != Type::Object) return nullptr;
    for (const auto& m : members)
      if (m.first == key) return &m.second;
    return nullptr;
  }
};

class JsonParser {
 public:
  JsonParser(const char* data, std::size_t size) : p_(data), end_(data + size) {}

  bool parse(Json* out, std::string* error) {
    if (!parse_value(out, 0)) {
      if (error) *error = message_;
      return false;
    }
    skip_ws();
    if (p_ != end_) {
      if (error) *error = "trailing bytes after JSON value";
      return false;
    }
    return true;
  }

 private:
  bool reject(const char* message) {
    if (message_.empty()) message_ = message;
    return false;
  }

  void skip_ws() {
    while (p_ != end_ && (*p_ == ' ' || *p_ == '\t' || *p_ == '\n' || *p_ == '\r')) ++p_;
  }

  bool consume(const char* literal) {
    std::size_t n = std::strlen(literal);
    if (static_cast<std::size_t>(end_ - p_) < n) return false;
    if (std::memcmp(p_, literal, n) != 0) return false;
    p_ += n;
    return true;
  }

  bool parse_value(Json* out, int depth) {
    if (depth > kMaxJsonDepth) return reject("JSON nesting too deep");
    skip_ws();
    if (p_ == end_) return reject("unexpected end of JSON");
    switch (*p_) {
      case '{': return parse_object(out, depth);
      case '[': return parse_array(out, depth);
      case '"':
        out->type = Json::Type::String;
        return parse_string(&out->text);
      case 't':
        if (!consume("true")) return reject("bad JSON literal");
        out->type = Json::Type::Bool;
        out->boolean = true;
        return true;
      case 'f':
        if (!consume("false")) return reject("bad JSON literal");
        out->type = Json::Type::Bool;
        out->boolean = false;
        return true;
      case 'n':
        if (!consume("null")) return reject("bad JSON literal");
        out->type = Json::Type::Null;
        return true;
      default:
        out->type = Json::Type::Number;
        return parse_number(&out->number);
    }
  }

  bool parse_object(Json* out, int depth) {
    out->type = Json::Type::Object;
    ++p_;  // '{'
    skip_ws();
    if (p_ != end_ && *p_ == '}') {
      ++p_;
      return true;
    }
    for (;;) {
      skip_ws();
      if (p_ == end_ || *p_ != '"') return reject("object key must be a string");
      std::string key;
      if (!parse_string(&key)) return false;
      skip_ws();
      if (p_ == end_ || *p_ != ':') return reject("expected ':' after object key");
      ++p_;
      Json value;
      if (!parse_value(&value, depth + 1)) return false;
      out->members.emplace_back(std::move(key), std::move(value));
      skip_ws();
      if (p_ == end_) return reject("unterminated object");
      if (*p_ == ',') {
        ++p_;
        continue;
      }
      if (*p_ == '}') {
        ++p_;
        return true;
      }
      return reject("expected ',' or '}' in object");
    }
  }

  bool parse_array(Json* out, int depth) {
    out->type = Json::Type::Array;
    ++p_;  // '['
    skip_ws();
    if (p_ != end_ && *p_ == ']') {
      ++p_;
      return true;
    }
    for (;;) {
      Json value;
      if (!parse_value(&value, depth + 1)) return false;
      out->items.push_back(std::move(value));
      skip_ws();
      if (p_ == end_) return reject("unterminated array");
      if (*p_ == ',') {
        ++p_;
        continue;
      }
      if (*p_ == ']') {
        ++p_;
        return true;
      }
      return reject("expected ',' or ']' in array");
    }
  }

  bool parse_string(std::string* out) {
    out->clear();
    if (p_ == end_ || *p_ != '"') return reject("expected string");
    ++p_;
    while (p_ != end_) {
      unsigned char c = static_cast<unsigned char>(*p_);
      if (c == '"') {
        ++p_;
        return true;
      }
      if (c < 0x20) return reject("control byte in JSON string");
      if (c != '\\') {
        out->push_back(static_cast<char>(c));
        ++p_;
        continue;
      }
      ++p_;
      if (p_ == end_) return reject("truncated escape in JSON string");
      char esc = *p_++;
      switch (esc) {
        case '"': out->push_back('"'); break;
        case '\\': out->push_back('\\'); break;
        case '/': out->push_back('/'); break;
        case 'b': out->push_back('\b'); break;
        case 'f': out->push_back('\f'); break;
        case 'n': out->push_back('\n'); break;
        case 'r': out->push_back('\r'); break;
        case 't': out->push_back('\t'); break;
        case 'u': {
          if (!append_utf8(out)) return reject("bad \\u escape in JSON string");
          break;
        }
        default: return reject("unknown escape in JSON string");
      }
    }
    return reject("unterminated JSON string");
  }

  bool read_hex4(std::uint32_t* out) {
    if (end_ - p_ < 4) return false;
    std::uint32_t value = 0;
    for (int i = 0; i < 4; ++i) {
      char c = *p_++;
      std::uint32_t digit;
      if (c >= '0' && c <= '9') digit = static_cast<std::uint32_t>(c - '0');
      else if (c >= 'a' && c <= 'f') digit = static_cast<std::uint32_t>(c - 'a' + 10);
      else if (c >= 'A' && c <= 'F') digit = static_cast<std::uint32_t>(c - 'A' + 10);
      else return false;
      value = (value << 4) | digit;
    }
    *out = value;
    return true;
  }

  static void append_code_point(std::string* out, std::uint32_t cp) {
    if (cp < 0x80) {
      out->push_back(static_cast<char>(cp));
    } else if (cp < 0x800) {
      out->push_back(static_cast<char>(0xC0 | (cp >> 6)));
      out->push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else if (cp < 0x10000) {
      out->push_back(static_cast<char>(0xE0 | (cp >> 12)));
      out->push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
      out->push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else {
      out->push_back(static_cast<char>(0xF0 | (cp >> 18)));
      out->push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
      out->push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
      out->push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
  }

  bool append_utf8(std::string* out) {
    std::uint32_t cp = 0;
    if (!read_hex4(&cp)) return false;
    if (cp >= 0xD800 && cp <= 0xDBFF) {
      if (end_ - p_ < 6 || p_[0] != '\\' || p_[1] != 'u') return false;
      p_ += 2;
      std::uint32_t low = 0;
      if (!read_hex4(&low) || low < 0xDC00 || low > 0xDFFF) return false;
      cp = 0x10000 + ((cp - 0xD800) << 10) + (low - 0xDC00);
    } else if (cp >= 0xDC00 && cp <= 0xDFFF) {
      return false;  // lone low surrogate
    }
    append_code_point(out, cp);
    return true;
  }

  bool parse_number(double* out) {
    const char* start = p_;
    if (p_ != end_ && (*p_ == '-' || *p_ == '+')) ++p_;
    bool any = false;
    while (p_ != end_ && ((*p_ >= '0' && *p_ <= '9') || *p_ == '.' || *p_ == 'e' || *p_ == 'E' ||
                          *p_ == '+' || *p_ == '-')) {
      ++p_;
      any = true;
    }
    if (!any) return reject("bad JSON number");
    std::string token(start, p_);
    char* parser_end = nullptr;
    const double value = std::strtod(token.c_str(), &parser_end);
    if (!parser_end || *parser_end != '\0') return reject("bad JSON number");
    if (!std::isfinite(value)) return reject("non-finite JSON number");
    *out = value;
    return true;
  }

  const char* p_;
  const char* end_;
  std::string message_;
};

// ---------------------------------------------------------------------------
// glTF helpers
// ---------------------------------------------------------------------------
bool as_index(const Json* value, std::uint32_t* out) {
  if (!value || value->type != Json::Type::Number) return false;
  const double d = value->number;
  if (d < 0.0 || d > static_cast<double>(std::numeric_limits<std::uint32_t>::max())) return false;
  if (std::floor(d) != d) return false;
  *out = static_cast<std::uint32_t>(d);
  return true;
}

bool as_size(const Json* value, std::size_t* out) {
  std::uint32_t v = 0;
  if (!as_index(value, &v)) return false;
  *out = v;
  return true;
}

const Json* array_at(const Json* array, std::size_t index) {
  if (!array || array->type != Json::Type::Array || index >= array->items.size()) return nullptr;
  return &array->items[index];
}

struct BufferView {
  std::size_t offset = 0;
  std::size_t length = 0;
  std::size_t stride = 0;  // 0 = tightly packed
};

struct BinData {
  const std::uint8_t* data = nullptr;
  std::size_t size = 0;
};

// `root.bufferViews[i]` resolved against buffer 0 (the GLB BIN chunk).
bool resolve_buffer_view(const Json& root, const BinData& bin, std::uint32_t index, BufferView* out,
                         std::string* error) {
  const Json* views = root.get("bufferViews");
  const Json* view = array_at(views, index);
  if (!view || view->type != Json::Type::Object) {
    if (error) *error = "bufferView index out of range";
    return false;
  }
  std::uint32_t buffer = 0;
  const Json* buffer_value = view->get("buffer");
  if (!as_index(buffer_value, &buffer) || buffer != 0) {
    if (error) *error = "only buffer 0 (the GLB BIN chunk) is supported";
    return false;
  }
  std::size_t offset = 0;
  if (view->get("byteOffset") && !as_size(view->get("byteOffset"), &offset)) {
    if (error) *error = "bufferView byteOffset is not a non-negative integer";
    return false;
  }
  std::size_t length = 0;
  if (!as_size(view->get("byteLength"), &length) || length == 0) {
    if (error) *error = "bufferView byteLength is missing or zero";
    return false;
  }
  std::size_t stride = 0;
  if (view->get("byteStride") && !as_size(view->get("byteStride"), &stride)) {
    if (error) *error = "bufferView byteStride is not a non-negative integer";
    return false;
  }
  if (offset > bin.size || length > bin.size - offset) {
    if (error) *error = "bufferView exceeds the BIN chunk";
    return false;
  }
  out->offset = offset;
  out->length = length;
  out->stride = stride;
  return true;
}

struct Accessor {
  std::uint32_t count = 0;
  std::uint32_t component_type = 0;
  std::string type;
  BufferView view{};
  std::size_t element_size = 0;   // bytes per element without padding
  std::size_t component_size = 0; // bytes per component
  std::size_t component_count = 0;
  std::size_t base_offset = 0;    // accessor byteOffset inside the view
};

bool resolve_accessor(const Json& root, const BinData& bin, std::uint32_t index, Accessor* out,
                      std::string* error) {
  const Json* accessor = array_at(root.get("accessors"), index);
  if (!accessor || accessor->type != Json::Type::Object) {
    if (error) *error = "accessor index out of range";
    return false;
  }
  if (!as_index(accessor->get("count"), &out->count) || out->count == 0) {
    if (error) *error = "accessor count is missing or zero";
    return false;
  }
  const Json* type = accessor->get("type");
  if (!type || type->type != Json::Type::String) {
    if (error) *error = "accessor type is missing";
    return false;
  }
  out->type = type->text;
  if (!as_index(accessor->get("componentType"), &out->component_type)) {
    if (error) *error = "accessor componentType is missing";
    return false;
  }
  switch (out->component_type) {
    case kCompU8: out->component_size = 1; break;
    case kCompU16: out->component_size = 2; break;
    case kCompU32: out->component_size = 4; break;
    case kCompF32: out->component_size = 4; break;
    default:
      if (error) *error = "unsupported accessor componentType";
      return false;
  }
  if (out->type == "VEC3") out->component_count = 3;
  else if (out->type == "SCALAR") out->component_count = 1;
  else {
    if (error) *error = "only VEC3 and SCALAR accessors are supported";
    return false;
  }
  out->element_size = out->component_size * out->component_count;

  std::uint32_t view_index = 0;
  if (!as_index(accessor->get("bufferView"), &view_index)) {
    if (error) *error = "sparse/absent bufferView accessors are not supported";
    return false;
  }
  if (!resolve_buffer_view(root, bin, view_index, &out->view, error)) return false;

  std::size_t offset = 0;
  if (accessor->get("byteOffset") && !as_size(accessor->get("byteOffset"), &offset)) {
    if (error) *error = "accessor byteOffset is not a non-negative integer";
    return false;
  }
  const std::size_t stride = out->view.stride == 0 ? out->element_size : out->view.stride;
  if (stride < out->element_size) {
    if (error) *error = "bufferView byteStride is smaller than one element";
    return false;
  }
  const std::size_t span = stride * static_cast<std::size_t>(out->count - 1) + out->element_size;
  if (offset > out->view.length || span > out->view.length - offset) {
    if (error) *error = "accessor exceeds its bufferView";
    return false;
  }
  out->base_offset = out->view.offset + offset;
  out->view.stride = stride;
  return true;
}

const std::uint8_t* element_ptr(const BinData& bin, const Accessor& accessor, std::size_t i) {
  return bin.data + accessor.base_offset + accessor.view.stride * i;
}

bool read_float3(const BinData& bin, const Accessor& accessor, std::size_t i, float* out) {
  const std::uint8_t* p = element_ptr(bin, accessor, i);
  for (int c = 0; c < 3; ++c) out[c] = read_f32(p + 4 * static_cast<std::size_t>(c));
  return std::isfinite(out[0]) && std::isfinite(out[1]) && std::isfinite(out[2]);
}

bool read_index(const BinData& bin, const Accessor& accessor, std::size_t i, std::uint32_t* out) {
  const std::uint8_t* p = element_ptr(bin, accessor, i);
  switch (accessor.component_type) {
    case kCompU8: *out = p[0]; return true;
    case kCompU16: {
      std::uint16_t v;
      std::memcpy(&v, p, sizeof(v));
      *out = v;
      return true;
    }
    case kCompU32: *out = read_u32(p); return true;
    default: return false;
  }
}

// Column-major 4x4, glTF convention.
struct Mat4 {
  float m[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

  void multiply(const Mat4& rhs) {
    float out[16] = {};
    for (int col = 0; col < 4; ++col) {
      for (int row = 0; row < 4; ++row) {
        float sum = 0.0f;
        for (int k = 0; k < 4; ++k) sum += m[k * 4 + row] * rhs.m[col * 4 + k];
        out[col * 4 + row] = sum;
      }
    }
    std::memcpy(m, out, sizeof(m));
  }

  void apply(float* p) const {
    float out[3];
    for (int row = 0; row < 3; ++row)
      out[row] = m[row] * p[0] + m[4 + row] * p[1] + m[8 + row] * p[2] + m[12 + row];
    std::memcpy(p, out, sizeof(out));
  }

  // Normal vectors ignore translation and use the inverse transpose of the
  // upper-left 3x3 (falls back to the plain 3x3 when it is singular).
  void apply_normal(float* n) const {
    const float a = m[0], b = m[4], c = m[8];
    const float d = m[1], e = m[5], f = m[9];
    const float g = m[2], h = m[6], i = m[10];
    const float det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    float out[3];
    if (std::fabs(det) > 1e-12f) {
      const float inv = 1.0f / det;
      // inverse-transpose = cofactor matrix / det
      const float t0 = (e * i - f * h) * inv;
      const float t1 = -(b * i - c * h) * inv;
      const float t2 = (b * f - c * e) * inv;
      const float t3 = -(d * i - f * g) * inv;
      const float t4 = (a * i - c * g) * inv;
      const float t5 = -(a * f - c * d) * inv;
      const float t6 = (d * h - e * g) * inv;
      const float t7 = -(a * h - b * g) * inv;
      const float t8 = (a * e - b * d) * inv;
      out[0] = t0 * n[0] + t1 * n[1] + t2 * n[2];
      out[1] = t3 * n[0] + t4 * n[1] + t5 * n[2];
      out[2] = t6 * n[0] + t7 * n[1] + t8 * n[2];
    } else {
      out[0] = a * n[0] + b * n[1] + c * n[2];
      out[1] = d * n[0] + e * n[1] + f * n[2];
      out[2] = g * n[0] + h * n[1] + i * n[2];
    }
    std::memcpy(n, out, sizeof(out));
  }
};

bool read_mat4(const Json* value, Mat4* out) {
  if (!value || value->type != Json::Type::Array || value->items.size() != 16) return false;
  for (std::size_t i = 0; i < 16; ++i) {
    const Json& item = value->items[i];
    if (item.type != Json::Type::Number) return false;
    out->m[i] = static_cast<float>(item.number);
  }
  return true;
}

bool read_vec(const Json* value, std::size_t count, float* out) {
  if (!value || value->type != Json::Type::Array || value->items.size() != count) return false;
  for (std::size_t i = 0; i < count; ++i) {
    const Json& item = value->items[i];
    if (item.type != Json::Type::Number) return false;
    out[i] = static_cast<float>(item.number);
  }
  return true;
}

// Local transform of the first node that references `mesh_index`; identity
// when no node does (a bare mesh import).
bool node_transform(const Json& root, std::uint32_t mesh_index, Mat4* out) {
  const Json* nodes = root.get("nodes");
  if (!nodes || nodes->type != Json::Type::Array) return true;
  for (const Json& node : nodes->items) {
    std::uint32_t node_mesh = 0;
    if (!as_index(node.get("mesh"), &node_mesh) || node_mesh != mesh_index) continue;
    if (node.get("matrix")) return read_mat4(node.get("matrix"), out);
    Mat4 scale, rotate, translate;
    float s[3] = {1.0f, 1.0f, 1.0f};
    if (node.get("scale") && !read_vec(node.get("scale"), 3, s)) return false;
    scale.m[0] = s[0];
    scale.m[5] = s[1];
    scale.m[10] = s[2];
    if (node.get("rotation")) {
      float q[4] = {0, 0, 0, 0};
      if (!read_vec(node.get("rotation"), 4, q)) return false;
      const float x = q[0], y = q[1], z = q[2], w = q[3];
      const float xx = x * x, yy = y * y, zz = z * z;
      const float xy = x * y, xz = x * z, yz = y * z, wx = w * x, wy = w * y, wz = w * z;
      rotate.m[0] = 1 - 2 * (yy + zz);
      rotate.m[1] = 2 * (xy + wz);
      rotate.m[2] = 2 * (xz - wy);
      rotate.m[3] = 0;
      rotate.m[4] = 2 * (xy - wz);
      rotate.m[5] = 1 - 2 * (xx + zz);
      rotate.m[6] = 2 * (yz + wx);
      rotate.m[7] = 0;
      rotate.m[8] = 2 * (xz + wy);
      rotate.m[9] = 2 * (yz - wx);
      rotate.m[10] = 1 - 2 * (xx + yy);
      rotate.m[11] = 0;
    }
    float t[3] = {0, 0, 0};
    if (node.get("translation") && !read_vec(node.get("translation"), 3, t)) return false;
    translate.m[12] = t[0];
    translate.m[13] = t[1];
    translate.m[14] = t[2];
    // T * R * S
    Mat4 composed = translate;
    composed.multiply(rotate);
    composed.multiply(scale);
    *out = composed;
    return true;
  }
  return true;
}

void normalize3(float* v) {
  const float len = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  if (!(len > 0.0f) || !std::isfinite(len)) {
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 1.0f;
    return;
  }
  v[0] /= len;
  v[1] /= len;
  v[2] /= len;
}

bool read_u32_field(const Json* object, const char* key, std::uint32_t* out) {
  if (!object) return false;
  return as_index(object->get(key), out);
}

}  // namespace

// ---------------------------------------------------------------------------
// Import
// ---------------------------------------------------------------------------
std::unique_ptr<PokoMesh> import_glb(const std::uint8_t* data, std::size_t size,
                                     std::string* error, GltfImportStats* stats,
                                     std::uint32_t mesh_index) {
  if (error) error->clear();
  if (stats) *stats = GltfImportStats{};
  if (!data || size < 20) return fail(error, "file too small for a GLB header");
  if (size > kMaxFileBytes) return fail(error, "GLB larger than 64 MiB");
  if (read_u32(data) != kGlbMagic) return fail(error, "bad magic (expected glTF)");
  if (read_u32(data + 4) != 2) return fail(error, "only GLB version 2 is supported");
  const std::uint32_t declared = read_u32(data + 8);
  if (declared != size) return fail(error, "GLB length field does not match the file size");

  const Json* json_root = nullptr;
  Json root;
  BinData bin;
  std::size_t offset = 12;
  bool saw_json = false;
  while (offset + 8 <= size) {
    const std::uint32_t chunk_length = read_u32(data + offset);
    const std::uint32_t chunk_type = read_u32(data + offset + 4);
    offset += 8;
    if (chunk_length > size - offset) return fail(error, "GLB chunk overruns the file");
    if (chunk_type == kChunkJson) {
      if (saw_json) return fail(error, "duplicate JSON chunk");
      saw_json = true;
      JsonParser parser(reinterpret_cast<const char*>(data + offset), chunk_length);
      std::string json_error;
      if (!parser.parse(&root, &json_error)) {
        if (error) *error = "bad JSON chunk: " + json_error;
        return nullptr;
      }
      json_root = &root;
    } else if (chunk_type == kChunkBin && !bin.data) {
      bin.data = data + offset;
      bin.size = chunk_length;
    }
    offset += chunk_length;
  }
  if (!json_root) return fail(error, "no JSON chunk in the GLB");
  if (json_root->type != Json::Type::Object) return fail(error, "glTF JSON root is not an object");

  const Json* asset = json_root->get("asset");
  const Json* version = asset ? asset->get("version") : nullptr;
  if (!version || version->type != Json::Type::String || version->text != "2.0")
    return fail(error, "asset.version must be \"2.0\"");

  const Json* meshes = json_root->get("meshes");
  if (!meshes || meshes->type != Json::Type::Array || meshes->items.empty())
    return fail(error, "glTF has no meshes");
  if (stats) stats->mesh_count = static_cast<std::uint32_t>(meshes->items.size());
  const Json* mesh = array_at(meshes, mesh_index);
  if (!mesh || mesh->type != Json::Type::Object) return fail(error, "mesh index out of range");

  Mat4 transform;
  if (!node_transform(*json_root, mesh_index, &transform)) return fail(error, "bad node transform");

  auto out = std::make_unique<PokoMesh>();
  const Json* primitives = mesh->get("primitives");
  if (!primitives || primitives->type != Json::Type::Array || primitives->items.empty())
    return fail(error, "mesh has no primitives");

  for (const Json& primitive : primitives->items) {
    if (primitive.type != Json::Type::Object) return fail(error, "primitive is not an object");
    std::uint32_t mode = 4;
    if (primitive.get("mode") && !read_u32_field(&primitive, "mode", &mode))
      return fail(error, "primitive mode is not an index");
    const Json* attributes = primitive.get("attributes");
    std::uint32_t position_index = 0;
    if (!attributes || !read_u32_field(attributes, "POSITION", &position_index)) {
      if (error) *error = "primitive has no POSITION attribute";
      return nullptr;
    }
    Accessor positions;
    if (!resolve_accessor(*json_root, bin, position_index, &positions, error)) return nullptr;
    if (positions.component_type != kCompF32 || positions.type != "VEC3") {
      if (error) *error = "POSITION must be a float VEC3 accessor";
      return nullptr;
    }
    if (mode != 4) {
      if (stats) ++stats->skipped_primitives;
      continue;
    }
    if (positions.count > kMaxVertices || out->vertices.size() + positions.count > kMaxVertices) {
      if (error) *error = "mesh exceeds the vertex budget";
      return nullptr;
    }

    std::uint32_t normal_index = 0;
    const Json* normal_value = attributes->get("NORMAL");
    if (normal_value && !read_u32_field(attributes, "NORMAL", &normal_index)) {
      if (error) *error = "NORMAL is not an accessor index";
      return nullptr;
    }
    const bool has_normals = normal_value != nullptr;
    Accessor normals;
    if (has_normals) {
      if (!resolve_accessor(*json_root, bin, normal_index, &normals, error)) return nullptr;
      if (normals.component_type != kCompF32 || normals.type != "VEC3" ||
          normals.count != positions.count) {
        if (error) *error = "NORMAL must be a float VEC3 accessor with the POSITION count";
        return nullptr;
      }
    }

    const std::uint32_t base = static_cast<std::uint32_t>(out->vertices.size());
    std::vector<std::uint32_t> local_indices;
    std::uint32_t index_count = 0;
    const Json* indices_value = primitive.get("indices");
    if (indices_value) {
      std::uint32_t index_accessor = 0;
      if (!as_index(indices_value, &index_accessor)) {
        if (error) *error = "primitive indices is not an accessor index";
        return nullptr;
      }
      Accessor indices;
      if (!resolve_accessor(*json_root, bin, index_accessor, &indices, error)) return nullptr;
      if (indices.type != "SCALAR" || indices.component_type == kCompF32) {
        if (error) *error = "indices must be an integer SCALAR accessor";
        return nullptr;
      }
      index_count = indices.count;
      local_indices.resize(index_count);
      for (std::uint32_t i = 0; i < index_count; ++i) {
        std::uint32_t value = 0;
        if (!read_index(bin, indices, i, &value) || value >= positions.count) {
          if (error) *error = "index value out of range";
          return nullptr;
        }
        local_indices[i] = value;
      }
    } else {
      index_count = positions.count;
      local_indices.resize(index_count);
      for (std::uint32_t i = 0; i < index_count; ++i) local_indices[i] = i;
    }
    if (index_count == 0 || index_count % 3 != 0) {
      if (error) *error = "triangle list index count is not a multiple of 3";
      return nullptr;
    }
    if (index_count > kMaxIndices ||
        out->indices.size() + static_cast<std::size_t>(index_count) > kMaxIndices) {
      if (error) *error = "mesh exceeds the index budget";
      return nullptr;
    }

    const std::size_t first_vertex = out->vertices.size();
    out->vertices.resize(first_vertex + positions.count);
    for (std::uint32_t i = 0; i < positions.count; ++i) {
      PokoMeshVertex vertex{};
      if (!read_float3(bin, positions, i, vertex.position)) {
        if (error) *error = "non-finite POSITION value";
        return nullptr;
      }
      transform.apply(vertex.position);
      if (has_normals) {
        if (!read_float3(bin, normals, i, vertex.normal)) {
          if (error) *error = "non-finite NORMAL value";
          return nullptr;
        }
        transform.apply_normal(vertex.normal);
      } else {
        vertex.normal[0] = 0.0f;
        vertex.normal[1] = 0.0f;
        vertex.normal[2] = 0.0f;
      }
      out->vertices[first_vertex + i] = vertex;
    }

    if (!has_normals) {
      // Area-weighted accumulation over the index list, then normalize.
      for (std::size_t t = 0; t + 2 < local_indices.size(); t += 3) {
        const PokoMeshVertex& a = out->vertices[first_vertex + local_indices[t]];
        const PokoMeshVertex& b = out->vertices[first_vertex + local_indices[t + 1]];
        const PokoMeshVertex& c = out->vertices[first_vertex + local_indices[t + 2]];
        const float u[3] = {b.position[0] - a.position[0], b.position[1] - a.position[1],
                            b.position[2] - a.position[2]};
        const float v[3] = {c.position[0] - a.position[0], c.position[1] - a.position[1],
                            c.position[2] - a.position[2]};
        const float n[3] = {u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
                            u[0] * v[1] - u[1] * v[0]};
        for (int k = 0; k < 3; ++k) {
          float* target = out->vertices[first_vertex + local_indices[t + static_cast<std::size_t>(k)]].normal;
          target[0] += n[0];
          target[1] += n[1];
          target[2] += n[2];
        }
      }
      for (std::uint32_t i = 0; i < positions.count; ++i)
        normalize3(out->vertices[first_vertex + i].normal);
    } else {
      for (std::uint32_t i = 0; i < positions.count; ++i)
        normalize3(out->vertices[first_vertex + i].normal);
    }

    out->indices.reserve(out->indices.size() + index_count);
    for (std::uint32_t value : local_indices) out->indices.push_back(base + value);

    if (stats) {
      ++stats->primitive_count;
      stats->triangle_count += index_count / 3u;
    }
  }

  if (out->vertices.empty() || out->indices.empty())
    return fail(error, "mesh has no triangle geometry");
  return out;
}

std::unique_ptr<PokoMesh> load_glb(const std::string& path, std::string* error,
                                   GltfImportStats* stats, std::uint32_t mesh_index) {
  if (error) error->clear();
  std::error_code ec;
  const auto size = std::filesystem::file_size(path, ec);
  if (ec || size > kMaxFileBytes) {
    if (error) *error = "cannot size the GLB file";
    return nullptr;
  }
  std::ifstream in(path, std::ios::binary);
  if (!in) {
    if (error) *error = "cannot open the GLB file";
    return nullptr;
  }
  std::vector<std::uint8_t> bytes(static_cast<std::size_t>(size));
  if (size > 0) in.read(reinterpret_cast<char*>(bytes.data()), static_cast<std::streamsize>(size));
  if (!in && size > 0) {
    if (error) *error = "short read on the GLB file";
    return nullptr;
  }
  return import_glb(bytes.data(), bytes.size(), error, stats, mesh_index);
}

// ---------------------------------------------------------------------------
// PMES v1 serialization + .meta sidecar
// ---------------------------------------------------------------------------
std::vector<std::uint8_t> serialize_pokomesh(const PokoMesh& mesh) {
  std::vector<std::uint8_t> out;
  out.reserve(20 + mesh.vertices.size() * 24 + mesh.indices.size() * 4);
  auto put32 = [&out](std::uint32_t v) {
    for (int i = 0; i < 4; ++i) out.push_back(static_cast<std::uint8_t>(v >> (8 * i)));
  };
  auto putf = [&out](float f) {
    std::uint32_t u;
    std::memcpy(&u, &f, sizeof(u));
    for (int i = 0; i < 4; ++i) out.push_back(static_cast<std::uint8_t>(u >> (8 * i)));
  };
  out.insert(out.end(), {'P', 'M', 'E', 'S'});
  put32(1);
  put32(static_cast<std::uint32_t>(mesh.vertices.size()));
  put32(static_cast<std::uint32_t>(mesh.indices.size()));
  put32(24);
  for (const PokoMeshVertex& vertex : mesh.vertices) {
    for (int c = 0; c < 3; ++c) putf(vertex.position[c]);
    for (int c = 0; c < 3; ++c) putf(vertex.normal[c]);
  }
  for (std::uint32_t index : mesh.indices) put32(index);
  return out;
}

std::uint64_t fnv1a64(const std::uint8_t* data, std::size_t size) {
  std::uint64_t hash = 0xcbf29ce484222325ull;
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= data[i];
    hash *= 0x100000001b3ull;
  }
  return hash;
}

namespace {

std::string json_escape(const std::string& value) {
  std::string out;
  out.reserve(value.size() + 8);
  for (char c : value) {
    const unsigned char u = static_cast<unsigned char>(c);
    if (c == '"' || c == '\\') {
      out.push_back('\\');
      out.push_back(c);
    } else if (u < 0x20) {
      char buffer[7];
      std::snprintf(buffer, sizeof(buffer), "\\u%04x", u);
      out += buffer;
    } else {
      out.push_back(c);
    }
  }
  return out;
}

}  // namespace

std::string serialize_meta(const AssetMeta& meta) {
  char hash[19];
  std::snprintf(hash, sizeof(hash), "0x%016llx", static_cast<unsigned long long>(meta.source_fnv64));
  std::string out = "{\n";
  out += "  \"importer\": \"ast-01\",\n";
  out += "  \"version\": 1,\n";
  out += "  \"source\": \"" + json_escape(meta.source_name) + "\",\n";
  out += "  \"source_bytes\": " + std::to_string(meta.source_bytes) + ",\n";
  out += "  \"source_fnv64\": \"" + std::string(hash) + "\",\n";
  out += "  \"mesh_index\": " + std::to_string(meta.mesh_index) + ",\n";
  out += "  \"vertices\": " + std::to_string(meta.vertex_count) + ",\n";
  out += "  \"indices\": " + std::to_string(meta.index_count) + ",\n";
  out += "  \"triangles\": " + std::to_string(meta.triangle_count) + "\n";
  out += "}\n";
  return out;
}

bool write_meta(const std::string& path, const AssetMeta& meta, std::string* error) {
  if (error) error->clear();
  std::ofstream out(path, std::ios::binary | std::ios::trunc);
  if (!out) {
    if (error) *error = "cannot open the meta file for writing";
    return false;
  }
  const std::string text = serialize_meta(meta);
  out.write(text.data(), static_cast<std::streamsize>(text.size()));
  out.flush();
  if (!out) {
    if (error) *error = "short write on the meta file";
    return false;
  }
  return true;
}

bool read_meta(const std::string& path, AssetMeta* meta, std::string* error) {
  if (error) error->clear();
  if (!meta) {
    if (error) *error = "no AssetMeta destination";
    return false;
  }
  std::ifstream in(path, std::ios::binary);
  if (!in) {
    if (error) *error = "cannot open the meta file";
    return false;
  }
  std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
  if (text.size() > 64 * 1024) {
    if (error) *error = "meta file is unreasonably large";
    return false;
  }
  Json root;
  JsonParser parser(text.data(), text.size());
  if (!parser.parse(&root, error)) return false;
  if (root.type != Json::Type::Object) {
    if (error) *error = "meta root is not an object";
    return false;
  }
  const Json* importer = root.get("importer");
  const Json* version = root.get("version");
  std::uint32_t version_value = 0;
  if (!importer || importer->type != Json::Type::String || importer->text != "ast-01" ||
      !as_index(version, &version_value) || version_value != 1) {
    if (error) *error = "meta is not an ast-01 v1 sidecar";
    return false;
  }
  const Json* source = root.get("source");
  if (!source || source->type != Json::Type::String) {
    if (error) *error = "meta source is missing";
    return false;
  }
  std::uint64_t source_bytes = 0;
  const Json* bytes = root.get("source_bytes");
  if (!bytes || bytes->type != Json::Type::Number || bytes->number < 0 ||
      bytes->number > 9.0e18) {
    if (error) *error = "meta source_bytes is missing";
    return false;
  }
  source_bytes = static_cast<std::uint64_t>(bytes->number);
  const Json* hash = root.get("source_fnv64");
  if (!hash || hash->type != Json::Type::String || hash->text.size() != 18 ||
      hash->text.rfind("0x", 0) != 0) {
    if (error) *error = "meta source_fnv64 is missing";
    return false;
  }
  std::uint64_t fnv = 0;
  for (std::size_t i = 2; i < hash->text.size(); ++i) {
    const char c = hash->text[i];
    std::uint64_t digit;
    if (c >= '0' && c <= '9') digit = static_cast<std::uint64_t>(c - '0');
    else if (c >= 'a' && c <= 'f') digit = static_cast<std::uint64_t>(c - 'a' + 10);
    else if (c >= 'A' && c <= 'F') digit = static_cast<std::uint64_t>(c - 'A' + 10);
    else {
      if (error) *error = "meta source_fnv64 is not hexadecimal";
      return false;
    }
    fnv = (fnv << 4) | digit;
  }
  std::uint32_t mesh_index = 0;
  std::uint32_t vertices = 0;
  std::uint32_t indices = 0;
  std::uint32_t triangles = 0;
  if (!as_index(root.get("mesh_index"), &mesh_index) || !as_index(root.get("vertices"), &vertices) ||
      !as_index(root.get("indices"), &indices) || !as_index(root.get("triangles"), &triangles)) {
    if (error) *error = "meta counts are missing or not integers";
    return false;
  }
  meta->source_name = source->text;
  meta->source_bytes = source_bytes;
  meta->source_fnv64 = fnv;
  meta->mesh_index = mesh_index;
  meta->vertex_count = vertices;
  meta->index_count = indices;
  meta->triangle_count = triangles;
  return true;
}

}  // namespace poko::resource
