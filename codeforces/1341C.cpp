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

	int n;
	while (t--) {
		cin >> n;

		vector <int> p(n+1), idx(n+1);
		for (int i = 1; i <= n; i++) {
			cin >> p[i];

			idx[p[i]] = i;
		}

		int cur = 1, it, end = n+1, cnt;
		bool f = 1;
		while (cur <= n) {
			it = idx[cur]+1;
			cnt = 1;

			while (it < end) {
				if (p[it] != p[it-1]+1) {
					f = 0;
					break;
				}

				cnt++;
				it++;
			}

			if (!f) break;

			end = idx[cur];
			cur = cur+cnt;
		}

		if (f) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}