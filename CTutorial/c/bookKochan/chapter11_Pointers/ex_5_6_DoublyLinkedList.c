#include <stdio.h>


struct Entry {
    int value;
    struct Entry *previous;
    struct Entry *next;
};

struct Entry *listPointer;


void traverseDoublyLinkedList(struct Entry *listTraverser)
{
    while (listTraverser != NULL)
    {
        printf("%i\n", listTraverser->value);
        listTraverser = listTraverser->next;
    }
}



/**
 * Inserts @insert after the @after Entry
 */
void insertEntry(struct Entry *location,
                 struct Entry *entry)
{
    /*if (before == listPointer) //if insert at head...
    {
        (*insert).next = before;
        listPointer = insert;
    }*/
    entry->next = location;
    entry->previous = (*location).previous;

    entry->previous->next = entry;
    entry->next->previous = entry;
}



int main() {

    struct Entry e1, e2, e3, e4, e5;

    listPointer = &e1;

    e1.value = 10;
    e1.previous = listPointer;
    e1.next = &e2;

    e2.value = 20;
    e2.previous = &e1;
    e2.next = &e3;

    e3.value = 30;
    e3.previous = &e2;
    e3.next = &e4;

    e4.value = 40;
    e4.previous = &e3;
    e4.next = &e5;

    e5.value = 50;
    e5.previous = &e4;
    e5.next = NULL;


    struct Entry entryToInsert;
    entryToInsert.value =12345678;
    entryToInsert.previous = entryToInsert.next = NULL;

    /*printf("\nINSERT: Before:\n");
    traverseDoublyLinkedList(listPointer);
    printf("After:\n");
    insertEntry(&e2, &entryToInsert);
    traverseDoublyLinkedList(listPointer);*/

    printf("\nHEAD: Before:\n");
    traverseDoublyLinkedList(listPointer);
    printf("After:\n");
    insertEntry(&e1, &entryToInsert);
    traverseDoublyLinkedList(listPointer);

    return 0;
}