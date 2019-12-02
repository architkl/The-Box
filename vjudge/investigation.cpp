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
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

// pos , sum , flag
// vector < vector < vector < vector <int> > > > dp(12, vector < vector < vector <int> > > (120, vector < vector <int> > (120, vector <int> (2))));
int dp[12][120][120][2];
vector <int> num, temp;
int gK;

// int getNum(vector <int> vec) {
// 	int res = 0;
// 	for (auto i : vec) {
// 		res *= 10;
// 		res += i;
// 	}

// 	// for (auto i : vec) cout << i;
// 	// cout << "\n";

// 	return res;
// }

int investigate(int pos, int sum, int val, bool f) {
	// cout << "\n" << pos << " " << sum << " " << f << "\n";
	if (pos == num.size()) {
		// if ((getNum(temp) % gK == 0) && (sum % gK == 0)) {
		// 	cout << "FOUND 1\n";
		// 	cout << "\n" << pos << " " << sum << " " << f << "\n";
		// 	for (auto i : temp) cout << i;
		// 	cout << "\n";
		// }
		return ((val % gK == 0) && (sum % gK == 0));
	}

	if (dp[pos][sum][val][f] != -1) {
		// cout << pos << " " << sum << " " << val << " " << f << " " << dp[pos][sum][val][f] << " REP\n";
		return dp[pos][sum][val][f];
	}

	int res = 0, lmt;

	if (f) lmt = 9;
	else lmt = num[pos];

	for (int dgt = 0; dgt <= lmt; dgt++) {
		int nf = f, nsum = sum + dgt, nval = (val*10 + dgt) % gK;
		// temp[pos] = dgt;

		if (f == 0 && dgt < lmt) nf = 1;

		res += investigate(pos+1, nsum, nval, nf);
	}

	// cout << pos << " " << sum << " " << f << " " << res << "\n";

	return dp[pos][sum][val][f] = res;
}

int solve(int x, int k) {
	if (k > 90) return 0;

	num.clear();
	// temp.clear();

	while (x) {
		num.pb(x % 10);
		x /= 10;
	}

	reverse(num.begin(), num.end());
	// temp.assign(num.begin(), num.end());

	// for (auto i : num) cout << i;
	// cout << "\n";

	memset(dp, -1, sizeof(dp));

	// for (int i = 0; i < 12; i++) for (int j = 0; j < 120; j++) for (int k = 0; k < 120; k++) fill(dp[i][j][k].begin(), dp[i][j][k].end(), -1);
	gK = k;

	return investigate(0, 0, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int A, B, K;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> K;

		cout << "Case " << i << ": " << solve(B, K) - solve(A-1, K) << "\n";
	}

	return 0;
}