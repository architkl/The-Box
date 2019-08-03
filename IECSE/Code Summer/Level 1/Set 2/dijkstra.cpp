#include <iostream>
#include <vector>

using namespace std;

const int V_MAX = 1005;
const int INF = 999999999;

vector < pair <int, pair <int, int> > > G[V_MAX];

bool vis[V_MAX];
int dist[V_MAX];

void init()
{
	for (int i = 0; i < V_MAX; i++)
	{
		vis[i] = 0;
		dist[i] = INF;
	}
}

int minDist(int V)
{
	int mn = INF, mn_idx;
	for (int i = 1; i <= V; i++)
	{
		if (vis[i] == false && dist[i] < mn)
		{
			mn = dist[i];
			mn_idx = i;
		}
	}

	return mn_idx;
}

void Dijkstra(int src, int V)
{
	init();
	dist[src] = 0;

	int cur;
	for (int i = 0; i < V; i++)
	{
		cur = minDist(V);
		vis[cur] = true;

		for (auto j : G[cur])
		{
			if (dist[j.second.second] > dist[cur] + j.first)
				dist[j.second.second] = dist[cur] + j.first;
		}
	}
}

int main()
{
	int V, E;
	cin >> V >> E;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> w >> v;

		G[u].push_back(make_pair(w, make_pair(u, v)));
		G[v].push_back(make_pair(w, make_pair(v, u)));
	}

	for (int i = 1; i <= V; i++)
	{
		Dijkstra(1, V);

		for (int j = 1; j <= V; j++)
			cout << dist[j] << " ";

		cout < "\n";
	}

	return 0;
}