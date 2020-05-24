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

	int t;
	cin >> t;

	int n, k;

	while (t--) {
		cin >> n >> k;

		int e1 = n-1, e2 = 0;
		vector <int> ans;
		for (int i = 0; i < n; i++) {
			if (i % 2) {
				ans.pb(e2);
				e2++;
			}

			else {
				ans.pb(e1);
				e1--;
			}
		}

		for (int i = 0; i < n; i++) {
			if (ans[i] == k) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}

/*
0 1 2 3 4
4 3 2 1 0
4 0 1 2 3
4 0 3 2 1
4 0 3 1 2
*/