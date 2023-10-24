#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int lookahead;

void expr();
void term();
void match(int t);

void expr() {
    term();
    while (1) {
        if (lookahead == '+') {
            match('+');
            term();
            putchar('+');
        } else if (lookahead == '-') {
            match('-');
            term();
            putchar('-');
        } else {
            return;
        }
    }
}

void term() {
    if (isdigit(lookahead)) {
        putchar(lookahead);
        match(lookahead);
    } else {
        fprintf(stderr, "syntax error\n");
        exit(1);
    }
}

void match(int t) {
    if (lookahead == t) {
        lookahead = getchar();
    } else {
        fprintf(stderr, "syntax error\n");
        exit(1);
    }
}

int main() {
    lookahead = getchar();
    if (lookahead == EOF) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    expr();
    return 0;
}

