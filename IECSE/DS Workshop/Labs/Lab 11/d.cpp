class Tree
{
	public:
	int data;
	Tree *llink, *rlink;
};

Tree *root = NULL;

Tree *create_binary_tree()
{
	int ele;

	cout << "Enter Node(-1)\n";
	cin >> ele

	Tree *temp = new Tree;

	if (ele == -1)
		return NULL;

	temp->data = ele;

	cout << "Going to left child of " << ele << "\n";
	temp->l_child = create_binary_tree();

	cout << "Going to right child of " << ele << "\n"
	temp->r_child = create_binary_tree();

	return temp;
}

void rec_inorder(Tree *root)
{
	if (root == NULL)
		return;

	rec_inorder(root->llink);
	cout << root->data << " ";
	rec_inorder(root->rlink);
}

void rec_preorder(Tree *root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	rec_inorder(root->llink);
	rec_inorder(root->rlink);
}

void rec_postorder(Tree *root)
{
	if (root == NULL)
		return;

	rec_inorder(root->llink);
	rec_inorder(root->rlink);
	cout << root->data << " ";
}

void inorder(Tree *root)
{
	if (root == NULL)
		return;
	
	Tree *stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
			stack[++top] = root;

		if (top != -1)
		{
			root = stack[top--];		
			cout << root->data << " ";

			root = root->r_child;
		}

		else
			return;
	}
}

void preorder(Tree *root)
{
	if (root == NULL)
		return;

	Tree *stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
		{
			stack[++top] = root;
			cout << root->data << " ";
		}

		if (top != -1)
		{
			root = stack[top--];
			root = root->r_child;
		}

		else
			return;
	}
}

void postorder(NODE root)
{
	if (root == NULL)
		return;

	class treenode
	{
		tree *addr;
		int flag;
	};

	treenode stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
		{
			stack[++top].addr = root;
			stack[top].flag = 1;
		}

		while (top != -1 && stack[top].flag == 2)
		{
			root = stack[top--].addr;
			cout << root->data << " ";
		}

		if (top == -1)
			return;

		root = stack[top].addr;
		stack[top].flag = 2;
		root = root->r_child;
	}
}

void insert(Tree *root, int ele)
{
	Tree *node = new Tree;

	node->data = ele;

	if (root == NULL)
		root = node;

	Node *cur = root, *par = NULL;
	while (cur != NULL)
	{
		par = cur;

		if (ele < cur->data)
			cur = cur->l_child;

		else if (ele > cur->data)
			cur = cur->r_child;
	}

	if (ele < par->data)
		par->l_child = node;

	else
		par->r_child = node;
}