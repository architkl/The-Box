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

int ancestor(NODE root, int x)
{
    if (root == NULL)
        return 0;

    if (root->data == x)
        return 1;

    if (ancestor(root->l_child, x) || ancestor(root->r_child, x))
    {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int main()
{
    NODE root = create_binary_tree();
    int x;
    
    printf("Enter value of node\n");
    scanf("%d", &x);

    if (ancestor(root, x) == 0)
        printf("Ancestor does not exist\n");

    return 0;
}