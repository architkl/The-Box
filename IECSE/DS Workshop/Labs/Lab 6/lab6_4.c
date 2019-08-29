#include <stdio.h>
#include "stack.h"

int main()
{
	int stack_i[max_size], stack_o[max_size], top_i = -1, top_o = -1;

	int ele;
	char ch;
	
	do
	{
		printf("\n\n1. Enter Element\n2. Delete Element\n3. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				push(stack_i, &top_i, ele);
				break;

			case '2':
				if (top_i == -1 && top_o == -1)
					printf("Empty Queue\n");

				else
				{
					if (top_o == -1)
						while (top_i != -1)
							push(stack_o, &top_o, pop(stack_i, &top_i));

					ele = pop(stack_o, &top_o);

					printf("%d Deleted\n", ele);
				}
				break;

			case '3':
				ch = '0';
				break;

			default:
				ch = '3';
		}
	} while (ch != '0');

	return 0;
}