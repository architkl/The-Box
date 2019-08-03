#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N_MAX = 100005;

bool dup[N_MAX];

void ini_dup()
{
	for (int i = 0; i < N_MAX; i++)
		dup[i] = 0;
}

int main()
{
	int T;
	cin >> T;

	int N, t, even, odd;
	int ans;
	vector <int> A;
	for (int i = 0; i < T; i++)
	{
		A.clear();

		cin >> N;

		ini_dup();
		for (int j = 0; j < N; j++)
		{
			cin >> t;

			if (dup[t])
				continue;

			dup[t] = 1;
			A.push_back(t);
		}

		even = odd = 0;
		ans = 1;

		for (int j = 0; j < A.size(); j++)
		{
			if (A[j] % 2)
				odd++;
			else
				even++;
		}

		if (odd == 0)
			cout << 0 << "\n";

		else
		{
			for (int i = 0; i < even; i++)
			{
				ans *= 2;
				ans %= ((int)pow(10, 9) + 7);
			}

			for (int i = 0; i < odd-1; i++)
			{
				ans *= 2;
				ans %= ((int)pow(10, 9) + 7);
			}

			cout << ans << "\n";
		}

	}

	return 0;
}