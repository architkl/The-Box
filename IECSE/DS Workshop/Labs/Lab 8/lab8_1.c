#include <stdio.h>
#include <stdlib.h>

#define UF -999999

typedef struct node
{
	int data;
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
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	(*r)->next = temp;
	(*r) = temp;
	(*head)->data++;
}

int delete(NODE *head, NODE *f, NODE *r)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->next;

	int ele = temp->data;
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
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	NODE head = (NODE)malloc(sizeof(struct node)), f, r;
	head->data = 0;
	head->next = NULL;
	f = r = NULL;

	char ch;
	int ele;
	do
	{
		printf("1. Insert Node\n2. Delete Node\n3. Display\n4. Exit\n\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				insert(&head, &f, &r, ele);
				break;

			case '2':
				ele = delete(&head, &f, &r);
				if (ele != UF)
					printf("%d Deleted\n", ele);
				break;

			case '3':
				display(head, f, r);
				break;

			case '4':
				ch = '0';
				break;

			default:
				ch = '4';
		}
	} while (ch != '0');

	return 0;
}