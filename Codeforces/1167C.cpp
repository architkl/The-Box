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

const int N_MAX = 5e5 + 5;

int parent[N_MAX];
int children[N_MAX];
int dsu_rank[N_MAX];

void init()
{
    for (int i = 0; i < N_MAX; i++)
    {
        parent[i] = i;
        children[i] = 0;
        dsu_rank[i] = 0;
    }
}

int find_parent(int x)
{
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);

    return parent[x];
}

void dsu_union(int x, int y)
{
    int px = find_parent(x), py = find_parent(y);

    if (px == py)
        return;

    if (dsu_rank[px] > dsu_rank[py])
    {
        parent[py] = px;
        children[px] += children[py] + 1;
    }

    else
    {
        parent[px] = py;
        children[py] += children[px] + 1;
    }

    if (dsu_rank[px] == dsu_rank[py])
        dsu_rank[py]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int n, m;
	cin >> n >> m;

	int x, y, z;
	for (int i = 0; i < m; i++)
	{
		cin >> x;

		if (x != 0)
			cin >> y;

		for (int j = 1; j < x; j++)
		{
			cin >> z;
			dsu_union(y, z);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << children[find_parent(i)] + 1 << " ";
	}

	cout << "\n";

	return 0;
}