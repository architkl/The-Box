	#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N_MAX = 1005;

bool qd[N_MAX];

int main()
{
	int N, M, T, C, X, Y;
	cin >> N >> M >> T >> C;

	vector < pair <int, int> > G[N+1];
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}

	cin >> X >> Y;

	//	BFS

	int q[N_MAX], /*time[N_MAX],*/ parent[N_MAX], rear = 1, cur;
	q[0] = X;
	qd[X] = 1;
	//time[0] = 0;

	for (int i = 0; i < rear; i++)
	{
		cur = q[i];

		if (cur == Y)
		{
			vector <int> path;
			int k = i;
			while (k != 0)
			{
				path.push_back(q[k]);
				k = parent[k];
			}
			path.push_back(q[k]);

			cout << path.size() << "\n";
			for (int j = path.size() - 1; j >= 0; j--)
				cout << path[j] << " ";

			break;
		}

		for (int j = 0; j < G[cur].size(); j++)
		{
			if (qd[G[cur][j].second])
				continue;

			q[rear] = G[cur][j].second;
			parent[rear] = i;
			qd[G[cur][j].second] = 1;
			rear++;
		}
	}

	return 0;
}