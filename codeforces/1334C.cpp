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
	
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;

		vector <ll> a(n), b(n);
		ll ans = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}

		vector <ll> dep(n);
		dep[0] = max(0ll, a[0] - b[n-1]);
		ll sum = dep[0];
		for (int i = 1; i < n; i++) {
			dep[i] = max(0ll, a[i] - b[i-1]);
			sum += dep[i];
		}

		for (int i = 0; i < n; i++) {
			ans = min(ans, sum-dep[i]+a[i]);
		}

		cout << ans << "\n";
	}

	return 0;
}