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

const int N_MAX = 1e5 + 5;
const int tree_size = 2 * (int)pow(2, floor(log2(N_MAX)) + 1);

vector < vector < bitset <5001> > > tree(2, vector < bitset <5001> > (tree_size));
vector < vector <int> > arr(2, vector <int> (N_MAX));

void build(int node, int start, int end, int idx)
{
	// cout << start << " " << end << "\n";
	if (start == end)
		tree[idx][node].set(arr[idx][start]);

	else
	{
		int mid = (start + end) / 2;
		build(2*node, start, mid, idx);
		build(2*node+1, mid+1, end, idx);
		tree[idx][node] = tree[idx][2*node] | tree[idx][2*node+1];
	}
}

bitset <5001> query(int node, int start, int end, int l, int r, int idx)
{
	// cout << start << " " << end << "\n";
	if (l > end || r < start)
		return bitset <5001> ();

	if (l <= start && end <= r)
		return tree[idx][node];

	int mid = (start + end) / 2;
	bitset <5001> temp = query(2*node, start, mid, l, r, idx);
	temp = temp | query(2*node+1, mid+1, end, l, r, idx);

	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	build(1, 0, N-1, 0);
	build(1, 0, N-1, 1);

	int Q, a, b, c, d;
	cin >> Q;

	while (Q--)
	{
		cin >> a >> b >> c >> d;

		bitset <5001> ans = query(1, 0, N-1, a-1, b-1, 0);
		bitset <5001> temp = query(1, 0, N-1, c-1, d-1, 1);
		
		ans = ans | temp;

		cout << ans.count() << "\n";
	}

	return 0;
}