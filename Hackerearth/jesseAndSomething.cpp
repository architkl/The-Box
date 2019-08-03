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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 1e5+5;
const int tree_size = 2 * (int)pow(2, floor(log2(N_MAX)) + 1);

vector <int> A(N_MAX);
vector < vector <int> > tree(2, vector <int> (tree_size));

void build(int node, int start, int end, bool mx)
{
	if (start == end)
		tree[mx][node] = A[start];

	else
	{
		int mid = (start + end) / 2;
		build(2*node, start, mid, mx);
		build(2*node + 1, mid+1, end, mx);
		
		if (mx)
			tree[mx][node] = max(tree[2*node], tree[2*node+1]);

		else
			tree[mx][node] = min(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r, bool mx)
{
	if (l > end || r < start)
		return mx ? 0 : INT_MAX;

	if (l <= start && end <= r)
		return tree[mx][node];

	int mid = (start + end) / 2;
	int left = query(2*node, start, mid, l, r, mx);
	int right = query(2*node+1, mid+1, end, l, r, mx);

	return mx ? max(left, right) : min(left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	build(1, 1, N, 0);			// segment tree for min element
	build(1, 1, N, 1);			// segment tree for max element

	long long int ans = 0, t1, t2;
	int l = 0, r = 0;
	while (l <= r)
	{
		
	}

	return 0;
}