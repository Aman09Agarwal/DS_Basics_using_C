#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->data = element;
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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
    third->next = head;

    printf("Circular Linked List before Insertion :\n");
    traverse(head);

    head = insertAtFirst(head, 80);
    printf("Circular Linked List after Insertion :\n");
    traverse(head);
    return 0;
}