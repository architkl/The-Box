#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		if (n % 2 == 0)
			cout << n/2 << "\n";

		else
		{
			cout << (n-1)/2 - n << "\n";
		}
	}

	return 0;
}