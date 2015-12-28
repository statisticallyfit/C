#include <stdio.h>


void scalarMultiply (int numRows, int numCols,
                     int matrix[numRows][numCols],
                     int scalar) {

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            matrix[r][c] *= scalar;
        }
    }
}

void displayMatrix (int numRows, int numCols,
                    int matrix[numRows][numCols]){

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            printf("%5i", matrix[r][c]);
        }
        printf("\n");
    }
}


int main() {

    int sampleMatrix[3][5] =
            {
                    {7, 16, 55, 13, 12},
                    {12, 10, 52, 0, 7},
                    {-2, 1, 2, 4, 9}
            };

    printf("Original matrix: \n");
    displayMatrix(3, 5, sampleMatrix);

    scalarMultiply(3, 5, sampleMatrix, 2);

    printf("\nMultiplied by 2: \n");
    displayMatrix(3, 5, sampleMatrix);

    scalarMultiply(3, 5, sampleMatrix, -1);

    printf("\nThen multiplied by -1: \n");
    displayMatrix(3, 5, sampleMatrix);

    return 0;
}