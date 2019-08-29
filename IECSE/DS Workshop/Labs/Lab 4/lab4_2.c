#include <stdio.h>
#include "stack.h"

int main()
{
	int stack[max_size], top = -1, n;

	printf("Enter decimal number\n");
	scanf("%d", &n);

	while (n != 0)
	{
		push(stack, &top, n % 2);
		n /= 2;
	}

	display(stack, top);

	return 0;
}