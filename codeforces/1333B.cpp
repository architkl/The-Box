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
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		if (a[0] != b[0]) cout << "NO\n";

		else {
			vector <bool> ones(n), m_ones(n);
			for (int i = 1; i < n; i++) {
				ones[i] = ones[i-1] || (a[i-1] == 1);
				m_ones[i] = m_ones[i-1] || (a[i-1] == -1);
			}

			bool f = 1;
			for (int i = n-1; i > 0; i--) {
				if (a[i] < b[i]) {
					if (ones[i]) continue;
				}

				else if (a[i] > b[i]) {
					if (m_ones[i]) continue;
				}

				else if (a[i] == b[i]) {
					continue;
				}
				
				f = 0;
				break;
			}

			if (f) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}