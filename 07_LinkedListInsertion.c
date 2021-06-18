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
struct Node *insertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = head;
    return ptr;
}

// case 2:
struct Node *insertAtIndex(struct Node *head, int element, int index)
{
    int i = 0;
    struct Node *p = head;
    while (i++ < index - 1)
    {
        head = head->next;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = head->next;
    head->next = ptr;
    return p;
}

// case 3:
struct Node *insertAtEnd(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    ptr->data = element;
    ptr->next = NULL;
    head->next = ptr;
    return p;
}

// case 4:
struct Node *insertAfterNode(struct Node *head, int element, struct Node *prevNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = element;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    third->next = NULL;

    printf("Linked List before insertion : \n");
    traverse(head);

    // head = insertAtFirst(head,46);
    // head = insertAtIndex(head,48,3);
    // head = insertAtEnd(head,41);
    head = insertAfterNode(head, 41, first);

    printf("Linked List after insertion : \n");
    traverse(head);

    return 0;
}