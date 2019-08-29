#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coeff, exp;
	struct node *next;
} *NODE;

void insert(NODE *head, NODE *first, int c, int e)
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->coeff = c;
	temp->exp = e;
	temp->next = (*head)->next;

	(*head)->next = temp;
	(*head)->coeff++;
	*first = temp;
}

void delete(NODE *head, NODE *first)
{
	if ((*head)->coeff == 0)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp = *first;
	*first = (*first)->next;
	(*head)->next = *first;
	(*head)->coeff--;

	free(temp);
}

void display(NODE head, NODE first)
{
	if (head->coeff == 0)
	{
		printf("Empty List\n");
		return;
	}

	while (first != head)
	{
		printf("%dx^%d ", first->coeff, first->exp);
		first = first->next;
	}
	printf("\n\n");
}

void subtract(NODE *P3, NODE *f3, NODE P1, NODE f1, NODE P2, NODE f2)
{
	if (f1 == NULL || f2 == NULL)
		return;

	while (f1 != P1 && f2 != P2)
	{
		if (f1->exp > f2->exp)
		{
			insert(P3, f3, f1->coeff, f1->exp);
			f1 = f1->next;
		}

		else if (f2->exp > f1->exp)
		{
			insert(P3, f3, f2->coeff, f2->exp);
			f2 = f2->next;
		}

		else
		{
			int res = f1->coeff - f2->coeff;

			if (res == 0)
			{
				f1 = f1->next;
				f2 = f2->next;
				continue;
			}

			insert(P3, f3, res, f1->exp);
			f1 = f1->next;
			f2 = f2->next;
		}
	}

	while (f1 != P1)
	{
		insert(P3, f3, f1->coeff, f1->exp);
		f1 = f1->next;
	}

	while (f2 != P2)
	{
		insert(P3, f3, f2->coeff, f2->exp);
		f2 = f2->next;
	}
}

int search(NODE head, NODE f, int ele)
{
	if (head->coeff == 0)
		return 0;

	NODE x = f;
	while (x != head)
	{
		if (x->exp == ele)
			return 1;

		x = x->next;
	}

	return 0;
}

void multiply(NODE *P3, NODE *f3, NODE P1, NODE f1, NODE P2, NODE f2)
{
	if (f1 == NULL || f2 == NULL)
		return;

	while (f1 != P1)
	{
		NODE temp = f2;

		while (temp != P2)
		{
			int res_ex = f1->exp + temp->exp, res_cf = f1->coeff * temp->coeff;

			if (search(*P3, *f3, res_ex))
			{
				NODE x = *f3;
				while (x->exp != res_ex)
					x = x->next;
				x->coeff += res_cf; 
			}

			else
				insert(P3, f3, res_cf, res_ex);

			temp = temp->next;
		}

		f1 = f1->next;
	}
}

int main()
{
	NODE P1 = (NODE)malloc(sizeof(struct node)), P2 = (NODE)malloc(sizeof(struct node)), P1_f = NULL, P2_f = NULL;
	P1->next = P1;
	P2->next = P2;
	P1->coeff = P2->coeff = 0;

	int n, c, e;
	printf("Enter no. of elements in first polynomial\n");
	scanf("%d", &n);

	printf("Enter coefficient and exponent\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &e);
		insert(&P1, &P1_f, c, e);
	}

	printf("Enter no. of elements in second list\n");
	scanf("%d", &n);

	printf("Enter coefficient and exponent\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &e);
		insert(&P2, &P2_f, c, e);
	}

	NODE P3 = (NODE)malloc(sizeof(struct node)), P3_f = NULL;
	P3->next = P3;
	P3->coeff = 0;

	display(P1, P1_f);
	display(P2, P2_f);

	subtract(&P3, &P3_f, P1, P1_f, P2, P2_f);

	display(P3, P3_f);

	NODE P4 = (NODE)malloc(sizeof(struct node)), P4_f = NULL;
	P4->next = P4;
	P4->coeff = 0;

	multiply(&P4, &P4_f, P1, P1_f, P2, P2_f);

	display(P4, P4_f);

	return 0;
}