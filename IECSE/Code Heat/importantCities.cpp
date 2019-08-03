#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 10005;

bool vis[N_MAX], ap[N_MAX];
int disc[N_MAX], low[N_MAX], parent[N_MAX];
vector < pair <int, int> > G[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		vis[i] = ap[i] = false;
		parent[i] = -1;
		G[i].clear();
	}
}

void find_AP(int u)
{
	static int time = 1;
	int child = 0, v;

	vis[u] = true;
	disc[u] = low[u] = time++;

	for (auto i : G[u])
	{
		v = i.second;

		if (!vis[v])
		{
			parent[v] = u;
			child++;

			find_AP(v);

			low[u] = min(low[u], low[v]);

			if (parent[u] == -1 && child > 1)
				ap[u] = true;

			else if (parent[u] != -1 && low[v] >= disc[u])
				ap[u] = true;
		}

		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

int main()
{
	int T;
	cin >> T;

	int n, m;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;

		init();

		int u, v;
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v;
			
			G[u].push_back(make_pair(u, v));
			G[v].push_back(make_pair(v, u));
		}

		for (int j = 1; j <= n; j++)
			if (!vis[j])
				find_AP(j);
		
		int cnt = 0;
		for (int j = 1;j <= n; j++)
			if (ap[j])
				cnt++;

		cout << cnt << "\n";
	}

	return 0;
}