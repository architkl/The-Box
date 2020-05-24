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

	int m, n;
	cin >> n >> m;

	multiset <int> a;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;

		a.insert(x);
	}

	vector <int> ans;
	multiset <int>::iterator it;
	while (!a.empty()) {
		it = a.end();
		it--;

		x = *it;

		ans.pb(x);
		a.erase(it);

		if (x != 0) a.insert(x/2);
	}

	int q;
	while (m--) {
		cin >> q;

		cout << ans[q-1] << "\n";
	}

	return 0;
}