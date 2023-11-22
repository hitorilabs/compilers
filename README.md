# data-structures
toy implementations of data structures in C++

```
# for google benchmark (usually turn this off)
BENCHMARK_ENABLE_TESTING=ON

# this project
BUILD_BENCHMARKS=OFF 
BUILD_TESTS=OFF 

# for lsp
CMAKE_EXPORT_COMPILE_COMMANDS=ON
```

e.g. build with benchmarks on
```
cmake -DBUILD_BENCHMARKS=ON -DBENCHMARK_ENABLE_TESTING=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build
```

# Related Topics
- **CFG (Context-Free Grammar)** - a formal system used in linguistics and computer
science to describe the syntax of languages. A CFG consists of a set of
production rules that describe how strings in the language can be generated.
Each rule specifies how a non-terminal symbol can be replaced by a sequence of
terminal and/or non-terminal symbols.

    1. **Terminals**: The basic symbols from which strings are formed. They are the
       "alphabet" of the language. In the context of programming languages,
       terminals might be literals, keywords, or punctuation symbols.
    2. **Non-terminals**: Symbols that are used to help define the language.
       They are placeholders for patterns that can be replaced by other
       non-terminals or terminals.
    3. **Productions**: Rules that define how a non-terminal can be replaced by a
       sequence of terminals and non-terminals.
    4. **Start Symbol**: A special non-terminal symbol that begins the derivation of
       strings.
- **Parsers**
    - `Precedence` - a type of bottom-up parser for context-free grammars
    that can be used only by simple precedence grammars (grammars that can be
    represented using simple precedence relations between terminals)
    - `LR(k)` (Left to right, Rightmost Derivation) - a type of shift-reduce
    parser and the most general-purpose parsers possible that would still be
    efficient in the worst cases. Invented by Donald Knuth as an efficient
    generalization of precedence parsers. 
    - `Shift-reduce` - a class of efficient, table-driven bottom-up parsing
    methods. The parsing methods most commonly used for parsing programming
    languages, LR parsing and its variations, are shift-reduce methods
    - `LALR` (Look-Ahead, Left-to-right, Rightmost Derivation) - a simplified
    version of a canonical LR parser 
- `YACC` (Yet Another Compiler-Compiler) - a tool that generates a parser for
processing the syntax of programming languages.
- `Flex` (Fast Lexical Analyzer Generator) - a tool used for generating a lexical
analyzer responsible for breaking up the input source code into tokens (like
keywords, identifiers, literals, etc.) which are then fed to the parser.
- `Bison` - general-purpose parser generator that converts a grammar description
for an LALR (Look-Ahead, Left-to-right) context-free grammar into a C program
to parse that grammar. Bison is a successor of YACC and offers more features
and flexibility

---

It's [recommended](https://chromium.googlesource.com/external/github.com/pwnall/googletest/+/refs/tags/release-1.8.0/googletest/docs/FAQ.md#why-is-it-not-recommended-to-install-a-pre_compiled-copy-of-google-test-for-example_into-usr_local) that each project compiles Google Test itself

See [instructions](https://github.com/google/googletest/blob/main/googletest/README.md) for installing `googletest`

Typically you'll clone the `googletest` repo and run something like this:

```
cmake -DBUILD_GMOCK=OFF -B build 
sudo make -C build install
```
