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

const int N_MAX = 1e5+5;

// idx, min, max
vector <piii> tree(4*N_MAX);
vector <pii> A(N_MAX);
vector <int> lazy(4*N_MAX);

bool comp(pii a, pii b) {
	return (a.first > b.first);
}

void build(int start, int end, int idx) {
	if (start == end) tree[idx] = mp(A[start].second, mp(A[start].first, A[start].first));

	else {
		int mid = (start + end) / 2;
		build(start, mid, 2*idx);
		build(mid+1, end, 2*idx+1);

		tree[idx].first = 0;
		tree[idx].second.first = min(tree[2*idx].second.first, tree[2*idx+1].second.first);
		tree[idx].second.second = max(tree[2*idx].second.second, tree[2*idx+1].second.second);
	}

	// cout << start << " " << end << " " << tree[idx].second.first << " " << tree[idx].second.second << "\n";
}

void update(int x, int nl, int nr, int idx, int val) {
	if (lazy[idx] != 0) {
		tree[idx].second.first += lazy[idx];
		tree[idx].second.second += lazy[idx];

		if (nl != nr) {
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}

		lazy[idx] = 0;

		// cout << "Lazy update\n";
		// cout << nl << " " << nr << " " << tree[idx].second.first << " " << tree[idx].second.second << "\n";
	}

	// if min element > x update all
	if (tree[idx].second.first > x) {
		tree[idx].second.first += val;
		tree[idx].second.second += val;

		if (nl != nr) {
			lazy[2*idx] += val;
			lazy[2*idx+1] += val;
		}

		// cout << "HIT update\n";
		// cout << nl << " " << nr << " " << tree[idx].second.first << " " << tree[idx].second.second << "\n";

		return;
	}

	// if max element <= x no update
	if (tree[idx].second.second <= x) {
		// cout << "No Updates\n";
		// cout << nl << " " << nr << " " << tree[idx].second.first << " " << tree[idx].second.second << "\n";
		return;
	}

	int mid = (nl + nr) / 2;
	update(x, nl, mid, 2*idx, val);
	update(x, mid+1, nr, 2*idx+1, val);
	
	tree[idx].second.first = min(tree[2*idx].second.first, tree[2*idx+1].second.first);
	tree[idx].second.second = max(tree[2*idx].second.second, tree[2*idx+1].second.second);

	// cout << "Child Update\n";
	// cout << nl << " " << nr << " " << tree[idx].second.first << " " << tree[idx].second.second << "\n";
}

piii query(int idx, int nl, int nr, int n_idx) {
	if (lazy[n_idx] != 0) {
		tree[n_idx].second.first += lazy[n_idx];
		tree[n_idx].second.second += lazy[n_idx];

		if (nl != nr) {
			lazy[2*n_idx] += lazy[n_idx];
			lazy[2*n_idx+1] += lazy[n_idx];
		}

		lazy[n_idx] = 0;
	}

	// no overlap
	if (nl > idx || idx > nr) return mp(-1, mp(0, 0));

	// complete overlap
	if (idx <= nl && nr <= idx) return tree[n_idx];

	// partial overlap
	int mid = (nl + nr) / 2;
	piii res_l = query(idx, nl, mid, 2*n_idx), res_r = query(idx, mid+1, nr, 2*n_idx+1);
	
	if (res_l.first != -1) return res_l;
	else return res_r;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int N;
	cin >> N;

	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;

		A[i] = mp(t, i);
	}

	sort(A.begin(), A.begin()+N);

	build(0, N-1, 1);

	int M, X;
	cin >> M;

	while (M--) {
		cin >> X;

		update(X, 0, N-1, 1, -1);
	}

	vector <int> res(N);
	piii temp;
	for (int i = 0; i < N; i++) {
		temp = query(i, 0, N-1, 1);
		
		res[temp.first] = temp.second.first;
	}

	for (int i = 0; i < N; i++) cout << res[i] << " ";
	cout << "\n";

	return 0;
}