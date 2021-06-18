#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
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

struct Node *insertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
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
    head->prev = NULL;
    head->next = first;

    first->data = 64;
    first->prev = head;
    first->next = second;

    second->data = 482;
    second->prev = first;
    second->next = third;

    third->data = 9;
    third->prev = second;
    third->next = NULL;

    printf("Doubly Linked List before Insertion :\n");
    traverse(head);

    head = insertAtFirst(head, 80);
    printf("Doubly Linked List after Insertion :\n");
    traverse(head);

    return 0;
}