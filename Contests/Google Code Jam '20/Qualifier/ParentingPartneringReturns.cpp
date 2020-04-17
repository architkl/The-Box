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
	if (a.second.first == b.second.first) return (a.second.second < b.second.second);

	return (a.second.first < b.second.first);
}

bool comp2(piii a, piii b) {
	return (a.second.second <= b.second.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N;
	for (int x = 1; x <= T; x++) {
		cin >> N;

		vector <piii> act(N);
		int s, e;
		for (int i = 0; i < N; i++) {
			cin >> s >> e;

			act[i] = mp(i, mp(s, e));
		}

		sort(act.begin(), act.end(), comp);

		// for (int i = 0; i < N; i++) cout << act[i].first << " " << act[i].second << "\n";

		int c_act_end = -1, j_act_end = -1;
		bool f = 1;
		vector <int> c_acts, j_acts;
		for (int i = 0; i < N; i++) {
			if (act[i].second.first >= c_act_end) {
				c_acts.pb(act[i].first);
				c_act_end = act[i].second.second;
			}

			else if (act[i].second.first >= j_act_end) {
				j_acts.pb(act[i].first);
				j_act_end = act[i].second.second;
			}

			else {
				f = 0;
				break;
			}
		}

		string ans = "";
		if (f) {
			sort(c_acts.begin(), c_acts.end());
			sort(j_acts.begin(), j_acts.end());

			int a = 0, b = 0;
			while (a < c_acts.size() && b < j_acts.size()) {
				if (c_acts[a] < j_acts[b]) {
					ans += "C";
					a++;
				}

				else {
					ans += "J";
					b++;
				}
			}

			while (a < c_acts.size()) {
				ans += "C";
				a++;
			}

			while (b < j_acts.size()) {
				ans += "J";
				b++;
			}
		}

		else ans = "IMPOSSIBLE";

		cout << "Case #" << x << ": " << ans << "\n";
	}

	return 0;
}