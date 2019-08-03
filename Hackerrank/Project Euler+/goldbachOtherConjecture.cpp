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

const int sieve_max = 5e5 + 5;

vector <bool> prime(sieve_max, 1);

void sieve()
{
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i*i < sieve_max; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j < sieve_max; j+=i)
			prime[j] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int T;
	cin >> T;

	int N, ans;
	while (T--)
	{
		cin >> N;

		ans = 0;
		for (int i = 1; 2*i*i < N; i++)
			if (prime[N - 2*i*i])
				ans++;

		cout << ans << "\n";
	}

	return 0;
}