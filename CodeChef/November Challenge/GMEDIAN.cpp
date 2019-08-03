/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int K = 1e9 + 7;
int fact[2005];

void fact_init()
{
	fact[0] = 1;
	for (int i = 1; i < 2005; i++)
	{
		fact[i] *= fact[i-1];
		fact[i] %= K;
	}
}

int mod_ex(int a, int b, int m)
{
	if (b == 1)
		return a % m;

	long long int res = mod_ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int nCr(int n, int r)
{
	return (((fact[n] * mod_ex(fact[n-r], K-2, K)) % K) * mod_ex(fact[r], K-2, K)) % K;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;
	while (T--)
	{
		cin >> N;

		int mn = INT_MAX, mx = 0;
		vector <int> A(N);
		unordered_map <int, int> freq;
		multiset <int> mset;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			
			freq[A[i]]++;
			mset.insert(A[i]);

			if (A[i] < mn)
				mn = A[i];

			if (A[i] > mx)
				mx = A[i];
		}

		int med = mn;
		long long int res = mod_ex(2, N-1, K);
		while (med <= mx)
		{
			if (freq[med] <= 1)
			{
				med++;
				continue;
			}

			int same = freq[med] - 2;
			int l = mset.lower_bound(med);
			int r = N - l - freq[med];
			int temp, c;

			for (int i = 2; i <= freq[med]; i++)
			{
				c = i - 2;
				
			}
		}
	}

	return 0;
}

/*
2 2 2 2 2
...22....

.*.

.2*.	.*2.

.2*2.
.22*.	.*22.

.22*2. .2*22.
.222*. .*222.
*/