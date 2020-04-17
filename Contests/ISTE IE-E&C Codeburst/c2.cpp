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

int main() {
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector < vector <int> > pre(n+1, vector <int> (26));
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) pre[i+1][j] = pre[i][j];
		pre[i+1][s[i]-65]++;
	}

	int l, r, f, res = 0;
	while (q--) {
		cin >> l >> r;
		// l++;
		// r++;

		f = 0;
		for (int j = 0; j < 26; j++) {
			// cout << ((pre[r][j] - pre[l-1][j]) % 2) << "\n";
			f += ((pre[r][j] - pre[l-1][j]) % 2);
		}

		if (f <= 1) res++;
	}

	cout << res << "\n";

	return 0;
}