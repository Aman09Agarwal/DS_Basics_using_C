#include <stdio.h>
#include <stdlib.h>

struct cQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct cQueue *c)
{
    if (c->f == c->r)
        return 1;
    return 0;
}

int isFull(struct cQueue *c)
{
    if (c->f == (c->r + 1) % c->size)
        return 1;
    return 0;
}

void enqueue(struct cQueue *c, int element)
{
    if (isFull(c))
        printf("Circular queue overflow!\n");
    else
    {
        c->arr[c->r] = element;
        c->r = (c->r + 1) % c->size;
        printf("Enqued element: %d\n", element);
    }
}

int dequeue(struct cQueue *c)
{
    int element = -1;
    if (isEmpty(c))
        printf("Circular queue underflow!\n");
    else
    {
        element = c->arr[c->f];
        c->f = (c->f + 1) % c->size;
    }
    return element;
}

int main()
{
    struct cQueue q;
    q.size = 5;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);

    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(&q))
    {
        printf("Queue is full\n");
    }
}