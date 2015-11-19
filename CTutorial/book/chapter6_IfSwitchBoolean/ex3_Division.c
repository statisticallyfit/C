#include <stdio.h>


int main() {

    double num1 = 0;
    double num2 = 0;

    printf("Enter two numbers.\n");
    printf("First: ");
    scanf("%lf", &num1);
    printf("Second: ");
    scanf("%lf", &num2);

    if (num2 != 0) {
        printf("Result num1 / num2: \t%.3f", num1 / num2);
    } else {
        printf("Cannot divide by zero");
    }

    return 0;
}