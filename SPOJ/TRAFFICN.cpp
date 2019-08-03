/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 1e4+5;
const int INF = 1e7+5;

void init(int dist[N_MAX])
{
	for (int i = 0; i < N_MAX; i++)
		dist[i] = INF;
}

void dijkstra(vector <vector <pii>> G, int s, int t, int dist[N_MAX])
{
	priority_queue <pii, vector <pii>, greater <pii>> pq;

	dist[s] = 0;
	pq.push(mp(0, s));

	pii cur;

	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();

		for (auto i : G[cur.second])
		{
			if (dist[cur.second] + i.first < dist[i.second])
			{
				dist[i.second] = dist[cur.second] + i.first;
				pq.push(mp(dist[i.second], i.second));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int n, m, k, s, t;
	while (T--)
	{
		cin >> n >> m >> k >> s >> t;

		vector <vector <pii>> G(n+1), G_(n+1);

		int u, v, w;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			
			G[u].pb(mp(w, v));
			G_[v].pb(mp(w, u));
		}

		vector <pair<int, pii>> roads;
		for (int i = 0; i < k; i++)
		{
			cin >> u >> v >> w;

			roads.pb(mp(w, mp(u, v)));
		}

		int dist_s[N_MAX], dist_t[N_MAX];
		init(dist_s);
		init(dist_t);
		dijkstra(G, s, t, dist_s);
		dijkstra(G_, t, s, dist_t);

		for (auto i : roads)
		{
			dist_s[t] = min(dist_s[t], min(
				dist_s[i.second.first] + i.first + dist_t[i.second.second],
				dist_s[i.second.second] + i.first + dist_t[i.second.first]));
		}

		dist_s[t] == INF ? cout << "-1\n" : cout << dist_s[t] << "\n";
	}

	return 0;
}