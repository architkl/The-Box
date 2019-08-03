#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 1001;

bool vis[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = false;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector <pair <int, int>> G[N];
	pair <int, int> t;
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}

	for (int i = 1; i < N; i++)
	{
		init();

		vector <int> q[2];
		q[0].push_back(0);
		q[1].push_back(0);
		int cur, flag = 0;
		
		for (int j = 0; j < q[0].size(); j++)
		{
			cur = q[0][j];
			vis[cur] = true;

			if (cur == i)
			{
				cout << q[1][j] * 5 << " ";
				flag = 1;
				break;
			}

			for (int k = 0; k < G[cur].size(); k++)
			{
				if (vis[G[cur][k].second])
					continue;
				q[0].push_back(G[cur][k].second);
				q[1].push_back(q[1][j] + 1);
			}
		}

		if (!flag)
			cout << -1 << " ";
	}

	return 0;
}