# MUT-02 arithmetic parser contract

`poko_mute_parser` builds by default as a C++20 static library and links the MUT-01 lexer. Include `poko/mute/parser.hpp` and call `parse_arithmetic(source)`. This first parser handles **one complete expression**, not a file or statement sequence:

```text
expression = term (("+" | "-") term)*
term       = prefix (("*" | "/" | "%") prefix)*
prefix     = ("+" | "-") prefix | primary
primary    = integer | floating | identifier | "(" expression ")"
```

Unary operators bind tighter than multiplication/division/remainder, which bind tighter than addition/subtraction. Binary operators associate left. The lexer determines token spellings, numeric forms, UTF-8 validation and comment handling; doc-comment tokens are not expressions. Other operators, calls, assignments, comparison, logical operators, declarations, strings and statements are intentionally outside MUT-02. No evaluation, type inference, numeric conversion, overflow checking or division-by-zero checking is performed. For example, `1/0` is a syntactically valid AST; runtime behavior is future evaluator work.

The result is a `std::variant<Ast, Diagnostic, ParseDiagnostic>`: lexing errors are propagated intact, while syntax errors carry a distinct error code and source position. The parser requires the entire input to be consumed; the first syntax error is returned without recovery. The lexer first rejects oversized input using its configurable byte cap; within that limit whole-input UTF-8 validation takes precedence over parsing errors. `parse_arithmetic(source, LexOptions{limit})` forwards a custom limit. Positions are original byte offsets plus 1-based scalar line/column, as in the lexer contract.

## AST and dump

`Ast` owns every literal/identifier spelling and all nodes, so the original input can be destroyed after parsing. `nodes()` returns a borrowed, read-only span, invalidated when its owning AST is destroyed or moved. Child indices point to earlier entries; `root()` identifies the result. `left` is the operand of a unary expression or the left side of a binary expression, and `right` is present only for binary expressions. `no_node` marks absent children. Grouping parentheses do not create nodes: they extend the grouped node's full expression span, while the node's token span still identifies its original literal, identifier or operator. End offsets are exclusive. Copying an AST copies its storage; moving it leaves the source with `root() == no_node`. Dumping a moved-from AST throws `std::invalid_argument`.

`dump_ast` emits deterministic ASCII S-expressions followed by one LF, for example:

```text
(binary + (integer "1") (binary * (integer "2") (integer "3")))
```

Literal and identifier spellings are quoted, with non-ASCII bytes, double quotes, backslashes and non-printable bytes represented by lowercase `\xhh`. Parsing, AST storage and dumping use iterative stacks rather than C++ recursion. They allocate proportionally to the input/AST. The configurable lexer source-byte limit applies before parsing, but there is no total memory quota, so callers handling untrusted source must impose appropriate limits. Allocation failures propagate as standard exceptions.
