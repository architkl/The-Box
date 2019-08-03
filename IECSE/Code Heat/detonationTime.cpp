#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int N_MAX = 100005;

pair <int, int> bfs(vector < pair <int, int> > G[], int x)
{
	int dist[N_MAX] = {};
	vector <int> q;
	q.push_back(x);

	int cur = 0;
	while (cur < q.size())
	{
		for (auto i : G[q[cur]])
		{
			if (dist[i.second] == 0)
			{
				q.push_back(i.second);
				dist[i.second] = dist[q[cur]] + 1;
			}
		}
		cur++;
	}

	return make_pair(q[q.size()-1], dist[q[q.size()-1]]);
}

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector < pair <int, int> > G[N];
		int u, v;
		for (int j = 0; j < N-1; j++)
		{
			cin >> u >> v;

			G[u].push_back(make_pair(u, v));
			G[v].push_back(make_pair(v, u));
		}

		pair <int, int> ans = bfs(G, 0);
		ans = bfs(G, ans.first);

		cout << ceil(ans.second / 2.0) << "\n";
	}

	return 0;
}