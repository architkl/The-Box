#include <stdio.h>

#define max_size 100
#define UF -999999

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

int peek(int *stack, int top)
{
	if (top == -1)
		return UF;

	return stack[top];
}

void display(int *stack, int top)
{
	if (top == -1)
	{
		printf("Stack is empty\n");
		return;
	}

	while (top != -1)
	{
		printf("%d ", stack[top]);
		top--;
	}
	printf("\n");
}