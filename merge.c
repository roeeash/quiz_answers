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

struct node *merge(struct node *l1, struct node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    else
    {
        struct node *new_list = NULL;
        struct node *curr1 = l1;
        struct node *curr2 = l2;

        while (curr1 != NULL && curr2 != NULL)
        {
            insertFirst(&new_list, curr1->data);
            curr1 = curr1->next;
            insertFirst(&new_list, curr2->data);
            curr2 = curr2->next;
        }

        while (curr1 != NULL)
        {
            insertFirst(&new_list, curr1->data);
            curr1 = curr1->next;
        }
        while (curr2 != NULL)
        {
            insertFirst(&new_list, curr1->data);
            curr2 = curr2->next;
        }

        return new_list;
    }
}

void reverse(struct node **head_ptr)
{
    struct node *head = (*head_ptr);
    struct node *prev = NULL;
    struct node *next;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    *head_ptr = prev;
}

int main()
{
    struct node *list = NULL;
    insertFirst(&list, 3);
    insertFirst(&list, 30);
    insertFirst(&list, 300);
    list = merge(list, list);
    printf("\nlist = ");
    printList(list);
    struct node *list2 = NULL;
    insertFirst(&list2, 32);
    insertFirst(&list2, 302);
    insertFirst(&list2, 3002);
    printf("\nlist2 = ");
    printList(list2);
    list = merge(list, list2);
    printf("\nlist = ");
    reverse(&list);
    printList(list);
    return (0);
}