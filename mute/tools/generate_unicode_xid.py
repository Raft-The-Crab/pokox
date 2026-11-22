#!/usr/bin/env python3
"""Generate the pinned Unicode XID tables; no network access required."""
import hashlib
import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
SOURCE = ROOT / 'data/unicode/DerivedCoreProperties-15.1.0.txt'
SHA256 = 'f55d0db69123431a7317868725b1fcbf1eab6b265d756d1bd7f0f6d9f9ee108b'
raw = SOURCE.read_bytes()
if hashlib.sha256(raw).hexdigest() != SHA256:
    sys.exit('Unicode input hash does not match pinned Unicode 15.1 data')
properties = {'XID_Start': [], 'XID_Continue': []}
for rawline in raw.decode('utf-8').splitlines():
    line = rawline.split('#', 1)[0].strip()
    if not line:
        continue
    interval, prop = (part.strip() for part in line.split(';', 1))
    if prop not in properties:
        continue
    endpoints = interval.split('..')
    first, last = int(endpoints[0], 16), int(endpoints[-1], 16)
    ranges = properties[prop]
    if ranges and first <= ranges[-1][1] + 1:
        ranges[-1] = (ranges[-1][0], max(last, ranges[-1][1]))
    else:
        ranges.append((first, last))
lines = ['// Generated from Unicode 15.1 DerivedCoreProperties; see mute/data/unicode.',
         '#pragma once', '#include <array>', '#include <cstdint>',
         'namespace poko::mute::detail {',
         'struct Range { char32_t first; char32_t last; };']
for prop, ranges in properties.items():
    lines.append(f'inline constexpr std::array<Range, {len(ranges)}> {prop}{{{{')
    lines.extend(f'  {{0x{a:X}, 0x{b:X}}},' for a, b in ranges)
    lines.append('}};')
lines.extend(['template <std::size_t N>',
              'constexpr bool contains(const std::array<Range, N>& ranges, char32_t c) {',
              '  std::size_t low = 0, high = N;',
              '  while (low < high) {',
              '    const auto mid = low + (high - low) / 2;',
              '    if (ranges[mid].last < c) low = mid + 1; else high = mid;',
              '  }',
              '  return low < N && ranges[low].first <= c;',
              '}', '} // namespace poko::mute::detail', ''])
text = '\n'.join(lines)
if len(sys.argv) == 2 and sys.argv[1] == '--check':
    if (ROOT / 'src/lexer/unicode_xid.hpp').read_text(encoding='utf-8') != text:
        sys.exit('Generated Unicode XID tables are stale')
elif len(sys.argv) == 1:
    with (ROOT / 'src/lexer/unicode_xid.hpp').open('w', encoding='utf-8', newline='\n') as output:
        output.write(text)
else:
    sys.exit('usage: generate_unicode_xid.py [--check]')
