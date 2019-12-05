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

		int div = n, res = 1, sq = sqrt(n);
		vector <int> ans(1);
		for (int k = 1; k <= sq; k++) {
			ans.pb(k);
			res++;

			if (n/k == k) continue;

			ans.pb(n/k);
			res++;
		}

		sort(ans.begin(), ans.end());

		cout << res << "\n";
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}

	return 0;
}