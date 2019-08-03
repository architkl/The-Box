#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	vector <int> fish[N];
	int T, A;
	for (int i = 0; i < N; i++)
	{
		cin >> T;

		for (int j = 0; j < T; j++)
		{
			cin >> A;
			fish[i].push_back(A);
		}
	}

	vector < pair <int, pair <int, int> > > road[M];
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;

		G[u].push_back(make_pair(w, make_pair(u, v)));
		G[v].push_back(make_pair(w, make_pair(v, u)));
	}
}