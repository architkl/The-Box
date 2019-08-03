#include <iostream>
#include <vector>
#include <utility>
#include <queue>

const int N_MAX = 5005;

bool vis[N_MAX];

void ini()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = false;
}

int main()
{
	int n;
	cin >> n;

	int u, v;
	vector < pair <int, int > > G[n];
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}

	queue <int> 
}