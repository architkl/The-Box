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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> b(n), g(n);
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) cin >> g[i];

		sort(b.begin(), b.end());
		sort(g.begin(), g.end());

		// boys first
		bool f = (g[0] >= b[0]);
		for (int i = 1; i < n && f; i++) if (b[i] < g[i-1] || g[i] < b[i]) f = 0;

		if (!f) {
			// girls first
			f = (b[0] >= g[0]);
			for (int i = 1; i < n && f; i++) if (g[i] < b[i-1] || b[i] < g[i]) f = 0;
		}

		f ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}