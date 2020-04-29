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

		vector <int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector <int> pre(n);
		for (int i = 1; i < n-1; i++) {
			pre[i] = pre[i-1];

			if (a[i] > a[i-1] && a[i] > a[i+1]) pre[i]++;
		}

		pre[n-1] = pre[n-2];

		int mx = INT_MIN, idx, i = 0, j = k-1;
		while (j < n) {
			if (pre[j-1] - pre[i] > mx) {
				mx = pre[j-1] - pre[i];
				idx = i;
			}

			i++;
			j++;
		}

		cout << mx+1 << " " << idx+1 << "\n";
	}

	return 0;
}