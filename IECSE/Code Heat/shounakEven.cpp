#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long int k;
	for (int i = 0; i < T; i++)
	{
		cin >> k;

		cout << (k - 1) * k * (k + 1) << "\n";
	}

	return 0;
}