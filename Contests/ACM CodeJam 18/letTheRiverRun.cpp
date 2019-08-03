#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N_MAX = 105;

vector < pair <int, pair <int, int> > > G[N_MAX];

bool vis[N_MAX];
int dist[N_MAX];

void topologicalSort(int, stack <int> &);

void init(int N, stack <int> &S)
{
	for (int i = 1; i <= N; i++)
	{
		vis[i] = 0;
		dist[i] = -1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (vis[i])
			continue;

		topologicalSort(i, S);
	}
}

void topologicalSort(int cur, stack <int> &S)
{
	vis[cur] = true;

	for (auto i : G[cur])
	{
		if (vis[i.second.second])
			continue;

		topologicalSort(i.second.second, S);
	}

	S.push(cur);
}

int main()
{
	int N, M;
	cin >> N >> M;

	int x, y, z;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;

		G[x].push_back(make_pair(z, make_pair(x, y)));
	}

	stack <int> S;
	init(N, S);

	dist[1] = 0;
	int i;
	while (!S.empty())
	{
		i = S.top();
		S.pop();

		if (dist[i] < 0)
			continue;
		
		for (auto j : G[i])
		{
			if (dist[j.second.second] < dist[i] + j.first)
				dist[j.second.second] = dist[i] + j.first;
		}
	}

	cout << dist[N] << "\n";

	return 0;
}