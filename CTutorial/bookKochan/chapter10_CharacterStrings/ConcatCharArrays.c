#include <stdio.h>


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


int main() {

    const char s1[5] = {'T', 'e', 's', 't', ' '};
    const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
    char result[11];

    concat(result, s1, s2);

    for (int i = 0; i < 11; ++i){
        printf("%c", result[i]);
    }

    printf("\n");

    return 0;
}