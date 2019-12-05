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

vector <pii> tree(tree_size);
vector <int> A(N_MAX);

void build(int node, int start, int end)
{
	if (start == end)
		tree[node] = mp(A[start], 0);

	else
	{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		pii l = tree[2*node], r = tree[2*node+1];
		tree[node] = mp((l.first + r.first) % 10, l.second + r.second + ((l.first + r.first) >= 10));
	}
}

pii query(int node, int start, int end, int l, int r)
{
	if (r < start || l > end)
		return mp(0, 0);

	if (l <= start && end <= r)
		return tree[node];

	int mid = (start + end) / 2;
	pii p1 = query(2*node, start, mid, l, r);
	pii p2 = query(2*node+1, mid+1, end, l, r);

	return mp((p1.first + p2.first) % 10, p1.second + p2.second + ((p1.first + p2.first) >= 10));
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	build(1, 0, n-1);

	int q;
	cin >> q;

	int l, r;
	while (q--)
	{
		cin >> l >> r;

		cout << query(1, 0, n-1, l-1, r-1).second << "\n";
	}

	return 0;
}