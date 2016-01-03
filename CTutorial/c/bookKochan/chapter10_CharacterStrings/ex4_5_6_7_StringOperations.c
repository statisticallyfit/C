/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>*/

//stringop already imports the above directories
#include "../../../include/StringOp.h"



void initialize(char string[]){
    strcpy(string, "");
}

void initializeWithValue(char string[], char newValue[]) {
    int i = 0;
    for (/*int i = 0*/; i < lengthString(newValue); i++){
        string[i] = newValue[i];
    }

    // now place empty zeroes after the end of the last new value letter
    for (; i < lengthString(string); i++)
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