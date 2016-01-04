#include <stdio.h>


void functionWithPointer (int *intPointer)
{
    *intPointer = 100;
}

int main() {

    int number = 50, *p = &number;

    printf("\nBefore call to function: %i\n", number);
    functionWithPointer(p);
    printf("After call to function: %i\n", number);

    return 0;
}