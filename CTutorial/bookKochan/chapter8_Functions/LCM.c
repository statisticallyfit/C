#include <stdio.h>

int gcd(int u, int v){

    int temp;

    printf("The gcd of %i and %i is ", u, v);

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

int lcm(int u, int v) {
    if (u >= 0 && v >= 0)
        return (u * v / gcd(u, v));
}