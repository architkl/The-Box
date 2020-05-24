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

	srand(time(NULL));

	int x, y, n;
	cin >> x >> y >> n;

	vector <pii> points(n+1);
	points[0] = mp(x, y);
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;

		points[i] = mp(x, y);
	}

	vector < vector <int> > dist(n+1, vector <int> (n+1));
	for (int i = 0; i <= n; i++) {
		dist[i][i] = 0;

		for (int j = i+1; j <= n; j++) {
			dist[i][j] = pow(abs(points[i].first - points[j].first), 2) + pow(abs(points[i].second - points[j].second), 2);
			dist[j][i] = dist[i][j];
		}
	}

	vector <ll> dp((1 << n), INT_MAX);
	vector <int> parent(1 << n);
	dp[0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) == 0) {
				if (dp[i] + 2*dist[0][j+1] < dp[i | (1 << j)]) {
					dp[i | (1 << j)] = dp[i] + 2*dist[0][j+1];
					parent[i | (1 << j)] = i;
				}

				for (int k = j+1; k < n; k++) {
					if ((i & (1 << k)) == 0) {
						if ((dp[i] + dist[0][j+1] + dist[j+1][k+1] + dist[0][k+1]) < (dp[i | (1 << j) | (1 << k)])) {
							dp[i | (1 << j) | (1 << k)] = dp[i] + dist[0][j+1] + dist[j+1][k+1] + dist[0][k+1];
							parent[i | (1 << j) | (1 << k)] = i;
						}
					}
				}

				break;
			}
		}
	}

	cout << dp[(1 << n)-1] << "\n";

	int state = (1 << n)-1, temp;
	while (state != 0) {
		temp = state - parent[state];

		cout << "0 ";

		for (int i = 0; i < n; i++) if (((temp >> i) & 1) == 1) cout << i+1 << " ";

		state = parent[state];
	}

	cout << "0\n";

	return 0;
}

/*
0 1 2 3 ... n

1111
1100
*/