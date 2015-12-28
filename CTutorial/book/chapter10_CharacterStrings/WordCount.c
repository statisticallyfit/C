#include <stdio.h>
#include <stdbool.h>



bool isAlphabetic(const char c) {

    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}



int countWords (const char string[]){

    int wordCount = 0;
    bool lookingForWord = true;


}