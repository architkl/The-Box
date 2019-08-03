#include <iostream>

using namespace std;

const int N_MAX = 100005;
const int M_MAX = 100005;

int parent[N_MAX];
int dsu_rank[N_MAX];

void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		dsu_rank[i] = 0;
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
	int px = parent[x], py = parent[y];

	if (dsu_rank[px] > dsu_rank[py])
		parent[py] = px;
	
	else
		parent[px] = py;

	if (dsu_rank[px] == dsu_rank[py])
		dsu_rank[py]++;
}

int main()
{
	int T;
	cin >> T;

	int n, m;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;

		make_set(n);

		int u ,v, f = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v;

			if (find_set(u) == find_set(v))
				f = 1;

			union_set(u, v);
		}

		if (f)
			cout << "No\n";

		else
			cout << "Yes\n";
	}

	return 0;
}