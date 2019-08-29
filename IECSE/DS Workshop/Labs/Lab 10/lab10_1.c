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

void preorder(NODE root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	preorder(root->l_child);
	preorder(root->r_child);
}

void postorder(NODE root)
{
	if (root == NULL)
		return;

	postorder(root->l_child);
	postorder(root->r_child);
	printf("%d ", root->data);
}

void inorder(NODE root)
{
	if (root == NULL)
		return;
	
	NODE stack[50];
	int top = -1;

	while (1)
	{
		for (; root != NULL; root = root->l_child)
			stack[++top] = root;

		if (top != -1)
		{		
			root = stack[top--];
			printf("%d ", root->data);

			root = root->r_child;
		}

		else
			return;
	}
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