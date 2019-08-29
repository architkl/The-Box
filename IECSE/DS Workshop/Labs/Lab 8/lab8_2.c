#include <stdio.h>
#include <stdlib.h>

#define str_size 20
#define UF 'F'

typedef struct node
{
	char data;
	struct node *next;
} *NODE;

void insert(NODE *head, NODE *f, NODE *r, char ele)
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

char delete(NODE *head, NODE *f, NODE *r)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->next;
	(*r)->next = *f;

	char ele = temp->data;
	free(temp);

	(*head)->data--;
	return ele;
}

void display(NODE head, NODE f, NODE r)
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
		printf("%c ", temp->data);
		temp = temp->next;
	} while (temp != f);
	printf("\n");
}

int main()
{
	NODE head[2], f[2], r[2];

	for (int i = 0; i < 2; i++)
	{
		head[i] = (NODE)malloc(sizeof(struct node));
		head[i]->data = 0;
	}

	f[0] = f[1] = r[0] = r[1] = NULL;

	char ch;
	int n;
	printf("Enter no. of characters in first list\n");
	scanf(" %d", &n);


	printf("Enter characters in order\n");
	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &ch);
		insert(&head[0], &f[0], &r[0], ch);
	}

	printf("Enter no. of characters in second list\n");
	scanf(" %d", &n);

	printf("Enter characters in order\n");
	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &ch);
		insert(&head[1], &f[1], &r[1], ch);
	}

	NODE head_f, f_f, r_f;
	head_f = (NODE)malloc(sizeof(struct node));
	head_f->data = 0;
	f_f = r_f = NULL;

	NODE temp1 = f[0], temp2 = f[1];
	int iter1 = 0, iter2 = 0;
	
	while ((iter1 < head[0]->data) && (iter2 < head[1]->data))
	{
		if (temp1->data < temp2->data)
		{
			insert(&head_f, &f_f, &r_f, temp1->data);
			temp1 = temp1->next;
			iter1++;
		}

		else if (temp2->data < temp1->data)
		{
			insert(&head_f, &f_f, &r_f, temp2->data);
			temp2 = temp2->next;
			iter2++;
		}

		else
		{
			insert(&head_f, &f_f, &r_f, temp1->data);
			insert(&head_f, &f_f, &r_f, temp2->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
			iter1++;
			iter2++;	
		}
	}

	while (iter1 < head[0]->data)
	{
		insert(&head_f, &f_f, &r_f, temp1->data);
		temp1 = temp1->next;
		iter1++;
	}

	while (iter2 < head[1]->data)
	{
		insert(&head_f, &f_f, &r_f, temp2->data);
		temp2 = temp2->next;
		iter2++;
	}

	display(head_f, f_f, r_f);

	return 0;
}