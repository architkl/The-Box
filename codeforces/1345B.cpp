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

	set <ll> cards;
	ll x;
	for (int i = 1; ; i++) {
		x = (i * (3*i + 1)) / 2;

		if (x > 1e9) break;

		cards.insert(x);
	}

	int t;
	cin >> t;

	ll n;
	while (t--) {
		cin >> n;

		set <ll>::iterator it;
		int ans = 0;
		while (n >= 2) {
			ans++;

			it = cards.lower_bound(n);

			if (it == cards.end()) it--;

			if (*it > n) it--;

			n -= *it;
		}

		cout << ans << "\n";
	}

	return 0;
}