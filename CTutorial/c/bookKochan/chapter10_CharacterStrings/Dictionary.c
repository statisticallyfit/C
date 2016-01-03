#include <stdlib.h>
#include "../../../include/StringOp.h"


struct Entry{
    char word[15];
    char definition[50];
};




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


/**
 * Finds length of a dictionary
 * TODO Doesn't work! - returns 0 - why?
 */
int lengthDict (struct Entry dict[]) {

    return (sizeof(dict) / sizeof(dict[0]));
}

/**
 * Returns number of digits of largest word in the list
 */
int maxWordLength(char wordList[], int numWords)
{
    int maxLen = 0;
    for (int i = 0; i < numWords; i++)
    {
        int currLen = lengthString(wordList[i]);
        if (currLen > maxLen){
            maxLen = currLen;
        }
    }
    return maxLen;
}


void printDictionary (struct Entry dict[], int numEntries)
{
    // put words of dict into array then find maxword
    char words[numEntries][100]; // set 99 as max word length - a guess (last element is \0)

    for (int i = 0; i < numEntries; i++) {
        //words[i] = dict[i].word;
        strcpy(words[i], dict[i].word);
    }
    int width = 4 + maxWordLength(words, numEntries);

    // now print
    for (int i = 0; i < numEntries; i++)
    {
        printf("%s: ", dict[i].word);
        printf("%*s.\n", width, dict[i].definition);
    }
}



// ================================================

int comparatorByWord (const void *a,
                      const void *b)
{
    struct Entry *e1 = (struct Entry *) a;
    struct Entry *e2 = (struct Entry *) b;
    return compareStrings(e1->word, e2->word);
}

void dictionarySort (struct Entry dict[], int numEntries)
{
    size_t dictLength = sizeof(dict) / sizeof(struct Entry);

    qsort(dict,
          dictLength,
          sizeof(struct Entry),
          comparatorByWord);
}




int main(){

    //can hold 100 Entries; currently has 10
    /*const*/ struct Entry dictionaryOfEntries[100] =
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




    // Testing =================================================================

    printf("\n\n\nTEST: DICTIONARY SORT");
    printDictionary(dictionaryOfEntries, numOfEntries);

    return 0;
}