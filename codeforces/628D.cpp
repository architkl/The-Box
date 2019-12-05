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

const int K = 1e9+7;
int gD, gM;

vector <int> low, high;

// pos, rem, f1, f2
int dp[2000][2000][2][2];

int d_magic(int pos, int rem, bool f1, bool f2) {
	// cout << pos << " " << rem << " " << d_cnt << " " << f1 << " " << f2 << "\n";
	if (pos == high.size()) {
		// if (rem == 0 && d_cnt) cout << "FOUND 1\n";
		return (rem == 0);
	}

	if (dp[pos][rem][f1][f2] != -1) return dp[pos][rem][f1][f2];

	ll res = 0;
	int u_lmt, l_lmt;

	if (f1) u_lmt = 9;
	else u_lmt = high[pos];

	if (f2) l_lmt = 0;
	else l_lmt = low[pos];

	// odd idx means even pos
	if (pos % 2) {
		if (l_lmt <= gD && gD <= u_lmt) {
			res += d_magic(pos+1, (rem*10+gD) % gM, f1 || (gD < u_lmt), f2 || (gD > l_lmt));
			res %= K;
		}
	}

	else {
		for (int dgt = l_lmt; dgt <= u_lmt; dgt++) {
			if (dgt == gD) continue;

			res += d_magic(pos+1, (rem*10+dgt) % gM, f1 || (dgt < u_lmt), f2 || (dgt > l_lmt));
			res %= K;
		}
	}

	return (dp[pos][rem][f1][f2] = res);
}

int solve(string a, string b, int m, int d) {
	low.clear();
	high.clear();

	for (auto i : a) low.pb(i-48);
	for (auto i : b) high.pb(i-48);

	memset(dp, -1, sizeof(dp));

	gD = d;
	gM = m;

	return d_magic(0, 0, 0, 0);
}

int main() {
	int m, d;
	cin >> m >> d;

	string a, b;
	cin >> a >> b;

	cout << solve(a, b, m, d) << "\n";

	return 0;
}