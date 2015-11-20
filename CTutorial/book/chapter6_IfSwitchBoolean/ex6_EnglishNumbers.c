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
void splitNumber(int number) {

    int length = getNumberOfDigits(number);
    int individualDigits[length]; // declare array

    int i = 0;

    // Extracting digits: last digit first, first digit last
    while (number != 0) {
        int firstDigit = number % 10;
        individualDigits[i] = firstDigit;
        i++;
        number /= 10;
    }

    // now reverse the digits in array to match the number
    int firstIndex = 0;
    int lastIndex = length - 1;
    while (firstIndex < lastIndex) {
        int temp = individualDigits[firstIndex];
        individualDigits[firstIndex] = individualDigits[lastIndex];
        individualDigits[lastIndex] = temp;
        firstIndex++;
        lastIndex--;
    }

    //return individualDigits;
}

/**
 * Converts the int digits in array into string words
 */
void translateNumber(int digits[]){

    for (int i = 0; i < sizeof(digits) / sizeof(int); i++){
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

    int number = readNumber();

    splitNumber(number);
    translateNumber(array);

    return 0;
}