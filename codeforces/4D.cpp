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

bool comp(piii a, piii b) {
	return ((ll)a.second.first*a.second.second < (ll)b.second.first * b.second.second);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int n, w, h;
	cin >> n >> w >> h;

	int a, b;
	vector <piii> env;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (a > w && b > h)	env.pb(mp(i, mp(a, b)));
	}

	if ((int)env.size() != 0) {
		sort(env.begin(), env.end(), comp);

		vector <int> dp(env.size(), 1), prev(env.size(), -1);
		for (int i = 1; i < env.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (env[j].second.first < env[i].second.first && env[j].second.second < env[i].second.second) {
					if (dp[j]+1 > dp[i]) {
						dp[i] = dp[j]+1;
						prev[i] = j;
					}
				}
			}
		}

		int chain = *(max_element(dp.begin(), dp.end())), idx = -1;
		vector <int> ans;

		for (int i = 0; i < dp.size(); i++) {
			if (dp[i] == chain) {
				idx = i;
				break;
			}
		}

		while (idx != -1) {
			ans.pb(env[idx].first+1);
			idx = prev[idx];
		}

		reverse(ans.begin(), ans.end());

		cout << chain << "\n";
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}

	else cout << 0 << "\n";

	return 0;
}

/*
5 4
9 8
12 11

1 2 3

5 1000
6 9
500 5
9 10
14 15
16 17

1 1 1 2 3 4
*/