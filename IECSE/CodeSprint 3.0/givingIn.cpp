#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd (y, x % y));
}

int main()
{
	int T;
	cin >> T;

	int a, b, ma, mb;
	long long int lcm, pa, pb;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;

		lcm  = a * b / gcd(a, b);
		//cout << lcm << "\n";
		pa = 0;
		pb = 0;

		ma = 1;
		mb = 1;

		if (a < b)
			pa += a;

		else
			pb += b;

		while (ma * a <= lcm && mb * b <= lcm)
		{
			if (ma * a < mb * b)
			{
				if ((ma + 1) * a < mb * b)
				{
					pa += a;
					ma++;
				}

				else
				{
					pb += mb * b - ma * a;
					ma++;
				}
			}

			else if (mb * b < ma * a)
			{
				if ((mb + 1) * b < ma * a)
				{
					pb += b;
					mb++;
				}

				else
				{
					pa += ma * a - mb * b;
					mb++;
				}
			}

			else
				break;
		}
/*
		if (a < b)
			pb += lcm - (lcm / a - 1) * a;

		else
			pa += lcm - (lcm / b - 1) * b;*/

		if (pa == pb || a == b)
			cout << "Passed\n";

		else if (pa < pb)
			cout << "Fail\n";

		else
			cout << "Aced\n";
	}

	return 0;
}