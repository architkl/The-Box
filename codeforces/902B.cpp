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

const int N_MAX = 1e4 + 5;

vector <int> G[N_MAX];
vector <bool> vis(N_MAX);
vector <int> c(N_MAX);

int dfs(int x, int col)
{
	vis[x] = true;

	int temp = 0;
	for (auto i : G[x])
	{
		if (vis[i])
			continue;

		temp += dfs(i, c[x]);
	}
	
	return (temp + !(col == c[x]));
}

int main()
{
	int n;
	cin >> n;

	int t;
	for (int i = 2; i <= n; i++)
	{
		cin >> t;

		G[i].pb(t);
		G[t].pb(i);
	}

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	cout << dfs(1, 0) << "\n";

	return 0;
}