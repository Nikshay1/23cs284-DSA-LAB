#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *items;
    int top;
};

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->items = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

void push(struct Stack *stack, int item)
{
    stack->items[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    return stack->items[stack->top--];
}

void nextGreaterToRight(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    int nextGreater[n];

    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty(stack) && stack->items[stack->top] <= arr[i])
        {
            pop(stack);
        }
        if (isEmpty(stack))
        {
            nextGreater[i] = -1; // No greater element to the right
        }
        else
        {
            nextGreater[i] = stack->items[stack->top];
        }
        push(stack, arr[i]);
    }

    printf("Next Greater Elements to the Right:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d\n", arr[i], nextGreater[i]);
    }
}

int main()
{
    int arr[] = {4, 6, 3, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterToRight(arr, n);

    return 0;
}
