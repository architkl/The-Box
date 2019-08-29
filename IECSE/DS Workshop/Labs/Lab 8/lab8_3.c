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

void delete(NODE *head, NODE *f, NODE *r)
{
	if ((*head)->data == 0)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp1 = *f, temp2;
	while (temp1->next != NULL)
	{
		while ((temp1->next != NULL) && (temp1->data == (temp1->next)->data))
		{
			temp2 = temp1->next;
			temp1->next = temp2->next;
			free(temp2);
			(*head)->data--;
		}

		if (temp1->next == NULL)
			break;
		
		temp1 = temp1->next;
	}

	*r = temp1;
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

	int n, ele;

	printf("Enter no. of nodes\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		insert(&head, &f, &r, ele);
	}

	delete(&head, &f, &r);

	display(head, f, r);

	return 0;
}