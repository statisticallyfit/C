#include <stdio.h>




struct Entry {
    int value;
    struct Entry *next;
};


struct Entry e1, e2, e4, e5;
struct Entry *listPointer;


/**
 * Inserts @insert after the @after Entry
 */
void insertEntry(struct Entry *before,
                 struct Entry *insert)
{
    /*if (before == listPointer) //if insert at head...
    {
        (*insert).next = before;
        listPointer = insert;
    }*/

    (*insert).next = (*before).next; //same as before->next
    (*before).next = insert;
}


/**
 * Removes @remove which is after the before entry
 */
void removeEntry (struct Entry *before,
                  struct Entry *remove)
{
    (*before).next = (*remove).next;
}


/**
 * Removes head
 */
void removeHead()
{
    listPointer = (*listPointer).next;
}

void traverseLinkedList(struct Entry *listMarker)
{
    struct Entry *nullPointer = (struct Entry *) 0;
    while (listMarker != nullPointer)
    {
        printf("%i\n", listMarker->value);
        listMarker = listMarker->next;
    }
}



int main() {


    //struct Entry e1, e2, e4, e5;
    //struct Entry *listPointer;

    /*(*listPointer).value = -1;
    (*listPointer).next = e1.next;*/
    listPointer = &e1;

    e1.value = 10;
    e1.next = &e2;

    e2.value = 20;
    e2.next = &e4;

    e4.value = 40;
    e4.next = &e5;

    e5.value = 50;
    e5.next = NULL; //(struct Entry *) 0

    //Exercise 2
    struct Entry entryInsert; //initialize
    entryInsert.value = 30;
    entryInsert.next = (struct Entry *) 0;

    // Insert after e2
    printf("\nBefore inserting:\n");
    traverseLinkedList(listPointer);
    printf("After inserting:\n");
    insertEntry(&e2, &entryInsert);
    traverseLinkedList(listPointer);

    removeEntry(&e2, &entryInsert);

    // Insert after end
    printf("\n\nTAIL: Before inserting:\n");
    traverseLinkedList(listPointer);
    printf("After inserting:\n");
    insertEntry(&e5, &entryInsert); //insert entry after e5
    traverseLinkedList(listPointer);

    removeEntry(&e5, &entryInsert);

    // Iinsert after head
    printf("\n\nAFTER HEAD: Before inserting:\n");
    traverseLinkedList(listPointer);
    printf("After inserting:\n");
    insertEntry(&e1, &entryInsert);
    traverseLinkedList(listPointer);

    removeEntry(&e1, &entryInsert);

    //Exercise 3: Insert at head
    printf("\n\nHEAD: Before inserting:\n");
    traverseLinkedList(listPointer);
    printf("After inserting:\n");
    insertEntry(listPointer, &entryInsert);
    traverseLinkedList(listPointer);

    return 0;
}