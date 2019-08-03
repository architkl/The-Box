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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

/*
//	GRAPHS
const int N_MAX = 1e5+5;

vector <int> G[N_MAX];
vector <piii> G[N_MAX];
vector <bool> vis(N_MAX);

void init()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = 0;
}
*/
//	SIEVE
const int sieve_max = 1e7;

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
/*
//	Binary Exponentiation
int mod_ex(ll a, ll b, int m)
{
	if (b == 0)
		return 1;

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
*/

int main()
{
	int ans = 0, temp;

	for (int i = 1; i <= 100; i++)
	{
		temp = 0;

		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				temp++;
		}

		if (temp % 2)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}