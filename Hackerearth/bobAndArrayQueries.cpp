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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

const int N_MAX = 5e5+5;
const int tree_size = 2 * (int)pow(2, ceil(log2(N_MAX))) - 1;

vector <int> tree(tree_size);

void update(int node, int start, int end, int idx, bool op)
{
	if (start == end)
	{
		if (op)
			tree[node]++;

		else
			tree[node] = max(0, tree[node] - 1);
		
		return;
	}

	int mid = (start + end) / 2;
	if (idx <= mid)
		update(2*node, start, mid, idx, op);

	else
		update(2*node+1, mid+1, end, idx, op);

	tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int l, int r)
{
	if (l > end || r < start)
		return 0;

	if (l <= start && r >= end)
		return tree[node];

	int mid = (start + end) / 2;
	int l_child = query(2*node, start, mid, l, r);
	int r_child = query(2*node+1, mid+1, end, l, r);

	return (l_child + r_child);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q;
	cin >> N >> Q;

	int C, X, Y;
	while (Q--)
	{
		cin >> C >> X;

		if (C == 3)
		{
			cin >> Y;

			cout << query(1, 1, N, X, Y) << "\n";
		}

		else
			update(1, 1, N, X, C % 2);
	}

	return 0;
}