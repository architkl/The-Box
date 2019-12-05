#include <iostream>
#include <vector>

using namespace std;

#define ll long long

const int A_MAX = 1e6 + 5;

ll nC2(int n)
{
	return (n < 2) ? 0 : (ll)(n) * (n-1) / 2;
}

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> A(N), ex_even(A_MAX), ex_odd(A_MAX), hash(A_MAX);
		ll count_eq = 0;
		int even = 0, odd = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];
			
			if (A[j] % 2)
			{
				ex_odd[A[j] >> 2]++;
				odd++;
			}

			else
			{
				ex_even[A[j] >> 2]++;
				even++;
			}
		}

		for (int j = 0; j < A_MAX; j++)
		{
			if (ex_even[j] > 1)
				count_eq += nC2(ex_even[j]);

			if (ex_odd[j] > 1)
				count_eq += nC2(ex_odd[j]);
		}
		
		cout << even << " " << odd << " " << count_eq << "\n";

		ll ans = nC2(even) + nC2(odd) - count_eq;

		cout << ans << "\n";
	}

	return 0;
}