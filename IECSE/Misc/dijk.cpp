#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;

const int V_MAX = 1e3 + 5;
const int inf = 1e5;

int dist[V_MAX];
vector <pii> G[V_MAX];

void init()
{
	for (int i = 0; i < V_MAX; i++)
		dist[i] = inf;
}

int dijk(int src, int dest)
{
	dist[src] = 0;

	priority_queue <pii, vector <pii>, greater<pii>> myQ;
	myQ.push(mp(0, src));
	pii cur;

	while (!myQ.empty())
	{
		cur = myQ.top();
		myQ.pop();

		if (cur.second == dest)
			return dist[cur.second];

		for (auto i : G[cur.second])
		{
			if (dist[i.first] > dist[cur.second] + i.second)
			{
				dist[i.first] = dist[cur.second] + i.second;
				myQ.push(mp(dist[cur.second] + i.second, i.first));
				// cout << cur.second << " " << i.first << " " << dist[cur.second] + i.second << "\n";
			}
		}
	}

	return -1;
}

int main()
{
	int T;
	cin >> T;

	int n = 1;
	while (T--)
	{
		//cin >> n;

		init();

		for (int i = 1; i <= n; i++)
		{
			if (i+1 <= n)
				G[i].pb(mp(i+1, 1));

			if (3*i <= n)
				G[i].pb(mp(3*i, 1));
		}

		cout << n << ": " << dijk(1, n) << "\n";
		n++;
	}

	return 0;
}