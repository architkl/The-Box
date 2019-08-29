#include <stdio.h>

int main()
{
	int p[], n = 2;
	for (int i = 0; i < n; i++)
		p[i] = i;

	for (int i = 0; i < n; i++)
		printf("%d\n", i);

	return 0;
}