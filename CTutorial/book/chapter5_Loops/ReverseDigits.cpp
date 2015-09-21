#include <stdio.h>

int main(void) {
    int number, lastDigit;

    printf("Enter your number: ");
    scanf("%i", &number);

    int numberCopy = number;

    printf("While loop: ");
    while(number != 0)
    {
        lastDigit = number % 10;
        printf("%i", lastDigit);
        number /= 10;
    }
    printf("\nDo-while loop: ");

    // try again with do-while loop
    do {
        lastDigit = numberCopy % 10;
        printf("%i", lastDigit);
        numberCopy /= 10;
    } while(numberCopy != 0);

    printf("\n");

    return 0;
}