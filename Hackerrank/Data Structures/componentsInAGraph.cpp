#include <iostream>

using namespace std;

const int N_MAX = 30005;

int parent[N_MAX];
int dsu_rank[N_MAX];
int children[N_MAX];

void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		dsu_rank[i] = 0;
		children[i] = 0;
	}
}

int find_set(int x)
{
	if (parent[x] != x)
		parent[x] = find_set(parent[x]);

	return parent[x];
}

void union_set(int x, int y)
{
	int px = find_set(x), py = find_set(y);

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
	int N;
	cin >> N;

	make_set(2*N);

	int u, v;
	for (int i = 0; i < N; i++)
	{
		cin >> u >> v;

		union_set(u, v);
	}

	int mx = children[find_set(1)], i = 2;
	while (i <= 2*N)
	{
		if (children[find_set(i)] > mx)
			mx = children[find_set(i)];

		i++;
	}

	i = 1;
	while (children[find_set(i)] < 1)
		i++;

	int mn = children[find_set(i)];
	while (i <= 2*N)
	{
		if (children[find_set(i)] < mn && children[find_set(i)] >= 1)
			mn = children[find_set(i)];

		i++;
	}

	cout << mn + 1 << " " << mx + 1 << "\n";

	return 0;
}