#include <stdio.h>

void exchangeSort2(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void exchangeSort(int *array, int n)  {
    for (int *p1 = array; p1 < array + n - 1; p1++) {
        for (int *p2 = p1 + 1; p2 < array + n; p2++) {
            if (*p1 > *p2) {
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
}


void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n");
}



int main()
{
    int len = 13;
    int values[] = {3, 7, 9, 4, 5, 3, 6, 2, 1, 7, 9, 1, 5};

    printf("\nBEFORE:\n");
    printArray(values, len);

    printf("AFTER:\n");
    exchangeSort(values, len);
    printArray(values, len);

    return 0;
}