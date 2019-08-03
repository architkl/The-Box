#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int roots[2000] = {};

bool is_square(long long int x)
{
	return (sqrt(x) == (int)sqrt(x));
}

int main()
{
	long long int b, c;
	cin >> b >> c;

	long long int count = 0, p, p2, q;
	for (; p <= b; p++)
	{
		p2 = pow(p, 2);

		if (p2 > c)
		{
			if (is_square(p2-c))
				roots[-p + sqrt(p2-c)]
			count += 2 * c;
		}

		else if (p2 == c)
		{
			roots[-p/2 + 1000]++;
			roots[p/2 + 1000]++;
		}
	}

	return 0;
}