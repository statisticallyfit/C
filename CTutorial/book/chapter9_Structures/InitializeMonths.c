#include <stdio.h>


struct Month {

    int numberOfDays;
    char name[3];
};



int main() {

    const struct Month months[12] =
            {
                    {31, {'J', 'a', 'n'} }, {28, {'F', 'e', 'b'} },
                    {31, {'M', 'a', 'r'} }, {30, {'A', 'p', 'r'} },
                    {31, {'M', 'a', 'y'} }, {28, {'J', 'u', 'n'} },
                    {31, {'J', 'u', 'l'} }, {28, {'A', 'u', 'g'} },
                    {31, {'S', 'e', 'p'} }, {28, {'O', 'c', 't'} },
                    {31, {'N', 'o', 'v'} }, {28, {'D', 'e', 'c'} },
            };

    printf("Month    Number of Days\n");
    printf("-----    --------------\n");

    for (int i = 0; i < 12; i++) {
        printf(" %c%c%c           %i\n", months[i].name[0],
                                         months[i].name[1],
                                         months[i].name[2],
                                         months[i].numberOfDays);
    }

    return 0;
}