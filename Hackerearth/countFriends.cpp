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
typedef long long ll;

const int  N_MAX = 1e5+5;

vector <int> parent(N_MAX);
vector <int> children(N_MAX);
vector <int> dsu_rank(N_MAX);

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
	init();

	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		dsu_union(u, v);
	}

	for (int i = 1; i <= N; i++)
		cout << children[find_parent(i)] << " ";
	cout << "\n";

	return 0;
}