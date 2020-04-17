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

//	GRAPHS
const int N_MAX = 1e5+5;

vector <int> parent(N_MAX);
vector <int> rnk(N_MAX);

void init() {
	for (int i = 0; i < N_MAX; i++) {
		parent[i] = i;
		rnk[i] = 0;
	}
}

int find_parent(int x) {
	if (parent[x] != x) parent[x] = find_parent(parent[x]);

	return parent[x];
}

bool join(int x, int y) {
	int px = find_parent(x), py = find_parent(y);

	if (px == py) return false;

	if (rnk[px] > rnk[py]) parent[py] = px;
	else parent[px] = py;

	if (rnk[px] == rnk[py]) rnk[py]++;

	return true;
}

int main() {
	init();

	int n;
	cin >> n;

	vector <pll> point(n);
	multimap <ll, int> x, y;
	ll a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		point[i] = mp(a, b);

		x.insert(mp(a, i));
		y.insert(mp(b, i));
	}

	multimap <ll, int>::iterator it, temp;
	vector < pair <ll , pii> > E;
	map <int, bool> done_x, done_y;
	for (int i = 0; i < n; i++) {
		// cout << i << "\n";
		// x coordinate
		it = x.lower_bound(point[i].first);
		int u = it->second, v1 = -1, v2 = -1;

		if (x.count(point[i].first) > 1) {
			if (done_x.find(point[i].first) == done_x.end()) {
				it = x.equal_range(point[i].first).first;
				temp = it;
				temp++;
				while (temp != x.equal_range(point[i].first).second) {
					// cout << i << "\n";
					E.pb(mp(0, mp(it->second, temp->second)));
					it++;
					temp++;
				}

				done_x[point[i].first] = true;
			}
		}

		else {
			temp = it;
			temp++;
			if (temp != x.end()) v1 = temp->second;
			
			temp = it;
			if (temp != x.begin()) {
				temp--;
				v2 = temp->second;
			}

			if (v1 == -1) {
				E.pb(mp(abs(point[u].first - point[v2].first), mp(u, v2)));
			}

			else if (v2 == -1) {
				E.pb(mp(abs(point[u].first - point[v1].first), mp(u, v1)));
			}

			else if (abs(point[u].first - point[v1].first) < abs(point[u].first - point[v2].first)) {
				E.pb(mp(abs(point[u].first - point[v1].first), mp(u, v1)));
			}

			else {
				E.pb(mp(abs(point[u].first - point[v2].first), mp(u, v2)));
			}
		}

		// y coordinate
		it = y.lower_bound(point[i].second);
		u = it->second;
		v1 = v2 = -1;

		if (y.count(point[i].second) > 1) {
			if (done_y.find(point[i].second) == done_y.end()) {
				it = y.equal_range(point[i].second).first;
				temp = it;
				temp++;
				while (temp != y.equal_range(point[i].second).second) {
					E.pb(mp(0, mp(it->second, temp->second)));
					it++;
					temp++;
				}

				done_y[point[i].second] = true;
			}
		}

		else {
			temp = it;
			temp++;
			if (temp != y.end()) v1 = temp->second;
			
			temp = it;
			if (temp != y.begin()) {
				temp--;
				v2 = temp->second;
			}

			if (v1 == -1) {
				E.pb(mp(abs(point[u].second - point[v2].second), mp(u, v2)));
			}

			else if (v2 == -1) {
				E.pb(mp(abs(point[u].second - point[v1].second), mp(u, v1)));
			}

			else if (abs(point[u].second - point[v1].second) < abs(point[u].second - point[v2].second)) {
				E.pb(mp(abs(point[u].second - point[v1].second), mp(u, v1)));
			}

			else {
				E.pb(mp(abs(point[u].second - point[v2].second), mp(u, v2)));
			}
		}
	}

	sort(E.begin(), E.end());

	/*for (int i = 0; i < E.size(); i++) {
		cout << E[i].second.first << " " << E[i].second.second << " " << E[i].first << "\n";
	}*/

	int cnt = 0;
	ll ans = 0;
	for (int i = 0; i < E.size(); i++) {
		if (join(E[i].second.first, E[i].second.second)) {
			ans += E[i].first;
			cnt++;
		}

		if (cnt == n-1) break;
	}

	cout << ans << "\n";

	return 0;
}