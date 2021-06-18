#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, char c)
{
    if (isFull(s))
        printf("Stack overflow!");
    else
    {
        s->top++;
        s->arr[s->top] = c;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
        printf("Stack underflow!");
    else
    {
        return s->arr[s->top--];
    }
}

int isMatch(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return 1;
    return 0;
}

int parenMatch(char *c)
{
    struct stack *s;
    s->top = -1;
    s->size = strlen(c);
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '(' || c[i] == '{' || c[i] == '[')
            push(s, c[i]);
        if (c[i] == ')' || c[i] == '}' || c[i] == ']')
        {
            if (isEmpty(s))
                return 0;
            else
            {
                if (!isMatch(pop(s), c[i]))
                    return 0;
            }
        }
    }
    if (isEmpty(s))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "(8{})(*-)-[${$}9]([])";

    if (parenMatch(exp))
        printf("The parenthesis is balanced");
    else
        printf("The parenthesis is not balanced");

    return 0;
}