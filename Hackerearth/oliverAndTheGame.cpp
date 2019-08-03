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
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

//	GRAPHS
const int N_MAX = 1e5+5;

vector <int> G[N_MAX];
// vector <piii> G[N_MAX];
vector <bool> vis(N_MAX);
vector <int> a(N_MAX), d(N_MAX);

int _time = 0;

void dfs(int x)
{
	vis[x] = true;

	a[x] = ++_time;

	for (auto i : G[x])
	{
		if (vis[i])
			continue;

		dfs(i);
	}

	d[x] = ++_time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int u, v;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;

		G[u].pb(v);
		G[v].pb(u);
	}

	dfs(1);

	int Q;
	cin >> Q;

	int C, X, Y;
	while (Q--)
	{
		cin >> C >> X >> Y;

		if (C)
		{
			if (a[X] > a[Y] && d[X] < d[Y])
				cout << "YES\n";

			else
				cout << "NO\n";
		}

		else
		{
			if (a[X] < a[Y] && d[X] > d[Y])
				cout << "YES\n";

			else
				cout << "NO\n";
		}
	}

	return 0;
}