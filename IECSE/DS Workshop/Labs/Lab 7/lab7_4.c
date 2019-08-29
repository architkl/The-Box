#include <stdio.h>

#define max_size 10
#define UF -999999

typedef struct
{
	int q[max_size];
	int f, r;
} queue;

void enqueue(queue *Q, int ele)
{
	if (Q->r + 1 == max_size)
	{
		printf("Queue is full\n");
		return;
	}

	if (Q->f == -1)
	{
		Q->f = Q->r = 0;
		Q->q[0] = ele;
		return;
	}

	Q->q[++Q->r] = ele;
}

int dequeue(queue *Q)
{
	if (Q->f == -1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	int i = Q->f, temp = Q->q[i];

	while (i < Q->r)
	{
		Q->q[i] = Q->q[i+1];
		i++;
	}

	Q->r--;
	if (Q->r == -1)
		Q->f = -1;

	return temp;
}

int empty(queue Q)
{
	return (Q.f == -1) ? 1 : 0;
}

void reverse(queue *O, queue *T1, queue *T2, int n, int f)
{
	if (n == 0)
	{
		(f == 1) ? enqueue(O, dequeue(T2)) : enqueue(O, dequeue(T1));
		return;
	}

	if (f == 1)
	{
		for (int i = 0; i < n; i++)
			enqueue(T1, dequeue(T2));

		enqueue(O, dequeue(T2));
	}

	else
	{
		for (int i = 0; i < n; i++)
			enqueue(T2, dequeue(T1));

		enqueue(O, dequeue(T1));
	}

	reverse(O, T1, T2, n-1, f*(-1));
}

int main()
{
	queue O, T1, T2;
	O.f = O.r = T1.f = T1.r = T2.f = T2.r = -1;
	int n, temp;

	printf("Enter no. of elements\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		enqueue(&O, temp);
	}

	if (n > 1)
	{
		for (int i = 0; i < n-1; i++)
			enqueue(&T1, dequeue(&O));

		reverse(&O, &T1, &T2, n-2, -1);
	}

	while (!empty(O))
		printf("%d ", dequeue(&O));
	printf("\n");

	return 0;
}