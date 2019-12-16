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

bool comp(pii a, pii b) {
	return (a.second < b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N, l, r;
	while (T--) {
		cin >> N;

		int machine_learning = 0, ans = INT_MAX;
		unordered_map <int, int> intervals_that_start_at;
		vector <pii> interval(N);
		set <int> kuchhBhi, onlyStarts;
		for (int i = 0; i < N; i++) {
			cin >> l >> r;

			machine_learning = max(machine_learning, r);

			interval[i] = mp(l, r);

			onlyStarts.insert(l);

			intervals_that_start_at[l]++;
		}

		if (machine_learning < 1e6+5) {
			vector <int> mera_range(machine_learning+5);
			for (int i = 0; i < N; i++) {
				mera_range[interval[i].first]++;
				mera_range[interval[i].second+1]--;
			}

			for (int i = 1; i < mera_range.size(); i++) mera_range[i] += mera_range[i-1];

			sort(interval.begin(), interval.end(), comp);

			set <int>::iterator it = onlyStarts.begin();
			for (int i = 0; i < N; i++) {
				while (it != onlyStarts.end() && *it <= interval[i].second) it++;

				if (it == onlyStarts.end()) break;

				ans = min(ans, mera_range[*it] - intervals_that_start_at[*it]);
			}
		}

		else {
			for (int i = 0; i < N; i++) {
				kuchhBhi.insert(interval[i].first);
				kuchhBhi.insert(interval[i].second+1);
			}
			
			unordered_map <int, int> pos;
			set <int>::iterator it = kuchhBhi.begin();
			for (int i = 0; it != kuchhBhi.end(); i++, it++) pos[*it] = i;

			vector <int> pre(kuchhBhi.size());
			for (int i = 0; i < N; i++) {
				pre[pos[interval[i].first]]++;
				pre[pos[interval[i].second+1]]--;
			}

			for (int i = 1; i < pre.size(); i++) pre[i] += pre[i-1];

			sort(interval.begin(), interval.end(), comp);
			it = onlyStarts.begin();
			int n_r;
			for (int i = 0; i < N; i++) {
				while (it != onlyStarts.end() && *it <= interval[i].second) it++;

				if (it == onlyStarts.end()) break;

				n_r = *it;

				ans = min(ans, pre[pos[n_r]] - intervals_that_start_at[n_r]);
			}
		}

		if (ans == N-1 || ans == INT_MAX) ans = -1;

		cout << ans << "\n";
	}

	return 0;
}

/*
1
7
1 10
3 50
5 20
6 45
15 30
25 35
32 55

1
9
1 10
2 10
3 10
4 15
4 23
2 17
20 25
20 30
20 27
*/