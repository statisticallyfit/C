#include <stdio.h>

int main(int argc, char *argv[]) {
    //go through each string in argv

    int i = 0;
    while(i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    const char *states[] = {
            "California", "Oregon",
            "Washington", "Texas"
    };

    int numStates = 4;
    i = 0;
    while(i < numStates) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}