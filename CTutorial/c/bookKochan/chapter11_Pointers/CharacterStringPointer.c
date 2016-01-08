#include <stdio.h>


void copyString (char *from, char *to) {

    for ( ; *from != '\0'; from++, to++){
        *to = *from;
    }
    *to = '\0';
}


int main() {

    char string1[] = "A string to be copied";
    char string2[50];

    copyString(string1, string2);
    printf("%s\n", string2);

    copyString("So is this", string2);
    printf("%s\n", string2);

    return 0;
}