#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int height(NODE root)
{
    int leftheight, rightheight;
    if (root == NULL)
        return 0;
    else
    {
        leftheight = height(root->left);
        rightheight = height(root->right);
        if (leftheight > rightheight)
            return leftheight + 1;
        else
            return rightheight + 1;
    }
}

int countLeaf(NODE root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countNonLeaf(NODE root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 0;
    return countNonLeaf(root->left) + countNonLeaf(root->right) + 1;
}

NODE createNode(int item)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE insertBST(NODE root, int item)
{
    NODE temp;
    temp = createNode(item);
    if (root == NULL)
        return temp;
    else
    {
        if (item < root->data)
            root->left = insertBST(root->left, item);
        else
            root->right = insertBST(root->right, item);
    }
    return root;
}

NODE inorderSuccessor(NODE root)
{
    NODE curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

NODE deleteNode(NODE root, int key)
{
    NODE temp;
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    NODE root = NULL;
    int ch, item, key;
    for (;;)
    {
        printf("\nEnter 1)Insert 2)Preorder 3)Inorder 4)Postorder 5)Delete node 6)Exit :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            root = insertBST(root, item);
            break;
        case 2:
            printf("\nPreorder : ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nIorder : ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPostorder : ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nEnter Key to delete : ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("\n");
            break;
        default:
            exit(0);
        }
        printf("\n-----------**********------------\n");
    }
    return 0;
}