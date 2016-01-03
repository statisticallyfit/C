#include <stdio.h>
#include <cmath>

int main() {

    double num1 = 3.31 * pow(10, -8);
    double num2 = 2.01 * pow(10, -7);
    double num3 = 7.16 * pow(10, -6);
    double num4 = 2.01 * pow(10, -8);

    double result = (num1 * num2) / (num3 + num4);

    printf("The result is: %e", result);

    return 0;
}