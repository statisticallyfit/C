#include <stdio.h>


float absoluteValue (float x) {
    if (x < 0)
        x = -x;
    return x;
}

/**
 * Uses Newton-Raphson method to find square
 * root of number x
 */
float squareRoot (float x) {

    const float epsilon = 0.00001;
    float guess = 1.0;
    float absoluteValue(float x);

    if (x < 0){
        printf("\nERROR: Negative argument to squareRoot.\n\n");
        return -1.0f;
    }

    /*while (absoluteValue(guess * guess - x) >= epsilon){
        guess = (x / guess + guess) / 2;
    }*/

    while (absoluteValue((guess * guess) / x - 1) >= epsilon){
        guess = (x / guess + guess) / 2;
    }

    return guess;
}


int main() {

    printf("squareRoot(1023.0) = %f\n", squareRoot(1023));
    printf("squareRoot(2.0) = %f\n", squareRoot(2.0));
    printf("squareRoot(144.0) = %f\n", squareRoot(144));
    printf("squareRoot(17.5) = %f\n", squareRoot(17.5));
    printf("squareRoot(-10) = %f\n", squareRoot(-10));
}