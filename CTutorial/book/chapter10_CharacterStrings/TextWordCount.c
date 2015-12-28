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



int countWords (const char string[]){

    int wordCount = 0;
    bool lookingForWord = true;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isAlphabetic(string[i]))
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



int countTextWords (const char text[]) {

}



int main() {


}