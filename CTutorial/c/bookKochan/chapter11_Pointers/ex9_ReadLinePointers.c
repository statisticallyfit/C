#include <stdio.h>


void readLine(char *buffer) {

    char character;

    do {
        character = getchar();
        *(buffer++) = character;
    } while (character != '\n');

    *(buffer - 1) = '\0';
}



int main() {

    char line[81];

    for (int i = 0; i < 3; ++i){
        readLine(line);
        printf("%s\n\n", line);
    }

    return 0;
}