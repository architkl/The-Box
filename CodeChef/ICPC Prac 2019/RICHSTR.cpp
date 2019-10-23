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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	int T;
	cin >> T;

	int N, Q;
	while (T--) {
		cin >> N >> Q;

		string s;
		cin >> s;

		vector <bool> ans(N);

		if (N >= 3) {
			unordered_map <char, int> freq;
			freq[s[0]]++;
			freq[s[1]]++;
			freq[s[2]]++;

			for (auto itr : freq) if (itr.second > 1) ans[0] = true;

			for (int i = 3; i <= N; i++) {
				freq[s[i-3]]--;
				freq[s[i]]++;

				if (freq[s[i-3]] == 0) freq.erase(s[i-3]);

				for (auto itr : freq) if (itr.second > 1) ans[i-2] = true;
			}
		}

		vector <int> pre(N);
		pre[0] = ans[0];
		for (int i = 0; i < N; i++) pre[i] = pre[i-1] + ans[i];

		int l, r;
		while (Q--) {
			cin >> l >> r;

			l--;
			r--;

			if (r-l+1 < 3) {
				cout << "NO\n";
				continue;
			}

			// cout << ans[l] << " " << ans[r-2] << "\n";

			if (pre[r-2] - pre[l] > 0 || ans[l]) cout << "YES\n";

			else cout << "NO\n";
		}
	}

	return 0;
}