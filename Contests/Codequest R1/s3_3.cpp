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

vector < vector <int> > dp(1001, vector <int> (1001));
vector < vector <char> > mat(1000, vector <char> (1000));
map <int, int> num_path;

void rec(int x, int y, int sum) {
	// cout << x << " " << y << "\n";
	if (x < 0 || y < 0) return;

	if (x == 0 && y == 0) {
		// sum += (mat[i][j] - 48);
		// cout << "Sum: " << sum << "\n\n";

		if (num_path.find(sum) == num_path.end()) num_path[sum] = 1;
		else num_path[sum]++;

		return;
	}

	if (mat[x][y] != 'S') sum += mat[x][y]-48;

	if (y-1 >= 0 && mat[x][y-1] != 'X') rec(x, y-1, sum);
	if (x-1 >= 0 && mat[x-1][y] != 'X') rec(x-1, y, sum);
	if (x-1 >= 0 && y-1 >= 0 && mat[x-1][y-1] != 'X') rec(x-1, y-1, sum);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];

	rec(n-1, n-1, 0);

	int mx = 0;
	for (auto it = num_path.begin(); it != num_path.end(); it++) {
		mx = max(mx, it->first);
	}

	cout << mx << " " << num_path[mx] << "\n";

	return 0;
}