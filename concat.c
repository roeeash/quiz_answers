#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertFirst(struct node **head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}
struct node *deleteFirst(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    return temp;
}

// display the list
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

struct node *copyList(struct node *sourceList)
{
    if (sourceList == NULL)
        return NULL;
    struct node *targetList = (struct node *)malloc(sizeof(struct node));
    targetList->data = sourceList->data;
    targetList->next = copyList(sourceList->next);
    return targetList;
}

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