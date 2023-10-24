#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//  Grammar:
//      expr   -> term rest
//      rest   -> + term {print '+'} 
//              | - term {print '-'} 
//              | ε
//      term   -> 0 { print '0' }
//              | 1 { print '1' }
//                ...
//              | 9 { print '9' }

void get_expr();
void term(int* lookahead);
void match(int terminal, int* lookahead);

void get_expr() {
    int lookahead;

    lookahead = getchar();
    if (lookahead == EOF) {
        fprintf(stderr, "error reading stdin\n");
        exit(1);
    }
    term(&lookahead);

    while (1) {
        switch (lookahead) {
            case EOF:
                return;
            case '+':
                match('+', &lookahead);
                term(&lookahead);
                putchar('+');
                break;
            case '-':
                match('-', &lookahead);
                term(&lookahead);
                putchar('-');
                break;
            default:
                putchar('\n');
                fprintf(stderr, "syntax error: invalid grammar\n");
                exit(1);
        }
    }
}

// check if lookahead is a term
void term(int* lookahead) {
    if (isdigit(*lookahead)) {
        putchar(*lookahead);
        match(*lookahead, lookahead);
    } else {
        fprintf(stderr, "syntax error: expected a digit\n");
        exit(1);
    }
}

// if lookahead symbol matches an expected terminal symbol
// * get the next (non-whitespace) lookahead symbol
void match(int terminal, int* lookahead) {
    if (terminal == *lookahead) {
        do {
            *lookahead = getchar();
        } while (isspace(*lookahead));
    } else {
        fprintf(stderr, "syntax error: expected (%c) got (%c)\n", terminal, *lookahead);
        exit(1);
    }
}

int main() {
    get_expr();
    return 0;
}

