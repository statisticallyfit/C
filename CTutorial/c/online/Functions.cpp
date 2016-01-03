#include <stdio.h>
#include <ctype.h>

//forward declarations
int canPrintIt(char aChar);
void printLetters(char arg[]);

void printArguments(int argc, char *argv[]){
    printf("\n");

    for(int i = 0; i < argc; i++){
        printLetters(argv[i]);
    }
}

void printLetters(char arg[]){
    for(int i = 0; arg[i] != '\0'; i++) {
        char aChar = arg[i];

        if(canPrintIt(aChar)) {
            printf("'%c' == %d \n", aChar, aChar);
        }
    }
    printf("\n");
}

int canPrintIt(char aChar){
    return isalpha(aChar) || isblank(aChar);
}


int main(int argc, char *argv[]){
    printArguments(argc, argv);
    return 0;
}