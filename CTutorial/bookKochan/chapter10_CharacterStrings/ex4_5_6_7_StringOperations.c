#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool equalStrings(const char s1[], const char s2[]) {

    int i = 0;

    while (s1[i] == s2[i] &&
           s1[i] != '\0' && s2[i] != '\0'){
        ++i;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return true;
    return false;
}


int length (char string[]){

    int count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        count++;
    }
    return count;
}

/**
 * Takes a substring of the sourceString
 */
void substring (char sourceString[],
                int startIndex, int numChars,
                char resultString[]){

    int lastIndex = length(sourceString) - 1;
    startIndex = (startIndex < 0) ? 0 : startIndex;
    int stopIndex = 0;

    if (startIndex + numChars - 1 > lastIndex) {
        stopIndex = lastIndex;
    } else {
        stopIndex = startIndex + numChars - 1;
    }

    for (int i = startIndex; i <= stopIndex; i++) {
        resultString[i - startIndex] = sourceString[i];
    }
}


/**
 * Finds a piece of a string in another string. Returns its start index
 */
int findString (char sourceString[], char searchString[]) {

    char foundString[100];

    for (int i = 0; i < length(sourceString); i++)
    {
        substring(sourceString, i, length(searchString), foundString);

        if (length(foundString) == length(searchString) &&
                equalStrings(foundString, searchString))
        {
            return i;
        }
    }
    return -1; // string not found in source
}


/**
 * Removes specified string from sourceString
 * Puts the cleaned result in the sourceString
 */
void removeString (char textString[],
                   int startIndex,
                   int numChars)
{
    int lastIndex = length(textString) - 1;
    startIndex = (startIndex < 0) ? 0 : startIndex;
    int stopIndex = 0;

    // Getting the bound Indexes of the bit to remove
    if (startIndex + numChars - 1 > lastIndex) {
        stopIndex = lastIndex;
    } else {
        stopIndex = startIndex + numChars - 1;
    }

    // Copy over stuff after stopIndex over the bit to remove
    // and clean remainder with \0
    for (int i = stopIndex + 1; i <= lastIndex; i++)
    {
        textString[startIndex] = textString[i];
        startIndex++;
    }
    while (startIndex <= lastIndex)
    {
        textString[startIndex] = '\0'; // clean up
        startIndex++;
    }
}



/**
 * Inserts bit at position given into text
 * If pos is out of bounds of textString then do nothing
 */
void insertString (char textString[], char putString[], int pos)
{
    if (pos >= 0 && pos < length(textString))
    {
        int lastIndex = length(textString) - 1;
        pos = (pos < 0) ? 0 : pos;

        // rememberString stuff from pos onward
        char rememberString[100];
        for (int i = pos, j = 0; i <= lastIndex; i++, j++){
            rememberString[j] = textString[i];
        }

        // putting the string
        for (int i = pos, j = 0; i < length(textString) + length(putString); i++, j++) {
            textString[i] = putString[j];
        }

        // put in the saved bit after
        for (int i = pos + length(putString), j = 0; i < length(textString) + length(putString); i++, j++){
            textString[i] = rememberString[j];
        }
    }
}



/**
 * Replaces first occurrence of target with replaceString
 */
/*bool replaceString (char sourceString[], char targetString[], char replaceString[])
{

}*/



void initialize(char string[]){
    strcpy(string, "");
}

void initializeWithValue(char string[], char newValue[]) {
    int i = 0;
    for (/*int i = 0*/; i < length(newValue); i++){
        string[i] = newValue[i];
    }

    // now place empty zeroes after the end of the last new value letter
    for (; i < length(string); i++)
    {
        string[i] = '\0';
    }
}


int main() {

    char result[100];

    initialize(result);

    printf("\nTEST: SUBSTRING:\n");
    printf("\nTest 1:\n");
    substring("two words", 4, 20, result);
    printf("%s", result);

    initialize(result);

    printf("\n\nTest 2:\n");
    substring("character", 4, 3, result);
    printf("%s", result);

    initialize(result);

    printf("\n\nTest3:\n");
    substring("pomegranate", 4, 4, result);
    printf("%s", result);

    initialize(result);


    printf("\n\n============================================");
    printf("\nTEST: FINDSTRING");
    printf("\n\nTest 1:\n");
    printf("index = %i", findString("a chatterbox", "hat"));

    printf("\n\nTest 2:\n");
    printf("index = %i", findString("a chatterbox", "boring"));

    printf("\n\nTest 3:\n");
    printf("index = %i", findString("rowing", "arrow"));

    printf("\n\nTest 4:\n");
    printf("index = %i", findString("a chatterbox", "box"));

    printf("\n\nTest 5:\n");
    printf("index = %i", findString("inkheart", "ink"));


    printf("\n\n============================================");
    printf("\nTEST: REMOVE STRING");
    printf("\n\nTest 1:\n");
    char text[100];
    initializeWithValue(text, "the wrong son");
    removeString(text, 4, 6);
    printf("%s", text);

    printf("\n\nTest 2:\n");
    initializeWithValue(text, "the sad godmother");
    removeString(text, 4, 4);
    printf("%s", text);

    printf("\n\nTest 3:\n");
    initializeWithValue(text, "thewordishere");
    removeString(text, 9, 13); //one more than last index
    printf("%s", text);

    printf("\n\nTest 4:\n");
    initializeWithValue(text, "thewordishere");
    removeString(text, 9, 20); //one more than last index
    printf("%s", text);

    printf("\n\nTest 5:\n");
    initializeWithValue(text, "thewordishere");
    removeString(text, -3, 3); //one more than last index
    printf("%s", text);



    printf("\n\n============================================");
    printf("\nTEST: INSERT STRING");
    printf("\n\nTest 1:\n");
    initializeWithValue(text, "the wrong son");
    insertString(text, "per", 10);
    printf("%s", text);

    printf("\n\nTest 2:\n");
    initializeWithValue(text, "the wrong son");
    insertString(text, "per", 20);
    printf("%s", text);

    printf("\n\nTest 3:\n");
    initializeWithValue(text, "the one and only");
    printf("%s", text);
    removeString(text, 4, 3);
    printf("\n%s", text);
    insertString(text, "1", 4);
    printf("\n%s", text);

    printf("\n\n");

    return 0;
}