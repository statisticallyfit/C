#include <stdio.h>





void displayMatrix(int numRows, int numCols, int m[numRows][numCols]){
    for (int r = 0; r < numRows; r++){
        for (int c = 0; c < numCols; c++){
            printf("%5i", m[r][c]);
        }
        printf("\n");
    }
}


void transposeMatrix(int numRows, int numCols,
                     int matrix[numRows][numCols],
                     int transpose[numCols][numRows]){

    for (int r = 0; r < numRows; r++){
        for (int c = 0; c < numCols; c++) {
            transpose[c][r] = matrix[r][c];
        }
    }
}


int readRow() {
    int numRows = 0;
    scanf("%i", &numRows);
    return numRows;
}

int readCol() {
    int numCols = 0;
    scanf("%i", &numCols);
    return numCols;
}

void readMatrix(int numRows, int numCols, int matrix[numRows][numCols]){

    for (int r = 0; r < numRows; r++){
        for (int c = 0; c < numCols; c++) {
            scanf("%i ", &matrix[r][c]);
        }
    }
}


int main() {

    /*int matrix[4][5] =
            {
                    {1, 2, 3, 4, 5},
                    {3, 6, 9, 12, 21},
                    {2, 4, 6, 8, 10},
                    {5, 10, 15, 20, 25},
            };


    int t[5][4] =
            {
                    {1, 3, 2, 5},
                    {2, 6, 4, 10},
                    {3, 9, 6, 15},
                    {4, 12, 8, 20},
                    {5, 21, 10, 25},
            };*/

    // Get row and col numbers
    printf("Enter rows and cols:\n");
    int numRows = readRow();
    int numCols = readCol();

    // Create the matrix and transpose empty matrices
    int matrix[numRows][numCols];
    int transpose[numCols][numRows];

    // Fill the matrix
    printf("Enter elements in the %i by %i matrix: \n", numRows, numCols);
    readMatrix(numRows, numCols, matrix); // fill up this matrix by reference*/

    printf("\nMatrix before:\n");
    displayMatrix(numRows, numCols, matrix);

    transposeMatrix(numRows, numCols, matrix, transpose);

    printf("\nMatrix after:\n");
    displayMatrix(numCols, numRows, transpose);

    return 0;
}