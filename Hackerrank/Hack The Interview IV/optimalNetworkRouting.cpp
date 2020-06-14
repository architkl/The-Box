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

const int N_MAX = 301;

vector < vector <int> > C(N_MAX, vector <int> (N_MAX));
vector < vector <bool> > vis(N_MAX, vector <bool> (N_MAX));

void init() {
	for (int i = 0; i < N_MAX; i++) for (int j = 0; j < N_MAX; j++) vis[i][j] = false;
}

bool dfs(int x, int y, int eff, int N, int M) {
	if (x == N-1 && y == M-1) return true;

	vis[x][y] = true;

	bool res = false;

	// up
	if (x-1 >= 0 && !vis[x-1][y] && abs(C[x][y] - C[x-1][y]) <= eff) res |= dfs(x-1, y, eff, N, M);
	// down
	if (x+1 < N && !vis[x+1][y] && abs(C[x][y] - C[x+1][y]) <= eff) res |= dfs(x+1, y, eff, N, M);
	// left
	if (y-1 >= 0 && !vis[x][y-1] && abs(C[x][y] - C[x][y-1]) <= eff) res |= dfs(x, y-1, eff, N, M);
	// right
	if (y+1 < M && !vis[x][y+1] && abs(C[x][y] - C[x][y+1]) <= eff) res |= dfs(x, y+1, eff, N, M);

	vis[x][y] = false;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> C[i][j];

	int l = 0, h = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// up
			if (i-1 >= 0) h = max(h, abs(C[i][j] - C[i-1][j]));
			// down
			if (i+1 < N) h = max(h, abs(C[i][j] - C[i+1][j]));
			// left
			if (j-1 >= 0) h = max(h, abs(C[i][j] - C[i][j-1]));
			// right
			if (j+1 < M) h = max(h, abs(C[i][j] - C[i][j+1]));
		}
	}

	int mid;
	while (l < h) {
		mid = (l + h) / 2;

		init();

		if (dfs(0, 0, mid, N, M)) h = mid;
		else l = mid+1;
	}

	cout << l << "\n";

	return 0;
}