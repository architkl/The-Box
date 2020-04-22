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

	int n, m;
	cin >> n >> m;

	char c;
	cin >> c;

	vector < vector <char> > room(n, vector <char> (m));
	int tlx = -1, tly = -1, brx, bry;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];

			if (room[i][j] == c) {
				if (tlx == -1) {
					tlx = i;
					tly = j;
				}

				brx = i;
				bry = j;
			}
		}
	}

	int ans = 0;
	// trace top
	if (tlx-1 >= 0) {
		set <char> S;
		for (int i = tly; i <= bry; i++) if (room[tlx-1][i] != '.') S.insert(room[tlx-1][i]);

		ans += S.size();
	}

	// trace bottom
	if (brx+1 < n) {
		set <char> S;
		for (int i = tly; i <= bry; i++) if (room[brx+1][i] != '.') S.insert(room[brx+1][i]);

		ans += S.size();
	}

	// trace left
	if (tly-1 >= 0) {
		set <char> S;
		for (int i = tlx; i <= brx; i++) if (room[i][tly-1] != '.') S.insert(room[i][tly-1]);

		ans += S.size();
	}

	// trace right
	if (bry+1 < m) {
		set <char> S;
		for (int i = tlx; i <= brx; i++) if (room[i][bry+1] != '.') S.insert(room[i][bry+1]);

		ans += S.size();
	}

	cout << ans << "\n";

	return 0;
}