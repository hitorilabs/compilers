# Overview

Learning about compilers from the dragon book

I'll be honest I have no idea how you're supposed to structure C projects, but
here we go.

```
cmake -B ./build
make -C build
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

GPT4 Baseline Response

1. Front-End:
    - Lexical Analysis (Scanning): Converts the source code into a stream of
      tokens.
    - Syntax Analysis (Parsing): Converts the token stream into an abstract
      syntax tree (AST) or other intermediate representation.
    - Semantic Analysis: Checks for semantic errors and decorates the AST with
      additional information, like types.
    - Efficiency Considerations:
        - Use efficient data structures.
        - Optimize the parser and lexer. Tools like Flex and Bison can help
          generate optimized lexers and parsers.

2. Intermediate Representation (IR):
    - A compiler often translates source code into an intermediate form to make
      optimization easier.
    - The IR should be designed to be easy to transform and analyze.
    - Efficiency Considerations:
        - Choose an IR that captures the necessary information without being
          overly verbose.
        - Use compact in-memory representations.

3. Optimization:
    - The compiler tries to improve the code without changing its meaning.
    - Common optimizations include:
        - Constant folding and propagation.
        - Dead code elimination.
        - Loop optimization.
        - Inlining.
    - Efficiency Considerations:
        - Use data-flow analysis and other techniques to efficiently find
          optimization opportunities.
        - Implement optimization passes that have a high impact on the
          generated code's performance.

4. Back-End (Code Generation):
    - Translates the IR into machine code or another target language.
    - Efficiency Considerations:
        - Use efficient algorithms for register allocation.
        - Implement peephole optimizations to improve the quality of the
          generated code.
        - Target-specific optimizations can greatly improve the performance of
          the generated code.

5. Just-In-Time Compilation (JIT):
    - Some compilers, especially for dynamic languages, use JIT compilation to
      translate code at runtime.
    - Efficiency Considerations:
        - Use techniques like method caching to avoid recompiling code.
        - Implement fast code generation strategies that trade off code quality
          for compilation speed.

6. Parallelism:
    - Modern compilers can use parallel processing to speed up compilation.
    - Parts of the compilation process, especially optimization, can be
      parallelized.

7. Incremental Compilation:
    - Instead of recompiling everything, only recompile the parts of the code
      that have changed.
    - This can greatly speed up the compilation of large projects.

8. Memory Management:
    - Compilers can be memory-intensive, especially for large projects.
    - Efficient memory management can speed up the compilation process.

9. Tools and Libraries:
    - Using well-optimized libraries and tools can help. For instance, using an
      efficient garbage collector can help with memory management.

What makes a compiler "fast" compared to naive implementations:
- Efficient Algorithms: Using the best algorithms for each stage of the
  compilation process.
- Optimized Data Structures: Efficient storage and quick retrieval of
  information.
- Profiling and Benchmarking: Continuously testing the compiler against
  real-world code and optimizing the hot paths.
- Avoiding Redundancy: Eliminating unnecessary work, like avoiding re-parsing
  unchanged code or skipping optimization passes that won't improve the code.
- Tuned for the Target: Implementing optimizations specific to the target
  architecture or platform.

---

