#include <stdio.h>
#include <stdbool.h>



struct Date {
    int day;
    int month;
    int year;
};


struct Time {
    int hour;
    int minutes;
    int seconds;
};


struct DateTime {
    struct Date date;
    struct Time time;
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
 * Calculates tomorrow's date
 */
struct Date dateUpdate (struct Date today){
    struct Date tomorrow;

    if (today.day != numberOfDays(today)){
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

    return tomorrow;
}



/**
 * Updates time by one second
 */
struct Time timeUpdate(struct Time now) {
    now.seconds++;

    if (now.seconds == 60) { // next minute
        now.seconds = 0;
        now.minutes++;
    }
    if (now.minutes == 60) { // next hour
        now.minutes = 0;
        now.hour++;
    }
    if (now.hour == 24) { // midnight
        now.hour = 0;
    }

    return now;
}


/**
 * Tests if two Times are equal
 */
bool equal(struct Time t1, struct Time t2) {
    return (t1.hour == t2.hour &&
    t1.minutes == t2.minutes &&
    t1.seconds == t2.seconds);
}


/**
 * Update time by one second. If changes to midnight,
 * then switches date over to next day.
 */
struct DateTime clockKeeper(struct DateTime dt) {

    dt.time = timeUpdate(dt.time);

    struct Time midnight = {0, 0, 0};

    if (equal(dt.time, midnight)){
        dt.date = dateUpdate(dt.date); //update to next day
    }
    return dt;
}


/**
 * Prints a date time
 */
void display(struct DateTime dateTime) {
    printf("%.2i/%.2i/%.2i", dateTime.date.day,
    dateTime.date.month, dateTime.date.year);
    printf("\n");
    printf("%.2i:%.2i:%.2i", dateTime.time.hour,
    dateTime.time.minutes, dateTime.time.seconds);
}


int main() {

    struct DateTime dateTime;

    printf("Enter a date (dd/mm/yy): ");
    scanf("%i/%i/%i", &dateTime.date.day, &dateTime.date.month, &dateTime.date.year);
    printf("Enter a time (hh:mm:ss): ");
    scanf("%i:%i:%i", &dateTime.time.hour, &dateTime.time.minutes, &dateTime.time.seconds);

    printf("\nUpdated date time is: ");
    display(clockKeeper(dateTime));

    return 0;
}