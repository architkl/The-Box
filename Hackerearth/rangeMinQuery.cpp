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

const int N_MAX = 1e5+5;
const int tree_size = 2*(int)pow(2, floor(log2(N_MAX))+1) - 1;

vector <int> tree(tree_size);
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
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, int val)
{
	if (start == end)
	{
		A[idx] = val;
		tree[node] = val;
	}
	
	else
	{
		int mid = (start + end) / 2;

		if (idx <= mid)
			update(2*node, start, mid, idx, val);

		else
			update(2*node+1, mid+1, end, idx, val);
		
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if (r < start || l > end)
		return INT_MAX;

	if (l <= start && end <= r)
		return tree[node];

	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1, p2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	build(1, 0, N-1);

	char q;
	int a, b;
	while (Q--)
	{
		cin >> q >> a >> b;

		if (q == 'q')
			cout << query(1, 0, N-1, a-1, b-1) << "\n";
		
		else
			update(1, 0, N-1, a-1, b);
	}

	return 0;
}