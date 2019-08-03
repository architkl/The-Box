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

	unordered_map <int, int> digits;
	vector <string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		digits[a[i].length()]++;
	}

	ll res = 0;
	int pos;
	for (int i = 0; i < n; i++)
	{
		for (int j = a[i].length()-1; j >= 0; j--)
		{
			pos = a[i].length()-j;
			for (int k = 1; k < 11; k++)
			{
				if (pos <= k)
				{
					res += mod_ex(10, 2*(pos)-1, K) * (ll)(a[i][j]-48) * digits[k];
					res %= K;
					res += mod_ex(10, 2*(pos)-2, K) * (ll)(a[i][j]-48) * digits[k];
					res %= K;
				}

				else
				{
					res += mod_ex(10, pos+k-1, K) * (ll)(a[i][j]-48) * digits[k];
					res %= K;
					res += mod_ex(10, pos+k-1, K) * (ll)(a[i][j]-48) * digits[k];
					res %= K;
				}
			}
		}
	}

	cout << res << "\n";

	return 0;
}