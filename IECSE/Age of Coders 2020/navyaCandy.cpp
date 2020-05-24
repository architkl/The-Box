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

bool comp(pii a, pii b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector <pii> c(m);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		c[i] = mp(b, a);
	}

	sort(c.begin(), c.end(), comp);

	ll ans = 0;
	int boxes = 0;
	for (int i = 0; i < m; i++) {
		// cout << c[i].second << " " << c[i].first << "\n";
		if (n-boxes < c[i].second) {
			// cout << "last " << c[i].first * (n-boxes) << "\n";
			ans += (n-boxes)*c[i].first;
			break;
		}

		else {
			ans += c[i].first*c[i].second;
			boxes += c[i].second;
		}
	}

	cout << ans << "\n";

	return 0;
}