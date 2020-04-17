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
#include <cstdlib>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;

int main() {
	ll u, v;
	cin >> u >> v;

	if (u > v) {
		cout << -1 << "\n";
		exit(0);
	}

	if (u == 0 && v == 0) {
		cout << 0 << "\n";
		exit(0);
	}

	vector <bool> bin_u, bin_v;

	ll x = v;
	while (x) {
		bin_v.pb(x % 2);
		x /= 2;
	}

	reverse(bin_v.begin(), bin_v.end());

	x = u;
	while (x) {
		bin_u.pb(x % 2);
		x /= 2;
	}

	while (bin_u.size() != bin_v.size()) bin_u.pb(0);

	reverse(bin_u.begin(), bin_u.end());

	if (bin_u.back() ^ bin_v.back() == 1) {
		cout << -1 << "\n";
		exit(0);
	}

	vector <int> nums(bin_v.size());
	int pos = 0;
	bool flag = 1, c = 0;
	while (pos < nums.size()) {
		if (bin_u[pos] == 0 && bin_v[pos] == 0) {
			nums[pos] = 0;
			if (c) nums[pos] += 2;

			c = 0;
		}

		else if (bin_u[pos] == 0 && bin_v[pos] == 1) {
			nums[pos] = 0;

			if (c) nums[pos] += 2;

			c = 1;
		}

		else if (bin_u[pos] == 1 && bin_v[pos] == 0) {
			nums[pos] = 1;

			// if (c) nums[pos] += 2;

			c = 1;
		}

		else {
			nums[pos] = 1;
			if (c) nums[pos] += 2;

			c = 0;
		}

		pos++;
	}

	// for (auto i : bin_u) cout << i << " ";
	// cout << "\n";

	// for (auto i : bin_v) cout << i << " ";
	// cout << "\n";

	// for (auto i : nums) cout << i << " ";
	// cout << "\n";

	int ans = *max_element(nums.begin(), nums.end());

	cout << ans << "\n";

	vector <ll> arr(ans);
	reverse(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		int j = 0;
		while (nums[i]) {
			arr[j] += pow(2, i);
			j++;
			nums[i]--;
		}
	}

	for (auto i : arr) cout << i << " ";
	cout << "\n";

	return 0;
}