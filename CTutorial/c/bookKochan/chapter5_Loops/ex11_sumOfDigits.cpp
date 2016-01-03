#include <stdio.h>

int main(void)
{
    int number = 0;
    int lastDigit = 0;
    int sumOfDigits = 0;

    printf("\nEnter your number: ");
    scanf("%i", &number);

    do {
        lastDigit = number % 10;
        sumOfDigits += lastDigit;
        number /= 10;
    } while(number != 0);

    printf("Sum of the digits is: %i\n", sumOfDigits);

    return 0;
}