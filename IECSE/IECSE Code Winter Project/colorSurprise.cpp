#include <iostream>

using namespace std;

const int N_MAX = 30;

bool vis[N_MAX][N_MAX];

void initialize()
{
	for (int i = 0; i < N_MAX; i++)
		for (int j = 0; j < N_MAX; j++)
			vis[i][j] = false;
}

void fill(int G[N_MAX][N_MAX],int N, int i, int j, int W)
{
	if (vis[i][j])
		return;

	vis[i][j] = true;

	for (int l = -1; l < 2; l++)
	{
		for (int m = -1; m < 2; m++)
		{
			if ( (i+l < 0) || (i+l >= N) || (j+m < 0) || (j+m >= N) || (l == 0 && m == 0) )
				continue;

			if (G[i+l][j+m] == G[i][j])
				fill(G, N, i+l, j+m, W);
		}
	}
	G[i][j] = W;
}

int main()
{
	int q;
	cin >> q;

	int N, i, j, W, grid[N_MAX][N_MAX];
	for (int k = 0; k < q; k++)
	{
		cin >> N >> i >> j >> W;

		for (int l = 0; l < N; l++)
			for (int m = 0; m < N; m++)
				cin >> grid[l][m];

		initialize();

		fill(grid, N, i, j, W);

		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
				cout << grid[l][m] << " ";
			cout << "\n";
		}
	}

	return 0;
}