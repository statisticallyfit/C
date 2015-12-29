#include <stdio.h>


/**
 * Converts string to integer
 */
/*int toInteger(char string[]) {
    int sign = 0;
    int offset = 0;
    int number = 0;

    if (string[0] == '-'){
        sign = -1;
        offset = 1;
    } else {
        offset = 0;
    }

    for (int i = offset; string[i] != '\0'; i++) {
        number = number * 10 + string[i] - '0';
    }

    if (sign == -1){
        number = -number;
    }

    return number;
}*/


/**
 * Converts a string to integer
 */
int toInteger(const char string[]){

    int intValue, result = 0;

    for (int i = 0; string[i] >= '0' && string[i] <= '9'; i++){
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }
    return result;
}



int main() {
    char string[81];
    printf("Enter a string integer: ");
    scanf("%s", string);

    printf("To integer: %i\n", toInteger(string));


    // More tests
    printf("%i\n", toInteger("245"));
    printf("%i\n", toInteger("100") + 25);
    printf("%i\n", toInteger("13x5"));

    return 0;
}