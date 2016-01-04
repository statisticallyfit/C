#include <stdio.h>


int main () {

    struct Entry {
        int value;
        struct Entry *next;
    };

    struct Entry n1, n2, n3;

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;

    n1.next = &n2;
    n2.next = &n3;

    printf("\n%i\n", n1.next->value);
    printf("%i\n", n2.next->value);

    return 0;
}