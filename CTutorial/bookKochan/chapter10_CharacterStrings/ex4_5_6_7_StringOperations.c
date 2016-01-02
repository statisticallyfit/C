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

    int i = startIndex;
    for ( ; i <= stopIndex; i++) {
        resultString[i - startIndex] = sourceString[i];
    }
    resultString[i - startIndex] = '\0';
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
    textString[startIndex] = '\0';
}



/**
 * Inserts bit at position given into text
 * If pos is out of bounds of textString then do nothing
 */
void insertString (char textString[], char putString[], int pos)
{
    if (pos >= 0 && pos <= length(textString))
    {
        int lastIndex = length(textString) - 1;
        pos = (pos < 0) ? 0 : pos;

        // rememberString stuff from pos onward
        char rememberString[100];
        int j = 0;
        for (int i = pos; i <= lastIndex; i++, j++){
            rememberString[j] = textString[i];
        }
        rememberString[j] = '\0';

        // putting the string
        for (int i = pos, j = 0; i < length(textString) + length(putString); i++, j++) {
            textString[i] = putString[j];
        }

        // put in the saved bit after
        int zeroFillStartIndex = 0;
        for (int i = pos + length(putString), j = 0; i < length(textString) + length(putString); i++, j++){
            textString[i] = rememberString[j];
            zeroFillStartIndex = i;
        }

        // fill the rest with zeroes \0
        zeroFillStartIndex++;
        for (int i = zeroFillStartIndex; i < length(textString); i++){
            textString[i] = '\0';
        }
    }
}



/**
 * Replaces first occurrence of target with replaceString
 */
bool replaceString (char sourceString[],
                    char targetString[],
                    char replacerString[])
{
    int indexOfTarget = findString(sourceString, targetString);

    if (indexOfTarget != -1) {

        removeString(sourceString, indexOfTarget, length(targetString));

        insertString(sourceString, replacerString, indexOfTarget);

        return true;
    }
    return false;
}



/**
 * Replaces multiple occurrences
 */
void replaceAll (char sourceString[],
                  char targetString[],
                  char replacerString[]) {

    bool stillFound = true;

    do {
        stillFound = replaceString(sourceString, targetString, replacerString);
    } while (stillFound);
}



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
    char text[100];


    printf("\nTEST: REPLACE ALL: ");
    printf("\n\nTest 1:\n");
    initializeWithValue(text, "***___** * *");
    replaceAll(text, "*", "+");
    printf("%s", text);

    printf("\n\nTest 2:\n");
    initializeWithValue(text, "one and only one in the whole one worldone");
    replaceAll(text, "one", "1");
    printf("%s", text);

    printf("\n\nTest 3:\n");
    initializeWithValue(text, "paris, France is nice in the winter because paris is European");
    replaceAll(text, "paris", "Paris");
    printf("%s", text);

    printf("\n\n============================================");

    printf("\nTEST: REPLACE STRING: ");
    printf("\n\nTest 1:\n");
    initializeWithValue(text, "the one and only");
    replaceString(text, "one", "1");
    printf("%s", text);

    printf("\n\nTest 2:\n");
    initializeWithValue(text, "the beautiful pomegranate orchard blossomed");
    printf("%s", text);
    replaceString(text, "pomegranate", "lemon");
    printf("\n%s", text);
    replaceString(text, "beautiful", "tangy");
    printf("\n%s", text);
    replaceString(text, "blossomed", "thrived");
    printf("\n%s", text);
    replaceString(text, "the", "after the thunderstorm, the");
    printf("\n%s", text);

    printf("\n\nTest 3:\n");
    initializeWithValue(text, "the *s are out tonight");
    replaceString(text, "*", "star");
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

    printf("\n\n============================================");

    printf("\nTEST: REMOVE STRING");
    printf("\n\nTest 1:\n");
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

    initialize(result);

    printf("\nTEST: SUBSTRING:\n");
    printf("\nTest 1:\n");
    substring("two words", 4, 20, result);
    printf("%s", result);

    printf("\n\nTest 2:\n");
    initialize(result);
    substring("character", 4, 3, result);
    printf("%s", result);

    printf("\n\nTest3:\n");
    initialize(result);
    substring("pomegranate", 4, 2, result);
    printf("%s", result);

    printf("\n\n");

    return 0;
}