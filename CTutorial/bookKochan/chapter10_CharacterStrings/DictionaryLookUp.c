#include <stdio.h>
#include <stdbool.h>


struct Entry{
    char word[15];
    char definition[50];
};


bool equalStrings(const char s1[], const char s2[]) {

    int i = 0;

    while (s1[i] == s2[i] &&
           s1[i] != '\0' && s2[i] != '\0'){
        ++i;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return true;
    return false;
}


/** Returns -1 if first word is before the second
 * Returns 1 if first word is after second
 * Returns 0 if they are the same
 */
int compareStrings (const char s1[], const char s2[]){

    int i = 0, answer;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }

    if (s1[i] < s2[i]){
        answer = -1;
    } else if (s1[i] > s2[i]){
        answer = 1;
    } else {
        answer = 0;
    }

    return answer;
}



/**
 * Function to lookup word inside dictionary
 * Implements binary search
 */
int lookUp(const struct Entry dictionary[],
           const char wordToSearch[],
           const int numberOfEntries){

    int low = 0;
    int high = numberOfEntries - 1;
    int mid, result;

    while (low <= high) {
        mid = (low + high) / 2;
        result = compareStrings(dictionary[mid].word, wordToSearch);

        if (result == -1){
            low = mid + 1;
        } else if (result == 1){
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}


int main(){

    //can hold 100 Entries; currently has 10
    const struct Entry dictionaryOfEntries[100] =
            {
                {"aardvark", "a burrowing African mammal"},
                {"abyss",    "a bottomless pit"},
                {"acumen",   "mentally sharp; keen"},
                {"addle",    "to become confused"},
                {"aerie",    "a high nest"},
                {"affix",    "to append; attach"},
                {"agar",     "a jelly made from seaweed"},
                {"ahoy",     "a nautical call of greeting"},
                {"aigrette", "an ornamental cluster of feathers"},
                {"ajar",     "partially opened"}
            };
    char word[10]; // to hold a word with 9 letters
    int numOfEntries = 10;
    int entryIndex = 0;

    printf("Enter word: \n");
    scanf("%14s", word);

    entryIndex = lookUp(dictionaryOfEntries, word, numOfEntries);

    if (entryIndex != -1){
        printf("%s\n", dictionaryOfEntries[entryIndex].definition);
    } else {
        printf("Sorry, the word \"%s\" is not in my dictionary.\n", word);
    }

    return 0;
}