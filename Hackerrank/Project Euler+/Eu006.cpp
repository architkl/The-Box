#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int n;
	long long int diff;
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		cout << (long long)n * n * (n + 1) * (n + 1) / 4 - (long long)n * (n + 1) * (2 * n + 1) / 6 << "\n";
	}

	return 0;
}