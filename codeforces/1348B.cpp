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

		set <int> s;
		int t;
		for (int i = 0; i < n; i++) {
			cin >> t;

			s.insert(t);
		}

		if (s.size() > k) cout << -1 << "\n";

		else {
			for (int i = 1; i <= n; i++) {
				if (s.size() == k) break;
				s.insert(i);
			}

			string temp = "", ans = "";
			for (auto i : s) {
				temp += to_string(i);
				temp += ' ';
			}

			for (int i = 0; i < n; i++) ans += temp;

			cout << n*k << "\n" << ans << "\n";
		}
	}

	return 0;
}