#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

struct stack
{
    int top;
    int bit[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, int num)
{
    s->bit[++(s->top)] = num;
}

int pop(STACK *s)
{
    return s->bit[(s->top)--];
}
int decimal_to_binary(STACK *s, int deci)
{
    if (deci == 0)
    {
        push(s, 0);
    }
    while (deci > 0)
    {
        push(s, deci % 2);
        deci /= 2;
    }
}

void display(STACK *s)
{

    for (;;)
    {
        printf("%d", pop(s));
        if (s->top == -1)
            break;
    }
}

int main()
{
    STACK s;
    s.top = -1;
    int deci = 1;
    decimal_to_binary(&s, deci);
    display(&s);
    return 0;
}
