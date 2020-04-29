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

	int n, k;
	cin >> n >> k;

	vector <int> m(k+1), c(k+1);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;

		m[t]++;
	}

	for (int i = 1; i <= k; i++) cin >> c[i];

	vector <int> suff(k+1);
	suff[k] = m[k];
	int num = ceil(suff[k] / c[k]);
	for (int i = k-1; i > 0; i--) {
		suff[i] = suff[i+1] + m[i];

		num = max(num, (int)ceil((float)suff[i] / c[i]));
	}

	vector < vector <int> > ans(num);
	int j = 0;
	for (int i = 1; i <= k; i++) {
		while (m[i] > 0) {
			ans[j % num].pb(i);
			m[i]--;
			j++;
		}
	}

	cout << num << "\n";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << " ";
		for (auto j : ans[i]) cout << j << " ";

		cout << "\n";
	}

	return 0;
}

/*
4 3
1 2 2 3
4 1 1

1: 0
2: 2
3: 0

suff
2 1 1
1 1 0
1 1 0

ans
3 1
2
2

*/