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
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;

		vector <int> p(n), c(n);
		for (int i = 0; i < n; i++) cin >> p[i] >> c[i];

		bool f = 1;
		if (c[0] > p[0]) f = 0;

		else {
			for (int i = 1; i < n; i++) {
				if (p[i] < p[i-1] || c[i] < c[i-1] || c[i] > p[i]) {
					f = 0;
					break;
				}

				if (c[i] > c[i-1]) {
					if (p[i]-p[i-1] < c[i]-c[i-1]) {
						f = 0;
						break;
					}
				}
			}
		}

		if (f) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}