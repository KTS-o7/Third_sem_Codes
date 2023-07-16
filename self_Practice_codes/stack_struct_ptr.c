#include <stdio.h>
#include <stdlib.h>

// Program to understand implementation of stack
#define SIZE 5 // size is a macro

struct stack
{
    int data[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, int item) // push function takes 2 arguments , a struct pointer and an item to push into stack
{
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top = s->top + 1;    // pre increment the top or index to the place where the item must be added.
        s->data[s->top] = item; // item is being pushed imto stack
        printf("Item %d added to stack at %d \n", item, s->top);
    }
}

void pop(STACK *s) // pop function to pop the element at the index top in the stack
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Item %d popped from %d\n", s->data[s->top], s->top); // item being popped out of the stack
        s->top = s->top - 1;                                         // post decrement the top or index to the index where the data is present or to -1
    }
}

void display(STACK s) // display function to print all the contents of the stack
{
    int i;
    if (s.top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("The contents of Stack are: ");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d ", s.data[i]);
        }
    }
}

int main()
{
    STACK st;
    int ch, item;
    st.top = -1;

    for (;;)
    {
        printf("\n");
        printf("Enter The choice\nPush - 1\nPop - 2\nDisplay - 3\nExit - 4\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(&st, item);
            break;
        case 2:
            pop(&st);
            break;

        case 3:
            display(st);
            break;
        default:
            printf("\n-------------------------------------------------------------------------------\n");
            exit(0);
        }
    }
}