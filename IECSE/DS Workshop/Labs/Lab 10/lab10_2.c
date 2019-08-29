#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *l_child, *r_child;
} *NODE;

NODE getNode()
{
	NODE x = malloc(sizeof(struct node));
	return x;
}

NODE create_binary_tree()
{
	NODE root = getNode(), parent, child, stack[50];
	int ele, top = -1;

	printf("Enter value of node(-1)\n");
	scanf("%d", &ele);

	if (ele == -1)
		return NULL;

	root->data = ele;
	stack[++top] = root;

	while (1)
	{
		printf("Enter left child of %d\n", stack[top]->data);
		scanf("%d", &ele);

		if (ele == -1)
			stack[top]->l_child = NULL;

		else
		{
			child = getNode();
			child->data = ele;
			stack[top]->l_child = child;
		}

		printf("Enter right child of %d\n", stack[top]->data);
		scanf("%d", &ele);

		if (ele == -1)
			stack[top]->r_child = NULL;

		else
		{
			child = getNode();
			child->data = ele;
			stack[top]->r_child = child;
		}

		parent = stack[top--];
		if (parent->l_child != NULL)
			stack[++top] = parent->l_child;

		if (parent->r_child != NULL)
			stack[++top] = parent->r_child;

		if (top == -1)
			return root;
	}
}

void preorder(NODE root)
{
	if (root == NULL)
		return;

	NODE stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
		{
			printf("%d ", root->data);
			stack[++top] = root;
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

	struct treenode
	{
		NODE addr;
		int flag;
	};

	struct treenode stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
		{
			stack[++top].addr = root;
			stack[top].flag = 1;
		}

		while (stack[top].flag == 2)
		{
			root = stack[top--].addr;
			printf("%d ", root->data);
		}

		if (top == -1)
			return;

		root = stack[top].addr;
		stack[top].flag = 2;
		root = root->r_child;
	}
}

void inorder(NODE root)
{
	if (root == NULL)
		return;
	
	inorder(root->l_child);
	printf("%d ", root->data);
	inorder(root->r_child);
}

int main()
{
	NODE root;

	root = create_binary_tree();

	preorder(root);
	printf("\n\n");
	postorder(root);
	printf("\n\n");
	inorder(root);

	return 0;
}