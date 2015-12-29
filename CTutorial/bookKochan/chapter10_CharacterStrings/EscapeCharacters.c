#include <stdio.h>


int main() {

    int a = 3, b = 2, c = 5;

    printf("\a ALERT! it is audible\n\n");

    printf("%i\t%i\t%i\t\n\n", a, b, c);

    printf("\\t is the horizontal tab character.\n\n");

    printf("\"Hello,\", he said.\n\n");

    printf("\'Hello,\' he said, again\? \n\n");



    printf("How to separate long char strings: \n");
    char letters[] = "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("%s", letters);

    return 0;
}