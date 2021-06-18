#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int element)
{
    if (isFull(s))
        printf("Stack overflow! Cannot push new element in the stack.\n");
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty!\n");
        return -1;
    }
    else
    {
        int element = s->arr[s->top];
        s->top--;
        return element;
    }
}

int peek(struct stack *s, int pos)
{
    int index = s->top - pos + 1;
    if (index < 0)
    {
        printf("Not a valid position.\n");
        return -1;
    }
    else
    {
        int element = s->arr[index];
        return element;
    }
}

int stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct stack *s)
{
    return s->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));
    push(s, 1);
    push(s, 23);
    push(s, 46);
    push(s, 89);
    push(s, 6); // ---> Pushed 5 values
    // push(s, 46); // Stack Overflow since the size of the stack is 10
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!
    // printf("Popped %d from the stack\n", pop(s)); // --> Last in first out!

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("Element at position %d is %d\n", i, peek(s, i));
    }

    printf("StackTop -> %d\n", stackTop(s));
    printf("StackBottom -> %d\n", stackBottom(s));

    return 0;
}