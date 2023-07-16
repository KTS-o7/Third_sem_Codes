// a code to check is parentheses present in an infix expression is balanced or not.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}

char pop(STACK *s)
{
    return s->data[(s->top)--];
}

int check_parenthesis(STACK *s, char expression[20])
{
    int i, flag = 1;
    char symbol, temp;
    for (i = 0; expression[i] != '\0'; i++)
    {
        symbol = expression[i];
        if (symbol == '(' || symbol == '{' || symbol == '[')
            push(s, symbol);
        else
        {
            if ((s->top) == -1)
                flag = 0;
            else
            {
                temp = pop(s);
                if (temp == '(' && (symbol == '}' || symbol == ']'))
                    flag = 0;
                if (temp == '{' && (symbol == ')' || symbol == ']'))
                    flag = 0;
                if (temp == '[' && (symbol == '}' || symbol == ')'))
                    flag = 0;
            }
        }
    }
    if (s->top != -1) // check if any parenthesis is left out in stack
        flag = 0;
    return flag;
}

int main()
{
    int flag;
    char exp[20];
    STACK s;
    s.top = -1;
    printf("\nenter the expression: ");
    scanf("%s", exp);
    flag = check_parenthesis(&s, exp);
    if (flag)
        printf("\nBalanced Parentheses.\n");
    else

        printf("\nNot balanced.\n");
    return 0;
}