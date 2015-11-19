#include <stdio.h>
#include <stdbool.h> // to use bool, true/false not _Bool


int main() {

    bool isPrime;

    for (int i = 2; i <= 50; ++i) {
        isPrime = true; // value 1 is true, 0 is false

        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {  // if isPrime != 0
            printf("%i \n", i);
        }
    }
    printf("\n");

    return 0;
}