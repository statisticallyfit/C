#include "../../../include/StringOp.h"




int main() {

    char text[81];

    printf("Type in text:\n");
    printf("When done, press 'ENTER'.\n\n");

    printf("\nThere are %i total words in the above text.\n", countWordsText(text));

    return 0;
}