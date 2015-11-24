#include <stdio.h>



int main() {

    struct Date {
        int month;
        int day;
        int year;
    };

    struct Date today, tomorrow;

    // index = month, element = day
    const int dayAtMonthEnd[13] = {0, 31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31};

    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &today.month, &today.day, &today.year);

    int lastDayOfMonth = dayAtMonthEnd[today.month];

    if (today.day != lastDayOfMonth){
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    //implicit: (&& today.day = last)
    else if (today.month == 12){        // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    //implicit: (&& today.day = last)
    else {                            // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month,
                                               tomorrow.day,
                                               tomorrow.year % 100);

    return 0;
}