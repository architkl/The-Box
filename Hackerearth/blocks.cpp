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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 2e5 + 5;
const int tree_size = 2 * (int)pow(2, floor(log2(N_MAX)) + 1);

vector <int> tree(tree_size);
vector <int> lazy(tree_size);
vector <int> A(N_MAX);

void build(int node, int start, int end)
{
	if (start == end)
		tree[node] = A[start];

	else
	{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
	if (lazy[node] != 0)
	{
		tree[node] = lazy[node];

		if (start != end)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node+1] = lazy[node];
		}

		lazy[node] = 0;
	}

	if (start > r || end < l)
		return;

	if (l <= start && end <= r)
	{
		tree[node] = val;

		if (start != end)
		{
			lazy[2*node] = val;
			lazy[2*node+1] = val;
		}

		return;
	}
	
	int mid = (start + end) / 2;
	updateRange(2*node, start, mid, l, r, val);
	updateRange(2*node+1, mid+1, end, l, r, val);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int queryRange(int node, int start, int end, int l, int r)
{
	if (start > r || end < l)
		return 0;

	if (lazy[node] != 0)
	{
		tree[node] = lazy[node];

		if (start != end)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node+1] = lazy[node];
		}

		lazy[node] = 0;
	}

	if (l <= start && end <= r)
		return tree[node];

	int mid = (start + end) / 2;
	int p1 = queryRange(2*node, start, mid, l, r);
	int p2 = queryRange(2*node+1, mid+1, end, l, r);
	return max(p1, p2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	build(1, 1, N_MAX);

	int l, h, p, c, x;
	for (int i = 0; i < N; i++)
	{
		cin >> l >> h >> p >> c >> x;

		if (c)
		{
			int mx = queryRange(1, 1, N_MAX, x, x+l-1);
			updateRange(1, 1, N_MAX, x, x+l-1, mx+1);
			updateRange(1, 1, N_MAX, x+p-1, x+p-1, mx+h+1);
		}

		else
		{
			int mx = queryRange(1, 1, N_MAX, x, x+l-1), temp = queryRange(1, 1, N_MAX, x+p-1, x+p-1);
			mx = max(mx+1, temp+h+1);
			updateRange(1, 1, N_MAX, x, x+l-1, mx);
		}
	}

	cout << queryRange(1, 1, N_MAX, 1, N_MAX) << "\n";

	return 0;
}