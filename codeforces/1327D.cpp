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
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;

		vector <int> p(n+1), c(n+1);
		for (int i = 1; i <= n; i++) cin >> p[i];

		for (int i = 1; i <= n; i++) cin >> c[i];

		vector <int> vis(n+1), cycle;
		int ans = INT_MAX, l;
		for (int i = 1; i <= n; i++) {
			if (vis[p[i]]) continue;

			set <int> div;
			l = 0;
			cycle.clear();
			int x = p[i];
			// cout << i << " ";
			// cout << "Cycle: ";
			while (!vis[x]) {
				// cout << x << " ";
				cycle.pb(x);
				vis[x] = true;
				l++;
				x = p[x];
			}
			// cout << "\n";

			int lim = sqrt(l);
			div.insert(1);
			div.insert(l);
			for (int j = 2; j <= lim; j++) {
				if (l % j == 0) {
					div.insert(j);
					div.insert(l/j);
				}
			}

			for (auto k : div) {
				// cout << k << "\n";
				for (int j = 0; j < k; j++) {
					// cout << "Cycle starting at " << cycle[j] << "\n";
					int x = (j+k)%l;
					while (x != j && c[cycle[x]] == c[cycle[j]]) x = (x+k)%l;

					if (x == j) ans = min(ans, k);
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
/*
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4

3 6 1 8 7 2 5 4


3 4 2 5 6 1
1 2 3 3 2 3
*/