#include <stdio.h>
#include <stdbool.h>



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


int main() {
    const char stringA[] = "string compare test";
    const char stringB[] = "string";

    printf("%i\n", equalStrings(stringA, stringB));
    printf("%i\n", equalStrings(stringA, stringA));
    printf("%i\n", equalStrings(stringB, "string"));

    return 0;
}