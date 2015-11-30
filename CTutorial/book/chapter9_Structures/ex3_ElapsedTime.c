#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>


struct Date {
    int month;
    int day;
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



//Declare all functions
bool isLeapYear(struct Date d);
int getNumDaysInMonth(struct Date d);
bool isLesserDate(struct Date d1, struct Date d2);
bool isLesserTime(struct Time t1, struct Time t2);
bool isLesser(struct DateTime x1, struct DateTime x2);
long int reduceTimeToSeconds(struct Time t);
long long int reduceDateToSeconds(struct Date d);
void displayTime(struct Time t);
void displayDate(struct Date d);
void display(struct DateTime dateTime);
struct Time elapsedTime(struct Time t1, struct Time t2);
struct DateTime elapsedPeriod(struct DateTime x1, struct DateTime x2);
bool datesAreEqual(struct Date, struct Date);
bool timesAreEqual(struct Time, struct Time);
bool areEqual(struct DateTime, struct DateTime);




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
int getNumDaysInMonth(struct Date d){
    //bool isLeapYear(struct Date);

    const int dayAtMonthEnd[13] = {0, 31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
    return (isLeapYear(d) && d.month == 2) ? 29 : dayAtMonthEnd[d.month];
}





/**
 * Converts string to integer
 */
/*int toString(char string[]) {
    int sign = 0;
    int offset = 0;
    int number = 0;

    if (string[0] == '-'){
        sign = -1;
        offset = 1;
    } else {
        offset = 0;
    }

    for (int i = offset; string[i] != '\0'; i++) {
        number = number * 10 + string[i] - '0';
    }

    if (sign == -1){
        number = -number;
    }

    return number;
}*/




/**
 * Returns true if d1 < d2, false otherwise
 */
bool isLesserDate(struct Date d1, struct Date d2) {
    //int reduceDateToSeconds(struct Date);

    return reduceDateToSeconds(d1) <
            reduceDateToSeconds(d2);
}




/**
 * Returns true if t1 < t2, false otherwise
 */
bool isLesserTime(struct Time t1, struct Time t2) {
    //int reduceTimeToSeconds(struct Time);

    return reduceTimeToSeconds(t1) <
           reduceTimeToSeconds(t2);
}




/**
 * Return true if first one is smaller, false if second is smaller
 */
bool isLesser(struct DateTime x1, struct DateTime x2) {
    //bool datesAreEqual(struct Date, struct Date);
    //bool isLesserTime(struct Time, struct Time);
    //bool isLesserDate(struct Date, struct Date);

    if (datesAreEqual(x1.date, x2.date)){
        return isLesserTime(x1.time, x2.time);
    }
    return isLesserDate(x1.date, x2.date);
}



/**
 * HELPER of ELAPSED: Gets seconds of the time struct
 */
long int reduceTimeToSeconds(struct Time t) {
    return ((long) t.seconds + t.minutes * 60 + t.hour * 3600);
}




/**
 * HELPER OF ELAPSED PERIOD: converts the Date to seconds
 * Converts each component of Date to days, then sums
 * days and converts to seconds
 */
long long int reduceDateToSeconds(struct Date d) {
    //bool isLeapYear(struct Date);
    //int getNumDaysInMonth(struct Date);

    long long int daysInYear = (isLeapYear(d)) ? 366 : 365;
    daysInYear *= d.year;
    long long int daysInMonth = getNumDaysInMonth(d) * d.month;
    long long int totalDays = d.day + daysInMonth + daysInYear;
    return (totalDays * 24 * 3600); //number of seconds
}




/**
 * Tests if two Time structs are areEqual in values
 */
bool timesAreEqual(struct Time t1, struct Time t2) {
    return (t1.hour == t2.hour &&
            t1.minutes == t2.minutes &&
            t1.seconds == t2.seconds);
}



/**
 * Checks if two Date structs are areEqual in values
 */
bool datesAreEqual(struct Date d1, struct Date d2) {
    return (d1.year == d2.year &&
            d1.month == d2.month &&
            d1.day == d2.day);
}



/**
 * Checks if two DateTime structs are areEqual in values
 */
bool areEqual(struct DateTime x1, struct DateTime x2) {
    return datesAreEqual(x1.date, x2.date) &&
           timesAreEqual(x1.time, x2.time);
}



/**
 * Prints a Time struct
 */
void displayTime(struct Time t) {
    printf("%.2i:%.2i:%.2i\n", t.hour, t.minutes, t.seconds);
}




/**
 * Prints a Date struct
 */
void displayDate(struct Date d) {
    printf("%.2i/%.2i/%.2i\n", d.month, d.day, d.year);
}




/**
 * Prints a DateTime struct
 */
void display(struct DateTime dateTime) {
    displayDate(dateTime.date);
    displayTime(dateTime.time);
}





/**
 * Calculates elapsed time between two Times
 * Even if you give two times that are two days apart
 * it will calculate as if they are 1 day apart, with 1 midnight
 * between them.
 */
struct Time elapsedTime(struct Time t1, struct Time t2) {

    struct Time elapsed;

    // get individual seconds
    long double s1 = (long double) reduceTimeToSeconds(t1);
    long double s2 = (long double) reduceTimeToSeconds(t2);

    long double elapsedSeconds = (s2 > s1) ? s2 - s1 : s1 - s2;

    // convert back to hh:mm:ss

    // HourMin: separate decimal and change it to minutes
    long double hourMin = elapsedSeconds / 3600;
    elapsed.hour = (int) hourMin;
    long double minSec = 60 * (hourMin - (int) hourMin); // get decimal part (min in hour form)
    elapsed.minutes = (int) minSec;
    long double secMillisec = 60 * (minSec - (int) minSec);
    elapsed.seconds = (int) secMillisec; // millisec are ignored

    return elapsed;
}




/**
 * Calculates elapsed time between two Times
 * Returns mm:dd:yy and hh:mm:ss between two DateTime structs
 */
struct DateTime elapsedPeriod(struct DateTime x1, struct DateTime x2) {

    struct DateTime elapsed;
    long int smallerTimeInSeconds = 0;
    long int biggerTimeInSeconds = 0;

    long int s1 = 0;
    long int s2 = 0;

    // If periods are not in the same day...
    if (!datesAreEqual(x1.date, x2.date)) {

        s1 = reduceTimeToSeconds(x1.time);
        s2 = reduceTimeToSeconds(x2.time);

        smallerTimeInSeconds = (s1 < s2) ? s1 : s2;
        biggerTimeInSeconds = (s1 == smallerTimeInSeconds) ? s2 : s1;
        //biggerTimeInSeconds += 24 * 3600; //create the sandbox

        struct Date smallerDate = (isLesserDate(x1.date, x2.date)) ? x1.date : x2.date;
        struct Date biggerDate = (datesAreEqual(x1.date, smallerDate)) ? x2.date : x1.date;
        long int totalBig = biggerTimeInSeconds + reduceDateToSeconds(biggerDate);
        long int totalSmall = smallerTimeInSeconds + reduceDateToSeconds(smallerDate);


        // The Big Moment: find the difference in seconds
        long double elapsedSeconds = (long double) (totalBig - totalSmall);


        // Now going the other way: convert seconds to DateTime
        long double yearMonth = elapsedSeconds / (365 * 24 * 3600);
        elapsed.date.year = (int) yearMonth;
        long double monthDay = 12 * (yearMonth - (int) yearMonth);
        elapsed.date.month = (int) monthDay;
        long double dayHour = 30 * (monthDay - (int) monthDay);
        elapsed.date.day = (int) dayHour;
        long double hourMin = 24 * (dayHour - (int) dayHour);
        elapsed.time.hour = (int) hourMin;
        long double minSec = 60 * (hourMin - (int) hourMin); // get decimal part (min in hour form)
        elapsed.time.minutes = (int) minSec;
        long double secMillisec = 60 * (minSec - (int) minSec);
        elapsed.time.seconds = (int) secMillisec; // millisec are ignored


    } else {

        //normal time differencing
        struct Time timeElapsed = elapsedTime(x1.time, x2.time);
        elapsed.date.year = 0;
        elapsed.date.month = 0;
        elapsed.date.day = 0;
        elapsed.time.hour = timeElapsed.hour;
        elapsed.time.minutes = timeElapsed.minutes;
        elapsed.time.seconds = timeElapsed.seconds;
    }

    return elapsed;
}




int main() {

    struct Time t1 = {3, 45, 15};
    struct Time t2 = {9, 44, 3};
    struct Time expected1 = {5, 58, 48};
    assert(timesAreEqual(elapsedTime(t1, t2), expected1));

    struct Time t3 = {5, 8, 0};
    struct Time t4 = {6, 7, 0};
    struct Time expected2 = {0, 59, 0};
    assert(timesAreEqual(elapsedTime(t3, t4), expected2));

    //month/day/year
    struct DateTime x = {{11, 2, 2015}, {22, 0, 0}}; // 11/2/2015 and 11pm
    struct DateTime y = {{11, 3, 2015}, {1, 5, 5}}; // 11/3/2015 and 1:0:05am
    //struct DateTime e = {{0, 0, 0}, {3, 5, 5}};
    //assert(areEqual(elapsedPeriod(x, y), e));

    printf("\n");
    display(elapsedPeriod(x, y));

    struct DateTime x1 = {{11, 2, 2015}, {5, 6, 0}}; //5:06 am
    struct DateTime y1 = {{11, 2, 2015}, {7, 7, 0}}; //7.07 am
    struct DateTime x2 = {{11, 2, 2015}, {17, 6, 0}}; // 5:06 pm
    struct DateTime y2 = {{11, 2, 2015}, {19, 7, 0}}; // 7:07 pm

    printf("\n");
    display(elapsedPeriod(x1, y1));
    printf("\n");
    display(elapsedPeriod(x2, y2));

    return 0;
}