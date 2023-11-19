#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

enum Token {
    TOK_EOF = -1,
    TOK_DEF = -2,
    TOK_EXTERN = -3,
    TOK_IDENTIFIER = -4,
    TOK_NUMBER = -5,
};

// New InputFunction type
int custom_getchar(std::istream& input) {
    return input.get();
}

static int (*InputFunction)(std::istream&) = custom_getchar;

/// gettok - Return the next token from standard input.
static int gettok(std::istream& input, std::string& token_buffer) {  // Accept istream reference
    int LastChar = ' ';

    // Skip any whitespace.
    while (isspace(LastChar))
        LastChar = InputFunction(input);

    if (isalpha(LastChar)) {
        token_buffer = LastChar;
        while (isalnum((LastChar = InputFunction(input)))) {
            token_buffer += LastChar;
        }

        if (token_buffer == "def")
            return TOK_DEF;
        if (token_buffer == "extern")
            return TOK_EXTERN;
        return TOK_IDENTIFIER;
    }
    if (isdigit(LastChar) || LastChar == '.') {  // Number: [0-9.]+
        std::string NumStr;
        double NumberValue;
        do {
            NumStr += LastChar;
            LastChar = InputFunction(input);
        } while (isdigit(LastChar) || LastChar == '.');

        NumberValue = strtod(NumStr.c_str(), 0);
        return TOK_NUMBER;
    }

    if (LastChar == '#') {
        // Comment until end of line.
        do
            LastChar = InputFunction(input);
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return gettok(input, token_buffer);
    }

    if (LastChar == EOF)
        return TOK_EOF;

    // Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = InputFunction(input);
    return ThisChar;
}

