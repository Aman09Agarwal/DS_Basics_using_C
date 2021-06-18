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

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}

int precedence(char a)
{
    if (a == '/' || a == '%' || a == '*')
        return 3;
    else if (a == '+' || a == '-')
        return 2;
    else
        return 0;
}

int isOperator(char c)
{
    if (c == '/' || c == '%' || c == '*' || c == '+' || c == '-')
        return 1;
    return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; //tracking infix traversal
    int j = 0; //tracking postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (isEmpty(s))
                push(s, infix[i++]);
            else if (precedence(infix[i]) > precedence(stackTop(s)))
                push(s, infix[i++]);
            else
                postfix[j++] = pop(s);
        }
    }
    while (!isEmpty(s))
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    // char * infix = "a-b+t/6";
    // char * infix = "a-b";
    char *infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));

    return 0;
}