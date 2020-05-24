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

		string s;
		cin >> s;

		map <char, int> last_occ;
		set <char> c;
		for (int i = 0; i < n; i++) {
			if (last_occ.find(s[i]) == last_occ.end()) last_occ.insert(mp(s[i], 0));
			
			last_occ[s[i]] = i;
			c.insert(s[i]);
		}

		int start = INT_MAX;
		set <char> d;
		for (auto i : last_occ) start = min(start, i.second);

		int ans = 0;
		for (int i = start; i < n; i++) {
			ans++;
			d.insert(s[i]);

			if (d.size() == c.size()) break;
		}

		cout << ans << "\n";
	}

	return 0;
}