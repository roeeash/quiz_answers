#include <stdio.h>
#include <stdlib.h>
/**
 * @brief a sturct for a list node
 *
 */
struct node
{
    int data;
    struct node *next;
};
/**
 * @brief this function adds an item to the beginning the list
 *
 * @param head - the beginning of the list
 * @param value - the value we want to insert
 */
void insertFirst(struct node **head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}
/**
 * @brief this function deletes the first item of the list
 *
 * @param head - the first node of the list
 * @return struct node* - the deleted item
 */
struct node *deleteFirst(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    return temp;
}

/**
 * @brief display the list
 *
 * @param head - the first node of the list we'll display
 */
void printList(struct node *head)
{
    struct node *ptr = head;
    printf("\n[ ");

    // start from the beginning
    while (ptr != NULL)
    {
        printf("(%d) ", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}
/**
 * @brief copy a list recursively
 *
 * @param sourceList - the source list we want to copy
 * @return struct node* - the copied list
 */
struct node *copyList(struct node *sourceList)
{
    if (sourceList == NULL)
        return NULL;
    struct node *targetList = (struct node *)malloc(sizeof(struct node));
    targetList->data = sourceList->data;
    targetList->next = copyList(sourceList->next);
    return targetList;
}
/**
 * @brief concatanate two lists
 *
 * @param sourceList1 - the first list
 * @param sourceList2 - the second list
 * @return struct node* - the concatanated list
 */
struct node *concat(struct node *sourceList1, struct node *sourceList2)
{
    struct node *targetList = copyList(sourceList1);
    struct node *curr = targetList;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = copyList(sourceList2);
    return targetList;
}

int main()
{
    struct node *list = NULL;
    insertFirst(&list, 3);
    insertFirst(&list, 30);
    insertFirst(&list, 300);
    printList(list);
    deleteFirst(&list);
    printList(list);
    struct node *temp = copyList(list);
    printf("\ntemp = ");
    printList(temp);
    printf("\nconcated = ");
    temp = concat(temp, temp);
    printList(temp);
    return (0);
}