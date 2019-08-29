#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_size 20

typedef struct node
{
	char data[str_size];
	struct node *l_link, *r_link;
} *NODE;

NODE getNode()
{
	NODE x = (NODE)malloc(sizeof(struct node));
	return x;
}

void insert(NODE *f, char str[str_size])
{
	NODE temp = getNode();

	strcpy(temp->data, str);

	if (*f == NULL)
	{
		*f = temp;
		temp->l_link = NULL;
		temp->r_link = NULL;
		return;
	}

	NODE last = *f;
	while (last->r_link != NULL)
		last = last->r_link;

	last->r_link = temp;
	temp->l_link = last;
	temp->r_link = NULL;
}
//create a binary tree using iterative method and display its elements using iterative preorder, postorder and inorder traversal
void display(NODE f)
{
	if (f == NULL)
	{
		printf("Empty List\n");
		return;
	}

	while (f != NULL)
	{
		printf("%s ", f->data);
		f = f->r_link;
	}
}

void reverse(NODE *f)
{
	NODE cur = *f, temp = NULL;
	while (cur->r_link != NULL)
	{
		temp = cur->l_link;
		cur->l_link = cur->r_link;
		cur->r_link = temp;

		cur = cur->l_link;
	}

	temp = cur->l_link;
	cur->l_link = cur->r_link;
	cur->r_link = temp;

	*f = cur;
}

int main()
{
	NODE f = NULL;

	insert(&f, "WORLD");
	insert(&f, "HELLO");
	insert(&f, "JAVA");
	insert(&f, "NO");

	display(f);
	printf("\n\n");

	reverse(&f);

	display(f);

	return 0;
}