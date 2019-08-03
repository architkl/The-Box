#include <iostream>

using namespace std;

int sumOfDigits(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main()
{
	int t;
	cin >> t;

	int n, t, sum;
	for (int i = 0; i < n; i++)
	{
		cin >> n;

		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> t;

			sum += sumOfDigits(t);
		}

		if (sum % 3 == 0)
			cout << "Yes\n";

		else
			cout << "No\n";
	}

	return 0;
}