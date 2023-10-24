#include <stdio.h>

int main(void) {
    while (1) {
        char i = getchar();
        if (i == EOF || i == '\n')
            break;
        printf("%c", i);
    }
    putchar('\n');
    return 0;
}
