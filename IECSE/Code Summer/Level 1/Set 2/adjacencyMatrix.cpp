#include <iostream>

using namespace std;

const int V_MAX = 1005;
const int E_MAX = 1000005;

int adj_mat[V_MAX][V_MAX] = {};

int main()
{
	int V, E;
	cin >> V >> E;

	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		adj_mat[u][v] = 1;
		adj_mat[v][u] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << adj_mat[i][j];
		cout << "\n";
	}

	return 0;
}