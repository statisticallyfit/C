#include <stdio.h>

struct Entry;
void insert(struct Entry *, struct Entry *);
void erase(struct Entry *, struct Entry *);
void traverse(struct Entry *);


struct Entry {
    int value;
    struct Entry *next;
};


struct Entry *listPointer;


/**
 * Inserts @insert after the @after Entry
 * If before is Null, assume you want to insert at head
 */
void insert(struct Entry *before,
            struct Entry *insert)
{
    if (before == NULL) //then assume you insert at the head
    {
        insert->next = listPointer; // this is e1
        listPointer = insert;
    } else {
        (*insert).next = (*before).next; //same as before->next
        (*before).next = insert;
    }
}


/**
 * Removes @erase which is after the before entry
 */
void erase(struct Entry *before,
           struct Entry *erase)
{
    (*before).next = (*erase).next;
}


/**
 * Removes head
 */
void removeHead()
{
    listPointer = (*listPointer).next;
}

void traverse(struct Entry *listMarker)
{
    struct Entry *nullPointer = (struct Entry *) 0;
    while (listMarker != nullPointer)
    {
        printf("%i\n", listMarker->value);
        listMarker = listMarker->next;
    }
}



int main() {


    struct Entry e1, e2, e4, e5;

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
    struct Entry anEntry; //initialize
    anEntry.value = 12345678;
    anEntry.next = (struct Entry *) 0;

    // Insert after e2
    printf("\nBefore inserting:\n");
    traverse(listPointer);
    printf("After inserting:\n");
    insert(&e2, &anEntry);
    traverse(listPointer);

    erase(&e2, &anEntry);

    // Insert after end
    printf("\n\nTAIL: Before inserting:\n");
    traverse(listPointer);
    printf("After inserting:\n");
    insert(&e5, &anEntry); //insert entry after e5
    traverse(listPointer);

    erase(&e5, &anEntry);

    // Insert after head
    printf("\n\nAFTER HEAD: Before inserting:\n");
    traverse(listPointer);
    printf("After inserting:\n");
    insert(&e1, &anEntry);
    traverse(listPointer);

    erase(&e1, &anEntry);

    //Exercise 3: Insert at head
    printf("\n\nHEAD: Before inserting:\n");
    traverse(listPointer);
    printf("After inserting:\n");
    insert(NULL, &anEntry);
    traverse(listPointer);

    return 0;
}