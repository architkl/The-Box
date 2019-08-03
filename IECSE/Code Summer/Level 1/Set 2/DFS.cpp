#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int V_MAX = 1005;

bool vis[1005];

vector <int> G[V_MAX];

void init()
{
	for (int i = 0; i < V_MAX; i++)
		vis[i] = 0;
}

void dfs(int cur, vector <int> &order1, vector <int> &order2)
{
	vis[cur] = true;

	order1.push_back(cur);

	sort(G[cur].begin(), G[cur].end());
	
	for (auto i : G[cur])
	{
		if (vis[i])
			continue;

		dfs(i, order);
	}

	order2.push_back(cur);
}

int main()
{
	int V, E;
	cin >> V >> E;

	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	init();

	vector <int> order1, order2;

	for (int i = 1; i <= V; i++)
	{
		if (vis[i])
			continue;
		
		dfs(i, order1, order2);
	}

	for (int i = 0; i < order1.size(); i++)
		cout << order1[i] << " ";
	cout << "\n";

	for (int i = 0; i < order2.size(); i++)
		cout << order2[i] << " ";
	cout <<"\n";

	return 0;
}