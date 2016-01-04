#include <stdio.h>


int main() {

    struct Date {
        int day;
        int month;
        int year;
    };

    struct Date today, *datePointer;

    datePointer = &today;

    // all are equivalent ways of assigning
    (*datePointer).month = 9;
    datePointer->day = 25;
    datePointer->year = 2004;

    printf("Today's date is %i/%i/%.2i.\n",
           datePointer->day,
           datePointer->month,
           datePointer->year % 100);

    return 0;
}