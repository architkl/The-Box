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

// max length of correct bracket sequence,
// no. of unmatched open brackets,
// no. of unmatched closed brackets
vector <piii> tree(4*N_MAX);
string s;

void create_tree(int start, int end, int idx) {
	if (start == end) tree[idx] = mp(0, mp(s[start] == '(', s[start] == ')'));

	else {
		int mid = (start + end) / 2;
		create_tree(start, mid, 2*idx);
		create_tree(mid+1, end, 2*idx+1);

		// new brackets = min(unmatched open brackets on left, unmatched closed brackets on right)
		int a, b, c, new_brackets = min(tree[2*idx].second.first, tree[2*idx+1].second.second);

		// max length = length of seq in left child + length of seq in right child + 2 * new brackets
		a = tree[2*idx].first + tree[2*idx+1].first + 2*new_brackets;

		// unmatched open brackets = unmatched open brackets on right +
		// unmatched open brackets on left - new brackets
		b = tree[2*idx+1].second.first + tree[2*idx].second.first - new_brackets;

		// unmatched closed brackets = unmatched closed brackets on left +
		// unmatched closed brackets on right - new brackets
		c = tree[2*idx].second.second + tree[2*idx+1].second.second - new_brackets;

		tree[idx] = mp(a, mp(b, c));
	}
}

piii query(int start, int end, int l, int r, int idx) {
	// no overlap
	if (end < l || start > r) return mp(0, mp(0, 0));

	// complete overlap
	if (start <= l && r <= end) return tree[idx];

	// partial overlap
	int mid = (l + r) / 2;
	piii res_l = query(start, end, l, mid, 2*idx), res_r = query(start, end, mid+1, r, 2*idx+1);
	int a, b, c, new_brackets = min(res_l.second.first, res_r.second.second);

	a = res_l.first + res_r.first + 2*new_brackets;
	b = res_r.second.first + res_l.second.first - new_brackets;
	c = res_l.second.second + res_r.second.second  - new_brackets;

	return mp(a, mp(b, c));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	create_tree(0, s.length()-1, 1);

	int m;
	cin >> m;

	int l, r;
	while (m--) {
		cin >> l >> r;

		cout << query(l-1, r-1, 0, s.length()-1, 1).first << "\n";
	}

	return 0;
}