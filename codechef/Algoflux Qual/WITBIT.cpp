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

int mod_ex(int a, int b, int m)
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	ull l, r;
	while (T--)
	{
		cin >> l >> r;

		int low = log2(l)+1, high = ceil(log2(r));

		long long int ans = 0;
		for (int i = low; i < high; i++)
		{
			ans += pow(2, (low-3));
		}

		low = log2(l);
		while (1)
		{
			int x = 6;
			while (low + x < l)
				x *= 2;
		}
	}

	return 0;
}