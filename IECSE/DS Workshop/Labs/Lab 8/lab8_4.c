#include <stdio.h>
#include <stdlib.h>

#define UF -999999

typedef struct node
{
	char data;
	struct node *next;
} *NODE;

void insert(NODE *head, NODE *f, NODE *r, int ele)
{
	NODE temp = (NODE)malloc(sizeof(struct node));

	temp->data = ele;
	temp->next = NULL;

	if ((*head)->data == 0)
	{
		*f = temp;
		*r = temp;
		temp->next = *f;
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	temp->next = *f;
	(*r)->next = temp;
	*r = temp;
	(*head)->data++;
}

int delete(NODE *head, NODE *f, NODE *r, NODE *exe)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp1 = *f;
	while (temp1->next != *exe)
		temp1 = temp1->next;

	NODE temp2 = temp1->next;
	temp1->next = temp2->next;

	int ele = temp2->data;
	free(temp2);
	*exe = temp1->next;
	(*head)->data--;
	return ele;
}

/*void display(NODE head, NODE f, NODE r)
{
	printf("Nodes: %d\n", head->data);
	if (head->data == 0)
	{
		printf("List is empty\n");
		return;
	}

	NODE temp = f;
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != f);
	printf("\n");
}*/

int main()
{
	NODE head = (NODE)malloc(sizeof(struct node)), f, r;
	head->data = 0;
	head->next = NULL;
	f = r = NULL;

	int n, m;

	printf("Enter no. of people\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		insert(&head, &f, &r, i+1);

	printf("Enter value of m\n");
	scanf("%d", &m);

	NODE temp = f;
	int p;
	while (head->data != 1)
	{
		for (int i = 1; i < m; i++)
			temp = temp->next;

		p = delete(&head, &f, &r, &temp);
		printf("Person %d Executed\n", p);
	}

	printf("Person %d is free\n", temp->data);

	return 0;
}