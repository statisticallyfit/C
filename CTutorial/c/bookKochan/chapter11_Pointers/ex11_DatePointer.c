#include <stdio.h>
#include <stdbool.h>


struct Date {
    int day;
    int month;
    int year;
};




/**
 * Finds if year is leap year
 */
bool isLeapYear(struct Date d) {

    return ((d.year % 4 == 0 && d.year % 100 != 0) ||
            d.year % 400 == 0);
}



/**
 * Finds number of days in a month
 */
int numberOfDays(struct Date d){

    const int dayAtMonthEnd[13] = {0, 31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
    return (isLeapYear(d) && d.month == 2) ? 29 : dayAtMonthEnd[d.month];
}


/**
 * Calculates tomorrow's date (updates date by one day)
 */
struct Date dateUpdate (struct Date *today){
    struct Date tomorrow;

    if (today->day != numberOfDays(*today)){
        tomorrow.day = today->day + 1;
        tomorrow.month = today->month;
        tomorrow.year = today->year;
    }
        //implicit: (&& today.day = last)
    else if (today->month == 12){        // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today->year + 1;
    }
        //implicit: (&& today.day = last)
    else {                            // end of month
        tomorrow.day = 1;
        tomorrow.month = today->month + 1;
        tomorrow.year = today->year;
    }

    return tomorrow;
}



int main()
{
    struct Date thisDay, nextDay;

    printf("Enter thisDay's date (mm dd yyyy): ");
    scanf("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);

    nextDay = dateUpdate(&thisDay);

    printf("Tomorrow's date is %i/%i/%.2i.\n",
           nextDay.month,
           nextDay.day,
           nextDay.year % 100);

    return 0;
}