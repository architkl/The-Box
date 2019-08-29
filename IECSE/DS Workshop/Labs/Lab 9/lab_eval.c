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

void display(queue Q)
{
	if (Q.f == -1)
	{
		printf("Queue is empty\n");
		return;
	}

	for (int i = Q.f; i <= Q.r; i++)
		printf("%d ", Q.q[i]);
}

void push(int *stack, int *top, int ele)
{
	if (*top == max_size - 1)
	{
		printf("Stack Overflow\n");
		return;
	}

	stack[++(*top)] = ele;
}

int pop(int *stack, int *top)
{
	if (*top == -1)
	{
		printf("Stack Underflow\n");
		return UF;
	}

	return stack[(*top)--];
}

void reverse(queue *O, int n, int k)
{
	queue T;
	T.f = T.r = -1;

	int stack[max_size], top = -1;

	for (int i = 0; i < k; i++)
		push(stack, &top, dequeue(O));

	for (int i = k; i < n; i++)
		enqueue(&T, dequeue(O));

	for (int i = 0; i < k; i++)
		enqueue(O, pop(stack, &top));

	for (int i = k; i < n; i++)
		enqueue(O, dequeue(&T));
}

int main()
{
	queue O;
	O.f = O.r = -1;

	int n, k, ele;
	printf("Enter n, k\n");
	scanf("%d %d", &n, &k);

	printf("Enter %d elements\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ele);
		enqueue(&O, ele);
	}

	reverse(&O, n, k);

	display(O);

	return 0;
}