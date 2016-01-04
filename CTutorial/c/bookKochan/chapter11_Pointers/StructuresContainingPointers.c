#include <stdio.h>

int main() {

    struct PointToInt {
        int *p1;
        int *p2;
    };

    struct PointToInt pointers;
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97; //address that pointers.p2 holds remains same, but value changes and also value of i2

    printf("\ni1 = %i \n*pointers.p1 = %i\n", i1, *pointers.p1);
    printf("\ni2 = %i \n*pointers.p2 = %i\n", i2, *pointers.p2);

    return 0;
}