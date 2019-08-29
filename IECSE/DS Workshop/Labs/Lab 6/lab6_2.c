#include <stdio.h>

#define max_size 8
#define UF -999999

void insert_1(int *queue, int *f1, int *r1, int ele)
{
	if ((*r1 + 1) % (max_size/2) == *f1)
	{
		printf("Queue is full\n");
		return;
	}

	*r1 = (*r1 + 1) % (max_size / 2);
	queue[*r1] = ele;
}

void insert_2(int *queue, int *f2, int *r2, int ele)
{
	int temp = *r2 - 1;
	if (temp < max_size/2)
		temp += max_size/2 + (max_size % 2);

	if (temp == *f2)
	{
		printf("Queue is full\n");
		return;
	}

	*r2 = temp;
	queue[*r2] = ele;
}

int delete_1(int *queue, int *f1, int *r1)
{
	if (*f1 == *r1)
	{
		printf("Queue is empty\n");
		return UF;
	}

	*f1 = (*f1 + 1) % (max_size/2);
	return queue[*f1];
}

int delete_2(int *queue, int *f2, int *r2)
{
	if (*f2 == *r2)
	{
		printf("Queue is empty\n");
		return UF;
	}

	int temp = *f2 - 1;
	if (temp < max_size/2)
		temp += max_size/2 + (max_size % 2);

	*f2 = temp;
	return queue[*f2];
}

void display_1(int *queue, int f1, int r1)
{
	if (f1 == r1)
	{
		printf("Queue is empty\n");
		return;
	}

	for (int i = (f1 + 1) % (max_size/2); i != r1; i = (i+1) % (max_size/2))
		printf("%d ", queue[i]);
	printf("%d\n", queue[r1]);
}

void display_2(int *queue, int f2, int r2)
{
	if (f2 == r2)
	{
		printf("Queue is empty\n");
		return;
	}

	int i = f2 - 1;
	if (i < max_size/2)
		i += max_size/2 + (max_size % 2);

	while (i != r2)
	{
		printf("%d ", queue[i]);

		i--;
		if (i < max_size/2)
			i += max_size/2 + (max_size % 2);
	}
	printf("%d\n", queue[r2]);
}


int main()
{
	int queue[max_size], f1, r1, f2, r2;
	f1 = r1 = 0;
	f2 = r2 = max_size-1;

	char ch;
	int ele;

	do
	{
		printf("1. Insert in Queue 1\n2. Insert in Queue 2\n3. Delete from Queue 1\n4. Delete from Queue 2\n5. Display Queue 1\n6. Display Queue 2\n7. Exit\n");
		scanf(" %c", &ch);

		switch (ch)
		{
			case '1':
				printf("Enter element\n");
				scanf("%d", &ele);
				insert_1(queue, &f1, &r1, ele);
				break;

			case '2':
				printf("Enter element\n");
				scanf("%d", &ele);
				insert_2(queue, &f2, &r2, ele);
				break;

			case '3':
				ele = delete_1(queue, &f1, &r1);
				if (ele != UF)
					printf("%d Deleted\n", ele);
				break;

			case '4':
				ele = delete_2(queue, &f2, &r2);
				if (ele != UF)
					printf("%d Deleted\n", ele);
				break;

			case '5':
				display_1(queue, f1, r1);
				break;

			case '6':
				display_2(queue, f2, r2);
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