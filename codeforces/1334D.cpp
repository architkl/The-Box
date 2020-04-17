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

	ll n, l, r;
	while (T--) {
		cin >> n >> l >> r;

		ll size = 2*n-2, len = 2*n-2, row = 1;
		while (l > len) {
			if (row == n-1) break;

			row++;
			size -= 2;
			len += size;
		}

		len -= size;
		len++;

		bool f = 0;
		for (int i = row; i < n; i++) {
			for (int j = 1; i+j <= n; j++) {
				if (len > r) {
					f = 1;
					break;
				}

				if (len >= l && len <= r) cout << i << " ";
				len++;

				if (len >= l && len <= r) cout << i+j << " ";
				len++;
			}

			if (f) break;
		}

		if (len == r) cout << 1;

		cout << "\n";
	}

	return 0;
}