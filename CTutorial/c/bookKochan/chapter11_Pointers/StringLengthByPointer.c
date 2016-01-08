#include <stdio.h>

int stringLength (const char *string)
{
    const char *cptr = string;

    while (*cptr) { // e.g. while not null...
        ++cptr;
    }
    return cptr - string; // the number of elements between pointer and index 0
}

int main() {

    printf("%i\n", stringLength("stringLength test"));
    printf("%i\n", stringLength(""));
    printf("%i\n", stringLength("complete"));

    return 0; 
}