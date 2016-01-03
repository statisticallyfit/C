#include <stdio.h>
#include <cmath>

int main()
{
    printf("TABLE OF NUMBERS AND THEIR SQUARES\n\n");
    printf(" n     n^2\n");
    printf("---   -----\n");

    for(int n = 1; n <= 10; n++)
    {
        printf("%-2i      %2i\n", n, ((int)pow(n, 2)));
        // left justification
    }

    return 0;
}