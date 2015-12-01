#include <stdio.h>
//#include <qfloat.h>
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
bool isLeapYear(struct Date);
int getNumDaysInMonth(struct Date);
struct Date subtractDates(struct Date, struct Date);
bool isLesserDate(struct Date, struct Date);
bool isLesserTime(struct Time, struct Time);
bool isLesser(struct DateTime, struct DateTime);
long int reduceTimeToSeconds(struct Time);
long long int reduceDateToSeconds(struct Date);
void displayTime(struct Time);
void displayDate(struct Date);
void display(struct DateTime);
struct Time elapsedTime(struct Time, struct Time);
struct DateTime elapsedPeriod(struct DateTime, struct DateTime);
bool datesAreEqual(struct Date, struct Date);
bool timesAreEqual(struct Time, struct Time);
bool areEqual(struct DateTime, struct DateTime);
long double correctForLeapYear(struct DateTime, struct DateTime, long double);



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
 * Returns Date object with values diffed
 */
struct Date subtractDates(struct Date d1, struct Date d2) {
    long int s1 = reduceDateToSeconds(d1);
    long int s2 = reduceDateToSeconds(d2);
    struct Date small, big, diff;

    if (s1 < s2) {
        small = d1;
        big = d2;
    } else {
        small = d2;
        big = d1;
    }

    diff.month = big.month - small.month;
    diff.day = big.day - small.day;
    diff.year = big.year - small.year;

    return diff;
}





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
 * Adds 1 to seconds if number of leaps is odd, else nothing
 */
long double correctForLeapYear(struct DateTime x1,
                               struct DateTime x2,
                               long double seconds){
    int numLeaps = 0;
    for (int year = x1.date.year; year <= x2.date.year; year++){
        struct Date maybeLeap = {0, 0, year};
        if (isLeapYear(maybeLeap)){
            numLeaps++;
        }
    }
    if (numLeaps % 2 != 0){
        seconds += 24 * 3600; //extra seconds in 1 day
    }
    return seconds;
}





/**
 * PRECONDITION: x1 must be less than x2
 * Calculates elapsed time between two Times
 * Returns mm:dd:yy and hh:mm:ss between two DateTime structs
 */
struct DateTime elapsedPeriod(struct DateTime x1, struct DateTime x2) {

    struct DateTime elapsed;
    struct Date dateWithSameDay;
    struct Date diff;
    long double secondsDiff = 0;

    dateWithSameDay.day = x1.date.day;
    dateWithSameDay.month = x2.date.month;
    dateWithSameDay.year = x2.date.year;

    diff = subtractDates(dateWithSameDay, x1.date);

    secondsDiff = reduceDateToSeconds(diff);
    secondsDiff += 24 * 3600 * (x2.date.day - x1.date.day);
    secondsDiff += reduceTimeToSeconds(x2.time);
    secondsDiff -= reduceTimeToSeconds(x1.time);

    secondsDiff = correctForLeapYear(x1, x2, secondsDiff);

    // Now going the other way: convert seconds to DateTime
    /*long double yearMonth = secondsDiff / (365 * 24 * 3600);
    elapsed.date.year = (int) yearMonth;
    long double monthDay = 12 * (yearMonth - (int) yearMonth);
    elapsed.date.month = (int) monthDay;
    long double dayHour = 30 * (monthDay - (int) monthDay);
    elapsed.date.day = (int) dayHour;*/
    long double hourMin = secondsDiff / 3600; //24 * (dayHour - (int) dayHour);
    elapsed.time.hour = (int) hourMin;
    long double minSec = 60 * (hourMin - (int) hourMin); // get decimal part (min in hour form)
    elapsed.time.minutes = (int) minSec;
    long double secMillisec = 60 * (minSec - (int) minSec);
    elapsed.time.seconds = (int) secMillisec; // millisec are ignored

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