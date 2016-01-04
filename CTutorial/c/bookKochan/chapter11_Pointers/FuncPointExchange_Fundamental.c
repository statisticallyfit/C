#include <stdio.h>


void exchange (int *const pInt1, int *const pInt2) {

    int temp;

    temp = *pInt1;
    *pInt1 = *pInt2;
    *pInt2 = temp;
}


int main() {

    int i1 = -5, i2 = 66, *p1 = &i1, *p2 = &i2;

    printf("\ni1 = %i \ni2 = %i\n", i1, i2);
    exchange(p1, p2);
    printf("\ni1 = %i \ni2 = %i\n", i1, i2);

    exchange(&i1, &i2);
    printf("\ni1 = %i \ni2 = %i\n", i1, i2);

    return 0;
}