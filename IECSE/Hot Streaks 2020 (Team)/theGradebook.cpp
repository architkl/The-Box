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

	int p, q;
	cin >> p >> q;

	vector <string> v(p);
	for (int i = 0; i < p; i++) cin >> v[i];

	set <int> ans;
	for (int i = 0; i < q; i++) {
		vector <int> arr;
		arr.pb(0);
		int mx = v[0][i];
		for (int j = 1; j < p; j++) {
			if (v[j][i] > mx) {
				mx = v[j][i];
				arr.clear();
				arr.pb(j);
			}

			else if (v[j][i] == mx) arr.pb(j);
		}

		for (auto j : arr) ans.insert(j);
	}

	cout << ans.size() << "\n";

	return 0;
}