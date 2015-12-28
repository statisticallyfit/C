#include <stdio.h>


struct Date {
    int month;
    int day;
    int year;
};




int f(int dateYear, int dateMonth){
    return (dateMonth <= 2) ? dateYear - 1 : dateYear;
}

int g(int dateMonth) {
    return (dateMonth <= 2) ? dateMonth + 13 : dateMonth + 1;
}


/**
 * Finds N according to the formula, using f() and g()
 */
int calculateN(struct Date date) {

    int N = 1461 * f(date.year, date.month) / 4 +
                 153 * g(date.month) / 5 + date.day;

    // if between 3/1/1700 and 2/28/1800 exclusive
    if (date.day > 1 && date.day < 28 &&
        (date.month != 2 || date.month != 3) &&
        date.year > 1700 && date.year < 1800) {
        N += 2;
    } // if between 3/1/1800 and 2/28/1900 inclusive
    else if (date.day >= 1 && date.day <= 28 &&
             date.year >= 1800 && date.year <= 1900){
        N += 1;
    }

    return N;
}


/**
 * Gets elapsed number of days between two dates
 */
int elapsedDays(struct Date d1, struct Date d2) {

    int n1 = calculateN(d1);
    int n2 = calculateN(d2);

    return (n2 > n1) ? n2 - n1 : n1 - n2;
}


int main() {

    struct Date firstDate, secondDate;

    printf("Enter firstDate's date (mm dd yyyy): ");
    scanf("%i%i%i", &firstDate.month, &firstDate.day, &firstDate.year);
    printf("Enter secondDate's date (mm dd yyyy): ");
    scanf("%i%i%i", &secondDate.month, &secondDate.day, &secondDate.year);

    printf("Difference in days: %i\n", elapsedDays(firstDate, secondDate));

    return 0;
}