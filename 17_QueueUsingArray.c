#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int element)
{
    if (isFull(q))
        printf("Queue overflow!\n");
    else
    {
        q->arr[++q->r] = element;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!\n");
        return -1;
    }
    else
    {
        return q->arr[++q->f];
    }
}

void traverse(struct queue *q)
{
    printf("Queue List: \n");
    if (q->f == q->r)
        printf("Empty\n");
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 9);
    enqueue(&q, 14);
    enqueue(&q, 12);
    enqueue(&q, 7);
    printf("Popped Element: %d\n", dequeue(&q));
    traverse(&q);
    enqueue(&q, 9);
    enqueue(&q, 49);
    traverse(&q);
    printf("Popped Element: %d\n", dequeue(&q));
    printf("Popped Element: %d\n", dequeue(&q));
    printf("Popped Element: %d\n", dequeue(&q));
    traverse(&q);
    printf("Popped Element: %d\n", dequeue(&q));
    printf("Popped Element: %d\n", dequeue(&q));
    traverse(&q);
    return 0;
}