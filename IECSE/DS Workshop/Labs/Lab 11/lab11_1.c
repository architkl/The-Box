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

NODE deleteNode(NODE root,  int x)
{
    if (root == NULL)
        return NULL;
    
    NODE node_del = root, par_del = NULL, in_suc, par_suc;
    while (node_del != NULL)
    {
        if (x == node_del->data)
            break;
        
        par_del = node_del;
        
        if (x < node_del->data)
            node_del = node_del->l_child;
        
        else
            node_del = node_del->r_child;
    }
    
    if (node_del == NULL)
        return root;
    
    if (node_del->r_child == NULL)
        in_suc = node_del->l_child;
    
    else if (node_del->l_child == NULL)
        in_suc = node_del->r_child;
    
    else
    {
        in_suc = node_del->r_child;
        par_suc = node_del;
        
        while (in_suc->l_child != NULL)
        {
            par_suc = in_suc;
            in_suc = in_suc->l_child;
        }
        
        if (in_suc != node_del->r_child)
        {
            par_suc->l_child = in_suc->r_child;
            in_suc->r_child = node_del->r_child;
        }
        
        in_suc->l_child = node_del->l_child;
    }

    if (node_del == root)
    {
        free(node_del);
        return in_suc;
    }
    
    if (node_del->data < par_del->data)
        par_del->l_child = in_suc;
    
    else
        par_del->r_child = in_suc;

    free(node_del);
    
    return root;
}

void level_order(NODE root)
{
    NODE queue[50];
    int f = 0, r = 1;
    queue[f] = root;

    while (f != r)
    {
        if (queue[f]->l_child != NULL)
            queue[r++] = queue[f]->l_child;

        if (queue[f]->r_child != NULL)
            queue[r++] = queue[f]->r_child;

        f++;
    }

    for (int i = 0; i < r; i++)
        printf("%d ", queue[i]->data);
}

int main()
{
    NODE root;
    int ch, ele;

    do
    {
        printf("1. Create BST\n2. Delete element\n3. Level Order Traversal\n4. Exit\n\n");

        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                root = create_binary_tree();
                break;

            case 2:
                printf("Enter element to be deleted\n");
                scanf("%d", &ele);
                root = deleteNode(root, ele);
                break;

            case 3:
                level_order(root);
                printf("\n");
                break;

            case 4:
                ch = -1;
                break;

            default:
                ch = 4;
        }
    } while (ch != -1);

    return 0;
}