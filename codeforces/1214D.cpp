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

vector <piii> v;
map <pii, bool> vis;

bool comp(piii a, piii b) {
	return (a.first < b.first);
}

bool dfs(pii x, pii dest, int d, vector < vector <char> > mat) {
	if (x.first == mat.size() || x.second == mat[0].size())
		return false;

	if (x == dest)
		return true;

	vis[x] = true;
	bool f = false;

	if (!vis[mp(x.first, x.second+1)] && x.second+1 < mat[0].size())
		f |= dfs(mp(x.first, x.second+1), dest, d+1, mat);

	if (!vis[mp(x.first+1, x.second)] && x.first+1 < mat.size())
		f |= dfs(mp(x.first+1, x.second), dest, d+1, mat);

	if (f)
		v.pb(mp(d, x));

	return f;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector < vector <char> > mat(n, vector <char> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	bool temp = dfs(mp(0, 0), mp(n-1, m-1), 0, mat);

	sort(v.begin(), v.end(), comp);

	for (auto i : v)
		cout << i.second.first << " " << i.second.second << " " << i.first << "\n";

	int cur_d = 1, mn = (v.size() == 0 ? 0 : INT_MAX);
	for (int i = 1; i < v.size(); i++) {
		int j = i;

		while (j < v.size() && v[j].first == cur_d)
			j++;

		cur_d++;
		mn = min(mn, j-i);
		i = j-1;
	}

	cout << min(mn, 2) << "\n";

	return 0;
}