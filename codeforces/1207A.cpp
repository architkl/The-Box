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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int t;
	cin >> t;

	int b, p, f, h, c, ans;
	while (t--)
	{
		cin >> b >> p >> f >> h >> c;

		if (h > c)
		{
			swap(h, c);
			swap(p, f);
		}

		ans = min(b/2, f) * c;
		b -= min((b/2)*2, 2*f);
		ans += min(b/2, p) * h;

		cout << ans << "\n";
	}

	return 0;
}