#include <stdio.h>
#include <stdbool.h>


int main(void) {
    int number, lastDigit;
    int numberCopy = number;
    bool numberWasNegative = false;


    printf("Enter your number: ");
    scanf("%i", &number);


    if (number < 0){
        numberWasNegative = true;
        number = - number;
    }

    //printf("While loop: ");
    while(number != 0)
    {
        lastDigit = number % 10;
        printf("%i", lastDigit);
        number /= 10;
    }
    if (numberWasNegative) {
        printf("-");
    }
    /*printf("\nDo-while loop: ");

    // try again with do-while loop
    do {
        lastDigit = numberCopy % 10;
        printf("%i", lastDigit);
        numberCopy /= 10;
    } while(numberCopy != 0);*/

    printf("\n");

    return 0;
}