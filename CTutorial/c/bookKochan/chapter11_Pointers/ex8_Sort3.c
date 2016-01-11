#include <stdio.h>


void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortThree(int *num1, int *num2, int *num3)
{
    if (*num1 > *num2){
        swap(num1, num2);
    }
    if (*num1 > *num3) {
        swap(num1, num3);
    }
    if (*num2 > *num3){
        swap(num2, num3);
    }
}

void sortTest(int num1, int num2, int num3){
    sortThree(&num1, &num2, &num3);
    printf("%i %i %i\n", num1, num2, num3);
}


int main() {

    sortTest(1, 2, 3);
    sortTest(1, 3, 2);

    sortTest(2, 1, 3);
    sortTest(2, 3, 1);

    sortTest(3, 1, 2);
    sortTest(3, 2, 1);

    return 0;
}