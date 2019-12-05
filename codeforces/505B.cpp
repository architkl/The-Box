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

const int N_MAX = 105;

vector < pair <int, pii> > G[N_MAX+5];
vector <bool> vis(N_MAX);
int dest, col;

void init()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = 0;
}

bool dfs(int x)
{
	if (x == dest)
		return 1;

	vis[x] = true;

	bool temp;
	for (auto i : G[x])
	{
		if (!vis[i.second.second] && i.first == col)
		{
			temp = dfs(i.second.second);

			if (temp)
				return 1;
		}
	}

	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int a, b, c;
	set <int> colour;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		G[a].pb(mp(c, mp(a, b)));
		G[b].pb(mp(c, mp(b, a)));

		colour.insert(c);
	}

	int q, u, v, res;
	cin >> q;

	while (q--)
	{
		cin >> u >> v;

		dest = v;
		res = 0;

		for (auto i : colour)
		{
			init();
			
			col = i;

			if (dfs(u))
				res++;
		}

		cout << res << "\n";
	}

	return 0;
}