#include <stdio.h>


void concat(char result[], const char str1[], int n1,
            const char str2[], int n2) {

    // copy str1 to result
    for (int i = 0; i < n1; ++i){
        result[i] = str1[i];
    }

    for (int i = 0; i < n2; ++i){
        result[n1 + i] = str2[i];
    }
}


int main() {

    const char s1[5] = {'T', 'e', 's', 't', ' '};
    const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
    char s3[11];

    concat(s3, s1, 5, s2, 6);

    for (int i = 0; i < 11; ++i){
        printf("%c", s3[i]);
    }

    printf("\n");

    return 0;
}