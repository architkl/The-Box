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

const int K = 1e9+7;

// pos, non-zero digits, f1 (>L), f2 (<R)
int dp[101][101][2][2];
vector <int> lb, ub;
int gK;

int NOI(int pos, int nz_cnt, bool f1, bool f2) {
	if (nz_cnt > gK) return 0;

	if (pos == ub.size()) return (nz_cnt == gK);

	if (dp[pos][nz_cnt][f1][f2] != -1) return dp[pos][nz_cnt][f1][f2];

	int l_lmt, u_lmt;
	ll res = 0;

	if (f1) l_lmt = 0;
	else l_lmt = lb[pos];

	if (f2) u_lmt = 9;
	else u_lmt = ub[pos];

	for (int dgt = l_lmt; dgt <= u_lmt; dgt++) {
		int n_nzcnt = nz_cnt+1, nf1 = f1, nf2 = f2;

		if (dgt == 0) n_nzcnt--;
		if (!f1 && dgt > l_lmt) nf1 = 1;
		if (!f2 && dgt < u_lmt) nf2 = 1;

		res += NOI(pos+1, n_nzcnt, nf1, nf2);
		res %= K;
	}

	return (dp[pos][nz_cnt][f1][f2] = res);
}

int solve(string L, string R) {
	for (int i = 0; i < R.length(); i++) ub.pb(R[i]-48);

	for (int i = 0; i < R.length()-L.length(); i++) lb.pb(0);

	for (int i = 0; i < L.length(); i++) lb.pb(L[i]-48);

	// as > L and <= R
	lb[lb.size()-1]++;

	memset(dp, -1, sizeof(dp));

	return NOI(0, 0, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string L, R;
	cin >> L >> R >> gK;

	cout << solve(L, R) << "\n";

	return 0;
}