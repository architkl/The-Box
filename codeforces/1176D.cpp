/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int sieve_max = 3e6;

vector <bool> prime(sieve_max, 1);
unordered_map <int, int> sm_div, prime_cnt;

void sieve()
{
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i*i < sieve_max; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j < sieve_max; j+=i)
		{
			prime[j] = false;

			if (sm_div[j] == 0)
				sm_div[j] = i;
		}
	}

	int cnt = 1;
	for (int i = 2; i < sieve_max; i++)
		if (prime[i])
			prime_cnt[i] = cnt++;
}

bool mycomp(int i, int j)
{
	return (i > j);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int n;
	cin >> n;

	n *= 2;
	vector <int> b(n);
	unordered_map <int, int> freq;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		freq[b[i]]++;
	}

	sort(b.begin(), b.end(), mycomp);

	for (int i = 0; i < n; i++)
	{
		if (freq[b[i]] == 0)
			continue;

		if (prime[b[i]])
		{
			cout << prime_cnt[b[i]] << " ";
			freq[b[i]]--;
			freq[prime_cnt[b[i]]]--;
		}

		else
		{
			cout << b[i] << " ";
			freq[b[i]]--;
			freq[b[i] / sm_div[b[i]]]--;
		}
	}

	cout << "\n";

	return 0;
}