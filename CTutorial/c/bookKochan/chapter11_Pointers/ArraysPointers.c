#include <stdio.h>


int arraySum1(int array[], const int arrayLength) {

    int sum = 0, *pointer;
    int *const arrayEnd = array + arrayLength;

    for (pointer = array; pointer < arrayEnd; pointer++){
        printf("%i %i\n", *pointer, *array);
        sum += *pointer;
    }
    return sum;
}

int arraySum2(int *array, const int arrayLength) {

    int sum = 0;
    int *const arrayEnd = array + arrayLength;

    for( ; array < arrayEnd; array++){
        sum += *array;
    }
    return sum;
}


int main() {

    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", arraySum1(values, 10));

    return 0;
}