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

bool comp(string a, string b) {
	return (a.length() > b.length());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	for (int x = 1; x <= T; x++) {
		cout << "Case #" << x << ": ";
		cin >> n;

		vector <string> P(n), pre(n, ""), suff(n, ""), mid(n, "");
		for (int i = 0; i < n; i++) cin >> P[i];

		for (int i = 0; i < n; i++) {
			int first = INT_MAX, last = INT_MIN;
			for (int j = 0; j < P[i].length(); j++) {
				if (P[i][j] == '*') {
					first = min(first, j);
					last = max(last, j);
				}
			}

			for (int j = 0; j < first; j++) pre[i] += P[i][j];

			for (int j = first+1; j < last; j++) {
				if (P[i][j] == '*') continue;

				mid[i] += P[i][j];
			}

			for (int j = last+1; j < P[i].length(); j++) suff[i] += P[i][j];
		}

		sort(pre.begin(), pre.end(), comp);
		sort(suff.begin(), suff.end(), comp);

		bool f;
		// check prefix
		for (int i = 1; i < n; i++) {
			f = 1;
			for (int j = 0; j < pre[i].length(); j++) {
				if (pre[i][j] != pre[0][j]) {
					f = 0;
					break;
				}
			}

			if (!f) break;
		}

		if (!f) {
			// cout << "PRE fails\n";
			cout << "*\n";
			continue;
		}

		// check suffix
		for (int i = 1; i < n; i++) {
			f = 1;
			for (int j = suff[i].length()-1, k = suff[0].length()-1; j >=  0; j--, k--) {
				if (suff[i][j] != suff[0][k]) {
					f = 0;
					break;
				}
			}

			if (!f) break;
		}

		if (!f) {
			// cout << "SUFF fails\n";
			cout << "*\n";
			continue;
		}

		string ans = pre[0];
		for (int i = 0; i < n; i++) {
			ans += mid[i];
		}

		ans += suff[0];

		cout << ans << "\n";
	}

	return 0;
}