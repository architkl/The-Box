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

bool comp(ll a, ll b) {
	return (a > b);
}

ll pow_er(int k, int p) {
	ll temp = 1;

	while (p--) temp *= k;

	return temp;
}

int main() {
	int t;
	cin >> t;

	int n, k;
	while (t--) {
		cin >> n >> k;

		vector <ll> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end(), comp);

		ll mx_dig = ceil(log10(a[0]) / log10(k));
		cout << mx_dig << "\n";
		vector <int> used(100);

		bool f;
		for (int i = 0; i < n; i++) {
			f = 0;
			for (int j = mx_dig; j >= 0; j--) {
				if (used[j] == 0 && (a[i] - pow_er(k, j)) >= 0) {
					a[i] -= pow_er(k, j);
					used[j] = 1;
				}

				if (a[i] == 0) {
					f = 1;
					break;
				}
			}

			if (!f) break;
		}

		if (f) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}