#include <stdio.h>
#include <stdbool.h>



void readLine(char buffer[]) {

    char character;
    int i = 0;

    do {
        character = getchar();
        buffer[i] = character;
        ++i;
    } while (character != '\n');

    buffer[i-1] = '\0';
}



bool isAlphabetic(const char c) {

    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}



int countLineWords(const char line[]){

    int wordCount = 0;
    bool lookingForWord = true;

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (isAlphabetic(line[i]))
        {
            if (lookingForWord){
                wordCount++;
                lookingForWord = false;
            }
        } else {
            lookingForWord = true;
        }
    }
    return wordCount;
}



int countTextWords (char text[]) {

    int totalWords = 0;
    bool endOfText = false;

    while (!endOfText) {

        readLine(text);

        if (text[0] == '\0'){
            endOfText = true;
        } else {
            totalWords += countLineWords(text);
        }
    }
    return totalWords;
}



int main() {


    char text[81];

    printf("Type in text:\n");
    printf("When done, press 'ENTER'.\n\n");

    printf("\nThere are %i total words in the above text.\n", countTextWords(text));

    return 0;
}