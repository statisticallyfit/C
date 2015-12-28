#include <stdio.h>
#include <stdbool.h>

/** Goal: To display prime numbers between 1 and n
 * Method: the array stores list of 1s. (Assume all prime)
 * If we find an index that is not prime, put 0 under that index.
 */


int main() {

    int numPrimes = 0;
    printf("Enter how many primes to generate: ");
    scanf("%i", &numPrimes);
    printf("\n");

    bool isPrime[numPrimes];

    // initialize the array
    isPrime[0] = false; // not prime
    isPrime[1] = false; // not prime
    for (int i = 2; i < numPrimes; i++){
        isPrime[i] = true;
    }

    // sieve for primes
    for (int i = 2; i < numPrimes; i++) {
        if (isPrime[i]){
            for (int j = i; i*j < numPrimes; j++){
                isPrime[i*j] = false;
            }
        }
    }

    // print out primes
    for (int i = 0; i < numPrimes; i++) {
        if (isPrime[i]){
            printf("%i  ", i);
        }
    }
    printf("\n");

    return 0;
}