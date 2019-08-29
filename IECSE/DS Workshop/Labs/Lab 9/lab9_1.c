#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} *NODE;

void insert(NODE *first, int ele)
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	if (*first == NULL)
	{
		temp->next = temp;
		*first = temp;
		return;
	}

	NODE x = *first;
	while (x->next != *first)
		x = x->next;

	x->next = temp;
	temp->next = *first;
	*first = temp;
}

void delete(NODE *first)
{
	if (*first == NULL)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp = *first;
	if ((*first)->next == *first)
	{
		*first = NULL;
		free(temp);
		return;
	}

	NODE x = *first;
	while (x->next != *first)
		x = x->next;

	*first = (*first)->next;
	x->next = *first;
	free(temp);
}

void display(NODE first)
{
	if (first == NULL)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp = first;
	do
	{
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != first);
	printf("\n\n");
}

int search(NODE l, int ele)
{
	if (l == NULL)
		return 0;

	NODE x = l;
	do
	{
		if (x->data == ele)
			return 1;

		x = x->next;
	} while (x != l);

	return 0;
}

void set_union(NODE l1, NODE l2, NODE *l3)
{
	if (l1 != NULL)
	{
		NODE x = l1;
		do
		{
			insert(l3, x->data);
			x = x->next;
		} while (x != l1);
	}

	NODE x = l2;
	do
	{
		if (search(l1, x->data) == 0)
			insert(l3, x->data);
		x = x->next;
	} while (x != l2);
}

void set_interx(NODE l1, NODE l2, NODE *l3)
{
	if (l1 == NULL || l2 == NULL)
		return;

	NODE x = l1;
	do
	{
		if (search(l2, x->data))
			insert(l3, x->data);
		x = x->next;
	} while (x != l1);
}

int main()
{
	NODE l1 = NULL, l2 = NULL;

	int n, ele;
	printf("Enter no. of elements in first list\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		insert(&l1, ele);
	}

	printf("Enter no. of elements in second list\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		insert(&l2, ele);
	}

	NODE l3 = NULL, l4 = NULL;

	set_union(l1, l2, &l3);
	set_interx(l1, l2, &l4);

	printf("\nUnion: ");
	display(l3);

	printf("Intersection: ");
	display(l4);

	return 0;
}