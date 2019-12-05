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

int main() {
	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;

		vector <int> p(n), idx(n+1), ans(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];

			idx[p[i]] = i;
		}

		int mx = idx[1], mn = idx[1];
		for (int i = 1; i <= n; i++) {
			if (idx[i] < mn) mn = idx[i];
			else if (idx[i] > mx) mx = idx[i];

			if (mx-mn == i-1) ans[i-1] = 1;
		}

		for (int i = 0; i < n; i++) cout << ans[i];
		cout << "\n";
	}

	return 0;
}