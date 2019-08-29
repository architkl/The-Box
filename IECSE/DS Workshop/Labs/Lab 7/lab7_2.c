#include <stdio.h>
#include <string.h>

#define max_size 10
#define str_size 20
#define UF "UF"

typedef struct
{
	char arr[max_size][str_size];
	int f, r;
} dequeue;

void insert_front(dequeue *dq, char *ele)
{
	if (dq->r + 1 == max_size)
	{
		printf("Queue is full\n");
		return;
	}

	if (dq->f == -1)
	{
		dq->f = dq->r = 0;
		strcpy(dq->arr[0], ele);
		return;
	}

	int i = dq->r++;
	while (i >= 0)
	{
		strcpy(dq->arr[i+1], dq->arr[i]);
		i--;
	}

	strcpy(dq->arr[0], ele);
}

void insert_rear(dequeue *dq, char *ele)
{
	if (dq->r + 1 == max_size)
	{
		printf("Queue is full\n");
		return;
	}

	if (dq->f == -1)
	{
		dq->f = dq->r = 0;
		strcpy(dq->arr[0], ele);
		return;
	}

	strcpy(dq->arr[++dq->r], ele);
}

char *delete_front(dequeue *dq, char del[str_size])
{
	if (dq->f == -1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	int i = dq->f;
	strcpy(del, dq->arr[i]);

	while (i < dq->r)
	{
		strcpy(dq->arr[i], dq->arr[i+1]);
		i++;
	}

	dq->r--;
	if (dq->r == -1)
		dq->f = -1;

	return del;
}

void display(dequeue dq)
{
	if (dq.f == -1)
	{
		printf("Queue is empty\n");
		return;
	}

	for (int i = dq.f; i <= dq.r; i++)
		printf("%s ", dq.arr[i]);
	printf("\n");
}

int main()
{
	dequeue dq;
	dq.f = dq.r = -1;

	char ch, ele[str_size];
	do
	{
		printf("1. Insert Element Front\n2. Insert Element Rear\n3. Delete Element Front\n4. Display\n5. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%s", ele);
				insert_front(&dq, ele);
				break;

			case '2':
				printf("Enter element\n");
				scanf("%s", ele);
				insert_rear(&dq, ele);
				break;

			case '3':
				strcpy(ele, delete_front(&dq, ele));

				if (strcmp(ele, UF) != 0)
					printf("%s Deleted\n", ele);
				break;

			case '4':
				display(dq);
				break;

			case '5':
				ch = '0';
				break;

			default:
				ch = '5';
		}
	} while (ch != '0');

	return 0;
}