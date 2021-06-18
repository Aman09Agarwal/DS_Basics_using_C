#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// case 1:
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head->next;
    free(head);
    return ptr;
}

// case 2:
struct Node *deleteAtIndex(struct Node *head, int index)
{
    int i = 0;
    struct Node *p = head;
    while (i++ < index - 1)
    {
        head = head->next;
    }
    struct Node *ptr = head->next;
    head->next = head->next->next;
    free(ptr);
    return p;
}

// case 3:
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    struct Node *ptr = head->next;
    free(ptr);
    head->next = NULL;
    return p;
}

// case 4:
struct Node *deleteGivenNodeVal(struct Node *head, int element)
{
    // if the element is the 1st node of the list
    if (head->data == element)
        return deleteAtFirst(head);

    // otherwise - checking elements for other positions
    struct Node *ptr = head;
    while (head->next->data != element && head->next->next != NULL)
    {
        head = head->next;
    }

    if (head->next->data == element)
    {
        struct Node *p = head->next;
        head->next = head->next->next;

        return ptr;
    }

    // if the element is absent in the list
    printf("\ncould not find the given element\n\n");
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 17;
    head->next = first;

    first->data = 64;
    first->next = second;

    second->data = 482;
    second->next = third;

    third->data = 9;
    third->next = NULL;

    printf("Linked List before deletion : \n");
    traverse(head);

    // head = deleteAtFirst(head);
    // head = deleteAtIndex(head,3);
    // head = deleteAtEnd(head);
    head = deleteGivenNodeVal(head, 64);

    printf("Linked List after deletion : \n");
    traverse(head);

    return 0;
}