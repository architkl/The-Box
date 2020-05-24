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

		vector <ll> odd;
		ll t, ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> t;

			if (t % 2) odd.pb(t);
			else ans += t;
		}

		sort(odd.begin(), odd.end());

		int sz = odd.size();
		int i  = (sz % 2) ? 1 : 0;
		while (i < sz) ans += odd[i++];

		cout << ans << "\n";
	}

	return 0;
}