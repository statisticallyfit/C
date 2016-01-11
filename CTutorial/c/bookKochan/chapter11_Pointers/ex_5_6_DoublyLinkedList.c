#include <stdio.h>


struct Entry {
    int value;
    struct Entry *past;
    struct Entry *next;
};

struct Entry *listPointer;


void traverse(struct Entry *listTraverser)
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
void insert(struct Entry *before,
            struct Entry *insert)
{
    if (before == NULL) // assume we want to insert at head
    {
        insert->past = NULL; //to make this identifiable as head or set to listPtr
        insert->next = listPointer; //is really e1
        listPointer = insert;
    } else  // if at tail
    {
        insert->past = before;
        insert->next = before->next;

        if (before->next != NULL){ //if meant to insert at tail
            before->next = insert;
            insert->next->past = insert;
        }
        before->next = insert;
    }
}


/**
 * Removes the entry after the before entry
 */
void erase (struct Entry *before,
            struct Entry *erase)
{
    //if list pointer (which is e1) == erase
    if (erase->past == NULL) // then erase the head
    {
        listPointer = erase->next; // since erase is the first one
        erase->next->past = NULL;
    } else
    {
        before->next = erase->next;

        if (erase->next != NULL) { // if not at tail{
            erase->next->past = before;
        }
    }
}


int main()
{
    struct Entry e1, e2, e3, e4, e5;

    listPointer = &e1;

    e1.value = 10;
    e1.past = NULL;
    e1.next = &e2;

    e2.value = 20;
    e2.past = &e1;
    e2.next = &e3;

    e3.value = 30;
    e3.past = &e2;
    e3.next = &e4;

    e4.value = 40;
    e4.past = &e3;
    e4.next = &e5;

    e5.value = 50;
    e5.past = &e4;
    e5.next = NULL;


    struct Entry entry;
    entry.value =12345678;
    entry.past = entry.next = NULL;

    printf("\nINSERT: Before:\n");
    traverse(listPointer);
    printf("After:\n");
    insert(&e2, &entry); //insert so entry is third element
    traverse(listPointer);

    erase(&e2, &entry);

    printf("\nHEAD: Before:\n");
    traverse(listPointer);
    printf("After:\n");
    insert(NULL, &entry);
    traverse(listPointer);

    erase(NULL, &entry);

    printf("\nTAIL: Before:\n");
    traverse(listPointer);
    printf("After:\n");
    insert(&e5, &entry);
    traverse(listPointer);

    erase(&e5, &entry);
    printf("\n");
    traverse(listPointer);

    return 0;
}