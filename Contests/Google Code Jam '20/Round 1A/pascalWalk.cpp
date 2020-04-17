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

const int N_MAX = 505;

vector < vector <ll> > pasc(N_MAX);
vector <pii> path;
vector < vector <bool> > vis(N_MAX, vector <bool> (N_MAX));

void pre() {
	pasc[1].resize(2);
	pasc[1][1] = 1;
	for (int i = 2; i < N_MAX; i++) {
		pasc[i].resize(i+1);
		pasc[i][1] = pasc[i][i] = 1;
		for (int j = 2; j < i; j++) {
			pasc[i][j] = pasc[i-1][j-1] + pasc[i-1][j];
		}
	}
}

void init() {
	for (int i = 0; i < N_MAX; i++) for (int j = 0; j < N_MAX; j++) vis[i][j] = false;
}

bool dfs(int r, int k, int steps, ll sum, ll n) {
	if (r <= 0 || k <= 0 || steps > 500 || sum > n || vis[r][k]) return false;

	vis[r][k] = true;

	sum += pasc[r][k];
	if (sum == n) {
		// cout << r << " " << k << " "  << sum << "\n";
		path.pb(mp(r, k));
		return true;
	}

	// (r-1, k-1), (r, k-1), (r+1, k), (r+1, k+1), (r, k+1), (r-1, k)
	map <int, pii, greater <int> > nb;
	if (r-1 > 0 && k-1 > 0) nb[pasc[r-1][k-1]] = mp(r-1, k-1);
	if (k-1 > 0) nb[pasc[r][k-1]] = mp(r, k-1);
	if (r+1 < 501) nb[pasc[r+1][k]] = mp(r+1, k);
	if (r+1 < 501 && k+1 <= r+1) nb[pasc[r+1][k+1]] = mp(r+1, k+1);
	if (k+1 <= r) nb[pasc[r][k+1]] = mp(r, k+1);
	if (r-1 > 0 && r-1 >= k) nb[pasc[r-1][k]] = mp(r-1, k);

	for (auto i : nb) {
		if (dfs(i.second.first, i.second.second, steps+1, sum, n)) {
			// cout << r << " " << k << " "  << sum << "\n";
			path.pb(mp(r, k));
			return true;
		}
	}

	vis[r][k] = false;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();

	int T;
	cin >> T;

	int n;
	for (int x = 1; x <= T; x++) {
		cout << "Case #" << x << ":\n";

		cin >> n;

		init();
		path.clear();

		bool temp = dfs(1, 1, 1, 0, n);

		for (int i = path.size()-1; i >= 0; i--) cout << path[i].first << " " << path[i].second << "\n";

		cout << "\n";
	}

	return 0;
}