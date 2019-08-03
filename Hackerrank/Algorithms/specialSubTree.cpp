#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 3000;
const int M_MAX = N_MAX * (N_MAX - 1) / 2;

pair <int, pair <int, int> > E[M_MAX];

int q_union[N_MAX + 1];

void ini()
{
	for (int i = 1; i <= N_MAX; i++)
		q_union[i] = i;
}

int root(int x)
{
	int p;
	for (p = x; p != q_union[p]; p = q_union[p]);

	return p;
}

void connect(int u, int v)
{
	int p = root(u), q = root(v);
	
	q_union[p] = q_union[q];
}

int connected(int u, int v)
{
	return (root(u) == root(v));
}

bool special(const pair <int, pair <int, int> > &a, 
			const pair <int, pair <int, int> > &b)
{
	int a_wt = a.first, a_x = a.second.first, a_y = a.second.second;
	int b_wt = b.first, b_x = b.second.first, b_y = b.second.second;
	
	return a_wt == b_wt ? (a_x + a_y < b_x + b_y) : (a_wt < b_wt);
}

int main()
{
	int N, M;
	cin >> N >> M;

	int u, v, wt;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> wt;

		E[i] = make_pair(wt, make_pair(u, v));
	}

	sort(E, E + M, special);
	ini();

	/*for (int i = 0; i < M; i++)
	{
		cout << E[i].first << " - " << E[i].second.first << " " << E[i].second.second << "\n";
	}*/


	long long int subtree_wt = 0;
	for (int i = 0; i < M; i++)
	{
		if (connected(E[i].second.first, E[i].second.second))
			continue;

		subtree_wt += E[i].first;

		connect(E[i].second.first, E[i].second.second);
	}

	cout << subtree_wt << "\n";

	return 0;
}