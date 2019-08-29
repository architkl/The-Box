#include <stdio.h>

#define max_size 10
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

int main()
{
	int stack[max_size], top = -1, ele;
	char ch;

	do
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				push(stack, &top, ele);
				break;
			
			case '2':
				ele = pop(stack, &top);
				if (ele != UF)
					printf("%d\n", ele);
				break;

			case '3':
				display(stack, top);
				break;

			case '4':
				ch = '0';
				break;

			default:
				printf("Enter again\n");
				ch = '4';
		}
	} while (ch != '0');

	return 0;
}