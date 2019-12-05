#include <iostream>

using namespace std;

int main()
{
	long long int n, k, A, B;
	cin >> n >> k >> A >> B;

	long long int cost = 0;

	if (k == 1)
	{
		cost += (n - 1) * A;
		n = 1;
	}

	while (n != 1)
	{
		if (n % k == 0)
		{
			if ( (n - (n / k)) * A <= B)
			{
				cost += (n - 1) * A;
				break;
			}

			else
			{
				while (n % k == 0)
				{
					cost += B;
					n /= k;
				}
			}
		}

		else
		{
			cost += A;
			n--;
		}
	}

	cout << cost << "\n";

	return 0;
}