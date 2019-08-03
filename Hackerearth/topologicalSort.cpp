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

const int N_MAX = 15;

vector <pii> G[N_MAX];
vector <int> order;
vector <bool> vis(N_MAX);

bool mycomp(pii a, pii b)
{
	return (a.second > b.second);
}

void top_sort(int x)
{
	vis[x] = true;

	for (auto i : G[x])
	{
		if (!vis[i.second])
			top_sort(i.second);
	}

	order.pb(x);
}

int main()
{
	int N, M;
	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		G[u].pb(mp(u, v));
	}

	for (int i = 1; i <= N; i++)
		sort(G[i].begin(), G[i].end(), mycomp);

	for (int i = N; i > 0; i--)
	{
		if (!vis[i])
			top_sort(i);
	}

	reverse(order.begin(), order.end());
	for (auto i : order)
		cout << i << " ";
	cout << "\n";

	return 0;
}