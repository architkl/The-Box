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

	int n;
	cin >> n;

	vector <ll> a(n), pre(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre[i+1] = pre[i] + a[i];
	}

	ll ans = 0;
	int ri = 0;
	set <ll> sums = {0};
	for (int i = 0; i < n; i++) {
		int j = max(ri, i);
		for (j = ri; j < n; j++) {
			if (sums.find(pre[j+1]) != sums.end()) break;

			sums.insert(pre[j+1]);
		}

		ans += (ll)j-i;
		ri = j;
		sums.erase(pre[i]);
	}

	cout << ans << "\n";

	return 0;
}