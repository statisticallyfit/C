#include <stdio.h>

int main() {

    _Bool isPrime;

    for (int i = 2; i <= 50; ++i) {
        isPrime = 1; // value 1 is true, 0 is false

        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                isPrime = 0;
            }
        }
        if (isPrime) {  // if isPrime != 0
            printf("%i \n", i);
        }
    }
    printf("\n");

    return 0;
}