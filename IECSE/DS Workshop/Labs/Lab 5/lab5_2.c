#include <stdio.h>
#include <string.h>
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

int priority(char op)
{
	switch (op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '%':
			return 3;
		case '^':
			return 4;
		case '(':
		case ')':
			return 0;
	}
}

int main()
{
	char expression[50];

	printf("Enter infix expression\n");
	scanf("%s", expression);

	int len = strlen(expression);
	int stack[50], top = -1;
	char prefix[50] = "", plen = 0, temp;

	for (int i = len-1; i >= 0; i--)
	{
		if (expression[i] == ')')
			push(stack, &top, expression[i]);

		else if (expression[i] == '(')
		{
			while (stack[top] != ')')
				//strcat(prefix, (char *)(pop(stack, &top)));
				prefix[plen++] = (char)(pop(stack, &top));
			temp = (char)(pop(stack, &top));
		}

		else if (type(expression[i]) == OPERAND)
			prefix[plen++] = expression[i];
			//strcat(prefix, expression[i]);

		else
		{
			if (top == -1)
				push(stack, &top, expression[i]);

			else
			{
				while (top != -1 && priority(expression[i]) <= priority(stack[top]))
					//strcat(prefix, (char *)(pop(stack, &top)));
					prefix[plen++] = (char)(pop(stack, &top));
				
				push(stack, &top, expression[i]);
			}
		}
	}

	while (top != -1)
		prefix[plen++] = (char)(pop(stack, &top));

	printf("Prefix Expression: ");
	for (int i = plen-1; i >= 0; i--)
		printf("%c", prefix[i]);

	return 0;
}