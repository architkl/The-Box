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

int dp[18][19][2][2];

vector <int> low, high, temp;

int palNum(int pos, int st_idx, bool f1, bool f2) {
	if (pos == high.size()) return (st_idx != -1);

	if (dp[pos][st_idx+1][f1][f2] != -1) return dp[pos][st_idx+1][f1][f2];

	int res = 0, l_lmt, u_lmt;

	if (f1) u_lmt = 9;
	else u_lmt = high[pos];

	if (f2) l_lmt = 0;
	else l_lmt = low[pos];

	// when you're in the second half
	if (st_idx != -1 && (pos > (high.size()-1+st_idx) / 2)) {
		int mid = (high.size()-1+st_idx) / 2;
		int num = temp[mid - (pos-mid) + (high.size()-1-st_idx)%2];

		// check if in range
		if (l_lmt <= num && num <= u_lmt) {
			temp.pb(num);
			res += palNum(pos+1, st_idx, f1 || (num < u_lmt), f2 || (num > l_lmt));
			temp.pop_back();
		}
	}

	// when you're in first half
	else {
		for (int dgt = l_lmt; dgt <= u_lmt; dgt++) {
			if (st_idx == -1 && dgt > 0) st_idx = pos;

			temp.pb(dgt);
			res += palNum(pos+1, st_idx, f1 || (dgt < u_lmt), f2 || (dgt > l_lmt));
			temp.pop_back();
		}
	}

	return (dp[pos][st_idx+1][f1][f2] = res);
}

int solve(ll a, ll b) {
	low.clear();
	high.clear();

	while (b) {
		high.pb(b%10);
		low.pb(a%10);
		b /= 10;
		a /= 10;
	}

	reverse(low.begin(), low.end());
	reverse(high.begin(), high.end());

	memset(dp, -1, sizeof(dp));

	return palNum(0, -1, 0, 0);
}

void swap(ll &a, ll &b) {
	ll c = a;
	a = b;
	b = c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	ll a, b;
	for (int i = 1; i <= T; i++) {
		cin >> a >> b;

		if (a > b) swap(a, b);

		cout << "Case " << i << ": " << solve(a, b) + (a == 0) << "\n";
	}

	return 0;
}