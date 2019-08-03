#include <iostream>
#include <vector>

using namespace std;

const int K = 1e9 + 7;
const int N_MAX = 100005;

long long int prefix_sum[N_MAX] = {};

int main()
{
	int N;
	cin >> N;

	vector <int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		prefix_sum[i] += A[i];
	}

	long long int ans = 0, temp;
	for (int i = 0; i < N-1; i++)
	{
		int count = 0;
		if (prefix_sum[i] % 2)
		{
			for (int j = 0; j < i; j++)
			{
				if (prefix_sum[j] % 2)
					count++;
			}
		}

		else
		{
			for (int j = 0; j <= i; j++)
			{
				if (prefix_sum[j] % 2 == 0)
					count++;
			}
		}

		int c1 = 0, c0 = 0;
		for (int j = i+1; j < N; j++)
		{
			if (prefix_sum[j] % 2)
				c1++;

			else
				c0++;
		}

		temp = count * (c1 * (c1 - 1) / 2 + c0 * (c0 - 1) / 2 + c0);
		ans += temp;
		ans %= K;
	}

	cout << ans << "\n";

	return 0;
}