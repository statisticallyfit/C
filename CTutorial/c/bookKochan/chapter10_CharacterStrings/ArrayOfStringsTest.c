#include <stdio.h>
#include <string.h>


int main() {

    int numWords = 10;
    int maxNumLetters = 30;

    char listOfWords[numWords][maxNumLetters];
    char oneWord[maxNumLetters];

    strcpy(listOfWords[1], "yellow sun");

    strcpy(oneWord, listOfWords[1]);

    printf("\n%s", oneWord);

    return 0;
}