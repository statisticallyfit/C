#include <stdio.h>


int compareStrings (const char *s1, const char *s2){

    int answer;

    while ( *s1 == *s2 && *s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
    }

    if (*s1 < *s2){
        answer = -1;
    } else if (*s1 > *s2){
        answer = 1;
    } else {
        answer = 0;
    }

    return answer;
}



int main()
{
    printf("\nComparing Strings:\n");
    printf("-1 %i\n", compareStrings("Merry Christmas", "Vacation"));
    printf("0 %i\n", compareStrings("Merry Christmas", "Merry Christmas"));
    printf("0 %i\n", compareStrings("", ""));
    printf("1 %i\n", compareStrings("Ireland", "Garden")); // I comes before G

    return 0;
}