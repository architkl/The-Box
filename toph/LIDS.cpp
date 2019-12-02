/*
Author: architkl
Language: C++ 17
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

vector <int> num1, num2, temp;

// f1 = (num < high), f2 = (num > low)

int dp[10][11][10][2][2][2];
int gK;

int LIDS(int pos, int prev, int len, bool zf, bool f1, bool f2) {
	// cout << pos << " " << prev << " " << len << " " << zf << " " << f1 << " " << f2 << "\n";
	
	if (pos == num1.size()) {
		if (len == gK) {
			// cout << "\n";
			// for (auto i : temp) cout << i << " ";
			// cout << "\n";
			// cout << "FOUND 1\n";
		}
		return (len == gK);
	}

	if (dp[pos][prev+1][len][zf][f1][f2] != -1) {
		// cout << "REP\n";
		return dp[pos][prev+1][len][zf][f1][f2];
	}

	int res = 0, u_lmt, l_lmt;

	if (f1) u_lmt = 9;
	else u_lmt = num1[pos];

	if (f2) l_lmt = 0;
	else l_lmt = num2[pos];

	// if (l_lmt == 1 0&& zf) l_lmt = 0;
	// else if (l_lmt == 10) l_lmt = 1;

	for (int dgt = l_lmt; dgt <= u_lmt; dgt++) {
		int nlen = len+1, nzf = zf, nf1 = f1, nf2 = f2;

		if (f1 == 0 && dgt < u_lmt) nf1 = 1;
		if (f2 == 0 && dgt > l_lmt) nf2 = 1;
		if (!zf && dgt > 0) nzf = 1;

		res += LIDS(pos+1, prev, len, nzf, nf1, nf2);

		if (dgt > prev && nzf) {
			temp.pb(dgt);
			res += LIDS(pos+1, dgt, nlen, nzf, nf1, nf2);
			temp.pop_back();
		}
	}

	// cout << pos << " " << prev+1 << " " << len << " " << zf << " " << f1 << " " << f2 << ": " << res << "\n";

	return (dp[pos][prev+1][len][zf][f1][f2] = res);
}

int solve(int a, int b) {
	num1.clear();
	num2.clear();

	while (b) {
		num1.pb(b % 10);
		num2.pb(a % 10);
		b /= 10;
		a /= 10;
	}

	/*while (a) {
		num2.pb(a % 10);
		a /= 10;
	}

	while (num2.size() != num1.size())
		num2.pb(10);*/

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	// for (auto i : num1) cout << i << " ";
	// cout << "\n";
	// for (auto i : num2) cout << i << " ";
	// cout << "\n";

	int res;

	for (int i = 9; i > 0; i--) {
		gK = i;
		// cout << gK << "\n";

		memset(dp, -1, sizeof(dp));
		res = LIDS(0, -1, 0, 0, 0, 0);

		if (res != 0) break;
	}

	cout << gK << " ";

	return res;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int T;
	cin >> T;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;

		cout << "Case " << i+1 << ": " << solve(x, y) << "\n";
	}

	return 0;
}