#include <stdio.h>


int main() {

    int numbers[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < i; j++) {
            numbers[i] += numbers[j];
        }
    }

    // print
    for (int i = 0; i < 10; i++){
        printf("%i ", numbers[i]);
    }

    printf("\n");

    return 0;
}