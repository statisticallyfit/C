#include <stdio.h>
#include <math.h>

double polynomial(double x) {
    return(pow(3*x, 3) - pow(5*x, 2) + 6);
}

int main() {
    printf("print a pow: %i", ((int)pow((double)2, 3)));
    /*double x;

    printf("Enter an x to plug into the polynomial: ");
    scanf("%d", &x);

    printf("The answer is: %d", polynomial(x));

    return 0;*/
    return 0;
}