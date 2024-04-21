#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    char *items;
    int top;
};

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->items = (char *)malloc(size * sizeof(char));
    stack->top = -1;
    return stack;
}

bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

void push(struct Stack *stack, char item)
{
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    return stack->items[stack->top--];
}

bool isValidParentheses(char *s)
{
    struct Stack *stack = createStack(strlen(s));

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(stack, s[i]);
        }
        else if (s[i] == ')' && !isEmpty(stack) && stack->items[stack->top] == '(')
        {
            pop(stack);
        }
        else if (s[i] == '}' && !isEmpty(stack) && stack->items[stack->top] == '{')
        {
            pop(stack);
        }
        else if (s[i] == ']' && !isEmpty(stack) && stack->items[stack->top] == '[')
        {
            pop(stack);
        }
        else
        {
            return false; // Invalid parentheses encountered
        }
    }

    return isEmpty(stack); // Stack should be empty if all parentheses are valid
}

int main()
{
    char str1[] = "{[()]}";
    char str2[] = "{[()]}}";

    if (isValidParentheses(str1))
    {
        printf("String 1 has valid parentheses\n");
    }
    else
    {
        printf("String 1 has invalid parentheses\n");
    }

    if (isValidParentheses(str2))
    {
        printf("String 2 has valid parentheses\n");
    }
    else
    {
        printf("String 2 has invalid parentheses\n");
    }

    return 0;
}
