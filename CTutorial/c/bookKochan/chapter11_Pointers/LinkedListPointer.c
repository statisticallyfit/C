#include <stdio.h>


int main () {

    struct Entry {
        int value;
        struct Entry *next;
    };

    struct Entry n1, n2, n3;

    struct Entry *listPointer;
    listPointer = &n1;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = (struct Entry *) 0; //marking end of list with null pointer

    /*printf("\nlistptr value: %i\n", (*listPointer).value);
    printf("listptr nextval: %i\n", (*listPointer).next->value);
    printf("%i\n", n1.next->value); // means (*(n1.next)).value
    printf("%i\n", n2.next->value);*/

    // Traversing linkedlist
    struct Entry *nullPointer = (struct Entry *) 0;
    while (listPointer != nullPointer)
    {
        printf("%i\n", listPointer->value);
        listPointer = listPointer->next;
    }

    return 0;
}