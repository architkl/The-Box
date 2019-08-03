/*
Author: architkl
Language: C++ 14
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

const int size = 1e7+5;

bool prime[size] = {};
vector <int> pri_list;

void sieve()
{
	for (int i = 0; i < size; i++)
		prime[i] = true;

	prime[0] = false;
	prime[1] = false;

	int n = sqrt(size);

	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j <= size; j+=i)
			prime[j] = false;
	}

	for (int i = 13; i <= size; i++)
		if (prime[i])
			pri_list.pb(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	vector <int> final;
	for (int i = 0; i < 30000; i++)
	{
		if (i % 2 == 0)
		{
			final.pb(pri_list[i]*2); 
			final.pb(pri_list[i]*3);
		}

		else
		{
			final.pb(pri_list[i]*3);
			final.pb(pri_list[i]*2);
		}
	}

	int T;
	cin >> T;


	int N;
	while (T--)
	{
		cin >> N;

		if (N <= 3333)
		{
			vector <int> dupl(N);
			for (int i = 0; i < N-1; i++)
				dupl[i] = pri_list[i] * pri_list[i+1];

			dupl[N-1] = pri_list[0] * pri_list[N-1];

			for (int i = 0; i < N; i++)
				cout << dupl[i] << " ";

			cout << "\n";

			continue;
		}

		int temp1, temp2, temp3, temp4, K = (N-2) % 3;

		temp1 = final[0];
		temp2 = final[N-3-K];
		temp3 = __gcd(final[0], final[1]);
		temp4 = __gcd(final[N-3-K], final[N-4-K]);

		if (K != 0)
		{
			for (int i = 0; i < N-2-K; i++)
				cout << final[i] << " ";
		}

		else
		{
			K = 1;

			for (int i = 0; i < N-2-K; i++)
				cout << final[i] << " ";

			temp2 = final[N-3-K];
			temp4 = __gcd(final[N-3-K], final[N-4-K]);
		}

		// cout << temp2 << " " << temp4 << "\n";

		if (K == 1)
			cout << (temp2 / temp4) * 5 << " " << 35 << " " << (temp1 / temp3) * 7 << "\n";
		
		else
			cout << (temp2 / temp4) * 5 << " " << 35 << " " << 77 << " " << (temp1 / temp3) * 11 << "\n";
	}

	return 0;
}