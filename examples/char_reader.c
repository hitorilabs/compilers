#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
