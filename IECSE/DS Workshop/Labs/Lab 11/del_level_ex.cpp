Tree *deleteNode(Tree *root,  int x)
{
    if (root == NULL)
        return NULL;
    
    Tree *node_del = root, *par_del = NULL, *in_suc, *par_suc;
    // search
    while (node_del != NULL)
    {
        if (node_del->data == x)
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
        delete node_del;
        return in_suc;
    }
    
    if (node_del->data < par_del->data)
        par_del->l_child = in_suc;
    
    else
        par_del->r_child = in_suc;

    delete node_del;
    
    return root;
}

void level_order(Tree *root)
{
    Tree *queue[50];
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

int height(Tree *root)
{
    if (root == NULL)
        return 0;

    return (1 + max(height(root->l_child, root->r_child)));
}

Tree *exp_tree(char post[])
{
    Tree *temp, stack[50];
    int i, top = -1;

    for (i = 0; post[i] != '\0'; i++)
    {
        temp = new Tree;
        temp->l_child = temp->r_child = NULL;

        if (isalnum(post[i]))
            stack[++top] = temp;

        else
        {
            temp->r_child = stack[top--];
            temp->l_child = stack[top--];
            stack[++top] = temp;
        }
    }

    return stack[0];
}

int eval_post(Tree *root)
{
    if (root == NULL)
        return -1;

    switch (root->data)
    {
        case '+':
            return eval_post(root->l_child) +
                eval_post(root->r_child);
                break;

        case '-':
            return eval_post(root->l_child) -
                eval_post(root->r_child);
                break;

        case '*':
            return eval_post(root->l_child) *
                eval_post(root->r_child);
                break;

        case '/':
            return eval_post(root->l_child) /
                eval_post(root->r_child);
                break;

        default:
            return (root->data - '0');
    }
}