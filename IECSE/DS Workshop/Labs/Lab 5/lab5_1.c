#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

#define OPERATOR 1
#define OPERAND 2

int type(char x)
{
	switch (x)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			return OPERATOR;
	}

	return OPERAND;
}

int operation(int b, int a, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
		case '%':
			return (a % b);
		case '^':
			return pow(a, b);
	}
}

int main()
{
	char expression[50];

	printf("Enter prefix expression\n");
	scanf("%s", expression);
	
	char ch;
	int len = strlen(expression);

	int stack[50], top = -1;

	for (int i = len-1; i >= 0; i--)
	{
		ch = expression[i];

		if (type(ch) == OPERAND)
			push(stack, &top, ch - 48);
		
		else
			push(stack, &top, operation(pop(stack, &top), pop(stack, &top), ch));
	}

	printf("%d\n", pop(stack, &top));

	return 0;
}