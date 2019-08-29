#include <stdio.h>
#include "stack.h"

int main()
{
	int stack[max_size], top = -1, n, k, inp, del, pops = 0;

	printf("Enter k\n");
	scanf("%d", &k);

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &inp);

		if (pops == k || top == -1)
		{
			push(stack, &top, inp);
			continue;
		}

		while ((peek(stack, top) < inp) && (peek(stack, top) != UF))
		{
			del = pop(stack, &top);
			pops++;

			if (pops == k)
				break;
		}

		push(stack, &top, inp);
	}

	display(stack, top);

	return 0;
}