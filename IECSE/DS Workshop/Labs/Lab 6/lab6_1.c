#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 5
#define str_size 20

void insertcq(char **queue, int *f, int *r, char *ele)
{
	if ((*r + 1) % max_size == *f)
	{
		printf("Queue is full\n");
		return;
	}

	*r = (*r + 1) % max_size;
	strcpy(queue[*r], ele);
}

char* deletecq(char **queue, int *f, int *r)
{
	if (*f == *r)
	{
		printf("Queue is empty\n");
		return "UF";
	}

	*f = (*f + 1) % max_size;
	return queue[*f];
}

void displaycq(char **queue, int f, int r)
{
	if (f == r)
	{
		printf("Queue is empty\n");
		return;
	}

	for (int i = (f+1) % max_size; i != r; i = (i+1) % max_size)
		printf("%s ", queue[i]);
	printf("%s\n", queue[r]);
}

int main()
{
	char **queue = (char **)calloc(max_size, sizeof(char *));
	for (int i = 0; i < max_size; i++)
		queue[i] = (char *)calloc(str_size, sizeof(char));
	
	int f = 0, r = 0;

	char ch, str[str_size];
	do
	{
		printf("1. Insert String\n2. Delete String\n3. Display Queue\n4. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter String\n");
				scanf("%s", str);
				insertcq(queue, &f, &r, str);
				break;

			case '2':
				strcpy(str, deletecq(queue, &f, &r));
				if (strcmp(str, "UF"))
					printf("%s Deleted\n", str);
				break;

			case '3':
				displaycq(queue, f, r);
				break;

			case '4':
				ch = '0';
				break;

			default:
				ch = '4';
		}
	} while (ch != '0');

	for (int i = 0; i < max_size; i++)
		free(queue[i]);

	free(queue);

	return 0;
}