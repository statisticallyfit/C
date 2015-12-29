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


/**
 * Exercise 3: fixing function to not count a new word
 * after a word that contains an apostrophe.
 * If there is space around the apostrophe, the (letter) after apostrophe will count as new word
 */
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
        } else if (line[i] == '\''){ // if apostrophe
            lookingForWord = false;
        } else {
            lookingForWord = true;
        }
    }
    return wordCount;
}



int main() {

    char input[81];

    printf("Enter a line:\n");
    readLine(input);

    printf("Number of words: %i", countLineWords(input));

    return 0;
}