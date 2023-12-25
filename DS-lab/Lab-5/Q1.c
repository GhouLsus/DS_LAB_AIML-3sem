#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFULL(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

int isEMPTY(struct stack *ptr)
{
    return ptr->top == -1;
}

void push(struct stack *ptr, int val)
{
    if (isFULL(ptr))
    {
        printf("Stack OVERFLOW\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEMPTY(ptr))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void display(struct stack *s)
{
    if (isEMPTY(s))
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 10;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));
    int input;
    int val;

    do
    {
        printf("\nEnter 1 to push, 2 to pop, 3 to display, and -1 to exit: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Enter value to be pushed: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if (val != -1)
            {
                printf("Popped value: %d\n", val);
            }
            break;
        case 3:
            display(st);
            break;
        case -1:
            break;
        default:
            printf("Invalid input\n");
        }
    } while (input != -1);

    return 0;
}
 