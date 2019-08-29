#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *l_link, *r_link;
} *NODE;

NODE getNode()
{
	NODE x = (NODE)malloc(sizeof(struct node));
	return x;
}

void insert(NODE *head, NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	(*head)->data++;
	((*head)->l_link)->r_link = temp;
	temp->l_link = (*head)->l_link;
	(*head)->l_link = temp;
	temp->r_link = *head;

	if (*f == NULL)
		*f = temp;
}

void display(NODE head)
{
	if (head->data == 0)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp = head->l_link;

	while (temp != head)
	{
		printf("%d", temp->data);
		temp = temp->l_link;
	}
	printf("\n");
}

void add(NODE *H3, NODE *f, NODE H2, NODE H1)
{
	NODE t1 = H1->l_link, t2 = H2->l_link;
	int res, carry = 0;

	while (t1 != H1 && t2 != H2)
	{
		res = t1->data + t2->data + carry;
		//printf("%d + %d + %d = %d\n", t1->data, t2->data, carry, res);
		carry = res / 10;
		res = res % 10;

		insert(H3, f, res);

		t1 = t1->l_link;
		t2 = t2->l_link;
	}

	while (t1 != H1)
	{
		res = t1->data + carry;
		//printf("%d + %d = %d\n", t1->data, carry, res);
		carry = res / 10;
		res = res % 10;

		insert(H3, f, res);

		t1 = t1->l_link;
	}

	while (t2 != H2)
	{
		res = t2->data + carry;
		//printf("%d + %d = %d\n", t2->data, carry, res);
		carry = res / 10;
		res = res % 10;

		insert(H3, f, res);

		t2 = t2->l_link;
	}
}

int main()
{
	NODE head1 = getNode(), head2 = getNode(), f1, f2;
	
	head1->data = 0;
	head1->l_link = head1;
	head1->r_link = head1;

	head2->data = 0;
	head2->l_link = head2;
	head2->r_link = head2;

	f1 = f2 = NULL;

	char num1[20], num2[20];

	printf("Enter first number\n");
	scanf("%s", num1);

	printf("Enter second number\n");
	scanf("%s", num2);

	for (int i = 0; i < strlen(num1); i++)
		insert(&head1, &f1, (int)(num1[i])-48);

	for (int i = 0; i < strlen(num2); i++)
		insert(&head2, &f2, (int)(num2[i])-48);

	NODE head3 = getNode(), f3;
	head3->data = 0;
	head3->l_link = head3;
	head3->r_link = head3;

	f3 = NULL;

	add(&head3, &f3, head1, head2);

	display(head3);

	return 0;
}