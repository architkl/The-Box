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
	int n, m;
	cin >> n >> m;

	vector < vector <int> > G(n+1, vector <int> (n+1));
	vector <int> deg(n+1);
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;

		G[u][v] = 1;
		G[v][u] = 1;
		deg[u]++;
		deg[v]++;
	}

	int sum = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (!G[i][j])
				continue;

			for (int k = j+1; k <= n; k++)
			{
				if (G[i][k] && G[j][k])
					sum = min(sum, deg[i] + deg[j] + deg[k] - 6);
			}
		}
	}

	cout << ((sum == INT_MAX) ? -1 : sum) << "\n";

	return 0;
}