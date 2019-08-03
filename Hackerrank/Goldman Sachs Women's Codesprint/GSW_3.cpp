/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb

typedef pair <int, int> pii;

const int N_MAX = 200005;

vector < pii > G[N_MAX];

bool vis[N_MAX];

void init()
{
	for (int i = 0; i > N_MAX; i++)
		vis[i] = false;

	G.clear();
}

void dfs(int x)
{
	if (vis[x])
		return 0;

	vis[x] = true;
	for (auto i:G[x])
	{
		dfs(i.second);
	}

	
}

int main()
{
	int tc;
	cin >> tc;

	int n, m, b, e;
	for (int i = 0; i < tc; i++)
	{
		cin >> n >> m;

		make_dsu();

		for (int j = 0; j < m; j++)
		{
			cin >> 
		}
	}

	return 0;
}