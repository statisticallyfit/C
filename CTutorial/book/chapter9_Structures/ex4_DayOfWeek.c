#include <stdio.h>


struct Date {
    int day;
    int month;
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


void displayDayOfWeek(int N) {

    int dayNumber = (N - 621049) % 7;

    switch (dayNumber){
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        default: // case 0
            printf("Sunday");
            break;
    }
}



int main() {

    struct Date date;

    printf("Enter a date (dd:mm:yy): ");
    scanf("%i/%i/%i", &date.day, &date.month, &date.year);

    printf("\nDay of week is: ");
    displayDayOfWeek(calculateN(date));
    printf("\n");

    return 0;
}