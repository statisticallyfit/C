#include <stdio.h>

int main(void)
{
    int limit, triangularNumber, tries;

    for(tries = 1; tries <= 5; tries++)
    {
        printf("What triangular number do you want? ");
        scanf("%i", &limit);

        triangularNumber = 0;

        for(int i = 1; i <= limit; i++)
        {
            triangularNumber += i;
        }
        printf("Triangular number %i is %i\n", limit, triangularNumber);
    }

    return 0;
}