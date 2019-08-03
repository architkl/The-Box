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

		int hcf = A[0];
		for (int j = 1; j < N; j++)
			hcf = gcd(hcf, A[j]);

		hcf == 1 ? cout << 0 << "\n" : cout << -1 << "\n";
	}

	return 0;
}