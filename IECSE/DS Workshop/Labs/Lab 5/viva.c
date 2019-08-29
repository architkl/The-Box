#include <stdio.h>
#include <math.h>

int isprime(int x, int i)
{
	if (x == 0 || x == 1)
		return 0;

	if (i > sqrt(x))
		return 1;

	if (x % i == 0)
		return 0;

	return isprime(x, i+1);
}

int main()
{
	int l, h;

	printf("Enter limits for prime generation\n");
	scanf("%d %d", &l, &h);

	if (l > h)
	{
		int temp = l;
		l = h;
		h = temp;
	}

	printf("Primes: ");
	for (int i = l; i <= h; i++)
	{
		if (isprime(i, 2))
			printf("%d ", i);
	}

	return 0;
}