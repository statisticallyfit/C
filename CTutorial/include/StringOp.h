#ifndef STRING_OP_H
#define STRING_OP_H


#include <stdio.h>
#include <stdbool.h>
#include <string.h>



bool equalStrings       (const char[], const char[]);
int compareStrings      (const char[], const char[]);
int lengthString        (const char[]);
void substring          (const char[], int, int, char[]);
int findString          (const char[], const char[]);
void removeString       (char[], int, int);
void insertString       (char[], const char[], int);
bool replaceString      (char[], const char[], const char[]);
void replaceAll         (char[], const char[], const char[]);
void concat             (char[], const char[], const char[]);
int toInteger           (const char[]);
void toUppercase        (char[]);
void toLowercase        (char[]);
void readLine           (char[]);
bool isAlphabetic       (const char);
int countWordsLine      (const char[]);
int countWordsText      (char[]);   // not const since uses readLine and that arg is not const



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



/** Returns -1 if first word is previous the second
 * Returns 1 if first word is next second
 * Returns 0 if they are the same
 */
int compareStrings (const char s1[], const char s2[]){

    int i = 0, answer;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }

    if (s1[i] < s2[i]){
        answer = -1;
    } else if (s1[i] > s2[i]){
        answer = 1;
    } else {
        answer = 0;
    }

    return answer;
}


int lengthString(const char string[]){

    int count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        count++;
    }
    return count;
}



/**
 * Takes a substring of the sourceString
 */
void substring (const char sourceString[],
                int startIndex,
                int numChars,
                char resultString[]){

    int lastIndex = lengthString(sourceString) - 1;
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
int findString (const char sourceString[], const char searchString[]) {

    char foundString[100];

    for (int i = 0; i < lengthString(sourceString); i++)
    {
        substring(sourceString, i, lengthString(searchString), foundString);

        if (lengthString(foundString) == lengthString(searchString) &&
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
    int lastIndex = lengthString(textString) - 1;
    startIndex = (startIndex < 0) ? 0 : startIndex;
    int stopIndex = 0;

    // Getting the bound Indexes of the bit to remove
    if (startIndex + numChars - 1 > lastIndex) {
        stopIndex = lastIndex;
    } else {
        stopIndex = startIndex + numChars - 1;
    }

    // Copy over stuff next stopIndex over the bit to remove
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
void insertString (char textString[], const char putString[], int pos)
{
    if (pos >= 0 && pos <= lengthString(textString))
    {
        int lastIndex = lengthString(textString) - 1;
        pos = (pos < 0) ? 0 : pos;

        // rememberString stuff from pos onward
        char rememberString[100];
        int j = 0;
        for (int i = pos; i <= lastIndex; i++, j++){
            rememberString[j] = textString[i];
        }
        rememberString[j] = '\0';

        // putting the string
        for (int i = pos, j = 0; i < lengthString(textString) + lengthString(putString); i++, j++) {
            textString[i] = putString[j];
        }

        // put in the saved bit next
        int zeroFillStartIndex = 0;
        for (int i = pos + lengthString(putString), j = 0; i < lengthString(textString) + lengthString(putString); i++, j++){
            textString[i] = rememberString[j];
            zeroFillStartIndex = i;
        }

        // fill the rest with zeroes \0
        zeroFillStartIndex++;
        for (int i = zeroFillStartIndex; i < lengthString(textString); i++){
            textString[i] = '\0';
        }
    }
}



/**
 * Replaces first occurrence of target with replaceString
 */
bool replaceString (char sourceString[],
                    const char targetString[],
                    const char replacerString[])
{
    int indexOfTarget = findString(sourceString, targetString);

    if (indexOfTarget != -1) {

        removeString(sourceString, indexOfTarget, lengthString(targetString));

        insertString(sourceString, replacerString, indexOfTarget);

        return true;
    }
    return false;
}



/**
 * Replaces multiple occurrences
 */
void replaceAll (char sourceString[],
                 const char targetString[],
                 const char replacerString[]) {

    bool stillFound = true;

    do {
        stillFound = replaceString(sourceString, targetString, replacerString);
    } while (stillFound);
}



void concat(char result[], const char str1[], const char str2[]) {

    int lastIndex = 0;

    // copy str1 to result
    for (int i = 0; str1[i] != '\0'; ++i){
        result[i] = str1[i];
        lastIndex = i;
    }

    for (int i = 0; str2[i] != '\0'; ++i){
        result[lastIndex] = str2[i];
        lastIndex++;
    }
    // no need to increment lastIndex once out of loop
    // since the != \0 means get right to its location
    result[lastIndex] = '\0';
}


/**
 * Converts a string to integer
 */
int toInteger(const char string[]){

    int intValue, result = 0;
    int index = 0;
    bool wasNegative = false;

    if (string[0] == '-') {
        wasNegative = true;
        index = 1;
    } else {
        index = 0;
    }

    for (int i = index; string[i] >= '0' && string[i] <= '9'; i++){
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }

    if (wasNegative) {
        result *= -1;
    }

    return result;
}



void toUppercase (char string[])
{
    for (int i = 0; i < lengthString(string); i++)
    {
        if (isAlphabetic(string[i]))
        {
            char letter = string[i] - 'a' + 'A';
            string[i] = letter;
        }
    }
}

void toLowercase (char string[])
{
    for (int i = 0; i < lengthString(string); i++)
    {
        if (isAlphabetic(string[i]))
        {
            char letter = string[i] - 'A' + 'a';
            string[i] = letter;
        }
    }
}


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
 * next a word that contains an apostrophe.
 * If there is space around the apostrophe, the (letter) next apostrophe will count as new word
 */
int countWordsLine(const char line[]){

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



int countWordsText(/*const */char text[]) {

    int totalWords = 0;
    bool endOfText = false;

    while (!endOfText) {

        readLine(text);

        if (text[0] == '\0'){
            endOfText = true;
        } else {
            totalWords += countWordsLine(text);
        }
    }
    return totalWords;
}



#endif //STRING_OP_H