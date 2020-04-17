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

vector < vector <int> > mat(1000, vector <int> (1000));

int solve(int x, int y, int n, int m, int sum) {
	// cout << x << " " << y << " " << sum+mat[x][y] << "\n";
	if (x == n-1 && y == m-1) return (sum+mat[x][y]);

	int mx = sum+mat[x][y];
	if (x+1 < n) mx = max(mx, solve(x+1, y, n, m, sum+mat[x][y]));
	if (y+1 < m) mx = max(mx, solve(x, y+1, n, m, sum+mat[x][y]));
	if ((x+1) < n && (y+1) < m) mx = max(mx, solve(x+1, y+1, n, m, sum+mat[x][y]));

	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];

	cout << solve(0, 0, n, m, 0) << "\n";

	return 0;
}