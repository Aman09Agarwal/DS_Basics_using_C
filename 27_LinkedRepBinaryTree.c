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

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
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

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct Node *p = createTreeNode(2);
    struct Node *p1 = createTreeNode(1);
    struct Node *p2 = createTreeNode(4);
    struct Node *p3 = createTreeNode(9);
    struct Node *p4 = createTreeNode(11);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // PreOrder Traversal
    printf("PreOrder Traversal \n");
    preOrder(p);
    printf("\n");

    // PostOrder Traversal
    printf("PostOrder Traversal \n");
    postOrder(p);
    printf("\n");

    // InOrder Traversal
    printf("InOrder Traversal \n");
    inOrder(p);
    printf("\n");

    return 0;
}