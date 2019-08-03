/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int N_MAX = 55;
const int INF = 999999999;

bool vis[N_MAX];
int dist[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		vis[i] = 0;
		dist[i] = INF;
	}
}

int minDist(int V)
{
	int mn = INF, mn_idx;
	for (int i = 1; i <= V; i++)
	{
		if (vis[i] == false && dist[i] < mn)
		{
			mn = dist[i];
			mn_idx = i;
		}
	}

	return mn_idx;
}

void Dijkstra(int src, int V)
{
	init();
	dist[src] = 0;

	int cur;
	for (int i = 0; i < V; i++)
	{
		cur = minDist(V);
		vis[cur] = true;

		for (auto j : G[cur])
		{
			if (dist[j.second.second] > dist[cur] + j.first)
				dist[j.second.second] = dist[cur] + j.first;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	int N, M;
	while (T--)
	{
		cin >> N >> M;

		vector < pair <int, pii> > G[N];
		int x, y, z;
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y >> z;

			G[x].pb(mp(z, mp(x, y)));
		}
	}

	return 0;
}