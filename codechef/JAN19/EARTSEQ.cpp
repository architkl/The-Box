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
const int nth = 1200;
const int value = 10000;

bool prime[size] = {};
vector <long long int> pri_list;
vector <vector <int>> G(value);
unordered_map <int, int> start_idx;
bool vis[value][value];

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

	for (int i = 2; i <= size; i++)
		if (prime[i])
			pri_list.pb(i);
}

void pre()
{
	for (int i = 0; i < nth; i++)
	{
		for (int j = 1; j < nth; j++)
		{
			if (i == j)
				continue;

			G[pri_list[i]].pb(pri_list[j]);
		}
	}
}

void init()
{
	// start_idx.clear();
	for (int i = 0; i < nth; i++)
	{
		start_idx[pri_list[i]] = 0;

		for (int j = 0; j < nth; j++)
			vis[pri_list[i]][pri_list[j]] = false;
	}
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	sieve();

	pre();

	int T;
	cin >> T;

	int N, f1, f2;
	while (T--)
	{
		cin >> N;

		// if (N == 3)
		// {
		// 	cout << "6 10 15\n";
		// 	continue;
		// }

		// if (N == 4)
		// {
		// 	cout << "6 10 35 14\n";
		// 	continue;
		// }

		init();

		vector <int> final(N);

		final[0] = 6;
		start_idx[2]++;
		vis[2][3] = true;
		vis[3][2] = true;

		f1 = 3;
		f2 = G[f1][start_idx[f1]];

		for (int i = 1; i < N-1; i++)
		{
			// cout << f1 << " " << f2 << "\n";
			final[i] = f1 * f2;

			vis[f1][f2] = true;
			vis[f2][f1] = true;

			start_idx[f1]++;

			f1 = f2;
			f2 = G[f1][start_idx[f1]];

			while (vis[f1][f2])
			{
				start_idx[f1]++;
				f2 = G[f1][start_idx[f1]];				
			}
		}

		if (__gcd(6, final[N-2]) != 1)
			final[N-2] = final[N-2]/f1 * 2129;
		
		final[N-1] = 2*2129;

		for (int i = 0; i < N; i++)
			cout << final[i] << " ";

		cout << "\n";

		// for (int i = 0; i < N-1; i++)
		// 	final[i] = pri_list[i] * pri_list[i+1];

		// final[N-1] = pri_list[0] * pri_list[N-1];

		// for (int i = 0; i < N; i++)
		// 	cout << final[i] << " ";

		for (int i = 0; i < N-2; i++)
		{
			if (__gcd(final[i], __gcd(final[i+1], final[i+2])) != 1)
				cout << "RETARD\n";
		}

		if (__gcd(final[N-2], __gcd(final[N-1], final[0])) != 1)
			cout << "RETARD\n";

		if (__gcd(final[N-1], __gcd(final[0], final[1])) != 1)
			cout << "RETARD\n";

		// cout << "\n";
	}

	return 0;
}

/*
2*3 3*5 5*2

2*3 3*5 5*2 
*/