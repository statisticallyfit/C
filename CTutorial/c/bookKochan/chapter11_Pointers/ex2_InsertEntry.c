#include <stdio.h>




struct Entry {
    int value;
    struct Entry *next;
};


struct Entry *listPointer;


/**
 * Inserts @insert after the @after Entry
 */
void insertEntry(struct Entry insert,
                 struct Entry after)
{
    insert.next = after.next;
    after.next = &insert;
    //printf("After entry:", after.value);
    /*(*insert).next = (*after).next; //same as after->next
    (*after).next = &(*insert);*/
}


void traverseLinkedList(struct Entry *listPointer)
{
    struct Entry *nullPointer = (struct Entry *) 0;
    while (listPointer != nullPointer)
    {
        printf("%i\n", listPointer->value);
        listPointer = listPointer->next;
    }
}



int main() {


    struct Entry e1, e2, e4, e5;
    //struct Entry *listPointer;

    listPointer = &e1;

    e1.value = 10;
    e1.next = &e2;

    e2.value = 20;
    e2.next = &e4;

    e4.value = 40;
    e4.next = &e5;

    e5.value = 50;
    e5.next = NULL; //(struct Entry *) 0

    //insert entry
    struct Entry entryInsert;
    entryInsert.value = 30;
    entryInsert.next = (struct Entry *) 0;

    printf("\nBefore inserting:\n");
    traverseLinkedList(listPointer);
    printf("After inserting:\n");
    insertEntry(entryInsert, e2);
    traverseLinkedList(listPointer);

    return 0;
}