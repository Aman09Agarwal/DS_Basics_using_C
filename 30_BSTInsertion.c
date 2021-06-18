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

void insert(struct Node *root, int element)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == element)
        {
            printf("Cannot insert %d, already exists.\n", element);
            return;
        }
        else if (element < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct Node *new = createTreeNode(element);
    if (element < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct Node *p = createTreeNode(5);
    struct Node *p1 = createTreeNode(3);
    struct Node *p2 = createTreeNode(64);
    struct Node *p3 = createTreeNode(1);
    struct Node *p4 = createTreeNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int element = 15;

    // insert element in BST
    insert(p, element);

    // check if the new node has been inserted properly
    inOrder(p);

    return 0;
}