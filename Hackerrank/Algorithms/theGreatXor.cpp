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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	ll x;
	while (q--)
	{
		cin >> x;

		int i = 0;
		ll temp = x, res = 0;
		while (temp)
		{
			if (!(temp & 1))
				res += (1ll << i);
			i++;
			temp >>= 1;
		}

		cout << res << "\n";
	}

	return 0;
}