#include <stdio.h>

#define max_size 50
#define UF -999999

void ADD(int *stack, int *next, int *top, int stack_top, int i, int X)
{
	if (stack_top == max_size - 1)
	{
		printf("Overflow\n");
		return;
	}

	stack_top++;
	next[stack_top+1] = top[i];
	top[i] = stack_top;
	stack[top[i]] = X;
}

int DELETE(int *stack, int *next, int *top, int i)
{
	if (top[i] == -1)
	{
		printf("Underflow\n");
		return UF;
	}

	int temp = top[i];
	top[i] = next[stack[top[i]]];

	return temp;
}

int main()
{
	int stack[max_size], next[max_size], top[max_size+1], stack_top = -1, n, s, X;
	char ch;

	printf("Enter number of stacks\n");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		top[i] = -1;

	do
	{
		printf("1. ADD(i, X)\n2. DELETE(i)\n3. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("i X\n");
				scanf("%d %d", &s, &X);
				ADD(stack, next, top, stack_top, s, X);
				break;

			case '2':
				printf("i\n");
				scanf("%d", &s);
				printf("%d\n", DELETE(stack, next, top, s));
				break;
		}
	} while(ch != '3');

	return 0;
}