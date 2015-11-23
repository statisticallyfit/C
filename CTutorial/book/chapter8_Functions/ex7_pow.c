#include <stdio.h>
#include <stdbool.h>


float calculatePower(int base, int exp) {

    float result;

    if (exp == 0)
        result = 1;
    else
        result = base * calculatePower(base, exp - 1);

    return result;
}


float power(int base, int exp) {

    bool exponentWasNegative = false;
    float p = 0;

    if (exp < 0){
        exponentWasNegative = true;
        exp = -exp; // make it positive for now
    }

    if (base < 0){
        p = calculatePower(-base, exp); //send it as though it were positive

        if (exp % 2 != 0){ //if exponent was odd, result is negative
            p = -p;
        }
    } else {
        p = calculatePower(base, exp);
    }

    if (exponentWasNegative){
        p = 1 / p;
    }

    return p;
}


int main() {

    int integer = 0;
    int pow = 0;

    printf("Enter an integer and a calculatePower: \n"
                   "IMPORTANT: I assume braces around the integer!\n\n");
    scanf("%i %i", &integer, &pow);

    printf("(%i)^(%i) = %f", integer, pow, power(integer, pow));

    return 0;
}