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

int checkBST(NODE root, NODE l, NODE r)
{
	if (root == NULL)
		return 1;

	if (l != NULL && root->data < l->data)
		return 0;

	if (r != NULL && root->data > r->data)
		return 0;

	return checkBST(root->l_child, l, root) 
		& checkBST(root->r_child, root, r);
}

int main()
{
	NODE root;

	root = create_binary_tree();

	if (checkBST(root, NULL, NULL))
		printf("It is a BST\n");

	else
		printf("It is not a BST\n");

	return 0;
}