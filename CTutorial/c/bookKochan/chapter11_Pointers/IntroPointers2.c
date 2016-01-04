#include <stdio.h>



int main() {

    int i1, i2;
    int *p1, *p2;

    i1 = 5;
    p1 = &i1;
    i2 = *p1 / 2 + 10;
    p2 = p1;

    printf("\ni1 = %i\ni2 = %i\n*p1 = %i\n*p2 = %i\n", i1, i2, *p1, *p2);

    return 0;
}