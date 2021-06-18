#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createTreeNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct Node *p = createTreeNode(5);
    struct Node *p1 = createTreeNode(3);
    struct Node *p2 = createTreeNode(6);
    struct Node *p3 = createTreeNode(1);
    struct Node *p4 = createTreeNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // InOrder Traversal
    printf("InOrder Traversal \n");
    inOrder(p);
    printf("\n");

    // Check if it is BST or not?
    printf("Is Binary Search Tree?\n%s", isBST(p) == 1 ? "Yes" : "No");

    return 0;
}