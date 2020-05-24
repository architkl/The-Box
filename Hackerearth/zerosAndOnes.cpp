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

const int N_MAX = 1e6+5;

// no. of ones in [l, r]
vector <int> tree(4*N_MAX);
vector <int> A(N_MAX, 1);

void build(int l, int r, int idx) {
	if (l == r) tree[idx] = 1;

	else {
		int mid = (l + r) / 2;
		build(l, mid, 2*idx);
		build(mid+1, r, 2*idx+1);

		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
}

void update(int l, int r, int t_id, int idx, int val) {
	if (l == r) A[idx] = tree[t_id] = val;

	else {
		int mid = (l + r) / 2;

		if (l <= idx && idx <= mid)	update(l, mid, 2*t_id, idx, val);
		else update(mid+1, r, 2*t_id+1, idx, val);

		tree[t_id] = tree[2*t_id] + tree[2*t_id+1];
	}
}

int query(int l, int r, int t_l, int t_r, int idx) {
	// cout << l << " " << r << " " << t_l << " " << t_r << " " << tree[idx] << "\n";
	if (l > t_r || r < t_l) return 0;

	if (l <= t_l && t_r <= r) return tree[idx];

	int mid = (t_l + t_r) / 2;
	int res_l = query(l, r, t_l, mid, 2*idx), res_r = query(l, r, mid+1, t_r, 2*idx+1);

	return (res_l + res_r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	build(0, N-1, 1);

	int Q;
	cin >> Q;

	int c, k;
	while (Q--) {
		cin >> c >> k;

		if (c == 0) update(0, N-1, 1, k-1, 0);

		else if (query(0, N-1, 0, N-1, 1) < k || query(0, N-1, 0, N-1, 1) == 0) cout << -1 << "\n";

		else {
			int l = 0, r = N-1, mid;
			while (l < r) {
				mid = (l + r) / 2;
				// cout << "l: " << l << " " << "r: " << r << " " << "mid: " << mid << "\n";

				if (query(0, mid, 0, N-1, 1) >= k) r = mid;
				else l = mid+1;
			}

			if (l == 0) cout << 1 << "\n";
			else if (query(0, l-1, 0, N-1, 1) == k) cout << l << "\n";
			else cout << l+1 << "\n";
		}
	}

	return 0;
}