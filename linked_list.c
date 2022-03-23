#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList()
{
    struct node *ptr = head;
    printf("\n[ ");

    // start from the beginning
    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}

// insert link at the first location
void insertFirst(int key, int data)
{
    // create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    // point it to old first node
    link->next = head;

    // point first to new first node
    head = link;
}

// delete first item
struct node *deleteFirst()
{

    // save reference to first link
    struct node *tempLink = head;

    // mark next to first link as first
    head = head->next;

    // return the deleted link
    return tempLink;
}

void reverse(struct node **head_ref)
{
    struct node *curr = (*head_ref);
    struct node *next;
    struct node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head_ref = prev;
}

int main()
{
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    struct node *l = head;
    printf("\nOriginal List: \n");
    printList();
    reverse(&head);
    printf("\nAfter Flip: \n");
    printList();
}