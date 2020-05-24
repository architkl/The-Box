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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;

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

	for (int i = 0; i < sieve_max; i++)
		if (prime[i])
			cout << i << " ";
}

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

//  Extended GCD
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = extended_gcd(b, a%b, x1, y1);	
	x = y1;
	y = x1 - (a/b) * y1;

	return g;
}

//  Trim Leading 0s
str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	return 0;
}