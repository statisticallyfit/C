#include <stdio.h>
#include <string.h>

int main(void)
{
    int dollars, cents, count;

    for(count = 1; count <= 1; count++)
    {
        printf("Enter dollars: ");
        scanf("%i", &dollars);
        printf("Enter cents: ");
        scanf("%i", &cents);
        printf("$%i.%.2i\n\n", dollars, cents);
    }

    // effect of the dot before field width:
    //double e = 2.71828282828282828;
    //printf("%.6f", e);

    //converting from int to string
    int anInt = 368;
    char str[15];
    sprintf(str, "%d", anInt);
    printf("%s\n", str);

    return 0;
}