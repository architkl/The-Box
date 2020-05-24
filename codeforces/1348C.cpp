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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n, k;
	while (t--) {
		cin >> n >> k;

		string s;
		cin >> s;

		sort(s.begin(), s.end());

		set <char> myset;
		for (auto i : s) myset.insert(i);

		vector <string> poss(k, "");
		for (int i = 0; i < k; i++) poss[i] += s[i];

		if (poss[k-1] != poss[0]) cout << poss[k-1] << "\n";

		else {
			if (myset.size() == 1) {
				int s_itr = k, poss_itr = 0;
				while (s_itr < n) {
					poss[poss_itr] += s[s_itr];
					
					poss_itr++;
					poss_itr %= k;
					s_itr++;
				}

				cout << poss[(poss_itr-1+k)%k] << "\n";
			}

			else if (myset.size() == 2) {
				char c = s[0];
				int cnt1 = 0, cnt2 = 0;
				for (int i = 0; i < n; i++) {
					if (s[i] == c) cnt1++;
					else cnt2++;
				}

				int s_itr = k, poss_itr = 0;
				if (cnt1 == k) {
					while (s_itr < n) {
						poss[poss_itr] += s[s_itr];
						
						poss_itr++;
						poss_itr %= k;
						s_itr++;
					}

					cout << poss[(poss_itr-1+k)%k] << "\n";
				}

				else {
					while (s_itr < n) {
						poss[0] += s[s_itr];

						s_itr++;
					}

					cout << poss[0] << "\n";
				}
			}

			else {
				for (int i = k; i < s.size(); i++) poss[0] += s[i];

				cout << poss[0] << "\n";
			}
		}
	}

	return 0;
}