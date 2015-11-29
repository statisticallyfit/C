#include <stdio.h>
#include <math.h>



struct Time {

    int hour;
    int minutes;
    int seconds;
};



/**
 * Converts string to integer
 */
int toString(char string[]) {
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
}



/**
 * Gets seconds of the time struct
 */
int reduceToSeconds(struct Time t) {
    return t.seconds + t.minutes * 60 + t.hour * 3600;
}



/**
 * Calculates elapsed time between two Times
 */
struct Time elapsedTime(struct Time t1, struct Time t2) {

    struct Time timeDiff;

    // get individual seconds
    double s1 = (double)reduceToSeconds(t1);
    double s2 = (double)reduceToSeconds(t1);

    double elapsedSeconds = (s2 > s1) ? s2 - s1 : s1 - s2;

    // convert back to hh:mm:ss

    // HourMin: separate decimal and change it to minutes
    double hourMin = elapsedSeconds / 3600;
    timeDiff.hour = (int) floor(hourMin);
    double minSec = 60 * (hourMin - floor(hourMin)); // get decimal part (min in hour form)
    timeDiff.minutes = (int) floor(minSec);
    double secMillisec = 60 * (minSec - floor(minSec));
    timeDiff.seconds = (int) floor(secMillisec); // millisec are ignored

    return timeDiff;
}


int main() {

}