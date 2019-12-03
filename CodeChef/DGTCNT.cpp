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

vector <int> a(10), low, high, cnt(10);
int dp[18][10][18][2][2][2];
int gDGT;

void print() {
	for (int i = 0; i < 10; i++) cout << cnt[i] << " ";
	cout << "\n";
}

int like(int pos, int prev, bool st, bool f1, bool f2) {
	if (pos == high.size()) {
		// print();
		for (int i = 0; i < 10; i++) if (cnt[i] == a[i]) return 0;
		// cout << "FOUND 1\n";
		return 1;
	}

	if (dp[pos][prev][cnt[prev]][st][f1][f2] != -1) return dp[pos][prev][cnt[prev]][st][f1][f2];

	int res = 0, l_lmt, u_lmt;

	if (f1) u_lmt = 9;
	else u_lmt = high[pos];

	if (f2) l_lmt = 0;
	else l_lmt = low[pos];

	for (int dgt = l_lmt; dgt <= u_lmt; dgt++) {
		// cout << dgt << "\n";
		// cout << pos+1 << " " << dgt << " " << (st || (dgt > 0)) << " " << (f1 || (dgt < u_lmt)) << " " << (f2 || (dgt > l_lmt)) << "\n";
		cnt[dgt]++;
		res += like(pos+1, dgt, st || (dgt > 0), f1 || (dgt < u_lmt), f2 || (dgt > l_lmt));
		cnt[dgt]--;
	}

	return (dp[pos][prev][cnt[prev]][st][f1][f2] = res);
}

int solve(ll L, ll R) {
	low.clear();
	high.clear();

	while (R) {
		low.pb(L%10);
		high.pb(R%10);
		L /= 10;
		R /= 10;
	}

	reverse(low.begin(), low.end());
	reverse(high.begin(), high.end());

	memset(dp, -1, sizeof(dp));

	return like(0, 0, 0, 0, 0);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int T;
	cin >> T;

	ll L, R;
	while (T--) {
		cin >> L >> R;

		a.clear();
		for (int i = 0; i < 10; i++) cin >> a[i];

		cout << solve(L, R) << "\n";
	}

	return 0;
}