#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

void traverse(struct stack *s)
{
    while (s != NULL)
    {
        printf("%d\n", s->data);
        s = s->next;
    }
}

int isFull()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

struct stack *push(struct stack *s, int element)
{
    if (isFull())
        printf("Stack overflow!");
    else
    {
        struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
        ptr->data = element;
        ptr->next = s;
        s = ptr;
        return s;
    }
}

int pop(struct stack *tp)
{
    if (isEmpty(tp))
        printf("Stack underflow!");
    else
    {
        struct stack *ptr = tp;
        int element = ptr->data;
        top = (tp)->next;
        free(ptr);
        return element;
    }
}

int peek(struct stack *s, int pos)
{
    struct stack *ptr = s;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int stackTop(struct stack *s)
{
    if (s != NULL)
        return s->data;
    else
        return -1;
}

int stackBottom(struct stack *s)
{
    if (s == NULL)
        return -1;
    else
    {
        while (s->next != NULL)
        {
            s = s->next;
        }
        return s->data;
    }
}

int main()
{
    // defined top struct globally so that we dont have to pass the address of top in pop func.
    top = push(top, 78);
    top = push(top, 14);
    top = push(top, 139);
    top = push(top, 62);
    top = push(top, 271);

    traverse(top);

    int element = pop(top);
    printf("Popped element is %d\n", element);
    traverse(top);

    // Peek function
    for (int i = 1; i <= 2; i++)
    {
        printf("Element at position %d is %d\n", i, peek(top, i));
    }

    printf("StackTop -> %d\n", stackTop(top));
    printf("StackBottom -> %d\n", stackBottom(top));

    return 0;
}