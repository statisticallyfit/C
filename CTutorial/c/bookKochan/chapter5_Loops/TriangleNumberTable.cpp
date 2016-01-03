#include <stdio.h>

int main(void) {

    int triangularNumber = 0;

    printf("TABLE OF TRIANGULAR NUMBERS\n\n");
    printf(" n    Sum from 1 to n\n");
    printf("---   ---------------\n");

    for(int i = 1; i <= 10; ++i)
    {
        triangularNumber += i;
        printf("%2i           %i\n", i, triangularNumber);
        // use "%2i" instead of " %i" to avoid the "push over" effect
        // means the number takes up two columns in the display
        // single digit numbers are displayed with leading space (called right justification)
    }

    return 0;
}