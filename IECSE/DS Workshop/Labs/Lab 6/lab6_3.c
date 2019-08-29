#include <stdio.h>

#define max_size 10
#define UF -999999

int delete(int *queue, int *f, int *r)
{
	return (*f == *r) ? UF : queue[(*f)++];
}

int main()
{
	int queue[max_size], n, f, r;

	printf("Enter no. of elements\n");
	scanf("%d", &n);

	f = 0;
	r = n-1;

	printf("Eneter elements\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &queue[i]);

	int ele;
	printf("Enter element to be searched\n");
	scanf("%d", &ele);

	int temp = delete(queue, &f, &r);
	while (1)
	{
		if (temp == ele)
		{
			printf("Element present\n");
			break;
		}

		if (temp == UF)
		{
			printf("Element not present\n");
			break;
		}

		temp = delete(queue, &f, &r);
	}

	return 0;
}