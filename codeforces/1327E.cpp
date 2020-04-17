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

const int K = 998244353;

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

int main() {
	int n;
	cin >> n;

	ll res, b, nb;
	for (int x = 1; x < n; x++) {
		b = mod_ex(10, n-x-1, K);
		b *= 18;
		b %= K;

		nb = mod_ex(10, n-x-2, K);
		nb *= 81;
		nb %= K;
		nb *= (n-x+1-2);
		nb %= K;

		res = (b + nb) % K;
		res *= 10;
		res %= K;

		cout << res << " ";
	}

	cout << 10 << "\n";

	return 0;
}