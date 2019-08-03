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

bool vis[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = false;
}

pair <int, int> bfs(vector <vector <pii>> G, int src)
{
	queue <pii> q;
	q.push(mp(src, 0));

	pii cur;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (auto i : G[cur.first])
		{
			if (vis[i.second])
				continue;

			q.push(mp(i.second, cur.second+1));
			vis[i.second] = true;
		}
	}

	return cur;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector <vector <pii>> G(N+1);
	int u, v;
	for (int i = 0; i < N-1; i++)
	{
		cin >> u >> v;

		G[u].pb(mp(u, v));
		G[v].pb(mp(v, u));
	}

	init();
	int temp = bfs(G, 1).first;

	init();
	cout << bfs(G, temp).second << "\n";

	return 0;
}