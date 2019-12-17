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
	int n, m;
	cin >> n >> m;

	vector <pll> bal(n+1);
	int u, v, d;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;

		bal[u] = mp(bal[u].first-d, u);
		bal[v] = mp(bal[v].first+d, v);
	}

	sort(bal.begin()+1, bal.end());
	int a = 1, b = n, ans = 0;
	ll mn;
	
	vector < pair <ll, pii> > debt;
	while (bal[b].first > 0 && bal[a].first < 0) {

		mn = min(-bal[a].first, bal[b].first);
		bal[a].first += mn;
		bal[b].first -= mn;

		debt.pb(mp(mn, mp(bal[a].second, bal[b].second)));
		ans++;

		if (bal[a].first == 0) a++;
		if (bal[b].first == 0) b--;
	}

	cout << ans << "\n";
	for (auto i : debt) cout << i.second.first << " " << i.second.second << " " << i.first << "\n";

	return 0;
}