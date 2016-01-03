#include "../../../include/StringOp.h"


int main() {

    char input[81];

    printf("Enter a line:\n");
    readLine(input);

    printf("Number of words: %i", countWordsLine(input));

    return 0;
}