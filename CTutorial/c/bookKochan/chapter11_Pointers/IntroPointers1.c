#include <stdio.h>


int main() {

    int count = 10, x;
    int *pointerToInt;

    pointerToInt = &count;
    x = *pointerToInt; //unlatching

    printf("\ncount = %i, x = %i\n", count, x);

    // =========================================

    char c = 'Q';
    char *pointerToChar = &c;
    printf("%c %c\n", c, *pointerToChar);

    c = '/';
    printf("%c %c\n", c, *pointerToChar); //if original var changes, so does value in pointer chest

    *pointerToChar = '(';
    printf("%c %c\n", c, *pointerToChar); // changing pointer value changes original value

    return 0;
}