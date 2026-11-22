#include "poko/mute/state.hpp"
#include <array>
#include <bit>
namespace poko::mute {
namespace {
constexpr std::uint64_t p1=11400714785074694791ULL,p2=14029467366897019727ULL,
 p3=1609587929392839161ULL,p4=9650029242287828579ULL,p5=2870177450012600261ULL;
std::uint64_t read64(std::span<const std::uint8_t> s,std::size_t i) noexcept {
 std::uint64_t v=0;for(unsigned n=0;n<8;++n)v|=static_cast<std::uint64_t>(s[i+n])<<(8*n);return v;
}
std::uint32_t read32(std::span<const std::uint8_t> s,std::size_t i) noexcept {
 std::uint32_t v=0;for(unsigned n=0;n<4;++n)v|=static_cast<std::uint32_t>(s[i+n])<<(8*n);return v;
}
std::uint64_t round(std::uint64_t v,std::uint64_t x) noexcept {v+=x*p2;v=std::rotl(v,31);return v*p1;}
std::uint64_t merge(std::uint64_t h,std::uint64_t v) noexcept {h^=round(0,v);return h*p1+p4;}
}
std::uint64_t xxhash64(std::span<const std::uint8_t> bytes,std::uint64_t seed) noexcept {
 const auto n=bytes.size();std::size_t i=0;std::uint64_t h;
 if(n>=32) {
  std::uint64_t a=seed+p1+p2,b=seed+p2,c=seed,d=seed-p1;
  do {a=round(a,read64(bytes,i));b=round(b,read64(bytes,i+8));c=round(c,read64(bytes,i+16));d=round(d,read64(bytes,i+24));i+=32;} while(i<=n-32);
  h=std::rotl(a,1)+std::rotl(b,7)+std::rotl(c,12)+std::rotl(d,18);h=merge(h,a);h=merge(h,b);h=merge(h,c);h=merge(h,d);
 } else h=seed+p5;
 h+=n;
 while(n-i>=8){h^=round(0,read64(bytes,i));h=std::rotl(h,27)*p1+p4;i+=8;}
 if(n-i>=4){h^=static_cast<std::uint64_t>(read32(bytes,i))*p1;h=std::rotl(h,23)*p2+p3;i+=4;}
 while(i<n){h^=static_cast<std::uint64_t>(bytes[i])*p5;h=std::rotl(h,11)*p1;++i;}
 h^=h>>33;h*=p2;h^=h>>29;h*=p3;h^=h>>32;return h;
}
std::variant<std::uint64_t,StateError> hash_state(const ProgramState& state) {
 if(!state.initialized)return StateError::uninitialized;
 if(state.fields.size()>max_state_fields)return StateError::invalid_state;
 std::array<std::uint8_t,max_state_fields*4> bytes{};std::size_t at=0;
 for(std::size_t i=0;i<state.fields.size();++i){
  if(state.fields[i].name.empty())return StateError::invalid_state;
  for(std::size_t j=0;j<i;++j)if(state.fields[j].name==state.fields[i].name)return StateError::invalid_state;
  const auto v=static_cast<std::uint32_t>(state.fields[i].value);
  for(unsigned j=0;j<4;++j)bytes[at++]=static_cast<std::uint8_t>(v>>(j*8));
 }
 return xxhash64(std::span(bytes).first(at));
}
} // namespace poko::mute
