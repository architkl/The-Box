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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		vector <int> G[N+1];
		int u, v;
		for (int i = 1; i < N; i++) {
			cin >> u >> v;

			G[u].pb(v);
			G[v].pb(u);
		}

		queue <pii> q;
		vector <bool> vis(N+1);
		q.push(mp(1, 1));
		vis[1] = true;
		pii cur;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			// cout << cur.first << "\n";

			for (auto j : G[cur.first]) {
				if (vis[j]) continue;

				q.push(mp(j, cur.second+1));
				vis[j] = true;
			}
		}

		vis.clear();
		vis.resize(N+1);
		q.push(mp(cur.first, 1));
		vis[cur.first] = true;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			// cout << cur.first << "\n";

			for (auto j : G[cur.first]) {
				if (vis[j]) continue;

				q.push(mp(j, cur.second+1));
				vis[j] = true;
			}
		}

		cout << cur.second-1 << "\n";
	}

	return 0;
}