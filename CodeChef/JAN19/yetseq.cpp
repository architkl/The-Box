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

const int size = 15000;

bool prime[size] = {};
vector <long long int> pri_list;
bool vis[size][size];

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

void init()
{
	for (int i = 0; i < pri_list.size(); i++)
		for (int j = 0; j < pri_list.size(); j++)
			vis[pri_list[i]][pri_list[j]] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int T;
	cin >> T;

	int N, f1, f2;
	while (T--)
	{
		cin >> N;

		f1 = 0;
		f2 = 1;

		init();

		vector <int> final(N);

		int k = 1;
		for (int i = 0; i < N-3; i++)
		{
			final[i] = pri_list[f1] * pri_list[f2];
			vis[pri_list[f1]][pri_list[f2]] = true;
			vis[pri_list[f2]][pri_list[f1]] = true;

			if (f2 + k >= pri_list.size())
			{
				int idx = 0;
				while (vis[pri_list[f2]][pri_list[idx]])
					idx++;

				final[i+1] = pri_list[f2] * pri_list[idx];
				vis[pri_list[f2]][pri_list[idx]] = true;
				vis[pri_list[idx]][pri_list[f2]] = true;
				k++;
				i++;

				f1 = idx;
				f2 = idx + k;

				continue;
			}

			f1 += k;
			f2 += k;
		}

		final[N-3] = pri_list[f1] * 17389;
		final[N-2] = 17389 * 17387;
		final[N-1] = 17387 * 2;

		for (int i = 0; i < N-1; i++)
			if (__gcd(final[i], final[i+1]) == 1)
				cout << "RETARD1 " << i << "\n";

		for (int i = 0; i < N-2; i++)
		{
			if (__gcd(final[i], __gcd(final[i+1], final[i+2])) != 1)
				cout << "RETARD2 " << i << " " << final[i] << " " << final[i+1] << " " << final[i+2] << "\n";
		}

		// cout << pri_list[f1] << "\n";

		if (__gcd(final[N-2], __gcd(final[N-1], final[0])) != 1)
			cout << "RETARD2\n";

		if (__gcd(final[N-1], __gcd(final[0], final[1])) != 1)
			cout << "RETARD2\n";

		// for (int i = 0; i < N; i++)
		// 	cout << final[i] << " ";

		cout << "\n";
	}

	return 0;
}