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

	ll a, b, q;
	while (t--) {
		cin >> a >> b >> q;

		if (b < a) {
			int c = b;
			b = a;
			a = c;
		}

		ll l, r, lcm = (a*b) / __gcd(a, b);
		ll ans;
		while (q--) {
			cin >> l >> r;

			ans = 0;

			if (b % a == 0) cout << 0 << " ";

			else {
				ll m1 = (l / lcm) * lcm, m2 = (r / lcm) * lcm;

				ans += max(0ll, m1+b-l);
				ans += min(b, r-m2+1);

				m1 += lcm;
				ans += (m2/lcm - m1/lcm)*b;

				cout << r-l+1-ans << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}