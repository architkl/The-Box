#include <iostream>
#include <set>

using namespace std;

int main()
{
	int V, E;
	cin >> V >> E;

	set <int> G[V+1];
	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		G[u].insert(v);
		G[v].insert(u);
	}

	for (int i = 1; i <= V; i++)
	{
		for (auto j : G[i])
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}