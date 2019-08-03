#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> A(N);

		for (int j = 0; j < N; j++)
			cin >> A[j];

		int div = A[0];
		for (int j = 1; j < N; j++)
		{
			div = gcd(A[j], div);

			if (div == 1)
			{
				cout << "YES\n";
				f = 1;
				break;
			}
		}

		if (f)
			continue;

		else
			cout << "NO\n";
	}

	return 0;
}