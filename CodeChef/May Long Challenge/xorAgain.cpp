#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> A(N);
		int result = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];

			result ^= (2 * A[j]);
		}

		cout << result << "\n";
	}

	return 0;
}