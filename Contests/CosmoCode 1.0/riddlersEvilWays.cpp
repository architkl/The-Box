#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int N_MAX = 10005;

bool vis[N_MAX];
char type[N_MAX];

vector < pair <int, int> > G[N_MAX];

void ini()
{
	for (int i = 0; i < N_MAX; i++)
		vis[i] = false;
}

void ini_type()
{
	for (int i = 0; i < N_MAX; i++)
		type[i] = 'A';
}

// void change(int x, int type)
// {
// 	if (type == 'A')
// 		type = 'B';
	
// 	else
// 		type = 'A';

// 	for (int i = 0; i < G[x].size(); i++)
// 	{
// 		G[x][i].first = type;
// 	}
// }

void change_type(int x)
{
	type[x] == 'A' ? type[x] = 'B' : type[x] = 'A';
}

int dfs(int x)
{
	vis[x] = true;

	//cout << "bomb " << x << "\n";

	int sum = 1, cur;

	for (int i = 0; i < G[x].size(); i++)
	{
		cur = G[x][i].second;

		if (vis[cur] || type[x] != type[cur])
			continue;

		sum += dfs(cur);
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;

	//vector < pair <char, int> > G[n];
	int u, v;
	for (int i = 0; i < n-1; i++)
	{
		cin >> u >> v;

		G[u].push_back(make_pair(u, v));
		G[v].push_back(make_pair(v, u));
	}

	int q, l, x;
	cin >> q;

	ini_type();

	for (int i = 0; i < q; i++)
	{
		cin >> l >> x;

		ini();

		if (l == 0)
			cout << dfs(x) << "\n";

		else
			change_type(x);
	}

	return 0;
}