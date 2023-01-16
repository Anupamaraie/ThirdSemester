// BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insertion operation
Node *insert(Node *nd, int data)
{
    if (nd == NULL)
        return createNode(data);
    if (data < nd->item)
        nd->left = insert(nd->left, data);
    else if (data > nd->item)
        nd->right = insert(nd->right, data);
    return nd;
}

// Required for deletion operation
// Find the inorder successor
Node *minValueNode(Node *node)
{
    Node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
// Deletion operation
Node *deleteNode(Node *root, int item)
{

    // return if tree is empty
    if (root == NULL)
        return root;

    // find the node to be deleted
    if (item < root->item)
        root->left = deleteNode(root->left, item);
    else if (item > root->item)
        root->right = deleteNode(root->right, item);

    // deleting the node
    else
    {

        // If the root has only one child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children

        Node *temp = minValueNode(root->right);

        // place the inorder successor in position of the node to be deleted
        root->item = temp->item;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}
// Inorder Traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d -> ", root->item);

        // Traverse right
        inorder(root->right);
    }
}

// Search operation
int search(Node *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (value == root->item)
    {
        printf("Found");
        return root->item;
    }

    else if (value < root->item)
        return search(root->left, value);
    else if (value > root->item)
        return search(root->right, value);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 1);
    printf("Inorder traversal: ");
    inorder(root);

    int item = search(root, 6);
}