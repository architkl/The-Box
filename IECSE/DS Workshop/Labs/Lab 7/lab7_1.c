#include <stdio.h>

#define max_size 10
#define UF -999999

typedef struct
{
	int pq[max_size];
	int f, r;
} priority_queue;

void pqinsert(priority_queue *PQ, int ele)
{
	if (PQ->r + 1 == max_size)
	{
		printf("Queue is full\n");
		return;
	}

	if(PQ->f == -1)
	{
		PQ->f = PQ->r = 0;
		PQ->pq[0] = ele;
		return;
	}

	int i = PQ->r++;
	while (PQ->pq[i] > ele && i >= 0)
	{
		PQ->pq[i+1] = PQ->pq[i];
		i--;
	}

	PQ->pq[i+1] = ele;
}

int pqdelete(priority_queue *PQ)
{
	if (PQ->f == -1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	int temp = PQ->pq[PQ->f], i = PQ->f;
	while (i < PQ->r)
	{
		PQ->pq[i] = PQ->pq[i+1];
		i++;
	}

	PQ->r--;
	
	if (PQ->r == -1)
		PQ->f = -1;

	return temp;
}

void display(priority_queue PQ)
{
	if (PQ.f == -1)
	{
		printf("Queue is empty\n");
		return;
	}

	for (int i = PQ.f; i <= PQ.r; i++)
		printf("%d ", PQ.pq[i]);
	printf("\n");
}

int main()
{
	priority_queue PQ;
	PQ.f = PQ.r = -1;

	char ch;
	int ele;
	do
	{
		printf("1. Insert Element\n2. Delete Min Element\n3. Display\n4. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				pqinsert(&PQ, ele);
				break;

			case '2':
				ele = pqdelete(&PQ);

				if (ele != UF)
					printf("%d Deleted\n", ele);
				break;

			case '3':
				display(PQ);
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