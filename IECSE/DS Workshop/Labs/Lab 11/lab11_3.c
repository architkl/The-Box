#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *l_child, *r_child;
} *NODE;

NODE create_binary_tree()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    int ele;

    printf("Enter value of node(-1)\n");
    scanf("%d", &ele);

    if (ele == -1)
        return NULL;

    temp->data = ele;

    printf("Going to left child of %d\n", ele);
    temp->l_child = create_binary_tree();

    printf("Going to right child of %d\n", ele);
    temp->r_child = create_binary_tree();

    return temp;
}

void find_in_suc(NODE root, int x)
{
    if (root == NULL)
        return;

    NODE node = root;

    while (node != NULL)
    {
        if (x == node->data)
            break;
        
        else if (x < node->data)
            node = node->l_child;
        
        else
            node = node->r_child;
    }

    if (node == NULL)
    {
        printf("Node doesn't exist\n");
        return;
    }

    NODE in_suc = node->r_child;

    if (in_suc == NULL)
    {
        printf("Inorder Successor doesn't exist\n");
        return;
    }

    while (in_suc->l_child != NULL)
        in_suc = in_suc->l_child;

    printf("Inorder Successor: %d", in_suc->data);
}

int main()
{
    NODE root;

    root = create_binary_tree();

    int x;
    printf("Enter node whose inorder successor is to be found\n");
    scanf("%d", &x);

    find_in_suc(root, x);

    return 0;
}