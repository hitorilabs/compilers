#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void parse_and_convert();

void parse_and_convert() {
    int ch = getchar();

    // Check if the character is a digit
    if (isdigit(ch)) {
        putchar(ch);
    } else {
        fprintf(stderr, "Expected digit\n");
        exit(1);
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '+' || ch == '-') {
            int next_ch = getchar();
            if (isdigit(next_ch)) {
                putchar(next_ch);
                putchar(ch);
            } else {
                fprintf(stderr, "Expected digit after operator\n");
                exit(1);
            }
        } else {
            fprintf(stderr, "Unexpected character\n");
            exit(1);
        }
    }
}

int main() {
    parse_and_convert();
    putchar('\n');
    return 0;
}

