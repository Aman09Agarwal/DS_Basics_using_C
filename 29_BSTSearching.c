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

struct Node *searchBST(struct Node *root, int element)
{
    if (root == NULL)
        return NULL;
    else if (root->data == element)
        return root;
    else if (element < root->data)
        searchBST(root->left, element);
    else
        searchBST(root->right, element);
}

struct Node *searchBSTIterative(struct Node *root, int element)
{
    while (root != NULL)
    {
        if (root->data == element)
            return root;
        else if (element < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
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

    int element = 7;

    // Search element in BST
    // printf("%s",searchBST(p,element)==NULL?"Element Not Found":"Element Found");

    // Search element in BST (Iterative method)
    printf("%s", searchBSTIterative(p, element) == NULL ? "Element Not Found" : "Element Found");

    return 0;
}