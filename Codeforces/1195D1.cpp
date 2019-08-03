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

int main()
{
	int n;
	cin >> n;

	vector <string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i].length()-1; j >= 0; j--)
		{
			res += mod_ex(10, 2*(a[i].length()-j)-1, K) * (ll)(a[i][j]-48) * n;
			res %= K;
			res += mod_ex(10, 2*(a[i].length()-j)-2, K) * (ll)(a[i][j]-48) * n;
			res %= K;
		}
	}

	cout << res << "\n";

	return 0;
}