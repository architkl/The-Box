#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <fstream>

using namespace std;

const int N_MAX = 100005;

bool vis[N_MAX];

vector <int> val(N_MAX);
vector < pair <int, int> > G[N_MAX];

int ans;

void ini()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = 0;
}

void dfs(int cur, int count, long long int sum, int K)
{
	vis[cur] = 1;
	
	if (sum >= K)
	{
		ans = min(ans, count);
		return;
	}

	for (int i = 0; i < G[cur].size(); i++)
	{
		if (vis[G[cur][i].second] == false)
			dfs(G[cur][i].second, count + 1, sum + val[G[cur][i].second], K);
	}
}

int main()
{
	ifstream fi("minimumNodes_TC.txt");

	int N, Q;
	fi >> N >> Q;
	//cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		fi >> val[i];//cin >> val[i];
	
	int u, v;
	for (int i = 0; i < N-1; i++)
	{
		fi >> u >> v;
		//cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}
/*
	for (int i = 1; i <= N; i++)
	{
		cout << i << ": ";

		for (int j = 0; j < G[i].size(); j++)
			cout << G[i][j].second << " ";

		cout << "\n";
	}*/

	int X, K;
	for (int i = 0; i < Q; i++)
	{
		fi >> X >> K;
		//cin >> X >> K;

		ans = INT_MAX;
		ini();

		dfs(X, 1, val[X], K);

		ans == INT_MAX ? cout << -1 << "\n" : cout << ans << "\n";
	}

	fi.close();
	
	return 0;
}