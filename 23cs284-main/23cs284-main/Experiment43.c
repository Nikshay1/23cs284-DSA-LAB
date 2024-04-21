#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

void push(struct Stack *stack, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

int main()
{
    struct Stack *stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element after pop: %d\n", peek(stack));

    return 0;
}
