#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * @brief a sturct for a list node
 *
 */
struct node
{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

/**
 * @brief display the list
 *
 */
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
/**
 * @brief insert link at the first location
 *
 * @param key - the item's key
 * @param data -the item's data
 */

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

/**
 * @brief delete first item
 *
 * @return struct node* - the deleted item
 */
struct node *deleteFirst()
{

    // save reference to first link
    struct node *tempLink = head;

    // mark next to first link as first
    head = head->next;

    // return the deleted link
    return tempLink;
}
/**
 * @brief this function reverses a list
 *
 * @param head_ref - the first node in the reversed list
 */
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
/**
 * @brief main function
 *
 * @return int
 */
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