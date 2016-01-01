#include <stdio.h>



int length (char string[]){

    int count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        count++;
    }
    return count;
}


void substring (char sourceString[],
                int startIndex, int numChars,
                char resultString[]){

    int lastIndex = length(sourceString) - 1;
    int endIndex = 0;

    // if startIndex is within the bounds of the sourceString, ...
    if (startIndex >= 0 && startIndex <= lastIndex) {

        if (startIndex + numChars - 1 > lastIndex) {
            endIndex = lastIndex;
        } else {
            endIndex = startIndex + numChars - 1;
        }

        for (int i = startIndex; i <= endIndex; i++) {
            resultString[i - startIndex] = sourceString[i];
        }

    } else {
        // copy over the source into result
        for (int i = 0; i <= lastIndex; i++){
            resultString[i] = sourceString[i];
        }
    }
}


void initialize(char string[]){
    for (int i = 0; i < length(string); i++){
        string[i] = ' ';
    }
}


int main() {

    char result[100];
    char result2[100];
    char result3[100];



    //initialize(result);

    printf("\nTest 1\n");
    substring("two words", 4, 20, result);
    printf("%s", result);

    printf("\n\nTest 2\n");
    substring("character", 4, 3, result2);
    printf("%s", result2);

    printf("\n\nTest3\n");
    substring("pomegranate", 4, 4, result3);
    printf("%s", result3);

    return 0;
}