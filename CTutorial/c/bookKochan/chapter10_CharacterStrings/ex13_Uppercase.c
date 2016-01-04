#include "../../../include/StringOp.h"





int main() {

    char word[] = "the sky is bright tonight!";

    printf("\nBefore:\n");
    printf("%s\n", word);

    printf("After 1:\n");
    toUppercase(word);
    printf("%s\n", word);

    printf("After 2:\n");
    toLowercase(word);
    printf("%s\n", word);

    return 0;
}