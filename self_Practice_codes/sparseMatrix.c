#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row, col, data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

NODE insertEnd(NODE start, int row, int col, int data)
{
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if (start == NULL)
    {
        return temp;
    }
    curr = start;
    while (curr->next != NULL)
        curr = curr->next;
    temp->prev = curr;
    curr->next = temp;
    return start;
}

void display(NODE start)
{
    NODE temp = start;
    if (start == NULL)
    {
        printf("\nList empty.\n");
    }

    else
    {
        printf("\nRow\tcol\tData\n");
        while (temp != NULL)

        {
            printf("%d\t%d\t%d\n", temp->row + 1, temp->col + 1, temp->data);
            temp = temp->next;
        }
    }
}

void displayMatrix(NODE start, int m, int n)
{
    NODE temp = start;
    int i, j;
    if (start == NULL)
    {
        printf("\nList empty.\n");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (temp != NULL && temp->row == i && temp->col == j)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    int m, n, item, i, j;
    NODE start = NULL;
    printf("\nEnter the size of matrix : ");
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the (%d,%d) element: ", i + 1, j + 1);
            scanf("%d", &item);
            if (item != 0)
                start = insertEnd(start, i, j, item);
        }
    }
    display(start);
    printf("\n");
    displayMatrix(start, m, n);
    return 0;
}