#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int K = pow(10, 9) + 7;

int main()
{
	int T;
	cin >> T;

	int M, N;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N;

		vector <int> A(M), B(M);

		for (int j = 0; j < M; j++)
			cin >> A[j];

		for (int j = 0; j < M; j++)
			cin >> B[j];

		long long int result = 0;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
			{
				long long int f1 = A[j], f2 = B[k], f3;

				for (int l = 2; l < N; l++)
				{
					f3 = f1 + f2;
					f1 = f2;
					f2 = f3;

					f3 %= K;
				}

				result += f3;
				result %= K;
			}
		}

		cout << result << "\n";
	}

	return 0;
}