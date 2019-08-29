#include <stdio.h>

#define max_size 20
#define UF 'F'

typedef struct
{
	char str[max_size];
	int f, r;
} dequeue;

void insert_rear(dequeue *dq, char ele)
{
	if (dq->r + 1 == max_size)
	{
		printf("Queue is full\n");
		return;
	}

	if (dq->f == -1)
	{
		dq->f = dq->r = 0;
		dq->str[0] = ele;
		return;
	}

	dq->str[++dq->r] = ele;
}

char delete_front(dequeue *dq)
{
	if (dq->f == -1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	int i = dq->f;
	char temp = dq->str[i];

	while (i < dq->r)
	{
		dq->str[i] = dq->str[i+1];
		i++;
	}

	dq->r--;
	if (dq->r == -1)
		dq->f = -1;

	return temp;
}

char delete_rear(dequeue *dq)
{
	if (dq->f == -1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	char temp = dq->str[dq->r--];
	if (dq->r == -1)
		dq->f = -1;

	return temp;
}

int main()
{
	dequeue dq;
	dq.f = dq.r = -1;
	char str[max_size];

	printf("Enter String\n");
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++)
		insert_rear(&dq, str[i]);

	while (1)
	{
		if (dq.r == 0 || dq.r == -1)
		{
			printf("Pallindrome\n");
			break;
		}

		if (delete_front(&dq) != delete_rear(&dq))
		{
			printf("Not a Pallindrome\n");
			break;
		}
	}

	return 0;
}