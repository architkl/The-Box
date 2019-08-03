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

int main()
{
	int n;
	cin >> n;

	vector <int> G[n+5];
	int u, v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;

		G[u].pb(v);
		G[v].pb(u);
	}

	vector <int> s1, s2;
	vector <bool> vis(n+1);
	queue <pii> q;
	q.push(mp(1, -1));
	vis[1] = true;
	pii cur;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (cur.second == 1)
			s1.pb(cur.first);

		else
			s2.pb(cur.first);

		for (auto i : G[cur.first])
		{
			if (vis[i])
				continue;

			q.push(mp(i, cur.second * (-1)));
			vis[i] = true;
		}
	}

	ll ans = 0;
	for (auto i : s1)
		ans += s2.size() - G[i].size();

	cout << ans << "\n";

	return 0;
}