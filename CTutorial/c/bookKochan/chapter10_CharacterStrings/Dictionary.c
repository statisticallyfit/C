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
int maxWordLength(int numWords, int numLetters, char wordList[][numLetters])
{
    int maxLen = 0;
    for (int i = 0; i < numWords; i++)
    {
        char aWord[100];
        strcpy(aWord, wordList[i]);
        int currLen = lengthString(aWord);
        if (currLen > maxLen){
            maxLen = currLen;
        }
    }
    return maxLen;
}

void printDictionary (struct Entry dict[], int numEntries)
{
    // put words of dict into array then find maxword
    int numLetters = 100;
    char words[numEntries][numLetters]; // set 99 as max word length - a guess (last element is \0)

    for (int i = 0; i < numEntries; i++) {
        strcpy(words[i], dict[i].word);
    }
    int rightJustify = 4 + maxWordLength(numEntries, numLetters, words);

    // now print
    for (int i = 0; i < numEntries; i++) {
        printf("%-*s: ", rightJustify, dict[i].word);
        printf("%s.\n", dict[i].definition);
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


// ===================================================================

void librarian (struct Entry dict[], char word[], int numEntries)
{
    printf("Enter word: \n");
    scanf("%14s", word);

    int entryIndex = lookUp(dict, word, numEntries);

    if (entryIndex != -1){
        printf("%s\n", dict[entryIndex].definition);
    } else {
        printf("Sorry, the word \"%s\" is not in my dictionary.\n", word);
    }
}

int main(){

/*    *//*const*//* struct Entry dictionaryOfEntries[100] =
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
            };*/
    //can hold 100 Entries; currently has 10
    /*const*/ /*struct Entry dictionaryOfEntries[100] =
            {
                    {"aerie",    "a high nest"},
                    {"ajar",     "partially opened"},
                    {"abyss",    "a bottomless pit"},
                    {"affix",    "to append; attach"},
                    {"addle",    "to become confused"},
                    {"aigrette", "an ornamental cluster of feathers"},
                    {"ahoy",     "a nautical call of greeting"},
                    {"agar",     "a jelly made from seaweed"},
                    {"aardvark", "a burrowing African mammal"},
                    {"acumen",   "mentally sharp; keen"}
            };
    int numEntries = 10;
    //char word[10]; // to hold a word with 9 letters
    //librarian(dictionaryOfEntries, word, numEntries);



    // Testing =================================================================

    printf("\n\nTEST: DICTIONARY SORT");
    printf("\n\nBefore:\n");
    printDictionary(dictionaryOfEntries, numEntries);
    dictionarySort(dictionaryOfEntries, numEntries);
    printf("\n\nAfter:\n");
    printDictionary(dictionaryOfEntries, numEntries);
*/
    //==========================================================================
    struct st_ex {
        char product[16];
        float price;
    };

    struct st_ex structArray[] = {{"mp3 player", 299.0f}, {"plasma tv", 2200.0f},
                                  {"notebook",   1300.0f}, {"smartphone", 499.99f},
                                  {"dvd player", 150.0f}, {"matches", 0.2f }};

    size_t structs_len = sizeof(structArray) / sizeof(struct st_ex);
    printf("\n%zu", structs_len);

    //==========================================================================

    struct Entry dict[10];
    strcpy(dict[0].word, "benign");     strcpy(dict[0].definition, "harmless; a good thing");
    strcpy(dict[1].word, "baffled");    strcpy(dict[1].definition, "completely confused");
    strcpy(dict[2].word, "bizarre");    strcpy(dict[2].definition, "very weird; out of the ordinary");

    size_t dict_len = sizeof(dict) / sizeof(struct Entry);
    printf("\n%zu", dict_len);

    return 0;
}