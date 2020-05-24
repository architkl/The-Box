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

	int n, h;
	cin >> n >> h;

	vector < vector <ll> > dp(n+1, vector <ll> (n+1));
	ll p1, p2;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= i; k++) {
				p1 = p2 = 0;

				// left < j-1, right = j-1
				for (int l = 0; l < j-1; l++) p1 += dp[k-1][l];
				p1 *= dp[i-k][j-1];

				// left = j-1, right <= j-1
				for (int l = 0; l < j; l++) p2 += dp[i-k][l];
				p2 *= dp[k-1][j-1];

				// cout << i << " " << j << " " << k << " as root: "<< p1 << " " << p2 << "\n";

				dp[i][j] += p1+p2;
			}
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }

	ll ans = 0;
	for (int i = h; i <= n; i++) ans += dp[n][i];

	cout << ans << "\n";

	return 0;
}