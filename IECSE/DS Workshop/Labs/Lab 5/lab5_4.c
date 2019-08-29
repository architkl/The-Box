#include <stdio.h>
#include <string.h>
#include "stack.h"

int is_open_para(char ch)
{
	switch (ch)
	{
		case '(':
		case '{':
		case '[':
			return 1;
	}
	return 0;
}

int main()
{
	int stack[20], top = -1;
	char expression[50];

	printf("Enter expression\n");
	scanf("%s", expression);

	int len = strlen(expression), temp;
	for (int i = 0; i < len; i++)
	{
		if (is_open_para(expression[i]))
			push(stack, &top, expression[i]);

		else if((expression[i] == ')' && stack[top] == '(') ||
				(expression[i] == '}' && stack[top] == '{') ||
				(expression[i] == ']' && stack[top] == '['))
			temp = pop(stack, &top);
	}

	if (top != -1)
		printf("Unbalanced\n");

	else
		printf("Balanced\n");

	return 0;
}