#include <iostream>
#include <math.h>

using namespace std;

int phi(int n)
{
	float result = n;

	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;

			result *= (1 - (float)1 / i);
		}
	}

	return ceil(result);
}

int main()
{
	int p;
	cin >> p;

	cout << phi(p) << "\n";

	return 0;
}