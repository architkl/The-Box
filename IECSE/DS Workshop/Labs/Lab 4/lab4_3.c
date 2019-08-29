#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	int stack[max_size], top = -1;
	char str[50];

	printf("Enter String\n");
	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len/2; i++)
		push(stack, &top, str[i]);

	int counter = len/2 + (len % 2), pall = 1;
	while (counter < len)
	{
		if (pop(stack, &top) != str[counter])
		{
			pall = 0;
			break;
		}
		
		counter++;
	}
	
	if (pall)
		printf("It is a pallindrome\n");

	else
		printf("It is not a pallindrome\n");

	return 0;
}