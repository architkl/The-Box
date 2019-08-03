#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N, A, B, t;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> A >> B;

		map <int, int> x;
		for (int j = 0; j < N; j++)
		{
			cin >> t;

			x[t]++;
		}

		cout << setprecision(8) << fixed << (float) x[A] * x[B] / (N * N) << "\n";
	}

	return 0;
}