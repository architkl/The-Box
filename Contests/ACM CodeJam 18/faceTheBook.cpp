#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	long long T, N, X, F;
	long long users;
	for (int i = 0; i < t; i++)
	{
		cin >> T >> N >> X >> F;

		users = N;
		for (int j = 0; j < T; j++)
		{
			N = N / 2 * 3 * X;
			users += N;
			X *= F;
		}

		cout << users << "\n";
	}

	return 0;
}