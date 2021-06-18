#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueueR(int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        printf("Queue is full!\n");
    else
    {
        n->data = element;
        n->next = NULL;
        if (f == NULL)
            f = r = n;
        else
        {
            r->next = n;
            r = n;
        }
    }
}

void enqueueF(int element)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        printf("Queue is full!\n");
    else
    {
        n->data = element;
        n->next = NULL;
        if (f == NULL)
            f = r = n;
        else
        {
            n->next = f;
            f = n;
        }
    }
}

int dequeueF()
{
    struct Node *ptr = f;
    int element = -1;
    if (f == NULL)
        printf("Queue is empty!\n");
    else
    {
        f = f->next;
        element = ptr->data;
        free(ptr);
    }
    return element;
}

int dequeueR()
{
    struct Node *p = f;
    int element = -1;
    if (f == NULL)
        printf("Queue is empty!\n");
    else
    {
        //special case if only one element is left in the queue and we want dequeueRear func to execute.
        if (f == r)
        {
            element = r->data;
            f = r = NULL;
            return element;
        }
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        struct Node *ptr = p->next;
        element = ptr->data;
        free(ptr);
        p->next = NULL;
        r = p;
    }
    return element;
}

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list:\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    linkedListTraversal(f);
    enqueueF(34);
    enqueueF(4);
    enqueueR(7);
    enqueueF(17);
    linkedListTraversal(f);
    dequeueR();
    linkedListTraversal(f);
    dequeueF();
    linkedListTraversal(f);
    dequeueR();
    linkedListTraversal(f);
    enqueueF(27);
    enqueueR(81);
    linkedListTraversal(f);
    return 0;
}