#include <stdio.h>
#include <stdbool.h>

bool isPrime(int candidate) {
    if (candidate == 0 || candidate == 1)
        return false;

    if (candidate < 0)
        candidate = -candidate;

    for (int i = 2; i < candidate; i++) {
        if (candidate % i == 0){
            return false;
        }
    }
    return true;
}

int main() {

    /**
     * Any integral type shorter than int is
     * promoted to int when passed to printf()
     */

    printf("\n");
    for (int i = 10; i <= 20; i++){
        if (isPrime(i)){
            printf("number %i: %s\n", i, "PRIME");
        } else {
            printf("number %i: %s\n", i, "-----");
        }
    }

    return 0;
}