#include <iostream>
#include <set>
#include <queue>
#include <functional>

using namespace std;

const int N_MAX = 3005;
const int INF = 999999999;

int dist[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		dist[i] = INF;
}

void dijkstra(set < pair <int, pair <int, int> > > G[N_MAX], int n, int s)
{
	init();

	priority_queue < pair <int, int>, vector < pair <int, int> >, greater< pair <int, int> > > pq;
	dist[s] = 0;
	pq.push(make_pair(dist[s], s));

	int cur;
	while (!pq.empty())
	{
		cur = pq.top().second;
		pq.pop();

		for (auto i : G[cur])
		{
			if (dist[i.second.second] > dist[i.second.first] + i.first)
			{
				dist[i.second.second] = dist[i.second.first] + i.first;
				pq.push(make_pair(dist[i.second.second], i.second.second));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (dist[i] == INF)
			dist[i] = -1;
}

void print(int n)
{
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}

int main()
{
	int n, m, x, y, r, s;
    cin >> n >> m >> s;

	set < pair <int, pair <int, int> > > G[N_MAX];

	for (int j = 0; j < m; j++)
	{
		scanf("%d %d %d", &x, &y, &r);

		G[x].insert(make_pair(r, make_pair(x, y)));
		G[y].insert(make_pair(r, make_pair(y, x)));
	}

	dijkstra(G, n, s);

	print(n);
	
    return 0;
}