#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N_MAX = 100005;

bool vis[N_MAX];

vector < pair <int, int> > G[N_MAX];

int arr[N_MAX][2];

void ini()
{
	for (int i = 0; i < N_MAX; i++)
	{
		arr[i][0] = i;
		arr[i][1] = 0;
		vis[i] = false;
	}
}

int dfs(int x, int parent)
{
	vis[x] = true;
	//cout << "NODE " << x << "\n";

	int sum = 1, cur;
	arr[x][0] = parent;
	arr[x][1] = 1;

	for (int i = 0; i < G[x].size(); i++)
	{
		cur = G[x][i].second;

		if (vis[cur])
			continue;

		sum += dfs(cur, parent);
	}

	return sum;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++)
	{	
		cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}

	for (int i = 1; i <= n; i++)
	{
		//cout << i+1 << " " << arr[i+1][1] << "\n";
		if (arr[i][1] == 0)
		{
			arr[i][0] = dfs(i, i) - 1;
			arr[i][1] = 1;

			cout << arr[i][0] << " ";
		}

		else
			cout << arr[arr[i][0]][0] << " ";
	}

	return 0;
}