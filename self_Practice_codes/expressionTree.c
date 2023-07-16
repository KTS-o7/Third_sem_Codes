#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

struct node
{
    char data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

struct stack
{
    int top;
    NODE data[SIZE];
};
typedef struct stack STACK;

NODE createNode(char item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void push(STACK *s, NODE item)
{
    s->data[++(s->top)] = item;
}

NODE pop(STACK *s)
{
    return s->data[(s->top)--];
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int preced(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    }
}

NODE createExpTree(char infix[])
{
    STACK OS, TS;
    OS.top = -1;
    TS.top = -1;
    NODE temp, t;
    int i;
    for (i = 0; infix[i] != '\0'; i++)
    {
        temp = createNode(infix[i]);
        if (isalnum(temp->data))
            push(&TS, temp);
        else
        {
            if (OS.top == -1)
                push(&OS, temp);
            else
            {
                while (OS.top != -1 && (preced(OS.data[OS.top]->data) >= preced(temp->data)))
                {
                    t = pop(&OS);
                    t->right = pop(&TS);
                    t->left = pop(&TS);
                    push(&TS, t);
                }
                push(&OS, temp);
            }
        }
    }

    while (OS.top != -1)
    {
        t = pop(&OS);
        t->right = pop(&TS);
        t->left = pop(&TS);
        push(&TS, t);
    }
    return pop(&TS);
}

int main()
{
    char infix[SIZE];
    NODE root = NULL;
    printf("\nEnter the infix expression : ");
    scanf("%s", infix);
    root = createExpTree(infix);
    printf("\nPreOrder : ");
    preorder(root);
    printf("\nInOrder : ");
    inorder(root);
    printf("\nPostOrder : ");
    postorder(root);
    printf("\n");
    return 0;
}