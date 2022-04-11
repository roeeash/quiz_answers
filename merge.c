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
 * @brief this function merges two lists
 *
 * @param l1 - the first list
 * @param l2 - the second list
 * @return struct node* - the merged list
 */
struct node *merge(struct node *l1, struct node *l2)
{

    struct node *new_list = NULL;
    struct node *curr1 = l1;
    struct node *curr2 = l2;

    // while both lists are not null, add one item from each list
    while (curr1 != NULL && curr2 != NULL)
    {
        insertFirst(&new_list, curr1->data);
        curr1 = curr1->next;
        insertFirst(&new_list, curr2->data);
        curr2 = curr2->next;
    }

    // add the rest
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

/**
 * @brief this function reverses the list
 *
 * @param head_ptr - a pointer to the head of the list
 */
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
/**
 * @brief main function
 *
 * @return int
 */
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