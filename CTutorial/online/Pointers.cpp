#include <stdio.h>


// Printing ages in three ways
int main(int argc, char *argv[]) {

    //create two arrays
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
            "Alan", "Frank",
            "Mary", "John", "Lisa"
    };

    //safely get the size of the ages
    int numOfPeople = sizeof(ages) / sizeof(int);


    // FIRST WAY USING INDEXING
    for(int i = 0; i < numOfPeople; i++){
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
    printf("---\n");

    //set up the pointers to the start of the arrays
    int *currentAge = ages;
    char **currentName = names;


    // SECOND WAY USING POINTERS
    for(int i = 0; i < numOfPeople; i++) {
        printf("%s is %d years old.\n",
                *(currentName + i), *(currentAge + i));
    }
    printf("---\n");


    // THIRD WAY, pointers are just arrays
    for(int i = 0; i < numOfPeople; i++) {
        printf("%s is %d years old again.\n",
                currentName[i], currentAge[i]);
    }
    printf("---\n");


    // FOURTH WAY WITH POINTERS IN STUPID AND COMPLEX WAY
    for(currentName = names, currentAge = ages;
        (currentAge - ages) < numOfPeople;
            currentName++, currentAge++) {
        printf("%s lived %d years so far.\n",
                *currentName, *currentAge);
    }

    return 0;
}
