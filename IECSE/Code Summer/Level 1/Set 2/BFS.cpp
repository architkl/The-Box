#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int V_MAX = 1005;

bool vis[V_MAX];

void init()
{
	for (int i = 0;  i < V_MAX; i++)
		vis[i] = 0;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector <int> G[V+1];
	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	init();

	for (int j = 1; j <= V; j++)
	{
		if (vis[j])
			continue;
		
		int q[V+5], f = 0, r = 1;

		q[f] = j;
		vis[q[f]] = true;
		cout << q[f] << " ";
		
		while (f < r)
		{
			int cur = q[f];

			sort(G[cur].begin(), G[cur].end());

			for (int i = 0; i < G[cur].size(); i++)
			{
				if (vis[G[cur][i]])
					continue;

				vis[G[cur][i]] = true;
				q[r] = G[cur][i];
				cout << q[r] << " ";
				r++;
			}
	        f++;
		}
	}

	return 0;
}