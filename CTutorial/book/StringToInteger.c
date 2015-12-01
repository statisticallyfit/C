#include <stdio.h>


/**
 * Converts string to integer
 */
int toInteger(char string[]) {
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
}

int main() {
    char string[];
    printf("Enter a string integer: ");
    scanf("%s", &string);

    printf("To integer: %i", toString(string));
}