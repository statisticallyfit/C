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

    while (absoluteValue((guess * guess) / x - 1) >= epsilon){
        guess = (x / guess + guess) / 2;
    }

    return guess;
}


void findQuadraticRoots(int a, int b, int c){

    float discriminant = b*b - 4*a*c;
    float r1, r2;

    if (discriminant < 0){
        printf("Imaginary roots.");
    } else {
        r1 = (-b + squareRoot(discriminant)) / (2*a);
        r2 = (-b - squareRoot(discriminant)) / (2*a);
        printf("r1: %f\n", r1);
        printf("r2: %f\n", r2);
    }
}


int main() {
    int a, b, c;

    printf("Enter a, b, c: ");
    scanf("%i %i %i\n", &a, &b, &c);

    findQuadraticRoots(a, b, c);
}