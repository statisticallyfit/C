#include <stdio.h>


/**
 * Reads in a single number and returns it
 */
int readNumber() {
    int number;
    scanf("%i", &number);
    return number;
}

/**
 * Gets number of digits of a number
 */
int getNumberOfDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

/**
 * Splits the number into several digits and returns array
 */
void splitNumber(int number, int *digitsOfNumber, int length) {

    int index = 0;

    // Creating digitsOfNumber: last digit first, first digit last
    while (number != 0) {
        int firstDigit = number % 10;
        digitsOfNumber[index] = firstDigit;
        index++;
        number /= 10;
    }

    // now reverse the digitsOfNumber in array to match the number
    int firstIndex = 0;
    int lastIndex = length - 1;
    while (firstIndex < lastIndex) {
        int temp = digitsOfNumber[firstIndex];
        digitsOfNumber[firstIndex] = digitsOfNumber[lastIndex];
        digitsOfNumber[lastIndex] = temp;
        firstIndex++;
        lastIndex--;
    }
}



/**
 * Converts the int digits in array into string words
 */
void translateNumber(int digits[], int length){

    for (int i = 0; i < length; i++){
        int digit = digits[i];

        switch (digit){
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            default:
                printf("zero ");
                break;
        }
    }
}



int main() {

    printf("Enter a number: \n");
    int number = readNumber();

    const int length = getNumberOfDigits(number);
    int digitsOfNumber[length];
    splitNumber(number, digitsOfNumber, length);
    translateNumber(digitsOfNumber, length);

    printf("\n");

    return 0;
}