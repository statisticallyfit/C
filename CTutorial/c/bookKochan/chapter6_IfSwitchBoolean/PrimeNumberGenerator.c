#include <stdio.h>
#include <stdbool.h> // to use bool, true/false not _Bool


int main() {

    bool isPrime;

    printf("2\n"); // 2 is prime

    for (int i = 3; i <= 50; i += 2) {
        isPrime = true; // value 1 is true, 0 is false

        for (int j = 3; j < i; j += 2) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {  // if isPrime != 0
            printf("%i \n", i);
        }
    }
    printf("\n");

    return 0;
}