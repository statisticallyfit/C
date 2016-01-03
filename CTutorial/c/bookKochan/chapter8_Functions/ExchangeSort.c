#include <stdio.h>


void exchangeSort(int a[], int n) {

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


void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n");
}


int main() {

    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                     44, -3, -9, 12, 17, 22, 6, 11};

    printf("\nThe array before the sort: \n");
    printArray(array, 16);
    exchangeSort(array, 16);
    printf("\nThe array after the sort: \n");
    printArray(array, 16);

    return 0;
}