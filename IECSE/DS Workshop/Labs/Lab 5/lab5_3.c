#include <stdio.h>

#define size 10
#define UF -999999

void push(int *stack, int *top1, int *top2, int ele, int num)
{
	if (*top1 + 1 == *top2)
	{
		printf("Stack Overflow\n");
		return;
	}

	if (num == 1)
		stack[++(*top1)] = ele;
	
	else
		stack[--(*top2)] = ele;
}

int pop(int *stack, int *top, int num)
{
	if ((num == 1 && *top == -1) || (num == 2 && *top == size))
	{
		printf("Stack is empty\n");
		return UF;
	}

	if (num == 1)
		return stack[(*top)--];

	return stack[(*top)++];
}

void display(int *stack, int top, int num)
{
	if ((num == 1 && top == -1) || (num == 2 && top == size))
	{
		printf("Stack is empty\n");
		return;
	}

	if (num == 1)
	{
		while (top != -1)
		{
			printf("%d ", stack[top]);
			top--;
		}
	}

	else
	{
		while (top != size)
		{
			printf("%d ", stack[top]);
			top++;
		}
	}
}

int main()
{
	int stack[size], top1, top2;
	top1 = -1;
	top2 = size;

	int ele;
	char ch;
	do
	{
		printf("\n\n1. Push to Stack 1\n2. Push to Stack 2\n3. Pop from Stack 1\n4. Pop from Stack 2\n5. Display Stack 1\n6. Display Stack 2\n7. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				push(stack, &top1, &top2, ele, 1);
				break;
			
			case '2':
				printf("Enter element\n");
				scanf("%d", &ele);
				push(stack, &top1, &top2, ele, 2);
				break;

			case '3':
				ele = pop(stack, &top1, 1);
				if (ele != UF)
					printf("%d Popped\n", ele);
				break;

			case '4':
				ele = pop(stack, &top2,2);
				if (ele != UF)
					printf("%d Popped\n", ele);
				break;

			case '5':
				display(stack, top1, 1);
				break;

			case '6':
				display(stack, top2, 2);
				break;

			case '7':
				ch = '0';
				break;

			default:
				ch = '7';
		}
	} while (ch != '0');

	return 0;
}