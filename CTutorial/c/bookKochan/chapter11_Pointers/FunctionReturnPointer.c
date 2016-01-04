#include <stdio.h>



struct Entry {
    int value;
    struct Entry *next;
};

struct Entry *findEntry (struct Entry *listPointer, int match)
{
    struct Entry *nullPointer = (struct Entry *) 0;

    while (listPointer != nullPointer)
    {
        if (listPointer->value == match)
            return listPointer;
        listPointer = listPointer->next;
    }
    return nullPointer; // did not find
}


int main() {

    struct Entry n1, n2, n3;
    struct Entry *foundPtr, *listStart = &n1;

    int search;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = 0;

    printf("Enter value to locate: ");
    scanf("%i", &search);

    foundPtr = findEntry(listStart, search);

    if (foundPtr != (struct Entry *) 0){
        printf("Found %i.\n", foundPtr->value);
    } else {
        printf("Not found.\n");
    }

    return 0;
}