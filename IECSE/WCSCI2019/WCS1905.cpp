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

vector < vector < vector <ll> > > dp(31, vector < vector <ll> > (31, vector <ll> (51, INT_MAX)));

void pre() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 51; k++) {
				if (i == 0 || j == 0 || k == 0 || i*j == k) dp[i][j][k] = 0;

				for (int l = 1; l < i; l++) {
					dp[i][j][k] = min(dp[i][j][k], dp[l][j][k] + j*j);

					if ((i-l)*j <= k) dp[i][j][k] = min(dp[i][j][k], dp[l][j][k-(i-l)*j] + j*j);
				}

				for (int l = 1; l < j; l++) {
					dp[i][j][k] = min(dp[i][j][k], dp[i][l][k] + i*i);

					if (i*(j-l) <= k) dp[i][j][k] = min(dp[i][j][k], dp[i][l][k-i*(j-l)] + i*i);
				}
			}
		}
	}
}

int main() {
	pre();

	int T;
	cin >> T;

	int N, M, K;
	while (T--) {
		cin >> N >> M >> K;

		cout << dp[N][M][K] << "\n";
	}

	return 0;
}