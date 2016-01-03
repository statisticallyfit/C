#include <stdio.h>


int main() {

    int values[3][2] = {
            365, 7,
            12258, 23,
            996, 4
    };

    int length = sizeof(values)/sizeof(int);
    printf("length: %i\n", length);
    printf("size of values: %zu\n", sizeof(values));
    printf("size of int: %zu\n", sizeof(int));
    printf("sizeof(values) / sizeof(values[0][0]): %zu\n", sizeof(values) / sizeof(values[0][0]));
    printf("trying for number of rows (width): %zu\n", sizeof(values) / sizeof(values[0]));
    printf("trying for number of cols (height): %zu\n", sizeof(values[0])/ sizeof(values[0][0]));

    int numRows = sizeof(values) / sizeof(values[0]);
    int numCols = sizeof(values[0]) / sizeof(values[0][0]);

    // formula: next even multiple = i + j - i % j
    for(int r = 0; r < numRows; r++) {
        for(int c = 1; c < numCols; c++) {
            printf("%i\n", values[r][0] + values[r][c] - values[r][0] % values[r][c]);
        }
    }

    return 0;
}